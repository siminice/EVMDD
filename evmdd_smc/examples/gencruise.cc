/*

  Program to generate a model for the EOFM cruise control

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STOPPED 	 0
#define SLOW 		 1
#define MODERATE 	 2
#define FAST 		 3
#define DESIRED 	 2

#define BEGIN_RAMP 	 6
#define END_RAMP	 5
#define AT_INTERSECTION	 0

#define SEMAPHORE_CYCLE	10
#define BEGIN_GREEN	10
#define END_GREEN	 5
#define BEGIN_YELLOW	 4
#define END_YELLOW	 4
#define BEGIN_RED	 3
#define END_RED		 0

#define DISABLED	 0
#define ENABLED		 1

int INIT_DISTANCE = 15;

void Init(){
   printf("Variables\n");
      printf("  semaphore      [0, %d]\n", SEMAPHORE_CYCLE);
      printf("  distance       [0, %d]\n", INIT_DISTANCE);
      printf("  speed          [%d, %d]\n", STOPPED, FAST);
      printf("  cruise         [0, 1]\n");
      printf("  cruise_speed   [%d, %d]\n", STOPPED, FAST);
   printf("Initial states\n");
      printf("  semaphore      = %d\n", SEMAPHORE_CYCLE);
      printf("  distance       = %d\n", INIT_DISTANCE);
      printf("  speed          = %d\n", SLOW);
      printf("  cruise         = %d\n", DISABLED);
      printf("  cruise_speed   = %d\n", STOPPED);
}

void Trans(){
   printf("Transitions\n");
     printf("  distance > %d /\\ speed < %d", BEGIN_RAMP, DESIRED);
     printf("  ->");
     printf("  semaphore\' = semaphore - 1 /\\ distance\' = distance - speed /\\ speed\' = speed + 1\n");

     printf("  distance > %d /\\ speed > %d", BEGIN_RAMP, DESIRED);
     printf("  ->");
     printf("  semaphore\' = semaphore - 1 /\\ distance\' = distance - speed /\\ speed\' = speed - 1\n");

     printf("  distance > %d /\\ speed = %d /\\ cruise = %d", BEGIN_RAMP, DESIRED, DISABLED);
     printf("  ->");
     printf("  semaphore\' = semaphore - 1 /\\ distance\' = distance - speed /\\ cruise\' = %d /\\ cruise_speed\' = speed\n", ENABLED);

     printf("  distance > %d /\\ speed = %d /\\ cruise = %d", BEGIN_RAMP, DESIRED, ENABLED);
     printf("  ->");
     printf("  semaphore\' = semaphore - 1 /\\ distance\' = distance - speed\n");

     printf("  distance >= %d /\\ distance <=%d", END_RAMP, BEGIN_RAMP);
     printf("  ->");
     printf("  semaphore\' = semaphore - 1 /\\ distance\' = distance - speed /\\ speed\' = speed + 1\n");

     printf("  distance >= %d /\\ distance <=%d", END_RAMP, BEGIN_RAMP);
     printf("  ->");
     printf("  semaphore\' = semaphore - 1 /\\ distance\' = distance - speed /\\ speed\' = speed - 1\n");

     printf("  distance <%d /\\ semaphore > %d /\\ speed = %d", END_RAMP, BEGIN_YELLOW, DESIRED);
     printf("  ->");
     printf("  semaphore\' = semaphore - 1 /\\ distance\' = distance - speed\n");

     printf("  distance <%d /\\ semaphore > %d /\\ cruise = %d /\\ speed > cruise_speed", END_RAMP, BEGIN_YELLOW, ENABLED);
     printf("  ->");
     printf("  semaphore\' = semaphore - 1 /\\ distance\' = distance - speed /\\ speed\' = speed - 1\n");

     printf("  distance <%d /\\ semaphore > %d /\\ cruise = %d /\\ speed < cruise_speed", END_RAMP, BEGIN_YELLOW, ENABLED);
     printf("  ->");
     printf("  semaphore\' = semaphore - 1 /\\ distance\' = distance - speed /\\ speed\' = speed + 1\n");

     printf("  distance <%d /\\ semaphore <= %d /\\ cruise = %d /\\ speed = cruise_speed", END_RAMP, BEGIN_YELLOW, ENABLED);
     printf("  ->");
     printf("  semaphore\' = semaphore - 1 /\\ distance\' = distance - speed\n");

     printf("  distance <%d /\\ semaphore <= %d /\\ cruise = %d /\\ speed = cruise_speed", END_RAMP, BEGIN_YELLOW, ENABLED);
     printf("  ->");
     printf("  semaphore\' = semaphore - 1 /\\ distance\' = distance - speed /\\ cruise\' = %d\n", DISABLED);

     printf("  distance <%d /\\ semaphore <= %d /\\ cruise = %d /\\ speed > cruise_speed", END_RAMP, BEGIN_YELLOW, ENABLED);
     printf("  ->");
     printf("  semaphore\' = semaphore - 1 /\\ distance\' = distance - speed /\\ speed\' = speed - 1\n");

     printf("  distance <%d /\\ semaphore <= %d /\\ cruise = %d /\\ speed > %d", END_RAMP, BEGIN_YELLOW, DISABLED, STOPPED);
     printf("  ->");
     printf("  semaphore\' = semaphore - 1 /\\ distance\' = distance - speed /\\ speed\' = speed - 1\n");

}

void Spec() {
    printf("Properties\n");
    printf("   distance >= %d \n", AT_INTERSECTION);
//    printf("  (distance = %d) /\\ (speed > %d)\n", AT_INTERSECTION, STOPPED);
}

int main(int argc, char *argv[])
{
  Init();
  Trans();
  Spec();	
  return 0;
}
