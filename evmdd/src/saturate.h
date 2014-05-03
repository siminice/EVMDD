#ifndef SATURATE_H
#define SATURATE_H

/** \file
 * \author Pierre Roux
 * \date 2009
 *
 * \brief Saturation algorithm.
 *
 * Saturation algorithm can compute efficiently reachable state space from some initial state
 * through a given transition relation.
 */

#include "mdd_manager.h"

/** Compute reachable states.
 * Compute reachable states from \a s with registered events in \a manager
 * using a saturation algorithm.
 *
 * event_register and saturate cannot be interleaved
 * (or the cache should be freed)
 *
 * \see file events.h to see how to define the transition relation
 *
 * \param manager all events should have been registered in it
 * \param s initial set of states
 * \return set of reachable states
 */
mdd_level_index_t saturate(mdd_manager_t *manager, mdd_level_index_t s);

#endif /* SATURATE_H */
