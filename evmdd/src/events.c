#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "events.h"
#include "mdd_node_priv.h"
#include "unique_table_priv.h"
#include "cache_priv.h"

#define CHECK(manager, level_index)                                     \
  do {                                                                  \
    assert(mdd_index(manager, level_index) <                            \
           manager->mdd_nodes[mdd_level(manager, level_index)].size);   \
    assert(mdd_node_get(manager, level_index)->flags &                  \
           MDD_NODE_ALLOCATED);                                         \
  } while (0)

/* TODO: put this in mdd_manager */
/* extern int verbosity_level; */

static int *used_caches;

static mdd_level_index_t mdd_union_rec(mdd_manager_t *manager, mdd_level_index_t p, mdd_level_index_t q)
{
  int i, j, range;
  mdd_level_index_t r, rchild, tmp;
  mdd_node_t *np, *nq, *npchild, *nqchild, *nr, *nrchild;
  int k;

  CHECK(manager, p);
  CHECK(manager, q);

  if (p == 0)
    return q;
  if (q == 0)
    return p;
  if (p == q)
    return p;
 
  if (p < q) {
    tmp = p; p = q; q = tmp;
  }

  k = (mdd_level(manager, p)+1) & ~1;  /* round to next even */

  if (k == 0)
    return p | q;

  if (cache_UNION_IDENTITY_REDUCED_find(manager, k, p, q, &r)) {
    CHECK(manager, r);
    return r;
  }

  r = mdd_node_new(manager, k);
  np = mdd_node_get(manager, p);
  nr = mdd_node_get(manager, r);
  ++(nr->flags);  /* protect from deletion */

  range = manager->ranges[k/2];  /* k is even */
  if (mdd_level(manager, p) == k) {  /* unprimed not skipped in p */
    if (mdd_level(manager, q) < k-1) {  /* both primed and unprimed skipped in q */
      for (i = 0; i < range; ++i)
        if (mdd_level(manager, np->children[i]) == k-1) {
          rchild = mdd_node_new(manager, k-1);
          nrchild = mdd_node_get(manager, rchild);
          npchild = mdd_node_get(manager, np->children[i]);
          ++(nrchild->flags);
          for (j = 0; j < i; ++j)
            nrchild->children[j] = npchild->children[j];
          nrchild->children[j] = mdd_union_rec(manager, npchild->children[j], q);
          for(++j; j < range; ++j)
            nrchild->children[j] = npchild->children[j];
          --(nrchild->flags);
          rchild = unique_table_mdd_checkin(manager, rchild);
          CHECK(manager, rchild);
          nr->children[i] = rchild;
        } else
          nr->children[i] = mdd_union_rec(manager, np->children[i], q);
    } else if (mdd_level(manager, q) < k) {  /* unprimed skipped in q */
      nq = mdd_node_get(manager, q);
      for (i = 0; i < range; ++i) {
        rchild = mdd_node_new(manager, k-1);
        nrchild = mdd_node_get(manager, rchild);
        ++(nrchild->flags);
        if (mdd_level(manager, np->children[i]) == k-1) {
          npchild = mdd_node_get(manager, np->children[i]);
          for (j = 0; j < range; ++j)
            nrchild->children[j] = mdd_union_rec(manager, npchild->children[j], nq->children[j]);
        } else {
          for (j = 0; j < i; ++j)
            nrchild->children[j] = nq->children[j];
          nrchild->children[j] = mdd_union_rec(manager, np->children[i], nq->children[j]);
          for(++j; j < range; ++j)
            nrchild->children[j] = nq->children[j];
        }
        --(nrchild->flags);
        rchild = unique_table_mdd_checkin(manager, rchild);
        CHECK(manager, rchild);
        nr->children[i] = rchild;
      }
    } else {  /* unprimed not skipped in q */
      /* 4 */
      nq = mdd_node_get(manager, q);
      for (i = 0; i < range; ++i)
        switch ((mdd_level(manager, np->children[i]) == k-1) << 1 |
                (mdd_level(manager, nq->children[i]) == k-1)) {
        case 0 << 1 | 0:
          nr->children[i] = mdd_union_rec(manager, np->children[i], nq->children[i]);
          break;
        case 0 << 1 | 1:
          rchild = mdd_node_new(manager, k-1);
          nrchild = mdd_node_get(manager, rchild);
          nqchild = mdd_node_get(manager, nq->children[i]);
          ++(nrchild->flags);
          for (j = 0; j < i; ++j)
            nrchild->children[j] = nqchild->children[j];
          nrchild->children[j] = mdd_union_rec(manager, np->children[i], nqchild->children[j]);
          for(++j; j < range; ++j)
            nrchild->children[j] = nqchild->children[j];
          --(nrchild->flags);
          rchild = unique_table_mdd_checkin(manager, rchild);
          CHECK(manager, rchild);
          nr->children[i] = rchild;
          break;
        case 1 << 1 | 0:
          rchild = mdd_node_new(manager, k-1);
          nrchild = mdd_node_get(manager, rchild);
          npchild = mdd_node_get(manager, np->children[i]);
          ++(nrchild->flags);
          for (j = 0; j < i; ++j)
            nrchild->children[j] = npchild->children[j];
          nrchild->children[j] = mdd_union_rec(manager, npchild->children[j], nq->children[i]);
          for(++j; j < range; ++j)
            nrchild->children[j] = npchild->children[j];
          --(nrchild->flags);
          rchild = unique_table_mdd_checkin(manager, rchild);
          CHECK(manager, rchild);
          nr->children[i] = rchild;
          break;
        case 1 << 1 | 1:
          rchild = mdd_node_new(manager, k-1);
          nrchild = mdd_node_get(manager, rchild);
          npchild = mdd_node_get(manager, np->children[i]);
          nqchild = mdd_node_get(manager, nq->children[i]);
          ++(nrchild->flags);
          for (j = 0; j < range; ++j)
            nrchild->children[j] = mdd_union_rec(manager, npchild->children[j], nqchild->children[j]);
          --(nrchild->flags);
          rchild = unique_table_mdd_checkin(manager, rchild);
          CHECK(manager, rchild);
          nr->children[i] = rchild;
          break;
        }
    }
  } else {  /* unprimed skipped in p */
    if (mdd_level(manager, q) < k-1) {  /* both primed and unprimed skipped in q */
      for (i = 0; i < range; ++i) {
        rchild = mdd_node_new(manager, k-1);
        nrchild = mdd_node_get(manager, rchild);
        ++(nrchild->flags);
        for (j = 0; j < i; ++j)
          nrchild->children[j] = np->children[j];
        nrchild->children[j] = mdd_union_rec(manager, np->children[j], q);
        for(++j; j < range; ++j)
          nrchild->children[j] = np->children[j];
        --(nrchild->flags);
        rchild = unique_table_mdd_checkin(manager, rchild);
        CHECK(manager, rchild);
        nr->children[i] = rchild;
      }
    } else {  /* only unprimed skipped in q */
      rchild = mdd_node_new(manager, k-1);
      nrchild = mdd_node_get(manager, rchild);
      nq = mdd_node_get(manager, q);
      ++(nrchild->flags);
      for (j = 0; j < range; ++j)
        nrchild->children[j] = mdd_union_rec(manager, np->children[j], nq->children[j]);
      --(nrchild->flags);
      rchild = unique_table_mdd_checkin(manager, rchild);
      CHECK(manager, rchild);
      for (i = 0; i < range; ++i)
        nr->children[i] = rchild;
    }
  }

  --(nr->flags);

  /* check that the node is not redundant */  
  for (i = 1;
       i < range &&
         nr->children[0] == nr->children[i];
       ++i);
  if (i == range) {  /* node is redundant */
    tmp = nr->children[0];
    mdd_node_free(manager, r);
    r = tmp;
  } else {
    r = unique_table_mdd_checkin(manager, r);
    CHECK(manager, r);
  }

  cache_UNION_IDENTITY_REDUCED_add(manager, k, p, q, r);

  return r;
}

