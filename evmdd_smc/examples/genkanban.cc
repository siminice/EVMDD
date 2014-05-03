/*

  Program to generate the kanban model

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N=-1;
bool spec=false;

void Init(){
   printf("Variables\n");
      printf("   pm1    [0, %d]\n", N);
      printf("   pback1 [0, %d]\n", N);
      printf("   pkan1  [0, %d]\n", N);
      printf("   pout1  [0, %d]\n", N);
      printf("   pm2    [0, %d]\n", N);
      printf("   pback2 [0, %d]\n", N);
      printf("   pkan2  [0, %d]\n", N);
      printf("   pout2  [0, %d]\n", N);
      printf("   pm3    [0, %d]\n", N);
      printf("   pback3 [0, %d]\n", N);
      printf("   pkan3  [0, %d]\n", N);
      printf("   pout3  [0, %d]\n", N);
      printf("   pm4    [0, %d]\n", N);
      printf("   pback4 [0, %d]\n", N);
      printf("   pkan4  [0, %d]\n", N);
      printf("   pout4  [0, %d]\n", N);
   printf("Initial states\n");
      printf("   pm1    = 0\n");
      printf("   pback1 = 0\n");
      printf("   pkan1  = %d\n", N);
      printf("   pout1  = 0\n");
      printf("   pm2    = 0\n");
      printf("   pback2 = 0\n");
      printf("   pkan2  = %d\n", N);
      printf("   pout2  = 0\n");
      printf("   pm3    = 0\n");
      printf("   pback3 = 0\n");
      printf("   pkan3  = %d\n", N);
      printf("   pout3  = 0\n");
      printf("   pm4    = 0\n");
      printf("   pback4 = 0\n");
      printf("   pkan4  = %d\n", N);
      printf("   pout4  = 0\n");
}

void Trans(){
   printf("Transitions\n");
     printf("  pkan1 > 0 -> pkan1\' = pkan1-1 /\\ pm1\' = pm1+1\n");
     printf("  pm1 > 0 -> pm1\' = pm1-1 /\\ pback1\' = pback1+1\n");
     printf("  pm1 > 0 -> pm1\' = pm1-1 /\\ pout1\' = pout1+1\n");
     printf("  pback1 > 0 -> pback1\' = pback1-1 /\\ pm1\' = pm1+1\n");

     printf("  pout1 > 0 /\\ pkan2 > 0 /\\ pkan3 > 0 -> pout1\' = pout1-1 /\\ pkan2\' = pkan2-1 /\\ pkan3\' = pkan3-1 /\\ pm2\' = pm2+1 /\\ pm3\' = pm3+1 /\\ pkan1\' = pkan1+1\n");
     printf("  pm2 > 0 -> pm2\' = pm2-1 /\\ pback2\' = pback2+1\n");
     printf("  pm2 > 0 -> pm2\' = pm2-1 /\\ pout2\' = pout2+1\n");
     printf("  pback2 > 0 -> pback2\' = pback2-1 /\\ pm2\' = pm2+1\n");
     printf("  pout2 > 0 /\\ pout3 > 0 /\\ pkan4 > 0 -> pout2\' = pout2-1 /\\ pout3\' = pout3-1 /\\ pkan4\' = pkan4-1 /\\ pkan2\' = pkan2+1 /\\ pkan3\' = pkan3+1 /\\ pm4\' = pm4+1\n");

     printf("  pm3 > 0 -> pm3\' = pm3-1 /\\ pback3\' = pback3+1\n");
     printf("  pm3 > 0 -> pm3\' = pm3-1 /\\ pout3\' = pout3+1\n");
     printf("  pback3 > 0 -> pback3\' = pback3-1 /\\ pm3\' = pm3+1\n");

     printf("  pm4 > 0 -> pm4\' = pm4-1 /\\ pback4\' = pback4+1\n");
     printf("  pm4 > 0 -> pm4\' = pm4-1 /\\ pout4\' = pout4+1\n");
     printf("  pback4 > 0 -> pback4\' = pback4-1 /\\ pm4\' = pm4+1\n");
     printf("  pout4 > 0 -> pout4\' = pout4-1 /\\ pkan4\' = pkan4+1\n");
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
      if (N<1) {
        fprintf(stderr, " ERROR: illegal parameter N = %d.\n", N);
        return 2;
      }
    }
  }
  if (N == -1) {
    fprintf(stderr, "ERROR: no initial value for N specified.\n");
    return 1;
  }
  fprintf(stderr, "Parameter N: %d.\n", N);
  Init();
  Trans();
  Spec();	
  return 0;
}
