#ifndef PRECOMPILED_AST_CUDD_H
#define PRECOMPILED_AST_CUDD_H

#include "ast.h"
/* CUDD */
#include "util.h"
#include "cudd.h"

typedef enum {PRECOMPILED_AST_CUDD_BDD,
              PRECOMPILED_AST_CUDD_NOT, PRECOMPILED_AST_CUDD_OR, PRECOMPILED_AST_CUDD_AND,
              PRECOMPILED_AST_CUDD_EX, PRECOMPILED_AST_CUDD_EG, PRECOMPILED_AST_CUDD_EU} precompiled_ast_cudd_ops_t;

struct precompiled_ast_cudd;

struct precompiled_ast_cudd_node {
  struct precompiled_ast_cudd *l;
  struct precompiled_ast_cudd *r;
};

struct precompiled_ast_cudd {
  precompiled_ast_cudd_ops_t node_type;
  union {
    struct precompiled_ast_cudd_node *node;
    struct precompiled_ast_cudd *child;
    DdNode *bdd;
  } node_content;
};

struct precompiled_ast_cudd *precompiled_ast_cudd_from_ast(DdManager *manager, struct ast *t);

/* free the AST t */
void precompiled_ast_cudd_free(DdManager *manager, struct precompiled_ast_cudd *t);

#endif  /* PRECOMPILED_AST_CUDD_H */
