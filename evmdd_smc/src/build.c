#include <stdio.h>
#include <assert.h>
#include "build.h"
#include <evmdd/mdd_node.h>
#include <evmdd/evmdd_node.h>
#include <evmdd/mdd_ops.h>
#include <evmdd/evmdd_ops.h>
#include "ctl.h"
#include "env.h"
#include "clock.h"
#include "utils.h"

extern int ranges[];
extern int iorder[];
extern int verbosity_level;
extern int nb_printed;
extern char *dot_output;

FILE *f;

evmdd_edge_t build_evmdd_from_ast(mdd_manager_t *mdd_manager, struct ast *t)
{
  int lb, ub, voi, voli, vp;
  evmdd_edge_t op1, op2, r = {0, 0};

  switch (t->node_type) {
  case AST_VAR:
  case AST_MACRO:
    vp = t->node_content.var_id & 1;
    voi = iorder[t->node_content.var_id >> 1]; 
/*    voi = t->node_content.var_id >> 1; */
    env_name(voi, &lb, &ub);
    return evmdd_var_new(mdd_manager, voi, vp);
  case AST_VPOWC:
    vp = (t->node_content.node->l->node_content.var_id) & 1;
    voli = iorder[t->node_content.node->l->node_content.var_id >> 1]; 
/*    voli = t->node_content.node->l->node_content.var_id >> 1; */
    env_name(voli, &lb, &ub);
    return evmdd_var_new_at_power(mdd_manager,
                                  voli,
                                  vp,
                                  t->node_content.node->r->node_content.constant);
  case AST_ADDC:
    r = evmdd_add_scalar(mdd_manager,
                         build_evmdd_from_ast(mdd_manager, t->node_content.node->l),
                         t->node_content.node->r->node_content.constant);
    if (dot_output) {
      printf("DOT build %d : ", nb_printed); ast_print(t); printf("\n");
      f = utils_nfopen(dot_output, nb_printed, "_build_trans.dot");
      evmdd_print_dot(mdd_manager, r, f);
      fclose(f);
      ++nb_printed;
    }
    return r;
  case AST_MULC:
    op1 = build_evmdd_from_ast(mdd_manager, t->node_content.node->l);
    evmdd_ref(mdd_manager, op1);
    r = evmdd_mult_scalar(mdd_manager, op1, t->node_content.node->r->node_content.constant);
    evmdd_unref(mdd_manager, op1);
    if (dot_output) {
      printf("DOT build %d : ", nb_printed); ast_print(t); printf("\n");
      f = utils_nfopen(dot_output, nb_printed, "_build_trans.dot");
      evmdd_print_dot(mdd_manager, r, f);
      fclose(f);
      ++nb_printed;
    }
    return r;
  case AST_ADD:
    op1 = build_evmdd_from_ast(mdd_manager, t->node_content.node->l);
    evmdd_ref(mdd_manager, op1);
    op2 = build_evmdd_from_ast(mdd_manager, t->node_content.node->r);
    evmdd_ref(mdd_manager, op2);
    r = evmdd_add(mdd_manager, op1, op2);
    evmdd_unref(mdd_manager, op1);
    evmdd_unref(mdd_manager, op2);
    if (dot_output) {
      printf("DOT build %d : ", nb_printed); ast_print(t); printf("\n");
      f = utils_nfopen(dot_output, nb_printed, "_build_trans.dot");
      evmdd_print_dot(mdd_manager, r, f);
      fclose(f);
      ++nb_printed;
    }
    return r;
  case AST_MUL:
    op1 = build_evmdd_from_ast(mdd_manager, t->node_content.node->l);
    evmdd_ref(mdd_manager, op1);
    op2 = build_evmdd_from_ast(mdd_manager, t->node_content.node->r);
    evmdd_ref(mdd_manager, op2);
    r = evmdd_mult(mdd_manager, op1, op2);
    evmdd_unref(mdd_manager, op1);
    evmdd_unref(mdd_manager, op2);
    if (dot_output) {
      printf("DOT build %d : ", nb_printed); ast_print(t); printf("\n");
      f = utils_nfopen(dot_output, nb_printed, "_build_trans.dot");
      evmdd_print_dot(mdd_manager, r, f);
      fclose(f);
      ++nb_printed;
    }
    return r;
  case AST_DIV:
    op1 = build_evmdd_from_ast(mdd_manager, t->node_content.node->l);
    evmdd_ref(mdd_manager, op1);
    op2 = build_evmdd_from_ast(mdd_manager, t->node_content.node->r);
    evmdd_ref(mdd_manager, op2);
    r = evmdd_div(mdd_manager, op1, op2);
    evmdd_unref(mdd_manager, op1);
    evmdd_unref(mdd_manager, op2);
    if (dot_output) {
      printf("DOT build %d : ", nb_printed); ast_print(t); printf("\n");
      f = utils_nfopen(dot_output, nb_printed, "_build_trans.dot");
      evmdd_print_dot(mdd_manager, r, f);
      fclose(f);
      ++nb_printed;
    }
    return r;
  case AST_MOD:
    op1 = build_evmdd_from_ast(mdd_manager, t->node_content.node->l);
    evmdd_ref(mdd_manager, op1);
    op2 = build_evmdd_from_ast(mdd_manager, t->node_content.node->r);
    evmdd_ref(mdd_manager, op2);
    r = evmdd_mod(mdd_manager, op1, op2);
    evmdd_unref(mdd_manager, op1);
    evmdd_unref(mdd_manager, op2);
    if (dot_output) {
      printf("DOT build %d : ", nb_printed); ast_print(t); printf("\n");
      f = utils_nfopen(dot_output, nb_printed, "_build_trans.dot");
      evmdd_print_dot(mdd_manager, r, f);
      fclose(f);
      ++nb_printed;
    }
    return r;
  case AST_DIVC:
    op1 = build_evmdd_from_ast(mdd_manager, t->node_content.node->l);
    evmdd_ref(mdd_manager, op1);
    r = evmdd_div_scalar(mdd_manager, op1, t->node_content.node->r->node_content.constant);
    evmdd_unref(mdd_manager, op1);
    if (dot_output) {
      printf("DOT build %d : ", nb_printed); ast_print(t); printf("\n");
      f = utils_nfopen(dot_output, nb_printed, "_build_trans.dot");
      evmdd_print_dot(mdd_manager, r, f);
      fclose(f);
      ++nb_printed;
    }
    return r;
  case AST_MODC:
    op1 = build_evmdd_from_ast(mdd_manager, t->node_content.node->l);
    evmdd_ref(mdd_manager, op1);
    r = evmdd_mod_scalar(mdd_manager, op1, t->node_content.node->r->node_content.constant);
    evmdd_unref(mdd_manager, op1);
    if (dot_output) {
      printf("DOT build %d : ", nb_printed); ast_print(t); printf("\n");
      f = utils_nfopen(dot_output, nb_printed, "_build_trans.dot");
      evmdd_print_dot(mdd_manager, r, f);
      fclose(f);
      ++nb_printed;
    }
    return r;
  case AST_CONST:
    r.value = t->node_content.constant;
    return r;
  case AST_POW:
  case AST_LT:
  case AST_EQ:
  case AST_NOT:
  case AST_OR:
  case AST_AND:
  case AST_SUB:
  case AST_EX:
  case AST_EG:
  case AST_EU:
    assert(0);  /* must be called on the result of normalize (see normalize.h) */
    return r;
  };

  return r;
}

