#include <stdlib.h>
#include <assert.h>
#include "saturate.h"
#include "mdd_node_priv.h"
#include "events.h"
#include "cache_priv.h"
#include "unique_table_priv.h"

#define CHECK(manager, level_index)                                     \
  do {                                                                  \
    assert(mdd_index(manager, level_index) <                            \
           manager->mdd_nodes[mdd_level(manager, level_index)].size);   \
    assert(mdd_node_get(manager, level_index)->flags &                  \
           MDD_NODE_ALLOCATED);                                         \
  } while (0)

static mdd_level_index_t mdd_union_rec(mdd_manager_t *manager, mdd_level_index_t p, mdd_level_index_t q)
{
  mdd_level_index_t r, tmp;
  mdd_node_t *np, *nq, *nr;
  int i, range;

  CHECK(manager, p);
  CHECK(manager, q);

  if (p == 0)
    return q;
  if (q == 0)
    return p;
  if (p == 1 || q == 1)
    return 1;
  if (p == q) {
    return p;
  }

  if (p < q) {
    tmp = p; p = q; q = tmp;
  }

  if (cache_UNION_UNREDUCED_find(manager, mdd_level(manager, p), p, q, &r)) {
    CHECK(manager, r);
    return r;
  }

  r = mdd_node_new(manager, mdd_level(manager, p));
  np = mdd_node_get(manager, p);
  nq = mdd_node_get(manager, q);
  nr = mdd_node_get(manager, r);
  ++(nr->flags);  /* protect from deletion */
  range = manager->ranges[mdd_level(manager, p)/2];  /* level(p) is even */
  for (i = 0; i < range; ++i) {
    nr->children[i] = mdd_union_rec(manager, np->children[i], nq->children[i]);
    assert(mdd_level(manager, nr->children[i]) == mdd_level(manager, p) - 2 || nr->children[i] == 0);
  }
  --(nr->flags);

  r = unique_table_mdd_checkin(manager, r);
  CHECK(manager, r);

  cache_UNION_UNREDUCED_add(manager, mdd_level(manager, p), p, q, r);

  return r;
}

static mdd_level_index_t saturate_node(mdd_manager_t*, mdd_level_index_t);

