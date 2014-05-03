#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include "mdd_manager_priv.h"
#include "mdd_node_priv.h"
#include "cache_priv.h"
#include "unique_table_priv.h"
#include "garbage_collector_priv.h"
#include "bigint_priv.h"

#define MDD_NODE_STORAGE_INITIAL_SIZE 256 /* 32768 */

void mdd_node_storage_init(mdd_manager_t *manager, mdd_level_t k)
{
  mdd_node_storage_t *storage = &(manager->mdd_nodes[k]);

  storage->size = 0;
  storage->maxsize = MDD_NODE_STORAGE_INITIAL_SIZE;
  storage->free_stack = 0;
  storage->table = malloc(storage->maxsize*mdd_node_size(manager, k)*sizeof(int));
  manager->currently_allocated += storage->maxsize*mdd_node_size(manager, k)*sizeof(int);
}

void mdd_node_storage_free(mdd_manager_t *manager, mdd_level_t k)
{
  mdd_node_storage_t *storage = &(manager->mdd_nodes[k]);

  manager->currently_allocated -= storage->maxsize*mdd_node_size(manager, k)*sizeof(int);
  free(storage->table);
}

/* returns 1 if successfully enlarged,
   otherwise 0 and left node_storage untouched */
static int mdd_node_storage_enlarge(mdd_manager_t *manager, mdd_level_t k)
{
  mdd_node_storage_t *storage = &(manager->mdd_nodes[k]);
  mdd_node_t *new_table;

/*  fprintf(stderr, "%s/%d: enlarge node_storage\n", __FILE__, __LINE__); */

  manager->currently_allocated += storage->maxsize*mdd_node_size(manager, k)*sizeof(int);
  storage->maxsize *= 2;
  if (storage->maxsize > 1 << manager->level_shift) return 0;
  new_table = realloc(storage->table, storage->maxsize*mdd_node_size(manager, k)*sizeof(int));
  if (new_table == NULL) return 0;
  storage->table = new_table;

  return 1;
}

/* returns 1 if successfully found a fresh index,
   otherwise 0 */
static int mdd_node_new_index(mdd_manager_t *manager, mdd_level_t k, mdd_level_index_t *index)
{
  mdd_node_storage_t *storage = &(manager->mdd_nodes[k]);

  if (storage->free_stack) {
    *index = storage->free_stack;
    storage->free_stack = mdd_node_get(manager, *index)->children[0];
    return 1;
  }
  if (storage->size < storage->maxsize) {
    *index = mdd_level_index(manager, k, storage->size);
    ++(storage->size);
    return 1;
  }

  return 0;
}

mdd_level_index_t mdd_const0(mdd_manager_t *manager)
{
  return mdd_level_index(manager, 0, 0);
}

mdd_level_index_t mdd_const1(mdd_manager_t *manager)
{
  return mdd_level_index(manager, 0, 1);
}

mdd_level_index_t mdd_node_new(mdd_manager_t *manager, mdd_level_t k)
{
  mdd_node_storage_t *storage = &(manager->mdd_nodes[k]);
  mdd_level_index_t index;
  mdd_node_t *node;
  int i, range;

  if (manager->currently_allocated > manager->gc_threshold)
    garbage_collector_mdd(manager);

  if (!mdd_node_new_index(manager, k, &index)) {
    if (!mdd_node_storage_enlarge(manager, k) ||
        !mdd_node_new_index(manager, k, &index)) {
      fprintf(stderr, "%s/%d: Unable to allocate %lu byte of memory.\n", __FILE__, __LINE__, (long)storage->maxsize*mdd_node_size(manager, k)*sizeof(int));
      fprintf(stderr, "%s/%d: number of nodes at level %d: %d (cannot exceed %d)\n",
              __FILE__, __LINE__, k, storage->size, 1 << manager->level_shift);
      exit(1);
    }
  }

  /* initialize node */
  node = mdd_node_get(manager, index);

  node->flags = MDD_NODE_ALLOCATED;

  range = manager->ranges[(k+1)/2];
  for (i = 0; i < range; ++i)
    node->children[i] = 0;

  return index;
}

