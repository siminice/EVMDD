#include <limits.h>
#include <stdlib.h>  /* DEBUG */
#include <stdio.h>  /* DEBUG */
#include <assert.h>
#include <limits.h>
#include "evmdd_ops.h"
#include "mdd_manager_priv.h"
#include "mdd_node_priv.h"
#include "evmdd_node_priv.h"
#include "unique_table_priv.h"
#include "cache_priv.h"

#define CHECK(manager, level_index)                                     \
  do {                                                                  \
    assert(mdd_index(manager, level_index) <                            \
           manager->evmdd_nodes[mdd_level(manager, level_index)].size); \
    assert(evmdd_node_get(manager, level_index)->flags &                \
           MDD_NODE_ALLOCATED);                                         \
    assert(mdd_level(manager, level_index) > 0 ||                       \
           mdd_index(manager, level_index) == 0);                       \
  } while (0)

#define CHECK_MDD(manager, level_index)                                 \
  do {                                                                  \
    assert(mdd_index(manager, level_index) <                            \
           manager->mdd_nodes[mdd_level(manager, level_index)].size);   \
    assert(mdd_node_get(manager, level_index)->flags &                  \
           MDD_NODE_ALLOCATED);                                         \
    assert(mdd_level(manager, level_index) > 0 ||                       \
           mdd_index(manager, level_index) <= 1);                       \
  } while (0)

static int evmdd_value_power(int x, int y)
{
  int tmp;

  if (y == 0) return 1;

  tmp = evmdd_value_power(x, y >> 1);
  if (y & 1)
    return tmp*tmp*x;
  else
    return tmp*tmp;
}

evmdd_edge_t evmdd_var_new_at_power(mdd_manager_t *manager, mdd_level_t k, from_to_t primed, int pow)
{
  int i, range;
  evmdd_node_t *n;
  evmdd_edge_t r = {INT_MAX, 0};

  if (k < 1 || k > manager->nb_levels)
    return r;  /* TODO: better error signal? */

  /* compute actual level (primed and unprimed variables are interleaved) */
  k = 2*k-primed;

  if (cache_VAR_find(manager, k, pow, &(r.value), &(r.node))) {
    CHECK(manager, r.node);
    return r;
  }

  r.node = evmdd_node_new(manager, k);
  n = evmdd_node_get(manager, r.node);
  ++(n->flags);  /* protect from deletion */
  range = manager->ranges[(k+1)/2];
  for (i = 0; i < range; ++i) {
    n->edges[i].value = evmdd_value_power(manager->lower_bounds[(k+1)/2]+i, pow);
    if (n->edges[i].value < r.value)
      r.value = n->edges[i].value;
    n->edges[i].node = 0;
  }
  for (i = 0; i < manager->ranges[(k+1)/2]; ++i)
    n->edges[i].value -= r.value;
  --(n->flags);

  r.node = unique_table_evmdd_checkin(manager, r.node);

  cache_VAR_add(manager, k, pow, r.value, r.node);

  return r;
}

evmdd_edge_t evmdd_var_new(mdd_manager_t *manager, mdd_level_t k, from_to_t primed)
{
  return evmdd_var_new_at_power(manager, k, primed, 1);
}

evmdd_edge_t evmdd_add_scalar(mdd_manager_t *manager, evmdd_edge_t p, int c)
{
  evmdd_edge_t r;

  r.value = p.value+c;
  r.node = p.node;

  return r;
}

static evmdd_edge_t evmdd_mult_scalar_positive(mdd_manager_t *manager, evmdd_edge_t p, int c)
{
  evmdd_edge_t r;
  evmdd_node_t *np, *nr;
  int i, range;

  CHECK(manager, p.node);

  if (p.node == 0) {
    r.value = p.value*c;
    r.node = 0;
    return r;
  }

  if (cache_MULT_SCALAR_P_find(manager, mdd_level(manager, p.node),
                               p.node, c, &(r.node))) {
    CHECK(manager, r.node);
    r.value = p.value*c;
    return r;
  }

  r.node = evmdd_node_new(manager, mdd_level(manager, p.node));
  np = evmdd_node_get(manager, p.node);
  nr = evmdd_node_get(manager, r.node);
  ++(nr->flags);  /* protect from deletion */
  range = manager->ranges[(mdd_level(manager, p.node)+1)/2];
  for (i = 0; i < range; ++i)
    nr->edges[i] = evmdd_mult_scalar_positive(manager, np->edges[i], c);
  --(nr->flags);

  r.node = unique_table_evmdd_checkin(manager, r.node);
  CHECK(manager, r.node);

  cache_MULT_SCALAR_P_add(manager, mdd_level(manager, p.node),
                          p.node, c, r.node);

  r.value = p.value*c;
  return r;
}

