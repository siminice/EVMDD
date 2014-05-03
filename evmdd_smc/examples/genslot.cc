/*

  Program to generate a slotted ring protocol model

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int SLOTS=-1;
bool spec=false;

void Init(){
   printf("Variables\n");
   for (int i=0; i<SLOTS;i++){
      printf("   a%d [1, 5]\n", i);
      printf("   h%d [1, 3]\n", i);
   }
   printf("Initial states\n");
   for (int i=0; i<SLOTS;i++){
      printf("   a%d = 3\n", i);
      printf("   h%d = 1\n", i);
   }
}

void Trans(){
   printf("Transitions\n");
   for (int i=0; i<SLOTS; i++) {
     printf("  a%d = 1 -> a%d\' = 4\n", i, i);
     printf("  a%d = 1 -> a%d\' = 2\n", i, i);
     printf("  a%d = 2 -> a%d\' = 4\n", i, i);
     printf("  a%d = 2 -> a%d\' = 5\n", i, i);
     printf("  a%d = 5 /\\ h%d = 2 -> a%d\' = 3 /\\ h%d\' = 1\n", i, i, i, i);
     printf("  a%d = 4 /\\ h%d = 2 -> a%d\' = 3 /\\ h%d\' = 3\n", i, i, i, i);
     printf("  a%d = 3 /\\ h%d = 3 -> a%d\' = 1 /\\ h%d\' = 2\n", (i+1)%SLOTS, i, (i+1)%SLOTS, i);
     printf("  a%d = 3 /\\ h%d = 1 -> a%d\' = 2 /\\ h%d\' = 2\n", (i+1)%SLOTS, i, (i+1)%SLOTS, i);
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
      SLOTS = atoi(argv[i]);
      if (SLOTS<2) {
        fprintf(stderr, " ERROR: illegal number of slots, %d.\n", SLOTS);
        return 2;
      }
    }
  }
  if (SLOTS == -1) {
    fprintf(stderr, "ERROR: no #slots specified.\n");
    return 1;
  }
  fprintf(stderr, "Number of slots: %d.\n", SLOTS);
  Init();
  Trans();
  Spec();	
  return 0;
}
