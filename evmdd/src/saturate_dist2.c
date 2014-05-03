#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "saturate.h"
#include "mdd_node_priv.h"
#include "evmdd_node_priv.h"
#include "events.h"
#include "cache_priv.h"
#include "unique_table_priv.h"
#include "mdd_utils_priv.h"
#include "evmdd_ops.h"

#define CHECK_MDD(manager, level_index)                                 \
  do {                                                                  \
    assert(mdd_index(manager, level_index) <                            \
           manager->mdd_nodes[mdd_level(manager, level_index)].size);   \
    assert(mdd_node_get(manager, level_index)->flags &                  \
           MDD_NODE_ALLOCATED);                                         \
  } while (0)

#define CHECK(manager, level_index)                                     \
  do {                                                                  \
    assert(mdd_index(manager, level_index) <                            \
           manager->evmdd_nodes[mdd_level(manager, level_index)].size); \
    assert(evmdd_node_get(manager, level_index)->flags &                \
           MDD_NODE_ALLOCATED);                                         \
  } while (0)

#ifndef NDEBUG
static int is_quasi_reduced(mdd_manager_t *manager, mdd_level_index_t p)
{
/*   evmdd_node_t *np = evmdd_node_get(manager, p); */
/*   int i, range = manager->ranges[(mdd_level(manager, p)+1)/2]; */

/*   if (p == 0) return 1; */

/*   for (i = 0; i < range; ++i) { */
/*     if (mdd_level(manager, np->edges[i].node) != mdd_level(manager, p) - 2 && */
/*         np->edges[i].value != INT_MAX) */
/*       return 0; */
/*     if (np->edges[i].value < 0) */
/*       return 0; */
/*   } */
    
  return 1;
}
#endif

/* return max of values strictly less than INT_MAX */
static int evmdd_max_finite_rec(mdd_manager_t *manager, mdd_level_index_t p)
{
  int i, range;
  evmdd_node_t *np;
  int m, tmp;

  if (p == 0)
    return 0;

  if (cache_MAX_FINITE_find(manager, mdd_level(manager, p), p, &m))
    return m;

  m = 0;
  np = evmdd_node_get(manager, p);
  range = manager->ranges[(mdd_level(manager, p)+1)/2];
  for (i = 0; i < range; ++i)
    if (np->edges[i].value != INT_MAX) {
      tmp = evmdd_max_finite_rec(manager, np->edges[i].node);
      tmp += np->edges[i].value;
      if (tmp > m) m = tmp;
    }

  cache_MAX_FINITE_add(manager, mdd_level(manager, p), p, m);

  return m;
}

static int evmdd_max_finite(mdd_manager_t *manager, evmdd_edge_t p)
{
  return evmdd_max_finite_rec(manager, p.node)+p.value;
}

/* global arrays used for some statistics */
static unsigned long int *nb_cuts_unreach;
static unsigned long int *nb_cuts_dist;
static unsigned long int *nb_calls;

