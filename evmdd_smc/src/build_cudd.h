#ifndef BUILD_CUDD_H
#define BUILD_CUDD_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_CUDD

#include "ast.h"
#include "precompiled_ast_cudd.h"
/* CUDD */
#include "util.h"
#include "cudd.h"

DdNode *build_cudd_add_from_ast(DdManager *manager, struct ast *t);
DdNode *build_cudd_bdd_from_ast(DdManager *manager, struct ast *t);
DdNode *build_cudd_ctl(DdManager *manager, struct precompiled_ast_cudd *t, DdNode *ss);
/* indexes == NULL means identities at each level */
DdNode *build_cudd_identities(DdManager *manager, int *indexes, int n);

#endif /* HAVE_CUDD */

#endif /* BUILD_CUDD_H */
