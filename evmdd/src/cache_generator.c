#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********************
 * type definitions *
 ********************/

typedef enum {F_MDD, F_EVMDD, F_VAL, F_LVAL, F_BIGINT} cache_field_t;

typedef struct cache_desc {
  char *name;
  int nb_inputs;
  cache_field_t *inputs;
  int nb_outputs;
  cache_field_t *outputs;
} cache_desc_t;

/********************
 * global variables *
 ********************/

static char *input_file;
static char *filename_h;
static char *filename_c;

static cache_desc_t caches[128];

/*********************
 * parsing functions *
 *********************/

/* "mdd" -> F_MDD, "evmdd" -> F_EVMDD,..." */
static cache_field_t parse_type(char *s, int ln)
{
  if (!strcmp(s, "mdd")) return F_MDD;
  else if (!strcmp(s, "evmdd")) return F_EVMDD;
  else if (!strcmp(s, "val")) return F_VAL;
  else if (!strcmp(s, "lval")) return F_LVAL;
  else if (!strcmp(s, "bigint")) return F_BIGINT;
  else {
    fprintf(stderr, "ERROR: line %d: unknown type of entry '%s'.\n", ln, s);
    exit(1);
  }
}

/* parse lines like "name: in0, in1, in2 -> out0, out1"
 * /no/ space before ':' */
static void parse_line(int n, char *s, int ln)
{
  char *str1, *str2, *token, *subtoken;
  char *saveptr1, *saveptr2;
  int i, j;

  for (i=0, str1 = s; ; ++i, str1=NULL) {
    token = strtok_r(str1, ":->", &saveptr1);
    if (token == NULL) break;
    switch (i) {
    case 0:  /* name */
      caches[n].name = strdup(token);
      break;
    case 1:  /* inputs */
      caches[n].inputs = malloc(64*sizeof(cache_field_t));
      for (j = 0, str2 = token; ; ++j, str2 = NULL) {
        subtoken = strtok_r(str2, ", ", &saveptr2);
        if (subtoken == NULL) break;
        caches[n].inputs[j] = parse_type(subtoken, ln);
      }
      caches[n].nb_inputs = j;
      break;
    case 2:  /* outputs */
      caches[n].outputs = malloc(64*sizeof(cache_field_t));
      for (j = 0, str2 = token; ; ++j, str2 = NULL) {
        subtoken = strtok_r(str2, ", \n", &saveptr2);
        if (subtoken == NULL) break;
        caches[n].outputs[j] = parse_type(subtoken, ln);
      }
      caches[n].nb_outputs = j;
      break;
    default:
      fprintf(stderr, "ERROR: line %d: don't know what to do with '%s'.\n", ln, token);
      exit(1);
      break;
    }
  }
}

static void parse(FILE *f)
{
  char s[65536];
  int i=0, ln=0;

  while (!feof(f)) {
    fgets(s, 65535, f);
    ++ln;
    if (feof(f)) continue;
    /* allow comments with # as /first/ character of the line */
    if (s[0] == '#') continue;
    parse_line(i, s, ln);
    ++i;
  }

  caches[i].name = NULL;
}

/*****************************
 * code generation functions *
 *****************************/

static void generate_header(FILE *fc, FILE *fh)
{
  fprintf(fc, "\
/* This file was generated by cache_generator from %s, do not edit! */\n\
\n\
#include <stdlib.h>\n\
#include <stdio.h>\n\
#include <assert.h>\n\
#include \"mdd_manager_priv.h\"\n\
#include \"cache_priv.h\"\n\
#include \"mdd_utils_priv.h\"\n\
#include \"mdd_node_priv.h\"\n\
#include \"evmdd_node_priv.h\"\n\
#include \"bigint_priv.h\"\n\
\n\
#define CACHE_INITIAL_SIZE 37\n\
#define CACHE_MAX_AVERAGE_PER_ENTRY 2\n\
\n\
", input_file);

  fprintf(fh, "\
/* This file was generated by cache_generator from %s, do not edit! */\n\
\n\
#ifndef CACHE_PRIV_H\n\
#define CACHE_PRIV_H\n\
\n\
#include \"mdd_manager_priv.h\"\n\
#include \"bigint.h\"\n\
\n\
", input_file);
}

