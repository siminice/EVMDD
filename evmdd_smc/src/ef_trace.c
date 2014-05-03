#include "ef_trace.h"

void ef_trace(mdd_manager_t *manager,
              evmdd_edge_t evmdd_state_space,
              mdd_level_index_t goal)
{
  evmdd_edge_t evmdd_goal_0_1, evmdd_goal, evmdd_goal_pos;
  evmdd_edge_t evmdd_goal_0, evmdd_goal_max;
  mdd_level_index_t mdd_goal_0;
  int i, max, trace_length;
  mdd_level_index_t oldr, r, prev, s;

  if (!goal) return;

  printf("EF trace (first is a nearest state satisfying property, then a trace backward to an initial state):\n");

  /* find length of the shortest trace
     (this may appear a bit tricky since if we direclty compute
     min(evmdd_state_space*goal) we would just get 0) */

  evmdd_goal_0_1 = evmdd_from_mdd(manager, goal);
  evmdd_ref(manager, evmdd_goal_0_1);
  evmdd_goal = evmdd_mult(manager, evmdd_state_space, evmdd_goal_0_1);
  evmdd_ref(manager, evmdd_goal);  /* evmdd_state_space*goal */
  evmdd_unref(manager, evmdd_goal_0_1);
  mdd_goal_0 = evmdd_lt_scalar(manager, evmdd_goal, 1);
  mdd_ref(manager, mdd_goal_0);
  evmdd_goal_0 = evmdd_from_mdd(manager, mdd_goal_0);
  evmdd_ref(manager, evmdd_goal_0);
  mdd_unref(manager, mdd_goal_0);
  max = evmdd_max(manager, evmdd_goal);
  evmdd_goal_max = evmdd_mult_scalar(manager, evmdd_goal_0, max);
  evmdd_ref(manager, evmdd_goal_max);  /* max(evmdd_goal)*(evmdd_goal == 0) */
  evmdd_unref(manager, evmdd_goal_0);
  evmdd_goal_pos = evmdd_add(manager, evmdd_goal, evmdd_goal_max);
  evmdd_ref(manager, evmdd_goal_pos);  /* evmdd_goal+max(evmdd_goal)*(evmdd_goal == 0) */
  evmdd_unref(manager, evmdd_goal_max);
  evmdd_unref(manager, evmdd_goal);
  trace_length = evmdd_min(manager, evmdd_goal_pos);
  printf("Found trace of length %d.\n", trace_length);
  evmdd_unref(manager, evmdd_goal_pos);

  /* compute set of states of goal at distance trace_length */
  oldr = evmdd_eq_scalar(manager, evmdd_state_space, trace_length);
  mdd_ref(manager, oldr);
  r = mdd_inter(manager, oldr, goal);
  mdd_ref(manager, r);
  mdd_unref(manager, oldr);

  for (i = trace_length; i; --i) {
    oldr = r;

    /* extract a state s and print it */
    s = mdd_choose(manager, oldr);
    mdd_ref(manager, s);
    mdd_unref(manager, oldr);
    printf("distance %d:\n", i);
    mdd_print_states(manager, s, 1);

    /* compute predecessors of s at distance i-1 from initial states */
    prev = mdd_prev(manager, s, mdd_manager_get_all_events(manager));
    mdd_ref(manager, prev);
    mdd_unref(manager, s);
    oldr = evmdd_lt_scalar(manager, evmdd_state_space, i);
    mdd_ref(manager, oldr);
    r = mdd_inter(manager, oldr, prev);
    mdd_ref(manager, r);
    mdd_unref(manager, oldr);
    mdd_unref(manager, prev);
  }

  /* extract an initial state s and print it */
  s = mdd_choose(manager, r);
  mdd_ref(manager, s);
  mdd_unref(manager, r);
  printf("distance 0 (initial state):\n");
  mdd_print_states(manager, s, 1);
  mdd_unref(manager, s);
}
