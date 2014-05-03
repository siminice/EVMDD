#ifndef MDD_MANAGER_PRIV_H
#define MDD_MANAGER_PRIV_H

#include "mdd_manager.h"

/* here, we assume that this will fit in a 32 bits (at least) int */
typedef enum {MDD_NODE_ALLOCATED      =(int)0x80000000,
              /* used for garbage collection and useful for lot of things (e.g. BFS),
               * must be reinitialized at 0 after usage */
              MDD_NODE_MARK           =(int)0x40000000,
              /* this reference count are only from the exterior of the package
               * (we don't maintain any reference count internally)
               * in practice, they are also used to temporaly protect
               * a newly created node from garbage collection */
              MDD_NODE_REFERENCE_COUNT=(int)0x3fffffff} mdd_node_flags_t;

typedef enum {MDD_O_VAR,
              MDD_O_NOT,
              MDD_O_UNION,
              MDD_O_INTER,
              MDD_O_NEXT,
              MDD_O_PREV,
              MDD_O_FIRE,
              MDD_O_FIRE_DIST,
              MDD_O_FIRE_DIST2,
              MDD_O_FIRE_BOUND,
              MDD_O_ADD,
              MDD_O_MULT,
              MDD_O_MOD,
              MDD_O_MULT_SCALAR_P,
              MDD_O_MULT_SCALAR_N,
              MDD_O_DIV_SCALAR,
              MDD_O_MOD_SCALAR,
              MDD_O_DIV,
              MDD_O_LT,
              MDD_O_EQ,
              MDD_O_QLT,
              MDD_O_QEQ,
              MDD_O_EVMDD_FROM_MDD,
              MDD_O_MAX,
              MDD_O_MAX_FINITE,
              MDD_O_CARDINAL,
              MDD_O_CARDINAL_EVMDD,
              MDD_O_ADD_IDENTITIES,
              MDD_O_UNREDUCE,
              MDD_O_REDUCE,
              MDD_O_UNREDUCE_DIST,
              MDD_O_UNREDUCE_EVMDD_DIST,
              MDD_O_UNION_UNREDUCED,
              MDD_O_UNION_MIN,
              MDD_O_UNION_IDENTITY_REDUCED,
              MDD_O_BOUND,
              MDD_O_READ,
              MDD_O_READ_EVMDD,
              MDD_O_NB} mdd_ops_t;

struct mdd_manager {
  /* total number of variables */
  int nb_levels;
  /* levels k and index i are packed together in a long
   * level_index = k << level_shift | i
   * so level_shift is the greatest integer such that
   * 2*nb_levels << level_shift can fit in a long
   * and index_mask is just (1 << level_shift)-1 */
  int level_shift;
  int index_mask;
  /* name of variables (can be NULL), indexed from 1 to nb_levels */
  char **var_names;
  /* minimum value of each variable, indexed from 1 to nb_levels */
  int *lower_bounds;
  /* ranges of each variable, indexed from 1 to nb_levels and ranges[0] = 0
     (i.e. number of values the variable can take),
     so variable i (i in [1, nb_levels]) take values
     lower_bounds[i]..(lower_bounds[i]+ranges[i]-1) */
  int *ranges;
  /* current memory allocated size (in bytes) */
  unsigned long currently_allocated;
  /* if currently_allocated becomes greater than this threshold (in bytes), launch garbage collection
   * special value -1 means never launch garbage collection */
  unsigned long gc_threshold;
  /* currently_allocated should not go above this threshold
   * special value -1 means don't care */
  unsigned long memlimit;
  /* events (for computation of reachable states) by top level affected by the event */
  struct event_entry **events;
  /* union of all events in one */
  mdd_level_index_t all_events;
  /* nodes arranged by level */
  struct mdd_node_storage *mdd_nodes;
  struct evmdd_node_storage *evmdd_nodes;
  /* unique tables arranged by level */
  struct unique_table *mdd_unique_tables;
  struct unique_table *evmdd_unique_tables;
  /* caches by operations (mdd_ops_t) then level */
  union cache *caches[MDD_O_NB];
  /* only for statistics, count of lookups in cache and unique table */
  unsigned nb_cache_worst;
  unsigned long nb_cache_lookup_entries;
  unsigned long nb_cache_lookups;
  unsigned nb_unique_table_worst;
  unsigned long nb_unique_table_lookup_entries;
  unsigned long nb_unique_table_lookups;
};

#pragma GCC diagnostic ignored "-Wunused-function"

static mdd_level_t mdd_level(mdd_manager_t *manager, mdd_level_index_t p)
{
  return p >> manager->level_shift;
}

static mdd_level_t mdd_index(mdd_manager_t *manager, mdd_level_index_t p)
{
  return p & manager->index_mask;
}

static mdd_level_index_t mdd_level_index(mdd_manager_t *manager, mdd_level_t k, mdd_index_t i)
{
  return (k << manager->level_shift) | i;
}

#endif /* MDD_MANAGER_PRIV_H */