void mdd_node_free(mdd_manager_t *manager, mdd_level_index_t p)
{
  mdd_node_storage_t *storage = &(manager->mdd_nodes[mdd_level(manager, p)]);
  mdd_node_t *node = mdd_node_get(manager, p);

  node->flags &= ~MDD_NODE_ALLOCATED;
  node->children[0] = storage->free_stack;
  storage->free_stack = p;
}

void mdd_ref(mdd_manager_t *manager, mdd_level_index_t p)
{
  mdd_node_t *node = mdd_node_get(manager, p);

  ++(node->flags);
}

void mdd_unref(mdd_manager_t *manager, mdd_level_index_t p)
{
  mdd_node_t *node = mdd_node_get(manager, p);

  assert((node->flags & MDD_NODE_REFERENCE_COUNT) > 0);
  --(node->flags);
}

void mdd_print_states(mdd_manager_t *manager, mdd_level_index_t p, int max)
{
  int range, count, extra, i, j;
  int *state;
  mdd_level_index_t q, *path;
  mdd_level_t num_levels, plevel, qlevel, k;
  mdd_node_t *n;

  if (p == 0) return;	/* empty set */
  num_levels = mdd_manager_get_nb_levels(manager);
  plevel  = (mdd_level(manager, p)+1)/2;
  if (plevel < num_levels) {
    /* printing partial states not supported */
    return;
  }
  range = manager->ranges[plevel];
  n = mdd_node_get(manager, p);
  
  count = 0;
  extra = 1;
  state = malloc((plevel+1)*sizeof(int));
  path = malloc((plevel+1)*sizeof(mdd_level_index_t));
  for (j=plevel; j; --j) state[j] = -1;	/* fill with unknown */
  path[plevel] = p;
  k = plevel;
  /* 
     enumeration of states based on backtracking 
     on all paths from p to terminal
  */
  while (count < max && k<=plevel) {
    n = mdd_node_get(manager, path[k]);
    range = manager->ranges[k];
    i = state[k] + 1;
    while (i < range && n->children[i] == 0) i++;	/* skip zeros */
    if (k>0 && i>=range) {
      state[k] = -1;	/* next time start at 0 again */	
      k++;
      while (state[k]<0 && k<=plevel) k++;		/* backtrack */
      extra = 1;
    }
    else {
      state[k] = i;
      if (k>1) {
        q = n->children[i];
        qlevel  = (mdd_level(manager, q)+1)/2;
        for (j=k-1; j>qlevel; j--)
          extra = extra*manager->ranges[j];
        k = qlevel;
        path[k] = q;
      }
      else if (k==1) {
        /* full state constructed */
        if (extra>1) 
          fprintf(stdout, ";; ---\n*States %d-%d: ", count+1, count+extra);
        else 
          fprintf(stdout, ";; ---\n*State %d: ", count+1);
        count = count+extra;
        mdd_manager_print_state(manager, state);
        fprintf(stdout, "\n");
      }
      else {
        /* k = 0 (terminal) */
        /* reached terminal via don-t-cares */
        /* find previous don-t-care */
        k++;
        extra = 1;
        while (state[k]<0 && k<plevel) {
          extra = extra*manager->ranges[k];
          k++;
        }
        fprintf(stdout, ";; ---\n*States %d-%d: ", count+1, count+extra);
        count += extra;
        mdd_manager_print_state(manager, state);
        fprintf(stdout, "\n");
      }
    }
  }
  free(path);
  free(state);
}

