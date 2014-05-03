/*

  Program to generate a model for the round robin mutex

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int PROCS=-1;
bool spec=false;

void Init(){
   printf("Variables\n");
   printf("   resource [0, 1]\n");
   printf("   owner    [0, %d]\n", PROCS);
   for (int i=1; i<=PROCS;i++){
      printf("   buffer_%d  [0, 2]\n", i);
      printf("   process_%d [0, 4]\n", i);
   }
   printf("Initial states\n");
   printf("   resource = 1\n");
   printf("   owner    = 0\n");
   for (int i=1; i<=PROCS;i++){
      printf("   buffer_%d  = 0\n", i);
      printf("   process_%d = %d\n", i, (i==1?1:0));
   }
}

void Trans(){
   printf("Transitions\n");
   for (int i=1; i<=PROCS; i++) {
     printf("  resource = 1 /\\ process_%d = 1 -> resource\' = 0 /\\ owner\' = %d /\\ process_%d\' = 2\n", i, i, i);
     printf("  owner = %d /\\ buffer_%d = 0 -> owner\' = 0 /\\ buffer_%d\' = 1 /\\ resource\' = 1\n", i, i, i);
     printf("  buffer_%d = 1 /\\ process_%d = 2 -> buffer_%d\' = 0 /\\ process_%d\' = 4\n", i, i, i, i);
     printf("  buffer_%d = 1 /\\ process_%d = 3 -> buffer_%d\' = 0 /\\ process_%d\' = 0\n", i, i, i, i);
     printf("  process_%d = 2 /\\ process_%d = 0 -> process_%d\' = 3 /\\ process_%d\' = 1\n", i, i%PROCS+1, i, i%PROCS+1);
     printf("  process_%d = 4 /\\ process_%d = 0 -> process_%d\' = 0 /\\ process_%d\' = 1\n", i, i%PROCS+1, i, i%PROCS+1);
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
      PROCS = atoi(argv[i]);
      if (PROCS<2) {
        fprintf(stderr, " ERROR: illegal number of processes, %d.\n", PROCS);
        return 2;
      }
    }
  }
  if (PROCS == -1) {
    fprintf(stderr, "ERROR: no #PROCS specified.\n");
    return 1;
  }
  fprintf(stderr, "Number of processes: %d.\n", PROCS);
  Init();
  Trans();
  Spec();	
  return 0;
}