static evmdd_edge_t evmdd_union_rec(mdd_manager_t *manager, evmdd_edge_t p, evmdd_edge_t q)
{
  evmdd_edge_t r, p0, q0;
  evmdd_node_t *np, *nq, *nr;
  int i, range;

  CHECK(manager, p.node);
  CHECK(manager, q.node);
  assert(is_quasi_reduced(manager, p.node));
  assert(is_quasi_reduced(manager, q.node));

  if (p.value == INT_MAX)
    return q;
  if (q.value == INT_MAX)
    return p;
  if (p.node == 0 && q.node == 0) {
    r.value = p.value < q.value ? p.value : q.value;
    r.node = 0;
    return r;
  }
  if (p.node == q.node)
    return p.value < q.value ? p : q;

  if (cache_UNION_MIN_find(manager, mdd_level(manager, p.node),
                           p.node, q.node, p.value-q.value,
                           &(r.node))) {
    CHECK(manager, r.node);
    r.value = p.value < q.value ? p.value : q.value;
    return r;
  }

  r.value = p.value < q.value ? p.value : q.value;
  r.node = evmdd_node_new(manager, mdd_level(manager, p.node));
  np = evmdd_node_get(manager, p.node);
  nr = evmdd_node_get(manager, r.node);
  ++(nr->flags);  /* protect from deletion */
  range = manager->ranges[mdd_level(manager, p.node)/2];  /* level(p) is even */
  nq = evmdd_node_get(manager, q.node);
  for (i = 0; i < range; ++i) {
    if (np->edges[i].value != INT_MAX)
      p0.value = p.value-r.value+np->edges[i].value;
    else
      p0.value = INT_MAX;
    p0.node = np->edges[i].node;
    if (nq->edges[i].value != INT_MAX)
      q0.value = q.value-r.value+nq->edges[i].value;
    else
      q0.value = INT_MAX;
    q0.node = nq->edges[i].node;
    if (p0.value < evmdd_max_finite(manager, q0))
      nr->edges[i] = evmdd_union_rec(manager, p0, q0);
    else
      nr->edges[i] = q0;
  }
  --(nr->flags);

  r.node = unique_table_evmdd_checkin(manager, r.node);
  CHECK(manager, r.node);

  cache_UNION_MIN_add(manager, mdd_level(manager, p.node),
                      p.node, q.node, p.value-q.value,
                      r.node);

  return r;
}

static void saturate_node(mdd_manager_t*, mdd_level_index_t);

/* Computes the image of p by event e and do the union_min with q.
 * p and q are quasi reduced except for +oo, e is fully-identity reduced
 * requires the image to be included in q
 * requires p.value != +oo, q.value != +oo and e != 0 */
