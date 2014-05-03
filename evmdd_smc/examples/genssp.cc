/*

  Program to generate models of a self stabilization protocol

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define P		11
#define G		 3
#define F		 1
#define D		 1
#define d		 0
#define T_R		F+1
#define T_A		G-1
#define DELTA_MAX	G*(D+d)
#define DELTA_LIM	DELTA_MAX+1
#define DELTA_MIN	D
#define FAULTY		3
#define T		3*P+6

#define USS	0
#define UTP	1
#define PSS	2
#define BENIGN	3

#define NONE	0
#define RESTAB	1
#define ACCEPT	2

int dest(int i, int j) {
  // the destination node of a channel
  return j+1 - (i>j?1:0);
}

int idx(int i, int j) {
  // the index of the incoming channel
  return i - (i>j?1:0)
}

void Init(){
   printf("Variables\n");

   printf("  tick [0, %d]\n", T);
   printf("  ticket [0, 1]\n\n");

   for (int i=0; i<G; i++) {
     printf("  node_turn_%d     [0, 1]\n", i);
     printf("  node_state_%d    [0, %d]\n", i, PSS);
     printf("  node_delta_%d    [0, %d]\n", i, DELTA_LIM);
     printf("  node_delta_en_%d [0, 1]\n", i);
     printf("  node_timer_%d    [0, %d]\n\n", i, P);

     for (int j=0; j<G-1; j++) {
       printf("  mon_turn_%d_%d    [0, 1]\n", i, j);
       printf("  mon_state_%d_%d   [0, %d]\n", i, j, BENIGN);
       printf("  mon_delta_%d_%d   [0, %d]\n", i, j, DELTA_LIM);
       printf("  mon_message_%d_%d [0, %d]\n", i, j, ACCEPT);
       printf("  link_%d_%d        [0, %d]\n\n", i, j, ACCEPT);
     }
   }

   printf("Initial states\n");
   printf("  tick   = 0\n");
   printf("  ticket = 0\n\n");

   for (int i=0; i<G; i++) {
     printf("  node_turn_%d      = 0\n", i);
     printf("  node_state_%d    >= 0\n", i);
     printf("  node_delta_%d    >= 0\n", i);
     printf("  node_delta_en_%d >= 0\n", i);
     printf("  node_timer_%d    >= 0\n", i);

     for (int j=0; j<G-1; j++) {
       printf("  mon_turn_%d_%d     = 0\n", i, j);
       printf("  mon_state_%d_%d   >= 0\n", i, j);
       printf("  mon_delta_%d_%d   >= 0\n", i, j);
       printf("  mon_message_%d_%d >= 0\n", i, j);
       printf("  link_%d_%d        >= 0\n", i, j);
     }
   }

}


void Trans() {
  printf("Transitions\n");
  printf("  ticket = 0");
  for (int i=0; i<G; i++) for (int j=0; j<G-1; j++) printf(" /\\ mon_turn_%d_%d = 0", i, j);
  printf(" /\\ tick <= %d -> ", T);
  for (int i=0; i<G; i++) printf("node_turn_%d\' = 1 /\\ ", i);
  printf("ticket\' = 1 /\\ tick\' = tick+1\n");

  printf("  ticket = 1");
  for (int i=0; i<G; i++) printf(" /\\ node_turn_%d = 0", i);
  printf(" -> ");
  for (int i=0; i<G; i++) for (int j=0; j<G-1; j++) printf("mon_turn_%d_%d\' = 1 /\\ ", i, j);
  printf("ticket\' = 0\n");

  for (int i=0; i<G; i++) {
    printf("  node_turn_%d = 1 -> node_turn_%d\' = 0 /\\ node_timer_%d\' = (node_timer_%d + 1) %% %d\n", i, i, i, i, P);
  }

  for (int i=0; i<G; i++) {
  for (int j=0; j<G-1; j++) {
    printf("  mon_turn_%d_%d = 1 /\\ link_%d_%d = %d -> mon_turn_%d_%d\' = 0 /\\ link_%d_%d\' = %d /\\ mon_state_%d_%d\' = %d /\\ mon_delta_%d_%d\' = 0 /\\ mon_message_%d_%d\' = %d\n", i, j, i, j, RESTAB, i, j, i, j, NONE, i, j, USS, i, j, i, j, RESTAB);
    printf("  mon_turn_%d_%d = 1 /\\ link_%d_%d = %d /\\ mon_state_%d_%d = %d -> mon_turn_%d_%d\' = 0 /\\ mon_message_%d_%d\' = %d\n", i, j, i, j, NONE, i, j, BENIGN, i, j, i, j, NONE);
    printf("  mon_turn_%d_%d = 1 /\\ link_%d_%d = %d /\\ mon_state_%d_%d != %d /\\ mon_delta_%d_%d < %d -> mon_turn_%d_%d\' = 0 /\\ mon_delta_%d_%d\' = mon_delta_%d_%d + 1 /\\ mon_message_%d_%d\' = %d\n", i, j, i, j, NONE, i, j, BENIGN, i, j, DELTA_MAX, i, j, i, j, i, j, i, j, NONE);
    printf("  mon_turn_%d_%d = 1 /\\ link_%d_%d = %d /\\ mon_state_%d_%d = %d /\\ mon_delta_%d_%d >= %d /\\ mon_message_%d_%d != %d -> mon_turn_%d_%d\' = 0 /\\ mon_delta_%d_%d\' = %d /\\ mon_message_%d_%d\' = %d\n", i, j, i, j, NONE, i, j, USS, i, j, DELTA_MAX, i, j, ACCEPTED, i, j, i, j, DELTA_LIM, i, j, NONE);
    printf("  mon_turn_%d_%d = 1 /\\ link_%d_%d = %d /\\ mon_state_%d_%d = %d /\\ mon_delta_%d_%d >= %d /\\ mon_message_%d_%d = %d -> mon_turn_%d_%d\' = 0 /\\ mon_state_%d_%d = %d /\\ mon_delta_%d_%d\' = 0 /\\ mon_message_%d_%d\' = %d\n", i, j, i, j, NONE, i, j, USS, i, j, DELTA_MAX, i, j, ACCEPTED, i, j, i, j, BENIGN, i, j, i, j, NONE);
    printf("  mon_turn_%d_%d = 1 /\\ link_%d_%d = %d /\\ (mon_state_%d_%d = %d \\/ mon_state_%d_%d = %d) /\\ mon_delta_%d_%d >= %d -> mon_turn_%d_%d\' = 0 /\\ mon_state_%d_%d = %d /\\ mon_delta_%d_%d\' = 0 /\\ mon_message_%d_%d\' = %d\n", i, j, i, j, NONE, i, j, UTP, i, j, PSS, i, j, DELTA_MAX, i, j, i, j, BENIGN, i, j, i, j, NONE);

  }
  }
}

void Spec() {
    printf("Properties\n");
    printf("  !EX(true)\n");
}

int main(int argc, char *argv[])
{
  Init();
  Trans();
  Spec();
  return 0;
}
