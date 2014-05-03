#ifndef CTL_CUDD_H
#define CTL_CUDD_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_CUDD

/* CUDD */
#include "util.h"
#include "cudd.h"

DdNode *ctl_cudd_EX(DdManager *manager, DdNode *s);
DdNode *ctl_cudd_EG(DdManager *manager, DdNode *s);
DdNode *ctl_cudd_EU(DdManager *manager, DdNode *s1, DdNode *s2);

#endif /* HAVE_CUDD */

#endif /* CTL_CUDD_H */
