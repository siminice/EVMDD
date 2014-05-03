#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <evmdd/evmdd.h>
#include "env.h"
#include "normalize.h"
#include "bfs.h"
#include "test_cudd.h"
#include "build.h"
#include "implicit_identities.h"
#include "cuthill_mckee.h"
#include "ef_trace.h"
#include "clock.h"
#include "utils.h"
/* #include "unique_table.h" */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#define error(format)                                           \
  do {                                                          \
    fprintf(stderr, "Error: "format"\n");                       \
    exit(1);                                                    \
  } while (0)

#define error1(format, arg)                                     \
  do {                                                          \
    fprintf(stderr, "Error: "format"\n", arg);                  \
    exit(1);                                                    \
  } while (0)

extern int yyparse();

static mdd_level_index_t initial_states = 0;
static mdd_level_index_t state_space = 0;
/* evmdd representing minimal distance
 * from any state in set initial_states
 * INT_MAX meaning unreachable */
static evmdd_edge_t evmdd_state_space;

static char *var_names[ENV_SIZE];
static int lower_bounds[ENV_SIZE];
int ranges[ENV_SIZE];
int vorder[ENV_SIZE];
int iorder[ENV_SIZE];
char **dep;
static mdd_manager_t *mdd_manager=NULL;

char *dot_output = NULL;
int nb_printed=0;
int verbosity_level = 1;
char *dump_state_space = NULL;
char *read_state_space = NULL;
char *dump_dist = NULL;
char *read_dist = NULL;
char *read_vorder = NULL;
char *dump_vorder = NULL;
int static_reorder = 0;
/* garbage collection threshold, in Bytes,
 * default value 5GB (resp. 500MB) on 64 (resp. 32) bit machines */
static unsigned long garbage_size = ((sizeof(unsigned long) > 4) ? 5120 : 500)*(unsigned long)1048576;
/* print witness ? */
/* = maximum number of states to be printed */
int witness = 0;
/* wether events having same top level are merged before computing state space */
int merge_by_top_level = 1;
int EF_trace = 0;
/* stop when first solution of an equation is found */
int solutions = 0;
#ifdef HAVE_CUDD
/* wether to test with CUDD (1) or EV+MDDs (0) */
static int test_with_cudd = 0;
#endif
/* wether to use breadth first search (1) or saturation (0) */
int use_bfs = 0;
/* wether we have to compute reachable state space or not */
static int compute_ss = 0;
/* wether we compute distances during saturation */
static int use_saturate_dist = 0;
/* potential bound for saturation with distance (0 means no bound) */
static int saturate_dist_bound = 0;

static clock__t start_init_states=NULL, stop_init_states;
static clock__t start_expressions=NULL, stop_expressions;
static clock__t start_transition_relation=NULL, stop_transition_relation;
static clock__t start_properties=NULL, stop_properties;

static void reorder_vars() {
  int i, l;

  l = env_size();

  if (read_vorder!=NULL) {
    env_read_vorder(read_vorder, vorder);
    env_reorder(vorder);
  }
  else {
    for (i=1; i<=l; i++)
      vorder[i] = i;
  }
  for (i=1; i<=l; i++) {
    iorder[vorder[i]] = i;
  }
}

static void create_dependencies() {
  int i, j, l;

  l = env_size();
  dep = (char**)malloc((l+1)*sizeof(char*));
  for (i=0; i<=l; i++) {
    dep[i] = (char*)malloc((l+1)*sizeof(char));
    for (j=0; j<=l; j++) {
      dep[i][j] = '-';
    }
  }
}

static void print_dependencies() {
  int i, j, l;

  fprintf(stderr, "Dependencies by multiplication/division:\n");
  l = env_size();
  for (i=l; i>=1; i--) {
    fprintf(stderr, "%10s: ", var_names[vorder[i]]);
    for (j=l; j>=1; j--) {
      fprintf(stderr, "%c", dep[vorder[i]][vorder[j]]);
    }
    fprintf(stderr, "\n");
  }
}

static void reset_dependencies() {
  int i, j, l;

  l = env_size();
  for (i=0; i<=l; i++) {
    for (j=0; j<=l; j++) {
      dep[i][j] = 'n';
    }
  }
}

