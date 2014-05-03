#ifndef GARBAGE_COLLECTOR_PRIV_H
#define GARBAGE_COLLECTOR_PRIV_H

#include "mdd_manager_priv.h"

void garbage_collector_mdd(mdd_manager_t*);
void garbage_collector_evmdd(mdd_manager_t*);

#endif /* GARBAGE_COLLECTOR_PRIV_H */
