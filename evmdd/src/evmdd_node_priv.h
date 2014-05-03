#ifndef EVMDD_NODE_PRIV_H
#define EVMDD_NODE_PRIV_H

#include "evmdd_node.h"

typedef struct evmdd_node {
  mdd_node_flags_t flags;
  /* indeed the begin of an array which size is unknown now */
  evmdd_edge_t edges[1];
} evmdd_node_t;

typedef struct evmdd_node_storage {
  unsigned int size;
  unsigned int maxsize;
  mdd_index_t free_stack;
  evmdd_node_t *table;
} evmdd_node_storage_t;

void evmdd_node_storage_init(mdd_manager_t *, mdd_level_t);
void evmdd_node_storage_free(mdd_manager_t *, mdd_level_t);

/* Create a new node at given level and return its index,
   reference count of new node will be 0,
   and all children will be initialized to 0.
   WARNING: edge values are not initialized
   WARNING: this can move the storage table for all evmdd nodes at level k,
   hence all pointers on node at this level can become invalid after a call
   to this function (indexes remain valid of course)
   In practice this means, that following code should never be written:
     p = evmdd_node_get(manager, k);
     evmdd_node_new(manager, k);
     *p; // p may be an invalid pointer */
mdd_level_index_t evmdd_node_new(mdd_manager_t *, mdd_level_t);

/** Free a node.
 *
 * You have to be absolutely sure that there is no incoming arc
 * on this node.
 *
 * Not any attempt will be made to delete children.
 *
 * @param manager
 * @param p must be an index referencing a valid node
 */
void evmdd_node_free(mdd_manager_t *manager, mdd_level_index_t p);

void evmdd_reset_mark(mdd_manager_t*, mdd_level_index_t);

/* hash function for evmdd_nodes,
   the last parameter is some kind of prime number
   for hashing stuff */
int evmdd_node_hash(mdd_manager_t *, mdd_level_index_t, int);

/* return 1 if two nodes have same edges, 0 elsewhere */
int evmdd_node_compare(mdd_manager_t *, mdd_level_index_t, mdd_level_index_t);

/** Give size of any EVMDD node (in ints) at level k.
 */
static int evmdd_node_size(mdd_manager_t *manager, mdd_level_t k)
{
  return (sizeof(evmdd_node_t)+(manager->ranges[(k+1)/2]-1)*sizeof(evmdd_edge_t))/sizeof(int);
}

static evmdd_node_t *evmdd_node_get(mdd_manager_t *manager, mdd_level_index_t i)
{
  return (evmdd_node_t*)((int*)(manager->evmdd_nodes[mdd_level(manager, i)].table)+
                         mdd_index(manager, i)*evmdd_node_size(manager, mdd_level(manager, i)));
}

#endif /* EVMDD_NODE_PRIV_H */
