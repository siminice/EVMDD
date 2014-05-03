#include <stdio.h>  /* DEBUG */
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "mdd_manager_priv.h"
#include "mdd_node_priv.h"
#include "evmdd_node_priv.h"
#include "unique_table_priv.h"
#include "cache_priv.h"
#include "events_priv.h"

mdd_manager_t *mdd_manager_new(int nb_levels, int *lower_bounds, int *ranges)
{
  int i, j;
  mdd_manager_t *manager = malloc(sizeof(mdd_manager_t));
  manager->currently_allocated = sizeof(mdd_manager_t);

  manager->nb_levels = nb_levels;

  for (manager->level_shift = 0, manager->index_mask = 1;
       manager->index_mask <= 2*manager->nb_levels;
       ++(manager->level_shift), manager->index_mask <<= 1);
  manager->level_shift = sizeof(mdd_level_index_t)*8-manager->level_shift;
  manager->index_mask = (1 << manager->level_shift)-1;
/*
  printf("mdd_manager level_shift: %d.\n", manager->level_shift);
  printf("mdd_manager index_mask:  %d.\n", manager->index_mask);
*/

  manager->var_names = NULL;

  manager->lower_bounds = malloc((manager->nb_levels+1)*sizeof(int));
  manager->currently_allocated += (manager->nb_levels+1)*sizeof(int);
  manager->lower_bounds[0] = 0;
  memcpy(manager->lower_bounds+1, lower_bounds+1, manager->nb_levels*sizeof(int));

  manager->ranges = malloc((manager->nb_levels+1)*sizeof(int));
  manager->currently_allocated += (manager->nb_levels+1)*sizeof(int);
  manager->ranges[0] = 0;
  memcpy(manager->ranges+1, ranges+1, manager->nb_levels*sizeof(int));

  manager->gc_threshold = (unsigned long)-1;

  manager->events = calloc(manager->nb_levels+1, sizeof(event_entry_t *));
  manager->currently_allocated += (manager->nb_levels+1)*sizeof(event_entry_t *);

  manager->all_events = 0;

  manager->mdd_nodes = malloc((2*manager->nb_levels+1)*sizeof(mdd_node_storage_t));
  manager->currently_allocated += (2*manager->nb_levels+1)*sizeof(mdd_node_storage_t);
  for (i = 0; i <= 2*manager->nb_levels; ++i)
    mdd_node_storage_init(manager, i);
  mdd_node_new(manager, 0);  /* terminal 0 */
  mdd_node_new(manager, 0);  /* terminal 1 */

  manager->evmdd_nodes = malloc((2*manager->nb_levels+1)*sizeof(evmdd_node_storage_t));
  manager->currently_allocated += (2*manager->nb_levels+1)*sizeof(evmdd_node_storage_t);
  for (i = 0; i <= 2*manager->nb_levels; ++i)
    evmdd_node_storage_init(manager, i);
  evmdd_node_new(manager, 0);  /* terminal 0 */

  manager->mdd_unique_tables = malloc((2*manager->nb_levels+1)*sizeof(unique_table_t));
  manager->currently_allocated += (2*manager->nb_levels+1)*sizeof(unique_table_t);
  for (i = 1; i <= 2*manager->nb_levels; ++i)
    unique_table_mdd_init(manager, i);

  manager->evmdd_unique_tables = malloc((2*manager->nb_levels+1)*sizeof(unique_table_t));
  manager->currently_allocated += (2*manager->nb_levels+1)*sizeof(unique_table_t);
  for (i = 1; i <= 2*manager->nb_levels; ++i)
    unique_table_evmdd_init(manager, i);

  for (i = 0; i < MDD_O_NB; ++i) {
    manager->caches[i] = malloc((2*manager->nb_levels+1)*sizeof(cache_t));
    manager->currently_allocated += (2*manager->nb_levels+1)*sizeof(cache_t);
    for (j = 0; j <= 2*manager->nb_levels; ++j)
      cache_init(manager, i, j);
  }

  manager->nb_cache_worst = 0;
  manager->nb_cache_lookup_entries = 0;
  manager->nb_cache_lookups = 0;
  manager->nb_unique_table_worst = 0;
  manager->nb_unique_table_lookup_entries = 0;
  manager->nb_unique_table_lookups = 0;

  fprintf(stderr, "%s/%d: end of mdd_manager_new, currently_allocated: %lu bytes\n", __FILE__, __LINE__, manager->currently_allocated);

  return manager;
}

static void mdd_manager_free_var_names(mdd_manager_t *manager)
{
  int i;

  if (manager->var_names) {
    for (i = 1; i <= manager->nb_levels; ++i) {
      manager->currently_allocated -= strlen(manager->var_names[i])+1;
      free(manager->var_names[i]);
    }
    manager->currently_allocated -= (manager->nb_levels+1)*sizeof(char *);
    free(manager->var_names);
  }
}

void mdd_manager_set_var_names(mdd_manager_t *manager, char **var_names)
{
  int i;

  mdd_manager_free_var_names(manager);

  if (var_names) {
    manager->var_names = malloc((manager->nb_levels+1)*sizeof(char *));
    manager->currently_allocated += (manager->nb_levels+1)*sizeof(char *);
    manager->var_names[0] = NULL;
    for (i = 1; i <= manager->nb_levels; ++i) {
      manager->var_names[i] = malloc(strlen(var_names[i])+1);
      manager->currently_allocated += strlen(var_names[i])+1;
      strcpy(manager->var_names[i], var_names[i]);
    }
  } else
    manager->var_names = NULL;
}