static mdd_level_index_t saturate_fire_rec(mdd_manager_t *manager, mdd_level_index_t p, mdd_level_index_t e)
{
  int i, j, range;
  mdd_level_index_t r, f, u;
  mdd_node_t *np, *ne, *nechild, *nr;
  int change=0;

  CHECK(manager, p);
  CHECK(manager, e);

  if (p == 0 || e == 1)
    return p;
  if (e == 0)
    return 0;

  if (cache_FIRE_find(manager, mdd_level(manager, p), p, e, &r)) {
    CHECK(manager, r);
    return r;
  }

  r = mdd_node_new(manager, mdd_level(manager, p));
  np = mdd_node_get(manager, p);
  nr = mdd_node_get(manager, r);
  ++(nr->flags);  /* protect from deletion */

  range = manager->ranges[mdd_level(manager, p)/2];  /* level(p) is even */
  if (mdd_level(manager, p)-1 > mdd_level(manager, e)) {
    /* level(p)-1 > level(e)
     * both unprimed and primed skipped */
    for (i = 0; i < range; ++i)
      if (np->children[i]) {
        f = saturate_fire_rec(manager, np->children[i], e);
        ++(mdd_node_get(manager, f)->flags);
        u = mdd_union_rec(manager, f, nr->children[i]);
        --(mdd_node_get(manager, f)->flags);
        if (u != nr->children[i]) {
          nr->children[i] = u;
          assert(mdd_level(manager, nr->children[i]) == mdd_level(manager, p) - 2 || nr->children[i] == 0);
          change = 1;
        }
      }
  } else if (mdd_level(manager, p) > mdd_level(manager, e)) {
    /* level(p)-1 = level(e)
     * unprimed skipped */
    ne = mdd_node_get(manager, e);
    for (i = 0; i < range; ++i)
      if (np->children[i]) {
        for (j = 0; j < range; ++j)
          if (ne->children[j]) {
            f = saturate_fire_rec(manager, np->children[i], ne->children[j]);
            ++(mdd_node_get(manager, f)->flags);
            u = mdd_union_rec(manager, f, nr->children[j]);
            --(mdd_node_get(manager, f)->flags);
            if (u != nr->children[j]) {
              nr->children[j] = u;
              assert(mdd_level(manager, nr->children[j]) == mdd_level(manager, p) - 2);
              change = 1;
            }
          }
      }
  } else {
    /* level(p) = level(e) */
    ne = mdd_node_get(manager, e);
    for (i = 0; i < range; ++i)
      if (np->children[i] && ne->children[i]) {
        if (mdd_level(manager, p)-1 > mdd_level(manager, ne->children[i])) {
          /* level(p)-1 > level(e[i])
           * primed skipped */
          f = saturate_fire_rec(manager, np->children[i], ne->children[i]);
          ++(mdd_node_get(manager, f)->flags);
          u = mdd_union_rec(manager, f, nr->children[i]);
          --(mdd_node_get(manager, f)->flags);
          if (u != nr->children[i]) {
            nr->children[i] = u;
            assert(mdd_level(manager, nr->children[i]) == mdd_level(manager, p) - 2);
            change = 1;
          }
        } else {
          /* level(p)-1 = level(e[i])
           * nothing skipped */
          nechild = mdd_node_get(manager, ne->children[i]);
          for (j = 0; j < range; ++j)
            if (nechild->children[j]) {
              f = saturate_fire_rec(manager, np->children[i], nechild->children[j]);
              ++(mdd_node_get(manager, f)->flags);
              u = mdd_union_rec(manager, f, nr->children[j]);
              --(mdd_node_get(manager, f)->flags);
              if (u != nr->children[j]) {
                nr->children[j] = u;
                assert(mdd_level(manager, nr->children[j]) == mdd_level(manager, p) - 2 || nr->children[j] == 0);
                change = 1;
              }
            }
        }
      }
  }

  --(nr->flags);

  if (change)
    r = saturate_node(manager, r);
  else {
    /* check that the node is not redundant 0 */
    for (i = nr->children[0] == 0 ? 1 : range+1;
         i < range &&
           nr->children[0] == nr->children[i];
         ++i);
    if (i == range) {  /* node is redundant */
      f = nr->children[0];
      mdd_node_free(manager, r);
      r = f;
    } else {
      r = unique_table_mdd_checkin(manager, r);
      CHECK(manager, r);
    }
  }

  cache_FIRE_add(manager, mdd_level(manager, p), p, e, r);

  return r;
}

/* TODO: put this in mdd_manager */
/* extern int nb_printed; */
/* extern char *dot_output; */