static void build_mdd_manager()
{
  int i, l, lb, ub;
  clock__t start, stop;

  printf("Building mdd_manager...\n");
  start = clock_get();

  l = env_size();

  for (i = 1; i <= l; ++i) {
    var_names[i] = env_name(i, &lb, &ub);
    lower_bounds[i] = lb;
    ranges[i] = ub-lb+1;
    iorder[vorder[i]] = i;
    if (ranges[i] <=0) {
      error1("Illegal variable range for %s", var_names[i]);
    }
  }

  mdd_manager = mdd_manager_new(l, lower_bounds, ranges);
  mdd_manager_set_var_names(mdd_manager, var_names);
  mdd_manager_set_gc_threshold(mdd_manager, garbage_size);

  stop = clock_get();
  printf("mdd_manager_new: "); clock_print(start, stop);

  clock_free(start);
  clock_free(stop);
}

static mdd_manager_t *get_mdd_manager()
{
  if (mdd_manager == NULL)
    build_mdd_manager();

  return mdd_manager;
}

void add_init_states(struct ast *t)
{
  mdd_level_index_t p, oldis;
  int i, l;

  if (t == NULL) return;

  l =  env_size();
  for (i=1; i<=l; i++) vorder[i] = i;
 
#ifdef HAVE_CUDD
  if (!test_with_cudd)
#endif
    get_mdd_manager();

  if (start_init_states == NULL) {
    printf("Building initial state(s)...\n");
    start_init_states = clock_get();
  }

  normalize(t);
  if (verbosity_level >= 2) {
    printf("= "); ast_print(t);
  }

#ifdef HAVE_CUDD
  if (test_with_cudd) {
    test_cudd_add_init_states(t);
    return;
  }
#endif

  clock_global_start();
  p = build_mdd_from_ast(get_mdd_manager(), t);
  clock_global_stop();
  if (verbosity_level >= 2) {
    printf("  Construction of MDD: "); clock_global_print();
    printf("  number of nodes of resulting MDD: %d\n",
           mdd_num_nodes(get_mdd_manager(), p));
    printf("  total number of nodes with intermediate results: %d MDD + %d EV+MDD\n",
           mdd_total_num_nodes(get_mdd_manager()),
           evmdd_total_num_nodes(get_mdd_manager()));
  }

  oldis = initial_states;
  mdd_ref(get_mdd_manager(), p);
  if (oldis) {
    initial_states = mdd_inter(get_mdd_manager(), p, oldis);
    mdd_unref(get_mdd_manager(), p);
    mdd_unref(get_mdd_manager(), oldis);
    mdd_ref(get_mdd_manager(), initial_states);
  } else
    initial_states = p;

/* ----------- 
  printf("Number of initial states: ");
  bigint_print(mdd_num_encoded_elements(get_mdd_manager(), p), stdout);
  printf("\n");
 ----------- */

  ast_free(t);
}

void add_equation(struct ast *t)
{
  mdd_level_index_t p;

#ifdef HAVE_CUDD
  if (!test_with_cudd)
#endif
    get_mdd_manager();

  if (start_expressions == NULL) {
    printf("Building equation expressions...\n");
    start_expressions = clock_get();
  }

  normalize(t);
  if (verbosity_level >= 2) {
    printf("= "); ast_print(t);
  }

#ifdef HAVE_CUDD
  if (test_with_cudd) {
    test_cudd_add_init_states(t);
    return;
  }
#endif

  clock_global_start();
  if (solutions==0) {
    p = build_mdd_from_ast(get_mdd_manager(), t);
  }
  else {
    p = solve_mdd_from_ast(get_mdd_manager(), t);
  }
  clock_global_stop();
  if (verbosity_level >= 2) {
    printf("  Construction of MDD: "); clock_global_print();
    printf("  number of nodes of resulting MDD: %d\n",
           mdd_num_nodes(get_mdd_manager(), p));
    printf("  total number of nodes with intermediate results: %d MDD + %d EV+MDD\n",
           mdd_total_num_nodes(get_mdd_manager()),
           evmdd_total_num_nodes(get_mdd_manager()));
  }


/* ----------- */
  printf("Number of states satisfying expression: ");
  bigint_print(mdd_num_encoded_elements(get_mdd_manager(), p), stdout);
  printf("\n");

  if (witness) {
    fprintf(stdout, "Solutions:\n");
    mdd_print_states(get_mdd_manager(), p, witness);
  }

/* ----------- */

  ast_free(t);
}

