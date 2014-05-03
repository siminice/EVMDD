#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include "mdd_manager_priv.h"
#include "evmdd_node_priv.h"
#include "cache_priv.h"
#include "unique_table_priv.h"
#include "garbage_collector_priv.h"
#include "bigint_priv.h"

#define EVMDD_NODE_STORAGE_INITIAL_SIZE 256 /* 32768 */

void evmdd_node_storage_init(mdd_manager_t *manager, mdd_level_t k)
{
  evmdd_node_storage_t *storage = &(manager->evmdd_nodes[k]);

  storage->size = 0;
  storage->maxsize = EVMDD_NODE_STORAGE_INITIAL_SIZE;
  storage->free_stack = 0;
  storage->table = malloc(storage->maxsize*evmdd_node_size(manager, k)*sizeof(int));
  manager->currently_allocated += storage->maxsize*evmdd_node_size(manager, k)*sizeof(int);
}

void evmdd_node_storage_free(mdd_manager_t *manager, mdd_level_t k)
{
  evmdd_node_storage_t *storage = &(manager->evmdd_nodes[k]);

  manager->currently_allocated -= storage->maxsize*evmdd_node_size(manager, k)*sizeof(int);
  free(storage->table);
}

/* returns 1 if successfully enlarged,
   otherwise 0 and left node_storage untouched */
static int evmdd_node_storage_enlarge(mdd_manager_t *manager, mdd_level_t k)
{
  evmdd_node_storage_t *storage = &(manager->evmdd_nodes[k]);
  evmdd_node_t *new_table;

/*   fprintf(stderr, "%s/%d: enlarge node_storage\n", __FILE__, __LINE__); */

  manager->currently_allocated += storage->maxsize*evmdd_node_size(manager, k)*sizeof(int);
  storage->maxsize *= 2;
  if (storage->maxsize > 1 << manager->level_shift) return 0;
  new_table = realloc(storage->table, storage->maxsize*evmdd_node_size(manager, k)*sizeof(int));
  if (new_table == NULL) return 0;
  storage->table = new_table;
  return 1;
}

/* returns 1 if successfully found a fresh index,
   otherwise 0 */
static int evmdd_node_new_index(mdd_manager_t *manager, mdd_level_t k, mdd_level_index_t *index)
{
  evmdd_node_storage_t *storage = &(manager->evmdd_nodes[k]);

  if (storage->free_stack) {
    *index = storage->free_stack;
    storage->free_stack = evmdd_node_get(manager, *index)->edges[0].node;
    return 1;
  }
  if (storage->size < storage->maxsize) {
    *index = mdd_level_index(manager, k, storage->size);
    ++(storage->size);
    return 1;
  }

  return 0;
}

mdd_level_index_t evmdd_node_new(mdd_manager_t *manager, mdd_level_t k)
{
  evmdd_node_storage_t *storage = &(manager->evmdd_nodes[k]);
  mdd_level_index_t index;
  evmdd_node_t *node;
  int i, range;

  if (manager->currently_allocated > manager->gc_threshold)
    garbage_collector_evmdd(manager);

  if (!evmdd_node_new_index(manager, k, &index)) {
    if (!evmdd_node_storage_enlarge(manager, k) ||
        !evmdd_node_new_index(manager, k, &index)) {
      fprintf(stderr, "%s/%d: Unable to allocate %d byte of memory.\n", __FILE__, __LINE__, storage->maxsize*evmdd_node_size(manager, k)*(unsigned)sizeof(int));
      fprintf(stderr, "%s/%d: number of nodes at level %d: %d (cannot exceed %d)\n",
              __FILE__, __LINE__, k, storage->size, 1 << manager->level_shift);
      exit(1);
    }
  }

  /* initialize node */
  node = evmdd_node_get(manager, index);

  node->flags = MDD_NODE_ALLOCATED;

  range = manager->ranges[(k+1)/2];
  for (i = 0; i < range; ++i)
    node->edges[i].node = 0;

  return index;
}