static void generate_footer(FILE *fc, FILE *fh)
{
  fprintf(fh, "\n#endif /* CACHE_PRIV_H */\n");
}

static char *string_of_type(cache_field_t t)
{
  switch (t) {
  case F_MDD: return "mdd_level_index_t";
  case F_EVMDD: return "mdd_level_index_t";
  case F_VAL: return "int";
  case F_LVAL: return "long";
  case F_BIGINT: return "bigint_t *";
  }

  return "";
}

static void generate_types(FILE *fc, FILE *fh)
{
  int i, j;

  for (i = 0; caches[i].name; ++i) {
    fprintf(fh, "\
typedef struct cache_%s_entry {\n\
", caches[i].name);
    for (j = 0; j < caches[i].nb_inputs; ++j) {
      fprintf(fh, "\
  %s in_%d;\n\
", string_of_type(caches[i].inputs[j]), j);
    }
    for (j = 0; j < caches[i].nb_outputs; ++j) {
      fprintf(fh, "\
  %s out_%d;\n\
", string_of_type(caches[i].outputs[j]), j);
    }
    fprintf(fh, "\
  struct cache_%s_entry *next;\n\
} cache_%s_entry_t;\n\
\n\
", caches[i].name, caches[i].name);
    fprintf(fh, "\
typedef struct cache_%s {\n\
  unsigned int size;\n\
  unsigned int nb_elements;\n\
  cache_%s_entry_t **table;\n\
} cache_%s_t;\n\
\n\
", caches[i].name, caches[i].name, caches[i].name);
  }

  fprintf(fh, "\
typedef union cache {\n\
");
  for (i = 0; caches[i].name; ++i) {
    fprintf(fh, "\
  cache_%s_t %s;\n\
", caches[i].name, caches[i].name);
  }
  fprintf(fh, "\
} cache_t;\n\
\n\
");
}

static void generate_init(FILE *fc, FILE *fh)
{
  int i;

  for (i = 0; caches[i].name; ++i) {
    fprintf(fc, "\
static void cache_%s_init(mdd_manager_t *manager, mdd_level_t k)\n\
{\n\
  cache_%s_t *cache = &(manager->caches[MDD_O_%s][k].%s);\n\
\n\
  cache->size = mdd_utils_next_prime(CACHE_INITIAL_SIZE);\n\
  cache->nb_elements = 0;\n\
  cache->table = calloc(cache->size, sizeof(cache_%s_entry_t *));\n\
  manager->currently_allocated += cache->size*sizeof(cache_%s_entry_t *);\n\
", caches[i].name, caches[i].name, caches[i].name, caches[i].name, caches[i].name, caches[i].name);
    fprintf(fc, "\
  if (cache->table == NULL) {\n                            \
    fprintf(stderr, \"%%s/%%d: Unable to allocate %%u byte of memory.\\n\", __FILE__, __LINE__, cache->size*(unsigned)sizeof(cache_%s_entry_t *));\n\
    exit(1);\n\
  }\n\
}\n\
\n\
", caches[i].name);
  }

  fprintf(fc, "\
void cache_init(mdd_manager_t *manager, mdd_ops_t op, mdd_level_t k)\n\
{\n\
  switch (op) {\n\
");
  for (i = 0; caches[i].name; ++i) {
    fprintf(fc, "\
  case MDD_O_%s:\n\
    cache_%s_init(manager, k);\n\
    break;\n\
", caches[i].name, caches[i].name);
  }
  fprintf(fc, "\
  case MDD_O_NB:\n\
    break;\n\
  }\n\
}\n\
\n\
");

  fprintf(fh, "\
void cache_init(mdd_manager_t *, mdd_ops_t, mdd_level_t);\n\
\n\
");
}

