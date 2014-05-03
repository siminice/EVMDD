#ifndef EF_TRACE_H
#define EF_TRACE_H

#include <evmdd/evmdd.h>

void ef_trace(mdd_manager_t *manager,
              evmdd_edge_t evmdd_state_space,
              mdd_level_index_t goal);

#endif /* EF_TRACE_H */
