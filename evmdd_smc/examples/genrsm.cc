/*

  Program to generate a model for Runway Safety Monitor algorithm

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ST_OUT		0
#define ST_TAXI		1
#define ST_TAKEOFF	2
#define ST_CLIMBING	3
#define ST_LANDING	4
#define ST_ROLLOUT	5
#define ST_FLYTHRU	6
#define NUM_STATUS	6

#define PH_RADAR_UPDATE	0
#define PH_SET_STATUS	1
#define PH_SET_ALARM	2
#define PH_DONE		3
#define NUM_PHASES	3

int TARGETS  = 1;
int X = 3;
int Y = 5;
int Z = 3;
int S = 2;

void Init(){
   printf("Variables\n");

   for (int i=0; i<=TARGETS; i++) {
     printf("  x%d      [0, %d]\n", i, X);
     printf("  y%d      [0, %d]\n", i, Y);
     printf("  z%d      [0, %d]\n", i, Z);
     printf("  vx%d     [0, %d]\n", i, S);
     printf("  vy%d     [0, %d]\n", i, 2*S);
     printf("  vz%d     [0, %d]\n", i, 2*S);
     printf("  state%d  [0, %d]\n", i, NUM_STATUS);
     printf("  phase%d  [0, %d]\n\n", i, NUM_PHASES);
   }

   for (int i=1; i<=TARGETS; i++) {
     printf("  alarm%d  [0, 1]\n\n", i);
   }

   printf("Initial states\n");
   for (int i=0; i<=TARGETS; i++) {
     printf("  x%d     = 0\n", i);
     printf("  y%d     = 0\n", i);
     printf("  z%d     = 0\n", i);
     printf("  vx%d    = 0\n", i);
     printf("  vy%d    = 0\n", i);
     printf("  vz%d    = 0\n", i);
     printf("  state%d = %d\n", i, ST_OUT);
     printf("  phase%d = %d\n\n", i, PH_RADAR_UPDATE);
   }

   for (int i=1; i<=TARGETS; i++) {
     printf("  alarm%d  = 0\n\n", i);
   }

}

void Trans(){
   printf("Transitions\n");
   for (int i=0; i<=TARGETS; i++) {

     /* ----------------
        target movement
     ------------------- */

     // --- stay out
     printf("  phase%d = %d /\\ x%d = 0", i, PH_RADAR_UPDATE, i);
     printf("  ->");
     printf("  phase%d\' = %d\n", i, PH_SET_STATUS, i);
     // --- enter left
     printf("  phase%d = %d /\\ x%d = 0", i, PH_RADAR_UPDATE, i);
     printf("  ->");
     printf("  phase%d\' = %d /\\ x%d\' = 1 /\\ y%d\' > 0 /\\ z%d\' > 0 /\\ vx%d\' > %d /\\ vy%d\' >= 0 /\\ vz%d\' >= 0\n", i, PH_SET_STATUS, i, i, i, i, S, i, i);
     // --- enter right
     printf("  phase%d = %d /\\ x%d = 0", i, PH_RADAR_UPDATE, i);
     printf("  ->");
     printf("  phase%d\' = %d /\\ x%d\' = %d /\\ y%d\' > 0 /\\ z%d\' > 0 /\\ vx%d\' < %d /\\ vy%d\' >= 0 /\\ vz%d\' >= 0\n", i, PH_SET_STATUS, i, X, i, i, i, S, i, i);
     // --- enter front
     printf("  phase%d = %d /\\ x%d = 0", i, PH_RADAR_UPDATE, i);
     printf("  ->");
     printf("  phase%d\' = %d /\\ x%d\' > 0 /\\ y%d\' = 1 /\\ z%d\' > 0 /\\ vx%d\' >= 0 /\\ vy%d\' > %d /\\ vz%d\' >= 0\n", i, PH_SET_STATUS, i, i, i, i, i, S, i);
     // --- enter back
     printf("  phase%d = %d /\\ x%d = 0", i, PH_RADAR_UPDATE, i);
     printf("  ->");
     printf("  phase%d\' = %d /\\ x%d\' > 0 /\\ y%d\' = %d /\\ z%d\' > 0 /\\ vx%d\' >= 0 /\\ vy%d\' < %d /\\ vz%d\' >= 0\n", i, PH_SET_STATUS, i, i, Y, i, i, i, S, i);
     // --- enter up
     printf("  phase%d = %d /\\ x%d = 0", i, PH_RADAR_UPDATE, i);
     printf("  ->");
     printf("  phase%d\' = %d /\\ x%d\' > 0 /\\ y%d\' > 0 /\\ z%d\' = %d /\\ vx%d\' >= 0 /\\ vy%d\' >= 0 /\\ vz%d\' < %d\n", i, PH_SET_STATUS, i, i, i, Z, i, i, i, S);
     // --- exit left
     printf("  phase%d = %d /\\ x%d = 1 /\\ vx%d <= %d", i, PH_RADAR_UPDATE, i, i, S);
     printf("  ->");
     printf("  phase%d\' = %d /\\ x%d\' = 0 /\\ y%d\' = 0 /\\ z%d\' = 0 /\\ vx%d\' = 0 /\\ vy%d\' = 0 /\\ vz%d\' = 0\n", i, PH_SET_STATUS, i, i, i, i, i, i);
     // --- exit right
     printf("  phase%d = %d /\\ x%d = %d /\\ vx%d >= %d", i, PH_RADAR_UPDATE, i, X, i, S);
     printf("  ->");
     printf("  phase%d\' = %d /\\ x%d\' = 0 /\\ y%d\' = 0 /\\ z%d\' = 0 /\\ vx%d\' = 0 /\\ vy%d\' = 0 /\\ vz%d\' = 0\n", i, PH_SET_STATUS, i, i, i, i, i, i);
     // --- exit front
     printf("  phase%d = %d /\\ y%d = 1 /\\ vy%d <= %d", i, PH_RADAR_UPDATE, i, i, S);
     printf("  ->");
     printf("  phase%d\' = %d /\\ x%d\' = 0 /\\ y%d\' = 0 /\\ z%d\' = 0 /\\ vx%d\' = 0 /\\ vy%d\' = 0 /\\ vz%d\' = 0\n", i, PH_SET_STATUS, i, i, i, i, i, i);
     // --- exit back
     printf("  phase%d = %d /\\ y%d = %d /\\ vy%d >= %d", i, PH_RADAR_UPDATE, i, Y, i, S);
     printf("  ->");
     printf("  phase%d\' = %d /\\ x%d\' = 0 /\\ y%d\' = 0 /\\ z%d\' = 0 /\\ vx%d\' = 0 /\\ vy%d\' = 0 /\\ vz%d\' = 0\n", i, PH_SET_STATUS, i, i, i, i, i, i);
     // --- exit up
     printf("  phase%d = %d /\\ z%d = %d /\\ vz%d >= %d", i, PH_RADAR_UPDATE, i, Z, i, S);
     printf("  ->");
     printf("  phase%d\' = %d /\\ x%d\' = 0 /\\ y%d\' = 0 /\\ z%d\' = 0 /\\ vx%d\' = 0 /\\ vy%d\' = 0 /\\ vz%d\' = 0\n", i, PH_SET_STATUS, i, i, i, i, i, i);
     // --- internal moves
     // -- x' = x + dx, y' = y + dy, z' = z + dz
     // -- stay within boundaries
     // -- speed change consistent with movement
     char vxmin[32], vxmax[32], vymin[32], vymax[32], vzmin[32], vzmax[32];
     char decvx[32], incvx[32], decvy[32], incvy[32], decvz[32], incvz[32];
     char vzero[32];
     sprintf(vxmin, "vx%d - 1", i);
     sprintf(vxmax, "vx%d + 1", i);
     sprintf(vymin, "vy%d - 1", i);
     sprintf(vymax, "vy%d + 1", i);
     sprintf(vzmin, "vz%d - 1", i);
     sprintf(vzmax, "vz%d + 1", i);
     sprintf(decvx, " /\\ vx%d\' < %d", i, S);
     sprintf(incvx, " /\\ vx%d\' > %d", i, S);
     sprintf(decvy, " /\\ vy%d\' < %d", i, S);
     sprintf(incvy, " /\\ vy%d\' > %d", i, S);
     sprintf(decvz, " /\\ vz%d\' < %d", i, S);
     sprintf(incvz, " /\\ vz%d\' > %d", i, S);
     sprintf(vzero, "%d", S);
     for (int dx = -1; dx <= 1; dx++)
     for (int dy = -1; dy <= 1; dy++)
     for (int dz = -1; dz <= 1; dz++) {
       printf("  phase%d = %d /\\ x%d > 0", i, PH_RADAR_UPDATE, i);
       printf(" /\\ x%d + %d > 2 /\\ x%d + %d <= %d", i, dx+2, i, dx+2, X+2);
       printf(" /\\ y%d + %d > 2 /\\ y%d + %d <= %d", i, dy+2, i, dy+2, Y+2);
       printf(" /\\ z%d + %d > 2 /\\ z%d + %d <= %d", i, dz+2, i, dz+2, Z+2);
       printf("  ->");
       printf("  phase%d\' = %d", i, PH_SET_STATUS);
       printf(" /\\ x%d\' + 2 = x%d + %d /\\ y%d\' + 2 = y%d + %d /\\ z%d\' + 2 = z%d + %d", i, i, dx+2, i, i, dy+2, i, i, dz+2);
       printf(" /\\ vx%d\' >= %s /\\ vx%d\' <= %s%s%s", i, vxmin, i, vxmax, (dx<0?decvx:""), (dx>0?incvx:""));
       printf(" /\\ vy%d\' >= %s /\\ vy%d\' <= %s%s%s", i, vymin, i, vymax, (dy<0?decvy:""), (dy>0?incvy:""));
       printf(" /\\ vz%d\' >= %s /\\ vz%d\' <= %s%s%s\n", i, vzmin, i, vzmax, (dz<0?decvz:""), (dz>0?incvz:""));
     }
     printf("\n");

     /* ----------------
        set status
     ------------------- */

     // --- move out of monitored zone
     printf("  phase%d = %d /\\ x%d = 0 /\\ y%d = 0 /\\ z%d = 0", i, PH_SET_STATUS, i, i, i);
     printf("  ->");
     printf("  phase%d\' = %d /\\ state%d\' = %d\n", i, PH_SET_ALARM, i, ST_OUT);
     // --- taxi: on the ground and (a) not aligned, vx!=0 (b) not on runway, or (c) slow
     printf("  phase%d = %d /\\ z%d = 1 /\\ vx%d != %d", i, PH_SET_STATUS, i, i, S);
     printf("  ->");
     printf("  phase%d\' = %d /\\ state%d\' = %d\n", i, PH_SET_ALARM, i, ST_TAXI);
     printf("  phase%d = %d /\\ z%d = 1 /\\ (x%d = 1 \\/ x%d = %d)", i, PH_SET_STATUS, i, i, i, X-1);
     printf("  ->");
     printf("  phase%d\' = %d /\\ state%d\' = %d\n", i, PH_SET_ALARM, i, ST_TAXI);
     printf("  phase%d = %d /\\ z%d = 1 /\\ vx%d >= %d /\\ vx%d <= %d", i, PH_SET_STATUS, i, i, S-S/2, i, S+S/2);
     printf("  ->");
     printf("  phase%d\' = %d /\\ state%d\' = %d\n", i, PH_SET_ALARM, i, ST_TAXI);
     // --- takeoff or rollout: on the ground, aligned (vx=0), on runway, and not slow
     printf("  phase%d = %d /\\ z%d = 1 /\\ x%d > 1 /\\ x%d < %d /\\ (vx%d < %d \\/ vx%d > %d)", i, PH_SET_STATUS, i, i, i, X-1, i, S-S/2, i, S+S/2);
     printf("  ->");
     printf("  phase%d\' = %d /\\ (state%d\' = %d \\/ state%d\' = %d)\n", i, PH_SET_ALARM, i, ST_TAKEOFF, i, ST_ROLLOUT);
     // --- climbing: airborne (z>1), aligned (vx=0), and climbing (vz>0)
     printf("  phase%d = %d /\\ z%d > 1 /\\ vx%d = %d /\\ vz%d > %d", i, PH_SET_STATUS, i, i, S, i, S);
     printf("  ->");
     printf("  phase%d\' = %d /\\ state%d\' = %d\n", i, PH_SET_ALARM, i, ST_CLIMBING);
     // --- landing: airborne (z>1), aligned (vx=0), and descending (vz<=0)
     printf("  phase%d = %d /\\ z%d > 1 /\\ vx%d = %d /\\ vz%d <= %d", i, PH_SET_STATUS, i, i, S, i, S);
     printf("  ->");
     printf("  phase%d\' = %d /\\ state%d\' = %d\n", i, PH_SET_ALARM, i, ST_LANDING);
     // --- flythru: airborne (z>1) but not aligned (vx!=0)
     printf("  phase%d = %d /\\ z%d > 1 /\\ vx%d != %d", i, PH_SET_STATUS, i, i, S);
     printf("  ->");
     printf("  phase%d\' = %d /\\ state%d\' = %d\n\n", i, PH_SET_ALARM, i, ST_FLYTHRU);
   }
     /* ----------------
        set alarm
     ------------------- */

   for (int i=1; i<=TARGETS; i++) {
     char min_sep[128];
     char same_dir[128];
     char opzt_dir[128];
     char closing_o[128];
     char closing_t[128];
     char in_path_o[128];
     char in_path_t[128];
     char tracking[128];
     sprintf(min_sep,  "(x0 - 1 <= x%d /\\ x%d <= x0 + 1 /\\ y0 - 1 <= y%d /\\ y%d <= y0 + 1 /\\ z0 - 1 <= z%d /\\ z%d <= x0 + 1)", i, i, i, i, i, i);
     sprintf(same_dir, "((vy0 > %d /\\ vy%d > %d) \\/ (vy0 < %d /\\ vy%d < %d))", S, i, S, S, i, S);
     sprintf(opzt_dir, "((vy0 > %d /\\ vy%d < %d) \\/ (vy0 < %d /\\ vy%d > %d))", S, i, S, S, i, S);
     sprintf(closing_o,  "((vy0 >= %d /\\ y%d >= y0) \\/ (vy0 <= %d /\\ y%d <= y0))", S, i, S, i);
     sprintf(closing_t,  "((vy%d >= %d /\\ y0 >= y%d) \\/ (vy%d <= %d /\\ y0 <= y%d))", i, S, i, i, S, i);
     sprintf(in_path_o,  "((vy0 < %d /\\ y%d <= y0) \\/ (vy0 > %d /\\ y%d >= y0))", S, i, S, i);
     sprintf(in_path_t,  "((vy%d < %d /\\ y0 <= y%d) \\/ (vy%d > %d /\\ y0 >= y%d))", i, S, i, i, S, i);
     sprintf(tracking, "(state0 >= %d /\\ state0 <= %d /\\ state%d >= %d /\\ state%d <= %d)", ST_TAKEOFF, ST_ROLLOUT, i, ST_TAKEOFF, i, ST_ROLLOUT);

     printf("  phase0 = %d /\\ phase%d = %d /\\ (", PH_SET_ALARM, i, PH_SET_ALARM);
     printf("(state0 = %d /\\ state%d >= %d /\\ state%d <= %d /\\ %s)", ST_TAXI, i, ST_TAKEOFF, i, ST_LANDING, closing_t);
     printf(" \\/ ");
     printf("(state%d = %d /\\ state0 >= %d /\\ state0 <= %d /\\ %s)", i, ST_TAXI, ST_TAKEOFF, ST_LANDING, closing_o);
     printf(" \\/ ");
     printf("(state0 = %d /\\ state%d = %d /\\ %s /\\ %s)", ST_TAXI, i, ST_ROLLOUT, closing_t, min_sep);
     printf(" \\/ ");
     printf("(state%d = %d /\\ state0 = %d /\\ %s /\\ %s)", i, ST_TAXI, ST_ROLLOUT, closing_o, min_sep);
     printf(" \\/ ");
     printf("(state0 >= %d /\\ state0 <= %d /\\ state%d = %d /\\ (%s \\/ (%s /\\ %s)))", ST_TAKEOFF, ST_ROLLOUT, i, ST_ROLLOUT, closing_o, same_dir, min_sep);
     printf(" \\/ ");
     printf("(state%d >= %d /\\ state%d <= %d /\\ state0 = %d /\\ (%s \\/ (%s /\\ %s)))", i, ST_TAKEOFF, i, ST_ROLLOUT, ST_ROLLOUT, closing_t, same_dir, min_sep);
     printf(" \\/ ");
     printf("(state0 = %d /\\ state%d >= %d /\\ state%d <= %d /\\ %s /\\ %s)", ST_FLYTHRU, i, ST_TAKEOFF, i, ST_ROLLOUT, in_path_t, min_sep);
     printf(" \\/ ");
     printf("(state%d = %d /\\ state0 >= %d /\\ state0 <= %d /\\ %s /\\ %s)", i, ST_FLYTHRU, ST_TAKEOFF, ST_ROLLOUT, in_path_o, min_sep);
     printf(")  ->");
     printf("  phase%d\' = %d /\\ alarm%d\' = 1\n", i, PH_DONE, i);

     printf("  phase0 = %d /\\ phase%d = %d /\\ !(", PH_SET_ALARM, i, PH_SET_ALARM);
     printf("(state0 = %d /\\ state%d >= %d /\\ state%d <= %d /\\ %s)", ST_TAXI, i, ST_TAKEOFF, i, ST_LANDING, closing_t);
     printf(" \\/ ");
     printf("(state%d = %d /\\ state0 >= %d /\\ state0 <= %d /\\ %s)", i, ST_TAXI, ST_TAKEOFF, ST_LANDING, closing_o);
     printf(" \\/ ");
     printf("(state0 = %d /\\ state%d = %d /\\ %s /\\ %s)", ST_TAXI, i, ST_ROLLOUT, closing_t, min_sep);
     printf(" \\/ ");
     printf("(state%d = %d /\\ state0 = %d /\\ %s /\\ %s)", i, ST_TAXI, ST_ROLLOUT, closing_o, min_sep);
     printf(" \\/ ");
     printf("(state0 >= %d /\\ state0 <= %d /\\ state%d = %d /\\ (%s \\/ (%s /\\ %s)))", ST_TAKEOFF, ST_ROLLOUT, i, ST_ROLLOUT, closing_o, same_dir, min_sep);
     printf(" \\/ ");
     printf("(state%d >= %d /\\ state%d <= %d /\\ state0 = %d /\\ (%s \\/ (%s /\\ %s)))", i, ST_TAKEOFF, i, ST_ROLLOUT, ST_ROLLOUT, closing_t, same_dir, min_sep);
     printf(" \\/ ");
     printf("(state0 = %d /\\ state%d >= %d /\\ state%d <= %d /\\ %s /\\ %s)", ST_FLYTHRU, i, ST_TAKEOFF, i, ST_ROLLOUT, in_path_t, min_sep);
     printf(" \\/ ");
     printf("(state%d = %d /\\ state0 >= %d /\\ state0 <= %d /\\ %s /\\ %s)", i, ST_FLYTHRU, ST_TAKEOFF, ST_ROLLOUT, in_path_o, min_sep);
     printf(")  ->");
     printf("  phase%d\' = %d /\\ alarm%d\' = 0\n", i, PH_DONE, i);
   }

     /* ----------------
        cycle done
     ------------------- */

   printf("  phase0 = %d", PH_SET_ALARM);
   for (int i=1; i<=TARGETS; i++) printf(" /\\ phase%d = %d", i, PH_DONE);
   printf("  ->");
   printf("  phase0\' = %d\n\n", PH_DONE);

   printf("  phase0 = %d", PH_DONE);
   printf("  ->");
   printf("  phase0\' = %d", PH_RADAR_UPDATE);
   for (int i=1; i<=TARGETS; i++) printf(" /\\ phase%d\' = %d /\\ alarm%d\' = 0", i, PH_RADAR_UPDATE, i);
   printf("\n\n");
}

