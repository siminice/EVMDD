#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_CUDD

#include <stdlib.h>
#include <limits.h>
#include "precompiled_ast_cudd.h"
#include "build_cudd.h"

struct precompiled_ast_cudd *precompiled_ast_cudd_from_ast(DdManager *manager, struct ast *t)
{
  struct precompiled_ast_cudd *rn, *tmpnl, *tmpnr;
  DdNode *n = NULL;

  if (t == NULL) return NULL;

  rn = malloc(sizeof(struct precompiled_ast_cudd));
  switch (t->node_type) {
  case AST_CONST:
  case AST_LT:
  case AST_EQ:
    rn->node_type = PRECOMPILED_AST_CUDD_BDD;
    rn->node_content.bdd = build_cudd_bdd_from_ast(manager, t);
    Cudd_Ref(rn->node_content.bdd);
    return rn;
  case AST_NOT:
    tmpnl = precompiled_ast_cudd_from_ast(manager, t->node_content.child);
    if (tmpnl->node_type == PRECOMPILED_AST_CUDD_BDD) {
      n = Cudd_Not(tmpnl->node_content.bdd);
      Cudd_Ref(n);
      Cudd_RecursiveDeref(manager, tmpnl->node_content.bdd);
      free(rn);
      rn = tmpnl;
      rn->node_content.bdd = n;
    } else {
      rn->node_type = PRECOMPILED_AST_CUDD_NOT;
      rn->node_content.child = tmpnl;
    }
    return rn;
  case AST_OR:
    tmpnl = precompiled_ast_cudd_from_ast(manager, t->node_content.node->l);
    tmpnr = precompiled_ast_cudd_from_ast(manager, t->node_content.node->r);
    if (tmpnl->node_type == PRECOMPILED_AST_CUDD_BDD &&
        tmpnr->node_type == PRECOMPILED_AST_CUDD_BDD) {
      n = Cudd_bddOr(manager,
                     tmpnl->node_content.bdd,
                     tmpnr->node_content.bdd);
      Cudd_Ref(n);
      Cudd_RecursiveDeref(manager, tmpnl->node_content.bdd);
      Cudd_RecursiveDeref(manager, tmpnr->node_content.bdd);
      rn->node_type = PRECOMPILED_AST_CUDD_BDD;
      rn->node_content.bdd = n;
      free(tmpnl);
      free(tmpnr);
    } else {
      rn->node_type = PRECOMPILED_AST_CUDD_OR;
      rn->node_content.node = malloc(sizeof(struct precompiled_ast_cudd_node));
      rn->node_content.node->l = tmpnl;
      rn->node_content.node->l = tmpnr;
    }
    return rn;
  case AST_AND:
    tmpnl = precompiled_ast_cudd_from_ast(manager, t->node_content.node->l);
    tmpnr = precompiled_ast_cudd_from_ast(manager, t->node_content.node->r);
    if (tmpnl->node_type == PRECOMPILED_AST_CUDD_BDD &&
        tmpnr->node_type == PRECOMPILED_AST_CUDD_BDD) {
      n = Cudd_bddAnd(manager,
                      tmpnl->node_content.bdd,
                      tmpnr->node_content.bdd);
      Cudd_Ref(n);
      Cudd_RecursiveDeref(manager, tmpnl->node_content.bdd);
      Cudd_RecursiveDeref(manager, tmpnr->node_content.bdd);
      rn->node_type = PRECOMPILED_AST_CUDD_BDD;
      rn->node_content.bdd = n;
      free(tmpnl);
      free(tmpnr);
    } else {
      rn->node_type = PRECOMPILED_AST_CUDD_OR;
      rn->node_content.node = malloc(sizeof(struct precompiled_ast_cudd_node));
      rn->node_content.node->l = tmpnl;
      rn->node_content.node->l = tmpnr;
    }
    return rn;
  case AST_EX:
    rn->node_type = PRECOMPILED_AST_CUDD_EX;
    rn->node_content.child = precompiled_ast_cudd_from_ast(manager,
                                                           t->node_content.child);
    return rn;
  case AST_EG:
    rn->node_type = PRECOMPILED_AST_CUDD_EG;
    rn->node_content.child = precompiled_ast_cudd_from_ast(manager,
                                                           t->node_content.child);
    return rn;
  case AST_EU:
    rn->node_type = PRECOMPILED_AST_CUDD_EU;
    rn->node_content.node = malloc(sizeof(struct precompiled_ast_cudd_node));
    rn->node_content.node->l = precompiled_ast_cudd_from_ast(manager,
                                                             t->node_content.node->l);
    rn->node_content.node->r = precompiled_ast_cudd_from_ast(manager,
                                                             t->node_content.node->r);
    return rn;
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
    assert(0);  /* must be called on the result of normalize (see normalize.h) */
    return rn;
  }

  return rn;
}

void precompiled_ast_cudd_free(DdManager *manager, struct precompiled_ast_cudd *t)
{
  if (t == NULL) return;

  switch (t->node_type) {
  case PRECOMPILED_AST_CUDD_BDD:
    Cudd_RecursiveDeref(manager, t->node_content.bdd);
    free(t);
    break;
  case PRECOMPILED_AST_CUDD_OR:
  case PRECOMPILED_AST_CUDD_AND:
  case PRECOMPILED_AST_CUDD_EU:
    precompiled_ast_cudd_free(manager, t->node_content.node->l);
    precompiled_ast_cudd_free(manager, t->node_content.node->r);
    free(t->node_content.node);
    free(t);
    break;
  case PRECOMPILED_AST_CUDD_NOT:
  case PRECOMPILED_AST_CUDD_EX:
  case PRECOMPILED_AST_CUDD_EG:
    precompiled_ast_cudd_free(manager, t->node_content.child);
    free(t);
    break;
  }
}

#endif /* HAVE_CUDD */
