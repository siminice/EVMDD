#include <stdlib.h>
#include <stdio.h>
#include "normalize.h"
#include "ast.h"

void normalize(struct ast *t)
{
  int tmp;
  struct ast *tmp_ast;

  switch (t->node_type) {
  case AST_ADD:
    normalize(t->node_content.node->l);
    normalize(t->node_content.node->r);
    switch ((t->node_content.node->l->node_type == AST_CONST) << 1 |
            (t->node_content.node->r->node_type == AST_CONST)) {
    case 1 << 1 | 1:
      /* c + c -> c */
      tmp = t->node_content.node->l->node_content.constant
          + t->node_content.node->r->node_content.constant;
      free(t->node_content.node->l);
      free(t->node_content.node->r);
      free(t->node_content.node);
      t->node_type = AST_CONST;
      t->node_content.constant = tmp;
      break;
    case 1 << 1 | 0:
      /* c + f -> f + c */
      tmp_ast = t->node_content.node->l;
      t->node_content.node->l = t->node_content.node->r;
      t->node_content.node->r = tmp_ast;
      t->node_type = AST_ADDC;
      break;
    case 0 << 1 | 1:
      /* f + c */
      t->node_type = AST_ADDC;
      break;
    case 0 << 1 | 0:
      /* f + g */
      break;
    };
    break;
  case AST_SUB:
    normalize(t->node_content.node->l);
    normalize(t->node_content.node->r);
    switch ((t->node_content.node->l->node_type == AST_CONST) << 1 |
            (t->node_content.node->r->node_type == AST_CONST)) {
    case 1 << 1 | 1:
      /* c - c -> c */
      tmp = t->node_content.node->l->node_content.constant
          - t->node_content.node->r->node_content.constant;
      free(t->node_content.node->l);
      free(t->node_content.node->r);
      free(t->node_content.node);
      t->node_type = AST_CONST;
      t->node_content.constant = tmp;
      break;
    case 1 << 1 | 0:
      /* c - f -> (-f) + c */
      tmp_ast = malloc(sizeof(struct ast));
      tmp_ast->node_type = AST_MULC;
      tmp_ast->node_content.node = malloc(sizeof(struct ast_node));
      tmp_ast->node_content.node->r = malloc(sizeof(struct ast));
      tmp_ast->node_content.node->r->node_type = AST_CONST;
      tmp_ast->node_content.node->r->node_content.constant = -1;
      tmp_ast->node_content.node->l = t->node_content.node->r;
      t->node_content.node->r = t->node_content.node->l;
      t->node_content.node->l = tmp_ast;
      t->node_type = AST_ADDC;
      break;
    case 0 << 1 | 1:
      /* f -c -> f + (-c) */
      t->node_content.node->r->node_content.constant = -t->node_content.node->r->node_content.constant;
      t->node_type = AST_ADDC;
      break;
    case 0 << 1 | 0:
      /* f - g -> f + (-g) */
      tmp_ast = malloc(sizeof(struct ast));
      tmp_ast->node_type = AST_MULC;
      tmp_ast->node_content.node = malloc(sizeof(struct ast_node));
      tmp_ast->node_content.node->r = malloc(sizeof(struct ast));
      tmp_ast->node_content.node->r->node_type = AST_CONST;
      tmp_ast->node_content.node->r->node_content.constant = -1;
      tmp_ast->node_content.node->l = t->node_content.node->r;
      t->node_content.node->r = tmp_ast;
      t->node_type = AST_ADD;
      break;
    };
    break;
  case AST_MUL:
    normalize(t->node_content.node->l);
    normalize(t->node_content.node->r);
    switch ((t->node_content.node->l->node_type == AST_CONST) << 1 |
            (t->node_content.node->r->node_type == AST_CONST)) {
    case 1 << 1 | 1:
      /* c * c -> c */
      tmp = t->node_content.node->l->node_content.constant
          * t->node_content.node->r->node_content.constant;
      free(t->node_content.node->l);
      free(t->node_content.node->r);
      free(t->node_content.node);
      t->node_type = AST_CONST;
      t->node_content.constant = tmp;
      break;
    case 1 << 1 | 0:
      /* c * f -> f * c */
      tmp_ast = t->node_content.node->l;
      t->node_content.node->l = t->node_content.node->r;
      t->node_content.node->r = tmp_ast;
      t->node_type = AST_MULC;
      break;
    case 0 << 1 | 1:
      /* f * c */
      t->node_type = AST_MULC;
      break;
    case 0 << 1 | 0:
      /* f * g */
      break;
    };
    break;
  case AST_DIV:
    normalize(t->node_content.node->l);
    normalize(t->node_content.node->r);
    switch ((t->node_content.node->l->node_type == AST_CONST) << 1 |
            (t->node_content.node->r->node_type == AST_CONST)) {
    case 1 << 1 | 1:
      /* c / c -> c */
      tmp = t->node_content.node->l->node_content.constant
          / t->node_content.node->r->node_content.constant;
      free(t->node_content.node->l);
      free(t->node_content.node->r);
      free(t->node_content.node);
      t->node_type = AST_CONST;
      t->node_content.constant = tmp;
      break;
    case 0 << 1 | 1:
      /* f / c */
      t->node_type = AST_DIVC;
      break;
    case 0 << 1 | 0:
      /* f / g */
    case 1 << 1 | 0:
      /* c / f */
      break;
    };
    break;
  case AST_MOD:
    normalize(t->node_content.node->l);
    normalize(t->node_content.node->r);
    switch ((t->node_content.node->l->node_type == AST_CONST) << 1 |
            (t->node_content.node->r->node_type == AST_CONST)) {
    case 1 << 1 | 1:
      /* c % c -> c */
      tmp = t->node_content.node->l->node_content.constant
          % t->node_content.node->r->node_content.constant;
      free(t->node_content.node->l);
      free(t->node_content.node->r);
      free(t->node_content.node);
      t->node_type = AST_CONST;
      t->node_content.constant = tmp;
      break;
    case 0 << 1 | 1:
      /* f % c */
      t->node_type = AST_MODC;
      break;
    case 0 << 1 | 0:
      /* f % g */
    case 1 << 1 | 0:
      /* c % f */
      break;
    };
    break;
  case AST_LT:
    normalize(t->node_content.node->l);
    normalize(t->node_content.node->r);
    switch ((t->node_content.node->l->node_type == AST_CONST) << 1 |
            (t->node_content.node->r->node_type == AST_CONST)) {
    case 1 << 1 | 1:
      /* c < c -> c */
      tmp = t->node_content.node->l->node_content.constant
          < t->node_content.node->r->node_content.constant;
      free(t->node_content.node->l);
      free(t->node_content.node->r);
      free(t->node_content.node);
      t->node_type = AST_CONST;
      t->node_content.constant = tmp;
      break;
    case 1 << 1 | 0:
      /* c < f -> -f < -c */
      tmp_ast = malloc(sizeof(struct ast));
      tmp_ast->node_type = AST_MULC;
      tmp_ast->node_content.node = malloc(sizeof(struct ast_node));
      tmp_ast->node_content.node->r = malloc(sizeof(struct ast));
      tmp_ast->node_content.node->r->node_type = AST_CONST;
      tmp_ast->node_content.node->r->node_content.constant = -1;
      tmp_ast->node_content.node->l = t->node_content.node->r;
      t->node_content.node->r = t->node_content.node->l;
      t->node_content.node->r->node_content.constant = -t->node_content.node->r->node_content.constant;
      t->node_content.node->l = tmp_ast;
      break;
    case 0 << 1 | 1:
      /* f < c */
      break;
    case 0 << 1 | 0:
      /* f < g -> f-g < 0 */
      tmp_ast = malloc(sizeof(struct ast));
      tmp_ast->node_type = AST_MULC;
      tmp_ast->node_content.node = malloc(sizeof(struct ast_node));
      tmp_ast->node_content.node->r = malloc(sizeof(struct ast));
      tmp_ast->node_content.node->r->node_type = AST_CONST;
      tmp_ast->node_content.node->r->node_content.constant = -1;
      tmp_ast->node_content.node->l = t->node_content.node->r;
      t->node_content.node->r = tmp_ast;  /* r = -g */
      tmp_ast = malloc(sizeof(struct ast));
      tmp_ast->node_type = AST_ADD;
      tmp_ast->node_content.node = malloc(sizeof(struct ast_node));
      tmp_ast->node_content.node->l = t->node_content.node->l;
      tmp_ast->node_content.node->r = t->node_content.node->r;
      t->node_content.node->l = tmp_ast;  /* l = f + (-g) */
      t->node_content.node->r = malloc(sizeof(struct ast));
      t->node_content.node->r->node_type = AST_CONST;
      t->node_content.node->r->node_content.constant = 0;  /* r = 0 */
      break;
    };
    break;
  case AST_EQ:
    normalize(t->node_content.node->l);
    normalize(t->node_content.node->r);
    switch ((t->node_content.node->l->node_type == AST_CONST) << 1 |
            (t->node_content.node->r->node_type == AST_CONST)) {
    case 1 << 1 | 1:
      /* c = c -> c */
      tmp = t->node_content.node->l->node_content.constant
         == t->node_content.node->r->node_content.constant;
      free(t->node_content.node->l);
      free(t->node_content.node->r);
      free(t->node_content.node);
      t->node_type = AST_CONST;
      t->node_content.constant = tmp;
      break;
    case 1 << 1 | 0:
      /* c = f -> f = c */
      tmp_ast = t->node_content.node->r;
      t->node_content.node->r = t->node_content.node->l;
      t->node_content.node->l = tmp_ast;
      break;
    case 0 << 1 | 1:
      /* f = c */
      break;
    case 0 << 1 | 0:
      /* f = g -> f-g = 0 */
      tmp_ast = malloc(sizeof(struct ast));
      tmp_ast->node_type = AST_MULC;
      tmp_ast->node_content.node = malloc(sizeof(struct ast_node));
      tmp_ast->node_content.node->r = malloc(sizeof(struct ast));
      tmp_ast->node_content.node->r->node_type = AST_CONST;
      tmp_ast->node_content.node->r->node_content.constant = -1;
      tmp_ast->node_content.node->l = t->node_content.node->r;
      t->node_content.node->r = tmp_ast;  /* r = -g */
      tmp_ast = malloc(sizeof(struct ast));
      tmp_ast->node_type = AST_ADD;
      tmp_ast->node_content.node = malloc(sizeof(struct ast_node));
      tmp_ast->node_content.node->l = t->node_content.node->l;
      tmp_ast->node_content.node->r = t->node_content.node->r;
      t->node_content.node->l = tmp_ast;  /* l = f + (-g) */
      t->node_content.node->r = malloc(sizeof(struct ast));
      t->node_content.node->r->node_type = AST_CONST;
      t->node_content.node->r->node_content.constant = 0;  /* r = 0 */
      break;
    };
    break;
  case AST_NOT:
    if (t->node_content.child->node_type == AST_OR ||
        t->node_content.child->node_type == AST_AND) {
      /* !(f /\ g) -> !f \/ !g */
      /* !(f \/ g) -> !f /\ !g */
      tmp_ast = malloc(sizeof(struct ast));
      tmp_ast->node_type = AST_NOT;
      tmp_ast->node_content.child = t->node_content.child->node_content.node->l;
      t->node_content.child->node_content.node->l = tmp_ast;
      tmp_ast = malloc(sizeof(struct ast));
      tmp_ast->node_type = AST_NOT;
      tmp_ast->node_content.child = t->node_content.child->node_content.node->r;
      t->node_content.child->node_content.node->r = tmp_ast;
      tmp_ast = t->node_content.child;
      free(t->node_content.child);
      if (tmp_ast->node_type == AST_OR)
        t->node_type = AST_AND;
      else  /* tmp_ast->node_type == AST_AND */
        t->node_type = AST_OR;
      t->node_content = tmp_ast->node_content;
      normalize(t);
    } else if (t->node_content.child->node_type == AST_NOT) {
      /* !(!(f)) -> f */
      tmp_ast = t->node_content.child->node_content.child;
      free(t->node_content.child);
      t->node_type    = tmp_ast->node_type;
      t->node_content = tmp_ast->node_content;
      free(tmp_ast);
      normalize(t);
    } else {
      normalize(t->node_content.child);
      if (t->node_content.child->node_type == AST_CONST) {
        tmp = !(t->node_content.child->node_content.constant);
        free(t->node_content.child);
        t->node_type = AST_CONST;
        t->node_content.constant = tmp;
      }
    }
    break;
  case AST_OR:
    normalize(t->node_content.node->l);
    normalize(t->node_content.node->r);
    switch ((t->node_content.node->l->node_type == AST_CONST) << 1 |
            (t->node_content.node->r->node_type == AST_CONST)) {
    case 1 << 1 | 1:
      /* c \/ c -> c */
      tmp = t->node_content.node->l->node_content.constant
         || t->node_content.node->r->node_content.constant;
      free(t->node_content.node->l);
      free(t->node_content.node->r);
      free(t->node_content.node);
      t->node_type = AST_CONST;
      t->node_content.constant = tmp;
      break;
    case 1 << 1 | 0:
      /* 1 \/ f -> 1, 0 \/ f -> f */
      if (t->node_content.node->l->node_content.constant) {
        ast_free(t->node_content.node->r);
        free(t->node_content.node->l);
        free(t->node_content.node);
        t->node_type = AST_CONST;
        t->node_content.constant = 1;
      } else {
        free(t->node_content.node->l);
        tmp_ast = t->node_content.node->r;
        free(t->node_content.node);
        t->node_type = tmp_ast->node_type;
        t->node_content.node = tmp_ast->node_content.node;
      }
      break;
    case 0 << 1 | 1:
      /* f \/ 1 -> 1, f \/ 0 -> f */
      if (t->node_content.node->r->node_content.constant) {
        ast_free(t->node_content.node->l);
        free(t->node_content.node->r);
        free(t->node_content.node);
        t->node_type = AST_CONST;
        t->node_content.constant = 1;
      } else {
        free(t->node_content.node->r);
        tmp_ast = t->node_content.node->l;
        free(t->node_content.node);
        t->node_type = tmp_ast->node_type;
        t->node_content.node = tmp_ast->node_content.node;
      }
      break;
    case 0 << 1 | 0:
      /* f \/ g */
      break;
    };
    break;
  case AST_AND:
    normalize(t->node_content.node->l);
    normalize(t->node_content.node->r);
    switch ((t->node_content.node->l->node_type == AST_CONST) << 1 |
            (t->node_content.node->r->node_type == AST_CONST)) {
    case 1 << 1 | 1:
      /* c /\ c -> c */
      tmp = t->node_content.node->l->node_content.constant
         && t->node_content.node->r->node_content.constant;
      free(t->node_content.node->l);
      free(t->node_content.node->r);
      free(t->node_content.node);
      t->node_type = AST_CONST;
      t->node_content.constant = tmp;
      break;
    case 1 << 1 | 0:
      /* 1 /\ f -> f, 0 /\ f -> 0 */
      if (t->node_content.node->l->node_content.constant) {
        free(t->node_content.node->l);
        tmp_ast = t->node_content.node->r;
        free(t->node_content.node);
        t->node_type = tmp_ast->node_type;
        t->node_content.node = tmp_ast->node_content.node;
      } else {
        ast_free(t->node_content.node->r);
        free(t->node_content.node->l);
        free(t->node_content.node);
        t->node_type = AST_CONST;
        t->node_content.constant = 0;
      }
      break;
    case 0 << 1 | 1:
      /* f /\ 1 -> f, f /\ 0 -> 0 */
      if (t->node_content.node->r->node_content.constant) {
        free(t->node_content.node->r);
        tmp_ast = t->node_content.node->l;
        free(t->node_content.node);
        t->node_type = tmp_ast->node_type;
        t->node_content.node = tmp_ast->node_content.node;
      } else {
        ast_free(t->node_content.node->l);
        free(t->node_content.node->r);
        free(t->node_content.node);
        t->node_type = AST_CONST;
        t->node_content.constant = 0;
      }
      break;
    case 0 << 1 | 0:
      /* f /\ g */
      break;
    };
    break;
  case AST_POW:
    normalize(t->node_content.node->l);
    normalize(t->node_content.node->r);
    if (t->node_content.node->l->node_type == AST_VAR &&
        t->node_content.node->r->node_type == AST_CONST)
      t->node_type = AST_VPOWC;
    break;
  case AST_ADDC:
  case AST_MULC:
  case AST_DIVC:
  case AST_MODC:
    normalize(t->node_content.node->l);
    break;
  case AST_VPOWC:
    switch (t->node_content.node->r->node_content.constant) {
    case 0:
      t->node_type = AST_CONST;
      free(t->node_content.node->l);
      free(t->node_content.node->r);
      free(t->node_content.node);
      t->node_content.constant = 1;
      break;
    case 1:
      t->node_type = AST_VAR;
      tmp = t->node_content.node->l->node_content.var_id;
      free(t->node_content.node->l);
      free(t->node_content.node->r);
      free(t->node_content.node);
      t->node_content.var_id = tmp;
      break;
    default:
      break;
    }
    break;
  case AST_EX:
  case AST_EG:
    normalize(t->node_content.child);
    break;
  case AST_EU:
    normalize(t->node_content.node->l);
    normalize(t->node_content.node->r);
    break;
  case AST_VAR:
  case AST_MACRO:
  case AST_CONST:
    break;
  };
}
