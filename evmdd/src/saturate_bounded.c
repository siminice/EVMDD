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

/* return p with all points at distance greater or equal bound put to INT_MAX */
evmdd_edge_t evmdd_bound_rec(mdd_manager_t *manager, evmdd_edge_t p, int bound)
{
  evmdd_edge_t r;
  evmdd_node_t *np, *nr;
  int i, range;

  CHECK(manager, p.node);

  if (bound <= p.value) {
    r.value = INT_MAX;
    r.node = 0;
    return r;
  }

  if (evmdd_max_finite_rec(manager, p.node)+p.value < bound)
    return p;

  if (cache_BOUND_find(manager, mdd_level(manager, p.node),
                       p.node, bound-p.value,
                       &(r.node))) {
    CHECK(manager, r.node);
    r.value = p.value;
    return r;
  }

  r.value = p.value;
  r.node = evmdd_node_new(manager, mdd_level(manager, p.node));
  np = evmdd_node_get(manager, p.node);
  nr = evmdd_node_get(manager, r.node);
  ++(nr->flags);  /* protect from deletion */
  range = manager->ranges[mdd_level(manager, p.node)/2];  /* level(p) is even */
  for (i = 0; i < range; ++i)
    nr->edges[i] = evmdd_bound_rec(manager, np->edges[i], bound-p.value);
  --(nr->flags);
  
  r.node = unique_table_evmdd_checkin(manager, r.node);
  CHECK(manager, r.node);
  
  cache_BOUND_add(manager, mdd_level(manager, p.node),
                  p.node, bound-p.value,
                  r.node);
  
  return r;
}

static evmdd_edge_t evmdd_union_rec(mdd_manager_t *manager, evmdd_edge_t p, evmdd_edge_t q)
{
  evmdd_edge_t r, tmp, p0, q0;
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

  if (p.node < q.node) {
    tmp = p; p = q; q = tmp;
  }

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
  if (mdd_level(manager, p.node) > mdd_level(manager, q.node))
    for (i = 0; i < range; ++i) {
      if (np->edges[i].value != INT_MAX)
        p0.value = p.value-r.value+np->edges[i].value;
      else
        p0.value = INT_MAX;
      p0.node = np->edges[i].node;
      nr->edges[i] = evmdd_union_rec(manager, p0, q);
    }
  else {  /* level(p) = level(q) */
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
      nr->edges[i] = evmdd_union_rec(manager, p0, q0);
    }
  }
  --(nr->flags);

  r.node = unique_table_evmdd_checkin(manager, r.node);
  CHECK(manager, r.node);

  cache_UNION_MIN_add(manager, mdd_level(manager, p.node),
                      p.node, q.node, p.value-q.value,
                      r.node);

  return r;
}

static mdd_level_index_t saturate_node(mdd_manager_t*, mdd_level_index_t, int);