static void mdd_print_dot_node(mdd_manager_t *manager, mdd_level_index_t p, FILE *f)
{
  mdd_node_t *n = mdd_node_get(manager, p), *child;
  int i, range;

  if (p <= 1) return;

  /* printing node */
  if (manager->var_names)
    fprintf(f, "\"(%d|%d)\" [label = \"%s%s", mdd_level(manager, p), mdd_index(manager, p),
            manager->var_names[(mdd_level(manager, p)+1)/2], mdd_level(manager, p) & 1 ? "'" : "");
  else
    fprintf(f, "\"(%d|%d)\" [label = \"%d", mdd_level(manager, p), mdd_index(manager, p), mdd_level(manager, p));
  range = manager->ranges[(mdd_level(manager, p)+1)/2];
  for (i = 0; i < range; ++i)
    fprintf(f, "|<f%d>%d", i, manager->lower_bounds[(mdd_level(manager, p)+1)/2]+i);
  fprintf(f, "\" shape = \"record\"]\n");

  /* printing edges and children */
  for (i = 0; i < range; ++i)
    if (n->children[i] == 1)
      fprintf(f, "\"(%d|%d)\":f%d -- \"(0|1)\"\n", mdd_level(manager, p), mdd_index(manager, p), i);
    else if (n->children[i] != 0) {
      child = mdd_node_get(manager, n->children[i]);
      if (!(child->flags & MDD_NODE_MARK))
        mdd_print_dot_node(manager, n->children[i], f);
      fprintf(f, "\"(%d|%d)\":f%d -- \"(%d|%d)\"\n",
              mdd_level(manager, p), mdd_index(manager, p), i,
              mdd_level(manager, n->children[i]), mdd_index(manager, n->children[i]));
    }

  n->flags |= MDD_NODE_MARK;
}

void mdd_print_dot(mdd_manager_t *manager, mdd_level_index_t p, FILE *f)
{
  fprintf(f, "graph G {\n");
  if (p) {
    mdd_print_dot_node(manager, p, f);
    fprintf(f, "\"(0|1)\" [label = \"T\" shape = \"circle\"]\n");
  } else
    fprintf(f, "\"(0|0)\" [label = \"F\" shape = \"circle\"]\n");
  fprintf(f, "}\n");

  if (p) mdd_reset_mark(manager, p);
}

static void mdd_to_file_node(mdd_manager_t *manager, mdd_level_index_t p, FILE *f)
{
  mdd_node_t *n = mdd_node_get(manager, p), *child;
  int i, range;

  if (p <= 1) return;

  range = manager->ranges[(mdd_level(manager, p)+1)/2];

  /* printing children */
  /* node have to be printed in depth first postorder */
  for (i = 0; i < range; ++i)
    if (n->children[i] > 1) {
      child = mdd_node_get(manager, n->children[i]);
      if (!(child->flags & MDD_NODE_MARK))
        mdd_to_file_node(manager, n->children[i], f);
    }

  /* printing node */
  /* format: level (mdd_level_index_t), all children (range*mdd_level_index_t) */
  fprintf(f, "%u", p);
  for (i = 0; i < range; ++i)
    fprintf(f, " %u", n->children[i]);
  fprintf(f, "\n");

  n->flags |= MDD_NODE_MARK;
}

void mdd_to_file(mdd_manager_t *manager, mdd_level_index_t p, FILE *f)
{
  int i;

  /* write something at the beginning of the file to identify it */
  fprintf(f, "EVMDDdiagram\n");
  /* write nb_levels and ranges to check that they are correct when reading */
  fprintf(f, "%d\n", manager->nb_levels);
  for (i = 1; i < manager->nb_levels; ++i)
    fprintf(f, "%d ", manager->ranges[i]);
  fprintf(f, "%d\n", manager->ranges[manager->nb_levels]);
  /* write diagram type */
  fprintf(f, "MDD\n");

  /* now, actually write the diagram */
  mdd_to_file_node(manager, p, f);

  /* add a last false node as sentinel to mark end of input */
  /* this node is at level nb_levels+1 and has only one child, p */
  fprintf(f, "%u", mdd_level_index(manager, 2*manager->nb_levels+1, 0));
  fprintf(f, " %u\n", p);

  mdd_reset_mark(manager, p);
}

