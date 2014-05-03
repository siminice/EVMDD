#ifndef EF_TRACE_CUDD_H
#define EF_TRACE_CUDD_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_CUDD

/* CUDD */
#include "util.h"
#include "cudd.h"

#include "ast.h"
#include "precompiled_ast_cudd.h"

void ef_trace_print_cube(int *cube);

void ef_trace_cudd(DdManager *manager, DdNode **steps, int steps_sz,
                   DdNode *goal, DdNode *transition_relation);

#endif /* HAVE_CUDD */

#endif /* EF_TRACE_CUDD_H */
