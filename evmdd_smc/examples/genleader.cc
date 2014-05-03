/*

  Program to generate a randomized leader election protocol

 */

#include <stdio.h>
#include <stdlib.h>

int P;

void Init(){
   printf("Variables\n");
   for (int i=0; i<P;i++){
      printf("   state%d [0, 4]\n", i);
      printf("   sent%d  [0, 2]\n", i);
      printf("   recv%d  [0, 2]\n", i);
      printf("   pref%d  [0, 1]\n", i);
      printf("   count%d [0, %d]\n", i, P);
   }
   printf("Initial states\n");
   for (int i=0; i<P;i++){
      printf("   state%d = 0\n", i);
      printf("   sent%d  = 0\n", i);
      printf("   recv%d  = 0\n", i);
      printf("   pref%d  = 0\n", i);
      printf("   count%d = 0\n", i);
   }
}

void Trans(){
   printf("Transitions\n");
   for (int i=0; i<P; i++) {
     printf("  state%d = 0 /\\ sent%d = 0 /\\ recv%d = 0 -> state%d\' = 1 /\\ pref%d\' >= 0 /\\ pref%d\' <=1\n", i, i, i, i, i, i);
     printf("  state%d = 1 /\\ sent%d = 0 -> sent%d\' = 1\n", i, i, i);
     printf("  state%d = 1 /\\ sent%d > 0 /\\ sent%d = 1 /\\ recv%d = 0 /\\ pref%d >= pref%d -> state%d\' = 2 /\\ recv%d\' = 1\n", i, (i+1)%P, i, i, i, (i+1)%P, i, i);
     printf("  state%d = 1 /\\ sent%d > 0 /\\ sent%d = 1 /\\ recv%d = 0 /\\ pref%d < pref%d -> state%d\' = 3 /\\ recv%d\' = 1\n", i, (i+1)%P, i, i, i, (i+1)%P, i, i);
     printf("  state%d = 2 /\\ sent%d = 1 -> sent%d\' = 2\n", i, i, i);
     printf("  state%d = 2 /\\ sent%d = 2 /\\ recv%d = 1 /\\ count%d < %d -> state%d\' = 0 /\\ sent%d\' = 0 /\\ recv%d\' = 0 /\\ pref%d\' = 0 /\\ count%d\' = 0 /\\ count%d\' = 0\n", i, (i+1)%P, i, (i+1)%P, P-1, i, (i+1)%P, i, i, i, (i+1)%P);
     printf("  state%d = 2 /\\ sent%d = 2 /\\ recv%d = 1 /\\ count%d >= %d -> state%d\' = 4 /\\ sent%d\' = 0 /\\ recv%d\' = 0 /\\ count%d\' = 0\n", i, (i+1)%P, i, (i+1)%P, P-1, i, (i+1)%P, i, (i+1)%P);
     printf("  state%d = 3 /\\ sent%d > 0 /\\ recv%d = 0 -> recv%d\' = 1 /\\ pref%d\' = pref%d /\\ count%d\' = 0\n", i, (i+1)%P, i, i, i, (i+1)%P, (i+1)%P);
     printf("  state%d = 3 /\\ sent%d = 0 /\\ recv%d > 0 -> sent%d\' = 1\n", i, i, i, i);
     printf("  state%d = 3 /\\ sent%d = 1 /\\ recv%d = 2 -> sent%d\' = 2 /\\ recv%d\' = 0 /\\ pref%d\' = 0\n", i, i, i, i, i, i);
     printf("  state%d = 3 /\\ sent%d = 2 /\\ recv%d = 1 -> sent%d\' = 0 /\\ recv%d\' = 2 /\\ count%d\' = count%d+1 /\\ count%d\'=0\n\n", i, (i+1)%P, i, (i+1)%P, i, i, (i+1)%P, (i+1)%P);
  }
}

void Spec() {
}

int main(int argc, char *argv[])
{
  if (argc<2) {
    fprintf(stderr, "ERROR: no #processes specified.\n");
    return 1;
  }
  P = atoi(argv[1]);
  fprintf(stderr, "Number of processes: %d.\n", P);
  if (P<2) {
    fprintf(stderr, " ERROR: illegal number of processes, %d.\n", P);
    return 2;
  }
  Init();
  Trans();
  Spec();	
  return 0;
}
