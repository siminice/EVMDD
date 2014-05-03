#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_CUDD

#include <stdio.h>
#include <assert.h>
/* CUDD */
#include "util.h"
#include "cudd.h"

#include "normalize.h"
#include "ast.h"
#include "build_cudd.h"
#include "test_cudd.h"
#include "event_cudd.h"
#include "trans_cudd.h"
#include "bfs_cudd.h"
#include "env.h"
#include "clock.h"
#include "utils.h"
#include "implicit_identities.h"
#include "precompiled_ast_cudd.h"
#include "ef_trace_cudd.h"

static DdManager *manager=NULL;

static DdNode *initial_states = 0;
static DdNode *transition_relation = 0;

/* CUDD implements _binary_ decision diagrams,
 * so the first thing to do is mapping our variables to booleans,
 * the array cudd_var_bits stores this mapping.
 *
 * More precisely, for all i from 0 to l (number of variables),
 * cudd_var_bits[i] is the number of boolean variables used to encode
 * variables indexed from i+1 to l (primed and unprimed, so may be twice the expected value).
 * So for example, cudd_var_bits[0] is the total number of boolean variables,
 * cudd_var_bits[l] is always 0 and
 * cudd_var_bits[i-1]-cudd_var_bits[i] is the number of boolean variables
 * used to represent variable i and i' (original variables are indexed from 1 to l).
 *
 * Most significant bit has lower indice.
 *
 * It can also be interesting to notice that in BDD,
 * boolean variable of indice i will stand for
 * an unprimed variable ("from" variables) if i is even
 * and for the prime corresponding ("to" variables) if i is odd. */
int cudd_var_bits[ENV_SIZE];

extern char *dot_output;
extern int verbosity_level;
extern int use_bfs;
extern int witness;

/* wether we have to compute reachable state space or not */
static int compute_ss = 0;

static DdManager *get_manager()
{
  int i, l;
  int lb, ub;
  int tmp, next_var;

  if (manager == NULL) {
    l = env_size();
    next_var = 0;
    for (i = l; i; --i) {
      env_name(i, &lb, &ub);
      cudd_var_bits[i] = next_var;
      tmp = ub-lb;
      while (tmp) {
        tmp >>= 1;
        next_var += 2;
      }
    }
    cudd_var_bits[0] = next_var;
    
    manager = Cudd_Init(0, 0, CUDD_UNIQUE_SLOTS, CUDD_CACHE_SLOTS, 0);
  }

  return manager;
}

void test_cudd_add_init_states(struct ast *t)
{
  DdNode *p, *oldis;
#ifdef USE_ADD
  DdNode *add;
#endif

  clock_global_start();
  p = build_cudd_bdd_from_ast(get_manager(), t);
  clock_global_stop();
  if (verbosity_level >= 2) {
    printf("  Construction of BDD: "); clock_global_print();
    printf("  number of nodes of resulting BDD: %d\n", Cudd_DagSize(p));
  }

  oldis = initial_states;
  Cudd_Ref(p);
#ifdef USE_ADD
  add = p;
  p = Cudd_addBddPattern(get_manager(), add);
  Cudd_Ref(p);
  Cudd_RecursiveDeref(get_manager(), add);
#endif
  if (oldis) {
    initial_states = Cudd_bddAnd(get_manager(), p, oldis);
    Cudd_Ref(initial_states);
    Cudd_RecursiveDeref(get_manager(), p);
    Cudd_RecursiveDeref(get_manager(), oldis);
  } else
    initial_states = p;

  ast_free(t);
}

void test_cudd_add_event(struct ast *t)
{
  DdNode *p, *implicit_identities, *conj, *oldtrans;
#ifdef USE_ADD
  DdNode *add;
#endif

  normalize(t);
  if (verbosity_level >= 2) {
    printf("= "); ast_print(t);
  }

  clock_global_start();

  implicit_identities = implicit_identities_build_cudd(get_manager(), t);
  Cudd_Ref(implicit_identities);
  p = build_cudd_bdd_from_ast(get_manager(), t);
  clock_global_stop();
  if (verbosity_level >= 2) {
    printf("  Construction of BDD: "); clock_global_print();
    printf("  number of nodes of resulting BDD: %d\n", Cudd_DagSize(p));
  }

  Cudd_Ref(p);
#ifdef USE_ADD
  add = p;
  p = Cudd_addBddPattern(get_manager(), add);
  Cudd_Ref(p);
  Cudd_RecursiveDeref(get_manager(), add);
#endif
  conj = Cudd_bddAnd(get_manager(), p, implicit_identities);
  Cudd_Ref(conj);
  Cudd_RecursiveDeref(get_manager(), implicit_identities);
  Cudd_RecursiveDeref(get_manager(), p);
  if (use_bfs == 2) {
    event_cudd_put(NULL, conj);
    Cudd_Deref(conj);
  } else {
    oldtrans = transition_relation;
    if (oldtrans) {
      transition_relation = Cudd_bddOr(get_manager(), conj, oldtrans);
      Cudd_Ref(transition_relation);
      Cudd_RecursiveDeref(get_manager(), conj);
      Cudd_RecursiveDeref(get_manager(), oldtrans);
    } else
      transition_relation = conj;
  }

  compute_ss = 1;

  ast_free(t);
}

