#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int my_rand(int max) {   
  return (int) ( ((double) max)*rand()/(RAND_MAX+1.0) );
}

void reset_rand() {
  srand((unsigned) time(NULL));
}
   
double my_random() {
  return ((double) rand())/(RAND_MAX+1.0);
};

int num_vars;
int num_mons;
int range;
int scalar;
int degree;
int *lb, *ub;
int **monomial;

int random_degree(int n) {
  double r = sqrt(double(my_rand(n*n)));
  return n - ((int)r);
}

int print_evmdd() {
  printf("Variables\n");
  for (int i=0; i<num_vars; i++) {
    printf("  v%d \t [%d,%d]\n", i, lb[i], ub[i]);
  }
  printf("Equations\n  ");
  for (int i=0; i<num_mons; i++) {
    if (i>0 && monomial[i][0]>0) printf(" +");
    printf(" %d*v%d", monomial[i][0], monomial[i][1]);
    if (monomial[i][2]>1) printf("^%d", monomial[i][2]);
    if (monomial[i][3]!=monomial[i][1]) {
      printf("*v%d", monomial[i][3]);
      if (monomial[i][4]>1) printf("^%d", monomial[i][4]);
    }
  }
  printf(" > 0\n");
}

void print_ymonomial(int i) {
  fprintf(stderr, "(* %d", monomial[i][0]);
    if (monomial[i][1]==monomial[i][3]) {
      if (monomial[i][2] <= 1) {
        fprintf(stderr, " v%d", monomial[i][1]);
      }
      else {
        for (int j=0; j<monomial[i][2]-1; j++) {
          fprintf(stderr, " (* v%d", monomial[i][1]);
        }
        fprintf(stderr, " v%d", monomial[i][1]);
        for (int j=0; j<monomial[i][2]-1; j++) {
          fprintf(stderr, ")");
        } 
      }
    }
  fprintf(stderr, ")");
}

int print_yices() {
  for (int i=0; i<num_vars; i++) {
    fprintf(stderr, "(define v%d::(subrange %d %d))\n", i, lb[i], ub[i]);
  }
  fprintf(stderr, "(define e::int ");
  for (int i=0; i<num_mons-1; i++) {
    fprintf(stderr, "(+ ");
    print_ymonomial(i);
  }
  fprintf(stderr, " ");
  print_ymonomial(num_mons-1);
  for (int i=0; i<num_mons-1; i++) {
    fprintf(stderr, ")");
  }
  fprintf(stderr, ")\n");
  fprintf(stderr, "(assert (> e 0))\n");
  fprintf(stderr, "(check)\n");
}

int main(int argc, char **argv) {
  reset_rand();

  /* set parameters */
  num_vars  	=  32;
  num_mons 	=  48;
  range		=   5;
  scalar	=  10;
  degree	=   3;

  int x;
  for (int j=1; j<argc; j++) {
    if (strcmp(argv[j], "-n")==0 && j<argc-1) {
      x = atoi(argv[j+1]);
      if (x >=2 && x <= 1000000) { num_vars = x; }
    }
    if (strcmp(argv[j], "-m")==0 && j<argc-1) {
      x = atoi(argv[j+1]);
      if (x >=2 && x <= 1000000) { num_mons = x; }
    }
    if (strcmp(argv[j], "-r")==0 && j<argc-1) {
      x = atoi(argv[j+1]);
      if (x >=2 && x <= 1000) { range = x; }
    }
    if (strcmp(argv[j], "-d")==0 && j<argc-1) {
      x = atoi(argv[j+1]);
      if (x >=1 && x <= 10) { degree = x; }
    }
  }

  /* allocate memory*/
  lb = new int[num_vars];
  ub = new int[num_vars];
  monomial = new int*[num_mons];
  for (int i=0; i<num_mons; i++) {
    monomial[i] = new int[num_vars+1];
  }

  /* define variable domains */
  for (int i=0; i<num_vars; i++) {
    lb[i] = my_rand(range/2);
    ub[i] = lb[i] + 1 + my_rand(2*range);
  }

  /* create monomials */
  for (int i=0; i<num_mons; i++) {
    int x = my_rand(num_vars);
    int y = x;
    if (my_rand(5) == 10) {
      y = my_rand(num_vars);
    }
    int d1 = random_degree(degree);
    int d2 = random_degree(degree);
    int s  = my_rand(range) - my_rand(2*range);
    if (s==0) s = 1;
    monomial[i][0] = s;
    monomial[i][1] = x;
    monomial[i][2] = d1;
    monomial[i][3] = y;
    monomial[i][4] = d2;
  }

  print_evmdd();
  print_yices();

  /* deallocate memory */
  if (lb) delete[] lb;
  if (ub) delete[] ub;
  for (int i=0; i<num_mons; i++) {
    if (monomial[i]) delete[] monomial[i];
  }
  if (monomial) delete monomial;
  
  return 0;
}
