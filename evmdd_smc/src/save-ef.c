#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_CUDD

#include "ef_trace_cudd.h"
#include "env.h"
#include "trans_cudd.h"

extern int cudd_var_bits[];

static void print_cube(int *cube)
{
  int i, j;
  int l=env_size();
  int tmp;
  char *name;
  int lb;

/****
A cube is represented as an array of literals, which are integers in {0, 1, 2}; 
0 represents a complemented literal, 
1 represents an uncomplemented literal, 
and 2 stands for don't care.
****/

  for (i = 1; i <= l; ++i) {
    tmp = 0;
    for (j = cudd_var_bits[i]; j < cudd_var_bits[i-1]; j+=2)
      tmp = (tmp << 1)+(cube[j] > 0);
    name = env_name(i, &lb, NULL);
    tmp += lb;
    printf("%s = %d%s", name, tmp, i < l ? ", " : "\n");
  }
}

void ef_trace_cudd(DdManager *manager, DdNode **steps, int steps_sz,
                   DdNode *goal, DdNode *transition_relation)
{
  int *cube;
  double d;
  int i;
  DdNode *oldr, *r=goal, *prev;

  printf("EF trace (first is a nearest state satisfying property, then a trace backward to an initial state):\n");

  Cudd_Ref(r);

  for (i = steps_sz-1; i; --i) {
    oldr = r;

    /* extract a state s and print it */
    Cudd_FirstCube(manager, oldr, &cube, &d);
    Cudd_RecursiveDeref(manager, oldr);
    printf("distance %d:\n", i);
    print_cube(cube);
    oldr = Cudd_CubeArrayToBdd(manager, cube);
    Cudd_Ref(oldr);
    free(cube);

    /* compute predecessors of s at distance i-1 from initial states */
    prev = trans_cudd_prev(manager, oldr, transition_relation);
    Cudd_Ref(prev);
    Cudd_RecursiveDeref(manager, oldr);
    r = Cudd_bddAnd(manager, prev, steps[i-1]);
    Cudd_Ref(r);
    Cudd_RecursiveDeref(manager, prev);
  }

  /* extract an initial state s and print it */
  Cudd_FirstCube(manager, r, &cube, &d);
  Cudd_RecursiveDeref(manager, r);
  printf("distance 0 (initial state):\n");
  print_cube(cube);
  free(cube);
}

#endif /* HAVE_CUDD */
