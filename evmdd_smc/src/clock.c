#include "clock.h"  
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

static struct rusage start, stop;

static double clock_get_elapsed(struct timeval v1, struct timeval v2)
{
  double m1,m2;
  m1 = v1.tv_sec + v1.tv_usec / 1000000.0 ;
  m2 = v2.tv_sec + v2.tv_usec / 1000000.0 ;
  return m2 - m1;
}

static void clock_print_elapsed(double m)
{
  int days,hours,minutes;
  long newm = (int)(m+0.5);
  double seconds;

  printf("%g seconds", m);
  newm = newm / 60;
  minutes = newm % 60;
  newm = newm / 60;
  hours = newm % 24;
  days = newm / 24;
  seconds = m - days*86400.0 - hours*3600.0 - minutes*60.0;
  if (m>=60.0) {
    printf(" (");
    if (days>0) printf("%dd:", days);
    if (hours>0) printf("%dh:", hours);
    if (minutes>0) printf("%dm:", minutes);
    printf("%gs)", seconds);
  }
}

void clock_global_start()
{
  getrusage(RUSAGE_SELF, &start);
}

void clock_global_stop()
{
  getrusage(RUSAGE_SELF, &stop);
}

void clock_global_print()
{
  clock_print(&start, &stop);
}

struct rusage *clock_get()
{
  struct rusage *r=malloc(sizeof(struct rusage));

  getrusage(RUSAGE_SELF, r);

  return r;
}

void clock_free(struct rusage *c)
{
  free(c);
}

void clock_print(struct rusage *start, struct rusage *stop)
{
  printf("User: ");
  clock_print_elapsed(clock_get_elapsed(start->ru_utime, stop->ru_utime));
  printf(" System: ");
  clock_print_elapsed(clock_get_elapsed(start->ru_stime, stop->ru_stime));
  printf("\n");
/*   printf(" Page faults: %d\n", stop->ru_majflt - start->ru_majflt); */
}
