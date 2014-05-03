#ifndef TEST_CUDD_H
#define TEST_CUDD_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_CUDD

#include "ast.h"

void test_cudd_add_init_states(struct ast *t);
void test_cudd_add_event(struct ast *t);
void test_cudd_build_state_space();
void test_cudd_property(struct ast *t, char *name);
void test_cudd_quit();

#endif /* HAVE_CUDD */

#endif /* TEST_CUDD_H */
