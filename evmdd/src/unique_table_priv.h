#ifndef UNIQUE_TABLE_PRIV_H
#define UNIQUE_TABLE_PRIV_H

#include "mdd_manager_priv.h"

typedef struct unique_table_entry {
  mdd_level_index_t data;
  struct unique_table_entry *next;
} unique_table_entry_t;

typedef struct unique_table {
  unsigned int size;
  unsigned int nb_elements;
  unique_table_entry_t **table;
} unique_table_t;

/* create a new (ev)mdd(2)_unique_table */
void unique_table_mdd_init(mdd_manager_t *, mdd_level_t);
void unique_table_evmdd_init(mdd_manager_t *, mdd_level_t);
void unique_table_mdd_free(mdd_manager_t *, mdd_level_t);
void unique_table_evmdd_free(mdd_manager_t *, mdd_level_t);

/** Insert node in unique table or return node already present in it.
 * Check if node <k|p> is present in unique table, if yes return corresponding node,
 * elsewhere add <k|p> to unique table and return it.
 *
 * Warning: this function may release node <k|p>, be sure that p has no incoming arc when
 * calling this function.
 *
 * @param manager the manager
 * @param p node to check
 * @return index of node duplicate of p in unique table if there is one or p elsewhere
 */
mdd_level_index_t unique_table_mdd_checkin(mdd_manager_t *manager, mdd_level_index_t p);
mdd_level_index_t unique_table_evmdd_checkin(mdd_manager_t *, mdd_level_index_t);

/** Add node to unique table.
 */
void unique_table_mdd_add(mdd_manager_t *manager, mdd_level_index_t p, int signature);
void unique_table_evmdd_add(mdd_manager_t *, mdd_level_index_t, int);

/** Remove all MDD nodes without flag MDD_NODE_MARK from unique_table.
 * Remove all nodes with flag MDD_NODE_MARK set to 0 from unique_table
 * for level k.
 */
void unique_table_mdd_cleanup(mdd_manager_t *manager, mdd_level_t k);
/** Remove all EVMDD nodes without flag MDD_NODE_MARK from unique_table.
 * Remove all nodes with flag MDD_NODE_MARK set to 0 from unique_table
 * for level k.
 */
void unique_table_evmdd_cleanup(mdd_manager_t *manager, mdd_level_t k);

#endif /* UNIQUE_TABLE_PRIV_H */
