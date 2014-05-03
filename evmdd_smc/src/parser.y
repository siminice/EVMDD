%{
  #include <stdlib.h>
  #include <stdio.h>
  #include "ast.h"
  #include "env.h"
  int yylex();
  extern int yylineno;
  extern char *yytext;
  void yyerror(char *);
  static struct ast *build_unode(ast_ops_t, struct ast*);
  static struct ast *build_node(ast_ops_t, struct ast*, struct ast*);
  extern void add_init_states(struct ast*);
  extern void add_equations(struct ast*);
  extern void add_event(struct ast*, char*);
  extern void check_property(struct ast*, char*);
  extern int build_model();
  extern int verbosity_level;
%}

%union {
  int value;
  char *name;
  struct ast *ast;
}

%type <ast> atom_bool_exp
%type <ast> bool_exp
%type <ast> int_exp
%type <ast> ctl
%type <ast> var
%type <ast> constant
%type <value> prime
%type <ast> event_body

%token <name> TIDENT
       TPRIME
       <value> TNUM
       TPLUS TMINUS TMULT TTT TFF TLT TLE TGT TGE TEQ TNEQ TNOT TOR TAND TLPAR TRPAR TPOW
       TLBRA TRBRA TCOMMA TQMARK TTIL
       TNL
       TVAR TDEF TEQN TINIT TTRANS
       TSEMI TARROW
       TAX TAG TAF TA TEX TEG TEF TE TX TF TG TU TR
       TPROP

%left TOR
%left TAND
%left TNOT
%left TAX TAG TAF TA TEX TEG TEF TE TX TF TG TU TR
%left TPLUS TMINUS
%left TMULT TDIV TMOD
%left TNEG
%right TPOW

%%
input:         TNL input  /* to enable comment at beginning of file */
             | decls defs inits events properties
             | decls defs inits events
             | decls inits events properties
             | decls inits events
             | decls defs eqns
             | decls eqns
;
     
decls:         TVAR
             | decls TNL
             | decls decl TNL
;

defs:         TDEF
             | defs TNL
             | defs def TNL
;

eqns:         TEQN
             | eqns TNL
             | eqns bool_exp TNL	{ equation_put(NULL, $2); }
					/* { add_equations($2); } */
;

inits:         TINIT
             | inits TNL
             | inits bool_exp TNL	{ init_put($2); }
					/* { add_init_states($2); } */
;

events:        TTRANS
             | events TNL
             | events event TNL
;

properties:    TPROP
             | properties TNL
             | properties property TNL
;

decl:          TIDENT TLBRA constant TCOMMA constant TRBRA
                                       { int id;
                                         if (env_is_in($1, NULL, NULL)) {
                                           fprintf(stderr, "Error: variable \"%s\" already declared, skipping declaration.\n", $1);
                                           free($1);
                                         } else {
                                           id = env_put($1, $3->node_content.constant, $5->node_content.constant);
                                         } }
;

def:          TIDENT TEQ int_exp
                                       { int id;
                                         if (mdf_is_in($1, NULL, NULL)) {
                                           fprintf(stderr, "Error: macro \"%s\" already declared, skipping declaration.\n", $1);
                                           free($1);
                                         } else {
                                         id = mdf_put($1, $3);
                                         } }
;

event:         event_body		{ event_put(NULL, $1); }
					/* { add_event($1, NULL); } */
             | TIDENT TSEMI event_body	{ event_put($1, $3); }
                                       /* { add_event($3, $1); } */
;

event_body:    bool_exp                { $$ = $1; }
             | bool_exp TARROW bool_exp
                                       { if ($1 && ast_contains_primed_var($1)) {
                                           fprintf(stderr, "Error: guard (before '->') should not contain any primed variable.\n");
                                           free($1);
                                           free($3);
                                           $$ = NULL;
                                         } else
                                           $$ = build_node(AST_AND, $1, $3); }
;

property:      ctl                   { check_property($1, NULL); }
             | TIDENT TSEMI ctl      { check_property($3, $1); }
;

atom_bool_exp: TTT                     { $$ = malloc(sizeof(struct ast));
                                         $$->node_type = AST_CONST;
                                         $$->node_content.constant = 1; }
             | TFF                     { $$ = malloc(sizeof(struct ast));
                                         $$->node_type = AST_CONST;
                                         $$->node_content.constant = 0; }
             | int_exp TLT int_exp     { $$ = build_node(AST_LT, $1, $3); }
             | int_exp TLE int_exp     { $$ = build_unode(AST_NOT, build_node(AST_LT, $3, $1)); }
             | int_exp TGT int_exp     { $$ = build_node(AST_LT, $3, $1); }
             | int_exp TGE int_exp     { $$ = build_unode(AST_NOT, build_node(AST_LT, $1, $3)); }
             | int_exp TEQ int_exp     { $$ = build_node(AST_EQ, $1, $3); }
             | int_exp TNEQ int_exp    { $$ = build_unode(AST_NOT, build_node(AST_EQ, $1, $3)); }
;

bool_exp:      atom_bool_exp           { $$ = $1; }
             | TNOT bool_exp           { $$ = build_unode(AST_NOT, $2); }
             | bool_exp TOR bool_exp   { $$ = build_node(AST_OR, $1, $3); }
             | bool_exp TAND bool_exp  { $$ = build_node(AST_AND, $1, $3); }
             | TLPAR bool_exp TRPAR    { $$ = $2; }
;