static void generate_free(FILE *fc, FILE *fh)
{
  int i, j;

  for (i = 0; caches[i].name; ++i) {
    fprintf(fc, "\
static int cache_%s_free(mdd_manager_t *manager, mdd_level_t k)\n\
{\n\
  cache_%s_t *cache = &(manager->caches[MDD_O_%s][k].%s);\n\
  unsigned int i;\n\
  cache_%s_entry_t *entry, *next_entry;\n\
\n\
  int sz_entries = 0;\n\
\n\
  for (i = 0; i < cache->size; ++i) {\n\
    entry = cache->table[i];\n\
    while (entry) {\n\
", caches[i].name, caches[i].name, caches[i].name, caches[i].name, caches[i].name);
    for (j = 0; j < caches[i].nb_inputs; ++j)
      if (caches[i].inputs[j] == F_BIGINT)
        fprintf(fc, "      bigint_free(entry->in_%d);\n", j);
    for (j = 0; j < caches[i].nb_outputs; ++j)
      if (caches[i].outputs[j] == F_BIGINT)
        fprintf(fc, "      bigint_free(entry->out_%d);\n", j);
    fprintf(fc, "\
      manager->currently_allocated -= sizeof(cache_%s_entry_t)+8;\n\
\n\
      sz_entries += sizeof(cache_%s_entry_t)+8;\n\
\n\
      next_entry = entry->next;\n\
      free(entry);\n\
      entry = next_entry;\n\
    }\n\
  }\n\
\n\
  manager->currently_allocated -= cache->size*sizeof(cache_%s_entry_t *);\n\
  free(cache->table);\n\
\n\
  return sz_entries;\n\
}\n\
\n\
", caches[i].name, caches[i].name, caches[i].name);
  }

  fprintf(fc, "\
int cache_free(mdd_manager_t *manager, mdd_ops_t op, mdd_level_t k)\n\
{\n\
  switch (op) {\n\
");
  for (i = 0; caches[i].name; ++i) {
    fprintf(fc, "\
  case MDD_O_%s:\n\
    return cache_%s_free(manager, k);\n\
", caches[i].name, caches[i].name);
  }
  fprintf(fc, "\
  case MDD_O_NB:\n\
    break;\n\
  }\n\
\n\
  return 0;\n\
}\n\
\n\
");

  fprintf(fh, "\
int cache_free(mdd_manager_t *, mdd_ops_t, mdd_level_t);\n\
\n\
");
}

static void generate_malloc_statistics(FILE *fc, FILE *fh)
{
  int i;

  for (i = 0; caches[i].name; ++i) {
    fprintf(fc, "\
static int cache_%s_malloc_statistics(mdd_manager_t *manager, mdd_level_t k)\n\
{\n\
  cache_%s_t *cache = &(manager->caches[MDD_O_%s][k].%s);\n\
  unsigned int i;\n\
  cache_%s_entry_t *entry, *next_entry;\n\
\n\
  int sz_entries = 0;\n\
\n\
  for (i = 0; i < cache->size; ++i) {\n\
    entry = cache->table[i];\n\
    while (entry) {\n\
      sz_entries += 8;\n\
      next_entry = entry->next;\n\
      entry = next_entry;\n\
    }\n\
  }\n\
\n\
  return sz_entries;\n\
}\n\
\n\
", caches[i].name, caches[i].name, caches[i].name, caches[i].name, caches[i].name);
  }

  fprintf(fc, "\
int cache_malloc_statistics(mdd_manager_t *manager, mdd_ops_t op, mdd_level_t k)\n\
{\n\
  switch (op) {\n\
");
  for (i = 0; caches[i].name; ++i) {
    fprintf(fc, "\
  case MDD_O_%s:\n\
    return cache_%s_malloc_statistics(manager, k);\n\
", caches[i].name, caches[i].name);
  }
  fprintf(fc, "\
  case MDD_O_NB:\n\
    break;\n\
  }\n\
\n\
  return 0;\n\
}\n\
\n\
");

  fprintf(fh, "\
int cache_malloc_statistics(mdd_manager_t *, mdd_ops_t, mdd_level_t);\n\
\n\
");
}