static evmdd_edge_t saturate_fire_rec(mdd_manager_t *manager, evmdd_edge_t p,
                                      mdd_level_index_t e, evmdd_edge_t q)
{
  int i, j, range;
  evmdd_edge_t r, f;
  evmdd_node_t *np, *nr, *nq;
  mdd_node_t *ne, *nechild;
  int change=0;

  int cut_unreach, cut_dist;

  CHECK(manager, p.node);
  CHECK(manager, q.node);
  CHECK_MDD(manager, e);
  assert(p.value != INT_MAX);
  assert(q.value != INT_MAX);
  assert(e != 0);
  assert(mdd_level(manager, p.node) == mdd_level(manager, q.node));
  assert((mdd_level(manager, p.node) & 1) == 0);

  if (p.node == 0) {
    /* equivalent to q.node == 0 since they are both quasi reduced
     * and different from +oo */
    r.node = 0;
    r.value = (p.value+1 < q.value) ? (p.value+1) : q.value;
    return r;
  }
  if (e == 1) {
    r.node = p.node;
    r.value = p.value+1;
    return evmdd_union_rec(manager, r, q);
  }

  if (cache_FIRE_DIST2_find(manager, mdd_level(manager, p.node),
                            p.node, e, q.node, q.value-p.value,
                            &(r.value), &(r.node))) {
    CHECK(manager, r.node);
    assert(r.value != INT_MAX);
    r.value += p.value;
    return r;
  }

  /* initialize r with q */
  r.node = evmdd_node_new(manager, mdd_level(manager, p.node));
  nr = evmdd_node_get(manager, r.node);
  nq = evmdd_node_get(manager, q.node);
  range = manager->ranges[mdd_level(manager, p.node)/2];  /* level(p) is even */
  for (i = 0; i < range; ++i) {
    nr->edges[i].node = nq->edges[i].node;
    if (nq->edges[i].value != INT_MAX)
      nr->edges[i].value = nq->edges[i].value + (q.value - p.value);
    else
      nr->edges[i].value = INT_MAX;
  }

  np = evmdd_node_get(manager, p.node);
  ++(nr->flags);  /* protect from deletion */

  if (mdd_level(manager, p.node)-1 > mdd_level(manager, e)) {
    /* level(p)-1 > level(e)
     * both unprimed and primed skipped */
    for (i = 0; i < range; ++i)
      if (np->edges[i].value != INT_MAX) {
        cut_unreach = nr->edges[i].value == INT_MAX;
        cut_dist = np->edges[i].value >= evmdd_max_finite(manager, nr->edges[i]);
        nb_cuts_unreach[mdd_level(manager, p.node)/2] += cut_unreach;
        nb_cuts_dist[mdd_level(manager, p.node)/2] += cut_dist;
        nb_calls[mdd_level(manager, p.node)/2] += 1;
        if (!cut_unreach && !cut_dist) {
          f = saturate_fire_rec(manager, np->edges[i], e, nr->edges[i]);
          if (f.value != nr->edges[i].value ||
              f.node != nr->edges[i].node) {
            nr->edges[i] = f;
            change = 1;
          }
        }
      }
  } else if (mdd_level(manager, p.node) > mdd_level(manager, e)) {
    /* level(p)-1 = level(e)
     * unprimed skipped */
    ne = mdd_node_get(manager, e);
    for (i = 0; i < range; ++i)
      if (np->edges[i].value != INT_MAX) {
        for (j = 0; j < range; ++j)
          if (ne->children[j]) {
            cut_unreach = nr->edges[j].value == INT_MAX;
            cut_dist = np->edges[i].value >= evmdd_max_finite(manager, nr->edges[j]);
            nb_cuts_unreach[mdd_level(manager, p.node)/2] += cut_unreach;
            nb_cuts_dist[mdd_level(manager, p.node)/2] += cut_dist;
            nb_calls[mdd_level(manager, p.node)/2] += 1;
            if (!cut_unreach && !cut_dist) {
              f = saturate_fire_rec(manager, np->edges[i], ne->children[j], nr->edges[j]);
              if (f.value != nr->edges[j].value ||
                  f.node != nr->edges[j].node) {
                nr->edges[j] = f;
                change = 1;
              }
            }
          }
      }
  } else {
    /* level(p) = level(e) */
    ne = mdd_node_get(manager, e);
    for (i = 0; i < range; ++i)
      if (np->edges[i].value != INT_MAX && ne->children[i]) {
        if (mdd_level(manager, p.node)-1 > mdd_level(manager, ne->children[i])) {
          /* level(p)-1 > level(e[i])
           * primed skipped */
          cut_unreach = nr->edges[i].value == INT_MAX;
          cut_dist = np->edges[i].value >= evmdd_max_finite(manager, nr->edges[i]);
          nb_cuts_unreach[mdd_level(manager, p.node)/2] += cut_unreach;
          nb_cuts_dist[mdd_level(manager, p.node)/2] += cut_dist;
          nb_calls[mdd_level(manager, p.node)/2] += 1;
          if (!cut_unreach && !cut_dist) {
            f = saturate_fire_rec(manager, np->edges[i], ne->children[i], nr->edges[i]);
            if (f.value != nr->edges[i].value ||
                f.node != nr->edges[i].node) {
              nr->edges[i] = f;
              change = 1;
            }
          }
        } else {
          /* level(p)-1 = level(e[i])
           * nothing skipped */
          nechild = mdd_node_get(manager, ne->children[i]);
          for (j = 0; j < range; ++j)
            if (nechild->children[j]) {
              cut_unreach = nr->edges[j].value == INT_MAX;
              cut_dist = np->edges[i].value >= evmdd_max_finite(manager, nr->edges[j]);
              nb_cuts_unreach[mdd_level(manager, p.node)/2] += cut_unreach;
              nb_cuts_dist[mdd_level(manager, p.node)/2] += cut_dist;
              nb_calls[mdd_level(manager, p.node)/2] += 1;
              if (!cut_unreach && !cut_dist) {
                f = saturate_fire_rec(manager, np->edges[i], nechild->children[j], nr->edges[j]);
                if (f.value != nr->edges[j].value ||
                    f.node != nr->edges[j].node) {
                  nr->edges[j] = f;
                  change = 1;
                }
              }
            }
        }
      }
  }

  --(nr->flags);

  /* normalize node */
  r.value = nr->edges[0].value;
  for (i = 0; i < range; ++i)
    if (nr->edges[i].value < r.value)
      r.value = nr->edges[i].value;
  for (i = 0; i < range; ++i)
    if (nr->edges[i].value != INT_MAX)
      nr->edges[i].value -= r.value;

  /* if firing event e changed the node, saturate it again */
  if (change)
    saturate_node(manager, r.node);

  /* check if a node identical to r already exists */
  r.node = unique_table_evmdd_checkin(manager, r.node);
  CHECK(manager, r.node);

  /* save result in cache */
  cache_FIRE_DIST2_add(manager, mdd_level(manager, p.node),
                       p.node, e, q.node, q.value-p.value,
                       r.value, r.node);

  r.value += p.value;
  return r;
}