void evmdd_node_free(mdd_manager_t *manager, mdd_level_index_t p)
{
  evmdd_node_storage_t *storage = &(manager->evmdd_nodes[mdd_level(manager, p)]);
  evmdd_node_t *node = evmdd_node_get(manager, p);

  node->flags &= ~MDD_NODE_ALLOCATED;
  node->edges[0].node = storage->free_stack;
  storage->free_stack = p;
}

void evmdd_ref(mdd_manager_t *manager, evmdd_edge_t p)
{
  evmdd_node_t *node = evmdd_node_get(manager, p.node);

  ++(node->flags);
}

void evmdd_unref(mdd_manager_t *manager, evmdd_edge_t p)
{
  evmdd_node_t *node = evmdd_node_get(manager, p.node);

  assert((node->flags & MDD_NODE_REFERENCE_COUNT) > 0);
  --(node->flags);
}

static void evmdd_print_dot_node(mdd_manager_t *manager, mdd_level_index_t p, FILE *f)
{
  evmdd_node_t *n = evmdd_node_get(manager, p), *child;
  int i, range;

  /* printing node */
  if (manager->var_names)
    fprintf(f, "\"(%d|%d)\" [label = \"%s%s", mdd_level(manager, p), mdd_index(manager, p),
            manager->var_names[(mdd_level(manager, p)+1)/2], mdd_level(manager, p) & 1 ? "'" : "");
  else
    fprintf(f, "\"(%d|%d)\" [label = \"%d", mdd_level(manager, p), mdd_index(manager, p), mdd_level(manager, p));
  range = manager->ranges[(mdd_level(manager, p)+1)/2];
  for (i = 0; i < range; ++i)
    fprintf(f, "|<f%d>%d", i, n->edges[i].value);
  fprintf(f, "\" shape = \"record\"]\n");

  /* printing edges and children */
  for (i = 0; i < range; ++i)
    if (n->edges[i].node == 0)
      fprintf(f, "\"(%d|%d)\":f%d -- \"(0|0)\"\n", mdd_level(manager, p), mdd_index(manager, p), i);
    else {
      child = evmdd_node_get(manager, n->edges[i].node);
      if (!(child->flags & MDD_NODE_MARK))
        evmdd_print_dot_node(manager, n->edges[i].node, f);
      fprintf(f, "\"(%d|%d)\":f%d -- \"(%d|%d)\"\n",
              mdd_level(manager, p), mdd_index(manager, p), i,
              mdd_level(manager, n->edges[i].node), mdd_index(manager, n->edges[i].node));
    }

  n->flags |= MDD_NODE_MARK;
}

void evmdd_print_dot(mdd_manager_t *manager, evmdd_edge_t p, FILE *f)
{
  fprintf(f, "graph G {\n");
  fprintf(f, "\"top\" [label = \"%d\" shape = \"record\"]\n", p.value);
  fprintf(f, "\"top\" -- \"(%d|%d)\"\n", mdd_level(manager, p.node), mdd_index(manager, p.node));
  if (p.node) evmdd_print_dot_node(manager, p.node, f);
  fprintf(f, "\"(0|0)\" [label = \"0\" shape = \"circle\"]\n");
  fprintf(f, "}\n");

  if (p.node) evmdd_reset_mark(manager, p.node);
}

static void evmdd_to_file_node(mdd_manager_t *manager, mdd_level_index_t p, FILE *f)
{
  evmdd_node_t *n = evmdd_node_get(manager, p), *child;
  int i, range;

  range = manager->ranges[(mdd_level(manager, p)+1)/2];

  /* printing children */
  /* node have to be printed in depth first postorder */
  for (i = 0; i < range; ++i)
    if (n->edges[i].node) {
      child = evmdd_node_get(manager, n->edges[i].node);
      if (!(child->flags & MDD_NODE_MARK))
        evmdd_to_file_node(manager, n->edges[i].node, f);
    }

  /* printing node */
  /* format: level (mdd_level_index_t), all children (node, value: range*evmdd_edge_t) */
  fprintf(f, "%u", p);
  for (i = 0; i < range; ++i)
    fprintf(f, " %u %d", n->edges[i].node, n->edges[i].value);
  fprintf(f, "\n");

  n->flags |= MDD_NODE_MARK;
}

