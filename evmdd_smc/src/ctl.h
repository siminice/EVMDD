#ifndef CTL_H
#define CTL_H

#include <evmdd/mdd_manager.h>

mdd_level_index_t ctl_EX(mdd_manager_t *manager, mdd_level_index_t s);
mdd_level_index_t ctl_EG(mdd_manager_t *manager, mdd_level_index_t s);
mdd_level_index_t ctl_EU(mdd_manager_t *manager, mdd_level_index_t s1, mdd_level_index_t s2);

#endif /* CTL_H */
