#ifndef SAL_INTF_H
#define SAL_INTF_H

/** \file
 * \author Pierre Roux
 * \date 2010
 *
 * \brief Include header with some wrapping functions
 * to use in SAL Scheme source code.
 *
 * It seems hard to have Scheme code manipulating C struct
 * hence all those wrappers.
 */

#include "mdd_manager.h"
#include "evmdd_node.h"
#include "evmdd_ops.h"

/** wrapper to evmdd_var_new */
evmdd_edge_t *sal_evmdd_var_new(mdd_manager_t *manager, mdd_level_t k, from_to_t primed);

/** wrapper to evmdd_eq_scalar */
mdd_level_index_t sal_evmdd_eq_scalar(mdd_manager_t *manager, evmdd_edge_t* p, int c);

/** wrapper to evmdd_eq */
mdd_level_index_t sal_evmdd_eq(mdd_manager_t *manager, evmdd_edge_t *p, evmdd_edge_t *q);

/** wrapper to evmdd_lt */
mdd_level_index_t sal_evmdd_lt(mdd_manager_t *manager, evmdd_edge_t* p, int c);

/** wrapper to evmdd_add_scalar */
evmdd_edge_t *sal_evmdd_add_scalar(mdd_manager_t *manager, evmdd_edge_t* p, int c);

/** wrapper to evmdd_add */
evmdd_edge_t *sal_evmdd_add(mdd_manager_t *manager, evmdd_edge_t* p, evmdd_edge_t* q);

/** wrapper to evmdd_mult_scalar */
evmdd_edge_t *sal_evmdd_mult_scalar(mdd_manager_t *manager, evmdd_edge_t* p, int c);

/** wrapper to evmdd_mult */
evmdd_edge_t *sal_evmdd_mult(mdd_manager_t *manager, evmdd_edge_t* p, evmdd_edge_t* q);

/** wrapper to mdd_num_encoded_elements */
void sal_mdd_num_encoded_elements(mdd_manager_t *manager, mdd_level_index_t p);

mdd_level_index_t saturate_withtime(mdd_manager_t *manager, mdd_level_index_t p);
#endif /* SAL_INTF_H */