void mdd_manager_set_gc_threshold(mdd_manager_t *manager, unsigned long gc_threshold)
{
  if (gc_threshold) {
    manager->memlimit = gc_threshold;
    /* (TODO: maybe we should return an error if the threshold is to close
     * from currently_allocated) */
    manager->gc_threshold = manager->memlimit/2;
  } else
    manager->memlimit = manager->gc_threshold = (unsigned long)-1;
}

int mdd_manager_get_nb_levels(mdd_manager_t *manager)
{
  return manager->nb_levels;
}

event_entry_t **mdd_manager_get_events(mdd_manager_t *manager)
{
  return manager->events;
}

mdd_level_index_t mdd_manager_get_all_events(mdd_manager_t *manager)
{
  if (manager->all_events == 0) event_union_all(manager);

  return manager->all_events;
}

void mdd_manager_print_state(mdd_manager_t *manager, int *state)
{
  int nl, i;

  if (!state) return;

  nl = mdd_manager_get_nb_levels(manager);
  for (i=nl; i; --i) {
    fprintf(stdout, "%s=", manager->var_names[i]); 
    /* negative value means "don't care" */
    if (state[i]>=0) 
      fprintf(stdout, "%d ", state[i] + manager->lower_bounds[i]);
    else
      fprintf(stdout, "* ");
  }
}

void current_statistics(mdd_manager_t *manager) {
  fprintf(stderr, "%s/%d: currently_allocated: %lu bytes\n", __FILE__, __LINE__, manager->currently_allocated);
}

void spare_statistics(mdd_manager_t *manager)
{
  int k, width, storage_size, i, j;
  mdd_node_t *n;
  int range, non_zero;
  unsigned long could_save=0;

  for (k = 2*manager->nb_levels; k; --k) {
    width = mdd_node_size(manager, k);
    range = manager->ranges[(k+1)/2];
    storage_size = manager->mdd_nodes[k].size;
    for (j = 0; j < storage_size; ++j) {
      n = mdd_node_get(manager, mdd_level_index(manager, k, j));
      if (n->flags & MDD_NODE_ALLOCATED) {
        non_zero = 0;
        for (i = 0; i < range; ++i)
          non_zero += n->children[i] != 0;
        if (2*non_zero < range)
          could_save += (range-2*non_zero)*sizeof(int);
      }
    }
  }

  fprintf(stderr, "%s/%d: optimal sparse nodes could save %lu bytes (%.2f %%)\n", __FILE__, __LINE__,
          could_save, could_save*100./manager->currently_allocated);
}

void malloc_statistics(mdd_manager_t *manager)
{
  int i, j;
  unsigned long could_save=0;

  for (i = 0; i < MDD_O_NB; ++i)
    for (j = 0; j <= 2*manager->nb_levels; ++j)
      could_save += cache_malloc_statistics(manager, i, j);

  fprintf(stderr, "%s/%d: malloc in cache leads to waste %lu bytes (%.2f %%)\n", __FILE__, __LINE__,
          could_save, could_save*100./manager->currently_allocated);
}

void final_statistics(mdd_manager_t *manager) {
  fprintf(stderr, "%s/%d:   cache worst length lookup: %u\n", __FILE__, __LINE__,
          manager->nb_cache_worst);
  fprintf(stderr, "%s/%d:   cache average length lookup: %.2f\n", __FILE__, __LINE__,
          (double)manager->nb_cache_lookup_entries/manager->nb_cache_lookups);

  fprintf(stderr, "%s/%d:   unique table worst length lookup: %u\n", __FILE__, __LINE__,
          manager->nb_unique_table_worst);
  fprintf(stderr, "%s/%d:   unique table average length lookup: %.2f\n", __FILE__, __LINE__,
          (double)manager->nb_unique_table_lookup_entries/manager->nb_unique_table_lookups);

  manager->currently_allocated -= (2*manager->nb_levels+1)*sizeof(mdd_node_storage_t);

  fprintf(stderr, "%s/%d: currently_allocated: %lu bytes\n", __FILE__, __LINE__, manager->currently_allocated);
}

void mdd_manager_free(mdd_manager_t *manager)
{
  int i;

  for (i = 0; i < MDD_O_NB; ++i) {
    free(manager->caches[i]);
  }

  for (i = 1; i <= 2*manager->nb_levels; ++i)
    unique_table_evmdd_free(manager, i);
  free(manager->evmdd_unique_tables);

  for (i = 1; i <= 2*manager->nb_levels; ++i)
    unique_table_mdd_free(manager, i);
  free(manager->mdd_unique_tables);

  for (i = 0; i <= 2*manager->nb_levels; ++i)
    evmdd_node_storage_free(manager, i);
  free(manager->evmdd_nodes);

  for (i = 0; i <= 2*manager->nb_levels; ++i)
    mdd_node_storage_free(manager, i);
  free(manager->mdd_nodes);

  free(manager->events);

  mdd_manager_free_var_names(manager);

  free(manager->ranges);

  free(manager->lower_bounds);

  free(manager);
}
