#include <stdlib.h>
#include "sal_intf.h"
/* for mdd_num_encoded_elements */
#include "mdd_node.h"
#include "clock_priv.h"

evmdd_edge_t* sal_evmdd_var_new(mdd_manager_t *manager, mdd_level_t k, from_to_t primed)
{
  evmdd_edge_t* result = malloc(sizeof(evmdd_edge_t));
  evmdd_edge_t r = evmdd_var_new(manager, k, primed);
  evmdd_ref(manager, r);
  result->value = r.value;
  result->node = r.node;
  return result;
}

mdd_level_index_t sal_evmdd_eq_scalar(mdd_manager_t *manager, evmdd_edge_t *p, int c)
{
  mdd_level_index_t result;

  result=evmdd_eq_scalar(manager, *p, c);
  mdd_ref(manager, result);

  if (!result) {
    fprintf(stderr, "evmdd error > sal_evmdd_eq_scalar : empty result.\n");
    fprintf(stderr, "c = %d, node: %u, ev: %d.\n", c, p->node, p->value);
	mdd_manager_free(manager);
    exit(-1);
  }

  return result;
}

mdd_level_index_t sal_evmdd_eq(mdd_manager_t *manager, evmdd_edge_t *p, evmdd_edge_t *q)
{
  return evmdd_eq(manager, *p, *q);
}

mdd_level_index_t sal_evmdd_lt_scalar(mdd_manager_t *manager, evmdd_edge_t *p, int c)
{
  return evmdd_lt_scalar(manager, *p, c);
}

evmdd_edge_t* sal_evmdd_add_scalar(mdd_manager_t *manager, evmdd_edge_t *p, int c)
{
  evmdd_edge_t *result = malloc(sizeof(evmdd_edge_t));

  *result = evmdd_add_scalar(manager, *p, c);

  return result;
}

evmdd_edge_t* sal_evmdd_add(mdd_manager_t *manager, evmdd_edge_t *p, evmdd_edge_t *q)
{
  evmdd_edge_t *result = malloc(sizeof(evmdd_edge_t));

  *result = evmdd_add(manager, *p, *q);

  return result;
}

evmdd_edge_t* sal_evmdd_mult_scalar(mdd_manager_t *manager, evmdd_edge_t *p, int c)
{
  evmdd_edge_t *result = malloc(sizeof(evmdd_edge_t));

  *result = evmdd_mult_scalar(manager, *p, c);

  return result;
}

evmdd_edge_t* sal_evmdd_mult(mdd_manager_t *manager, evmdd_edge_t *p, evmdd_edge_t *q)
{
  evmdd_edge_t *result = malloc(sizeof(evmdd_edge_t));

  *result = evmdd_mult(manager, *p, *q);

  return result;
}

void sal_mdd_num_encoded_elements(mdd_manager_t *manager, mdd_level_index_t p)
{
  printf("    ");
  bigint_print(mdd_num_encoded_elements(manager, p), stdout);
  printf("\n");
}

mdd_level_index_t saturate_withtime(mdd_manager_t *manager, mdd_level_index_t p)
{
  clock_t start, stop;
  start=clock_get();
  mdd_level_index_t result=saturate(manager, p);
  stop=clock_get();
  fprintf(stderr, "Saturation done in: ");clock_print(start, stop);
  clock_free(start);
  clock_free(stop);
  return result;
}
