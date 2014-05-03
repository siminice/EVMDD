#include <stdlib.h>
#include "implicit_identities.h"
#include "env.h"
#include <evmdd/mdd_ops.h>
#include "build_cudd.h"
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef HAVE_CUDD
/* binary indexes of variables for CUDD */
extern int cudd_var_bits[];
#endif

static int to_add[ENV_SIZE];

static void implicit_identities_find_primed_vars(struct ast *t)
{
  switch (t->node_type) {
  case AST_VAR:
    if (t->node_content.var_id & 1)
      to_add[t->node_content.var_id >> 1] = 0;
    break;
  case AST_CONST:
    break;
  case AST_ADD:
  case AST_ADDC:
  case AST_SUB:
  case AST_MUL:
  case AST_MULC:
  case AST_DIVC:
  case AST_MODC:
  case AST_DIV:
  case AST_MOD:
  case AST_LT:
  case AST_EQ:
  case AST_OR:
  case AST_AND:
  case AST_POW:
  case AST_VPOWC:
  case AST_EU:
    implicit_identities_find_primed_vars(t->node_content.node->l);
    implicit_identities_find_primed_vars(t->node_content.node->r);
    break;
  case AST_NOT:
  case AST_EX:
  case AST_EG:
    implicit_identities_find_primed_vars(t->node_content.child);
    break;
  }
}

struct ast *implicit_identities(struct ast *t)
{
  int i, l = env_size();
  struct ast *lvalue, *rvalue, *identity, *r, *old_r;

  r = NULL;
 
  for (i = 1; i <= l; ++i)
    to_add[i] = 1;

  implicit_identities_find_primed_vars(t);

  for (i = 1; i <= l; ++i)
    if (to_add[i]) {
      lvalue = malloc(sizeof(struct ast));
      lvalue->node_type = AST_VAR;
      lvalue->node_content.var_id = i << 1 | 1;
      rvalue = malloc(sizeof(struct ast));
      rvalue->node_type = AST_VAR;
      rvalue->node_content.var_id = i << 1;
      identity = malloc(sizeof(struct ast));
      identity->node_type = AST_EQ;
      identity->node_content.node = malloc(sizeof(struct ast_node));
      identity->node_content.node->l = lvalue;
      identity->node_content.node->r = rvalue;
      old_r = r;
      if (old_r == NULL)
        r = identity;
      else {
        r = malloc(sizeof(struct ast));
        r->node_type = AST_AND;
        r->node_content.node = malloc(sizeof(struct ast_node));
        r->node_content.node->l = identity;
        r->node_content.node->r = old_r;
      }
    }

    if (r == NULL)
      r = t;
    else {
      old_r = r;
      r = malloc(sizeof(struct ast));
      r->node_type = AST_AND;
      r->node_content.node = malloc(sizeof(struct ast_node));
      r->node_content.node->l = t;
      r->node_content.node->r = old_r;
    }

  return r;
}

int *implicit_identities_indexes(mdd_manager_t *manager, struct ast *t)
{
  int i, l = env_size();

  for (i = 1; i <= l; ++i)
    to_add[i] = 1;
  
  implicit_identities_find_primed_vars(t);

  return to_add;
}

#ifdef HAVE_CUDD
DdNode *implicit_identities_build_cudd(DdManager *manager, struct ast *t)
{
  int i, j, l = env_size();
  int *indexes = calloc(cudd_var_bits[0], sizeof(int));

  for (i = 1; i <= l; ++i)
    to_add[i] = 1;
  
  implicit_identities_find_primed_vars(t);

  for (i = l; i; --i)
    if (to_add[i])
      for (j = cudd_var_bits[i]; j < cudd_var_bits[i-1]; ++j)
        indexes[j] = 1;

  return build_cudd_identities(manager, indexes, cudd_var_bits[0]);
}
#endif
