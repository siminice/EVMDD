#include <stdlib.h>
#include <stdio.h>
#include "ast.h"
#include "env.h"

extern int iorder[];

int ast_contains_primed_var(struct ast* t)
{
  switch (t->node_type) {
  case AST_VAR:
    return t->node_content.var_id & 1;
  case AST_CONST:
    return 0;
  case AST_MACRO:
    return ast_contains_primed_var(t->node_content.node->r);
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
    return ast_contains_primed_var(t->node_content.node->l) ||
           ast_contains_primed_var(t->node_content.node->r);
  case AST_NOT:
  case AST_EX:
  case AST_EG:
    return ast_contains_primed_var(t->node_content.child);
  }
  return 0;
}

static void rec_print(struct ast *t)
{
  switch (t->node_type) {
  case AST_VAR:
    printf("%s%s", env_name(iorder[t->node_content.var_id >> 1], NULL, NULL), t->node_content.var_id & 1 ? "'" : ""); 
/*    printf("%s%s", env_name(t->node_content.var_id >> 1, NULL, NULL), t->node_content.var_id & 1 ? "'" : "");*/
    break;
  case AST_CONST:
    printf("%d", t->node_content.constant);
    break;
  case AST_ADD:
    rec_print(t->node_content.node->l);
    printf("+(");
    rec_print(t->node_content.node->r);
    printf(")");
    break;
  case AST_ADDC:
    rec_print(t->node_content.node->l);
    printf("+");
    rec_print(t->node_content.node->r);
    break;
  case AST_SUB:
    rec_print(t->node_content.node->l);
    printf("-(");
    rec_print(t->node_content.node->r);
    printf(")");
    break;
  case AST_MUL:
    printf("(");
    rec_print(t->node_content.node->l);
    printf(")*(");
    rec_print(t->node_content.node->r);
    printf(")");
    break;
  case AST_MULC:
    printf("(");
    rec_print(t->node_content.node->l);
    printf(")*");
    rec_print(t->node_content.node->r);
    break;
  case AST_DIV:
  case AST_DIVC:
    printf("(");
    rec_print(t->node_content.node->l);
    printf(")/(");
    rec_print(t->node_content.node->r);
    printf(")");
    break;
  case AST_MOD:
  case AST_MODC:
    printf("(");
    rec_print(t->node_content.node->l);
    printf(")%%(");
    rec_print(t->node_content.node->r);
    printf(")");
    break;
  case AST_LT:
    rec_print(t->node_content.node->l);
    printf(" < ");
    rec_print(t->node_content.node->r);
    break;
  case AST_MACRO:
  case AST_EQ:
    rec_print(t->node_content.node->l);
    printf(" = ");
    rec_print(t->node_content.node->r);
    break;
  case AST_NOT:
    printf("!(");
    rec_print(t->node_content.child);
    printf(")");
    break;
  case AST_AND:
    printf("(");
    rec_print(t->node_content.node->l);
    printf(") /\\ (");
    rec_print(t->node_content.node->r);
    printf(")");
    break;
  case AST_OR:
    printf("(");
    rec_print(t->node_content.node->l);
    printf(") \\/ (");
    rec_print(t->node_content.node->r);
    printf(")");
    break;
  case AST_POW:
    printf("(");
    rec_print(t->node_content.node->l);
    printf(")^(");
    rec_print(t->node_content.node->r);
    printf(")");
    break;
  case AST_VPOWC:
    rec_print(t->node_content.node->l);
    printf("^");
    rec_print(t->node_content.node->r);
    break;
  case AST_EX:
    printf("EX(");
    rec_print(t->node_content.child);
    printf(")");
    break;
  case AST_EG:
    printf("EG(");
    rec_print(t->node_content.child);
    printf(")");
    break;
  case AST_EU:
    printf("E[(");
    rec_print(t->node_content.node->l);
    printf(")U(");
    rec_print(t->node_content.node->r);
    printf(")]");
    break;
  }
}

