#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_CUDD

#include <stdlib.h>
#include "trans_cudd.h"
#include "env.h"
#include "build_cudd.h"

static DdNode *identity=0;
static DdNode *cube_from;
static DdNode *cube_to;

void trans_cudd_init(DdManager *manager)
{
  int i, l = env_size();
  int lb, ub, tmp, nb_bin_vars;
  int *cube_tmp_array;

  if (!identity) {
    l = env_size();
    nb_bin_vars = 0;
    for (i = l; i; --i) {
      env_name(i, &lb, &ub);
      tmp = ub-lb;
      while (tmp) {
        tmp >>= 1;
        nb_bin_vars += 2;
      }
    }

    cube_tmp_array = malloc(nb_bin_vars/2*sizeof(int));  

    for (i = 0; i < nb_bin_vars/2; ++i)
      cube_tmp_array[i] = 2*i;
    cube_from = Cudd_IndicesToCube(manager, cube_tmp_array, nb_bin_vars/2);
    Cudd_Ref(cube_from);

    for (i = 0; i < nb_bin_vars/2; ++i)
      cube_tmp_array[i] = 2*i+1;
    cube_to = Cudd_IndicesToCube(manager, cube_tmp_array, nb_bin_vars/2);
    Cudd_Ref(cube_to);

    free(cube_tmp_array);

    identity = build_cudd_identities(manager, NULL, nb_bin_vars);
    Cudd_Ref(identity);
  }
}

void trans_cudd_free(DdManager *manager)
{
  if (identity) {
    Cudd_RecursiveDeref(manager, cube_from);
    Cudd_RecursiveDeref(manager, cube_to);
    Cudd_RecursiveDeref(manager, identity);
  }
}

DdNode *trans_cudd_next(DdManager *manager, DdNode *s, DdNode *f)
{
  DdNode *r, *shiftedr;

  shiftedr = Cudd_bddAndAbstract(manager, s, f, cube_from);
  Cudd_Ref(shiftedr);
  r = Cudd_bddAndAbstract(manager, shiftedr, identity, cube_to);
  Cudd_Ref(r);
  Cudd_RecursiveDeref(manager, shiftedr);
  Cudd_Deref(r);

  return r;
}

DdNode *trans_cudd_add_next(DdManager *manager, DdNode *s, DdNode *f)
{
  DdNode *r, *shifted_next, *unshifted_next;

  shifted_next = Cudd_bddAndAbstract(manager, s, f, cube_from);
  Cudd_Ref(shifted_next);
  unshifted_next = Cudd_bddAndAbstract(manager, shifted_next, identity, cube_to);
  Cudd_Ref(unshifted_next);
  Cudd_RecursiveDeref(manager, shifted_next);
  r = Cudd_bddOr(manager, s, unshifted_next);
  Cudd_Ref(r);
  Cudd_RecursiveDeref(manager, unshifted_next);
  Cudd_Deref(r);

  return r;
}

DdNode *trans_cudd_prev(DdManager *manager, DdNode *s, DdNode *f)
{
  DdNode *r, *shifteds;

  shifteds = Cudd_bddAndAbstract(manager, s, identity, cube_from);
  Cudd_Ref(shifteds);
  r = Cudd_bddAndAbstract(manager, shifteds, f, cube_to);
  Cudd_Ref(r);
  Cudd_RecursiveDeref(manager, shifteds);
  Cudd_Deref(r);

  return r;
}

DdNode *trans_cudd_add_prev(DdManager *manager, DdNode *s, DdNode *f)
{
  DdNode *r, *shifteds, *prev;

  shifteds = Cudd_bddAndAbstract(manager, s, identity, cube_from);
  Cudd_Ref(shifteds);
  prev = Cudd_bddAndAbstract(manager, shifteds, f, cube_to);
  Cudd_Ref(prev);
  Cudd_RecursiveDeref(manager, shifteds);
  r = Cudd_bddOr(manager, s, prev);
  Cudd_Ref(r);
  Cudd_RecursiveDeref(manager, prev);
  Cudd_Deref(r);

  return r;
}

#endif /* HAVE_CUDD */
