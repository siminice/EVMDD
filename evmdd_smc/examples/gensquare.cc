/*

  Program to generate a model for the mxn puzzle

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ROWS=3;
int COLS=3;
bool spec=false;

void Init(){
   printf("Variables\n");
   for (int i=0; i<ROWS*COLS; i++){
      printf("   s%d [0, %d]\n", i, ROWS*COLS-1);
   }
   printf("Initial states\n");
   for (int i=0; i<ROWS*COLS; i++){
      printf("   s%d = %d\n", i, i);
  }
}

void Trans(){
   printf("Transitions\n");
   for (int i=0; i<ROWS; i++) {
   for (int j=0; j<COLS; j++) {
     if (j>0)      printf("  s%d = 0 -> s%d\' = s%d /\\ s%d\' = 0\n", i*COLS+j, i*COLS+j, i*COLS+(j-1), i*COLS+(j-1));
     if (i>0)      printf("  s%d = 0 -> s%d\' = s%d /\\ s%d\' = 0\n", i*COLS+j, i*COLS+j, (i-1)*COLS+j, (i-1)*COLS+j);
     if (j<COLS-1) printf("  s%d = 0 -> s%d\' = s%d /\\ s%d\' = 0\n", i*COLS+j, i*COLS+j, i*COLS+(j+1), i*COLS+(j+1));
     if (i<ROWS-1) printf("  s%d = 0 -> s%d\' = s%d /\\ s%d\' = 0\n", i*COLS+j, i*COLS+j, (i+1)*COLS+j, (i+1)*COLS+j);
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
    if (strcmp(argv[i], "-r")==0 && i<argc-1) {
      ROWS = atoi(argv[i+1]);
      if (ROWS<2) {
        fprintf(stderr, " ERROR: illegal number of rows, %d.\n", ROWS);
        return 2;
      }
    }
    else if (strcmp(argv[i], "-c")==0 && i<argc-1) {
      COLS = atoi(argv[i+1]);
      if (COLS<2) {
        fprintf(stderr, " ERROR: illegal number of columns, %d.\n", COLS);
        return 2;
      }
    }
  }
  fprintf(stderr, "Board size: %dx%d.\n", ROWS, COLS);
  Init();
  Trans();
  Spec();	
  return 0;
}
