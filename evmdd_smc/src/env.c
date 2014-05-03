#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "env.h"

/* var name is in the interval [lb, ub] */
struct var {
  char *name;
  int lb;
  int ub;
};

/* macro def: [identifer =] expr */
struct macrodef {
  char *name;
  int  root;
  void *body;
};

static struct var env[ENV_SIZE];
static struct macrodef mdf[ENV_SIZE];

/* other ast storage */

static struct macrodef inits[ENV_SIZE];
static struct macrodef events[ENV_SIZE];
static struct macrodef equations[ENV_SIZE];

static int nb_var=0;
static int nm_def=0;
static int n_ini=0;
static int n_evt=0;
static int n_eqn=0;

int env_put(char *name, int lb, int ub)
{
  ++nb_var;

  if (nb_var >= ENV_SIZE) {
    fprintf(stderr, "Error: variable environment is full (limited to ENV_SIZE = %d, modify in %s and recompile).\n", ENV_SIZE, __FILE__);
    exit(1);
  }

  env[nb_var].name = name;
  env[nb_var].lb = lb;
  env[nb_var].ub = ub;

  return nb_var;
}

int  env_is_in(char *name, int *lb, int *ub)
{
  int i;

  /* probably not the better way to do it
     (should use a hash table instead) but still works */
  for (i = 1; i <= nb_var; ++i)
    if (strcmp(name, env[i].name) == 0) {
      if (lb != NULL) *lb = env[i].lb;
      if (ub != NULL) *ub = env[i].ub;
      return i;
    }

  return 0;  /* not found */
}

char *env_name(int id, int *lb, int *ub)
{
  if (id < 1 || id > nb_var)
    return NULL;

  if (lb != NULL) *lb = env[id].lb;
  if (ub != NULL) *ub = env[id].ub;
  return env[id].name;
}

int env_size()
{
  return nb_var;
}

void env_reorder(int *order) {
  int *nlb = (int*)malloc((nb_var+1)*sizeof(int));
  int *nub = (int*)malloc((nb_var+1)*sizeof(int));
  char **nnm = (char**)malloc((nb_var+1)*sizeof(char*));
  int i;
  for (i=1; i<=nb_var; i++) {
    nlb[i] = env[order[i]].lb;
    nub[i] = env[order[i]].ub;
    nnm[i] = env[order[i]].name;
  }
  for (i=1; i<=nb_var; i++) {
    env[i].lb = nlb[i];
    env[i].ub = nub[i];
    env[i].name = nnm[i];
  }
  free(nlb);
  free(nub);
  free(nnm);
}

void env_read_vorder(char *filename, int *vo) {
  FILE *fvo;
  char s[4096], *vn;
  int i, vi;

  fvo = fopen(filename, "rt");
  if (fvo==NULL) {
    fprintf(stderr, "ERROR: variable order file %s not found.\n", filename);
    return;
  }
  fgets(s, 4096, fvo);
  for (i=1; i<=nb_var; i++) {
    if (i==1) {
      vn = strtok(s, " \t\n");
    }
    else {
      vn = strtok(NULL, " \t\n");
    }
    vi = env_is_in(vn, NULL, NULL);
    if (vi==0) {
      fprintf(stderr, "ERROR: variable %s not defined.\n", vn);
    }
    else {
      vo[i] = vi;
    }
  }
  fclose(fvo);
}

void env_free()
{
  while (nb_var) {
    free(env[nb_var].name);
    --nb_var;
  }
}

/* ---------------------------------- */

int mdf_put(char *name, void *body)
{
  ++nm_def;

  if (nm_def >= ENV_SIZE) {
    fprintf(stderr, "Error: macro definition environment is full (limited to ENV_SIZE = %d, modify in %s and recompile).\n", ENV_SIZE, __FILE__);
    exit(1);
  }

  mdf[nm_def].name = name;
  mdf[nm_def].root = 0;
  mdf[nm_def].body = body;

  return nm_def;
}

int  mdf_is_in(char *name, int *r, void **body)
{
  int i;

  for (i = 1; i <= nm_def; ++i)
    if (strcmp(name, mdf[i].name) == 0) {
      if (r)    *r    = mdf[i].root;
      if (body) *body = mdf[i].body;
      return i;
    }

  return 0;  /* not found */
}

int mdf_set_root(int x, int r) {
  if (x<1 || x>nm_def) return 0;
  mdf[x].root = r;
  return 1;
}

int mdf_get_root(char *name, int *r) {
  void **bod;
  int x, *dummy;
  r = 0;
  x = mdf_is_in(name, dummy, bod);
  if (x==0) return 0;
  *r = mdf[x].root;
  return 1;
}

char *mdf_get_name(int id)
{
  if (id < 1 || id > nm_def)
    return NULL;

  return mdf[id].name;
}

void *mdf_get_body(int id) {
  if (id<1 || id> nm_def) 
    return NULL;
  return mdf[id].body;
}

int mdf_size()
{
  return nm_def;
}

void mdf_free()
{
  while (nm_def) {
    free(mdf[nm_def].name);
    --nm_def;
  }
}

/* ----------------------------------------- */
int init_put(void *expr) {
  n_ini++;
  if (n_ini >= ENV_SIZE) {
    fprintf(stderr, "Error: too many initial states expressions (limited to ENV_SIZE = %d, modify in %s and recompile).\n", ENV_SIZE, __FILE__);
    exit(1);
  }
  inits[n_ini].body = expr;
  return n_ini;
}

void* init_get_body(int id) {
  if (id<1 || id> n_ini) 
    return NULL;
  return inits[id].body;
}

int num_inits() {
  return n_ini;
}

int event_put(char *name, void *expr) {
  n_evt++;
  if (n_evt >= ENV_SIZE) {
    fprintf(stderr, "Error: too many events declared (limited to ENV_SIZE = %d, modify in %s and recompile).\n", ENV_SIZE, __FILE__);
    exit(1);
  }
  events[n_evt].name = name;
  events[n_evt].body = expr;
  return n_evt;
}

char* event_get_name(int id) {
  if (id<1 || id> n_evt) 
    return NULL;
  return events[id].name;
}

void* event_get_body(int id) {
  if (id<1 || id> n_evt) 
    return NULL;
  return events[id].body;
}

int num_events() {
  return n_evt;
}

int equation_put(char *name, void *expr) {
  n_eqn++;
  if (n_eqn >= ENV_SIZE) {
    fprintf(stderr, "Error: too many events declared (limited to ENV_SIZE = %d, modify in %s and recompile).\n", ENV_SIZE, __FILE__);
    exit(1);
  }
  equations[n_eqn].name = name;
  equations[n_eqn].body = expr;
  return n_eqn;
}

char* equation_get_name(int id) {
  if (id<1 || id> n_eqn) 
    return NULL;
  return equations[id].name;
}

void* equation_get_body(int id) {
  if (id<1 || id> n_eqn) 
    return NULL;
  return equations[id].body;
}

int num_equations() {
  return n_eqn;
}