static evmdd_edge_t evmdd_mult_scalar_negative(mdd_manager_t *manager, evmdd_edge_t p, int c)
{
  evmdd_edge_t r;
  evmdd_node_t *np, *nr;
  int i, range;

  CHECK(manager, p.node);

  if (p.node == 0) {
    r.value = p.value*c;
    r.node = 0;
    return r;
  }

  if (cache_MULT_SCALAR_N_find(manager, mdd_level(manager, p.node),
                               p.node, c, &(r.value), &(r.node))) {
    CHECK(manager, r.node);
    r.value += p.value*c;
    return r;
  }

  r.value = 0;
  r.node = evmdd_node_new(manager, mdd_level(manager, p.node));
  np = evmdd_node_get(manager, p.node);
  nr = evmdd_node_get(manager, r.node);
  ++(nr->flags);  /* protect from deletion */
  range = manager->ranges[(mdd_level(manager, p.node)+1)/2];
  for (i = 0; i < range; ++i) {
    nr->edges[i] = evmdd_mult_scalar_negative(manager, np->edges[i], c);
    if (nr->edges[i].value < r.value)
      r.value = nr->edges[i].value;
  }
  for (i = 0; i < range; ++i)
    nr->edges[i].value -= r.value;
  --(nr->flags);

  r.node = unique_table_evmdd_checkin(manager, r.node);
  CHECK(manager, r.node);

  cache_MULT_SCALAR_N_add(manager, mdd_level(manager, p.node),
                          p.node, c, r.value, r.node);

  r.value += p.value*c;
  return r;
}

static evmdd_edge_t evmdd_mult_scalar_signed(mdd_manager_t *manager, evmdd_edge_t p, int c)
{
  evmdd_edge_t r = {0, 0};

  if (c > 0)
    return evmdd_mult_scalar_positive(manager, p, c);
  else if (c == 0)
    return r;
  else if (c == 1)
    return p;
  else
    return evmdd_mult_scalar_negative(manager, p, c);
}

evmdd_edge_t evmdd_mult_scalar(mdd_manager_t *manager, evmdd_edge_t p, int c)
{
  /* TODO: this should be an error (and not an assert) */
  assert((evmdd_node_get(manager, p.node)->flags & MDD_NODE_REFERENCE_COUNT) > 0);

  return evmdd_mult_scalar_signed(manager, p, c);
}

static evmdd_edge_t evmdd_add_rec(mdd_manager_t *manager, evmdd_edge_t p, evmdd_edge_t q)
{
  evmdd_edge_t r, tmp;
  evmdd_node_t *np, *nq, *nr;
  int i, range;

  CHECK(manager, p.node);
  CHECK(manager, q.node);

  if (p.node == 0) {
    r.value = p.value+q.value;
    r.node = q.node;
    return r;
  }
  if (q.node == 0) {
    r.value = p.value+q.value;
    r.node = p.node;
    return r;
  }

  if (p.node < q.node) {
    tmp = p; p = q; q = tmp;
  }

  if (cache_ADD_find(manager, mdd_level(manager, p.node),
                     p.node, q.node, &(r.value), &(r.node))) {
    CHECK(manager, r.node);
    r.value += p.value+q.value;
    return r;
  }

  r.value = INT_MAX;
  r.node = evmdd_node_new(manager, mdd_level(manager, p.node));
  np = evmdd_node_get(manager, p.node);
  nr = evmdd_node_get(manager, r.node);
  ++(nr->flags);  /* protect from deletion */
  range = manager->ranges[(mdd_level(manager, p.node)+1)/2];
  if (mdd_level(manager, p.node) > mdd_level(manager, q.node))
    for (i = 0; i < range; ++i) {
      nr->edges[i] = evmdd_add_rec(manager, np->edges[i], q);
      if (nr->edges[i].value < r.value)
        r.value = nr->edges[i].value;
    }
  else {  /* level(p) = level(q) */
    nq = evmdd_node_get(manager, q.node);
    for (i = 0; i < range; ++i) {
      nr->edges[i] = evmdd_add_rec(manager, np->edges[i], nq->edges[i]);
      if (nr->edges[i].value < r.value)
        r.value = nr->edges[i].value;
    }
  }
  --(nr->flags);

  /* check that the node is not redundant */  
  for (i = 1;
       i < range &&
         nr->edges[0].node  == nr->edges[i].node &&
         nr->edges[0].value == nr->edges[i].value;
       ++i);
  if (i == range) {  /* node is redundant */
    tmp.node = nr->edges[0].node;
    evmdd_node_free(manager, r.node);
    r.node = tmp.node;
  } else {
    for (i = 0; i < range; ++i)
      if (nr->edges[i].value != INT_MAX)
      nr->edges[i].value -= r.value;
    r.node = unique_table_evmdd_checkin(manager, r.node);
    CHECK(manager, r.node);
  }

  if (mdd_level(manager, p.node) > mdd_level(manager, q.node))
    r.value -= q.value;

  cache_ADD_add(manager, mdd_level(manager, p.node), p.node, q.node, r.value, r.node);

  r.value += p.value+q.value;

  return r;
}

