#ifndef EVENT_CUDD_H
#define EVENT_CUDD_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_CUDD

/* CUDD */
#include "util.h"
#include "cudd.h"

/* put event in env and return a unique positive id for it
   please note that now env is the "owner" of the string name and the BDD
   (which will be deleted with event_cudd_free) */
int event_cudd_put(char *name, DdNode *n);

/* return name of variable id
   or NULL if invalid id */
char *envent_cudd_name(int id);

/* return BDD of variable id
   or NULL if invalid id */
DdNode *event_cudd_bdd(int id);

/* return the number n of events recorded in env,
   valid variables ids are then [1..n]  */
int event_cudd_size();

/* delete all variables in env */
void event_cudd_free(DdManager *manager);

#endif /* HAVE_CUDD */

#endif /* EVENT_CUDD_H */
