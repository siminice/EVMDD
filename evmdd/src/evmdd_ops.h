#ifndef EVMDD_OPS_H
#define EVMDD_OPS_H

/** \file
 * \author Pierre Roux
 * \date 2009
 *
 * \brief EVMDD operations.
 */

#include "evmdd_node.h"

/** Primed and unprimed variables.
 * We distingate two type of variables:
 * - FROM variables also called unprimed variables represent values of variables before a transition
 * - TO variables also called primed variables represent values of variables after a transition
 *
 * For each unprimed variable exists a corresponding primed variable and vice versa.
 * These variables are interleaved in diagrams and are essential to define transition relations.
 */
typedef enum {MDD_FROM=0,  /**< unprimed */
              MDD_TO=1     /**< primed   */
} from_to_t;

/** Create a new variable \f$x\f$.
 *
 * \b Complexity: constant
 *
 * \param manager the manager
 * \param k variable to create (variables are indiced from 1 to \a manager->nb_levels included)
 * \param primed tells wether it's a from (MDD_FROM or 0) or to variable (MDD_TO or 1)
 * \return a new EVMDD representing variable \f$x\f$ at level \a k.
 * either primed or not according to parameter \a primed.
 */
evmdd_edge_t evmdd_var_new(mdd_manager_t *manager, mdd_level_t k, from_to_t primed);

/** Create a new variable elevated at a constant power \f$x^n\f$.
 * Same as function evmdd_var_new except that the variable is elevated at the power \a power.
 *
 * evmdd_var_new(manager, k, primed) is actually the same as
 * evmdd_var_new_at_power(manager, k, primed, 1)
 *
 * \b Complexity: constant
 *
 * \param manager the manager
 * \param k variable to create (variables are indiced from 1 to \a manager->nb_levels included)
 * \param primed tells wether it's a from (MDD_FROM or 0) or to variable (MDD_TO or 1)
 * \param power positive integer
 * \return \f$x^{power}\f$
 */
evmdd_edge_t evmdd_var_new_at_power(mdd_manager_t *manager, mdd_level_t k, from_to_t primed, int power);

/** Add a constant to a function.
 * Add constant \a c to function represented by EVMDD \a p.
 *
 * \b Complexity: constant
 *
 * \param manager the manager
 * \param p an EVMDD representing any function
 * \param c constant to add to \a p
 * \return \f$p+c\f$
 */
evmdd_edge_t evmdd_add_scalar(mdd_manager_t *manager, evmdd_edge_t p, int c);
/** Multiply a function by a constant.
 * Multiply function represented with EVMDD \a p by constant \a c.
 *
 * \b Complexity: linear in size \f$|p|\f$ (number of nodes) of \a p
 *
 * \param manager the manager
 * \param p an EVMDD representing any function
 * \param c scalar
 * \return \f$p \times c\f$
 */
evmdd_edge_t evmdd_mult_scalar(mdd_manager_t *manager, evmdd_edge_t p, int c);
/** Add two functions.
 * Compute the EVMDD representing the sum of functions encoded in EVMDD \a p and \a q.
 *
 * \b Complexity: \f$\rm{O}(|p| \; |q|)\f$
 *
 * Not that of course the size of the result is bounded by previous expression.
 * More preciselly \f$|pq| \leq |p| \; |q|\f$
 *
 * \param manager the manager
 * \param p first operand
 * \param q second operand
 * \return \f$p+q\f$
 */
evmdd_edge_t evmdd_add(mdd_manager_t *manager, evmdd_edge_t p, evmdd_edge_t q);
/** Multiply two functions.
 * Compute the EVMDD representing the product of functions encoded in EVMDD \a p and \a q.
 *
 * \b Complexity: \f$\rm{O}(|p|^2 \; |q|^2 \; |pq|)\f$ (note that \f$|pq|\f$ could be exponential)
 *
 * \param manager the manager
 * \param p first operand
 * \param q second operand
 * \return \f$p \times q\f$
 */
evmdd_edge_t evmdd_mult(mdd_manager_t *manager, evmdd_edge_t p, evmdd_edge_t q);
/** Divide EVMDD by scalar (integer division, 3/2 = 1).
 * Requires p non negative and c positive.
 *
 * \b Complexity: \f$\rm{O}(|p|c)\f$
 *
 * \param manager the manager
 * \param p an EVMDD representing any function
 * \param c scalar
 * \return \f$p/c\f$
 */
evmdd_edge_t evmdd_div_scalar(mdd_manager_t *manager, evmdd_edge_t p, int c);
/** Compute reminder of division of EVMDD by scalar.
 * Requires p non negative and c positive.
 *
 * \b Complexity: \f$\rm{O}(|p|c)\f$
 *
 * \param manager the manager
 * \param p an EVMDD representing any function
 * \param c scalar
 * \return \f$p\%c\f$
 */
evmdd_edge_t evmdd_mod_scalar(mdd_manager_t *manager, evmdd_edge_t p, int c);
/** Divide two functions.
 * Compute the EVMDD representing the division (integer division) of functions encoded in EVMDD \a p and \a q.
 * Requires \a p non negative and \a q positive.
 *
 * \b Complexity: \f$\rm{O}(|p| \; r_p \; |q| \; r_q)\f$ where \f$r_p\f$ is the range of function represented by \a p (namely \f$\rm{max}(p)-\rm{min}(p)\f$)
 *
 * \param manager the manager
 * \param p first operand
 * \param q second operand
 * \return \f$p/q\f$
 */
