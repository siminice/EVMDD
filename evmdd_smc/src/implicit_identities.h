#ifndef IMPLICIT_IDENTITIES_H
#define IMPLICIT_IDENTITIES_H

#include "ast.h"
#include <evmdd/mdd_manager.h>
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_CUDD
/* CUDD */
#include "util.h"
#include "cudd.h"
#endif

struct ast *implicit_identities(struct ast*);
int *implicit_identities_indexes(mdd_manager_t*, struct ast*);
#ifdef HAVE_CUDD
DdNode *implicit_identities_build_cudd(DdManager*, struct ast*);
#endif

#endif /* IMPLICIT_IDENTITIES_H */
