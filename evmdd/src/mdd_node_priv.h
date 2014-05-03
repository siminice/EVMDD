#ifndef MDD_NODE_PRIV_H
#define MDD_NODE_PRIV_H

#include "mdd_node.h"

#include "mdd_manager_priv.h"

typedef struct mdd_node {
  mdd_node_flags_t flags;
  /* indeed the begin of an array which size is unknown now */
  mdd_level_index_t children[1];
} mdd_node_t;

typedef struct mdd_node_storage {
  unsigned int size;
  unsigned int maxsize;
  mdd_level_index_t free_stack;
  mdd_node_t *table;
} mdd_node_storage_t;

void mdd_node_storage_init(mdd_manager_t *, mdd_level_t);
void mdd_node_storage_free(mdd_manager_t *, mdd_level_t);

/* Create a new node at given level and return its index,
   reference count of new node will be 0,
   and all children will be initialized to 0.
   WARNING: this can move the storage table for all evmdd nodes at level k,
   hence all pointers on node at this level can become invalid after a call
   to this function.
   In practice this means, that following code should never be written:
     p = mdd_node_get(manager, k);
     mdd_node_new(manager, k);
     *p; // p may be an invalid pointer */
mdd_level_index_t mdd_node_new(mdd_manager_t *, mdd_level_t);

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
void mdd_node_free(mdd_manager_t *manager, mdd_level_index_t p);

void mdd_reset_mark(mdd_manager_t*, mdd_level_index_t);

/* hash function for mdd_nodes,
   the last parameter is some kind of prime number
   for hashing stuff */
int mdd_node_hash(mdd_manager_t *, mdd_level_index_t, int);

/* return 1 if two nodes have same children, 0 elsewhere */
int mdd_node_compare(mdd_manager_t *, mdd_level_index_t, mdd_level_index_t);

/* DEBUG */
void mdd_node_print(mdd_manager_t *manager, mdd_level_index_t);

void mdd_node_pair(mdd_manager_t *manager, mdd_level_index_t, char*);

/** Give size of any MDD node (in ints) at level k.
 */
static int mdd_node_size(mdd_manager_t *manager, mdd_level_t k)
{
  return (sizeof(mdd_node_t)+(manager->ranges[(k+1)/2]-1)*sizeof(mdd_level_index_t))/sizeof(int);
}

static mdd_node_t *mdd_node_get(mdd_manager_t *manager, mdd_level_index_t p)
{
  return (mdd_node_t*)((int*)(manager->mdd_nodes[mdd_level(manager, p)].table)+
                       mdd_index(manager, p)*mdd_node_size(manager, mdd_level(manager, p)));
}

#endif /* MDD_NODE_PRIV_H */
