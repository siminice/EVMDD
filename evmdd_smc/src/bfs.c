#include "bfs.h"
#include <evmdd/mdd_node.h>
#include <evmdd/mdd_node.h>
#include <evmdd/events.h>
#include <evmdd/mdd_ops.h>

extern int verbosity_level;

mdd_level_index_t bfs_chaining(mdd_manager_t *manager, mdd_level_index_t s)
{
  mdd_level_index_t r=s, prevr, oldr;
  event_entry_t *e, **events=mdd_manager_get_events(manager);
  int k, nb_levels=mdd_manager_get_nb_levels(manager);
  int nb_iterations=0;

  do {
    oldr = r;
    for (k = 1; k <= nb_levels; ++k) {
      e = events[k];
      while (e) {
        prevr = r;
        mdd_ref(manager, prevr);
        r = mdd_add_next(manager, prevr, e->data);
        mdd_unref(manager, prevr);
        e = e->next;
      }
    }
    ++nb_iterations;
    fprintf(stderr, "%s/%d: BFS: iteration #%d completed\n", __FILE__, __LINE__, nb_iterations);
    fprintf(stderr, "Number of states: ");
    bigint_print(mdd_num_encoded_elements(manager, r), stderr);
    fprintf(stderr, "\n");
  } while (r != oldr);

  fprintf(stderr, "%s/%d: BFS: %d iterations\n", __FILE__, __LINE__, nb_iterations);

  return r;
}

mdd_level_index_t bfs(mdd_manager_t *manager, mdd_level_index_t s, int bound)
{
  mdd_level_index_t f, r, oldr, next;
  int nb_iterations = 0;

  r = s;
  mdd_ref(manager, r);
  f = mdd_manager_get_all_events(manager);

  do {
    oldr = r;
    next = mdd_next(manager, oldr, f);
    mdd_ref(manager, next);
    r = mdd_union(manager, oldr, next);
    mdd_ref(manager, r);
    mdd_unref(manager, next);
    mdd_unref(manager, oldr);
    ++nb_iterations;
    fprintf(stderr, "%s/%d: BFS: iteration #%d completed\n", __FILE__, __LINE__, nb_iterations);
    fprintf(stderr, "Number of states: ");
    bigint_print(mdd_num_encoded_elements(manager, r), stderr);
    fprintf(stderr, "\n");
  } while (r != oldr && (bound <= 0 || nb_iterations < bound));

  mdd_unref(manager, r);

  return r;
}

mdd_level_index_t strict_bfs(mdd_manager_t *manager, mdd_level_index_t s, int bound)
{
  mdd_level_index_t r=mdd_const0(manager), oldr, notoldr, next, frontier=s, oldfrontier, f;
  int nb_iterations = 0;

  f = mdd_manager_get_all_events(manager);
  mdd_ref(manager, f);

  do {
    oldr = r;
    mdd_ref(manager, oldr);
    oldfrontier = frontier;
    mdd_ref(manager, oldfrontier);
    next = mdd_next(manager, oldfrontier, f);
    mdd_ref(manager, next);
    notoldr = mdd_not(manager, oldr);
    mdd_ref(manager, notoldr);
    frontier = mdd_inter(manager, notoldr, next);
    mdd_ref(manager, frontier);
    mdd_unref(manager, notoldr);
    mdd_unref(manager, next);
    r = mdd_union(manager, oldr, frontier);
    mdd_ref(manager, r);
    mdd_unref(manager, oldr);
    mdd_unref(manager, oldfrontier);
    mdd_ref(manager, r);
    mdd_unref(manager, frontier);
    ++nb_iterations;
    fprintf(stderr, "%s/%d: BFS: iteration #%d completed\n", __FILE__, __LINE__, nb_iterations);
    fprintf(stderr, "Number of states: ");
    bigint_print(mdd_num_encoded_elements(manager, r), stderr);
    fprintf(stderr, "\n");
  } while (r != oldr && (bound <= 0 || nb_iterations < bound));

  mdd_unref(manager, f);

  fprintf(stderr, "%s/%d: BFS: %d iterations\n", __FILE__, __LINE__, nb_iterations);

  return r;
}