void add_event(struct ast *t, char *name)
{
  mdd_level_index_t p;
  clock__t start, stop;
  int *iii;

  if (start_init_states != NULL) {
    stop_init_states = clock_get();
    printf("building initial state(s): "); clock_print(start_init_states, stop_init_states);
    clock_free(start_init_states);
    clock_free(stop_init_states);
    start_init_states = NULL;
  }

  if (t == NULL) return;

  if (start_transition_relation == NULL) {
    printf("Building transition relation...\n");
    start_transition_relation = clock_get();
  }

#ifdef HAVE_CUDD
  if (test_with_cudd) {
    test_cudd_add_event(t);
    return;
  }
#endif

  start = clock_get();

  normalize(t);
  if (verbosity_level >= 2) {
    printf("= "); ast_print(t);
  }

  clock_global_start();

  p = build_mdd_from_ast(get_mdd_manager(), t);
  mdd_ref(get_mdd_manager(), p);

  clock_global_stop();
  if (verbosity_level >= 2) {
    printf("  Construction of MDD: "); clock_global_print();
    printf("  number of nodes of resulting MDD: %d\n",
           mdd_num_nodes(get_mdd_manager(), p));
    printf("  total number of nodes with intermediate results: %d MDD + %d EV+MDD\n",
           mdd_total_num_nodes(get_mdd_manager()),
           evmdd_total_num_nodes(get_mdd_manager()));
  }

  stop = clock_get();
  if (verbosity_level) {
    printf("construction of one transition relation: "); clock_print(start, stop);
  }
  clock_free(start);
  clock_free(stop);

  iii = implicit_identities_indexes(get_mdd_manager(), t);

  start = clock_get();
  event_register_name_merge(get_mdd_manager(), p, iii, name, merge_by_top_level);
  mdd_unref(get_mdd_manager(), p);

  stop = clock_get();
  if (verbosity_level) {
    printf("Registering one transition relation: "); clock_print(start, stop);
  }
  clock_free(start);
  clock_free(stop);

  compute_ss = 1;

  ast_free(t);
}

