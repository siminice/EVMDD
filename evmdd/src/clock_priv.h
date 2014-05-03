#ifndef CLOCK_PRIV_H
#define CLOCK_PRIV_H

#include <sys/resource.h>

typedef struct rusage* clock_t;

clock_t clock_get();
void clock_free(clock_t);
void clock_print(clock_t start, clock_t stop);

#endif /* CLOCK_PRIV_H */
