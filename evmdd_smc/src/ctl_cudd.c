#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_CUDD

#include "ctl_cudd.h"
#include "event_cudd.h"
#include "trans_cudd.h"

DdNode *ctl_cudd_EX(DdManager *manager, DdNode *s)
{
  DdNode *r=Cudd_ReadLogicZero(manager), *prevr, *tmp;
  int i, l=event_cudd_size();
  DdNode *e;  /* event */
  
  for (i = 1; i <= l; ++i) {
    e = event_cudd_bdd(i);
    prevr = r;
    Cudd_Ref(prevr);
    tmp = trans_cudd_prev(manager, s, e);
    Cudd_Ref(tmp);
    r = Cudd_bddOr(manager, prevr, tmp);
    Cudd_Ref(r);
    Cudd_RecursiveDeref(manager, prevr);
    Cudd_RecursiveDeref(manager, tmp);
    Cudd_Deref(r);
  }

  return r;
}

DdNode *ctl_cudd_EG(DdManager *manager, DdNode *s)
{
  DdNode *r=s, *oldr, *tmp;
  int nb_iterations=0;

  do {
    oldr = r;
    Cudd_Ref(oldr);
    tmp = ctl_cudd_EX(manager, oldr);
    Cudd_Ref(tmp);
    Cudd_RecursiveDeref(manager, oldr);
    r = Cudd_bddAnd(manager, tmp, s);
    Cudd_Ref(r);
    Cudd_RecursiveDeref(manager, tmp);
    Cudd_Deref(r);
    ++nb_iterations;
  } while (r != oldr);  

  fprintf(stderr, "%s/%d: ctl_EG: %d iterations\n", __FILE__, __LINE__, nb_iterations);

  return r;
}

DdNode *ctl_cudd_EU(DdManager *manager, DdNode *s1, DdNode *s2)
{
  DdNode *r=s2, *oldr, *prevr, *tmp;
  int i, l=event_cudd_size();
  DdNode *e;  /* event */
  int nb_iterations=0;
  DdNode *s1Us2 = Cudd_bddOr(manager, s1, s2);

  Cudd_Ref(s1Us2);
  do {
    oldr = r;
    /* computing tmp = add_prev(oldr) */
    Cudd_Ref(oldr);
    for (i = 1; i <= l; ++i) {
      e = event_cudd_bdd(i);
      prevr = r;
      tmp = trans_cudd_add_prev(manager, oldr, e);
      Cudd_Ref(tmp);
      r = Cudd_bddOr(manager, prevr, tmp);
      Cudd_Ref(r);
      Cudd_RecursiveDeref(manager, prevr);
      Cudd_RecursiveDeref(manager, tmp);
    }
    Cudd_RecursiveDeref(manager, oldr);
    tmp = r;  /* tmp = add_prev(oldr) */
    r = Cudd_bddAnd(manager, tmp, s1Us2);
    Cudd_Ref(r);
    Cudd_RecursiveDeref(manager, tmp);
    Cudd_Deref(r);
    ++nb_iterations;
  } while (r != oldr);  
  Cudd_RecursiveDeref(manager, s1Us2);

  fprintf(stderr, "%s/%d: ctl_EU: %d iterations\n", __FILE__, __LINE__, nb_iterations);

  return r;
}

#endif /* HAVE_CUDD */