evmdd_edge_t evmdd_add(mdd_manager_t *manager, evmdd_edge_t p, evmdd_edge_t q)
{
  /* TODO: this should be an error (and not an assert) */
  assert((evmdd_node_get(manager, p.node)->flags & MDD_NODE_REFERENCE_COUNT) > 0);
  assert((evmdd_node_get(manager, q.node)->flags & MDD_NODE_REFERENCE_COUNT) > 0);

  return evmdd_add_rec(manager, p, q);
}


static evmdd_edge_t evmdd_mult_rec(mdd_manager_t *manager, evmdd_edge_t p, evmdd_edge_t q)
{
  evmdd_edge_t r = {0, 0}, p0 = {0, 0}, q0 = {0, 0}, p0_p_q0, r1;
  evmdd_node_t *np, *nq, *nr;
  int i, range;

  CHECK(manager, p.node);
  CHECK(manager, q.node);

  if (p.node == 0)
    return evmdd_mult_scalar_signed(manager, q, p.value);
  if (q.node == 0)
    return evmdd_mult_scalar_signed(manager, p, q.value);

  if (p.node < q.node) {
    r1 = p; p = q; q = r1;
  }

  if (!(cache_MULT_find(manager, mdd_level(manager, p.node),
                        p.node, q.node, &(r.node)))) {
    r.node = evmdd_node_new(manager, mdd_level(manager, p.node));
    np = evmdd_node_get(manager, p.node);
    nq = evmdd_node_get(manager, q.node);
    nr = evmdd_node_get(manager, r.node);
    ++(nr->flags);  /* protect from deletion */
    range = manager->ranges[(mdd_level(manager, p.node)+1)/2];
    if (mdd_level(manager, p.node) > mdd_level(manager, q.node)) {
      q0.node = q.node;
      for (i = 0; i < range; ++i)
        nr->edges[i] = evmdd_mult_rec(manager, np->edges[i], q0);
    } else {  /* level(p) = level(q) */
      nq = evmdd_node_get(manager, q.node);
      for (i = 0; i < range; ++i)
        nr->edges[i] = evmdd_mult_rec(manager, np->edges[i], nq->edges[i]);
    }
    --(nr->flags);
    /* here, the node nr is already canonic */

    /* check that the node is not redundant */  
    for (i = 1;
         i < range &&
           nr->edges[0].node  == nr->edges[i].node &&
           nr->edges[0].value == nr->edges[i].value;
         ++i);
    if (i == range) {  /* node is redundant */
      r1.node = nr->edges[0].node;
      evmdd_node_free(manager, r.node);
      r.node = r1.node;
    } else {
      r.node = unique_table_evmdd_checkin(manager, r.node);
      CHECK(manager, r.node);
    }

    cache_MULT_add(manager, mdd_level(manager, p.node), p.node, q.node, r.node);
  }


  ++(evmdd_node_get(manager, r.node)->flags);  /* protect from deletion */

  p0.node = p.node;
  p0 = evmdd_mult_scalar_signed(manager, p0, q.value);
  ++(evmdd_node_get(manager, p0.node)->flags);
    
  q0.node = q.node;
  q0 = evmdd_mult_scalar_signed(manager, q0, p.value);
  ++(evmdd_node_get(manager, q0.node)->flags);

  p0_p_q0 = evmdd_add_rec(manager, p0, q0);
  ++(evmdd_node_get(manager, p0_p_q0.node)->flags);
  --(evmdd_node_get(manager, p0.node)->flags);
  --(evmdd_node_get(manager, q0.node)->flags);

  r1 = evmdd_add_rec(manager, p0_p_q0, r);
  --(evmdd_node_get(manager, p0_p_q0.node)->flags);

  --(evmdd_node_get(manager, r.node)->flags);

  r1.value += p.value*q.value;

  return r1;
}

evmdd_edge_t evmdd_mult(mdd_manager_t *manager, evmdd_edge_t p, evmdd_edge_t q)
{
  /* TODO: this should be an error (and not an assert) */
  assert((evmdd_node_get(manager, p.node)->flags & MDD_NODE_REFERENCE_COUNT) > 0);
  assert((evmdd_node_get(manager, q.node)->flags & MDD_NODE_REFERENCE_COUNT) > 0);

  return evmdd_mult_rec(manager, p, q);
}