static mdd_level_index_t event_add_identities_rec(mdd_manager_t *manager, mdd_level_t k, mdd_level_index_t p, int *indexes);

static mdd_level_index_t event_add_identities_rec_prime(mdd_manager_t *manager, mdd_level_t k, mdd_level_index_t p, int orig_index, int *indexes)
{
  mdd_level_index_t r, tmp;
  mdd_node_t *np, *nr;
  int i, range;

  CHECK(manager, p);

  r = mdd_node_new(manager, k);
  nr = mdd_node_get(manager, r);
  ++(nr->flags);  /* protect from deletion */
  range = manager->ranges[(k+1)/2];
  if (indexes[(k+1)/2]) {  /* constrain by identity */
    if (k > mdd_level(manager, p))
      nr->children[orig_index] = event_add_identities_rec(manager, k-1, p, indexes);
    else {
      np = mdd_node_get(manager, p);
      nr->children[orig_index] = event_add_identities_rec(manager, k-1, np->children[orig_index], indexes);
    }
  } else {  /* no constraint */
    if (k > mdd_level(manager, p))
      for (i = 0; i < range; ++i)
        nr->children[i] = event_add_identities_rec(manager, k-1, p, indexes);
    else {
      np = mdd_node_get(manager, p);
      for (i = 0; i < range; ++i)
        nr->children[i] = event_add_identities_rec(manager, k-1, np->children[i], indexes);
    }
  }
  --(nr->flags);

  /* check that the node is not redundant (identity reduction) */  
  for (i = 0;
       i < range &&
         ((i != orig_index && nr->children[i] == 0) ||
          i == orig_index);
       ++i);
  if (i == range) {  /* node is redundant */
    tmp = nr->children[orig_index];
    mdd_node_free(manager, r);
    r = tmp;
  } else {
    r = unique_table_mdd_checkin(manager, r);
    CHECK(manager, r);
  }

  return r;
}

