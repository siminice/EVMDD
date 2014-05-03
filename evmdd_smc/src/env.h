#ifndef ENV_H
#define ENV_H

#define ENV_SIZE 131072

/* put variable name in env and return a unique positive id for it
   variable is in interval [lb, gb]
   please note that now env is the "owner" of the string name
   (which will be deleted with env_free) */
int env_put(char *name, int lb, int gb);

/* return the unique id of variable name if it's in env
   and 0 elsewhere
   (lb abd ub allow to retrieve the interval for variable if found) */
int env_is_in(char *name, int *lb, int *ub);

/* return name of variable id
   or NULL if invalid id */
char *env_name(int id, int *lb, int *ub);

/* return the number n of variables recorded in env,
   valid variables ids are then [1..n]  */
int env_size();

/* reorder variables */
void env_reorder(int*);

/* read variable order */
void env_read_vorder(char*, int*);

/* delete all variables in env */
void env_free();

/* ------------------------------------ */

/* put macro def in env and return a unique positive id for it
*/
int mdf_put(char *name, void *body);

/* return the unique id of macro def if it's in env
   and 0 elsewhere
*/
int mdf_is_in(char *name, int *root, void **body);

/* store root of mdd */
int mdf_set_root(int x, int root);

/* return name of macdro def or NULL if invalid */
char *mdf_get_name(int id);

/* get root of mdd */
int mdf_get_root(char *name, int *root);

/* get body of macro */
void* mdf_get_body(int id);

/* return the number of macro defs in env */
int mdf_size();

/* delete all macro defs */
void mdf_free();

/* ------------------------------------ */

int init_put(void *expr);
void* init_get_body(int id);
int num_inits();

int event_put(char *name, void *expr);
char* event_get_name(int id);
void* event_get_body(int id);
int num_events();

int equation_put(char *name, void *expr);
char* equation_get_name(int id);
void* equation_get_body(int id);
int num_equations();

#endif /* ENV_H */