static mdd_level_index_t get_state_space()
{
  mdd_level_index_t pre_state_space, lt_bound;
  FILE *f;

  if (compute_ss) {
    compute_ss = 0;
    if (!use_saturate_dist && read_state_space) {
      printf("Reading reachable state space from file '%s'...\n", read_state_space);
      clock_global_start();
      f = fopen(read_state_space, "r");
      state_space = mdd_from_file(get_mdd_manager(), f);
      mdd_ref(get_mdd_manager(), state_space);
      fclose(f);
      clock_global_stop();
      printf("State space reading: "); clock_global_print();
    } else {
      printf("Computing reachable state space...\n");
      clock_global_start();
      if (use_bfs == 2)
        state_space = bfs_chaining(get_mdd_manager(), initial_states);
      else if (use_bfs == 3)
        state_space = strict_bfs(get_mdd_manager(), initial_states, saturate_dist_bound-1);
      else if (use_bfs)
        state_space = bfs(get_mdd_manager(), initial_states, saturate_dist_bound-1);
      else if (use_saturate_dist) {
        if (saturate_dist_bound && use_saturate_dist == 1) {
          evmdd_state_space = saturate_bounded(get_mdd_manager(), initial_states,
                                               saturate_dist_bound);
          evmdd_ref(get_mdd_manager(), evmdd_state_space);
        } else {
          if (read_state_space) {
            printf("Reading reachable state space from file '%s'...\n", read_state_space);
            f = fopen(read_state_space, "r");
            pre_state_space = mdd_from_file(get_mdd_manager(), f);
            fclose(f);
            printf("State space read.\n");
          } else {
            printf("Computing reachable state space...\n");
            pre_state_space = saturate(get_mdd_manager(), initial_states);
            printf("State space computed.\n");
          }
          mdd_ref(get_mdd_manager(), pre_state_space);
          if (dump_state_space) {
            f = fopen(dump_state_space, "w");
            mdd_to_file(get_mdd_manager(), pre_state_space, f);
            fclose(f);
          }
          if (read_dist) {
            printf("Reading distance function from file '%s'...\n", read_dist);
            f = fopen(read_dist, "r");
            evmdd_state_space = evmdd_from_file(get_mdd_manager(), f);
            fclose(f);
            printf("Distance function read.\n");
          } else {
            if (saturate_dist_bound) {
              evmdd_state_space = saturate_dist2(get_mdd_manager(), initial_states,
                                                 pre_state_space, saturate_dist_bound);
            } else
              evmdd_state_space = saturate_dist(get_mdd_manager(), initial_states,
                                                pre_state_space);
          }
          evmdd_ref(get_mdd_manager(), evmdd_state_space);
          mdd_unref(get_mdd_manager(), pre_state_space);
        }
        if (dump_dist) {
          f = fopen(dump_state_space, "w");
          evmdd_to_file(get_mdd_manager(), evmdd_state_space, f);
          fclose(f);
        }
      } else {
        state_space = saturate(get_mdd_manager(), initial_states);
        mdd_ref(get_mdd_manager(), state_space);
      }
      clock_global_stop();
      printf("State space computation: "); clock_global_print();
    }
    printf("Number of reachable states: ");
    if (use_saturate_dist) {
      bigint_print(evmdd_num_encoded_elements(get_mdd_manager(), evmdd_state_space), stdout);
      if (use_saturate_dist == 2) {
        lt_bound = evmdd_lt_scalar(get_mdd_manager(), evmdd_state_space, saturate_dist_bound);
        mdd_ref(get_mdd_manager(), lt_bound);
        printf(" (< %d: ", saturate_dist_bound);
        bigint_print(mdd_num_encoded_elements(get_mdd_manager(), lt_bound), stdout);
        printf(")");
        if (dot_output) {
          f = utils_fopen(dot_output, "_lt_bound.dot");
          mdd_print_dot(get_mdd_manager(), lt_bound, f);
          fclose(f);
        }
        mdd_unref(get_mdd_manager(), lt_bound);
      }
    } else
      bigint_print(mdd_num_encoded_elements(get_mdd_manager(), state_space), stdout);
    printf("\n");
    if (verbosity_level >= 2) {
      if (use_saturate_dist)
        printf("  number of nodes of resulting EVMDD: %d\n",
               evmdd_num_nodes(get_mdd_manager(), evmdd_state_space));
      else
        printf("  number of nodes of resulting MDD: %d\n",
               mdd_num_nodes(get_mdd_manager(), state_space));
    }
    if (dot_output) {
      f = utils_fopen(dot_output, "_state_space.dot");
      if (use_saturate_dist)
        evmdd_print_dot(get_mdd_manager(), evmdd_state_space, f);
      else
        mdd_print_dot(get_mdd_manager(), state_space, f);
      fclose(f);
    }
    if (!use_saturate_dist && dump_state_space) {
      f = fopen(dump_state_space, "w");
      mdd_to_file(get_mdd_manager(), state_space, f);
      fclose(f);
    }
  }

  return use_saturate_dist ? evmdd_state_space.node : state_space;
}

void check_property(struct ast *t, char *name)
{
  mdd_level_index_t p;
  FILE *f;

  if (start_transition_relation != NULL) {
    stop_transition_relation = clock_get();
    printf("building transition relation: "); clock_print(start_transition_relation, stop_transition_relation);
    clock_free(start_transition_relation);
    clock_free(stop_transition_relation);
    start_transition_relation = NULL;
  }

  if (t == NULL) return;

#ifdef HAVE_CUDD
  if (test_with_cudd)
    test_cudd_build_state_space();
  else
#endif
    get_state_space();

  if (start_properties == NULL) {
    printf("Building properties...\n");
    start_properties = clock_get();
  }

#ifdef HAVE_CUDD
  if (test_with_cudd) {
    test_cudd_property(t, name);
    return;
  }
#endif

  get_state_space();

  normalize(t);
  if (verbosity_level >= 2) {
    printf("= "); ast_print(t);
  }

  if (!state_space) {
    if(use_saturate_dist) {
      get_state_space();
      state_space = evmdd_lt_scalar(get_mdd_manager(), evmdd_state_space, INT_MAX);
      mdd_ref(get_mdd_manager(), state_space);
    } else {
      state_space = get_state_space();
    }
  }

  p = build_ctl(get_mdd_manager(), t, state_space);
  mdd_ref(get_mdd_manager(), p);
  printf("Number of states satisfying property %s: ", (name!=NULL?name:""));
  bigint_print(mdd_num_encoded_elements(get_mdd_manager(), p), stdout);
  printf("\n");

  if (witness) {
    fprintf(stdout, "Witness:\n");
    mdd_print_states(get_mdd_manager(), p, witness);
  }

  if (EF_trace)
    ef_trace(get_mdd_manager(), evmdd_state_space, p);
  
  if (dot_output) {
    f = utils_fopen(dot_output, "_property.dot");
    mdd_print_dot(get_mdd_manager(), p, f);
    fclose(f);
  }

  mdd_unref(get_mdd_manager(), p);
}