/* TODO: put this in mdd_manager */
/* extern int nb_printed; */
extern char *dot_output;

/* Applies saturate_fire_rec until a fixpoint is reached.
 * p and q are quasi reduced except for +oo, e is fully identity reduced.
 * requires that the result is included in p
 * from a reachability point of view (some states can be at a closer distance, of course). */
/* p is modified in place */
/* Assume that level(e) = level(p) or level(e) = level(p)-1 (unprimed level skipped) */
static int saturate_fire(mdd_manager_t *manager, mdd_level_index_t p, mdd_level_index_t e)
{
  int i, j, range=manager->ranges[mdd_level(manager, p)/2];  /* level(p) is even */
  evmdd_edge_t f;
  evmdd_node_t *np;
  mdd_node_t *ne, *nechild;
  int *updated = malloc(range*sizeof(int));
  int change, p_has_changed=0;

  int cut_unreach, cut_dist;

  CHECK(manager, p);
  CHECK_MDD(manager, e);
  assert(is_quasi_reduced(manager, p));
  assert((mdd_level(manager, p) & 1) == 0);

  np = evmdd_node_get(manager, p);
  ne = mdd_node_get(manager, e);

  /* determine children which could be affected by event e */
  if (mdd_level(manager, e) & 1)  /* unprimed level skipped */
    for (i = 0; i < range; ++i)
      updated[i] = np->edges[i].value != INT_MAX;
  else
    for (i = 0; i < range; ++i)
      updated[i] = np->edges[i].value != INT_MAX && ne->children[i];

  do {
    change = 0;
    if (mdd_level(manager, p) > mdd_level(manager, e)) {
      /* level(p)-1 = level(e) */
      for (i = 0; i < range; ++i)
        if (updated[i]) {
          updated[i] = 0;
          for (j = 0; j < range; ++j) {
            if (ne->children[j]) {
              cut_unreach = np->edges[j].value == INT_MAX;
              cut_dist = np->edges[i].value >= evmdd_max_finite(manager, np->edges[j]);
              nb_cuts_unreach[mdd_level(manager, p)/2] += cut_unreach;
              nb_cuts_dist[mdd_level(manager, p)/2] += cut_dist;
              nb_calls[mdd_level(manager, p)/2] += 1;
              if (!cut_unreach && !cut_dist) {
                f = saturate_fire_rec(manager, np->edges[i], ne->children[j], np->edges[j]);
                if (f.value != np->edges[j].value ||
                    f.node != np->edges[j].node) {
                  p_has_changed = 1;
                  change = 1;
                  updated[j] = 1;
                  np->edges[j] = f;
                }
              }
            }
          }
        }
    } else {
      /* level(p) = level(e) */
      for (i = 0; i < range; ++i)
        if (updated[i]) {
          updated[i] = 0;
          if (mdd_level(manager, ne->children[i]) < mdd_level(manager, p)-1) {
            /* level(p)-1 > level(e[i]) */
            cut_unreach = np->edges[i].value == INT_MAX;
            cut_dist = 0 >= evmdd_max_finite_rec(manager, np->edges[i].node);
            nb_cuts_unreach[mdd_level(manager, p)/2] += cut_unreach;
            nb_cuts_dist[mdd_level(manager, p)/2] += cut_dist;
            nb_calls[mdd_level(manager, p)/2] += 1;
            if (!cut_unreach && !cut_dist) {
              f = saturate_fire_rec(manager, np->edges[i], ne->children[i], np->edges[i]);
              if (f.value != np->edges[i].value ||
                  f.node != np->edges[i].node) {
                p_has_changed = 1;
                change = 1;
                updated[i] = 1;
                np->edges[i] = f;
              }
            }
          } else {
            /* level(p)-1 = level(e[i]) */
            nechild = mdd_node_get(manager, ne->children[i]);
            for (j = 0; j < range; ++j) {
              if (nechild->children[j]) {
                cut_unreach = np->edges[j].value == INT_MAX;
                cut_dist = np->edges[i].value >= evmdd_max_finite(manager, np->edges[j]);
                nb_cuts_unreach[mdd_level(manager, p)/2] += cut_unreach;
                nb_cuts_dist[mdd_level(manager, p)/2] += cut_dist;
                nb_calls[mdd_level(manager, p)/2] += 1;
                if (!cut_unreach && !cut_dist) {
                  f = saturate_fire_rec(manager, np->edges[i], nechild->children[j], np->edges[j]);
                  if (f.value != np->edges[j].value ||
                      f.node != np->edges[j].node) {
                    p_has_changed = 1;
                    if (ne->children[j]) {
                      change = 1;
                      updated[j] = 1;
                    }
                    np->edges[j] = f;
                  }
                }
              }
            }
          }
        }
    }
  } while (change);

  free(updated);

  return p_has_changed;
}