static evmdd_edge_t evmdd_div_scalar_rec(mdd_manager_t *manager, evmdd_edge_t p, int c)
{
  evmdd_edge_t arg, r;
  mdd_level_index_t tmp;
  int p_val_mod_c;
  evmdd_node_t *np, *nr;
  int i, range;

  CHECK(manager, p.node);

  if (p.node == 0) {
    r.value = (c!=0 ? p.value/c : 0);
    r.node = 0;
    return r;
  }

  p_val_mod_c = (c!=0 ? p.value%c : 0);

  if (cache_DIV_SCALAR_find(manager, mdd_level(manager, p.node),
                            p.node, p_val_mod_c, c, &(r.node))) {
    CHECK(manager, r.node);
    r.value = (c!=0 ? p.value/c : 0);
    return r;
  }

  r.node = evmdd_node_new(manager, mdd_level(manager, p.node));
  np = evmdd_node_get(manager, p.node);
  nr = evmdd_node_get(manager, r.node);
  ++(nr->flags);  /* protect from deletion */
  range = manager->ranges[(mdd_level(manager, p.node)+1)/2];
  for (i = 0; i < range; ++i) {
    arg.value = np->edges[i].value+p_val_mod_c;
    arg.node = np->edges[i].node;
    nr->edges[i] = evmdd_div_scalar_rec(manager, arg, c);
  }
  --(nr->flags);

  /* check that the node is not redundant */  
  for (i = 1;
       i < range &&
         nr->edges[0].node  == nr->edges[i].node &&
         nr->edges[0].value == nr->edges[i].value;
       ++i);
  if (i == range) {  /* node is redundant */
    tmp = nr->edges[0].node;
    evmdd_node_free(manager, r.node);
    r.node = tmp;
  } else {
    r.node = unique_table_evmdd_checkin(manager, r.node);
    CHECK(manager, r.node);
  }

  cache_DIV_SCALAR_add(manager, mdd_level(manager, p.node),
                       p.node, p_val_mod_c, c, r.node);

  r.value = (c!=0 ? p.value/c : 0);
  return r;
}

evmdd_edge_t evmdd_div_scalar(mdd_manager_t *manager, evmdd_edge_t p, int c)
{
  /* TODO: this should be an error (and not an assert) */
  assert((evmdd_node_get(manager, p.node)->flags & MDD_NODE_REFERENCE_COUNT) > 0);

  return evmdd_div_scalar_rec(manager, p, c);
}

static evmdd_edge_t evmdd_mod_scalar_rec(mdd_manager_t *manager, evmdd_edge_t p, int c)
{
  evmdd_edge_t arg, r;
  mdd_level_index_t tmp;
  int p_val_mod_c = (c!=0 ? p.value%c : 0);
  evmdd_node_t *np, *nr;
  int i, range;

  CHECK(manager, p.node);

  if (p.node == 0) {
    r.value = p_val_mod_c;
    r.node = 0;
    return r;
  }

  if (cache_MOD_SCALAR_find(manager, mdd_level(manager, p.node),
                            p.node, p_val_mod_c, c, &(r.value), &(r.node))) {
    CHECK(manager, r.node);
    return r;
  }

  r.value = c;
  r.node = evmdd_node_new(manager, mdd_level(manager, p.node));
  np = evmdd_node_get(manager, p.node);
  nr = evmdd_node_get(manager, r.node);
  ++(nr->flags);  /* protect from deletion */
  range = manager->ranges[(mdd_level(manager, p.node)+1)/2];
  for (i = 0; i < range; ++i) {
    arg.value = np->edges[i].value+p.value;
    arg.node = np->edges[i].node;
    nr->edges[i] = evmdd_mod_scalar_rec(manager, arg, c);
    if (nr->edges[i].value < r.value)
      r.value = nr->edges[i].value;
  }
  --(nr->flags);

  /* check that the node is not redundant */  
  for (i = 1;
       i < range &&
         nr->edges[0].node  == nr->edges[i].node &&
         nr->edges[0].value == nr->edges[i].value;
       ++i);
  if (i == range) {  /* node is redundant */
    tmp = nr->edges[0].node;
    evmdd_node_free(manager, r.node);
    r.node = tmp;
  } else {
    for (i = 0; i < range; ++i)
      nr->edges[i].value -= r.value;
    r.node = unique_table_evmdd_checkin(manager, r.node);
    CHECK(manager, r.node);
  }

  cache_MOD_SCALAR_add(manager, mdd_level(manager, p.node),
                       p.node, p_val_mod_c, c, r.value, r.node);

  return r;
}

evmdd_edge_t evmdd_mod_scalar(mdd_manager_t *manager, evmdd_edge_t p, int c)
{
  /* TODO: this should be an error (and not an assert) */
  assert((evmdd_node_get(manager, p.node)->flags & MDD_NODE_REFERENCE_COUNT) > 0);
  assert(p.value >= 0);  /* TODO: correct error handling */
  assert(c > 0);  /* TODO: correct error handling */

  return evmdd_mod_scalar_rec(manager, p, c);
}

