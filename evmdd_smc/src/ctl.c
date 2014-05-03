#include "ctl.h"
#include <evmdd/mdd_node.h>
#include <evmdd/mdd_ops.h>
#include <evmdd/events.h>

extern int verbosity_level;

mdd_level_index_t ctl_EX(mdd_manager_t *manager, mdd_level_index_t s)
{
  return mdd_prev(manager, s, mdd_manager_get_all_events(manager));
}

mdd_level_index_t ctl_EG(mdd_manager_t *manager, mdd_level_index_t s)
{
  mdd_level_index_t r=s, oldr, tmp;
  int nb_iterations=0;

  do {
    oldr = r;
    mdd_ref(manager, oldr);
    tmp = ctl_EX(manager, oldr);
    mdd_unref(manager, oldr);
    mdd_ref(manager, tmp);
    r = mdd_inter(manager, tmp, s);
    mdd_unref(manager, tmp);
    ++nb_iterations;
  } while (r != oldr);

  if (verbosity_level) 
  fprintf(stderr, "%s/%d: ctl_EG: %d iterations\n", __FILE__, __LINE__, nb_iterations);

  return r;
}

mdd_level_index_t ctl_EU(mdd_manager_t *manager, mdd_level_index_t s1, mdd_level_index_t s2)
{
  mdd_level_index_t r=s2, oldr, tmp;
  int nb_iterations=0;
  mdd_level_index_t s1Us2 = mdd_union(manager, s1, s2);

  mdd_ref(manager, s1Us2);
  do {
    oldr = r;
    mdd_ref(manager, oldr);
    tmp = mdd_add_prev(manager, oldr, mdd_manager_get_all_events(manager));
    mdd_unref(manager, oldr);
    mdd_ref(manager, tmp);
    r = mdd_inter(manager, tmp, s1Us2);
    mdd_unref(manager, tmp);
    ++nb_iterations;
  } while (r != oldr);
  mdd_unref(manager, s1Us2);

  if (verbosity_level)
  fprintf(stderr, "%s/%d: ctl_EU: %d iterations\n", __FILE__, __LINE__, nb_iterations);

  return r;
}
