#ifndef EVENTS_PRIV_H
#define EVENTS_PRIV_H

#include "events.h"

/* Computes the union of all previously registered events
 * (i.e. the entire transtion relation)
 * and put it in manager->all_events. */
void event_union_all(mdd_manager_t *manager);

#endif /* EVENTS_PRIV_H */
