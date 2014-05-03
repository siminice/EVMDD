#ifndef TRANS_CUDD_H
#define TRANS_CUDD_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_CUDD

/* CUDD */
#include "util.h"
#include "cudd.h"

/** Init transition relation stuff.
 * It is mandatory to call this function before
 * calling any of the next/prev following functions.
 * It need only be called once. Multiple calls
 * will just be of no effect.
 */
void trans_cudd_init(DdManager *manager);
void trans_cudd_free(DdManager *manager);

DdNode *trans_cudd_next(DdManager *manager, DdNode *s, DdNode *f);
DdNode *trans_cudd_add_next(DdManager *manager, DdNode *s, DdNode *f);
DdNode *trans_cudd_prev(DdManager *manager, DdNode *s, DdNode *f);
DdNode *trans_cudd_add_prev(DdManager *manager, DdNode *s, DdNode *f);

#endif /* HAVE_CUDD */

#endif /* TRANS_CUDD_H */
