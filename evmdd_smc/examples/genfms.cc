/*

  Program to generate the Flexible Manufacturing System model

 */

#include <stdio.h>
#include <stdlib.h>

int N;

void Init(){
   printf("Variables\n");
      printf("   pr     [0, %d]\n", N);
      printf("   pnr    [0, %d]\n", N);
      printf("   p1     [0, %d]\n", N);
      printf("   p1wm1  [0, %d]\n", N);
      printf("   p1m1   [0, %d]\n", N);
      printf("   m1     [0, %d]\n", N);
      printf("   p1d    [0, %d]\n", N);
      printf("   p1s    [0, %d]\n", N);
      printf("   pmid1  [0, %d]\n", N);
      printf("   p12s   [0, %d]\n", N);
      printf("   p12m3  [0, %d]\n", N);
      printf("   m3     [0, %d]\n", N);
      printf("   p12wm3 [0, %d]\n", N);
      printf("   p12    [0, %d]\n", N);
      printf("   p1wp2  [0, %d]\n", N);
      printf("   p2wp1  [0, %d]\n", N);
      printf("   ptop   [0, %d]\n", N);
      printf("   pbot   [0, %d]\n", N);
      printf("   p2     [0, %d]\n", N);
      printf("   p2wm2  [0, %d]\n", N);
      printf("   p2m2   [0, %d]\n", N);
      printf("   m2     [0, %d]\n", N);
      printf("   p2d    [0, %d]\n", N);
      printf("   p2s    [0, %d]\n", N);
      printf("   pmid2  [0, %d]\n", N);
      printf("   p3     [0, %d]\n", N);
      printf("   p3m2   [0, %d]\n", N);
      printf("   p3s    [0, %d]\n", N);
      printf("   pr     [0, %d]\n", 3*N);
   printf("Initial states\n");
      printf("   pr     = 0\n");
      printf("   pnr    = 0\n");
      printf("   p1     = %d\n", N);
      printf("   p1wm1  = 0\n");
      printf("   p1m1   = 0\n");
      printf("   m1     = 3\n");
      printf("   p1d    = 0\n");
      printf("   p1s    = 0\n");
      printf("   pmid1  = 0\n");
      printf("   p12s   = 0\n");
      printf("   p12m3  = 0\n");
      printf("   m3     = 2\n");
      printf("   p12wm3 = 0\n");
      printf("   p12    = 0\n");
      printf("   p1wp2  = 0\n");
      printf("   p2wp1  = 0\n");
      printf("   ptop   = %d\n", N);
      printf("   pbot   = %d\n", N);
      printf("   p2     = %d\n", N);
      printf("   p2wm2  = 0\n");
      printf("   p2m2   = 0\n");
      printf("   m2     = 1\n");
      printf("   p2d    = 0\n");
      printf("   p2s    = 0\n");
      printf("   pmid2  = 0\n");
      printf("   p3     = %d\n", N);
      printf("   p3m2   = 0\n");
      printf("   p3s    = 0\n");
      printf("   pr     = %d\n", 3*N);
}

void Trans(){
   printf("Transitions\n");
     printf("  p1>0 /\\ pr>0 -> p1\' = p1-1 /\\ pr\' = pr-1 /\\ pnr\' = pnr+1\n");
     printf("  p1wm1>0 /\\ m1>0 -> p1wm1\' = p1wm1-1 /\\ m1\' = m1-1 /\\ p1m1\' = p1m1+1\n");
     printf("  p1m1>0 -> p1m1\' = p1m1-1 /\\ m1\' = m1+1 /\\ p1d\' = p1d+1\n");
     printf("  p1wm1>0 /\\ m1>0 -> p1wm1\' = p1wm1-1 /\\ m1\' = m1-1 /\\ p1m1\' = p1m1+1\n");
}

void Spec() {
}

int main(int argc, char *argv[])
{
  if (argc<2) {
    fprintf(stderr, "ERROR: no initial value for N specified.\n");
    return 1;
  }
  N = atoi(argv[1]);
  fprintf(stderr, "Parameter N: %d.\n", N);
  if (N<1) {
    fprintf(stderr, " ERROR: illegal parameter N = %d.\n", N);
    return 2;
  }
  Init();
  Trans();
  Spec();	
  return 0;
}
