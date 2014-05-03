#ifndef BIGINT_PRIV_H
#define BIGINT_PRIV_H

#include "bigint.h"

/** Create a new bigint equal to int init_value.
 */
bigint_t *bigint_new(int init_value);
void bigint_free(bigint_t *n);

/** Add two bigints.
 * @param a first operand
 * @param b second operand
 * @param c bigint to place the result
 */
void bigint_add(bigint_t *a, bigint_t *b, bigint_t *c);

#endif /* BIGINT_PRIV_H */