int build_model() {
  int i, lb, ub;
  int n_var, n_def, n_init, n_ev, n_eq;
  struct ast *t;

  n_var = env_size();
  n_def = mdf_size();
  n_init = num_inits();
  n_ev = num_events();
  n_eq = num_equations();

  reorder_vars();

  for (i = 1; i <= n_var; ++i) {
    var_names[i] = env_name(i, &lb, &ub);
    lower_bounds[i] = lb;
    ranges[i] = ub-lb+1;
    if (ranges[i] <=0) {
      error1("Illegal variable range for %s", var_names[i]);
    }
  }

  create_dependencies();

  if (n_eq>0 && static_reorder) {
    t = (struct ast*) equation_get_body(1);
    ast_mult_dependencies(t, dep);
    reverse_cuthill_mckee(env_size(), dep, vorder);
    env_reorder(vorder);
    print_dependencies();
  }

  for (i = 1; i <= n_var; ++i) {
    var_names[i] = env_name(i, &lb, &ub);
    lower_bounds[i] = lb;
    ranges[i] = ub-lb+1;
    iorder[vorder[i]] = i;
    if (ranges[i] <=0) {
      error1("Illegal variable range for %s", var_names[i]);
    }
  }

  for (i=1; i<=n_def; i++) {
    t = (struct ast*) mdf_get_body(i);
    normalize(t);
    /* ... do macro substitutions ? ... */
  }

  for (i=1; i<=n_init; i++) {
    t = (struct ast*) init_get_body(i);
    add_init_states(t);
  }

  for (i=1; i<=n_ev; i++) {
    t = (struct ast*) event_get_body(i);
    add_event(t, event_get_name(i));
  }

  for (i=1; i<=n_eq; i++) {
    t = (struct ast*) equation_get_body(i);
    add_equation(t);
  }

  return 0;
}

static void print_usage(char *prog_name)
{
  printf("Usage: %s [OPTION]...\n", prog_name);
  printf("Read model on standard input.\n");
  printf("\n");
  printf("--merge-events                   merge events with same top affected variable (default)\n");
  printf("--split-events                   don't merge events with same top affected variable\n");
  printf("--witness[=<n>]                  print up to <n> witness states satisfying property\n");
  printf("--solutions[=<n>]                stop after finding <n> solutions for an equation\n");
  printf("--gc <n>                         set garbage collection threshold (in bytes, default %lu)\n", garbage_size);
  printf("--dist                           use saturation to compute minimal distances from initial state\n");
  printf("--bound <n>                      bound for saturation with EVMDD, consider only states at distance\n");
  printf("                                 strictly less than <n> (0 means no bound (default)), implies '--dist'\n");
  printf("--bound2 <n>                     same as bound with another algorithm\n");
  printf("--bfs                            use BFS instead of saturation\n");
  printf("--strict-bfs                     use strict BFS, (only next frontier is computed) instead of saturation\n");
  printf("--chaining                       use BFS with chaining\n");
  printf("--cudd                           use CUDD (BFS)\n");
  printf("--trace                          find shortest trace to a state satisfying property\n");
  printf("                                 requires '--cudd' (currently buggy, avoid it) or '--dist'\n");
  printf("--dump-vorder <file>             dump variable order in <file>\n");
  printf("--read-vorder <file>             read variable order from <file>\n");
  printf("--static-reorder           -s    use static variable reordering (reverse Cuthill-McKee algorithm)\n");
  printf("--dot <file.dot>                 output diagrams in dot format (graphviz)\n");
  printf("--dump-state-space <file>        dump state space in <file>\n");
  printf("--read-state-space <file>        read state space from <file>\n");
 
  printf("--dump-dist <file>               dump distance function in <file> (requires '--dist')\n");
  printf("--read-dist <file>               read distance function from <file> (requires '--dist')\n");
  printf("--quiet                    -q    do not output all messages\n");
  printf("--verbose                  -v    output many messages\n");
  printf("--very-verbose             -vv   output tons of messages\n");
  printf("--help                     -h    help message\n");
}