static void generate_hash(FILE *fc, FILE *fh)
{
  int i, j;

  for (i = 0; caches[i].name; ++i) {
    fprintf(fc, "static int %s_hash(", caches[i].name);
    for (j = 0; j < caches[i].nb_inputs; ++j)
      fprintf(fc, "%s in_%d, ", string_of_type(caches[i].inputs[j]), j);
    fprintf(fc, "int M)\n{\n  return ");
    for (j = 1; j < caches[i].nb_inputs; ++j)
      fprintf(fc, "((");
    for (j = 0; j < caches[i].nb_inputs; ++j)
      switch (caches[i].inputs[j]) {
      case F_MDD:
      case F_EVMDD:
        fprintf(fc, "%sin_%d%s %% M", j ? ")*256 + " : "", j, j ? ")" : "");
        break;
      case F_VAL:
        fprintf(fc, "%s(unsigned)in_%d%s %% M", j ? ")*256 + " : "", j, j ? ")" : "");
        break;
      case F_LVAL:
        fprintf(fc, "%s(unsigned)in_%d%s %% M", j ? ")*256 + " : "", j, j ? ")" : "");
        break;
      case F_BIGINT:
        fprintf(stderr, "ERROR: '%s': don't know how to hash a bigint.\n", caches[i].name);
        exit(1);
        break;
      }
    fprintf(fc, ";\n}\n\n");
  }
}

static void generate_resize(FILE *fc, FILE *fh)
{
  int i, j;

  for (i = 0; caches[i].name; ++i) {
    fprintf(fc, "\
static void cache_%s_resize(mdd_manager_t *manager, mdd_level_t k, int to_size)\n\
{\n\
  cache_%s_t *cache = &(manager->caches[MDD_O_%s][k].%s);\n\
  unsigned int i;\n\
  int sig;\n\
  cache_%s_entry_t *entry, *next_entry;\n\
  cache_%s_entry_t **old_table = cache->table;\n\
\n\
  cache->table = calloc(to_size, sizeof(cache_%s_entry_t *));\n\
  manager->currently_allocated += to_size*sizeof(cache_%s_entry_t *);\n\
\n\
", caches[i].name, caches[i].name, caches[i].name, caches[i].name, caches[i].name, caches[i].name, caches[i].name, caches[i].name);
    fprintf(fc, "\
  for (i = 0; i < cache->size; ++i) {\n    \
    entry = old_table[i];\n\
    while (entry) {\n\
      next_entry = entry->next;\n\
      sig = %s_hash(\
", caches[i].name);
    for (j = 0; j < caches[i].nb_inputs; ++j)
      fprintf(fc, "entry->in_%d, ", j);
    fprintf(fc, "to_size);\n\
      entry->next = cache->table[sig];\n\
      cache->table[sig] = entry;\n\
      entry = next_entry;\n\
    }\n\
  }\n\
\n\
  manager->currently_allocated -= cache->size*sizeof(cache_%s_entry_t *);\n\
  free(old_table);\n\
\n\
  cache->size = to_size;\n\
}\n\
\n\
", caches[i].name);
  }
}

