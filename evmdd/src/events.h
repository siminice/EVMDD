#ifndef EVENTS_H
#define EVENTS_H

/** \file
 * \author Pierre Roux
 * \date 2009
 *
 * \brief Definition of events.
 *
 * The transition relation of the system is the disjunction of all events.
 * The registered events are used to compute state space.
 */

#include "mdd_manager.h"

/** Events.
 */
struct event_entry {
  mdd_level_index_t data;  /**< the actual event */
  char *name;  /**< potentially a name for event (can be NULL) */
  struct event_entry *next;  /**< potentially another event */
};

/** Add an event to manager.
 * The event will be registered in manager for use in
 * state space exploration.
 *
 * Build an MDD (identity reduced on odd levels and regularly reduced
 * on even levels) being the intersection of p and an MDD
 * with identity patterns at levels k
 * for which \a indexes[k] != 0 and nodes with all children pointing
 * on the same child elsewhere (meaning "don't care").
 *
 * Global transition relation will be the logic disjunction of all
 * registered events.
 *
 * \param manager the manager
 * \param p the event
 * \param indexes array of size \a manager->nb_levels+1
 * in which \a indexes[k] is non null iff we want an identity at this level,
 * \a indexes[0] is irelevant ; can be NULL if we don't want to add any identity
 * \param name NULL or a name for the event, string is copied and can be freed immediatly after the call
 * \param merge wether to merge (1) or not(0) this event to other events
 * possibly registered with same top affected level,
 * 1 to merge the event with potential other events sharing
 * same top level (usually more efficient) or 0 to keep it distinct (sometimes better)
 */
void event_register_name_merge(mdd_manager_t *manager, mdd_level_index_t p, int *indexes, char *name, int merge);
/** Add an event to manager.
 *
 * This is just a shortcut for event_register without name and with \p merge equal to 1.
 *
 * \param manager the manager
 * \param p the event
 * \param indexes see event_register_name_merge for details
 */
void event_register(mdd_manager_t *manager, mdd_level_index_t p, int *indexes);

#endif /* EVENTS_H */
