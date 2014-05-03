#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_CUDD

#include <limits.h>
#include "build_cudd.h"
#include "ctl_cudd.h"
#include "env.h"
#include "clock.h"
#include "utils.h"

extern int cudd_var_bits[];
extern int verbosity_level;

static DdNode *build_cudd_var_new_rec(DdManager *manager, int bit_id, int lb, int ub, int power)
{
  DdNode *n, *l, *r;
  DdNode *var;
  int i;

  if (lb == ub)
    return Cudd_addConst(manager, utils_power(lb, power));

  for (i = 2; i < ub-lb+1; i <<= 1);
  i >>= 1;

  l = build_cudd_var_new_rec(manager, bit_id+2, lb, lb+i-1, power);
  Cudd_Ref(l);
  r = build_cudd_var_new_rec(manager, bit_id+2, lb+i, ub, power);
  Cudd_Ref(r);
  var = Cudd_addIthVar(manager, bit_id);
  Cudd_Ref(var);
  n = Cudd_addIte(manager, var, r, l);
  Cudd_Ref(n);
  Cudd_RecursiveDeref(manager, var);
  Cudd_RecursiveDeref(manager, l);
  Cudd_RecursiveDeref(manager, r);
  Cudd_Deref(n);

  return n;
}

static DdNode *build_cudd_var_new(DdManager *manager, int var_id, int lb, int ub, int power)
{
  return build_cudd_var_new_rec(manager, cudd_var_bits[var_id >> 1]+(var_id & 1), lb, ub, power);
}

DdNode *build_cudd_add_from_ast(DdManager *manager, struct ast *t)
{
  int lb, ub;
  DdNode *n = NULL, *l, *r, *tmp;
  
  switch (t->node_type) {
  case AST_VAR:
    env_name(t->node_content.var_id >> 1, &lb, &ub);
    return build_cudd_var_new(manager, t->node_content.var_id, lb, ub, 1);
  case AST_CONST:
    return Cudd_addConst(manager, t->node_content.constant);
  case AST_VPOWC:
    env_name(t->node_content.node->l->node_content.var_id >> 1, &lb, &ub);
    return build_cudd_var_new(manager, t->node_content.node->l->node_content.var_id, lb, ub,
                              t->node_content.node->r->node_content.constant);
  case AST_ADD:
  case AST_ADDC:
    l = build_cudd_add_from_ast(manager, t->node_content.node->l);
    Cudd_Ref(l);
    r = build_cudd_add_from_ast(manager, t->node_content.node->r);
    Cudd_Ref(r);
    n = Cudd_addApply(manager, Cudd_addPlus, l, r);
    Cudd_Ref(n);
    Cudd_RecursiveDeref(manager, l);
    Cudd_RecursiveDeref(manager, r);
    Cudd_Deref(n);
    return n;
  case AST_MUL:
  case AST_MULC:
    l = build_cudd_add_from_ast(manager, t->node_content.node->l);
    Cudd_Ref(l);
    r = build_cudd_add_from_ast(manager, t->node_content.node->r);
    Cudd_Ref(r);
    n = Cudd_addApply(manager, Cudd_addTimes, l, r);
    Cudd_Ref(n);
    Cudd_RecursiveDeref(manager, l);
    Cudd_RecursiveDeref(manager, r);
    Cudd_Deref(n);
    return n;
  case AST_DIV:
  case AST_DIVC:
    l = build_cudd_add_from_ast(manager, t->node_content.node->l);
    Cudd_Ref(l);
    r = build_cudd_add_from_ast(manager, t->node_content.node->r);
    Cudd_Ref(r);
    n = Cudd_addApply(manager, Cudd_addDivide, l, r);
    Cudd_Ref(n);
    Cudd_RecursiveDeref(manager, l);
    Cudd_RecursiveDeref(manager, r);
    Cudd_Deref(n);
    return n;
  case AST_MOD:
  case AST_MODC:
    l = build_cudd_add_from_ast(manager, t->node_content.node->l);
    Cudd_Ref(l);
    r = build_cudd_add_from_ast(manager, t->node_content.node->r);
    Cudd_Ref(r);
    n = Cudd_addApply(manager, Cudd_addDivide, l, r);
    Cudd_Ref(n);
    tmp = Cudd_addApply(manager, Cudd_addTimes, n, r);
    Cudd_Ref(tmp);
    Cudd_RecursiveDeref(manager, r);
    Cudd_RecursiveDeref(manager, n);
    n = Cudd_addApply(manager, Cudd_addMinus, l, tmp);
    Cudd_Ref(n);
    Cudd_RecursiveDeref(manager, l);
    Cudd_RecursiveDeref(manager, tmp);
    Cudd_Deref(n);
    return n;
  case AST_POW:
  case AST_LT:
  case AST_EQ:
  case AST_SUB:
  case AST_NOT:
  case AST_OR:
  case AST_AND:
  case AST_EX:
  case AST_EG:
  case AST_EU:
    assert(0);  /* must be called on the result of normalize (see normalize.h) */
    return n;
  };

  return n;
}