void ast_print(struct ast *t)
{
  rec_print(t);
  printf("\n");
}

struct ast *ast_copy(struct ast *t)
{
  struct ast *r;

  if (t == NULL) return NULL;

  r = malloc(sizeof(struct ast));
  r->node_type = t->node_type;
  switch (t->node_type) {
  case AST_VAR:
  case AST_CONST:
    r->node_content = t->node_content;
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
  case AST_MACRO:
  case AST_EU:
    r->node_content.node = malloc(sizeof(struct ast));
    r->node_content.node->l = ast_copy(t->node_content.node->l);
    r->node_content.node->r = ast_copy(t->node_content.node->r);
    break;
  case AST_NOT:
  case AST_EX:
  case AST_EG:
    r->node_content.child = ast_copy(t->node_content.child);
    break;
  }

  return r;
}

void ast_var_dependencies(struct ast *t, char *dep) {
  switch (t->node_type) {
  case AST_VAR:
      dep[t->node_content.var_id >> 1] = '+';
    break;
  case AST_CONST:
  case AST_EX:
  case AST_EG:
  case AST_EU:
  case AST_MACRO:
    break;
  case AST_ADDC:
  case AST_MULC:
  case AST_DIVC:
  case AST_MODC:
  case AST_VPOWC:
    ast_var_dependencies(t->node_content.node->l, dep);
    break;
  case AST_ADD:
  case AST_SUB:
  case AST_MUL:
  case AST_DIV:
  case AST_MOD:
  case AST_LT:
  case AST_EQ:
  case AST_OR:
  case AST_AND:
  case AST_POW:
    ast_var_dependencies(t->node_content.node->l, dep);
    ast_var_dependencies(t->node_content.node->r, dep);
    break;
  case AST_NOT:
    ast_var_dependencies(t->node_content.child, dep);
    break;
  }
}

void ast_mult_dependencies(struct ast *t, char **dep) {
  char *avl, *avr;
  int i, j, l;
  switch (t->node_type) {
  case AST_VAR:
  case AST_MACRO:
  case AST_CONST:
  case AST_EX:
  case AST_EG:
  case AST_EU:
    break;
  case AST_ADDC:
  case AST_MULC:
  case AST_DIVC:
  case AST_MODC:
  case AST_VPOWC:
    ast_mult_dependencies(t->node_content.node->l, dep);
    break;
  case AST_ADD:
  case AST_SUB:
  case AST_LT:
  case AST_EQ:
  case AST_OR:
  case AST_AND:
  case AST_POW:
    ast_mult_dependencies(t->node_content.node->l, dep);
    ast_mult_dependencies(t->node_content.node->r, dep);
    break;
  case AST_NOT:
    ast_mult_dependencies(t->node_content.child, dep);
    break;
  case AST_MUL:
  case AST_DIV:
  case AST_MOD:
    l = env_size();
    avl = (char*)malloc((l+1)*sizeof(char));
    avr = (char*)malloc((l+1)*sizeof(char));
    for (i=0; i<=l; i++) { avl[i] = '-'; avr[i] = '-'; }
    ast_var_dependencies(t->node_content.node->l, avl);
    ast_var_dependencies(t->node_content.node->r, avr);
    for (i=1; i<=l; i++) {
      if (avl[i]=='+') {
        for (j=1; j<=l; j++) {
          if (i!=j && avr[j]=='+') {
            dep[i][j] = '+';
            dep[j][i] = '+';
          }
        }
      }
    }
    free(avl);
    free(avr);
    break;
  }
}

void ast_free(struct ast* t)
{
  if (t == NULL) return;

  switch (t->node_type) {
  case AST_VAR:
  case AST_CONST:
    free(t);
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
  case AST_MACRO:
    ast_free(t->node_content.node->l);
    ast_free(t->node_content.node->r);
    free(t->node_content.node);
    free(t);
    break;
  case AST_NOT:
  case AST_EX:
  case AST_EG:
    ast_free(t->node_content.child);
    free(t);
    break;
  }
}

