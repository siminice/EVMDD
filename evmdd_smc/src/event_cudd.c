#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_CUDD

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "event_cudd.h"

struct event_cudd {
  char *name;
  DdNode *bdd;
};

#define EVENT_CUDD_SIZE 2048

static struct event_cudd env[EVENT_CUDD_SIZE];
static int nb_event=0;

int event_cudd_put(char *name, DdNode *n)
{
  ++nb_event;

  if (nb_event >= EVENT_CUDD_SIZE) {
    fprintf(stderr, "Error: event environment is full (limited to EVENT_CUDD_SIZE = %d, modify in %s and recompile).\n", EVENT_CUDD_SIZE, __FILE__);
    exit(1);
  }

  env[nb_event].name = name;
  env[nb_event].bdd = n;

  Cudd_Ref(n);
    
  return nb_event;
}

char *envent_cudd_name(int id)
{
  if (id < 1 || id > nb_event)
    return NULL;

  return env[id].name;
}

DdNode *event_cudd_bdd(int id)
{
  if (id < 1 || id > nb_event)
    return NULL;

  return env[id].bdd;
}

int event_cudd_size()
{
  return nb_event;
}

void event_cudd_free(DdManager *manager)
{
  while (nb_event) {
    free(env[nb_event].name);
    Cudd_RecursiveDeref(manager, env[nb_event].bdd);
    --nb_event;
  }
}

#endif /* HAVE_CUDD */