DdNode *build_cudd_bdd_from_ast(DdManager *manager, struct ast *t)
{
  DdNode *n = NULL, *l, *r;
  
  switch (t->node_type) {
  case AST_LT:
    l = build_cudd_add_from_ast(manager, t->node_content.node->l);
    clock_global_stop();
    if (verbosity_level >= 2) {
      printf("  Construction of ADD: "); clock_global_print();
      printf("  number of nodes of resulting ADD: %d\n", Cudd_DagSize(l));
    }
    clock_global_start();
    Cudd_Ref(l);
    n = Cudd_addBddInterval(manager, l, INT_MIN, t->node_content.node->r->node_content.constant-1);
    Cudd_Ref(n);
    Cudd_RecursiveDeref(manager, l);
    Cudd_Deref(n);
    return n;
  case AST_EQ:
    l = build_cudd_add_from_ast(manager, t->node_content.node->l);
    clock_global_stop();
    if (verbosity_level >= 2) {
      printf("  Construction of ADD: "); clock_global_print();
      printf("  number of nodes of resulting ADD: %d\n", Cudd_DagSize(l));
    }
    clock_global_start();
    Cudd_Ref(l);
    n = Cudd_addBddInterval(manager, l,
                            t->node_content.node->r->node_content.constant,
                            t->node_content.node->r->node_content.constant);
    Cudd_Ref(n);
    Cudd_RecursiveDeref(manager, l);
#ifdef USE_ADD
    r = n;
    n = Cudd_BddToAdd(manager, r);
    Cudd_Ref(n);
    Cudd_RecursiveDeref(manager, r);
#endif
    Cudd_Deref(n);
    return n;
  case AST_NOT:
    l = build_cudd_bdd_from_ast(manager, t->node_content.child);
    Cudd_Ref(l);
    n = Cudd_Not(l);
    Cudd_Ref(n);
    Cudd_RecursiveDeref(manager, l);
    Cudd_Deref(n);
    return n;
  case AST_OR:
    l = build_cudd_bdd_from_ast(manager, t->node_content.node->l);
    Cudd_Ref(l);
    r = build_cudd_bdd_from_ast(manager, t->node_content.node->r);
    Cudd_Ref(r);
#ifdef USE_ADD
    n = Cudd_addApply(manager, Cudd_addOr, l, r);
#else
    n = Cudd_bddOr(manager, l, r);
#endif
    Cudd_Ref(n);
    Cudd_RecursiveDeref(manager, l);
    Cudd_RecursiveDeref(manager, r);
    Cudd_Deref(n);
    return n;
  case AST_AND:
    l = build_cudd_bdd_from_ast(manager, t->node_content.node->l);
    Cudd_Ref(l);
    r = build_cudd_bdd_from_ast(manager, t->node_content.node->r);
    Cudd_Ref(r);
#ifdef USE_ADD
    n = Cudd_addApply(manager, Cudd_addTimes, l, r);
#else
    n = Cudd_bddAnd(manager, l, r);
#endif
    Cudd_Ref(n);
    Cudd_RecursiveDeref(manager, l);
    Cudd_RecursiveDeref(manager, r);
    Cudd_Deref(n);
    return n;
  case AST_CONST:
    if (t->node_content.constant)
      return Cudd_ReadOne(manager);
    else
#ifdef USE_ADD
      return Cudd_ReadZero(manager);
#else
    return Cudd_ReadLogicZero(manager);
#endif
  case AST_VAR:
  case AST_VPOWC:
  case AST_ADDC:
  case AST_MULC:
  case AST_ADD:
  case AST_MUL:
  case AST_DIVC:
  case AST_MODC:
  case AST_DIV:
  case AST_MOD:
  case AST_POW:
  case AST_SUB:
  case AST_EX:
  case AST_EG:
  case AST_EU:
    assert(0);  /* must be called on the result of normalize (see normalize.h) */
    return n;
  };

  return n;
}

