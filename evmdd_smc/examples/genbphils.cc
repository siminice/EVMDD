/*

  Program to generate a model for dining philosophers (with deadlock)

 */

#include <stdio.h>
#include <stdlib.h>

int PHILS;

void Init(){
   printf("Variables\n");
   for (int i=0; i<PHILS;i++){
      printf("   fork%d [0, 1]\n", i);
      printf("   idle%d [0, 1]\n", i);
      printf("   wait%d [0, 1]\n", i);
      printf("   hasl%d [0, 1]\n", i);
      printf("   hasr%d [0, 1]\n", i);
      printf("   eats%d [0, 1]\n", i);
   }
   printf("Initial states\n");
   for (int i=0; i<PHILS;i++){
      printf("   fork%d = 0\n", i);
      printf("   idle%d = 1\n", i);
      printf("   wait%d = 0\n", i);
      printf("   hasl%d = 0\n", i);
      printf("   hasr%d = 0\n", i);
      printf("   eats%d = 0\n", i);
   }
}

void Trans(){
   printf("Transitions\n");
   for (int i=0; i<PHILS; i++) {
     printf("  idle%d = 1              -> idle%d\' = 0 /\\ wait%d\' = 1\n", i, i, i);
     printf("  wait%d = 1 /\\ fork%d = 0 -> wait%d\' = 0 /\\ hasl%d\' = 1 /\\ fork%d\' = 1\n", i, i, i, i, i);
     printf("  wait%d = 1 /\\ fork%d = 0 -> wait%d\' = 0 /\\ hasr%d\' = 1 /\\ fork%d\' = 1\n", i, (i+1)%PHILS, i, i, (i+1)%PHILS);
     printf("  hasl%d = 1 /\\ fork%d = 0 -> hasl%d\' = 0 /\\ eats%d\' = 1 /\\ fork%d\' = 1\n", i, (i+1)%PHILS, i, i, (i+1)%PHILS);
     printf("  hasr%d = 1 /\\ fork%d = 0 -> hasr%d\' = 0 /\\ eats%d\' = 1 /\\ fork%d\' = 1\n", i, i, i, i, i);
     printf("  eats%d = 1              -> eats%d\' = 0 /\\ idle%d\' = 1 /\\ fork%d\' = 0 /\\ fork%d\' = 0\n", i, i, i, i, (i+1)%PHILS);
  }
}

void Spec() {
}

int main(int argc, char *argv[])
{
  if (argc<2) {
    fprintf(stderr, "ERROR: no #phils specified.\n");
    return 1;
  }
  PHILS = atoi(argv[1]);
  fprintf(stderr, "Number of philosophers: %d.\n", PHILS);
  if (PHILS<2) {
    fprintf(stderr, " ERROR: illegal number of philosophers, %d.\n", PHILS);
    return 2;
  }
  Init();
  Trans();
  Spec();	
  return 0;
}
