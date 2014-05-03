#ifndef AST_H
#define AST_H

typedef enum {AST_VAR, AST_MACRO, AST_CONST,
              AST_ADD, AST_SUB, AST_MUL, AST_POW, AST_DIV, AST_MOD, AST_LT, AST_EQ, AST_NOT, AST_OR, AST_AND,
              AST_EX, AST_EG, AST_EU,
              /* operations with a constant,
                 constant is right child
                 after applying normalization (see normalize.h) */
              AST_ADDC, AST_MULC, AST_VPOWC, AST_DIVC, AST_MODC} ast_ops_t;

struct ast;

struct ast_node {
  struct ast *l;
  struct ast *r;
};

struct ast {
  ast_ops_t node_type;
  union {
    struct ast_node *node;
    struct ast *child;
    int var_id;
    int constant;
  } node_content;
};

int ast_contains_primed_var(struct ast*);

/* find affected variables */
void ast_var_dependencies(struct ast*, char*);

/* compute variable dependencies due to multiplication */
void ast_mult_dependencies(struct ast*, char**);

/* print an AST */
void ast_print(struct ast*);

struct ast *ast_copy(struct ast*);

/* free the AST t */
void ast_free(struct ast *t);

#endif  /* AST_H */