/* Applies saturate_fire on r with all events having same top level, until a fixpoint is reached.
 * Requires that any reachable state is included in r. */
/* Assume that r is quasi reduced, except for +oo.
 * (i.e. all even levels and only them) */
/* r is modified in place */
static void saturate_node(mdd_manager_t *manager, mdd_level_index_t r)
{
  evmdd_node_t *nr;
  event_entry_t *e;
  int change;

  CHECK(manager, r);
  assert((mdd_level(manager, r) & 1) == 0);

  if (r == 0) return;

  nr = evmdd_node_get(manager, r);
  ++(nr->flags);  /* protect from deletion */

  do {
    change = 0;
    e = manager->events[mdd_level(manager, r)/2];  /* level(r) is even */
    while (e) {
      change |= saturate_fire(manager, r, e->data);
      e = e->next;
    }
  } while (change);

  --(nr->flags);

/*   if (mdd_level(manager, r) > 30) */
/*     fprintf(stderr, "%s/%d: saturated node %lu in place at level %d\n", __FILE__, __LINE__, r, mdd_level(manager, r)); */
}

/* Requires that any reachable state is included in p. */
/* Assume that p is quasi reduced except for +oo.
 * (i.e. all even levels and only them) */
static mdd_level_index_t saturate_rec(mdd_manager_t *manager, mdd_level_index_t p)
{
  mdd_level_index_t r;
  evmdd_node_t *np, *nr;
  int i, range;

/*   FILE *f; */

  CHECK(manager, p);
  assert((mdd_level(manager, p) & 1) == 0);

  if (p == 0)
    return p;

  r = evmdd_node_new(manager, mdd_level(manager, p));
  np = evmdd_node_get(manager, p);
  nr = evmdd_node_get(manager, r);
  ++(nr->flags);  /* protect from deletion */

  range = manager->ranges[mdd_level(manager, p)/2];  /* level(p) is even */
  for (i = 0; i < range; ++i)
    if (np->edges[i].value)
      nr->edges[i] = np->edges[i];
    else {
      nr->edges[i].value = np->edges[i].value;
      nr->edges[i].node = saturate_rec(manager, np->edges[i].node);
    }

  --(nr->flags);

  saturate_node(manager, r);

  /* check if a node identical to r already exists */
  r = unique_table_evmdd_checkin(manager, r);
  CHECK(manager, r);

/*   if (mdd_level(manager, p) > manager->nb_levels) */
/*     fprintf(stderr, "%s/%d: saturated node %lu at level %d\n", __FILE__, __LINE__, p, mdd_level(manager, p)); */

/*     if (dot_output) { */
/*       f = mdd_utils_nfopen(dot_output, nb_printed, "_saturate_dist.dot"); */
/*       rp.node = r; */
/*       rp.value = 0; */
/*       evmdd_print_dot(manager, rp, f); */
/*       fclose(f); */
/*       ++nb_printed; */
/*     } */

  return r;
}

