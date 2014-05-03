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
//       printf("   phil%d [0, 4]\n", i);
      printf("   phil%d [0, 3]\n", i);
   }
   printf("Initial states\n");
   for (int i=0; i<PHILS;i++){
      printf("   fork%d = 0\n", i);
      printf("   phil%d = 0\n", i);
   }
}

void Trans(){
   printf("Transitions\n");
   for (int i=0; i<PHILS; i++) {
//      printf("  phil%d = 0 -> phil%d\' = 1\n", i, i);
//      printf("  phil%d = 1 /\\ fork%d = 0 -> phil%d\' = 2 /\\ fork%d\' = 1\n", i, i, i, i);
//      printf("  phil%d = 1 /\\ fork%d = 0 -> phil%d\' = 3 /\\ fork%d\' = 1\n", i, (i+1)%PHILS, i, (i+1)%PHILS);
//      printf("  phil%d = 2 /\\ fork%d = 0 -> phil%d\' = 4 /\\ fork%d\' = 1\n", i, (i+1)%PHILS, i, (i+1)%PHILS);
//      printf("  phil%d = 3 /\\ fork%d = 0 -> phil%d\' = 4 /\\ fork%d\' = 1\n", i, i, i, i);
//      printf("  phil%d = 4 -> phil%d\' = 0 /\\ fork%d\' = 0 /\\ fork%d\' = 0\n", i, i, i, (i+1)%PHILS);
     printf("  phil%d = 0 /\\ fork%d = 0 -> phil%d\' = 1 /\\ fork%d\' = 1\n", i, i, i, i);
     printf("  phil%d = 0 /\\ fork%d = 0 -> phil%d\' = 2 /\\ fork%d\' = 1\n", i, (i+1)%PHILS, i, (i+1)%PHILS);
     printf("  phil%d = 1 /\\ fork%d = 0 -> phil%d\' = 3 /\\ fork%d\' = 1\n", i, (i+1)%PHILS, i, (i+1)%PHILS);
     printf("  phil%d = 2 /\\ fork%d = 0 -> phil%d\' = 3 /\\ fork%d\' = 1\n", i, i, i, i);
     printf("  phil%d = 3 -> phil%d\' = 0 /\\ fork%d\' = 0 /\\ fork%d\' = 0\n", i, i, i, (i+1)%PHILS);
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