static void generate_cleanup(FILE *fc, FILE *fh)
{
  int i, j, with_mdd, with_evmdd, por;

  /* MDD cleanup */
  for (i = 0; caches[i].name; ++i) {
    with_mdd = 0;
    for (j = 0; j < caches[i].nb_inputs; ++j)
      with_mdd |= caches[i].inputs[j] == F_MDD;
    for (j = 0; j < caches[i].nb_outputs; ++j)
      with_mdd |= caches[i].outputs[j] == F_MDD;
    if (!with_mdd) continue;
    fprintf(fc, "\
static void cache_%s_mdd_cleanup(mdd_manager_t *manager, mdd_level_t k)\n\
{\n\
  cache_%s_t *cache = &(manager->caches[MDD_O_%s][k].%s);\n\
  unsigned int i;\n\
  cache_%s_entry_t **previous_pointer;\n\
  cache_%s_entry_t *entry;\n\
\n\
  for (i = 0; i < cache->size; ++i) {\n\
    previous_pointer = cache->table+i;\n\
    entry = *previous_pointer;\n\
    while(entry) {\n\
      if (", caches[i].name, caches[i].name, caches[i].name, caches[i].name, caches[i].name, caches[i].name);
    por = 0;
    for (j = 0; j < caches[i].nb_inputs; ++j)
      switch (caches[i].inputs[j]) {
      case F_MDD:
        fprintf(fc, "%s", por ? " ||\n          " : "");
        fprintf(fc, "!(mdd_node_get(manager, entry->in_%d)->flags & MDD_NODE_MARK)", j);
        por = 1;
        break;
      default:
        break;
      }
    for (j = 0; j < caches[i].nb_outputs; ++j)
      switch (caches[i].outputs[j]) {
      case F_MDD:
        fprintf(fc, "%s", por ? " ||\n          " : "");
        fprintf(fc, "!(mdd_node_get(manager, entry->out_%d)->flags & MDD_NODE_MARK)", j);
        por = 1;
        break;
      default:
        break;
      }
    fprintf(fc, ") {\n\
        *previous_pointer = entry->next;\n\
        manager->currently_allocated -= sizeof(cache_%s_entry_t)+8;\n", caches[i].name);
    for (j = 0; j < caches[i].nb_inputs; ++j)
      if (caches[i].inputs[j] == F_BIGINT)
        fprintf(fc, "        bigint_free(entry->in_%d);\n", j);
    for (j = 0; j < caches[i].nb_outputs; ++j)
      if (caches[i].outputs[j] == F_BIGINT)
        fprintf(fc, "        bigint_free(entry->out_%d);\n", j);
    fprintf(fc, "\
        free(entry);\n\
        --(cache->nb_elements);\n\
      } else\n\
        previous_pointer = &(entry->next);\n\
      entry = *previous_pointer;\n\
    }\n\
  }\n\
\n\
  if (cache->nb_elements < CACHE_MAX_AVERAGE_PER_ENTRY*cache->size/4)\n\
    cache_%s_resize(manager, k, mdd_utils_next_prime(CACHE_MAX_AVERAGE_PER_ENTRY*cache->nb_elements*2));\n\
}\n\
\n\
", caches[i].name);
  }

  fprintf(fc, "\
void cache_mdd_cleanup(mdd_manager_t *manager, mdd_ops_t op, mdd_level_t k)\n\
{\n\
  switch (op) {\n\
");
  for (i = 0; caches[i].name; ++i) {
    with_mdd = 0;
    for (j = 0; j < caches[i].nb_inputs; ++j)
      with_mdd |= caches[i].inputs[j] == F_MDD;
    for (j = 0; j < caches[i].nb_outputs; ++j)
      with_mdd |= caches[i].outputs[j] == F_MDD;
    fprintf(fc, "\
  case MDD_O_%s:\n", caches[i].name);
    if (with_mdd)
      fprintf(fc, "\
    cache_%s_mdd_cleanup(manager, k);\n\
", caches[i].name);
    fprintf(fc, "\
    break;\n");
  }
  fprintf(fc, "\
  case MDD_O_NB:\n\
    break;\n\
  }\n\
}\n\
\n\
");

  fprintf(fh, "\
/** Remove all cache entries refering to MDD nodes without flag MDD_NODE_MARK.\n\
 * Remove all nodes wit flag MDD_NODE_MARK set to 0 from all caches\n\
 * for level k.\n\
 */\n\
void cache_mdd_cleanup(mdd_manager_t *, mdd_ops_t, mdd_level_t);\n\
\n\
");

  /* EVMDD cleanup */
  for (i = 0; caches[i].name; ++i) {
    with_evmdd = 0;
    for (j = 0; j < caches[i].nb_inputs; ++j)
      with_evmdd |= caches[i].inputs[j] == F_EVMDD;
    for (j = 0; j < caches[i].nb_outputs; ++j)
      with_evmdd |= caches[i].outputs[j] == F_EVMDD;
    if (!with_evmdd) continue;
    fprintf(fc, "\
static void cache_%s_evmdd_cleanup(mdd_manager_t *manager, mdd_level_t k)\n\
{\n\
  cache_%s_t *cache = &(manager->caches[MDD_O_%s][k].%s);\n\
  unsigned int i;\n\
  cache_%s_entry_t **previous_pointer;\n\
  cache_%s_entry_t *entry;\n\
\n\
  for (i = 0; i < cache->size; ++i) {\n\
    previous_pointer = cache->table+i;\n\
    entry = *previous_pointer;\n\
    while(entry) {\n\
      if (", caches[i].name, caches[i].name, caches[i].name, caches[i].name, caches[i].name, caches[i].name);
    for (por = 0, j = 0; j < caches[i].nb_inputs; ++j)
      switch (caches[i].inputs[j]) {
      case F_EVMDD:
        fprintf(fc, "%s", por ? " ||\n          " : "");
        fprintf(fc, "!(evmdd_node_get(manager, entry->in_%d)->flags & MDD_NODE_MARK)", j);
        por = 1;
        break;
      default:
        break;
      }
    for (j = 0; j < caches[i].nb_outputs; ++j)
      switch (caches[i].outputs[j]) {
      case F_EVMDD:
        fprintf(fc, "%s", por ? " ||\n          " : "");
        fprintf(fc, "!(evmdd_node_get(manager, entry->out_%d)->flags & MDD_NODE_MARK)", j);
        por = 1;
        break;
      default:
        break;
      }
    fprintf(fc, ") {\n\
        *previous_pointer = entry->next;\n\
        manager->currently_allocated -= sizeof(cache_%s_entry_t)+8;\n", caches[i].name);
    for (j = 0; j < caches[i].nb_inputs; ++j)
      if (caches[i].inputs[j] == F_BIGINT)
        fprintf(fc, "        bigint_free(entry->in_%d);\n", j);
    for (j = 0; j < caches[i].nb_outputs; ++j)
      if (caches[i].outputs[j] == F_BIGINT)
        fprintf(fc, "        bigint_free(entry->out_%d);\n", j);
    fprintf(fc, "\
        free(entry);\n\
        --(cache->nb_elements);\n\
      } else\n\
        previous_pointer = &(entry->next);\n\
      entry = *previous_pointer;\n\
    }\n\
  }\n\
\n\
  if (cache->nb_elements < CACHE_MAX_AVERAGE_PER_ENTRY*cache->size/4)\n\
    cache_%s_resize(manager, k, mdd_utils_next_prime(CACHE_MAX_AVERAGE_PER_ENTRY*cache->nb_elements*2));\n\
}\n\
\n\
", caches[i].name);
  }

  fprintf(fc, "\
void cache_evmdd_cleanup(mdd_manager_t *manager, mdd_ops_t op, mdd_level_t k)\n\
{\n\
  switch (op) {\n\
");
  for (i = 0; caches[i].name; ++i) {
    with_evmdd = 0;
    for (j = 0; j < caches[i].nb_inputs; ++j)
      with_evmdd |= caches[i].inputs[j] == F_EVMDD;
    for (j = 0; j < caches[i].nb_outputs; ++j)
      with_evmdd |= caches[i].outputs[j] == F_EVMDD;
    fprintf(fc, "\
  case MDD_O_%s:\n", caches[i].name);
    if (with_evmdd)
      fprintf(fc, "\
    cache_%s_evmdd_cleanup(manager, k);\n\
", caches[i].name);
    fprintf(fc, "\
    break;\n");
  }
  fprintf(fc, "\
  case MDD_O_NB:\n\
    break;\n\
  }\n\
}\n\
\n\
");

  fprintf(fh, "\
/** Remove all cache entries refering to EVMDD nodes without flag MDD_NODE_MARK.\n\
 * Remove all nodes wit flag MDD_NODE_MARK set to 0 from all caches\n\
 * for level k.\n\
 */\n\
void cache_evmdd_cleanup(mdd_manager_t *, mdd_ops_t, mdd_level_t);\n\
\n\
");
}