mdd_level_index_t build_mdd_from_ast(mdd_manager_t *mdd_manager, struct ast *t)
{
  evmdd_edge_t evop;
  mdd_level_index_t op1, op2, r=0;
  
  switch (t->node_type) {
  case AST_LT:
    evop = build_evmdd_from_ast(mdd_manager, t->node_content.node->l);
    clock_global_stop();
    evmdd_ref(mdd_manager, evop);
    if (verbosity_level >= 3) {
      printf("  f in [%d, %ld]\n", evmdd_min(mdd_manager, evop), evmdd_max(mdd_manager, evop));
      printf("  Construction of EV+MDD: "); clock_global_print();
      printf("  number of nodes of resulting EV+MDD: %d\n",
             evmdd_num_nodes(mdd_manager, evop));
    }
    clock_global_start();
    r = evmdd_lt_scalar(mdd_manager, evop, t->node_content.node->r->node_content.constant);
    evmdd_unref(mdd_manager, evop);
    if (dot_output) {
      printf("DOT build %d : ", nb_printed); ast_print(t); printf("\n");
      f = utils_nfopen(dot_output, nb_printed, "_build_trans.dot");
      mdd_print_dot(mdd_manager, r, f);
      fclose(f);
      ++nb_printed;
    }
    return r;
  case AST_EQ:
    evop = build_evmdd_from_ast(mdd_manager, t->node_content.node->l);
    clock_global_stop();
    evmdd_ref(mdd_manager, evop);
    if (verbosity_level >= 3) {
      printf("  f in [%d, %ld]\n", evmdd_min(mdd_manager, evop), evmdd_max(mdd_manager, evop));
      printf("  Construction of EV+MDD: "); clock_global_print();
      printf("  number of nodes of resulting EV+MDD: %d\n",
             evmdd_num_nodes(mdd_manager, evop));
    }
    clock_global_start();
    r = evmdd_eq_scalar(mdd_manager, evop, t->node_content.node->r->node_content.constant);
    evmdd_unref(mdd_manager, evop);
    if (dot_output) {
      printf("DOT build %d : ", nb_printed); ast_print(t); printf("\n");
      f = utils_nfopen(dot_output, nb_printed, "_build_trans.dot");
      mdd_print_dot(mdd_manager, r, f);
      fclose(f);
      ++nb_printed;
    }
    return r;
  case AST_NOT:
    op1 = build_mdd_from_ast(mdd_manager, t->node_content.child);
    mdd_ref(mdd_manager, op1);
    r = mdd_not(mdd_manager, op1);
    mdd_unref(mdd_manager, op1);
    return r;
  case AST_OR:
    op1 = build_mdd_from_ast(mdd_manager, t->node_content.node->l);
    mdd_ref(mdd_manager, op1);
    op2 = build_mdd_from_ast(mdd_manager, t->node_content.node->r);
    mdd_ref(mdd_manager, op2);
    r = mdd_union(mdd_manager, op1, op2);
    mdd_unref(mdd_manager, op1);
    mdd_unref(mdd_manager, op2);
    return r;
  case AST_AND:
    op1 = build_mdd_from_ast(mdd_manager, t->node_content.node->l);
    mdd_ref(mdd_manager, op1);
    op2 = build_mdd_from_ast(mdd_manager, t->node_content.node->r);
    mdd_ref(mdd_manager, op2);
    r = mdd_inter(mdd_manager, op1, op2);
    mdd_unref(mdd_manager, op1);
    mdd_unref(mdd_manager, op2);
    if (dot_output) {
      printf("DOT build %d : ", nb_printed); ast_print(t); printf("\n");
      f = utils_nfopen(dot_output, nb_printed, "_build_trans.dot");
      mdd_print_dot(mdd_manager, r, f);
      fclose(f);
      ++nb_printed;
    }
    return r;
  case AST_CONST:
    if (t->node_content.constant)
      return mdd_const1(mdd_manager);
    else
      return mdd_const0(mdd_manager);
  case AST_MACRO:
       break;
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
    return r;
  };

  return r;
}