mdd_level_index_t mdd_from_file(mdd_manager_t *manager, FILE *f)
{
  int i, k, range, read_nb_levels, read_range;
  mdd_level_index_t p, q, r;
  mdd_node_t *n;

  if (fscanf(f, "EVMDDdiagram\n"))
    fprintf(stderr, "%s/%d: file doesn't seem to contain a proper MDD\n", __FILE__, __LINE__);

  if (fscanf(f, "%d", &read_nb_levels) != 1)
    fprintf(stderr, "%s/%d: unable to read number of variables of MDD\n", __FILE__, __LINE__);
  if (read_nb_levels != manager->nb_levels)
    fprintf(stderr, "%s/%d: MDD being read contains a number of variables incompatible with current manager\n", __FILE__, __LINE__);

  for (i = 1; i <= manager->nb_levels; ++i) {
    if (fscanf(f, "%d", &read_range) != 1)
      fprintf(stderr, "%s/%d: unable to read range of variable %d of MDD\n", __FILE__, __LINE__, i);
    if (read_range != manager->ranges[i])
      fprintf(stderr, "%s/%d: MDD being read has an incompatible range for variable %d with current manager\n", __FILE__, __LINE__, i);
  }

  if (fscanf(f, " MDD\n"))
    fprintf(stderr, "%s/%d: file doesn't seem to contain a MDD\n", __FILE__, __LINE__);

  while (1) {
    if (fscanf(f, "%u", &p) != 1)
      fprintf(stderr, "%s/%d: unable to read node index\n", __FILE__, __LINE__);
    k = mdd_level(manager, p);
    if (k > 2*manager->nb_levels) break;
    r = mdd_node_new(manager, k);
    n = mdd_node_get(manager, r);
    range = manager->ranges[(k+1)/2];
    for (i = 0; i < range; ++i) {
      if (fscanf(f, "%u", &q) != 1)
        fprintf(stderr, "%s/%d: unable to read children node index\n", __FILE__, __LINE__);
      if (q <= 1)
        n->children[i] = q;
      else if (!cache_READ_find(manager, mdd_level(manager, q), q, n->children+i))
        fprintf(stderr, "%s/%d: children %u should have been already read\n", __FILE__, __LINE__, q);
    }
    r = unique_table_mdd_checkin(manager, r);
    cache_READ_add(manager, k, p, r);
  }

  if (fscanf(f, "%u", &q) != 1)
    fprintf(stderr, "%s/%d: unable to read root node index\n", __FILE__, __LINE__);
  if (q <= 1)
    r = q;
  else if (!cache_READ_find(manager, mdd_level(manager, q), q, &r))
    fprintf(stderr, "%s/%d: root should have been already read\n", __FILE__, __LINE__);

  /* clear cache (cache depends from the exact file we were reading) */
  for (k = 1; k <= 2*manager->nb_levels; ++k)
    cache_mdd_cleanup(manager, MDD_O_READ, k);

  return r;
}

static int mdd_num_nodes_rec(mdd_manager_t *manager, mdd_level_index_t p)
{
  mdd_node_t *n = mdd_node_get(manager, p), *child;
  int i, range;
  int r=1;

  range = manager->ranges[(mdd_level(manager, p)+1)/2];
  for (i = 0; i < range; ++i)
    if (n->children[i] > 1) {
      child = mdd_node_get(manager, n->children[i]);
      if (!(child->flags & MDD_NODE_MARK))
        r += mdd_num_nodes_rec(manager, n->children[i]);
    }

  n->flags |= MDD_NODE_MARK;

  return r;
}

