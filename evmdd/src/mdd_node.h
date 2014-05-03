#ifndef MDD_NODE_H
#define MDD_NODE_H

/** \file
 * \author Pierre Roux
 * \date 2009
 *
 * \brief Define MDD (Multiway Decision Diagrams), used for representing boolean functions.
 */

#include <stdio.h>
#include "mdd_manager.h"
#include "bigint.h"

/** Constant false.
 * \param manager the manager
 */
mdd_level_index_t mdd_const0(mdd_manager_t *manager);
/** Constant true.
 * \param manager the manager
 */
mdd_level_index_t mdd_const1(mdd_manager_t *manager);

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
void mdd_ref(mdd_manager_t *manager, mdd_level_index_t p);
/** Decrease reference count of a diagram.
 * Decrease the reference count of a diagram \a p.
 *
 * This must always occurs after a call to function mdd_ref.
 *
 * \b Complexity: constant.
 *
 * \see mdd_ref
 *
 * \param manager the manager
 * \param p the no longer in use diagram
 */
void mdd_unref(mdd_manager_t *manager, mdd_level_index_t p);

/** Print the states in an MDD to screen.
 *
 * \param manager the manager
 * \param p MDD to output
 * \param max maximum number of states to print
 */
void mdd_print_states(mdd_manager_t *manager, mdd_level_index_t p, int max);

/** Output a dot format representation of an MDD.
 * Output MDD \a p to famous dot format in file \a f.
 * Process the result with the program dot to obtain
 * a graphic representation of the diagram.
 *
 * This is of course untractable for real cases but
 * appears to be a useful tool to investigate
 * in small examples (no more than a few dozen of nodes).
 *
 * \b Complexity: linear in size of \a p.
 *
 * \param manager the manager
 * \param p MDD to output
 * \param f file in which to put the result graph
 */
void mdd_print_dot(mdd_manager_t *manager, mdd_level_index_t p, FILE *f);

/** Dump an MDD to a file, to be later reread.
 *
 * \b Complexity: linear in size of \a p.
 *
 * \param manager the manager
 * \param p MDD to output
 * \param f file in which to put the MDD
 */
void mdd_to_file(mdd_manager_t *manager, mdd_level_index_t p, FILE *f);

/** Read and MDD from file, previously written with mdd_to_file.
 *
 * \b Complexity: linear in size of the MDD read.
 *
 * \param manager the manager
 * \param f file in which to read the MDD
 * \return MDD read
 */
mdd_level_index_t mdd_from_file(mdd_manager_t *manager, FILE *f);

/** Number of nodes composing a diagram.
 *
 * \b Complexity: linear in size of \a p.
 *
 * \param manager the manager
 * \param p MDD we want to count the number of nodes
 * \return number of nodes in diagram \a p. 
 */
int mdd_num_nodes(mdd_manager_t *manager, mdd_level_index_t p);

/** Compute the total number of MDD nodes in manager.
 *
 * \b Complexity: linear in \a manager->nb_levels.
 *
 * \param manager the manager
 * \return sum of the maximum number of nodes
 * which can have been there simultaneously at each level.
 */
int mdd_total_num_nodes(mdd_manager_t *manager);

/** Return the cardinality of the set encoded by the EVMDD.
 *
 * See file bigint.h for ways to use the result.
 *
 * \b Complexity: linear in size of \a p.
 *
 * \param manager the manager
 * \param p MDD we want to count the number of states
 * \return number of elements evaluating to true in MDD \a p.
 */
bigint_t *mdd_num_encoded_elements(mdd_manager_t *manager, mdd_level_index_t p);

#endif /* MDD_NODE_H */