static void generate_add(FILE *fc, FILE *fh)
{
  int i, j;

  for (i = 0; caches[i].name; ++i) {
    fprintf(fc, "\
void cache_%s_add(mdd_manager_t *manager, mdd_level_t k", caches[i].name);
    for (j = 0; j < caches[i].nb_inputs; ++j)
      fprintf(fc, ", %s in_%d", string_of_type(caches[i].inputs[j]), j);
    for (j = 0; j < caches[i].nb_outputs; ++j)
      fprintf(fc, ", %s out_%d", string_of_type(caches[i].outputs[j]), j);
    fprintf(fc, ")\n\
{\n\
  cache_%s_t *cache = &(manager->caches[MDD_O_%s][k].%s);\n\
  int sig = %s_hash(", caches[i].name, caches[i].name, caches[i].name, caches[i].name);
    for (j = 0; j < caches[i].nb_inputs; ++j)
      fprintf(fc, "in_%d, ", j);
    fprintf(fc, "\
cache->size);\n\
  cache_%s_entry_t *entry = malloc(sizeof(cache_%s_entry_t));\n\
  manager->currently_allocated += sizeof(cache_%s_entry_t)+8;\n\
\n", caches[i].name, caches[i].name, caches[i].name);
    for (j = 0; j < caches[i].nb_inputs; ++j)
      fprintf(fc, "\
  entry->in_%d = in_%d;\n\
", j, j);
    for (j = 0; j < caches[i].nb_outputs; ++j)
      fprintf(fc, "\
  entry->out_%d = out_%d;\n\
", j, j);
    fprintf(fc, "\
  entry->next = cache->table[sig];\n\
  cache->table[sig] = entry;\n\
\n\
  ++(cache->nb_elements);\n\
  if (cache->nb_elements > CACHE_MAX_AVERAGE_PER_ENTRY*cache->size)\n\
    cache_%s_resize(manager, k, mdd_utils_next_prime(cache->size*2));\n\
}\n\
\n\
", caches[i].name);

    fprintf(fh, "\
/* add entry to cache, assumes that entry is not already present in cache */\n\
void cache_%s_add(mdd_manager_t *, mdd_level_t", caches[i].name);
    for (j = 0; j < caches[i].nb_inputs; ++j)
      fprintf(fh, ", %s", string_of_type(caches[i].inputs[j]));
    for (j = 0; j < caches[i].nb_outputs; ++j)
      fprintf(fh, ", %s", string_of_type(caches[i].outputs[j]));
    fprintf(fh, ");\n\
\n\
");
  }  
}

