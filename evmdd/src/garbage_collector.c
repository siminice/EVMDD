#include <stdio.h>  /* DEBUG */
#include "garbage_collector_priv.h"
#include "mdd_manager_priv.h"
#include "mdd_node_priv.h"
#include "evmdd_node_priv.h"
#include "unique_table_priv.h"
#include "cache_priv.h"
#include "clock_priv.h"

void garbage_collector_mdd(mdd_manager_t *manager)
{
  int k, j, i, range, width, storage_size;
  mdd_ops_t op;
  mdd_node_t *n;

  int nb_released=0, nb_kept=0;
  clock_t start, stop;
  start = clock_get();
  fprintf(stderr, "%s/%d: MDD Garbage collection (currently_allocated = %lu bytes)...\n", __FILE__, __LINE__,
          manager->currently_allocated);

  for (k = 2*manager->nb_levels; k; --k) {
    width = mdd_node_size(manager, k);
    storage_size = manager->mdd_nodes[k].size;
    range = manager->ranges[(k+1)/2];
    manager->mdd_nodes[k].free_stack = 0;
    for (j = 0; j < storage_size; ++j) {
      n = mdd_node_get(manager, mdd_level_index(manager, k, j));
      if (n->flags & MDD_NODE_REFERENCE_COUNT) n->flags |= MDD_NODE_MARK;
      if (n->flags & MDD_NODE_MARK) {
        /* mark children of n */
        for (i = 0; i < range; ++i)
          mdd_node_get(manager, n->children[i])->flags |= MDD_NODE_MARK;
        ++nb_kept;
      } else {
        /* free the node n */
        n->children[0] = manager->mdd_nodes[k].free_stack;
        manager->mdd_nodes[k].free_stack = mdd_level_index(manager, k, j);
        if (n->flags & MDD_NODE_ALLOCATED) {
          ++nb_released;
          n->flags &= ~MDD_NODE_ALLOCATED;
        }
      }
    }
  }

  for (k = 2*manager->nb_levels; k; --k) {
    unique_table_mdd_cleanup(manager, k);
    for (op = 0; op < MDD_O_NB; ++op)
      cache_mdd_cleanup(manager, op, k);
  }

  /* reset flags */
  for (k = 2*manager->nb_levels; k; --k) {
    storage_size = manager->mdd_nodes[k].size;
    for (j = 0; j < storage_size; ++j)
      mdd_node_get(manager, mdd_level_index(manager, k, j))->flags &= ~MDD_NODE_MARK;
  }

  manager->gc_threshold = (manager->memlimit + manager->gc_threshold)/2;
  /* pure sanity check, just in case someone changes the above gc policy */
  if (manager->gc_threshold > manager->memlimit)
    manager->gc_threshold = manager->memlimit;

  stop = clock_get();
  fprintf(stderr, "%s/%d: MDD Garbage collection released %d nodes and kept %d (currently_allocated = %lu bytes)\n", __FILE__, __LINE__, nb_released, nb_kept, manager->currently_allocated);
  fprintf(stderr, "%s/%d: MDD Garbage collection done in: ", __FILE__, __LINE__); clock_print(start, stop);
  clock_free(start);
  clock_free(stop);
}

void garbage_collector_evmdd(mdd_manager_t *manager)
{
  int k, j, i, range, width, storage_size;
  mdd_ops_t op;
  evmdd_node_t *n;

  int nb_released=0, nb_kept=0;
  clock_t start, stop;
  start = clock_get();
  fprintf(stderr, "%s/%d: EVMDD Garbage collection (currently_allocated = %lu bytes)...\n", __FILE__, __LINE__,
          manager->currently_allocated);

  for (k = 2*manager->nb_levels; k; --k) {
    width = evmdd_node_size(manager, k);
    storage_size = manager->evmdd_nodes[k].size;
    range = manager->ranges[(k+1)/2];
    manager->evmdd_nodes[k].free_stack = 0;
    for (j = 0; j < storage_size; ++j) {
      n = evmdd_node_get(manager, mdd_level_index(manager, k, j));
      if (n->flags & MDD_NODE_REFERENCE_COUNT) n->flags |= MDD_NODE_MARK;
      if (n->flags & MDD_NODE_MARK) {
        /* mark children of n */
        for (i = 0; i < range; ++i)
          evmdd_node_get(manager, n->edges[i].node)->flags |= MDD_NODE_MARK;
        ++nb_kept;
      } else {
        /* free the node n */
        n->edges[0].node = manager->evmdd_nodes[k].free_stack;
        manager->evmdd_nodes[k].free_stack = mdd_level_index(manager, k, j);
        if (n->flags & MDD_NODE_ALLOCATED) {
          ++nb_released;
          n->flags &= ~MDD_NODE_ALLOCATED;
        }
      }
    }
  }

  for (k = 2*manager->nb_levels; k; --k) {
    unique_table_evmdd_cleanup(manager, k);
    for (op = 0; op < MDD_O_NB; ++op)
      cache_evmdd_cleanup(manager, op, k);
  }

  /* reset flags */
  for (k = 2*manager->nb_levels; k; --k) {
    storage_size = manager->evmdd_nodes[k].size;
    for (j = 0; j < storage_size; ++j)
      evmdd_node_get(manager, mdd_level_index(manager, k, j))->flags &= ~MDD_NODE_MARK;
  }

  manager->gc_threshold = (manager->memlimit + manager->gc_threshold)/2;
  /* pure sanity check, just in case someone changes the above gc policy */
  if (manager->gc_threshold > manager->memlimit)
    manager->gc_threshold = manager->memlimit;

  stop = clock_get();
  fprintf(stderr, "%s/%d: EVMDD Garbage collection released %d nodes and kept %d (currently_allocated = %lu bytes)\n", __FILE__, __LINE__, nb_released, nb_kept, manager->currently_allocated);
  fprintf(stderr, "%s/%d: EVMDD Garbage collection done in: ", __FILE__, __LINE__); clock_print(start, stop);
  clock_free(start);
  clock_free(stop);

  for (k = 2*manager->nb_levels; k; --k)
    fprintf(stderr, "%s/%d: level %d, size: %d\n", __FILE__, __LINE__, k, manager->evmdd_nodes[k].size);
}
