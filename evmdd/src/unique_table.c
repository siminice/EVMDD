#include <stdlib.h>
#include "mdd_manager_priv.h"
#include "unique_table_priv.h"
#include "mdd_node_priv.h"
#include "evmdd_node_priv.h"
#include "mdd_utils_priv.h"

#define UNIQUE_TABLE_INITIAL_SIZE 37
#define UNIQUE_TABLE_MAX_AVERAGE_PER_ENTRY 2

void unique_table_mdd_init(mdd_manager_t *manager, mdd_level_t k)
{
  unique_table_t *unique_table = &(manager->mdd_unique_tables[k]);

  unique_table->size = UNIQUE_TABLE_INITIAL_SIZE;
  unique_table->nb_elements = 0;
  unique_table->table = calloc(unique_table->size, sizeof(unique_table_entry_t *));
  manager->currently_allocated += unique_table->size*sizeof(unique_table_entry_t *);
  if (unique_table->table == NULL) {
    fprintf(stderr, "%s/%d: Unable to allocate %u byte of memory.\n", __FILE__, __LINE__, unique_table->size*(unsigned)sizeof(unique_table_entry_t *));
    exit(1);
  }
}

void unique_table_evmdd_init(mdd_manager_t *manager, mdd_level_t k)
{
  unique_table_t *unique_table = &(manager->evmdd_unique_tables[k]);

  unique_table->size = UNIQUE_TABLE_INITIAL_SIZE;
  unique_table->nb_elements = 0;
  unique_table->table = calloc(unique_table->size, sizeof(unique_table_entry_t *));
  manager->currently_allocated += unique_table->size*sizeof(unique_table_entry_t *);
  if (unique_table->table == NULL) {
    fprintf(stderr, "%s/%d: Unable to allocate %u byte of memory.\n", __FILE__, __LINE__, unique_table->size*(unsigned)sizeof(unique_table_entry_t *));
    exit(1);
  }
}

static void unique_table_entry_free(mdd_manager_t *manager, unique_table_entry_t *entry)
{
  if (entry == NULL) return;
  unique_table_entry_free(manager, entry->next);
  manager->currently_allocated -= sizeof(unique_table_entry_t);
  free(entry);
}

void unique_table_mdd_free(mdd_manager_t *manager, mdd_level_t k)
{
  unique_table_t *unique_table = &(manager->mdd_unique_tables[k]);
  unsigned int i;

  for (i = 0; i < unique_table->size; ++i)
    unique_table_entry_free(manager, unique_table->table[i]);

  manager->currently_allocated -= unique_table->size*sizeof(unique_table_entry_t *);
  free(unique_table->table);
}

void unique_table_evmdd_free(mdd_manager_t *manager, mdd_level_t k)
{
  unique_table_t *unique_table = &(manager->evmdd_unique_tables[k]);
  unsigned int i;

  for (i = 0; i < unique_table->size; ++i)
    unique_table_entry_free(manager, unique_table->table[i]);

  manager->currently_allocated -= unique_table->size*sizeof(unique_table_entry_t *);
  free(unique_table->table);
}

static void unique_table_mdd_resize(mdd_manager_t *manager, mdd_level_t k, int to_size)
{
  unique_table_t *unique_table = &(manager->mdd_unique_tables[k]);
  unsigned int i;
  int sig;
  unique_table_entry_t *entry, *next_entry;
  unique_table_entry_t **old_table = unique_table->table;

  unique_table->table = calloc(to_size, sizeof(unique_table_entry_t *));
  manager->currently_allocated += to_size*sizeof(unique_table_entry_t *);

  for (i = 0; i < unique_table->size; ++i) {
    entry = old_table[i];
    while (entry) {
      next_entry = entry->next;
      sig = mdd_node_hash(manager, entry->data, to_size);
      entry->next = unique_table->table[sig];
      unique_table->table[sig] = entry;
      entry = next_entry;
    }
  }

  manager->currently_allocated -= unique_table->size*sizeof(unique_table_entry_t *);
  free(old_table);

  unique_table->size = to_size;
}