static evmdd_edge_t unreduce_rec(mdd_manager_t *manager, mdd_level_t k, mdd_level_index_t p)
{
  evmdd_edge_t r={0, 0};
  mdd_node_t *np;
  evmdd_node_t *nr;
  int i, range;

  CHECK_MDD(manager, p);

  if (p == 0 || k == 0) {
    r.value = p ? 0 : INT_MAX;
    return r;
  }

  if (cache_UNREDUCE_DIST_find(manager, k, p, &(r.value), &(r.node))) {
    CHECK(manager, r.node);
    return r;
  }

  r.value = INT_MAX;
  r.node = evmdd_node_new(manager, k);
  nr = evmdd_node_get(manager, r.node);
  ++(nr->flags);  /* protect from deletion */
  range = manager->ranges[k/2];  /* k is even */
  if (k > mdd_level(manager, p))
    for (i = 0; i < range; ++i) {
      nr->edges[i] = unreduce_rec(manager, k-2, p);
      if (nr->edges[i].value < r.value)
        r.value = nr->edges[i].value;
    }
  else {  /* k = level(p) */
    np = mdd_node_get(manager, p);
    for (i = 0; i < range; ++i) {
      nr->edges[i] = unreduce_rec(manager, k-2, np->children[i]);
      if (nr->edges[i].value < r.value)
        r.value = nr->edges[i].value;
    }
  }
  for (i = 0; i < range; ++i)
    if (nr->edges[i].value != INT_MAX)
      nr->edges[i].value -= r.value;
  --(nr->flags);

  r.node = unique_table_evmdd_checkin(manager, r.node);
  CHECK(manager, r.node);
  
  cache_UNREDUCE_DIST_add(manager, k, p, r.value, r.node);

  return r;
}

static evmdd_edge_t unreduce(mdd_manager_t *manager, mdd_level_index_t p)
{
  return unreduce_rec(manager, 2*manager->nb_levels, p);
}

static evmdd_edge_t unreduce_evmdd_rec(mdd_manager_t *manager, mdd_level_t k, evmdd_edge_t p)
{
  evmdd_edge_t r={0, 0};
  evmdd_node_t *np, *nr;
  int i, range;

  CHECK(manager, p.node);

  if (p.value == INT_MAX || k == 0) {
    r.value = p.value;
    return r;
  }

  if (cache_UNREDUCE_EVMDD_DIST_find(manager, k, p.node, &(r.node))) {
    CHECK(manager, r.node);
    r.value = p.value;
    return r;
  }

  r.node = evmdd_node_new(manager, k);
  nr = evmdd_node_get(manager, r.node);
  ++(nr->flags);  /* protect from deletion */
  range = manager->ranges[k/2];  /* k is even */
  if (k > mdd_level(manager, p.node)) {
    nr->edges[0] = unreduce_evmdd_rec(manager, k-2, p);
    r.value = nr->edges[0].value;
    nr->edges[0].value = 0;
    for (i = 1; i < range; ++i) {
      nr->edges[i] = nr->edges[0];
      nr->edges[i].value = 0;
    }
  } else {  /* k = level(p) */
    r.value = p.value;
    np = evmdd_node_get(manager, p.node);
    for (i = 0; i < range; ++i)
      nr->edges[i] = unreduce_evmdd_rec(manager, k-2, np->edges[i]);
  }
  --(nr->flags);

  r.node = unique_table_evmdd_checkin(manager, r.node);
  CHECK(manager, r.node);
  
  cache_UNREDUCE_EVMDD_DIST_add(manager, k, p.node, r.node);

  return r;
}