static evmdd_edge_t evmdd_div_rec(mdd_manager_t *manager, evmdd_edge_t p, evmdd_edge_t q)
{
  evmdd_edge_t r, p0, q0;
  evmdd_node_t *np, *nq, *nr;
  int k;
  int i, range;

  CHECK(manager, p.node);
  CHECK(manager, q.node);

  if (q.node == 0) {
    return evmdd_div_scalar_rec(manager, p, q.value);
  }

  k = mdd_level(manager, p.node > q.node ? p.node : q.node);

  if (cache_DIV_find(manager, k, p.node, p.value, q.node, q.value, &(r.value), &(r.node))) {
    CHECK(manager, r.node);
    return r;
  }

  r.value = INT_MAX;
  r.node = evmdd_node_new(manager, k);
  nr = evmdd_node_get(manager, r.node);
  ++(nr->flags);  /* protect from deletion */
  range = manager->ranges[(k+1)/2];
  if (mdd_level(manager, p.node) > mdd_level(manager, q.node)) {
    np = evmdd_node_get(manager, p.node);
    for (i = 0; i < range; ++i) {
      p0.value = np->edges[i].value+p.value;
      p0.node = np->edges[i].node;
      nr->edges[i] = evmdd_div_rec(manager, p0, q);
      if (nr->edges[i].value < r.value)
        r.value = nr->edges[i].value;
    }
  } else if (mdd_level(manager, p.node) == mdd_level(manager, q.node)) {
    np = evmdd_node_get(manager, p.node);
    nq = evmdd_node_get(manager, q.node);
    for (i = 0; i < range; ++i) {
      p0.value = np->edges[i].value+p.value;
      p0.node = np->edges[i].node;
      q0.value = nq->edges[i].value+q.value;
      q0.node = nq->edges[i].node;
      nr->edges[i] = evmdd_div_rec(manager, p0, q0);
      if (nr->edges[i].value < r.value)
        r.value = nr->edges[i].value;
    }
  } else {  /* level(p) < level(q) */
    nq = evmdd_node_get(manager, q.node);
    for (i = 0; i < range; ++i) {
      q0.value = nq->edges[i].value+q.value;
      q0.node = nq->edges[i].node;
      nr->edges[i] = evmdd_div_rec(manager, p, q0);
      if (nr->edges[i].value < r.value)
        r.value = nr->edges[i].value;
    }
  }
  --(nr->flags);

  /* check that the node is not redundant */  
  for (i = 1;
       i < range &&
         nr->edges[0].node  == nr->edges[i].node &&
         nr->edges[0].value == nr->edges[i].value;
       ++i);
  if (i == range) {  /* node is redundant */
    p0.node = nr->edges[0].node;
    evmdd_node_free(manager, r.node);
    r.node = p0.node;
  } else {
    for (i = 0; i < range; ++i)
      nr->edges[i].value -= r.value;
    r.node = unique_table_evmdd_checkin(manager, r.node);
    CHECK(manager, r.node);
  }

  cache_DIV_add(manager, k, p.node, p.value, q.node, q.value, r.value, r.node);

  return r;
}

evmdd_edge_t evmdd_div(mdd_manager_t *manager, evmdd_edge_t p, evmdd_edge_t q)
{
  /* TODO: this should be an error (and not an assert) */
  assert((evmdd_node_get(manager, p.node)->flags & MDD_NODE_REFERENCE_COUNT) > 0);
  assert((evmdd_node_get(manager, q.node)->flags & MDD_NODE_REFERENCE_COUNT) > 0);

  return evmdd_div_rec(manager, p, q);
}