static DdNode *get_state_space(struct precompiled_ast_cudd *stop_property, DdNode ***steps, int *steps_sz)
{
  static DdNode *state_space;
  FILE *f;

  if (compute_ss) {
    if (!stop_property) compute_ss = 0;
    trans_cudd_init(manager);
    printf("Computing reachable state space...\n");
    clock_global_start();
    if (use_bfs == 2)  /* BFS with chaining */
      state_space = bfs_cudd_chaining(get_manager(),
                                      initial_states);
    else {
      event_cudd_put(NULL, transition_relation);
      if (stop_property)      
        state_space = bfs_cudd_prepare_trace(get_manager(),
                                             initial_states,
                                             transition_relation,
                                             stop_property, steps, steps_sz);
      else
        state_space = bfs_cudd(get_manager(),
                               initial_states,
                               transition_relation);
    }
    clock_global_stop();
    printf("State space computation: "); clock_global_print();
    /* TODO: count states */
/*     printf("Number of reachable states: %f\n", Cudd_CountMinterm(manager, state_space, env_size())); */
    if (dot_output) {
      f = utils_fopen(dot_output, "_state_space.dot");
      Cudd_DumpDot(get_manager(), 1, &state_space, NULL, NULL, f);
      fclose(f);
    }
    Cudd_Ref(state_space);
  }

  return state_space;
}

extern int EF_trace;

void test_cudd_build_state_space()
{
  if (!EF_trace)
    get_state_space(NULL, NULL, NULL);
}

void test_cudd_property(struct ast *t, char *name)
{
  DdNode *ss, *p;
  FILE *f;
  struct precompiled_ast_cudd *precompiled_ast;
  DdNode **steps;
  int steps_sz;
  int *cube;
  double d;

  if (!EF_trace)
    get_state_space(NULL, NULL, NULL);

  normalize(t);
  if (verbosity_level >= 2) {
    printf("= "); ast_print(t);
  }

  precompiled_ast = precompiled_ast_cudd_from_ast(get_manager(), t);

  if (EF_trace)
    ss = get_state_space(precompiled_ast, &steps, &steps_sz);
  else
    ss = get_state_space(NULL, NULL, NULL);
  p = build_cudd_ctl(get_manager(), precompiled_ast, ss);
  Cudd_Ref(p);

  precompiled_ast_cudd_free(get_manager(), precompiled_ast);

  if (p != Cudd_ReadLogicZero(get_manager())) {
    if (EF_trace)
      ef_trace_cudd(get_manager(),
                    steps, steps_sz,
                    p, transition_relation);
    else {
      printf("Some state(s) verify property.\n");
      if (witness) {
        fprintf(stdout, "Witness:\n");
        Cudd_FirstCube(get_manager(), p, &cube, &d); 
        fprintf(stdout, ";; ---\n*State 1: ");
        ef_trace_print_cube(cube);
      }
    }
  } else
    printf("Property is not verified by any state.\n");
    
  if (dot_output) {
    f = utils_fopen(dot_output, "_property.dot");
    Cudd_DumpDot(get_manager(), 1, &p, NULL, NULL, f);
    fclose(f);
  }
  Cudd_RecursiveDeref(get_manager(), p);

  ast_free(t);
}

void test_cudd_quit()
{
  FILE *file;

  if (dot_output) {
    file = utils_fopen(dot_output, "_initial_states.dot");
    Cudd_DumpDot(get_manager(), 1, &initial_states, NULL, NULL, file);
    fclose(file);
  }

  if (!EF_trace)
    get_state_space(NULL, NULL, NULL); 
    
  event_cudd_free(get_manager());
  trans_cudd_free(get_manager());

  if (verbosity_level)
    Cudd_PrintInfo(get_manager(), stdout);

  Cudd_Quit(get_manager());
}

#endif /* HAVE_CUDD */