static void unique_table_evmdd_resize(mdd_manager_t *manager, mdd_level_t k, int to_size)
{
  unique_table_t *unique_table = &(manager->evmdd_unique_tables[k]);
  unsigned int i;
  int sig;
  unique_table_entry_t *entry, *next_entry;
  unique_table_entry_t **old_table = unique_table->table;

  unique_table->table = calloc(to_size, sizeof(unique_table_entry_t *));
  manager->currently_allocated += to_size*sizeof(unique_table_entry_t *);

  for (i = 0; i < unique_table->size; ++i) {
    entry = old_table[i];
    while (entry) {
      next_entry = entry->next;
      sig = evmdd_node_hash(manager, entry->data, to_size);
      entry->next = unique_table->table[sig];
      unique_table->table[sig] = entry;
      entry = next_entry;
    }
  }

  manager->currently_allocated -= unique_table->size*sizeof(unique_table_entry_t *);
  free(old_table);

  unique_table->size = to_size;
}

void unique_table_mdd_add(mdd_manager_t *manager, mdd_level_index_t p, int signature)
{
  unique_table_t *unique_table = &(manager->mdd_unique_tables[mdd_level(manager, p)]);
  unique_table_entry_t *entry = malloc(sizeof(unique_table_entry_t));
  manager->currently_allocated += sizeof(unique_table_entry_t);

  if (signature < 0)
    signature = mdd_node_hash(manager, p, unique_table->size);

  entry->data = p;
  entry->next = unique_table->table[signature];
  unique_table->table[signature] = entry;

  ++(unique_table->nb_elements);
  if (unique_table->nb_elements > UNIQUE_TABLE_MAX_AVERAGE_PER_ENTRY*unique_table->size)
    unique_table_mdd_resize(manager, mdd_level(manager, p), mdd_utils_next_prime(unique_table->size*2));
}

void unique_table_evmdd_add(mdd_manager_t *manager, mdd_level_index_t p, int signature)
{
  unique_table_t *unique_table = &(manager->evmdd_unique_tables[mdd_level(manager, p)]);
  unique_table_entry_t *entry = malloc(sizeof(unique_table_entry_t));
  manager->currently_allocated += sizeof(unique_table_entry_t);

  if (signature < 0)
    signature = evmdd_node_hash(manager, p, unique_table->size);

  entry->data = p;
  entry->next = unique_table->table[signature];
  unique_table->table[signature] = entry;

  ++(unique_table->nb_elements);
  if (unique_table->nb_elements > UNIQUE_TABLE_MAX_AVERAGE_PER_ENTRY*unique_table->size)
    unique_table_evmdd_resize(manager, mdd_level(manager, p), mdd_utils_next_prime(unique_table->size*2));
}

static int unique_table_mdd_find(mdd_manager_t *manager, mdd_level_index_t p, mdd_level_index_t *q, int *signature)
{
  unique_table_t *unique_table = &(manager->mdd_unique_tables[mdd_level(manager, p)]);
  unique_table_entry_t *entry;
  unsigned length = 0;

  *signature = mdd_node_hash(manager, p, unique_table->size);
  entry = unique_table->table[*signature];
  while (entry) {
    if (mdd_node_compare(manager, p, entry->data)) {
      *q = entry->data;
      if (length > manager->nb_unique_table_worst)
        manager->nb_unique_table_worst = length;
      manager->nb_unique_table_lookup_entries += length;
      ++(manager->nb_unique_table_lookups);
      return 1;
    }
    entry = entry->next;
    ++length;
  }

  if (length > manager->nb_unique_table_worst)
    manager->nb_unique_table_worst = length;
  manager->nb_unique_table_lookup_entries += length;
  ++(manager->nb_unique_table_lookups);

  return 0;
}