void evmdd_to_file(mdd_manager_t *manager, evmdd_edge_t p, FILE *f)
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
  fprintf(f, "EVMDD\n");

  /* now, actually write the diagram */
  evmdd_to_file_node(manager, p.node, f);

  /* add a last false node as sentinel to mark end of input */
  /* this node is at level nb_levels+1 and has only one child, p */
  fprintf(f, "%u", mdd_level_index(manager, 2*manager->nb_levels+1, 0));
  fprintf(f, " %u %d\n", p.node, p.value);

  evmdd_reset_mark(manager, p.node);
}

evmdd_edge_t evmdd_from_file(mdd_manager_t *manager, FILE *f)
{
  int i, k, range, read_nb_levels, read_range;
  mdd_level_index_t p;
  evmdd_edge_t q, r;
  evmdd_node_t *n;

  if (fscanf(f, "EVMDDdiagram\n"))
    fprintf(stderr, "%s/%d: file doesn't seem to contain a proper EVMDD\n", __FILE__, __LINE__);

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

  if (fscanf(f, " EVMDD\n"))
    fprintf(stderr, "%s/%d: file doesn't seem to contain an EVMDD\n", __FILE__, __LINE__);

  while (1) {
    if (fscanf(f, "%u", &p) != 1)
      fprintf(stderr, "%s/%d: unable to read node index\n", __FILE__, __LINE__);
    k = mdd_level(manager, p);
    if (k > 2*manager->nb_levels) break;
    r.node = evmdd_node_new(manager, k);
    n = evmdd_node_get(manager, r.node);
    range = manager->ranges[(k+1)/2];
    for (i = 0; i < range; ++i) {
      if (fscanf(f, "%u %d", &(q.node), &(q.value)) != 1)
        fprintf(stderr, "%s/%d: unable to read children node index or edge value\n", __FILE__, __LINE__);
      if (q.node == 0)
        n->edges[i].node = 0;
      else if (!cache_READ_EVMDD_find(manager, mdd_level(manager, q.node), q.node, &(n->edges[i].node)))
        fprintf(stderr, "%s/%d: children %u should have been already read\n", __FILE__, __LINE__, q.node);
      n->edges[i].value = q.value;
    }
    r.node = unique_table_evmdd_checkin(manager, r.node);
    cache_READ_EVMDD_add(manager, k, p, r.node);
  }

  if (fscanf(f, "%u %d", &(q.node), &(q.value)) != 1)
    fprintf(stderr, "%s/%d: unable to read root node index or edge value\n", __FILE__, __LINE__);
  if (q.node == 0)
    r.node = 0;
  else if (!cache_READ_EVMDD_find(manager, mdd_level(manager, q.node), q.node, &(r.node)))
    fprintf(stderr, "%s/%d: root should have been already read\n", __FILE__, __LINE__);
  r.value = q.value;

  /* clear cache (cache depends from the exact file we were reading) */
  for (k = 1; k <= 2*manager->nb_levels; ++k)
    cache_evmdd_cleanup(manager, MDD_O_READ_EVMDD, k);

  return r;
}

static int evmdd_num_nodes_rec(mdd_manager_t *manager, mdd_level_index_t p)
{
  evmdd_node_t *n = evmdd_node_get(manager, p), *child;
  int i, range;
  int r=1;

  range = manager->ranges[(mdd_level(manager, p)+1)/2];
  for (i = 0; i < range; ++i)
    if (n->edges[i].node) {
      child = evmdd_node_get(manager, n->edges[i].node);
      if (!(child->flags & MDD_NODE_MARK))
        r += evmdd_num_nodes_rec(manager, n->edges[i].node);
    }

  n->flags |= MDD_NODE_MARK;

  return r;
}

