/*

  Program to generate a model for the mxn puzzle

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N=8;

void Variables(){
  printf("Variables\n");
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      printf("  q_%d_%d [0, 1]\n", i, j);
    }
  }
}

void Rows(int d) {
  for (int i=0; i<N; i++) {
    printf("(");
    for (int j=0; j<N; j++) {
      if (j>0) printf("+");
      printf("q_%d_%d", i, j);
    }
    printf("=1)");
  }
}

void Cols() {
  /* sum of columns */
  for (int i=0; i<N; i++) {
    printf(" /\\ (");
    for (int j=0; j<N; j++) {
      if (j>0) printf("+");
      printf("q_%d_%d", j, i);
    }
    printf("=1)",);
  }
}

void Diagonals() {
  /* diagonals */
  printf(" /\\ (");
  for (int i=0; i<N; i++) {
    if (i>0) printf("+");
    printf("x%d", N*i+i);
  }
  printf("=%d)", SUM);
  printf(" /\\ (");
  for (int i=0; i<N; i++) {
    if (i>0) printf("+");
    printf("x%d", N*i+(N-1-i));
  }
  printf("=%d)", SUM);
}

void Equations() {
  printf("Equations\n");
  Rows(d);
  Cols();
  Diagonals();
  printf("\n\n");
}

int main(int argc, char *argv[])
{
  for (int i = 1; i < argc; ++i) {
    if (strcmp(argv[i], "-n")==0 && i<argc-1) {
      N = atoi(argv[i+1]);
      if (N<2) {
        fprintf(stderr, " ERROR: illegal number of rows, %d.\n", N);
        return 2;
      }
    }
  }

  fprintf(stderr, "Board size: %dx%d.\n", N, N);

  Variables();
  Equations();
  return 0;
}
