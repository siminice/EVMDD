#ifndef SATURATE_DIST_H
#define SATURATE_DIST_H

/** \file
 * \author Pierre Roux
 * \date 2009
 *
 * \brief Saturation algorithm computing distances.
 *
 * Saturation algorithm can compute efficiently reachable state space from some initial state
 * through a given transition relation. This version keep track of minimum distance
 * between each reachable state and a state in initial states.
 */

#include "mdd_manager.h"
#include "evmdd_node.h"

/** Compute reachable states.
 * Compute reachable states from s with registered events in manager
 * using a saturation algorithm.
 *
 * event_register and saturate cannot be interleaved
 * (or the cache should be freed)
 *
 * \see file events.h to see how to define the transition relation
 *
 * \param manager all events should have been registered in it
 * \param s initial set of states
 * \param state_space MDD representing state space used to try to speed up the computation of distance function
 * \return EVMDD encoding distance of states from initial set of states (INT_MAX means unreachable)
 */
evmdd_edge_t saturate_dist(mdd_manager_t *manager, mdd_level_index_t s, mdd_level_index_t state_space);

#endif /* SATURATE_DIST_H */
