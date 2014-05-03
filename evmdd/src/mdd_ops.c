#include <limits.h>
#include <stdlib.h>  /* DEBUG */
#include <stdio.h>  /* DEBUG */
#include <assert.h>
#include "mdd_ops.h"
#include "mdd_manager_priv.h"
#include "mdd_node_priv.h"
#include "unique_table_priv.h"
#include "cache_priv.h"
#include "mdd_utils_priv.h"

#define CHECK(manager, level_index)                                     \
  do {                                                                  \
    assert(mdd_index(manager, level_index) <                            \
           manager->mdd_nodes[mdd_level(manager, level_index)].size);   \
    assert(mdd_node_get(manager, level_index)->flags &                  \
           MDD_NODE_ALLOCATED);                                         \
    assert(mdd_level(manager, level_index) > 0 ||                       \
           mdd_index(manager, level_index) <= 1);                       \
  } while (0)

mdd_level_index_t mdd_not_rec(mdd_manager_t *manager, mdd_level_index_t p)
{
  mdd_level_index_t r;
  mdd_node_t *np, *nr;
  int i, range;

  CHECK(manager, p);

  if (p <= 1)
    return 1-p;

  if (cache_NOT_find(manager, mdd_level(manager, p), p, &r)) {
    CHECK(manager, r);
    return r;
  }

  r = mdd_node_new(manager, mdd_level(manager, p));
  np = mdd_node_get(manager, p);
  nr = mdd_node_get(manager, r);
  ++(nr->flags);  /* protect from deletion */
  range = manager->ranges[(mdd_level(manager, p)+1)/2];
  for (i = 0; i < range; ++i)
    nr->children[i] = mdd_not_rec(manager, np->children[i]);
  --(nr->flags);

  r = unique_table_mdd_checkin(manager, r);  
  CHECK(manager, r);

  cache_NOT_add(manager, mdd_level(manager, p), p, r);

  return r;
}

mdd_level_index_t mdd_not(mdd_manager_t *manager, mdd_level_index_t p)
{
  /* TODO: this should be an error (and not an assert) */
  assert((mdd_node_get(manager, p)->flags & MDD_NODE_REFERENCE_COUNT) > 0);

  return mdd_not_rec(manager, p);
}

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
  if (p == q)
    return p;

  if (p < q) {
    tmp = p; p = q; q = tmp;
  }

  if (cache_UNION_find(manager, mdd_level(manager, p), p, q, &r)) {
    CHECK(manager, r);
    return r;
  }

  r = mdd_node_new(manager, mdd_level(manager, p));
  np = mdd_node_get(manager, p);
  nr = mdd_node_get(manager, r);
  ++(nr->flags);  /* protect from deletion */
  range = manager->ranges[(mdd_level(manager, p)+1)/2];
  if (mdd_level(manager, p) > mdd_level(manager, q))
    for (i = 0; i < range; ++i)
      nr->children[i] = mdd_union_rec(manager, np->children[i], q);
  else {  /* level(p) = level(q) */
    nq = mdd_node_get(manager, q);
    for (i = 0; i < range; ++i)
      nr->children[i] = mdd_union_rec(manager, np->children[i], nq->children[i]);
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

  cache_UNION_add(manager, mdd_level(manager, p), p, q, r);

  return r;
}

mdd_level_index_t mdd_union(mdd_manager_t *manager, mdd_level_index_t p, mdd_level_index_t q)
{
  /* TODO: this should be an error (and not an assert) */
  assert((mdd_node_get(manager, p)->flags & MDD_NODE_REFERENCE_COUNT) > 0);
  assert((mdd_node_get(manager, q)->flags & MDD_NODE_REFERENCE_COUNT) > 0);

  return mdd_union_rec(manager, p, q);
}

