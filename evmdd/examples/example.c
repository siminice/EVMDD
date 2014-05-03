#include <stdio.h>
#include <evmdd/evmdd.h>

int main(int argc, char *argv[])
{
  /* one variable x ranging from 2 to 9 included */
  int lower_bounds[] = {0,  2};
  int ranges[]       = {0,  8};
  char *var_names[]  = {"", "x"};

  /* building manager */
  t_mdd_manager *manager = mdd_manager_new(1, lower_bounds, ranges);
  mdd_manager_set_var_names(mdd_manager, var_names);

  t_evmdd_edge x, xp, xP2, MxP2, xpMxP2;
  t_mdd_level_index initial_state, xpExP2, state_space;

  /* building initial state x = 4 */
  x = evmdd_var_new(manager, 1, MDD_FROM);
  evmdd_ref(manager, x);
  initial_state = evmdd_eq(manager, x, 4);
  mdd_ref(manager, initial_state);

  /* building transition relation x' = x+2 */
  xP2 = evmdd_add_scalar(manager, x, 2);
  evmdd_ref(manager, xP2);
  evmdd_unref(manager, x);
  MxP2 = evmdd_mult_scalar(manager, xP2, -1);
  evmdd_ref(manager, MxP2);
  evmdd_unref(manager, xP2);
  xp = evmdd_var_new(manager, 1, MDD_TO);
  evmdd_ref(manager, xp);
  xpMxP2 = evmdd_add(manager, xp, MxP2);
  evmdd_ref(manager, xpMxP2);
  evmdd_unref(manager, xp);
  evmdd_unref(manager, MxP2);
  xpExP2 = evmdd_eq(manager, xpMxP2, 0);
  mdd_ref(manager, xpExP2);
  evmdd_unref(manager, xpMxP2);

  /* registering transition relation */
  event_register(manager, xpExP2, NULL);
  mdd_unref(manager, xpExP2);

  /* computing state space */
  state_space = saturate(manager, initial_state);
  mdd_ref(manager, state_space);
  mdd_unref(manager, initial_state);

  /* outputing state space as a dot graph */
  mdd_print_dot(manager, state_space, stdout);

  mdd_unref(manager, state_space);

  /* releasing manager */
  mdd_manager_free(manager);

  return 0;
}
