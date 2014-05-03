/* Translation from a rubik's cube model from Benjamin Smith */


/* Each cube piece is indexed in a 3-dimensional coordinate system with values 0, 1, or 2;
 * 000 is a corner cube, 101 is cube in the center of a face, and so on. */

/* Matching between encoding of edges
 * in gencube_bsmith and rubik_edge.sm:
 *
 * front:
 *     102
 *     1
 * 001     201
 * 4       2
 *     100
 *     3
 * back:
 *     122
 *     5
 * 221     021
 * 6       8
 *     120
 *     7
 * right:
 *     212
 *     9
 * 201     221
 * 2       6
 *     210
 *     10
 * left:
 *     012
 *     12
 * 021     001
 * 8       4
 *     010
 *     11
 * top:
 *     122
 *     5
 * 012     212
 * 12      9
 *     102
 *     1
 *
 * bottom:
 *     100
 *     3
 * 010     210
 * 11      10
 *     120
 *     7
 */

/* Matching between encoding of corners
 * in gencube_bsmith and whole_cube_cw2.sm:
 *
 * front:
 * 002 202
 * 1   2
 * 000 200
 * 4   3
 *
 * back:
 * 222 022
 * 5   6
 * 220 020
 * 8   7
 */

/* Matching between encoding of centers
 * in gencube_bsmith and whole_cube_all_plus_center.sm:
 *
 * front: Center101 1
 * back: Center121 6
 * right: Center211 3
 * left: Center011 5
 * top: Center112 2
 * bottom: Center110 4
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int withCorner = 1;
int withEdge = 1;
int withCenter = 0;
int bothDir = 1;
int OrFlag = 0;
int HalfFlag = 0;
int DoX = 0;
int DoY = 0;
int DoZ = 0;

// For corners, Next(i,j): 00 => 02 => 22 => 20 => 00 => ...
int iNextCorn(int i, int j) {
  if (i == 0 && j == 0)
    return 0;
  else if (i == 0 && j == 2)
    return 2;
  else if (i == 2 && j == 2)
    return 2;
  else if (i == 2 && j == 0)
    return 0;
  else
    exit(2);
}

int jNextCorn(int i, int j) {
  if (i == 0 && j == 0)
    return 2;
  else if (i == 0 && j == 2)
    return 2;
  else if (i == 2 && j == 2)
    return 0;
  else if (i == 2 && j == 0)
    return 0;
  else
    exit(2);
}

int iPrevCorn(int i, int j) {
  if (i == 0 && j == 0)
    return 2;
  else if (i == 0 && j == 2)
    return 0;
  else if (i == 2 && j == 2)
    return 0;
  else if (i == 2 && j == 0)
    return 2;
  else
    exit(2);
}

int jPrevCorn(int i, int j) {
  if (i == 0 && j == 0)
    return 0;
  else if (i == 0 && j == 2)
    return 0;
  else if (i == 2 && j == 2)
    return 2;
  else if (i == 2 && j == 0)
    return 2;
  else
    exit(2);
}

int iHalfCorn(int i, int j) {
  if (i == 0 && j == 0)
    return 2;
  else if (i == 0 && j == 2)
    return 2;
  else if (i == 2 && j == 2)
    return 0;
  else if (i == 2 && j == 0)
    return 0;
  else
    exit(2);
}

int jHalfCorn(int i, int j) {
  if (i == 0 && j == 0)
    return 2;
  else if (i == 0 && j == 2)
    return 0;
  else if (i == 2 && j == 2)
    return 0;
  else if (i == 2 && j == 0)
    return 2;
  else
    exit(2);
}

// For edges,   Next(i,j): 01 => 12 => 21 => 10 => 01 => ...
int iNextEdge(int i, int j) {
  if (i == 0 && j == 1)
    return 1;
  else if (i == 1 && j == 2)
    return 2;
  else if (i == 2 && j == 1)
    return 1;
  else if (i == 1 && j == 0)
    return 0;
  else
    exit(2);
}

int jNextEdge(int i, int j) {
  if (i == 0 && j == 1)
    return 2;
  else if (i == 1 && j == 2)
    return 1;
  else if (i == 2 && j == 1)
    return 0;
  else if (i == 1 && j == 0)
    return 1;
  else
    exit(2);
}

int iPrevEdge(int i, int j) {
  if (i == 0 && j == 1)
    return 1;
  else if (i == 1 && j == 2)
    return 0;
  else if (i == 2 && j == 1)
    return 1;
  else if (i == 1 && j == 0)
    return 2;
  else
    exit(2);
}

int jPrevEdge(int i, int j) {
  if (i == 0 && j == 1)
    return 0;
  else if (i == 1 && j == 2)
    return 1;
  else if (i == 2 && j == 1)
    return 2;
  else if (i == 1 && j == 0)
    return 1;
  else
    exit(2);
}

int iHalfEdge(int i, int j) {
  if (i == 0 && j == 1)
    return 2;
  else if (i == 1 && j == 2)
    return 1;
  else if (i == 2 && j == 1)
    return 0;
  else if (i == 1 && j == 0)
    return 1;
  else
    exit(2);
}

int jHalfEdge(int i, int j) {
  if (i == 0 && j == 1)
    return 1;
  else if (i == 1 && j == 2)
    return 0;
  else if (i == 2 && j == 1)
    return 1;
  else if (i == 1 && j == 0)
    return 2;
  else
    exit(2);
}

int xCornOr(int x, int i, int j) {
  if (i == j)
    return x?1:2;
  else
    return x?2:1;
}

int yCornOr(int y, int i, int j) {
  if (i == j)
    return y?2:1;
  else
    return y?1:2;
}

void Init(){
  int l;

  printf("Variables\n");

  // Order for corners only
  if (withCorner && OrFlag) printf("  CornOr222 [0, 2]\n");
  if (withCorner && OrFlag) printf("  CornOr220 [0, 2]\n");
  if (withCorner && OrFlag) printf("  CornOr202 [0, 2]\n");
  if (withCorner && OrFlag) printf("  CornOr200 [0, 2]\n");
  if (withCorner && OrFlag) printf("  CornOr022 [0, 2]\n");
  if (withCorner && OrFlag) printf("  CornOr020 [0, 2]\n");
  if (withCorner && OrFlag) printf("  CornOr002 [0, 2]\n");
  if (withCorner && OrFlag) printf("  CornOr000 [0, 2]\n");
  if (withCorner) printf("  Corn222 [0, 7]\n");
  if (withCorner) printf("  Corn220 [0, 7]\n");
  if (withCorner) printf("  Corn202 [0, 7]\n");
  if (withCorner) printf("  Corn200 [0, 7]\n");
  if (withCorner) printf("  Corn022 [0, 7]\n");
  if (withCorner) printf("  Corn020 [0, 7]\n");
  if (withCorner) printf("  Corn002 [0, 7]\n");
  if (withCorner) printf("  Corn000 [0, 7]\n");

//   // Order for edges only from rubik_edges.sm
//   if (withEdge) printf("  Edge212 [0, 11]\n");
//   if (withEdge) printf("  Edge201 [0, 11]\n");
//   if (withEdge) printf("  Edge100 [0, 11]\n");
//   if (withEdge) printf("  Edge210 [0, 11]\n");
//   if (withEdge) printf("  Edge221 [0, 11]\n");
//   if (withEdge) printf("  Edge122 [0, 11]\n");
//   if (withEdge) printf("  Edge120 [0, 11]\n");
//   if (withEdge) printf("  Edge021 [0, 11]\n");
//   if (withEdge) printf("  Edge010 [0, 11]\n");
//   if (withEdge) printf("  Edge001 [0, 11]\n");
//   if (withEdge) printf("  Edge012 [0, 11]\n");
//   if (withEdge) printf("  Edge102 [0, 11]\n");
//   if (withEdge && OrFlag) printf("  EdgeOr102 [0, 1]\n");
//   if (withEdge && OrFlag) printf("  EdgeOr201 [0, 1]\n");
//   if (withEdge && OrFlag) printf("  EdgeOr100 [0, 1]\n");
//   if (withEdge && OrFlag) printf("  EdgeOr001 [0, 1]\n");
//   if (withEdge && OrFlag) printf("  EdgeOr010 [0, 1]\n");
//   if (withEdge && OrFlag) printf("  EdgeOr210 [0, 1]\n");
//   if (withEdge && OrFlag) printf("  EdgeOr120 [0, 1]\n");
//   if (withEdge && OrFlag) printf("  EdgeOr221 [0, 1]\n");
//   if (withEdge && OrFlag) printf("  EdgeOr212 [0, 1]\n");
//   if (withEdge && OrFlag) printf("  EdgeOr122 [0, 1]\n");
//   if (withEdge && OrFlag) printf("  EdgeOr021 [0, 1]\n");
//   if (withEdge && OrFlag) printf("  EdgeOr012 [0, 1]\n");

//   // Order for whole cube from whole_cube_quarters.sm
//   if (withCorner) printf("  Corn222 [0, 7]\n");
//   if (withCorner) printf("  Corn220 [0, 7]\n");
//   if (withCorner) printf("  Corn000 [0, 7]\n");
//   if (withCorner) printf("  Corn002 [0, 7]\n");
//   if (withCorner) printf("  Corn200 [0, 7]\n");
//   if (withCorner) printf("  Corn202 [0, 7]\n");
//   if (withCorner) printf("  Corn022 [0, 7]\n");
//   if (withCorner) printf("  Corn020 [0, 7]\n");
//   if (withCorner && OrFlag) printf("  CornOr002 [0, 2]\n");
//   if (withCorner && OrFlag) printf("  CornOr202 [0, 2]\n");
//   if (withCorner && OrFlag) printf("  CornOr000 [0, 2]\n");
//   if (withCorner && OrFlag) printf("  CornOr200 [0, 2]\n");
//   if (withCorner && OrFlag) printf("  CornOr020 [0, 2]\n");
//   if (withCorner && OrFlag) printf("  CornOr022 [0, 2]\n");
//   if (withCorner && OrFlag) printf("  CornOr220 [0, 2]\n");
//   if (withCorner && OrFlag) printf("  CornOr222 [0, 2]\n");
//   if (withEdge) printf("  Edge001 [0, 11]\n");
//   if (withEdge) printf("  Edge102 [0, 11]\n");
//   if (withEdge) printf("  Edge100 [0, 11]\n");
//   if (withEdge) printf("  Edge201 [0, 11]\n");
//   if (withEdge) printf("  Edge210 [0, 11]\n");
//   if (withEdge) printf("  Edge212 [0, 11]\n");
//   if (withEdge) printf("  Edge221 [0, 11]\n");
//   if (withEdge) printf("  Edge122 [0, 11]\n");
//   if (withEdge) printf("  Edge021 [0, 11]\n");
//   if (withEdge) printf("  Edge120 [0, 11]\n");
//   if (withEdge) printf("  Edge010 [0, 11]\n");
//   if (withEdge) printf("  Edge012 [0, 11]\n");
//   if (withEdge && OrFlag) printf("  EdgeOr001 [0, 1]\n");
//   if (withEdge && OrFlag) printf("  EdgeOr102 [0, 1]\n");
//   if (withEdge && OrFlag) printf("  EdgeOr100 [0, 1]\n");
//   if (withEdge && OrFlag) printf("  EdgeOr201 [0, 1]\n");
//   if (withEdge && OrFlag) printf("  EdgeOr210 [0, 1]\n");
//   if (withEdge && OrFlag) printf("  EdgeOr212 [0, 1]\n");
//   if (withEdge && OrFlag) printf("  EdgeOr221 [0, 1]\n");
//   if (withEdge && OrFlag) printf("  EdgeOr122 [0, 1]\n");
//   if (withEdge && OrFlag) printf("  EdgeOr021 [0, 1]\n");
//   if (withEdge && OrFlag) printf("  EdgeOr120 [0, 1]\n");
//   if (withEdge && OrFlag) printf("  EdgeOr010 [0, 1]\n");
//   if (withEdge && OrFlag) printf("  EdgeOr012 [0, 1]\n");
//   if (withCenter) printf("  Center101 [0, 3]\n");
//   if (withCenter) printf("  Center121 [0, 3]\n");
//   if (withCenter) printf("  Center211 [0, 3]\n");
//   if (withCenter) printf("  Center011 [0, 3]\n");
//   if (withCenter) printf("  Center112 [0, 3]\n");
//   if (withCenter) printf("  Center110 [0, 3]\n");

  printf("Initial states\n");
  
  if (withCorner) {
    printf("  /* Initialize cube corners */\n");
    for (int i=0; i<=2; i+=2)
      for (int j=0; j<=2; j+=2)
        for (int k=0; k<=2; k+=2)
          printf("  Corn%d%d%d = %d\n", i, j, k, (i<<1)|j|(k>>1));
  }
  if (withEdge) {
    printf("  /* Initialize cube edges */\n");
    l = 0;
    for (int i=0; i<=2; ++i)
      for (int j=0; j<=2; j+=(i==1)?2:1)
        for (int k=(i==1||j==1)?0:1; k<=((i==1&&j==1)?-1:2); k+=2)
          printf("  Edge%d%d%d = %d\n", i, j, k, l++);
  }
  if (OrFlag) {
    if (withCorner) {
      printf("  /* Initialize cube corner orientations */\n");
      for (int i=0; i<=2; i+=2)
        for (int j=0; j<=2; j+=2)
          for (int k=0; k<=2; k+=2)
            printf("  CornOr%d%d%d = 0\n", i, j, k);
    }
    if (withEdge) {
      printf("  /* Initialize cube edge orientations */\n");
      for (int i=0; i<=2; ++i)
        for (int j=0; j<=2; j+=(i==1)?2:1)
          for (int k=(i==1||j==1)?0:1; k<=((i==1&&j==1)?-1:2); k+=2)
            printf("  EdgeOr%d%d%d = 0\n", i, j, k);
    }
  }
  if (withCenter) {
    printf("  /* Initialize center cube orientations */\n");
    printf("  Center101 = 0\n");
    printf("  Center121 = 0\n");
    printf("  Center211 = 0\n");
    printf("  Center011 = 0\n");
    printf("  Center112 = 0\n");
    printf("  Center110 = 0\n");
  }
}

