#ifndef MDD_MANAGER_H
#define MDD_MANAGER_H

/** \file
 * \author Pierre Roux
 * \date 2009
 *
 * \brief Define the fundamental structure mdd_manager.
 *
 * This structure is used everywhere to store all kinds of datas about the decision diagrams represented,
 * managing garbage collection, caches, unique_tables and all sort of stuff
 * the user don't necessarily want to take care itself.
 */

typedef int mdd_level_t;  /**< type of indices of variables (in practice integers ranging from 1 to number of variables) */
typedef int mdd_index_t;  /**< type of indexes of nodes, identifying a node at a given level */
typedef unsigned int mdd_level_index_t;  /**< a couple (level, index) fully identifying a node */

typedef struct event_entry event_entry_t;  /**< type of events, \see file events.h */

typedef struct mdd_manager mdd_manager_t;  /**< THE manager, structure containing everything */

/** Creating a new manager.
 * This is certainly the first function to call in any program using this library.
 * Returns a brand new manager needed to do virtually everything in this library.
 *
 * \param nb_levels number of variables in decision diagrams to be build
 * \param lower_bounds array of size \a nb_levels+1 containing smallest values of variables indiced from 1 to \a nb_levels included,
 * \a lower_bounds[0] will never be accessed, this array is copied and can be freed just after the call
 * \param ranges array with ranges of variable (for example if we have only one variable which can take values
 * 2 and 3 and 4, \a lower_bounds[1] = 2 and \a ranges[1] = (4-2)+1 = 3 possible different values),
 * \a range[0] will never be accessed, this array is copied and can be freed just after the call
 * \return a newly allocated manager
 */
mdd_manager_t *mdd_manager_new(int nb_levels, int *lower_bounds, int *ranges);

/** Set variables names for manager.
 *
 * Those names can be useful for printing and other debuging  tasks.
 *
 * \param manager the manager
 * \param var_names NULL or an array of string (of size nb_levels+1) representing names of variables (indiced from 1 to nb_levels included), var_names[0] will never be accessed, data are copied and can be freed just after the call
 */
void mdd_manager_set_var_names(mdd_manager_t *manager, char **var_names);

/** Set garbage collection threshold.
 *
 * \param manager the manager
 * \param gc_threshold threshold for garbage collection, special value 0 means never attempt to garbage collect anything
 */
void mdd_manager_set_gc_threshold(mdd_manager_t *manager, unsigned long gc_threshold);

/** Retrieve nb_levels stored in manager.
 *
 * \param manager the manager
 * \return number of variables
 */
int mdd_manager_get_nb_levels(mdd_manager_t *manager);

/** Retrieve events stored in manager.
 *
 * \see file events.h
 *
 * \param manager the manager
 * \return an array of size \a manager->nb_levels+1 indexed from 1 to \a manager->nb_levels included
 * with lists of events ordered by their topmost relevant variables (the one with greatest indice aka level),
 * this array remains the property of the manager, do not modify it or attempt to free it.
 */
event_entry_t **mdd_manager_get_events(mdd_manager_t *manager);

/** Retrieve transition function stored in manager.
 *
 * \see file events.h
 *
 * \param manager the manager
 * \return (logic) disjunction of all events registered in manager in form of one big MDD.
 */
mdd_level_index_t mdd_manager_get_all_events(mdd_manager_t *manager);

/** Print a vector state to screen
 *
 * \param manager the manager
 * \param state a vector of integer values,
 *   size of state has to match \a nb_levels
 */
void mdd_manager_print_state(mdd_manager_t *manager, int *state);

/** Destructing a manager.
 * Function to call at end of a program when decision diagrams are no longer usefuls.
 * Release all memory used so far.
 *
 * \param manager the poor exhausted manager to be destroyed
 */
void mdd_manager_free(mdd_manager_t *manager);

/** Memory  Statistics.
 * Compute some memory stats.
 *
 * \param manager
 */
void current_statistics(mdd_manager_t*);
void spare_statistics(mdd_manager_t*);
void malloc_statistics(mdd_manager_t*);
void final_statistics(mdd_manager_t*);

#endif /* MDD_MANAGER_H */