static evmdd_edge_t evmdd_mod_rec(mdd_manager_t *manager, evmdd_edge_t p, evmdd_edge_t q)
{
  evmdd_edge_t r, p0, q0;
  evmdd_node_t *np, *nq, *nr;
  int k;
  int i, range;

  CHECK(manager, p.node);
  CHECK(manager, q.node);

  if (q.node == 0)
    return evmdd_mod_scalar_rec(manager, p, q.value);

  k = mdd_level(manager, p.node > q.node ? p.node : q.node);

  if (cache_MOD_find(manager, k, p.node, p.value, q.node, q.value, &(r.value), &(r.node))) {
    CHECK(manager, r.node);
    return r;
  }

  r.value = INT_MAX;
  r.node = evmdd_node_new(manager, k);
  nr = evmdd_node_get(manager, r.node);
  ++(nr->flags);  /* protect from deletion */
  range = manager->ranges[(k+1)/2];
  if (mdd_level(manager, p.node) > mdd_level(manager, q.node)) {
    np = evmdd_node_get(manager, p.node);
    for (i = 0; i < range; ++i) {
      p0.value = np->edges[i].value+p.value;
      p0.node = np->edges[i].node;
      nr->edges[i] = evmdd_mod_rec(manager, p0, q);
      if (nr->edges[i].value < r.value)
        r.value = nr->edges[i].value;
    }
  } else if (mdd_level(manager, p.node) == mdd_level(manager, q.node)) {
    np = evmdd_node_get(manager, p.node);
    nq = evmdd_node_get(manager, q.node);
    for (i = 0; i < range; ++i) {
      p0.value = np->edges[i].value+p.value;
      p0.node = np->edges[i].node;
      q0.value = nq->edges[i].value+q.value;
      q0.node = nq->edges[i].node;
      nr->edges[i] = evmdd_mod_rec(manager, p0, q0);
      if (nr->edges[i].value < r.value)
        r.value = nr->edges[i].value;
    }
  } else {  /* level(p) < level(q) */ 
    nq = evmdd_node_get(manager, q.node);
    for (i = 0; i < range; ++i) {
      q0.value = nq->edges[i].value+q.value;
      q0.node = nq->edges[i].node;
      nr->edges[i] = evmdd_mod_rec(manager, p, q0);
      if (nr->edges[i].value < r.value)
        r.value = nr->edges[i].value;
    }
  }
  --(nr->flags);

  /* check that the node is not redundant */  
  for (i = 1;
       i < range &&
         nr->edges[0].node  == nr->edges[i].node &&
         nr->edges[0].value == nr->edges[i].value;
       ++i);
  if (i == range) {  /* node is redundant */
    p0.node = nr->edges[0].node;
    evmdd_node_free(manager, r.node);
    r.node = p0.node;
  } else {
    for (i = 0; i < range; ++i)
      nr->edges[i].value -= r.value;
    r.node = unique_table_evmdd_checkin(manager, r.node);
    CHECK(manager, r.node);
  }

  cache_MOD_add(manager, k, p.node, p.value, q.node, q.value, r.value, r.node);

  return r;
}

evmdd_edge_t evmdd_mod(mdd_manager_t *manager, evmdd_edge_t p, evmdd_edge_t q)
{
  /* TODO: this should be an error (and not an assert) */
  assert((evmdd_node_get(manager, p.node)->flags & MDD_NODE_REFERENCE_COUNT) > 0);
  assert((evmdd_node_get(manager, q.node)->flags & MDD_NODE_REFERENCE_COUNT) > 0);
  assert(p.value >= 0);  /* TODO: correct error handling */
  assert(q.value > 0);  /* TODO: correct error handling */

  return evmdd_mod_rec(manager, p, q);
}

int evmdd_min(mdd_manager_t *manager, evmdd_edge_t p)
{
  /* TODO: this should be an error (and not an assert) */
  assert((evmdd_node_get(manager, p.node)->flags & MDD_NODE_REFERENCE_COUNT) > 0);

  return p.value;
}

static long evmdd_max_rec(mdd_manager_t *manager, mdd_level_index_t p)
{
  int i, range;
  evmdd_node_t *np;
  long m, tmp;

  if (p == 0)
    return 0;

  if (cache_MAX_find(manager, mdd_level(manager, p), p, &m))
    return ((int)m);

  m = 0;
  np = evmdd_node_get(manager, p);
  range = manager->ranges[(mdd_level(manager, p)+1)/2];
  for (i = 0; i < range; ++i) {
    tmp = evmdd_max_rec(manager, np->edges[i].node);
    tmp += np->edges[i].value;
    if (tmp > m) m = tmp;
  }
  cache_MAX_add(manager, mdd_level(manager, p), p, m);

  return m;
}

long evmdd_max(mdd_manager_t *manager, evmdd_edge_t p)
{
  return evmdd_max_rec(manager, p.node)+p.value;
}

static mdd_level_index_t evmdd_lt_scalar_rec(mdd_manager_t *manager, evmdd_edge_t p, int c)
{
  mdd_level_index_t r, tmp;
  evmdd_node_t *np;
  mdd_node_t *nr;
  int i, range;

  CHECK(manager, p.node);

  if (c-p.value <= 0)
    return 0;

  if (c-p.value > evmdd_max_rec(manager, p.node))
    return 1;

  if (cache_LT_find(manager, mdd_level(manager, p.node), p.node, c-p.value, &r)) {
    CHECK_MDD(manager, r);
    return r;
  }

  r = mdd_node_new(manager, mdd_level(manager, p.node));
  CHECK_MDD(manager, r);
  np = evmdd_node_get(manager, p.node);
  nr = mdd_node_get(manager, r);
  ++(nr->flags);  /* protect from deletion */
  range = manager->ranges[(mdd_level(manager, p.node)+1)/2];
  for (i = 0; i < range; ++i)
    nr->children[i] = evmdd_lt_scalar_rec(manager, np->edges[i], c-p.value);
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
    CHECK_MDD(manager, r);
  }

  cache_LT_add(manager, mdd_level(manager, p.node), p.node, c-p.value, r);

  return r;
}

