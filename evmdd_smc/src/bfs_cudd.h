#ifndef BFS_CUDD_H
#define BFS_CUDD_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_CUDD

/* CUDD */
#include "util.h"
#include "cudd.h"

#include "ast.h"
#include "precompiled_ast_cudd.h"

/** Compute reachable states.
 * Compute reachable states from s with registered events in event_cudd
 * using a breadth first search with chaining.
 * @param manager CUDD manager
 * @param s initial set of states
 * @return set of reachable states
 */
DdNode *bfs_cudd_chaining(DdManager *manager, DdNode *s);

/** Compute reachable states.
 * Compute reachable states from s with transition relation f
 * using a strict breadth first search.
 * @param manager CUDD manager
 * @param s initial set of states (BDD with only even variables)
 * @param f transition relation (BDD where even variables x are from variables
 * and odd variables x+1 represent to corresponding variables)
 * @return set of reachable states
 */
DdNode *bfs_cudd(DdManager *manager, DdNode *s, DdNode *f);

DdNode *bfs_cudd_prepare_trace(DdManager *manager, DdNode *s, DdNode *f, struct precompiled_ast_cudd *stop_property, DdNode ***steps, int *steps_sz);

#endif /* HAVE_CUDD */

#endif /* BFS_CUDD_H */
