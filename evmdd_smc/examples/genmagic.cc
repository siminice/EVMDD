/*

  Program to generate a model for the mxn puzzle

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N=9;
int df=0;
int SUM=N*(N*N+1)/2;

void Variables(){
  printf("Variables\n");
  for (int i=0; i<N*N; i++){
    printf("  x%d [1, %d]\n", i, N*N);
  }
}

void SumOfRows(int d) {
  /* sum of rows */
  for (int i=0; i<N; i++) {
    if (d==1 || i>0) printf(" /\\ ");
    printf("(");
    for (int j=0; j<N; j++) {
      if (j>0) printf("+");
      printf("x%d", N*i+j);
    }
    printf("=%d)", SUM);
  }
}

void SumOfCols() {
  /* sum of columns */
  for (int i=0; i<N; i++) {
    printf(" /\\ (");
    for (int j=0; j<N; j++) {
      if (j>0) printf("+");
      printf("x%d", N*j+i);
    }
    printf("=%d)", SUM);
  }
}

void SumOfDiagonals() {
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

void Distinct(int d) {
  for (int i=0; i<N*N-1; i++) {
    for (int j=i+1; j<N*N; j++) {
      if (d==0 || i!=0 || j!=1) printf(" /\\ ");
      printf("(x%d!=x%d)", i, j);
    }
  }
}

void Equations(int d) {
  printf("Equations\n");
  if (d>0) Distinct(d);
  SumOfRows(d);
  SumOfCols();
  SumOfDiagonals();
  if (d==0) Distinct(d);
  printf("\n\n");
}

int main(int argc, char *argv[])
{
  for (int i = 1; i < argc; ++i) {
    if (strcmp(argv[i], "-n")==0 && i<argc-1) {
      N = atoi(argv[i+1]);
      SUM = N*(N*N+1)/2;
      if (N<2) {
        fprintf(stderr, " ERROR: illegal number of rows, %d.\n", N);
        return 2;
      }
    }
    if (strcmp(argv[i], "-d")==0) {
      df = 1;
    }
  }

  fprintf(stderr, "Board size: %dx%d.\n", N, N);
  Variables();
  Equations(df);
  return 0;
}