int evmdd_num_nodes(mdd_manager_t *manager, evmdd_edge_t p)
{
  int r=0;

  if (p.node) {
    r = evmdd_num_nodes_rec(manager, p.node);
    evmdd_reset_mark(manager, p.node);
  }

  return r+1;  /* +1: terminal node */
}

int evmdd_total_num_nodes(mdd_manager_t *manager)
{
  int i, r = 0;
  for (i = 0; i <= 2*manager->nb_levels; ++i)
    r += manager->evmdd_nodes[i].size;
  return r;
}

static bigint_t *evmdd_num_encoded_elements_rec(mdd_manager_t *manager, mdd_level_t k, evmdd_edge_t p)
{
  evmdd_node_t *n;
  int i, range;
  bigint_t *r, *a;

  if (cache_CARDINAL_EVMDD_find(manager, k, p.node, &r))
    return r;

  if (k == 0 && p.value != INT_MAX) {
    r = bigint_new(1);
    cache_CARDINAL_EVMDD_add(manager, k, p.node, r);
    return r;
  }

  r = bigint_new(0);
  n = evmdd_node_get(manager, p.node);
  range = manager->ranges[k/2];  /* k is even */
  if (k > mdd_level(manager, p.node)) {
    a = evmdd_num_encoded_elements_rec(manager, k-2, p);
    for (i = 0; i < range; ++i)
      bigint_add(r, a, r);
  } else
    for (i = 0; i < range; ++i)
      if (n->edges[i].value != INT_MAX)
        bigint_add(r, evmdd_num_encoded_elements_rec(manager, k-2, n->edges[i]), r);

  cache_CARDINAL_EVMDD_add(manager, k, p.node, r);

  return r;
}

bigint_t *evmdd_num_encoded_elements(mdd_manager_t *manager, evmdd_edge_t p)
{
  return evmdd_num_encoded_elements_rec(manager, 2*manager->nb_levels, p);
}

void evmdd_reset_mark(mdd_manager_t *manager, mdd_level_index_t p)
{
  evmdd_node_t *n = evmdd_node_get(manager, p);
  int i, range;

  if (!(n->flags & MDD_NODE_MARK)) return;

  n->flags &= ~MDD_NODE_MARK;

  range = manager->ranges[(mdd_level(manager, p)+1)/2];
  for (i = 0; i < range; ++i)
    if (n->edges[i].node)
      evmdd_reset_mark(manager, n->edges[i].node);
}

int evmdd_node_hash(mdd_manager_t *manager, mdd_level_index_t p, int M)
{
  unsigned s = 0;
  int i, range;
  evmdd_node_t *n = evmdd_node_get(manager, p);

  range = manager->ranges[(mdd_level(manager, p)+1)/2];
  for (i = 0; i < range; ++i) {
    s *= 256;
    s += n->edges[i].node;
    s %= M;
    s *= 256;
    s += n->edges[i].value;
    s %= M;
  }

  return s;
}

int evmdd_node_compare(mdd_manager_t *manager, mdd_level_index_t p, mdd_level_index_t q)
{
  int i, range;
  evmdd_node_t *np;
  evmdd_node_t *nq;

  if (mdd_level(manager, p) != mdd_level(manager, q))
    return 0;

  np = evmdd_node_get(manager, p);
  nq = evmdd_node_get(manager, q);

  range = manager->ranges[(mdd_level(manager, p)+1)/2];
  for (i = 0; i < range; ++i)
    if (np->edges[i].value != nq->edges[i].value ||
        np->edges[i].node  != nq->edges[i].node)
      return 0;

  return 1;
}