int mdd_num_nodes(mdd_manager_t *manager, mdd_level_index_t p)
{
  int r=0;

  if (p > 1) {
    r = mdd_num_nodes_rec(manager, p);
    mdd_reset_mark(manager, p);
  }

  return r+2;  /* +2: terminal nodes */
}

int mdd_total_num_nodes(mdd_manager_t *manager)
{
  int i, r = 0;
  for (i = 0; i <= 2*manager->nb_levels; ++i)
    r += manager->mdd_nodes[i].size;
  return r;
}

static bigint_t *mdd_num_encoded_elements_rec(mdd_manager_t *manager, mdd_level_t k, mdd_level_index_t p)
{
  mdd_node_t *n;
  int i, range;
  bigint_t *r, *a;

  if (cache_CARDINAL_find(manager, k, p, &r))
    return r;

  if (k == 0 && p == 1) {
    r = bigint_new(1);
    cache_CARDINAL_add(manager, k, p, r);
    return r;
  }

  r = bigint_new(0);
  n = mdd_node_get(manager, p);
  range = manager->ranges[k/2];  /* k is even */
  if (k > mdd_level(manager, p)) {
    a = mdd_num_encoded_elements_rec(manager, k-2, p);
    for (i = 0; i < range; ++i)
      bigint_add(r, a, r);
  } else
    for (i = 0; i < range; ++i)
      if (n->children[i])
        bigint_add(r, mdd_num_encoded_elements_rec(manager, k-2, n->children[i]), r);

  cache_CARDINAL_add(manager, k, p, r);

  return r;
}

bigint_t *mdd_num_encoded_elements(mdd_manager_t *manager, mdd_level_index_t p)
{
  return mdd_num_encoded_elements_rec(manager, 2*manager->nb_levels, p);
}

void mdd_reset_mark(mdd_manager_t *manager, mdd_level_index_t p)
{
  mdd_node_t *n = mdd_node_get(manager, p);
  int i, range;

  if (!(n->flags & MDD_NODE_MARK)) return;

  n->flags &= ~MDD_NODE_MARK;

  range = manager->ranges[(mdd_level(manager, p)+1)/2];
  for (i = 0; i < range; ++i)
    if (n->children[i] > 1)
      mdd_reset_mark(manager, n->children[i]);
}

int mdd_node_hash(mdd_manager_t *manager, mdd_level_index_t p, int M)
{
  unsigned s = 0;
  int i, range;
  mdd_node_t *n = mdd_node_get(manager, p);

  range = manager->ranges[(mdd_level(manager, p)+1)/2];
  for (i = 0; i < range; ++i) {
    s *= 256;
    s += n->children[i];
    s %= M;
  }

  return s;
}

int mdd_node_compare(mdd_manager_t *manager, mdd_level_index_t p, mdd_level_index_t q)
{
  int i, range;
  mdd_node_t *np;
  mdd_node_t *nq;

  if (mdd_level(manager, p) != mdd_level(manager, q))
    return 0;

  np = mdd_node_get(manager, p);
  nq = mdd_node_get(manager, q);

  range = manager->ranges[(mdd_level(manager, p)+1)/2];
  for (i = 0; i < range; ++i)
    if (np->children[i] != nq->children[i])
      return 0;

  return 1;
}

void mdd_node_pair(mdd_manager_t *manager, mdd_level_index_t p, char *sn)
{
  sprintf(sn, "<%d,%d>", mdd_level(manager, p), mdd_index(manager, p));
}

void mdd_node_print(mdd_manager_t *manager, mdd_level_index_t p)
{
  int i, range;
  mdd_node_t *np = mdd_node_get(manager, p);

  range = manager->ranges[(mdd_level(manager, p)+1)/2];
  printf("mdd<%d,%d> = |", mdd_level(manager, p), mdd_index(manager, p));
  for (i = 0; i < range; ++i)
    printf("<%d,%d>|",  mdd_level(manager, np->children[i]), mdd_index(manager, np->children[i]));
  printf("\n");
}