/* Assume that level(e) = level(p) or level(e) = level(p)-1 (unprimed level skipped) */
static int saturate_fire(mdd_manager_t *manager, mdd_level_index_t p, mdd_level_index_t e)
{
  int i, j, range=manager->ranges[mdd_level(manager, p)/2];  /* level(p) is even */
  mdd_level_index_t f, u;
  mdd_node_t *np, *ne, *nechild;
  int *updated = malloc(range*sizeof(int));
  int change, p_has_changed=0;
  char *sn = (char*) malloc(128);

  CHECK(manager, p);
  CHECK(manager, e);

  np = mdd_node_get(manager, p);
  ne = mdd_node_get(manager, e);

  /* determine children which could be affected by event e */
  if (mdd_level(manager, e) & 1)  /* unprimed level skipped */
    for (i = 0; i < range; ++i)
      updated[i] = np->children[i];
  else
    for (i = 0; i < range; ++i)
      updated[i] = np->children[i] && ne->children[i];

  do {
    change = 0;
    if (mdd_level(manager, p) > mdd_level(manager, e)) {
      /* level(p)-1 = level(e) */
      for (i = 0; i < range; ++i)
        if (updated[i]) {
          updated[i] = 0;
          for (j = 0; j < range; ++j)
            if (ne->children[j]) {
              f = saturate_fire_rec(manager, np->children[i], ne->children[j]);
              if (f) {
                ++(mdd_node_get(manager, f)->flags);
                u = mdd_union_rec(manager, f, np->children[j]);
                --(mdd_node_get(manager, f)->flags);
                if (u != np->children[j]) {
/*
                  if (mdd_level(manager, p) >= 2*manager->nb_levels - 1) {
                    mdd_node_pair(manager, u, sn);
                    fprintf(stderr, "Setting arc #%d of root to %s. (le=lp-1)\n", j, sn);
                  }
*/
                  p_has_changed = 1;
                  change = 1;
                  updated[j] = 1;
                  np->children[j] = u;
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
            f = saturate_fire_rec(manager, np->children[i], ne->children[i]);
            if (f) {
              ++(mdd_node_get(manager, f)->flags);
              u = mdd_union_rec(manager, f, np->children[i]);
              --(mdd_node_get(manager, f)->flags);
              if (u != np->children[i]) {
/*
                  if (mdd_level(manager, p) >= 2*manager->nb_levels - 1) {
                    mdd_node_pair(manager, u, sn);
                    fprintf(stderr, "Setting arc #%d of root to %s. (lp=le)\n", j, sn);
                  }
*/
                p_has_changed = 1;
                change = 1;
                updated[i] = 1;
                np->children[i] = u;
              }
            }
          } else {
            /* level(p)-1 = level(e[i]) */
            nechild = mdd_node_get(manager, ne->children[i]);
            for (j = 0; j < range; ++j) {
              if (nechild->children[j]) {
                f = saturate_fire_rec(manager, np->children[i], nechild->children[j]);
                if (f) {
                  ++(mdd_node_get(manager, f)->flags);
                  u = mdd_union_rec(manager, f, np->children[j]);
                  --(mdd_node_get(manager, f)->flags);
                  if (u != np->children[j]) {
/*
                  if (mdd_level(manager, p) >= 2*manager->nb_levels - 1) {
                    mdd_node_pair(manager, u, sn);
                    fprintf(stderr, "Setting arc #%d of root to %s (lei=lp-1).\n", j, sn);
                  }
*/
                    p_has_changed = 1;
                    if (ne->children[j]) {
                      change = 1;
                      updated[j] = 1;
                    }
                    np->children[j] = u;
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
static mdd_level_index_t saturate_node(mdd_manager_t *manager, mdd_level_index_t r)
{
  mdd_node_t *nr;
  event_entry_t *e;
  int change;
/*
  char *sn = (char*)malloc(128);
*/

  if (r <= 1)
    return r;

  nr = mdd_node_get(manager, r);
  ++(nr->flags);  /* protect from deletion */
/*
  if (mdd_level(manager, r) >= 2*manager->nb_levels-1) {
    mdd_node_pair(manager, r, sn);
    fprintf(stderr, "Saturating node %s.\n", sn);
  }
*/
  do {
    change = 0;
    e = manager->events[mdd_level(manager, r)/2];  /* level(r) is even */
    while (e) {
      change |= saturate_fire(manager, r, e->data);
      e = e->next;
    }
  } while (change);

  --(nr->flags);

  r = unique_table_mdd_checkin(manager, r);
  CHECK(manager, r);

  return r;
}

/* Assume that p is quasi reduced.
 * (i.e. all even levels and only them) */
static mdd_level_index_t saturate_rec(mdd_manager_t *manager, mdd_level_index_t p)
{
  mdd_level_index_t r;
  mdd_node_t *np, *nr;
  int i, range;

  CHECK(manager, p);

  if (p <= 1)
    return p;

  r = mdd_node_new(manager, mdd_level(manager, p));
  np = mdd_node_get(manager, p);
  nr = mdd_node_get(manager, r);
  ++(nr->flags);  /* protect from deletion */

  range = manager->ranges[mdd_level(manager, p)/2];  /* level(p) is even */
  for (i = 0; i < range; ++i) {
    nr->children[i] = saturate_rec(manager, np->children[i]);
    assert(mdd_level(manager, nr->children[i]) == mdd_level(manager, p) - 2 || nr->children[i] == 0);
  }

  --(nr->flags);

  r = saturate_node(manager, r);

  return r;
}

static mdd_level_index_t unreduce_rec(mdd_manager_t *manager, mdd_level_t k, mdd_level_index_t p)
{
  mdd_level_index_t r;
  mdd_node_t *np, *nr;
  int i, range;

  CHECK(manager, p);

  if (p == 0 || k == 0)
    return p;

  if (cache_UNREDUCE_find(manager, k, p, &r)) {
    CHECK(manager, r);
    return r;
  }

  r = mdd_node_new(manager, k);
  nr = mdd_node_get(manager, r);
  ++(nr->flags);  /* protect from deletion */
  range = manager->ranges[k/2];  /* k is even */
  if (k > mdd_level(manager, p))
    for (i = 0; i < range; ++i) {
      nr->children[i] = unreduce_rec(manager, k-2, p);
      assert(mdd_level(manager, nr->children[i]) == k-2);
    }
  else {  /* k = level(p) */
    np = mdd_node_get(manager, p);
    for (i = 0; i < range; ++i) {
      nr->children[i] = unreduce_rec(manager, k-2, np->children[i]);
      assert(mdd_level(manager, nr->children[i]) == k-2 || nr->children[i] == 0);
    }
  }
  --(nr->flags);

  r = unique_table_mdd_checkin(manager, r);
  CHECK(manager, r);
  
  cache_UNREDUCE_add(manager, k, p, r);

  return r;
}

static mdd_level_index_t unreduce(mdd_manager_t *manager, mdd_level_index_t p)
{
  return unreduce_rec(manager, 2*manager->nb_levels, p);
}

static mdd_level_index_t reduce_rec(mdd_manager_t *manager, mdd_level_index_t p)
{
  mdd_level_index_t r, tmp;
  mdd_node_t *np, *nr;
  int i, range;

  CHECK(manager, p);

  if (p <= 1)
    return p;

  if (cache_REDUCE_find(manager, mdd_level(manager, p), p, &r)) {
    CHECK(manager, r);
    return r;
  }

  r = mdd_node_new(manager, mdd_level(manager, p));
  np = mdd_node_get(manager, p);
  nr = mdd_node_get(manager, r);
  ++(nr->flags);  /* protect from deletion */
  range = manager->ranges[mdd_level(manager, p)/2];  /* level(p) is even */
  for (i = 0; i < range; ++i)
    nr->children[i] = reduce_rec(manager, np->children[i]);
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

  cache_REDUCE_add(manager, mdd_level(manager, p), p, r);

  return r;
}

mdd_level_index_t saturate(mdd_manager_t *manager, mdd_level_index_t s)
{
  mdd_level_index_t unreduced_ss, ss;
/*   FILE *f; */

  /* TODO: this should be an error (and not an assert) */
  assert((mdd_node_get(manager, s)->flags & MDD_NODE_REFERENCE_COUNT) > 0);

  s = unreduce(manager, s);
  mdd_ref(manager, s);

/*     if (dot_output) { */
/*       f = mdd_utils_fopen(dot_output, "_unreduce.dot"); */
/*       mdd_print_dot(manager, s, f); */
/*       fclose(f); */
/*     } */

  unreduced_ss = saturate_rec(manager, s);

  mdd_unref(manager, s);

  mdd_ref(manager, unreduced_ss);
  ss = reduce_rec(manager, unreduced_ss);
  mdd_unref(manager, unreduced_ss);

  return ss;
}