static evmdd_edge_t saturate_fire_rec(mdd_manager_t *manager, evmdd_edge_t p, mdd_level_index_t e, int bound)
{
  int i, j, range;
  evmdd_edge_t r, f, u;
  evmdd_node_t *np, *nr;
  mdd_node_t *ne, *nechild;
  int change=0;

  CHECK(manager, p.node);
  CHECK_MDD(manager, e);

  if (p.node == 0 || e == 1)
    return p;
  if (e == 0) {
    r.value = INT_MAX;
    r.node = 0;
    return r;
  }

  if (cache_FIRE_BOUND_find(manager, mdd_level(manager, p.node),
                            p.node, e, bound-p.value,
                            &(r.value), &(r.node))) {
    CHECK(manager, r.node);
    if (r.value != INT_MAX) {
      r.value += p.value;
    }
    return r;
  }

  r.value = INT_MAX;
  r.node = evmdd_node_new(manager, mdd_level(manager, p.node));
  np = evmdd_node_get(manager, p.node);
  nr = evmdd_node_get(manager, r.node);
  ++(nr->flags);  /* protect from deletion */

  range = manager->ranges[mdd_level(manager, p.node)/2];  /* level(p) is even */
  for (i = 0; i < range; ++i)
    nr->edges[i].value = INT_MAX;
  if (mdd_level(manager, p.node)-1 > mdd_level(manager, e)) {
    /* level(p)-1 > level(e)
     * both unprimed and primed skipped */
    for (i = 0; i < range; ++i)
      if (np->edges[i].value != INT_MAX) {
        f = saturate_fire_rec(manager, np->edges[i], e, bound-p.value);
        ++(evmdd_node_get(manager, f.node)->flags);
        u = evmdd_union_rec(manager, f, nr->edges[i]);
        --(evmdd_node_get(manager, f.node)->flags);
        if (u.value != nr->edges[i].value ||
            u.node != nr->edges[i].node) {
          nr->edges[i] = u;
          if (nr->edges[i].value < r.value)
            r.value = nr->edges[i].value;
          change = 1;
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
            f = saturate_fire_rec(manager, np->edges[i], ne->children[j], bound-p.value);
            ++(evmdd_node_get(manager, f.node)->flags);
            u = evmdd_union_rec(manager, f, nr->edges[j]);
            --(evmdd_node_get(manager, f.node)->flags);
            if (u.value != nr->edges[j].value ||
                u.node != nr->edges[j].node) {
              nr->edges[j] = u;
              if (nr->edges[j].value < r.value)
                r.value = nr->edges[j].value;
              change = 1;
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
          f = saturate_fire_rec(manager, np->edges[i], ne->children[i], bound-p.value);
          ++(evmdd_node_get(manager, f.node)->flags);
          u = evmdd_union_rec(manager, f, nr->edges[i]);
          --(evmdd_node_get(manager, f.node)->flags);
          if (u.value != nr->edges[i].value ||
              u.node != nr->edges[i].node) {
            nr->edges[i] = u;
            if (nr->edges[i].value < r.value)
              r.value = nr->edges[i].value;
            change = 1;
          }
        } else {
          /* level(p)-1 = level(e[i])
           * nothing skipped */
          nechild = mdd_node_get(manager, ne->children[i]);
          for (j = 0; j < range; ++j)
            if (nechild->children[j]) {
              f = saturate_fire_rec(manager, np->edges[i], nechild->children[j], bound-p.value);
              ++(evmdd_node_get(manager, f.node)->flags);
              u = evmdd_union_rec(manager, f, nr->edges[j]);
              --(evmdd_node_get(manager, f.node)->flags);
              if (u.value != nr->edges[j].value ||
                  u.node != nr->edges[j].node) {
                nr->edges[j] = u;
                if (nr->edges[j].value < r.value)
                  r.value = nr->edges[j].value;
                change = 1;
              }
            }
        }
      }
  }

  --(nr->flags);

  /* check that the node is not redundant \infty
   * (MDD is quasi reduced except for \infty) */
  if (r.value == INT_MAX) {
    evmdd_node_free(manager, r.node);
    r.node = 0;
  } else {
    for (i = 0; i < range; ++i) {
      if (nr->edges[i].value != INT_MAX)
        nr->edges[i].value -= r.value;
    }
    if (change)
      r.node = saturate_node(manager, r.node, bound-r.value-p.value);
    else {
      r.node = unique_table_evmdd_checkin(manager, r.node);
      CHECK(manager, r.node);
    }
  }

  cache_FIRE_BOUND_add(manager, mdd_level(manager, p.node),
                       p.node, e, bound-p.value,
                       r.value, r.node);

  if (r.value != INT_MAX)
    r.value += p.value;

  return r;
}

/* TODO: put this in mdd_manager */
/* extern int nb_printed; */
/* extern char *dooutput_t; */

/* Assume that level(e) = level(p) or level(e) = level(p)-1 (unprimed level skipped) */
static int saturate_fire(mdd_manager_t *manager, mdd_level_index_t p, mdd_level_index_t e, int bound)
{
  int i, j, range=manager->ranges[mdd_level(manager, p)/2];  /* level(p) is even */
  evmdd_edge_t fu, f, u;
  evmdd_node_t *np;
  mdd_node_t *ne, *nechild;
  int *updated = malloc(range*sizeof(int));
  int change, p_has_changed=0;

  CHECK(manager, p);
  CHECK_MDD(manager, e);
  assert(is_quasi_reduced(manager, p));

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
          for (j = 0; j < range; ++j)
            if (ne->children[j]) {
              fu = saturate_fire_rec(manager, np->edges[i], ne->children[j], bound);
              if (fu.value != INT_MAX) {
                ++(fu.value);
                ++(evmdd_node_get(manager, fu.node)->flags);
                f = evmdd_bound_rec(manager, fu, bound);
                ++(evmdd_node_get(manager, f.node)->flags);
                --(evmdd_node_get(manager, fu.node)->flags);
                u = evmdd_union_rec(manager, f, np->edges[j]);
                --(evmdd_node_get(manager, f.node)->flags);
                if (u.value != np->edges[j].value ||
                    u.node != np->edges[j].node) {
                  p_has_changed = 1;
                  change = 1;
                  updated[j] = 1;
                  np->edges[j] = u;
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
            fu = saturate_fire_rec(manager, np->edges[i], ne->children[i], bound);
            if (fu.value != INT_MAX) {
              ++(fu.value);
              ++(evmdd_node_get(manager, fu.node)->flags);
              f = evmdd_bound_rec(manager, fu, bound);
              ++(evmdd_node_get(manager, f.node)->flags);
              --(evmdd_node_get(manager, fu.node)->flags);
              u = evmdd_union_rec(manager, f, np->edges[i]);
              --(evmdd_node_get(manager, f.node)->flags);
              if (u.value != np->edges[i].value ||
                  u.node != np->edges[i].node) {
                p_has_changed = 1;
                change = 1;
                updated[i] = 1;
                np->edges[i] = u;
              }
            }
          } else {
            /* level(p)-1 = level(e[i]) */
            nechild = mdd_node_get(manager, ne->children[i]);
            for (j = 0; j < range; ++j) {
              if (nechild->children[j]) {
                fu = saturate_fire_rec(manager, np->edges[i], nechild->children[j], bound);
                if (fu.value != INT_MAX) {
                  ++(fu.value);
                  ++(evmdd_node_get(manager, fu.node)->flags);
                  f = evmdd_bound_rec(manager, fu, bound);
                  ++(evmdd_node_get(manager, f.node)->flags);
                  --(evmdd_node_get(manager, fu.node)->flags);
                  u = evmdd_union_rec(manager, f, np->edges[j]);
                  --(evmdd_node_get(manager, f.node)->flags);
                  if (u.value != np->edges[j].value ||
                      u.node != np->edges[j].node) {
                    p_has_changed = 1;
                    if (ne->children[j]) {
                      change = 1;
                      updated[j] = 1;
                    }
                    np->edges[j] = u;
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

/* Assume that r is quasi reduced.
 * (i.e. all even levels and only them) */
static mdd_level_index_t saturate_node(mdd_manager_t *manager, mdd_level_index_t r, int bound)
{
  evmdd_node_t *nr;
  event_entry_t *e;
  int change;

  CHECK(manager, r);

  if (r == 0)
    return r;

  nr = evmdd_node_get(manager, r);
  ++(nr->flags);  /* protect from deletion */

  do {
    change = 0;
    e = manager->events[mdd_level(manager, r)/2];  /* level(r) is even */
    while (e) {
      change |= saturate_fire(manager, r, e->data, bound);
      e = e->next;
    }
  } while (change);

  --(nr->flags);

  r = unique_table_evmdd_checkin(manager, r);
  CHECK(manager, r);

/*   if (mdd_level(manager, r) > 30) */
/*     fprintf(stderr, "%s/%d: saturated node %lu in place at level %d\n", __FILE__, __LINE__, r, mdd_level(manager, r)); */

  return r;
}

/* Assume that p is quasi reduced.
 * (i.e. all even levels and only them) */
static mdd_level_index_t saturate_rec(mdd_manager_t *manager, mdd_level_index_t p, int bound)
{
  mdd_level_index_t r;
  evmdd_node_t *np, *nr;
  int i, range;

/*   evmdd_edge_t rp; */
/*   FILE *f; */

  CHECK(manager, p);

  if (p == 0)
    return p;

  r = evmdd_node_new(manager, mdd_level(manager, p));
  np = evmdd_node_get(manager, p);
  nr = evmdd_node_get(manager, r);
  ++(nr->flags);  /* protect from deletion */

  range = manager->ranges[mdd_level(manager, p)/2];  /* level(p) is even */
  for (i = 0; i < range; ++i) {
    nr->edges[i].value = np->edges[i].value;
    nr->edges[i].node = saturate_rec(manager, np->edges[i].node, bound-np->edges[i].value);
  }

  --(nr->flags);

  r = saturate_node(manager, r, bound);

/*   if (mdd_level(manager, p) > manager->nb_levels) */
/*     fprintf(stderr, "%s/%d: saturated node %lu at level %d\n", __FILE__, __LINE__, p, mdd_level(manager, p)); */

/*     if (dooutput_t) { */
/*       f = mdd_utils_nfopen(dooutput_t, nb_printed, "_saturate_dist.dot"); */
/*       rp.node = r; */
/*       rp.value = 0; */
/*       evmdd_prindot_t(manager, rp, f); */
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

evmdd_edge_t saturate_bounded(mdd_manager_t *manager, mdd_level_index_t s, int bound)
{
  evmdd_edge_t es, ss={0, 0};

  /* TODO: this should be an error (and not an assert) */
  assert((mdd_node_get(manager, s)->flags & MDD_NODE_REFERENCE_COUNT) > 0);

  es = unreduce(manager, s);
  evmdd_ref(manager, es);

  fprintf(stderr, "%s/%d: unreduced\n", __FILE__, __LINE__);

  ss.value = es.value;  /* either 0 or \infty */
  ss.node = saturate_rec(manager, es.node, bound);

  fprintf(stderr, "%s/%d: state space computed\n", __FILE__, __LINE__);

  evmdd_unref(manager, es);

  return ss;
}

static void debug_dot_evmdd(mdd_manager_t *manager, mdd_level_index_t p, char *filename)
{
  FILE *f;
  evmdd_edge_t e;

  e.value = 0;
  e.node = p;

  f = mdd_utils_fopen(filename, ".dot");
  evmdd_print_dot(manager, e, f);
  fclose(f);
}

static void debug_dot_mdd(mdd_manager_t *manager, mdd_level_index_t p, char *filename)
{
  FILE *f;

  f = mdd_utils_fopen(filename, ".dot");
  mdd_print_dot(manager, p, f);
  fclose(f);
}