mdd_level_index_t evmdd_lt_scalar(mdd_manager_t *manager, evmdd_edge_t p, int c)
{
  /* TODO: this should be an error (and not an assert) */
  assert((evmdd_node_get(manager, p.node)->flags & MDD_NODE_REFERENCE_COUNT) > 0);

  return evmdd_lt_scalar_rec(manager, p, c);
}

mdd_level_index_t evmdd_lt(mdd_manager_t *manager, evmdd_edge_t p, evmdd_edge_t q)
{
  evmdd_edge_t mq, pmq;
  mdd_level_index_t result;

  mq = evmdd_mult_scalar(manager, q, -1);
  evmdd_ref(manager, mq);
  pmq = evmdd_add(manager, p, mq);
  evmdd_ref(manager, pmq);
  evmdd_unref(manager, mq);
  result = evmdd_lt_scalar(manager, pmq, 0);  
  evmdd_unref(manager, pmq);

  return result;
}

static mdd_level_index_t evmdd_qlt_scalar_rec(mdd_manager_t *manager, evmdd_edge_t p, int c)
{
  mdd_level_index_t r, tmp;
  evmdd_node_t *np;
  mdd_node_t *nr;
  int i, range;

  CHECK(manager, p.node);

  if (c-p.value <= 0)
    return 0;

  if (c-p.value > evmdd_max_rec(manager, p.node))
    return 1;

  if (cache_QLT_find(manager, mdd_level(manager, p.node), p.node, c-p.value, &r)) {
    CHECK_MDD(manager, r);
    return r;
  }

  r = mdd_node_new(manager, mdd_level(manager, p.node));
  CHECK_MDD(manager, r);
  np = evmdd_node_get(manager, p.node);
  nr = mdd_node_get(manager, r);
  ++(nr->flags);  /* protect from deletion */
  range = manager->ranges[(mdd_level(manager, p.node)+1)/2];
  for (i = 0; i < range; ++i) {
    nr->children[i] = evmdd_qlt_scalar_rec(manager, np->edges[i], c-p.value);
    if (nr->children[i]) i=range; /* stop search */
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
    CHECK_MDD(manager, r);
  }

  cache_QLT_add(manager, mdd_level(manager, p.node), p.node, c-p.value, r);

  return r;
}

mdd_level_index_t evmdd_qlt_scalar(mdd_manager_t *manager, evmdd_edge_t p, int c)
{
  /* TODO: this should be an error (and not an assert) */
  assert((evmdd_node_get(manager, p.node)->flags & MDD_NODE_REFERENCE_COUNT) > 0);

  return evmdd_qlt_scalar_rec(manager, p, c);
}

mdd_level_index_t evmdd_qlt(mdd_manager_t *manager, evmdd_edge_t p, evmdd_edge_t q)
{
  evmdd_edge_t mq, pmq;
  mdd_level_index_t result;

  mq = evmdd_mult_scalar(manager, q, -1);
  evmdd_ref(manager, mq);
  pmq = evmdd_add(manager, p, mq);
  evmdd_ref(manager, pmq);
  evmdd_unref(manager, mq);
  result = evmdd_qlt_scalar(manager, pmq, 0);  
  evmdd_unref(manager, pmq);

  return result;
}

static mdd_level_index_t evmdd_eq_scalar_rec(mdd_manager_t *manager, evmdd_edge_t p, int c)
{
  mdd_level_index_t r, tmp;
  evmdd_node_t *np;
  mdd_node_t *nr;
  int i, range;

  if (c-p.value < 0)
    return 0;

  if (c-p.value > evmdd_max_rec(manager, p.node))
    return 0;

  if (p.node == 0)
    /* 0 would have already been returned */
    return 1;

  if (cache_EQ_find(manager, mdd_level(manager, p.node), p.node, c-p.value, &r))
    return r;

  r = mdd_node_new(manager, mdd_level(manager, p.node));
  np = evmdd_node_get(manager, p.node);
  nr = mdd_node_get(manager, r);
  ++(nr->flags);  /* protect from deletion */
  range = manager->ranges[(mdd_level(manager, p.node)+1)/2];
  for (i = 0; i < range; ++i)
    nr->children[i] = evmdd_eq_scalar_rec(manager, np->edges[i], c-p.value);
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
  } else
    r = unique_table_mdd_checkin(manager, r);

  cache_EQ_add(manager, mdd_level(manager, p.node), p.node, c-p.value, r);

  return r;
}

