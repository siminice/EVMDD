#ifndef BIGINT_H
#define BIGINT_H

/** \file
 * \author Pierre Roux
 * \date 2009
 *
 * \brief Arbitrary precision integers.
 *
 * Those very simple arbitrary precision integers are only
 * used for the purpose of counting states in state space
 * (see function mdd_num_encoded_elements in file mdd_node.h for example).
 * Only available operations are (because they are the only one needed for previously specified purpose):
 * - initialisation from a machine integer
 * - addition of two bigint
 * - printing in decimal format
 *
 * Note that the internal representation in base 1.000.000.000 may not be the most efficient
 * but was chosen for the great simplicity of decimal printing.
 */

/** Big int with addition.
 * In order to compute the number of states encoded by an MDD.
 */
typedef struct bigint bigint_t;

/** Print a bigint.
 * Print the value represented by the bigint \a n in decimal format (with thousand separator . and order of magnitute at end).
 * \param n bigint to print
 * \param f where to print n (for example stdout)
 */
void bigint_print(bigint_t *n, FILE *f);

#endif /* BIGINT_H */