void Spec() {
  printf("Properties\n");
  printf("  !EX(true)\n");
}

int main(int argc, char *argv[])
{
  for (int i = 1; i < argc; ++i) {
    if (strcmp(argv[i], "-t")==0 && i<argc-1) {
      TARGETS = atoi(argv[i+1]);
      if (TARGETS<1) {
        fprintf(stderr, " ERROR: invalid number of targets, %d.\n", TARGETS);
        fprintf(stderr, "        need at least 1 target.\n");
        return 2;
      }
    }
    else if (strcmp(argv[i], "-x")==0 && i<argc-1) {
      X = atoi(argv[i+1]);
      if (X<3) {
        fprintf(stderr, " ERROR: invalid number of X-axis divisions, %d.\n", X);
        fprintf(stderr, "        need X >= 3.\n");
        return 3;
      }
    }
    else if (strcmp(argv[i], "-y")==0 && i<argc-1) {
      Y = atoi(argv[i+1]);
      if (Y<3) {
        fprintf(stderr, " ERROR: invalid number of Y-axis divisions, %d.\n", Y);
        fprintf(stderr, "        need Y >= 3.\n");
        return 4;
      }
    }
    else if (strcmp(argv[i], "-z")==0 && i<argc-1) {
      Z = atoi(argv[i+1]);
      if (Z<2) {
        fprintf(stderr, " ERROR: invalid number of Z-axis divisions, %d.\n", Z);
        fprintf(stderr, "        need Z >= 2 (1:on-the-ground, 2:in-the-air).\n");
        return 5;
      }
    }
    else if (strcmp(argv[i], "-s")==0 && i<argc-1) {
      S = atoi(argv[i+1]);
      if (S<2) {
        fprintf(stderr, " ERROR: invalid number speed values, %d.\n", S);
        fprintf(stderr, "        need S >= 2 (0:stopped, 1:slow, 2:fast).\n");
        return 6;
      }
    }
  }

  Init();
  Trans();
  Spec();	
  return 0;
}
