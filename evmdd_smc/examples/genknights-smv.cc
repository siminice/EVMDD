/*

  Program to generate a model for the knights problem

 */

#include <stdio.h>
#include <stdlib.h>

int N;

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
   printf("MODULE main\n");
   printf("VAR\n");
   printf("  dir : {NW, NE, SW, SE, WN, WS, EN, ES};\n");
   for (int i=1; i<=N; i++){
     for (int j=1; j<=N; j++){
        printf("  p_%d_%d : {q0, q1, q2};\n", i, j);
     }
   }
   printf("ASSIGN\n");
   printf("  init(dir) := {NW, NE, SW, SE, WN, WS, EN, ES};\n");
   for (int i=1; i<=N; i++){
     for (int j=1; j<=N; j++){
        printf("  init(p_%d_%d) := q%d;\n", i, j, initpos(i,j,N));
     }
   }
}

void Trans(){
  printf("  next(dir) := {NW, NE, SW, SE, WN, WS, EN, ES};\n");
   for (int i=1; i<=N; i++){
     for (int j=1; j<=N; j++){
       printf("  next(p_%d_%d) := case\n", i, j);
       if (i-2>0 && j-1>0) {
         printf("    (dir = WN) & (p_%d_%d = q0) : p_%d_%d;\n", i, j, i-2, j-1);
         printf("    (dir = ES) & (p_%d_%d = q0) : q0;\n", i-2, j-1);
       }         
       if (i-2>0 && j+1<=N) {
         printf("    (dir = WS) & (p_%d_%d = q0) : p_%d_%d;\n", i, j, i-2, j+1);
         printf("    (dir = EN) & (p_%d_%d = q0) : q0;\n", i-2, j+1);
       }         
       if (i-1>0 && j-2>0) {
         printf("    (dir = NW) & (p_%d_%d = q0) : p_%d_%d;\n", i, j, i-1, j-2);
         printf("    (dir = SE) & (p_%d_%d = q0) : q0;\n", i-1, j-2);
       }         
       if (i-1>0 && j+2<=N) {
         printf("    (dir = SW) & (p_%d_%d = q0) : p_%d_%d;\n", i, j, i-1, j+2);
         printf("    (dir = NE) & (p_%d_%d = q0) : q0;\n", i-1, j+2);
       }         
       if (i+1<=N && j-2>0) {
         printf("    (dir = NE) & (p_%d_%d = q0) : p_%d_%d;\n", i, j, i+1, j-2);
         printf("    (dir = SW) & (p_%d_%d = q0) : q0;\n", i+1, j-2);
       }         
       if (i+1<=N && j+2<=N) {
         printf("    (dir = SE) & (p_%d_%d = q0) : p_%d_%d;\n", i, j, i+1, j+2);
         printf("    (dir = NW) & (p_%d_%d = q0) : q0;\n", i+1, j+2);
       }         
       if (i+2<=N && j-1>0) {
         printf("    (dir = EN) & (p_%d_%d = q0) : p_%d_%d;\n", i, j, i+2, j-1);
         printf("    (dir = WS) & (p_%d_%d = q0) : q0;\n", i+2, j-1);
       }         
       if (i+2<=N && j+1<=N) {
         printf("    (dir = ES) & (p_%d_%d = q0) : p_%d_%d;\n", i, j, i+2, j+1);
         printf("    (dir = WN) & (p_%d_%d = q0) : q0;\n", i+2, j+1);
       }         
       printf("    1 : p_%d_%d;\n", i, j);
       printf("  esac;\n");
     }
   }
}

void Spec() {
   printf("SPEC\n");
   printf("  EF (");
   for (int i=1; i<=N; i++){
     for (int j=1; j<=N; j++){
       switch (initpos(i, j, N)) {
       case 0:
         printf("(p_%d_%d = q0)%s", i, j, (i == N && j == N) ? ")\n" : " & ");
         break;
       case 1:
         printf("(p_%d_%d = q2)%s", i, j, (i == N && j == N) ? ")\n" : " & ");
         break;
       case 2:
         printf("(p_%d_%d = q1)%s", i, j, (i == N && j == N) ? ")\n" : " & ");
         break;
       }
     }
   }
}

int main(int argc, char *argv[])
{
  if (argc<2) {
    fprintf(stderr, "ERROR: no #N specified.\n");
    return 1;
  }
  N = atoi(argv[1]);
  fprintf(stderr, "Size of board: %d.\n", N);
  if (N<2 || N%2==0) {
    fprintf(stderr, " ERROR: illegal size, %d. Expecting positive odd number.\n", N);
    return 2;
  }
  Init();
  Trans();
  Spec();	
  return 0;
}
