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
   for (int i=0; i<ROWS; i++){
   for (int j=0; j<COLS; j++){
      printf("   s_%d_%d_x [0, %d]\n", i, j, ROWS-1);
      printf("   s_%d_%d_y [0, %d]\n", i, j, COLS-1);
   }
   }
   printf("Initial states\n");
   for (int i=0; i<ROWS; i++){
   for (int j=0; j<COLS; j++){
      printf("   s_%d_%d_x = %d\n", i, j, i);
      printf("   s_%d_%d_y = %d\n", i, j, j);
  }
  }
}

void Trans(){
   printf("Transitions\n");
   for (int i=0; i<ROWS; i++) {
   for (int j=0; j<COLS; j++) {
     if (i>0 || j>0) printf("  s_0_0_x = s_%d_%d_x+1 /\\ s_0_0_y = s_%d_%d_y -> s_0_0_x\' = s_%d_%d_x /\\ s_%d_%d_x\' = s_0_0_x\n", i, j, i, j, i, j, i, j);
     if (i>0 || j>0) printf("  s_0_0_x+1 = s_%d_%d_x /\\ s_0_0_y = s_%d_%d_y -> s_0_0_x\' = s_%d_%d_x /\\ s_%d_%d_x\' = s_0_0_x\n", i, j, i, j, i, j, i, j);
     if (i>0 || j>0) printf("  s_0_0_y = s_%d_%d_y+1 /\\ s_0_0_x = s_%d_%d_x -> s_0_0_y\' = s_%d_%d_y /\\ s_%d_%d_y\' = s_0_0_y\n", i, j, i, j, i, j, i, j);
     if (i>0 || j>0) printf("  s_0_0_y+1 = s_%d_%d_y /\\ s_0_0_x = s_%d_%d_x -> s_0_0_y\' = s_%d_%d_y /\\ s_%d_%d_y\' = s_0_0_y\n", i, j, i, j, i, j, i, j);
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