static evmdd_edge_t unreduce_evmdd(mdd_manager_t *manager, evmdd_edge_t p)
{
  return unreduce_evmdd_rec(manager, 2*manager->nb_levels, p);
}

evmdd_edge_t saturate_dist2(mdd_manager_t *manager, mdd_level_index_t s, mdd_level_index_t state_space, int bound)
{
  evmdd_edge_t state_space_0_1, state_space_0_bound;
  evmdd_edge_t state_space_infty_0, state_space_infty_bound;
  evmdd_edge_t state_space_infty_bound_unreduced;
  evmdd_edge_t es;
  evmdd_edge_t init;
  evmdd_edge_t ss={INT_MAX, 0};

  FILE *f;
  int i;

  if (bound < 1) return ss;

  nb_cuts_unreach = calloc(manager->nb_levels+1, sizeof(int));
  nb_cuts_dist = calloc(manager->nb_levels+1, sizeof(int));
  nb_calls = calloc(manager->nb_levels+1, sizeof(int));

  /* TODO: this should be an error (and not an assert) */
  assert((mdd_node_get(manager, s)->flags & MDD_NODE_REFERENCE_COUNT) > 0);
  assert((mdd_node_get(manager, state_space)->flags & MDD_NODE_REFERENCE_COUNT) > 0);

  /* convert state_space into an EVMDD with 1 -> bound and 0 -> +oo */
  state_space_0_1 = evmdd_from_mdd(manager, state_space);
  evmdd_ref(manager, state_space_0_1);
  state_space_0_bound = evmdd_mult_scalar(manager, state_space_0_1, bound);
  evmdd_ref(manager, state_space_0_bound);
  evmdd_unref(manager, state_space_0_1);
  state_space_infty_0 = unreduce(manager, state_space);
  evmdd_ref(manager, state_space_infty_0);
  state_space_infty_bound = evmdd_add(manager, state_space_0_bound, state_space_infty_0);
  evmdd_ref(manager, state_space_infty_bound);
  evmdd_unref(manager, state_space_0_bound);
  evmdd_unref(manager, state_space_infty_0);
  state_space_infty_bound_unreduced = unreduce_evmdd(manager, state_space_infty_bound);
  evmdd_ref(manager, state_space_infty_bound_unreduced);
  evmdd_unref(manager, state_space_infty_bound);

  /* convert initial state into an EVMDD with 1 -> 0 and 0 -> +oo */
  es = unreduce(manager, s);
  evmdd_ref(manager, es);

  init = evmdd_union_rec(manager, es, state_space_infty_bound_unreduced);
  evmdd_ref(manager, init);
  evmdd_unref(manager, state_space_infty_bound_unreduced);
  evmdd_unref(manager, es);

  fprintf(stderr, "%s/%d: unreduced\n", __FILE__, __LINE__);
  printf("Number of reachable states: ");
  bigint_print(evmdd_num_encoded_elements(manager, init), stdout);
  printf("\n");

  if (dot_output) {
    f = mdd_utils_fopen(dot_output, "_unreduced.dot");
    evmdd_print_dot(manager, init, f);
    fclose(f);
  }

  ss.value = init.value;  /* either 0 or \infty */
  ss.node = saturate_rec(manager, init.node);

  evmdd_unref(manager, init);

  for (i = manager->nb_levels; i > 0; --i)
    fprintf(stderr, "  %s/%d: level %d: cuts as unreachable: %.2f %%, cuts because too far: %.2f %%\n", __FILE__, __LINE__,
            i, nb_cuts_unreach[i]*100./nb_calls[i], nb_cuts_dist[i]*100./nb_calls[i]);

  free(nb_cuts_unreach);
  free(nb_cuts_dist);
  free(nb_calls);

  return ss;
}