mdd_level_index_t solve_mdd_from_ast(mdd_manager_t *mdd_manager, struct ast *t)
{
  evmdd_edge_t evop;
  mdd_level_index_t op1, op2, r=0;
  
  switch (t->node_type) {
  case AST_LT:
    evop = build_evmdd_from_ast(mdd_manager, t->node_content.node->l);
    clock_global_stop();
    evmdd_ref(mdd_manager, evop);
    if (verbosity_level >= 3) {
      printf("  f in [%d, %ld]\n", evmdd_min(mdd_manager, evop), evmdd_max(mdd_manager, evop));
      printf("  Construction of EV+MDD: "); clock_global_print();
      printf("  number of nodes of resulting EV+MDD: %d\n",
             evmdd_num_nodes(mdd_manager, evop));
    }
    clock_global_start();
    r = evmdd_qlt_scalar(mdd_manager, evop, t->node_content.node->r->node_content.constant);
    evmdd_unref(mdd_manager, evop);
    return r;
  case AST_EQ:
    evop = build_evmdd_from_ast(mdd_manager, t->node_content.node->l);
    clock_global_stop();
    evmdd_ref(mdd_manager, evop);
    if (verbosity_level >= 3) {
      printf("  f in [%d, %ld]\n", evmdd_min(mdd_manager, evop), evmdd_max(mdd_manager, evop));
      printf("  Construction of EV+MDD: "); clock_global_print();
      printf("  number of nodes of resulting EV+MDD: %d\n",
             evmdd_num_nodes(mdd_manager, evop));
    }
    clock_global_start();
    r = evmdd_qeq_scalar(mdd_manager, evop, t->node_content.node->r->node_content.constant);
    evmdd_unref(mdd_manager, evop);
    return r;
  case AST_NOT:
    op1 = solve_mdd_from_ast(mdd_manager, t->node_content.child);
    mdd_ref(mdd_manager, op1);
    r = mdd_not(mdd_manager, op1);
    mdd_unref(mdd_manager, op1);
    return r;
  case AST_OR:
    op1 = solve_mdd_from_ast(mdd_manager, t->node_content.node->l);
    mdd_ref(mdd_manager, op1);
    if (op1==0) {
      op2 = solve_mdd_from_ast(mdd_manager, t->node_content.node->r);
      mdd_ref(mdd_manager, op2);
    }
    else op2 = 0;
    r = mdd_union(mdd_manager, op1, op2);
    mdd_unref(mdd_manager, op1);
    mdd_unref(mdd_manager, op2);
    return r;
  case AST_AND:
    op1 = build_mdd_from_ast(mdd_manager, t->node_content.node->l);
    mdd_ref(mdd_manager, op1);
    op2 = build_mdd_from_ast(mdd_manager, t->node_content.node->r);
    mdd_ref(mdd_manager, op2);
    r = mdd_inter(mdd_manager, op1, op2);
    mdd_unref(mdd_manager, op1);
    mdd_unref(mdd_manager, op2);
    return r;
  case AST_CONST:
    if (t->node_content.constant)
      return mdd_const1(mdd_manager);
    else
      return mdd_const0(mdd_manager);
  case AST_VAR:
  case AST_MACRO:
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
    return r;
  };

  return r;
}