static void generate_find(FILE *fc, FILE *fh)
{
  int i, j;

  for (i = 0; caches[i].name; ++i) {
    fprintf(fc, "\
int cache_%s_find(mdd_manager_t *manager, mdd_level_t k", caches[i].name);
    for (j = 0; j < caches[i].nb_inputs; ++j)
      fprintf(fc, ", %s in_%d", string_of_type(caches[i].inputs[j]), j);
    for (j = 0; j < caches[i].nb_outputs; ++j)
      fprintf(fc, ", %s *out_%d", string_of_type(caches[i].outputs[j]), j);
    fprintf(fc, ")\n\
{\n\
  cache_%s_t *cache = &(manager->caches[MDD_O_%s][k].%s);\n\
  int sig = %s_hash(", caches[i].name, caches[i].name, caches[i].name, caches[i].name);
    for (j = 0; j < caches[i].nb_inputs; ++j)
      fprintf(fc, "in_%d, ", j);
    fprintf(fc, "\
cache->size);\n\
  cache_%s_entry_t *entry = cache->table[sig];\n\
  unsigned length = 0;\n\
\n\
  while (entry) {\n\
    if (", caches[i].name);
    for (j = 0; j < caches[i].nb_inputs; ++j)
      fprintf(fc, "%sentry->in_%d == in_%d", j ? " && " : "", j, j);
    fprintf(fc, ") {\n");
    for (j = 0; j < caches[i].nb_outputs; ++j)
      fprintf(fc, "      *out_%d = entry->out_%d;\n", j, j);
    fprintf(fc, "\
      if (length > manager->nb_cache_worst)\n\
        manager->nb_cache_worst = length;\n\
      manager->nb_cache_lookup_entries += length;\n\
      ++(manager->nb_cache_lookups);\n\
      return 1;\n\
    }\n\
    entry = entry->next;\n\
    ++length;\n\
  }\n\
\n\
  if (length > manager->nb_cache_worst)\n\
    manager->nb_cache_worst = length;\n\
  manager->nb_cache_lookup_entries += length;\n\
  ++(manager->nb_cache_lookups);\n\
\n\
  return 0;\n\
}\n\
\n\
");

    fprintf(fh, "\
/* return 1 if entry is find in cache, 0 elsewhere\n\
 * when find a value, set the output argument(s) to it */\n\
int cache_%s_find(mdd_manager_t *, mdd_level_t", caches[i].name);
    for (j = 0; j < caches[i].nb_inputs; ++j)
      fprintf(fh, ", %s", string_of_type(caches[i].inputs[j]));
    for (j = 0; j < caches[i].nb_outputs; ++j)
      fprintf(fh, ", %s*", string_of_type(caches[i].outputs[j]));
    fprintf(fh, ");\n\
\n\
");
  }  
}

