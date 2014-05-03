#ifndef BFS_H
#define BFS_H

#include <evmdd/mdd_manager.h>

/** Compute reachable states.
 * Compute reachable states from s with registered events in manager
 * using a breadth first search with chaining.
 * @param manager all events should have been registered in it
 * @param s initial set of states
 * @return set of reachable states
 */
mdd_level_index_t bfs_chaining(mdd_manager_t *manager, mdd_level_index_t s);
/** Compute reachable states.
 * Compute reachable states from s with registered events in manager
 * using a breadth first search (next(current (<= n)) is computed)
 * with event obtained from mdd_manager_get_all_events.
 * @param manager all events should have been registered in it
 * @param s initial set of states
 * @param bound stop after bound iterations
 * @return set of reachable states
 */
mdd_level_index_t bfs(mdd_manager_t *manager, mdd_level_index_t s, int bound);
/** Compute reachable states.
 * Compute reachable states from s with registered events in manager
 * using a strict breadth first search (only next(frontier (=n)) is computed)
 * with event obtained from mdd_manager_get_all_events.
 * @param manager all events should have been registered in it
 * @param s initial set of states
 * @param bound stop after bound iterations
 * @return set of reachable states
 */
mdd_level_index_t strict_bfs(mdd_manager_t *manager, mdd_level_index_t s, int bound);

#endif /* BFS_H */