mdd_level_index_t build_ctl(mdd_manager_t *mdd_manager, struct ast *t, mdd_level_index_t ss)
{
  evmdd_edge_t evop;
  mdd_level_index_t op1, op2, r=0;
  
  switch (t->node_type) {
  case AST_LT:
    evop = build_evmdd_from_ast(mdd_manager, t->node_content.node->l);
    evmdd_ref(mdd_manager, evop);
    op1 = evmdd_lt_scalar(mdd_manager, evop, t->node_content.node->r->node_content.constant);
    evmdd_unref(mdd_manager, evop);
    mdd_ref(mdd_manager, op1);
    r = mdd_inter(mdd_manager, op1, ss);
    mdd_unref(mdd_manager, op1);
    return r;
  case AST_EQ:
    evop = build_evmdd_from_ast(mdd_manager, t->node_content.node->l);
    evmdd_ref(mdd_manager, evop);
    op1 = evmdd_eq_scalar(mdd_manager, evop, t->node_content.node->r->node_content.constant);
    evmdd_unref(mdd_manager, evop);
    mdd_ref(mdd_manager, op1);
    r = mdd_inter(mdd_manager, op1, ss);
    mdd_unref(mdd_manager, op1);
    return r;
  case AST_NOT:
    op1 = build_ctl(mdd_manager, t->node_content.child, ss);
    mdd_ref(mdd_manager, op1);
    op2 = mdd_not(mdd_manager, op1);
    mdd_unref(mdd_manager, op1);
    mdd_ref(mdd_manager, op2);
    r = mdd_inter(mdd_manager, op2, ss);
    mdd_unref(mdd_manager, op2);
    return r;
  case AST_OR:
    op1 = build_ctl(mdd_manager, t->node_content.node->l, ss);
    mdd_ref(mdd_manager, op1);
    op2 = build_ctl(mdd_manager, t->node_content.node->r, ss);
    mdd_ref(mdd_manager, op2);
    r = mdd_union(mdd_manager, op1, op2);
    mdd_unref(mdd_manager, op1);
    mdd_unref(mdd_manager, op2);
    return r;
  case AST_AND:
    op1 = build_ctl(mdd_manager, t->node_content.node->l, ss);
    mdd_ref(mdd_manager, op1);
    op2 = build_ctl(mdd_manager, t->node_content.node->r, ss);
    mdd_ref(mdd_manager, op2);
    r = mdd_inter(mdd_manager, op1, op2);
    mdd_unref(mdd_manager, op1);
    mdd_unref(mdd_manager, op2);
    return r;
  case AST_CONST:
    if (t->node_content.constant)
      return ss;
    else
      return mdd_const0(mdd_manager);
  case AST_EX:
    op1 = build_ctl(mdd_manager, t->node_content.child, ss);
    mdd_ref(mdd_manager, op1);
    op2 = ctl_EX(mdd_manager, op1);
    mdd_unref(mdd_manager, op1);
    mdd_ref(mdd_manager, op2);
    r = mdd_inter(mdd_manager, op2, ss);
    mdd_unref(mdd_manager, op2);
    return r;
  case AST_EG:
    op1 = build_ctl(mdd_manager, t->node_content.child, ss);
    mdd_ref(mdd_manager, op1);
    r = ctl_EG(mdd_manager, op1);
    mdd_unref(mdd_manager, op1);
    return r;
  case AST_EU:
    op1 = build_ctl(mdd_manager, t->node_content.node->l, ss);
    mdd_ref(mdd_manager, op1);
    op2 = build_ctl(mdd_manager, t->node_content.node->r, ss);
    mdd_ref(mdd_manager, op2);
    r = ctl_EU(mdd_manager, op1, op2);
    mdd_unref(mdd_manager, op1);
    mdd_unref(mdd_manager, op2);
    return r;
  case AST_VAR:
  case AST_MACRO:
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
    return r;
  };

  return r;
}