static void generate_cache(FILE *f)
{
  FILE *fc, *fh;

  parse(f);

  fc = fopen(filename_c, "w");
  if (fc == NULL) {
    fprintf(stderr, "ERROR: file %s not found.\n", filename_c);
    exit(1);
  }

  fh = fopen(filename_h, "w");
  if (fh == NULL) {
    fprintf(stderr, "ERROR: file %s not found.\n", filename_h);
    exit(1);
  }

  generate_header(fc, fh);

  generate_types(fc, fh);

  generate_init(fc, fh);

  generate_free(fc, fh);

  generate_malloc_statistics(fc, fh);

  generate_hash(fc, fh);

  generate_resize(fc, fh);

  generate_cleanup(fc, fh);

  generate_add(fc, fh);

  generate_find(fc, fh);

  generate_footer(fc, fh);

  fclose(fc);
  fclose(fh);
}

int main(int argc, char *argv[])
{
  FILE *f;

  if (argc != 4) {
    fprintf(stderr, "Usage: %s description.desc output_header.h output.c\n", argv[0]);
    return 1;
  }

  input_file = argv[1];
  filename_h = argv[2];
  filename_c = argv[3];

  f = fopen(input_file, "r");
  if (f == NULL) {
    fprintf(stderr, "ERROR: file %s not found.\n", input_file);
    return 1;
  }

  generate_cache(f);  

  fclose(f);

  return 0;
}