int_exp:       constant                { $$ = $1; }
             | var                     { $$ = $1; }
             | var TPOW constant       { $$ = build_node(AST_POW, $1, $3); }
             | int_exp TPLUS int_exp   { $$ = build_node(AST_ADD, $1, $3); }
             | int_exp TMINUS int_exp  { $$ = build_node(AST_SUB, $1, $3); }
             | int_exp TMULT int_exp   { $$ = build_node(AST_MUL, $1, $3); }
             | int_exp TDIV int_exp    { $$ = build_node(AST_DIV, $1, $3); }
             | int_exp TMOD int_exp    { $$ = build_node(AST_MOD, $1, $3); }
             | TMINUS int_exp %prec TNEG { struct ast *n = malloc(sizeof(struct ast));
                                         n->node_type = AST_CONST;
                                         n->node_content.constant = -1;
                                         $$ = build_node(AST_MUL, n, $2); }
             | TLPAR int_exp TRPAR     { $$ = $2; }
;

prime:         /* empty */             { $$ = 0; }
             | TPRIME                  { $$ = 1; }
;

var:           TIDENT prime            { int vid = env_is_in($1, NULL, NULL);
					 int mid = mdf_is_in($1, NULL, NULL);
                                         if (vid==0 && mid==0) {
                                           fprintf(stderr, "Error: undeclared variable \"%s\", skipping expression.\n", $1);
                                           free($1);
                                           $$ = NULL;
                                         } else if (vid>0) {
                                           $$ = malloc(sizeof(struct ast));
                                           $$->node_type = AST_VAR;
                                           vid <<= 1;
                                           vid += $2;
                                           $$->node_content.var_id = vid;
					 } else if (mid>0) {
                                           struct ast *mb = (struct ast*) mdf_get_body(mid);
					   $$ = mb;
                                         } }
;

constant:      TNUM                    { $$ = malloc(sizeof(struct ast));
                                         $$->node_type = AST_CONST;
                                         $$->node_content.constant = $1; }
             | TMINUS TNUM %prec TNEG  { $$ = malloc(sizeof(struct ast));
                                         $$->node_type = AST_CONST;
                                         $$->node_content.constant = -$2;
                                        }
;

ctl:           atom_bool_exp           { $$ = $1; }
             | TNOT ctl                { $$ = build_unode(AST_NOT, $2); }
             | ctl TOR ctl             { $$ = build_node(AST_OR, $1, $3); }
             | ctl TAND ctl            { $$ = build_node(AST_AND, $1, $3); }
             | TLPAR ctl TRPAR         { $$ = $2; }
             | TEX ctl                 { $$ = build_unode(AST_EX, $2); }
             | TEG ctl                 { $$ = build_unode(AST_EG, $2); }
             | TE TLBRA ctl TU ctl TRBRA
                                       { $$ = build_node(AST_EU, $3, $5); }
             | TAX ctl                 { $$ = build_unode(AST_NOT,
                                              build_unode(AST_EX,
                                              build_unode(AST_NOT, $2))); }
             | TEF ctl                 { struct ast *n = malloc(sizeof(struct ast));
                                         n->node_type = AST_CONST;
                                         n->node_content.constant = 1;
                                         $$ = build_node(AST_EU, n, $2); }
             | TAG ctl                 { struct ast *n = malloc(sizeof(struct ast));
                                         n->node_type = AST_CONST;
                                         n->node_content.constant = 1;
                                         $$ = build_unode(AST_NOT,
                                              build_node(AST_EU,
                                                         n,
                                                         build_unode(AST_NOT, $2))); }
             | TAF ctl                 { $$ = build_unode(AST_NOT,
                                              build_unode(AST_EG,
                                              build_unode(AST_NOT, $2))); }
             | TA TLBRA ctl TU ctl TRBRA
                                       { $$ = build_node(AST_AND,
                                                build_unode(AST_NOT,
                                                  build_node(AST_EU,
                                                    build_unode(AST_NOT, $5),
                                                    build_node(AST_AND,
                                                      build_unode(AST_NOT, $3),
                                                        build_unode(AST_NOT, ast_copy($5))))),
                                                build_unode(AST_NOT,
                                                  build_unode(AST_EG,
                                                    build_unode(AST_NOT, ast_copy($5))))); }
             | TA TLBRA ctl TR ctl TRBRA
                                       { $$ = build_unode(AST_NOT,
                                                build_node(AST_EU,
                                                  build_unode(AST_NOT, $3),
                                                  build_unode(AST_NOT, $5))); }
             | TE TLBRA ctl TR ctl TRBRA
                                       { $$ = build_node(AST_OR,
                                                build_node(AST_EU,
                                                  $5,
                                                  build_node(AST_AND, $3, $5)),
                                                    build_unode(AST_EG, ast_copy($5))); }
;
%%

/* Called by yyparse on error.  */
void yyerror (char *s)
{
  fprintf(stderr, "Error, %s: \"%s\" on line %d\n", s, yytext, yylineno);
  exit(1);
}

/* build unary node of type op with children c */
static struct ast *build_unode(ast_ops_t op, struct ast *c)
{
  struct ast *n;

  if (c == NULL) {
     ast_free(c);
     return NULL;
  }

  n = malloc(sizeof(struct ast));
  n->node_type = op;
  n->node_content.child = c;

  return n;
}

/* build node of type op with two children l and r */
static struct ast *build_node(ast_ops_t op, struct ast *l, struct ast *r)
{
  struct ast *n;

  if (l == NULL || r == NULL) {
     ast_free(l);
     ast_free(r);
     return NULL;
  }

  n = malloc(sizeof(struct ast));
  n->node_type = op;
  n->node_content.node = malloc(sizeof(struct ast_node));
  n->node_content.node->l = l;
  n->node_content.node->r = r;

  return n;
}
