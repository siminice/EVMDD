#ifndef CLOCK_H
#define CLOCK_H

#include <sys/resource.h>

typedef struct rusage* clock__t;

void clock_global_start();
void clock_global_stop();
void clock_global_print();

clock__t clock_get();
void clock_free(clock__t);
void clock_print(clock__t start, clock__t stop);

#endif /* CLOCK_H */
