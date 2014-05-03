#ifndef BUILD_H
#define BUILD_H

#include <evmdd/mdd_manager.h>
#include <evmdd/evmdd_node.h>
#include "ast.h"

evmdd_edge_t build_evmdd_from_ast(mdd_manager_t *manager, struct ast *t);
mdd_level_index_t build_mdd_from_ast(mdd_manager_t *manager, struct ast *t);
mdd_level_index_t solve_mdd_from_ast(mdd_manager_t *manager, struct ast *t);
evmdd_edge_t build_evmdd2_from_ast(mdd_manager_t *manager, struct ast *t);
mdd_level_index_t build_mdd2_from_ast(mdd_manager_t *manager, struct ast *t);
mdd_level_index_t build_ctl(mdd_manager_t *manager, struct ast *t, mdd_level_index_t ss);

#endif /* BUILD_H */