mdd_level_index_t evmdd_eq_scalar(mdd_manager_t *manager, evmdd_edge_t p, int c)
{
  /* TODO: this should be an error (and not an assert) */
  assert((evmdd_node_get(manager, p.node)->flags & MDD_NODE_REFERENCE_COUNT) > 0);

  return evmdd_eq_scalar_rec(manager, p, c);
}

mdd_level_index_t evmdd_eq(mdd_manager_t *manager, evmdd_edge_t p, evmdd_edge_t q)
{
  evmdd_edge_t mq, pmq;
  mdd_level_index_t result;

  mq = evmdd_mult_scalar(manager, q, -1);
  evmdd_ref(manager, mq);
  pmq = evmdd_add(manager, p, mq);
  evmdd_ref(manager, pmq);
  evmdd_unref(manager, mq);
  result = evmdd_eq_scalar(manager, pmq, 0);  
  evmdd_unref(manager, pmq);

  return result;
}

static mdd_level_index_t evmdd_qeq_scalar_rec(mdd_manager_t *manager, evmdd_edge_t p, int c)
{
  mdd_level_index_t r, tmp;
  evmdd_node_t *np;
  mdd_node_t *nr;
  int i, range;

  if (c-p.value < 0)
    return 0;

  if (c-p.value > evmdd_max_rec(manager, p.node))
    return 0;

  if (p.node == 0)
    /* 0 would have already been returned */
    return 1;

  if (cache_QEQ_find(manager, mdd_level(manager, p.node), p.node, c-p.value, &r))
    return r;

  r = mdd_node_new(manager, mdd_level(manager, p.node));
  np = evmdd_node_get(manager, p.node);
  nr = mdd_node_get(manager, r);
  ++(nr->flags);  /* protect from deletion */
  range = manager->ranges[(mdd_level(manager, p.node)+1)/2];
  for (i = 0; i < range; ++i) {
    nr->children[i] = evmdd_qeq_scalar_rec(manager, np->edges[i], c-p.value);
    if (nr->children[i]) i=range; /* stop search */
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
  } else
    r = unique_table_mdd_checkin(manager, r);

  cache_QEQ_add(manager, mdd_level(manager, p.node), p.node, c-p.value, r);

  return r;
}

mdd_level_index_t evmdd_qeq_scalar(mdd_manager_t *manager, evmdd_edge_t p, int c)
{
  /* TODO: this should be an error (and not an assert) */
  assert((evmdd_node_get(manager, p.node)->flags & MDD_NODE_REFERENCE_COUNT) > 0);

  return evmdd_qeq_scalar_rec(manager, p, c);
}

mdd_level_index_t evmdd_qeq(mdd_manager_t *manager, evmdd_edge_t p, evmdd_edge_t q)
{
  evmdd_edge_t mq, pmq;
  mdd_level_index_t result;

  mq = evmdd_mult_scalar(manager, q, -1);
  evmdd_ref(manager, mq);
  pmq = evmdd_add(manager, p, mq);
  evmdd_ref(manager, pmq);
  evmdd_unref(manager, mq);
  result = evmdd_qeq_scalar(manager, pmq, 0);  
  evmdd_unref(manager, pmq);

  return result;
}

static evmdd_edge_t evmdd_from_mdd_rec(mdd_manager_t *manager, mdd_level_index_t p)
{
  evmdd_edge_t r;
  mdd_node_t *np;
  evmdd_node_t *nr;
  int i, range;

  CHECK_MDD(manager, p);

  if (p <= 1) {
    r.value = p;
    r.node = 0;
    return r;
  }

  if (cache_EVMDD_FROM_MDD_find(manager, mdd_level(manager, p),
                                p, &(r.value), &(r.node))) {
    CHECK(manager, r.node);
    return r;
  }

  r.value = 0;
  r.node = evmdd_node_new(manager, mdd_level(manager, p));
  np = mdd_node_get(manager, p);
  nr = evmdd_node_get(manager, r.node);
  ++(nr->flags);  /* protect from deletion */
  range = manager->ranges[(mdd_level(manager, p)+1)/2];
  for (i = 0; i < range; ++i)
    nr->edges[i] = evmdd_from_mdd_rec(manager, np->children[i]);
  --(nr->flags);

  r.node = unique_table_evmdd_checkin(manager, r.node);
  CHECK(manager, r.node);

  cache_EVMDD_FROM_MDD_add(manager, mdd_level(manager, p),
                           p, r.value, r.node);

  return r;
}

evmdd_edge_t evmdd_from_mdd(mdd_manager_t *manager, mdd_level_index_t p)
{
  /* TODO: this should be an error (and not an assert) */
  assert((mdd_node_get(manager, p)->flags & MDD_NODE_REFERENCE_COUNT) > 0);

  return evmdd_from_mdd_rec(manager, p);
}
