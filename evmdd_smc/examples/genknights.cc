/*

  Program to generate a model for the knights problem

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N=-1;
bool spec=false;

int initpos(int r, int c, int n) {
  /* the spot in the center is empty */
  int center = (n+1)/2;
  if (r==center && c==center) return 0; 
  /* the upper left section is white */
  /* the diagonal is not perfect: 
     there is a shift of one position below center row */
  if (r+c <= n + r/(center+1)) return 1;
  return 2;
}

void Init(){
   printf("Variables\n");
   for (int i=1; i<=N; i++){
     for (int j=1; j<=N; j++){
        printf("   p_%d_%d [0, 2]\n", i, j);
     }
   }
   printf("Initial states\n");
   for (int i=1; i<=N; i++){
     for (int j=1; j<=N; j++){
        printf("   p_%d_%d = %d\n", i, j, initpos(i,j,N));
     }
   }
}

void Trans(){
   printf("Transitions\n");
   for (int i=1; i<=N; i++){
     for (int j=1; j<=N; j++){
        if (i-2>0 && j-1>0)
          printf("   p_%d_%d = 0 -> p_%d_%d\' = p_%d_%d /\\ p_%d_%d\'= 0\n", 
            i, j, i, j, i-2, j-1, i-2, j-1);
        if (i-2>0 && j+1<=N)
          printf("   p_%d_%d = 0 -> p_%d_%d\' = p_%d_%d /\\ p_%d_%d\'= 0\n", 
            i, j, i, j, i-2, j+1, i-2, j+1);
        if (i-1>0 && j-2>0)
          printf("   p_%d_%d = 0 -> p_%d_%d\' = p_%d_%d /\\ p_%d_%d\'= 0\n", 
            i, j, i, j, i-1, j-2, i-1, j-2);
        if (i-1>0 && j+2<=N)
          printf("   p_%d_%d = 0 -> p_%d_%d\' = p_%d_%d /\\ p_%d_%d\'= 0\n", 
            i, j, i, j, i-1, j+2, i-1, j+2);
        if (i+1<=N && j-2>0)
          printf("   p_%d_%d = 0 -> p_%d_%d\' = p_%d_%d /\\ p_%d_%d\'= 0\n", 
            i, j, i, j, i+1, j-2, i+1, j-2);
        if (i+1<=N && j+2<=N)
          printf("   p_%d_%d = 0 -> p_%d_%d\' = p_%d_%d /\\ p_%d_%d\'= 0\n", 
            i, j, i, j, i+1, j+2, i+1, j+2);
        if (i+2<=N && j-1>0)
          printf("   p_%d_%d = 0 -> p_%d_%d\' = p_%d_%d /\\ p_%d_%d\'= 0\n", 
            i, j, i, j, i+2, j-1, i+2, j-1);
        if (i+2<=N && j+1<=N)
          printf("   p_%d_%d = 0 -> p_%d_%d\' = p_%d_%d /\\ p_%d_%d\'= 0\n", 
            i, j, i, j, i+2, j+1, i+2, j+1);
     }
   }
}

void Spec() {
  if (spec) {
    printf("Properties\n");
    printf("  !EX(true)\n");
  }
}

int main(int argc, char *argv[])
{
  for (int i = 1; i < argc; ++i) {
    if (!strcmp(argv[i], "-p"))
      spec = true;
    else {
      N = atoi(argv[i]);
      if (N<2 || N%2==0) {
        fprintf(stderr, " ERROR: illegal size, %d. Expecting positive odd number.\n", N);
        return 2;
      }
    }
  }
  if (N == -1) {
    fprintf(stderr, "ERROR: no #N specified.\n");
    return 1;
  }
  fprintf(stderr, "Size of board: %d.\n", N);
  Init();
  Trans();
  Spec();	
  return 0;
}