evmdd_edge_t evmdd_div(mdd_manager_t *manager, evmdd_edge_t p, evmdd_edge_t q);
/** Compute reminder of division of two functions.
 * Compute the EVMDD representing the remainder of the division of functions encoded in EVMDD \a p and \a q.
 * Requires \a p non negative and \a q positive.
 *
 * \b Complexity: \f$\rm{O}(|p| \; r_p \; |q| \; r_q)\f$ where \f$r_p\f$ is the range of function represented by \a p (namely \f$\rm{max}(p)-\rm{min}(p)\f$)
 *
 * \param manager the manager
 * \param p first operand
 * \param q second operand
 * \return \f$p\%q\f$
 */
evmdd_edge_t evmdd_mod(mdd_manager_t *manager, evmdd_edge_t p, evmdd_edge_t q);
/** Compute minimum value of a function.
 * Return the smallest value function represented by \a p can take.
 *
 * \b Commplexity: constant
 *
 * \param manager the manager
 * \param p an EVMDD
 * \return \f$\rm{min}(p)\f$
 */
int evmdd_min(mdd_manager_t *manager, evmdd_edge_t p);
/** Compute maximum value of a function.
 * Return the greatest value function represented by \a p can take.
 *
 * \b Commplexity: \f$\rm{O}(|p|)\f$
 *
 * \param manager the manager
 * \param p an EVMDD
 * \return \f$\rm{max}(p)\f$
 */
long evmdd_max(mdd_manager_t *manager, evmdd_edge_t p);
/** Compute function \a p < \a c.
 * Return the MDD (see file mdd_node.h) representing the (boolean) function \a p < \a c.
 *
 * \b Complexity: \f$\rm{O}(|p| \; r_p)\f$ where \f$r_p\f$ is the range of function represented by \a p (namely \f$\rm{max}(p)-\rm{min}(p)\f$)
 *
 * \param manager the manager
 * \param p an EVMDD
 * \param c a constant value
 * \return \f$p < c\f$
 */
mdd_level_index_t evmdd_qlt_scalar(mdd_manager_t *manager, evmdd_edge_t p, int c);
/** Solve function \a p < \a c.
 * Return the MDD (see file mdd_node.h) representing a solution for \a p < \a c.
 *
 * \b Complexity: \f$\rm{O}(|p| \; r_p)\f$ where \f$r_p\f$ is the range of function represented by \a p (namely \f$\rm{max}(p)-\rm{min}(p)\f$)
 *
 * \param manager the manager
 * \param p an EVMDD
 * \param c a constant value
 * \return \f$p < c\f$
 */
mdd_level_index_t evmdd_lt_scalar(mdd_manager_t *manager, evmdd_edge_t p, int c);
/** Compute function \a p = \a q.
 * Return the MDD (see file mdd_node.h) representing the (boolean) function \a p = \a q.
 *
 * Note that \a p < \a q is just computed as \a p + (-1) * \a q < 0
 * which is easyer (int terms of complexity at least) to compute.
 *
 * \b Complexity: this function is just a shortcut to \a p + (-1) * \a q < 0,
 * see respective complexities of evmdd_mult_scalar, evmdd_add and evmdd_eq_scalar
 *
 * \param manager the manager
 * \param p an EVMDD
 * \param q an EVMDD
 * \return \f$p < q\f$
 */
mdd_level_index_t evmdd_lt(mdd_manager_t *manager, evmdd_edge_t p, evmdd_edge_t q);
/** Compute function \a p = \a c.
 * Return the MDD (see file mdd_node.h) representing the (boolean) function \a p = \a c.
 *
 * \b Complexity: \f$\rm{O}(|p| \; r_p)\f$ where \f$r_p\f$ is the range of function represented by \a p (namely \f$\rm{max}(p)-\rm{min}(p)\f$)
 *
 * \param manager the manager
 * \param p an EVMDD
 * \param c a constant value
 * \return \f$p = c\f$
 */
mdd_level_index_t evmdd_eq_scalar(mdd_manager_t *manager, evmdd_edge_t p, int c);
/** Compute function \a p = \a c.
 * Return the MDD (see file mdd_node.h) representing the (boolean) function \a p = \a c.
 *
 * \b Complexity: \f$\rm{O}(|p| \; r_p)\f$ where \f$r_p\f$ is the range of function represented by \a p (namely \f$\rm{max}(p)-\rm{min}(p)\f$)
 *
 * \param manager the manager
 * \param p an EVMDD
 * \param c a constant value
 * \return \f$p = c\f$
 */
mdd_level_index_t evmdd_qeq_scalar(mdd_manager_t *manager, evmdd_edge_t p, int c);
/** Compute a solution for \a p = \a q.
 * Return the MDD (see file mdd_node.h) representing a solution for \a p = \a q.
 *
 * Note that \a p = \a q is just computed as \a p + (-1) * \a q = 0
 * which is easyer (int terms of complexity at least) to compute.
 *
 * \b Complexity: this function is just a shortcut to \a p + (-1) * \a q = 0,
 * see respective complexities of evmdd_mult_scalar, evmdd_add and evmdd_eq_scalar
 *
 * \param manager the manager
 * \param p an EVMDD
 * \param q an EVMDD
 * \return \f$p = q\f$
 */
mdd_level_index_t evmdd_eq(mdd_manager_t *manager, evmdd_edge_t p, evmdd_edge_t q);
/** Return an EVMDD taking only values 0 and 1 and pointwisely equal to \a p.
 *
 * \b Complexity: \f$\rm{O}(|p|)\f$
 *
 * \param manager the manager
 * \param p MDD to be converted
 * \return an EVMDD equal to \a p
 */
evmdd_edge_t evmdd_from_mdd(mdd_manager_t *manager, mdd_level_index_t p);

#endif /* EVMDD_OPS_H */