void Trans(){
  printf("Transitions\n");
  if (DoX) {
    for (int x = 0; x <= 2; x += 2) {
      if (HalfFlag) {
        printf("  /* %s, half turn */\n", x ? "right" : "left");
        printf("  ");
        if (withCorner) {
          for (int i = 0; i <= 2; i += 2)
            for (int j = 0; j <= 2; j += 2)
              printf("Corn%d%d%d' = Corn%d%d%d%s",
                     x, iHalfCorn(i, j), jHalfCorn(i, j),
                     x, i, j,
                     OrFlag || withEdge || withCenter || i != 2 || j != 2 ? " /\\ " : "");
          if (OrFlag)
            for (int i = 0; i <= 2; i += 2)
              for (int j = 0; j <= 2; j += 2)
                printf("CornOr%d%d%d' = CornOr%d%d%d%s",
                       x, iHalfCorn(i, j), jHalfCorn(i, j),
                       x, i, j,
                       withEdge || withCenter || i != 2 || j != 2 ? " /\\ " : "");
        }
        if (withEdge) {
          for (int i = 0; i <= 2; ++i)
            for (int j = i==1?0:1; j <= (i==1?2:1); j += 2)
              printf("Edge%d%d%d' = Edge%d%d%d%s",
                     x, iHalfEdge(i, j), jHalfEdge(i, j),
                     x, i, j,
                     OrFlag || withCenter || i != 2 || j != 1 ? " /\\ " :"");
          if (OrFlag)
            for (int i = 0; i <= 2; ++i)
              for (int j = i==1?0:1; j <= (i==1?2:1); j += 2)
                printf("EdgeOr%d%d%d' = EdgeOr%d%d%d%s",
                       x, iHalfEdge(i, j), jHalfEdge(i, j),
                       x, i, j,
                       withCenter || i != 2 || j != 1 ? " /\\ " : "");
        }
        if (withCenter)
          printf("Center%d11' = (Center%d11+2)%%4", x, x);
        printf("\n");
      }
      if (bothDir || x == 2) {
        printf("  /* %s, %sclockwise quarter turn */\n", x ? "right" : "left", x ? "" : "counter-");
        printf("  ");
        if (withCorner) {
          for (int i = 0; i <= 2; i += 2)
            for (int j = 0; j <= 2; j += 2)
              printf("Corn%d%d%d' = Corn%d%d%d%s",
                     x, iNextCorn(i, j), jNextCorn(i, j),
                     x, i, j,
                     OrFlag || withEdge || withCenter || i != 2 || j != 2 ? " /\\ " : "");
          if (OrFlag)
            for (int i = 0; i <= 2; i += 2)
              for (int j = 0; j <= 2; j += 2)
                printf("CornOr%d%d%d' = (CornOr%d%d%d+%d)%%3%s",
                       x, iNextCorn(i, j), jNextCorn(i, j),
                       x, i, j, xCornOr(x, i, j),
                       withEdge || withCenter || i != 2 || j != 2 ? " /\\ " : "");
        }
        if (withEdge) {
          for (int i = 0; i <= 2; ++i)
            for (int j = i==1?0:1; j <= (i==1?2:1); j += 2)
              printf("Edge%d%d%d' = Edge%d%d%d%s",
                     x, iNextEdge(i, j), jNextEdge(i, j),
                     x, i, j,
                     OrFlag || withCenter || i != 2 || j != 1 ? " /\\ " : "");
          if (OrFlag)
            for (int i = 0; i <= 2; ++i)
              for (int j = i==1?0:1; j <= (i==1?2:1); j += 2)
                printf("EdgeOr%d%d%d' = 1-EdgeOr%d%d%d%s",
                       x, iNextEdge(i, j), jNextEdge(i, j),
                       x, i, j,
                       withCenter || i != 2 || j != 1 ? " /\\ " : "");
        }
        if (withCenter)
          printf("Center%d11' = (Center%d11+%d)%%4", x, x, x ? 1 : 3);
        printf("\n");
      }
      if (bothDir || x == 0) {
        printf("  /* %s, %sclockwise quarter turn */\n", x ? "right" : "left", x ? "counter-" : "");
        printf("  ");
        if (withCorner) {
          for (int i = 0; i <= 2; i += 2)
            for (int j = 0; j <= 2; j += 2)
              printf("Corn%d%d%d' = Corn%d%d%d%s",
                     x, iPrevCorn(i, j), jPrevCorn(i, j),
                     x, i, j,
                     OrFlag || withEdge || withCenter || i != 2 || j != 2 ? " /\\ " : "");
          if (OrFlag)
            for (int i = 0; i <= 2; i += 2)
              for (int j = 0; j <= 2; j += 2)
                printf("CornOr%d%d%d' = (CornOr%d%d%d+%d)%%3%s",
                       x, iPrevCorn(i, j), jPrevCorn(i, j),
                       x, i, j, xCornOr(x, i, j),
                       withEdge || withCenter || i != 2 || j != 2 ? " /\\ " : "");
        }
        if (withEdge) {
          for (int i = 0; i <= 2; ++i)
            for (int j = i==1?0:1; j <= (i==1?2:1); j += 2)
              printf("Edge%d%d%d' = Edge%d%d%d%s",
                     x, iPrevEdge(i, j), jPrevEdge(i, j),
                     x, i, j,
                     OrFlag || withCenter || i != 2 || j != 1 ? " /\\ " : "");
          if (OrFlag)
            for (int i = 0; i <= 2; ++i)
              for (int j = i==1?0:1; j <= (i==1?2:1); j += 2)
                printf("EdgeOr%d%d%d' = 1-EdgeOr%d%d%d%s",
                       x, iPrevEdge(i, j), jPrevEdge(i, j),
                       x, i, j,
                       withCenter || i != 2 || j != 1 ? " /\\ " : "");
        }
        if (withCenter)
          printf("Center%d11' = (Center%d11+%d)%%4", x, x, x ? 3 : 1);
        printf("\n");
      }
    }
  }
  if (DoY) {
    for (int y = 0; y <= 2; y += 2) {
      if (HalfFlag) {
        printf("  /* %s, half turn */\n", y ? "back" : "front");
        printf("  ");
        if (withCorner) {
          for (int i = 0; i <= 2; i += 2)
            for (int j = 0; j <= 2; j += 2)
              printf("Corn%d%d%d' = Corn%d%d%d%s",
                     iHalfCorn(i, j), y, jHalfCorn(i, j),
                     i, y, j,
                     OrFlag || withEdge || withCenter || i != 2 || j != 2 ? " /\\ " : "");
          if (OrFlag)
            for (int i = 0; i <= 2; i += 2)
              for (int j = 0; j <= 2; j += 2)
                printf("CornOr%d%d%d' = CornOr%d%d%d%s",
                       iHalfCorn(i, j), y, jHalfCorn(i, j),
                       i, y, j,
                       withEdge || withCenter || i != 2 || j != 2 ? " /\\ " : "");
        }
        if (withEdge) {
          for (int i = 0; i <= 2; ++i)
            for (int j = i==1?0:1; j <= (i==1?2:1); j += 2)
              printf("Edge%d%d%d' = Edge%d%d%d%s",
                     iHalfEdge(i, j), y, jHalfEdge(i, j),
                     i, y, j,
                     OrFlag || withCenter || i != 2 || j != 1 ? " /\\ " : "");
          if (OrFlag)
            for (int i = 0; i <= 2; ++i)
              for (int j = i==1?0:1; j <= (i==1?2:1); j += 2)
                printf("EdgeOr%d%d%d' = EdgeOr%d%d%d%s",
                       iHalfEdge(i, j), y, jHalfEdge(i, j),
                       i, y, j,
                       withCenter || i != 2 || j != 1 ? " /\\ " : "");
        }
        if (withCenter)
          printf("Center1%d1' = (Center1%d1+2)%%4", y, y);
        printf("\n");
      }
      if (bothDir || y == 2) {
        printf("  /* %s, %sclockwise quarter turn */\n", y ? "back" : "front", y ? "" : "counter-");
        printf("  ");
        if (withCorner) {
          for (int i = 0; i <= 2; i += 2)
            for (int j = 0; j <= 2; j += 2)
              printf("Corn%d%d%d' = Corn%d%d%d%s",
                     iNextCorn(i, j), y ,jNextCorn(i, j),
                     i, y, j,
                     OrFlag || withEdge || withCenter || i != 2 || j != 2 ? " /\\ " : "");
          if (OrFlag)
            for (int i = 0; i <= 2; i += 2)
              for (int j = 0; j <= 2; j += 2)
                printf("CornOr%d%d%d' = (CornOr%d%d%d+%d)%%3%s",
                       iNextCorn(i, j), y, jNextCorn(i, j),
                       i, y, j, yCornOr(y, i, j),
                       withEdge || withCenter || i != 2 || j != 2 ? " /\\ " : "");
        }
        if (withEdge) {
          for (int i = 0; i <= 2; ++i)
            for (int j = i==1?0:1; j <= (i==1?2:1); j += 2)
              printf("Edge%d%d%d' = Edge%d%d%d%s",
                     iNextEdge(i, j), y ,jNextEdge(i, j),
                     i, y, j,
                     OrFlag || withCenter || i != 2 || j != 1 ? " /\\ " : "");
          if (OrFlag)
            for (int i = 0; i <= 2; ++i)
              for (int j = i==1?0:1; j <= (i==1?2:1); j += 2)
                printf("EdgeOr%d%d%d' = EdgeOr%d%d%d%s",
                       iNextEdge(i, j), y ,jNextEdge(i, j),
                       i, y, j,
                       withCenter || i != 2 || j != 1 ? " /\\ " : "");
        }
        if (withCenter)
          printf("Center1%d1' = (Center1%d1+%d)%%4", y, y, y ? 1 : 3);
        printf("\n");
      }
      if (bothDir || y == 0) {
        printf("  /* %s, %sclockwise quarter turn */\n", y ? "back" : "front", y ? "counter-" : "");
        printf("  ");
        if (withCorner) {
          for (int i = 0; i <= 2; i += 2)
            for (int j = 0; j <= 2; j += 2)
              printf("Corn%d%d%d' = Corn%d%d%d%s",
                     iPrevCorn(i, j), y, jPrevCorn(i, j),
                     i, y, j,
                     OrFlag || withEdge || withCenter || i != 2 || j != 2 ? " /\\ " : "");
          if (OrFlag)
            for (int i = 0; i <= 2; i += 2)
              for (int j = 0; j <= 2; j += 2)
                printf("CornOr%d%d%d' = (CornOr%d%d%d+%d)%%3%s",
                       iPrevCorn(i, j), y, jPrevCorn(i, j),
                       i, y, j, yCornOr(y, i, j),
                       withEdge || withCenter || i != 2 || j != 2 ? " /\\ " : "");
        }
        if (withEdge) {
          for (int i = 0; i <= 2; ++i)
            for (int j = i==1?0:1; j <= (i==1?2:1); j += 2)
              printf("Edge%d%d%d' = Edge%d%d%d%s",
                     iPrevEdge(i, j), y, jPrevEdge(i, j),
                     i, y, j,
                     OrFlag || withCenter || i != 2 || j != 1 ? " /\\ " : "");
          if (OrFlag)
            for (int i = 0; i <= 2; ++i)
              for (int j = i==1?0:1; j <= (i==1?2:1); j += 2)
                printf("EdgeOr%d%d%d' = EdgeOr%d%d%d%s",
                       iPrevEdge(i, j), y, jPrevEdge(i, j),
                       i, y, j,
                       withCenter || i != 2 || j != 1 ? " /\\ " : "");
        }
        if (withCenter)
          printf("Center1%d1' = (Center1%d1+%d)%%4", y, y, y ? 3 : 1);
        printf("\n");
      }
    }
  }
  if (DoZ) {
    for (int z = 0; z <= 2; z += 2) {
      if (HalfFlag) {
        printf("  /* %s, half turn */\n", z ? "up" : "down");
        printf("  ");
        if (withCorner) {
          for (int i = 0; i <= 2; i += 2)
            for (int j = 0; j <= 2; j += 2)
              printf("Corn%d%d%d' = Corn%d%d%d%s",
                     iHalfCorn(i, j), jHalfCorn(i, j), z,
                     i, j, z,
                     OrFlag || withEdge || withCenter || i != 2 || j != 2 ? " /\\ " : "");
          if (OrFlag)
            for (int i = 0; i <= 2; i += 2)
              for (int j = 0; j <= 2; j += 2)
                printf("CornOr%d%d%d' = CornOr%d%d%d%s",
                       iHalfCorn(i, j), jHalfCorn(i, j), z,
                       i, j, z,
                       withEdge || withCenter || i != 2 || j != 2 ? " /\\ " : "");
        }
        if (withEdge) {
          for (int i = 0; i <= 2; ++i)
            for (int j = i==1?0:1; j <= (i==1?2:1); j += 2)
              printf("Edge%d%d%d' = Edge%d%d%d%s",
                     iHalfEdge(i, j), jHalfEdge(i, j), z,
                     i, j, z,
                     OrFlag || withCenter || i != 2 || j != 1 ? " /\\ " : "");
          if (OrFlag)
            for (int i = 0; i <= 2; ++i)
              for (int j = i==1?0:1; j <= (i==1?2:1); j += 2)
                printf("EdgeOr%d%d%d' = EdgeOr%d%d%d%s",
                       iHalfEdge(i, j), jHalfEdge(i, j), z,
                       i, j, z,
                       withCenter || i != 2 || j != 1 ? " /\\ " : "");
        }
        if (withCenter)
          printf("Center11%d' = (Center11%d+2)%%4", z, z);
        printf("\n");
      }
      if (bothDir || z == 2) {
        printf("  /* %s, %sclockwise quarter turn */\n", z ? "up" : "down", z ? "" : "counter-");
        printf("  ");
        if (withCorner) {
          for (int i = 0; i <= 2; i += 2)
            for (int j = 0; j <= 2; j += 2)
              printf("Corn%d%d%d' = Corn%d%d%d%s",
                     iNextCorn(i, j), jNextCorn(i, j), z,
                     i, j, z,
                     OrFlag || withEdge || withCenter || i != 2 || j != 2 ? " /\\ " : "");
          if (OrFlag)
            for (int i = 0; i <= 2; i += 2)
              for (int j = 0; j <= 2; j += 2)
                printf("CornOr%d%d%d' = CornOr%d%d%d%s",
                       iNextCorn(i, j), jNextCorn(i, j), z,
                       i, j, z,
                       withEdge || withCenter || i != 2 || j != 2 ? " /\\ " : "");
        }
        if (withEdge) {
          for (int i = 0; i <= 2; ++i)
            for (int j = i==1?0:1; j <= (i==1?2:1); j += 2)
              printf("Edge%d%d%d' = Edge%d%d%d%s",
                     iNextEdge(i, j), jNextEdge(i, j), z,
                     i, j, z,
                     OrFlag || withCenter || i != 2 || j != 1 ? " /\\ " : "");
          if (OrFlag)
            for (int i = 0; i <= 2; ++i)
              for (int j = i==1?0:1; j <= (i==1?2:1); j += 2)
                printf("EdgeOr%d%d%d' = EdgeOr%d%d%d%s",
                       iNextEdge(i, j), jNextEdge(i, j), z,
                       i, j, z,
                       withCenter || i != 2 || j != 1 ? " /\\ " : "");
        }
        if (withCenter)
          printf("Center11%d' = (Center11%d+%d)%%4", z, z, z ? 1 : 3);
        printf("\n");
      }
      if (bothDir || z == 0) {
        printf("  /* %s, %sclockwise quarter turn */\n", z ? "up" : "down", z ? "counter-" : "");
        printf("  ");
        if (withCorner) {
          for (int i = 0; i <= 2; i += 2)
            for (int j = 0; j <= 2; j += 2)
              printf("Corn%d%d%d' = Corn%d%d%d%s",
                     iPrevCorn(i, j), jPrevCorn(i, j), z,
                     i, j, z,
                     OrFlag || withEdge || withCenter || i != 2 || j != 2 ? " /\\ " : "");
          if (OrFlag)
            for (int i = 0; i <= 2; i += 2)
              for (int j = 0; j <= 2; j += 2)
                printf("CornOr%d%d%d' = CornOr%d%d%d%s",
                       iPrevCorn(i, j), jPrevCorn(i, j), z,
                       i, j, z,
                       withEdge || withCenter || i != 2 || j != 2 ? " /\\ " :"");
        }
        if (withEdge) {
          for (int i = 0; i <= 2; ++i)
            for (int j = i==1?0:1; j <= (i==1?2:1); j += 2)
              printf("Edge%d%d%d' = Edge%d%d%d%s",
                     iPrevEdge(i, j), jPrevEdge(i, j), z,
                     i, j, z,
                     OrFlag || withCenter || i != 2 || j != 1 ? " /\\ " : "");
          if (OrFlag)
            for (int i = 0; i <= 2; ++i)
              for (int j = i==1?0:1; j <= (i==1?2:1); j += 2)
                printf("EdgeOr%d%d%d' = EdgeOr%d%d%d%s",
                       iPrevEdge(i, j), jPrevEdge(i, j), z,
                       i, j, z,
                       withCenter || i != 2 || j != 1 ? " /\\ " : "");
        }
        if (withCenter)
          printf("Center11%d' = (Center11%d+%d)%%4", z, z, z ? 3 : 1);
        printf("\n");
      }
    }
  }
}