static mdd_level_index_t event_add_identities_rec(mdd_manager_t *manager, mdd_level_t k, mdd_level_index_t p, int *indexes)
{
  mdd_level_index_t r, tmp;
  mdd_node_t *np, *nr;
  int i, range;

  CHECK(manager, p);

  if (k == 0)
    return p;
 
  for (i = k;
       i >= mdd_level(manager, p) &&
         indexes[i/2];
       i -= 2);
  if (i < mdd_level(manager, p)) i += 2;
  /* between k and i are only identities */
  if (k > i)
    return event_add_identities_rec(manager, i, p, indexes);

  if (cache_ADD_IDENTITIES_find(manager, k, p, &r)) {
    CHECK(manager, r);
    return r;
  }

  r = mdd_node_new(manager, k);
  nr = mdd_node_get(manager, r);
  ++(nr->flags);  /* protect from deletion */
  range = manager->ranges[k/2];  /* k is even */
  if (k > mdd_level(manager, p))
    for (i = 0; i < range; ++i)
      nr->children[i] = event_add_identities_rec_prime(manager, k-1, p, i, indexes);
  else {  /* k = level(p) */
    np = mdd_node_get(manager, p);
    for (i = 0; i < range; ++i)
      nr->children[i] = event_add_identities_rec_prime(manager, k-1, np->children[i], i, indexes);
  }
  --(nr->flags);

  /* check that the node is not redundant */  
  for (i = 1;
       i < range &&
         nr->children[0] == nr->children[i];
       ++i);
  if (i == range) {  /* node is redundant */
    tmp = nr->children[0];
    mdd_node_free(manager, r);
    r = tmp;
  } else {
    r = unique_table_mdd_checkin(manager, r);
    CHECK(manager, r);
  }

  cache_ADD_IDENTITIES_add(manager, k, p, r);
  used_caches[k/2] = 1;

  return r;
}

/** Intersection of an MDD with identity patterns at indicated levels.
 * Build an MDD identity reduced (on odd levels and regularly reduced
 * on even levels) being the intersection of p and an MDD
 * with identity patterns at levels k
 * for which indexes[k] != 0 and nodes with all children pointing
 * on the same child elsewhere (meaning "don't care").
 * @param manager the manager
 * @param indexes array of size manager->nb_levels+1
 * in which indexes[k] is non null iff we want an identity at this level
 */
static mdd_level_index_t event_add_identities(mdd_manager_t *manager, mdd_level_index_t p, int *indexes)
{
  mdd_level_index_t r;
  int k;

  used_caches = calloc(manager->nb_levels+1, sizeof(int));

  r = event_add_identities_rec(manager, 2*manager->nb_levels, p, indexes);

  /* clean cache beacause result depend from indexes
   * which is not part of cache entries (it'as an array of size nb_levels) */
  for (k = 2*manager->nb_levels; k; k -= 2)
    if (used_caches[k/2])
      cache_mdd_cleanup(manager, MDD_O_ADD_IDENTITIES, k);

  free(used_caches);

  return r;
}

/* TODO: put this in mdd_manager */
/* extern char *dot_output; */
/* int nb_printed=0; */

void event_register_name_merge(mdd_manager_t *manager, mdd_level_index_t p, int *indexes, char *name, int merge)
{
  event_entry_t *entry;
  mdd_level_index_t u;
  mdd_level_t event_level;

  if (p == 0) return;

  if (indexes != NULL)
    p = event_add_identities(manager, p, indexes);
  else {
    indexes = calloc(manager->nb_levels+1, sizeof(int));
    p = event_add_identities(manager, p, indexes);
    free(indexes);
  }

  /* we have to protect the diagram from deletion by garbage collection */
  mdd_ref(manager, p);

  CHECK(manager, p);

  event_level = (mdd_level(manager, p)+1)/2;

  if (manager->events[event_level] && merge) {
    entry = manager->events[event_level];
    u = mdd_union_rec(manager, p, entry->data);
    mdd_ref(manager, u);
    mdd_unref(manager, entry->data);
    entry->data = u;
  } else {
    entry = malloc(sizeof(event_entry_t));
    manager->currently_allocated += sizeof(event_entry_t);
    entry->data = p;
    if (name) {
      entry->name = malloc(strlen(name)+1);
      manager->currently_allocated += strlen(name)+1;
      strcpy(entry->name, name); 
    } else {
      entry->name = NULL;
    }
    entry->name = name;
    entry->next = manager->events[event_level];
    manager->events[event_level] = entry;
  }
}

void event_register(mdd_manager_t *manager, mdd_level_index_t p, int *indexes)
{
  event_register_name_merge(manager, p, indexes, NULL, 1);
}

/* Computes the union of all previously registered events
 * (i.e. the entire transtion relation)
 * and put it in manager->all_events. */
void event_union_all(mdd_manager_t *manager)
{
  int k;
  event_entry_t *entry;
  mdd_level_index_t u;

  for (k = 1; k <= manager->nb_levels; ++k) {
    entry = manager->events[k];
    while (entry) {
      u = mdd_union_rec(manager, entry->data, manager->all_events);
      mdd_ref(manager, u);
      if (manager->all_events) mdd_unref(manager, manager->all_events);
      manager->all_events = u;
      entry = entry->next;
    }
  }
}
