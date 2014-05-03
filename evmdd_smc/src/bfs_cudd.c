#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_CUDD

#include "bfs_cudd.h"
#include "event_cudd.h"
#include "trans_cudd.h"

#include "build_cudd.h"

extern int verbosity_level;

DdNode *bfs_cudd_chaining(DdManager *manager, DdNode *s)
{
  DdNode *r=s, *prevr, *oldr;
  DdNode *e;  /* event */
  int i, l=event_cudd_size();
  int nb_iterations=0;

  do {
    oldr = r;
    for (i = 1; i <= l; ++i) {
      e = event_cudd_bdd(i);
      prevr = r;
      Cudd_Ref(prevr);
      r = trans_cudd_add_next(manager, prevr, e);
      Cudd_Ref(r);
      Cudd_RecursiveDeref(manager, prevr);
      Cudd_Deref(r);
    }
    ++nb_iterations;
    if (verbosity_level > 0) {
      fprintf(stderr, "CUDD BFS iteration #%d.\n", nb_iterations);
    }
  } while (r != oldr);

  fprintf(stderr, "%s/%d: BFS (with chaining): %d iterations\n", __FILE__, __LINE__, nb_iterations);

  return r;
}

DdNode *bfs_cudd(DdManager *manager, DdNode *s, DdNode *f)
{
  DdNode *r=Cudd_ReadLogicZero(manager), *oldr, *next, *frontier=s, *oldfrontier;
  int nb_iterations=0;

  do {
    oldr = r;
    Cudd_Ref(oldr);
    oldfrontier = frontier;
    Cudd_Ref(oldfrontier);
    next = trans_cudd_next(manager, oldfrontier, f);
    Cudd_Ref(next);
    frontier = Cudd_bddAnd(manager, Cudd_Not(oldr), next);
    Cudd_Ref(frontier);
    Cudd_RecursiveDeref(manager, next);
    r = Cudd_bddOr(manager, oldr, frontier);
    Cudd_Ref(r);
    Cudd_RecursiveDeref(manager, oldr);
    Cudd_RecursiveDeref(manager, oldfrontier);
    Cudd_Deref(r);
    Cudd_Deref(frontier);
    ++nb_iterations;
    if (verbosity_level > 0) {
      fprintf(stderr, "CUDD BFS iteration #%d.\n", nb_iterations);
    }
  } while (r != oldr);

  Cudd_RecursiveDeref(manager, frontier);

  fprintf(stderr, "%s/%d: BFS: %d iterations\n", __FILE__, __LINE__, nb_iterations);

  return r;
}

DdNode *bfs_cudd_prepare_trace(DdManager *manager, DdNode *s, DdNode *f, struct precompiled_ast_cudd *stop_property, DdNode ***steps, int *steps_sz)
{
  DdNode *r=Cudd_ReadLogicZero(manager), *oldr, *next, *frontier=s, *oldfrontier;
  int nb_iterations=0;

  *steps = malloc(sizeof(DdNode*));
  *steps_sz = 1;
  *steps[0] = s;

  do {
    oldr = r;
    oldfrontier = frontier;
    Cudd_Ref(oldfrontier);
    next = trans_cudd_next(manager, oldfrontier, f);
    Cudd_Ref(next);
    frontier = Cudd_bddAnd(manager, Cudd_Not(oldr), next);
    Cudd_Ref(frontier);
    Cudd_RecursiveDeref(manager, next);
    r = Cudd_bddOr(manager, oldr, frontier);
    Cudd_Ref(r);
    Cudd_RecursiveDeref(manager, oldfrontier);
    ++(*steps_sz);
    *steps = realloc(*steps, *steps_sz*sizeof(DdNode*));
    (*steps)[*steps_sz-1] = r;
    ++nb_iterations;
    if (verbosity_level > 0) {
      fprintf(stderr, "CUDD BFS iteration #%d.\n", nb_iterations);
    }
    if (build_cudd_ctl(manager, stop_property, r) != Cudd_ReadLogicZero(manager)) {
      printf("Some state(s) verify property, no further iterating.\n");
      Cudd_Deref(frontier);
      break;
    }
    Cudd_Deref(frontier);
  } while (r != oldr);

  Cudd_RecursiveDeref(manager, frontier);

  fprintf(stderr, "%s/%d: BFS: %d iterations (may have stopped before actually reaching fixpoint)\n", __FILE__, __LINE__, nb_iterations);

  return r;
}

#endif /* HAVE_CUDD */