void Spec() {
}

void usage(char *prog) {
  printf("Usage: %s [OPTION]\n", prog);
  printf("  -h, --help            This message\n");
  printf("  -o, --orientation     Take orientation into account\n");
  printf("  -f, --half            Consider half turns as single moves\n");
  printf("  -l, --clockwise-only  Consider only clockwise quarter turns\n");
  printf("  -x, --do-x            Consider rotation along x axis\n");
  printf("  -y, --do-y            Consider rotation along y axis\n");
  printf("  -z, --do-z            Consider rotation along z axis\n");
  printf("  -c, --corner-only     Consider only corners\n");
  printf("  -e, --edge-only       Consider only edges\n");
  printf("  -t, --center     Consider also center cubes orientation\n");
  exit(0);
}

int main(int argc, char *argv[])
{
  for (int i = 1; i < argc; ++i) {
    if (!strcmp(argv[i], "--help") || !strcmp(argv[i], "-h"))
      usage(argv[0]);
    else if (!strcmp(argv[i], "--orientation") || !strcmp(argv[i], "-o"))
      OrFlag = 1;
    else if (!strcmp(argv[i], "--half") || !strcmp(argv[i], "-f"))
      HalfFlag = 1;
    else if (!strcmp(argv[i], "--clockwise-only") || !strcmp(argv[i], "-l"))
      bothDir = 0;
    else if (!strcmp(argv[i], "--do-x") || !strcmp(argv[i], "-x"))
      DoX = 1;
    else if (!strcmp(argv[i], "--do-y") || !strcmp(argv[i], "-y"))
      DoY = 1;
    else if (!strcmp(argv[i], "--do-z") || !strcmp(argv[i], "-z"))
      DoZ = 1;
    else if (!strcmp(argv[i], "--corner-only") || !strcmp(argv[i], "-c"))
      withEdge = 0;
    else if (!strcmp(argv[i], "--edge-only") || !strcmp(argv[i], "-e"))
      withCorner = 0;
    else if (!strcmp(argv[i], "--center") || !strcmp(argv[i], "-t"))
      withCenter = 1;
    else
      usage(argv[0]);
  }
  if (withCorner == 0 && withEdge == 0) {
    printf("Incompatible '--corner-only' and '--edge-only' options.\n");
    return 2;
  }
  if (!DoX && !DoY && !DoZ) {
    printf("Please use at least one of '--do-x', '--do-y' or '--do-z' options (see '--help').\n");
    return 2;
  }

  Init();
  Trans();
  Spec();	
  return 0;
}