static int unique_table_evmdd_find(mdd_manager_t *manager, mdd_level_index_t p, mdd_level_index_t *q, int *signature)
{
  unique_table_t *unique_table = &(manager->evmdd_unique_tables[mdd_level(manager, p)]);
  unique_table_entry_t *entry;
  unsigned length = 0;

  *signature = evmdd_node_hash(manager, p, unique_table->size);
  entry = unique_table->table[*signature];
  while (entry) {
    if (evmdd_node_compare(manager, p, entry->data)) {
      *q = entry->data;
      if (length > manager->nb_unique_table_worst)
        manager->nb_unique_table_worst = length;
      manager->nb_unique_table_lookup_entries += length;
      ++(manager->nb_unique_table_lookups);
      return 1;
    }
    entry = entry->next;
    ++length;
  }

  if (length > manager->nb_unique_table_worst)
    manager->nb_unique_table_worst = length;
  manager->nb_unique_table_lookup_entries += length;
  ++(manager->nb_unique_table_lookups);

  return 0;
}

mdd_level_index_t unique_table_mdd_checkin(mdd_manager_t *manager, mdd_level_index_t p)
{
  mdd_level_index_t r=p;
  int signature;

  if (unique_table_mdd_find(manager, p, &r, &signature))
    mdd_node_free(manager, p);
  else
    unique_table_mdd_add(manager, p, signature);

  return r;
}

mdd_level_index_t unique_table_evmdd_checkin(mdd_manager_t *manager, mdd_level_index_t p)
{
  mdd_level_index_t r=p;
  int signature;

  if (unique_table_evmdd_find(manager, p, &r, &signature))
    evmdd_node_free(manager, p);
  else
    unique_table_evmdd_add(manager, p, signature);

  return r;
}

void unique_table_mdd_cleanup(mdd_manager_t *manager, mdd_level_t k)
{
  unique_table_t *unique_table = &(manager->mdd_unique_tables[k]);
  unsigned int i;
  unique_table_entry_t **previous_pointer;
  unique_table_entry_t *entry;

  for (i = 0; i < unique_table->size; ++i) {
    previous_pointer = unique_table->table+i;
    entry = *previous_pointer;
    while(entry) {
      if (!(mdd_node_get(manager, entry->data)->flags & MDD_NODE_MARK)) {
        *previous_pointer = entry->next;
        manager->currently_allocated -= sizeof(unique_table_entry_t);
        free(entry);
        --(unique_table->nb_elements);
      } else
        previous_pointer = &(entry->next);
      entry = *previous_pointer;
    }
  }

  if (unique_table->nb_elements < UNIQUE_TABLE_MAX_AVERAGE_PER_ENTRY*unique_table->size/4)
    unique_table_mdd_resize(manager, k,
                            mdd_utils_next_prime(UNIQUE_TABLE_MAX_AVERAGE_PER_ENTRY*unique_table->nb_elements*2));
}

void unique_table_evmdd_cleanup(mdd_manager_t *manager, mdd_level_t k)
{
  unique_table_t *unique_table = &(manager->evmdd_unique_tables[k]);
  unsigned int i;
  unique_table_entry_t **previous_pointer;
  unique_table_entry_t *entry;

  for (i = 0; i < unique_table->size; ++i) {
    previous_pointer = unique_table->table+i;
    entry = *previous_pointer;
    while(entry) {
      if (!(evmdd_node_get(manager, entry->data)->flags & MDD_NODE_MARK)) {
        *previous_pointer = entry->next;
        manager->currently_allocated -= sizeof(unique_table_entry_t);
        free(entry);
        --(unique_table->nb_elements);
      } else
        previous_pointer = &(entry->next);
      entry = *previous_pointer;
    }
  }

  if (unique_table->nb_elements < UNIQUE_TABLE_MAX_AVERAGE_PER_ENTRY*unique_table->size/4)
    unique_table_evmdd_resize(manager, k,
                              mdd_utils_next_prime(UNIQUE_TABLE_MAX_AVERAGE_PER_ENTRY*unique_table->nb_elements*2));
}