int main(int argc, char *argv[])
{
  int i;
  FILE *f;
  char *ov;

  for (i = 1; i < argc; ++i) {
    if (strcmp(argv[i], "--help") == 0 ||
        strcmp(argv[i], "-h") == 0) {
      print_usage(argv[0]);
      return 0;
    } else if (strcmp(argv[i], "--bfs") == 0)
      use_bfs = 1;
    else if (strcmp(argv[i], "--strict-bfs") == 0)
      use_bfs = 3;
#ifdef HAVE_CUDD
    else if (strcmp(argv[i], "--cudd") == 0)
      test_with_cudd = 1;
#endif
    else if (strcmp(argv[i], "--trace") == 0)
      EF_trace = 1;
    else if (strcmp(argv[i], "--dist") == 0)
      use_saturate_dist = 1;
    else if (strcmp(argv[i], "--bound") == 0) {
      if (++i < argc) {
        saturate_dist_bound = atoi(argv[i]);
        if (saturate_dist_bound < 0)
          error1("Illegal bound %d.", saturate_dist_bound);
      }
      if (!use_bfs) use_saturate_dist = 1;
    }
    else if (strcmp(argv[i], "--bound2") == 0) {
      if (++i < argc) {
        saturate_dist_bound = atoi(argv[i]);
        if (saturate_dist_bound < 0)
          error1("Illegal bound %d.", saturate_dist_bound);
      }
      use_saturate_dist = 2;
    }
    else if (strcmp(argv[i], "--chaining") == 0)
      use_bfs = 2;
    else if (strcmp(argv[i], "--merge-events") == 0)
      merge_by_top_level = 1;
    else if (strcmp(argv[i], "--split-events") == 0)
      merge_by_top_level = 0;
    else if (strcmp(argv[i], "--gc") == 0) {
      if (++i < argc) {
        garbage_size = strtoul(argv[i], NULL, 10);
        if (garbage_size <= 0)
          error1("Illegal garbage collection size %ld.", garbage_size);
      }
      fprintf(stderr, "Garbage collection memory limit = %ld bytes.\n", garbage_size);
    }
    else if (strstr(argv[i], "--witness") == argv[i]) {
      ov = strstr(argv[i], "=");
      if (ov) {
        witness = atoi(ov+1);
        if (witness < 0)
          error1("Illegal witness size %d.", witness);
      }
      else witness = 100;	/* some default value */
    }
    else if (strstr(argv[i], "--solutions") == argv[i]) {
      ov = strstr(argv[i], "=");
      if (ov) {
        solutions = atoi(ov+1);
        if (solutions < 0)
          error1("Illegal number of solutions %d.", solutions);
      }
      else solutions = 0;	/* by default find all solutions */
    }
    else if (i+1 < argc && strcmp(argv[i], "--dot") == 0) {
      ++i;
      if (strlen(argv[i]) > strlen(".dot") &&
          strcmp(argv[i]+strlen(argv[i])-strlen(".dot"), ".dot") == 0)
        argv[i][strlen(argv[i])-strlen(".dot")] = '\0';
      dot_output = argv[i];
    } else if (i+1 < argc && strcmp(argv[i], "--dump-state-space") == 0) {
      ++i;
      dump_state_space = argv[i];
    } else if (i+1 < argc && strcmp(argv[i], "--read-state-space") == 0) {
      ++i;
      read_state_space = argv[i];
    } else if (i+1 < argc && strcmp(argv[i], "--dump-dist") == 0) {
      ++i;
      dump_dist = argv[i];
    } else if (i+1 < argc && strcmp(argv[i], "--read-dist") == 0) {
      ++i;
      read_dist = argv[i];
    } else if (strcmp(argv[i], "--static-reorder") == 0 ||
               strcmp(argv[i], "-s")==0) {
      static_reorder = 1;
    } else if (i+1 < argc && strcmp(argv[i], "--dump-vorder") == 0) {
      ++i;
      dump_vorder = argv[i];
    } else if (i+1 < argc && strcmp(argv[i], "--read-vorder") == 0) {
      ++i;
      read_vorder = argv[i];
    } else if (strcmp(argv[i], "--quiet") == 0 ||
              strcmp(argv[i], "-q") == 0)
      verbosity_level = 0;
    else if (strcmp(argv[i], "--verbose") == 0 ||
             strcmp(argv[i], "-v") == 0)
      verbosity_level = 2;
    else if (strcmp(argv[i], "--very-verbose") == 0 ||
             strcmp(argv[i], "-vv") == 0)
      verbosity_level = 3;
    else
      error1("Unknown option %s, ignoring!", argv[i]);
  }
  if (use_bfs && use_saturate_dist)
    error("'--dist' of no effect with BFS");
#ifdef HAVE_CUDD
  if (test_with_cudd && use_saturate_dist)
    error("'--dist' of no effect with '--cudd'");
  if (test_with_cudd && use_bfs == 1)
    error("'--bfs' of no effect with '--cudd'");
  if (!test_with_cudd && !use_saturate_dist && EF_trace)
    error("'--trace' of no effect without '--cudd' or '--dist'");
  if (EF_trace && use_bfs == 2)
    error("'--trace' of no effect with '--chaining'");
  if (test_with_cudd && !merge_by_top_level)
    error("'--split-events' of no effect with '--cudd'");
  if (test_with_cudd && dump_state_space)
    error("'--dump-state-space' of no effect with '--cudd'");
  if (test_with_cudd && read_state_space)
    error("'--read-state-space' of no effect with '--cudd'");
  if (test_with_cudd && dump_dist)
    error("'--dump-dist' of no effect with '--cudd'");
  if (test_with_cudd && read_dist)
    error("'--read-dist' of no effect with '--cudd'");
#else
  if (!use_saturate_dist && EF_trace)
    error("'--trace' of no effect without '--dist'");
#endif
  if (!use_saturate_dist && dump_dist)
    error("'--dump-dist' of no effect without '--dist'");
  if (!use_saturate_dist && read_dist)
    error("'--read-dist' of no effect without '--dist'");

  yyparse();

  build_model();

  if (start_init_states != NULL) {
    stop_init_states = clock_get();
    printf("building initial state(s): "); clock_print(start_init_states, stop_init_states);
    clock_free(start_init_states);
    clock_free(stop_init_states);
  }

  if (start_expressions != NULL) {
    stop_expressions = clock_get();
    printf("building expression(s): "); clock_print(start_expressions, stop_expressions);
    clock_free(start_expressions);
    clock_free(stop_expressions);
  }

  if (start_transition_relation != NULL) {
    stop_transition_relation = clock_get();
    printf("building transition relation: "); clock_print(start_transition_relation, stop_transition_relation);
    clock_free(start_transition_relation);
    clock_free(stop_transition_relation);
  }

  if (start_properties != NULL) {
    stop_properties = clock_get();
    printf("building properties: "); clock_print(start_properties, stop_properties);
    clock_free(start_properties);
    clock_free(stop_properties);
  }

#ifdef HAVE_CUDD
  if (!test_with_cudd) {
#endif
    if (dot_output) {
      f = utils_fopen(dot_output, "_initial_states.dot");
      mdd_print_dot(get_mdd_manager(), initial_states, f);
      fclose(f);
    }
    
    get_state_space();

    if (verbosity_level > 0) {
/*       printf("Total memory allocated: %lu bytes.\n", get_mdd_manager()->currently_allocated); */
    
/*       for (i = 1; i <= 2*get_mdd_manager()->nb_levels; ++i) */
/*         unique_table_mdd_stats(get_mdd_manager(), i); */
    }

    if (mdd_manager != NULL) {
      printf("Releasing mdd_manager...\n");
      if (verbosity_level >=2) {
        current_statistics(mdd_manager);
        final_statistics(mdd_manager);
        clock_global_start();
      }
      mdd_manager_free(mdd_manager);
      if (verbosity_level >=1) {
        clock_global_stop();
        printf("mdd_manager_free: "); clock_global_print();
      }
    }
#ifdef HAVE_CUDD
  } else
    test_cudd_quit();
#endif

  env_free();
  mdf_free();

  return 0;
}