DdNode *build_cudd_ctl(DdManager *manager, struct precompiled_ast_cudd *t, DdNode *ss)
{
  DdNode *n = NULL, *l, *r;
  
  switch (t->node_type) {
  case PRECOMPILED_AST_CUDD_BDD:
    n = Cudd_bddAnd(manager, ss, t->node_content.bdd);
    return n;
  case PRECOMPILED_AST_CUDD_NOT:
    l = build_cudd_ctl(manager, t->node_content.child, ss);
    Cudd_Ref(l);
    n = Cudd_Not(l);
    Cudd_Ref(n);
    Cudd_RecursiveDeref(manager, l);
    Cudd_Deref(n);
    return n;
  case PRECOMPILED_AST_CUDD_OR:
    l = build_cudd_ctl(manager, t->node_content.node->l, ss);
    Cudd_Ref(l);
    r = build_cudd_ctl(manager, t->node_content.node->r, ss);
    Cudd_Ref(r);
    n = Cudd_bddOr(manager, l, r);
    Cudd_Ref(n);
    Cudd_RecursiveDeref(manager, l);
    Cudd_RecursiveDeref(manager, r);
    Cudd_Deref(n);
    return n;
  case PRECOMPILED_AST_CUDD_AND:
    l = build_cudd_ctl(manager, t->node_content.node->l, ss);
    Cudd_Ref(l);
    r = build_cudd_ctl(manager, t->node_content.node->r, ss);
    Cudd_Ref(r);
    n = Cudd_bddAnd(manager, l, r);
    Cudd_Ref(n);
    Cudd_RecursiveDeref(manager, l);
    Cudd_RecursiveDeref(manager, r);
    Cudd_Deref(n);
    return n;
  case PRECOMPILED_AST_CUDD_EX:
    l = build_cudd_ctl(manager, t->node_content.child, ss);
    Cudd_Ref(l);
    n = ctl_cudd_EX(manager, l);
    Cudd_Ref(n);
    Cudd_RecursiveDeref(manager, l);
    Cudd_Deref(n);
    return n;
  case PRECOMPILED_AST_CUDD_EG:
    l = build_cudd_ctl(manager, t->node_content.child, ss);
    Cudd_Ref(l);
    n = ctl_cudd_EG(manager, l);
    Cudd_Ref(n);
    Cudd_RecursiveDeref(manager, l);
    Cudd_Deref(n);
    return n;
  case PRECOMPILED_AST_CUDD_EU:
    l = build_cudd_ctl(manager, t->node_content.node->l, ss);
    Cudd_Ref(l);
    r = build_cudd_ctl(manager, t->node_content.node->r, ss);
    Cudd_Ref(r);
    n = ctl_cudd_EU(manager, l, r);
    Cudd_Ref(n);
    Cudd_RecursiveDeref(manager, l);
    Cudd_RecursiveDeref(manager, r);
    Cudd_Deref(n);
    return n;
  }

  return n;
}

DdNode *build_cudd_identities(DdManager *manager, int *indexes, int n)
{
  int i;
  DdNode *var, *varp, *id_var, *r=Cudd_ReadOne(manager), *oldr;

  Cudd_Ref(r);
  for (i = n-2; i >= 0; i -= 2)
    if (indexes == NULL || indexes[i]) {
      oldr = r;
      var = Cudd_bddIthVar(manager, i);
      Cudd_Ref(var);
      varp = Cudd_bddIthVar(manager, i+1);
      Cudd_Ref(varp);
      id_var = Cudd_bddIte(manager, var, varp, Cudd_Not(varp));
      Cudd_Ref(id_var);
      Cudd_RecursiveDeref(manager, var);
      Cudd_RecursiveDeref(manager, varp);
      r = Cudd_bddAnd(manager, oldr, id_var);
      Cudd_Ref(r);
      Cudd_RecursiveDeref(manager, oldr);
      Cudd_RecursiveDeref(manager, id_var);
    }
  Cudd_Deref(r);

  return r;
}

#endif /* HAVE_CUDD */