static mdd_level_index_t mdd_inter_rec(mdd_manager_t *manager, mdd_level_index_t p, mdd_level_index_t q)
{
  mdd_level_index_t r, tmp;
  mdd_node_t *np, *nq, *nr;
  int i, range;

  CHECK(manager, p);
  CHECK(manager, q);

  if (p == 0 || q == 0)
    return 0;
  if (p == 1)
    return q;
  if (q == 1)
    return p;
  if (p == q)
    return p;
 
  if (p < q) {
    tmp = p; p = q; q = tmp;
  }

  if (cache_INTER_find(manager, mdd_level(manager, p), p, q, &r)) {
    CHECK(manager, r);
    return r;
  }

  r = mdd_node_new(manager, mdd_level(manager, p));
  np = mdd_node_get(manager, p);
  nr = mdd_node_get(manager, r);
  ++(nr->flags);  /* protect from deletion */
  range = manager->ranges[(mdd_level(manager, p)+1)/2];
  if (mdd_level(manager, p) > mdd_level(manager, q))
    for (i = 0; i < range; ++i)
      nr->children[i] = mdd_inter_rec(manager, np->children[i], q);
  else {  /* level(p) = level(q) */
    nq = mdd_node_get(manager, q);
    for (i = 0; i < range; ++i)
      nr->children[i] = mdd_inter_rec(manager, np->children[i], nq->children[i]);
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

  cache_INTER_add(manager, mdd_level(manager, p), p, q, r);

  return r;
}

mdd_level_index_t mdd_inter(mdd_manager_t *manager, mdd_level_index_t p, mdd_level_index_t q)
{
  /* TODO: this should be an error (and not an assert) */
  assert((mdd_node_get(manager, p)->flags & MDD_NODE_REFERENCE_COUNT) > 0);
  assert((mdd_node_get(manager, q)->flags & MDD_NODE_REFERENCE_COUNT) > 0);

  return mdd_inter_rec(manager, p, q);
}

static mdd_level_index_t mdd_next_rec(mdd_manager_t *manager, mdd_level_index_t s, mdd_level_index_t f)
{
  int i, j, range;
  mdd_level_index_t r, tmp;
  mdd_node_t *ns, *nf, *nfchild, *nr;
  int k;

  CHECK(manager, s);
  CHECK(manager, f);

  if (s == 0 || f == 0)
    return 0;
  if (f == 1)
    return s;
 
  k = (mdd_level(manager, s > f ? s : f)+1) & ~1;  /* round to next even */

  if (cache_NEXT_find(manager, k, s, f, &r)) {
    CHECK(manager, r);
    return r;
  }

  r = mdd_node_new(manager, k);
  ns = mdd_node_get(manager, s);
  nr = mdd_node_get(manager, r);
  ++(nr->flags);  /* protect from deletion */

  range = manager->ranges[k/2];  /* k is even */
  if (mdd_level(manager, s)-1 > mdd_level(manager, f)) {
    /* level(s)-1 > level(f)
     * both unprimed and primed skipped */
    for (i = 0; i < range; ++i)
      nr->children[i] = mdd_next_rec(manager, ns->children[i], f);
  } else if (mdd_level(manager, s) > mdd_level(manager, f)) {
    /* level(s)-1 = level(f)
     * unprimed skipped */
    nf = mdd_node_get(manager, f);
    for (i = 0; i < range; ++i)
      if (ns->children[i])
        for (j = 0; j < range; ++j)
          if (nf->children[j]) {
            tmp = mdd_next_rec(manager, ns->children[i], nf->children[j]);
            if (nr->children[j]) {
              ++(mdd_node_get(manager, tmp)->flags);
              nr->children[j] = mdd_union_rec(manager, tmp, nr->children[j]);
              --(mdd_node_get(manager, tmp)->flags);
            } else
              nr->children[j] = tmp;
          }
  } else if (mdd_level(manager, s) == mdd_level(manager, f)) {
    /* level(s) = level(f) */
    nf = mdd_node_get(manager, f);
    for (i = 0; i < range; ++i)
      if (ns->children[i] && nf->children[i]) {
        if (mdd_level(manager, s)-1 > mdd_level(manager, nf->children[i])) {
          /* level(s)-1 > level(f[i])
           * primed skipped */
          tmp = mdd_next_rec(manager, ns->children[i], nf->children[i]);
          if (nr->children[i]) {
            ++(mdd_node_get(manager, tmp)->flags);
            nr->children[i] = mdd_union_rec(manager, tmp, nr->children[i]);
            --(mdd_node_get(manager, tmp)->flags);
          } else
            nr->children[i] = tmp;
        } else {
          /* level(s)-1 = level(f[i])
           * nothing skipped */
          nfchild = mdd_node_get(manager, nf->children[i]);
          for (j = 0; j < range; ++j)
            if (nfchild->children[j]) {
              tmp = mdd_next_rec(manager, ns->children[i], nfchild->children[j]);
              if (nr->children[j]) {
                ++(mdd_node_get(manager, tmp)->flags);
                nr->children[j] = mdd_union_rec(manager, tmp, nr->children[j]);
                --(mdd_node_get(manager, tmp)->flags);
              } else
                nr->children[j] = tmp;
            }
        }
      }
  } else if (mdd_level(manager, f) & 1) {
    /* level(s) < level(f) and level(f) odd */
    nf = mdd_node_get(manager, f);
    for (j = 0; j < range; ++j)
      nr->children[j] = mdd_next_rec(manager, s, nf->children[j]);
  } else {
    /* level(s) < level(f) and level(f) even */
    nf = mdd_node_get(manager, f);
    for (i = 0; i < range; ++i)
      if (nf->children[i]) {
        if (k-1 > mdd_level(manager, nf->children[i])) {
          /* k-1 > level(f[i])
           * primed skipped */
          tmp = mdd_next_rec(manager, s, nf->children[i]);
          if (nr->children[i]) {
            ++(mdd_node_get(manager, tmp)->flags);
            nr->children[i] = mdd_union_rec(manager, tmp, nr->children[i]);
            --(mdd_node_get(manager, tmp)->flags);
          } else
            nr->children[i] = tmp;
        } else {
          /* k-1 = level(f[i])
           * nothing skipped */
          nfchild = mdd_node_get(manager, nf->children[i]);
          for (j = 0; j < range; ++j)
            if (nfchild->children[j]) {
              tmp = mdd_next_rec(manager, s, nfchild->children[j]);
              if (nr->children[j]) {
                ++(mdd_node_get(manager, tmp)->flags);
                nr->children[j] = mdd_union_rec(manager, tmp, nr->children[j]);
                --(mdd_node_get(manager, tmp)->flags);
              } else
                nr->children[j] = tmp;
            }
        }
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

  cache_NEXT_add(manager, k, s, f, r);

  return r;
}

mdd_level_index_t mdd_next(mdd_manager_t *manager, mdd_level_index_t s, mdd_level_index_t f)
{
  /* TODO: this should be an error (and not an assert) */
  assert((mdd_node_get(manager, s)->flags & MDD_NODE_REFERENCE_COUNT) > 0);
  assert((mdd_node_get(manager, f)->flags & MDD_NODE_REFERENCE_COUNT) > 0);

  return mdd_next_rec(manager, s, f);
}

/* TODO: improve (write like next but when s is 1, directly answer 1) */
mdd_level_index_t mdd_add_next(mdd_manager_t *manager, mdd_level_index_t s, mdd_level_index_t f)
{
  mdd_level_index_t img = mdd_next(manager, s, f);
  mdd_level_index_t r;

  mdd_ref(manager, img);
  r = mdd_union(manager, s, img);
  mdd_unref(manager, img);

  return r;
}

static mdd_level_index_t mdd_prev_rec(mdd_manager_t *manager, mdd_level_index_t s, mdd_level_index_t f)
{
  int i, j, range;
  mdd_level_index_t r, tmp;
  mdd_node_t *ns, *nf, *nfchild, *nr;
  int k;

  CHECK(manager, s);
  CHECK(manager, f);

  if (s == 0 || f == 0)
    return 0;
  if (f == 1)
    return s;
 
  k = (mdd_level(manager, s > f ? s : f)+1) & ~1;  /* round to next even */

  if (cache_PREV_find(manager, k, s, f, &r)) {
    CHECK(manager, r);
    return r;
  }

  r = mdd_node_new(manager, k);
  ns = mdd_node_get(manager, s);
  nr = mdd_node_get(manager, r);
  ++(nr->flags);  /* protect from deletion */

  range = manager->ranges[k/2];  /* k is even */
  if (mdd_level(manager, s)-1 > mdd_level(manager, f)) {
    /* level(s)-1 > level(f)
     * both unprimed and primed skipped */
    for (i = 0; i < range; ++i)
      nr->children[i] = mdd_prev_rec(manager, ns->children[i], f);
  } else if (mdd_level(manager, s) > mdd_level(manager, f)) {
    /* level(s)-1 = level(f)
     * unprimed skipped */
    nf = mdd_node_get(manager, f);
    for (j = 0; j < range; ++j)
      if (ns->children[j] && nf->children[j]) {
        tmp = mdd_prev_rec(manager, ns->children[j], nf->children[j]);
        ++(mdd_node_get(manager, tmp)->flags);
        nr->children[0] = mdd_union_rec(manager, tmp, nr->children[0]);
        --(mdd_node_get(manager, tmp)->flags);
      }
    for (i = 1; i < range; ++i)  /* TODO: avoid creating this redundant node */
      nr->children[i] = nr->children[0];
  } else if (mdd_level(manager, s) == mdd_level(manager, f)) {
    /* level(s) = level(f) */
    nf = mdd_node_get(manager, f);
    for (i = 0; i < range; ++i)
      if (nf->children[i]) {
        if (mdd_level(manager, s)-1 > mdd_level(manager, nf->children[i])) {
          /* level(s)-1 > level(f[i])
           * primed skipped */
          nr->children[i] = mdd_prev_rec(manager, ns->children[i], nf->children[i]);
        } else {
          /* level(s)-1 = level(f[i])
           * nothing skipped */
          nfchild = mdd_node_get(manager, nf->children[i]);
          for (j = 0; j < range; ++j)
            if (ns->children[j] && nfchild->children[j]) {
              tmp = mdd_prev_rec(manager, ns->children[j], nfchild->children[j]);
              if (nr->children[i]) {
                ++(mdd_node_get(manager, tmp)->flags);
                nr->children[i] = mdd_union_rec(manager, tmp, nr->children[i]);
                --(mdd_node_get(manager, tmp)->flags);
              } else
                nr->children[i] = tmp;
            }
        }
      }
  } else if (mdd_level(manager, f) & 1) {
    /* level(s) < level(f) and level(f) odd */
    nf = mdd_node_get(manager, f);
    for (j = 0; j < range; ++j) {
      tmp = mdd_prev_rec(manager, s, nf->children[j]);
      ++(mdd_node_get(manager, tmp)->flags);
      nr->children[0] = mdd_union_rec(manager, tmp, nr->children[0]);
      --(mdd_node_get(manager, tmp)->flags);
    }
    for (i = 1; i < range; ++i)  /* TODO: avoid creating this redundant node */
      nr->children[i] = nr->children[0];
  } else {
    /* level(s) < level(f) and level(f) even */
    nf = mdd_node_get(manager, f);
    for (i = 0; i < range; ++i)
      if (nf->children[i]) {
        if (k-1 > mdd_level(manager, nf->children[i])) {
          /* k-1 > level(f[i])
           * primed skipped */
          nr->children[i] = mdd_prev_rec(manager, s, nf->children[i]);
        } else {
          /* k-1 = level(f[i])
           * nothing skipped */
          nfchild = mdd_node_get(manager, nf->children[i]);
          for (j = 0; j < range; ++j)
            if (nfchild->children[j]) {
              tmp = mdd_prev_rec(manager, s, nfchild->children[j]);
              if (nr->children[i]) {
                ++(mdd_node_get(manager, tmp)->flags);
                nr->children[i] = mdd_union_rec(manager, tmp, nr->children[i]);
                --(mdd_node_get(manager, tmp)->flags);
              } else
                nr->children[i] = tmp;
            }
        }
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

  cache_PREV_add(manager, k, s, f, r);

  return r;
}

mdd_level_index_t mdd_prev(mdd_manager_t *manager, mdd_level_index_t s, mdd_level_index_t f)
{
  /* TODO: this should be an error (and not an assert) */
  assert((mdd_node_get(manager, s)->flags & MDD_NODE_REFERENCE_COUNT) > 0);
  assert((mdd_node_get(manager, f)->flags & MDD_NODE_REFERENCE_COUNT) > 0);

  return mdd_prev_rec(manager, s, f);
}

/* TODO: improve (write like next but when s is 1, directly answer 1) */
mdd_level_index_t mdd_add_prev(mdd_manager_t *manager, mdd_level_index_t s, mdd_level_index_t f)
{
  mdd_level_index_t reverse_img = mdd_prev(manager, s, f);
  mdd_level_index_t r;

  mdd_ref(manager, reverse_img);
  r = mdd_union(manager, s, reverse_img);
  mdd_unref(manager, reverse_img);

  return r;
}

static mdd_level_index_t mdd_choose_rec(mdd_manager_t *manager, mdd_level_index_t s)
{
  mdd_level_index_t r;
  mdd_node_t *ns, *nr;
  int i;

  CHECK(manager, s);

  if (s <= 1)
    return s;
 
  r = mdd_node_new(manager, mdd_level(manager, s));
  ns = mdd_node_get(manager, s);
  nr = mdd_node_get(manager, r);
  ++(nr->flags);  /* protect from deletion */

  for (i = 0; 1; ++i)
    /* s is reduced and not null, hence it has a non null child */
    if (ns->children[i]) {
      nr->children[i] = mdd_choose_rec(manager, ns->children[i]);
      break;
    }

  --(nr->flags);

  return r;
}

mdd_level_index_t mdd_choose(mdd_manager_t *manager, mdd_level_index_t s)
{
  /* TODO: this should be an error (and not an assert) */
  assert((mdd_node_get(manager, s)->flags & MDD_NODE_REFERENCE_COUNT) > 0);

  return mdd_choose_rec(manager, s);
}
