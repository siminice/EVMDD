#ifndef MDD_OPS_H
#define MDD_OPS_H

/** \file
 * \author Pierre Roux
 * \date 2009
 *
 * \brief MDD operations.
 */

#include "mdd_node.h"

/** Compute the boolean negation of a function.
 * This is also the complement of set represented by \a p.
 * 
 * \b Complexity: \f$\rm{O}(|p|)\f$
 *
 * \param manager the manager
 * \param p MDD to be negated
 */
mdd_level_index_t mdd_not(mdd_manager_t *manager, mdd_level_index_t p);
/** Disjunction of two functions.
 * Compute the MDD representing the logic disjunction (resp. union) of functions (resp. sets) encoded in MDD \a p and \a q.
 *
 * \b Complexity: \f$\rm{O}(|p| \; |q|)\f$
 *
 * Not that of course the size of the result is bounded by previous expression.
 * More preciselly \f$|pq| \leq |p| \; |q|\f$
 *
 * \param manager the manager
 * \param p first operand
 * \param q second operand
 */
mdd_level_index_t mdd_union(mdd_manager_t *manager, mdd_level_index_t p, mdd_level_index_t q);
/** Conjunction of two functions.
 * Compute the MDD representing the logic conjunction (resp. intersection) of functions (resp. sets) encoded in MDD \a p and \a q.
 *
 * \b Complexity: \f$\rm{O}(|p| \; |q|)\f$
 *
 * Not that of course the size of the result is bounded by previous expression.
 * More preciselly \f$|pq| \leq |p| \; |q|\f$
 *
 * \param manager the manager
 * \param p first operand
 * \param q second operand
 */
mdd_level_index_t mdd_inter(mdd_manager_t *manager, mdd_level_index_t p, mdd_level_index_t q);
/** Compute image of \a s by \a f.
 *
 * \b Complexity: \f$\rm{O}(|s| \; |f|)\f$
 *
 * \param manager the manager
 * \param s an MDD representing a set of states
 * \param f an MDD representing a transition relation (tipically obtained from an event, see file events.h)
 * \return an MDD representing \f$f(s)\f$
 */
mdd_level_index_t mdd_next(mdd_manager_t *manager, mdd_level_index_t s, mdd_level_index_t f);
/** Compute union of \a s and its image by \a f.
 *
 * \b Complexity: \f$\rm{O}(|s| \; |f|)\f$
 *
 * \param manager the manager
 * \param s an MDD representing a set of states
 * \param f an MDD representing a transition relation (tipically obtained from an event, see file events.h)
 * \return an MDD representing \f$s \cup f(s)\f$
 */
mdd_level_index_t mdd_add_next(mdd_manager_t *manager, mdd_level_index_t s, mdd_level_index_t f);
/** Compute reverse image of \a s by \a f.
 *
 * \b Complexity: \f$\rm{O}(|s| \; |f|)\f$
 *
 * \param manager the manager
 * \param s an MDD representing a set of states
 * \param f and MDD representing a transition relation
 * \return an MDD representing \f$f^{-1}(s)\f$
 */
mdd_level_index_t mdd_prev(mdd_manager_t *manager, mdd_level_index_t s, mdd_level_index_t f);
/** Compute union of \a s and its reverse image by \a f.
 *
 * \b Complexity: \f$\rm{O}(|s| \; |f|)\f$
 *
 * \param manager the manager
 * \param s an MDD representing a set of states
 * \param f and MDD representing a transition relation
 * \return an MDD representing \f$s \cup f^{-1}(s)\f$
 */
mdd_level_index_t mdd_add_prev(mdd_manager_t *manager, mdd_level_index_t s, mdd_level_index_t f);
/** Return an MDD representing only one state of the set represented by \a s.
 *
 * \b Complexity: \f$\rm{O}(l)\f$ with \f$l\f$ number of levels represented in \f$s\f$
 * (at most \f$|s|\f$)
 *
 * \param manager the manager
 * \param s an MDD representing a set of states
 * \return an MDD representing a unique state of \a s
 * or the empty set if \a s was empty.
 */
mdd_level_index_t mdd_choose(mdd_manager_t *manager, mdd_level_index_t s);

#endif /* MDD_OPS_H */
