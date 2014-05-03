#ifndef EVMDD_NODE_H
#define EVMDD_NODE_H

/** \file
 * \author Pierre Roux
 * \date 2009
 *
 * \brief Define EVMDD (Edge Valued Multiway Decision Diagrams), used for representing arithmetic functions.
 */

#include <stdio.h>
#include "mdd_manager.h"
#include "bigint.h"

/** Type of values on edges.
 * This is also the type of represented values.
 * int in practice.
 */
typedef int evmdd_edge_value_t;

/** Type of edges of decision diagrams.
 * Note that it is also the type of entire diagrams, value being the value of the topmost edge
 * and node a pointer to the remaining of the diagram.
 */
typedef struct evmdd_edge {
  evmdd_edge_value_t value;  /**< value attached to the edge */
  mdd_level_index_t node;  /**< node the edge is pointing to */
} evmdd_edge_t;

/** Increase reference count of a diagram.
 * Increase the reference count of diagram \a p.
 *
 * Don't forget to call function evmdd_unref as soon as you don't use the diagram
 * \a p anymore.
 *
 * C operating no garbage collector, reference count is the only way
 * to know if a diagram is still used by someone or not and so can be
 * released or not. That's why we use reference count for this interface
 * (but not necessarily internally).
 *
 * \b Complexity: constant.
 *
 * \param manager the manager
 * \param p the diagram we are using
 */
void evmdd_ref(mdd_manager_t *manager, evmdd_edge_t p);
/** Decrease reference count of a diagram.
 * Decrease the reference count of a diagram \a p.
 *
 * This must always occurs after a call to function evmdd_ref.
 *
 * \b Complexity: constant.
 *
 * \see evmdd_ref
 *
 * \param manager the manager
 * \param p the no longer in use diagram
 */
void evmdd_unref(mdd_manager_t *manager, evmdd_edge_t p);

/** Output a dot format representation of an EVMDD.
 * Output EVMDD \a p to famous dot format in file \a f.
 * Process the result with the program dot to obtain
 * a graphic representation of the diagram.
 *
 * This is of course untractable for real cases but
 * can appears to be a precious tool to see what happen
 * in small examples (no more than a few dozen of nodes).
 *
 * \b Complexity: linear in size of \a p.
 *
 * \param manager the manager
 * \param p EVMDD to output
 * \param f file in which to put the result graph
 */
void evmdd_print_dot(mdd_manager_t *manager, evmdd_edge_t p, FILE *f);
/** Dump an EVMDD to a file, to be later reread.
 *
 * \b Complexity: linear in size of \a p.
 *
 * \param manager the manager
 * \param p EVMDD to output
 * \param f file in which to put the EVMDD
 */
void evmdd_to_file(mdd_manager_t *manager, evmdd_edge_t p, FILE *f);
/** Read and EVMDD from file, previously written with mdd_to_file.
 *
 * \b Complexity: linear in size of the EVMDD read.
 *
 * \param manager the manager
 * \param f file in which to read the EVMDD
 * \return EVMDD read
 */
evmdd_edge_t evmdd_from_file(mdd_manager_t *manager, FILE *f);
/** Number of nodes composing a diagram.
 *
 * \b Complexity: linear in size of \a p.
 *
 * \param manager the manager
 * \param p EVMDD we want to count the number of nodes
 * \return number of nodes in diagram \a p. 
 */
int evmdd_num_nodes(mdd_manager_t *manager, evmdd_edge_t p);
/** Total number of nodes allocated in manager.
 *
 * \b Complexity: linear in \a manager->nb_levels.
 *
 * \param manager the manager
 * \return sum of the maximum number of nodes
 * which can have been there simultaneously at each level.
 */
int evmdd_total_num_nodes(mdd_manager_t *manager);
/** Return the cardinal of the set encoded by the EVMDD.
 *
 * See file bigint.h for ways to use the result.
 *
 * \b Complexity: linear in size of \a p.
 *
 * \param manager the manager
 * \param p EVMDD we want to count the number of states
 * \return number of elements evaluating
 * at something different from INT_MAX in EVMDD \a p.
 */
bigint_t *evmdd_num_encoded_elements(mdd_manager_t *manager, evmdd_edge_t p);

#endif /* EVMDD_NODE_H */
