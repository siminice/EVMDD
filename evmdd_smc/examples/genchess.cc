#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WHITE	0
#define PAWN	0
#define ROOK	1
#define KNIGHT	2
#define BISHOP	3
#define QUEEN	4
#define KING	5
#define EMPTY	6
#define BLACK	7

void white_pawn(char i, int j) {
  printf("  /* --- white pawn --- */\n");
  if (j==1 || j==8) return;
  printf("  %c%d = %d /\\ %c%d = 6 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, PAWN, i, j+1, i, j, i, j+1, PAWN);
  if (j==2)
  printf("  %c%d = %d /\\ %c%d = 6 /\\ %c%d = 6 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, PAWN, i, j+1, i, j+2, i, j, i, j+2, PAWN);
  if (i>'A')
  printf("  %c%d = %d /\\ %c%d > 6 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, PAWN, i-1, j+1, i, j, i-1, j+1, PAWN);
  if (i<'H')
  printf("  %c%d = %d /\\ %c%d > 6 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, PAWN, i+1, j+1, i, j, i+1, j+1, PAWN);
}

void white_rook(char i, int j) {
  printf("  /* --- white rook --- */\n");
  // forward
  for (int k = 1; k < j; k++) {
    printf("  %c%d = %d /\\ %c%d > 5", i, j, ROOK, i, k);
    for (int h = k+1; h < j; h++) printf(" /\\ %c%d = 6", i, h);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, i, k, ROOK);
  }
  // backward
  for (int k = j+1; k <= 8; k++) {
    printf("  %c%d = %d /\\ %c%d > 5", i, j, ROOK, i, k);
    for (int h = j+1; h < k; h++) printf(" /\\ %c%d = 6", i, h);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, i, k, ROOK);
  }
  // left
  for (char k = 'A'; k < i; k++) {
    printf("  %c%d = %d /\\ %c%d > 5", i, j, ROOK, k, j);
    for (char h = k+1; h < i; h++) printf(" /\\ %c%d = 6", h, j);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, k, j, ROOK);
  }
  // right
  for (char k = i+1; k <= 'H'; k++) {
    printf("  %c%d = %d /\\ %c%d > 5", i, j, ROOK, k, j);
    for (char h = i+1; h < k; h++) printf(" /\\ %c%d = 6", h, j);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, k, j, ROOK);
  }
}

void white_knight(char i, int j) {
  printf("  /* --- white knight --- */\n");
  if (i>'B' && j>1)
  printf("  %c%d = %d /\\ %c%d > 5 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, KNIGHT, i-2, j-1, i, j, i-2, j-1, KNIGHT);
  if (i>'A' && j>2)
  printf("  %c%d = %d /\\ %c%d > 5 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, KNIGHT, i-1, j-2, i, j, i-1, j-2, KNIGHT);
  if (i<'H' && j>2)
  printf("  %c%d = %d /\\ %c%d > 5 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, KNIGHT, i+1, j-2, i, j, i+1, j-2, KNIGHT);
  if (i<'G' && j>1)
  printf("  %c%d = %d /\\ %c%d > 5 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, KNIGHT, i+2, j-1, i, j, i+2, j-1, KNIGHT);
  if (i<'G' && j<8)
  printf("  %c%d = %d /\\ %c%d > 5 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, KNIGHT, i+2, j+1, i, j, i+2, j+1, KNIGHT);
  if (i<'H' && j<7)
  printf("  %c%d = %d /\\ %c%d > 5 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, KNIGHT, i+1, j+2, i, j, i+1, j+2, KNIGHT);
  if (i>'A' && j<7)
  printf("  %c%d = %d /\\ %c%d > 5 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, KNIGHT, i-1, j+2, i, j, i-1, j+2, KNIGHT);
  if (i>'B' && j<8)
  printf("  %c%d = %d /\\ %c%d > 5 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, KNIGHT, i-2, j+1, i, j, i-2, j+1, KNIGHT);
}

void white_bishop(char i, int j) {
  printf("  /* --- white bishop --- */\n");
  int d, d1, d2;
  // forward & left
  d1 = ((int) i) - 65;
  d2 = 8 - j;
  d = d1; if (d2 < d) d = d2;
  for (int k = 1; k <= d; k++) {
    printf("  %c%d = %d /\\ %c%d > 5", i, j, BISHOP, i-k, j+k);
    for (int h = 1; h < k; h++) printf(" /\\ %c%d = 6", i-h, j+h);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, i-k, j+k, BISHOP);
  }
  // forward & right
  d1 = 72 - ((int) i);
  d = d1; if (d2 < d) d = d2;
  for (int k = 1; k <= d; k++) {
    printf("  %c%d = %d /\\ %c%d > 5", i, j, BISHOP, i+k, j+k);
    for (int h = 1; h < k; h++) printf(" /\\ %c%d = 6", i+h, j+h);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, i+k, j+k, BISHOP);
  }
  // backward & left
  d1 = ((int) i) - 65;
  d2 = j-1;
  d = d1; if (d2 < d) d = d2;
  for (int k = 1; k <= d; k++) {
    printf("  %c%d = %d /\\ %c%d > 5", i, j, BISHOP, i-k, j-k);
    for (int h = 1; h < k; h++) printf(" /\\ %c%d = 6", i-h, j-h);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, i-k, j-k, BISHOP);
  }
  // backward & right
  d1 = 72 - ((int) i);
  d = d1; if (d2 < d) d = d2;
  for (int k = 1; k <= d; k++) {
    printf("  %c%d = %d /\\ %c%d > 5", i, j, BISHOP, i+k, j-k);
    for (int h = 1; h < k; h++) printf(" /\\ %c%d = 6", i+h, j-h);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, i+k, j-k, BISHOP);
  }
}

void white_queen(char i, int j) {
  printf("  /* --- white queen --- */\n");
  // forward
  for (int k = 1; k < j; k++) {
    printf("  %c%d = %d /\\ %c%d > 5", i, j, QUEEN, i, k);
    for (int h = k+1; h < j; h++) printf(" /\\ %c%d = 6", i, h);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, i, k, QUEEN);
  }
  // backward
  for (int k = j+1; k <= 8; k++) {
    printf("  %c%d = %d /\\ %c%d > 5", i, j, QUEEN, i, k);
    for (int h = j+1; h < k; h++) printf(" /\\ %c%d = 6", i, h);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, i, k, QUEEN);
  }
  // left
  for (char k = 'A'; k < i; k++) {
    printf("  %c%d = %d /\\ %c%d > 5", i, j, QUEEN, k, j);
    for (char h = k+1; h < i; h++) printf(" /\\ %c%d = 6", h, j);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, k, j, QUEEN);
  }
  // right
  for (char k = i+1; k <= 'H'; k++) {
    printf("  %c%d = %d /\\ %c%d > 5", i, j, QUEEN, k, j);
    for (char h = i+1; h < k; h++) printf(" /\\ %c%d = 6", h, j);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, k, j, QUEEN);
  }
  int d, d1, d2;
  // forward & left
  d1 = ((int) i) - 65;
  d2 = 8 - j;
  d = d1; if (d2 < d) d = d2;
  for (int k = 1; k <= d; k++) {
    printf("  %c%d = %d /\\ %c%d > 5", i, j, QUEEN, i-k, j+k);
    for (int h = 1; h < k; h++) printf(" /\\ %c%d = 6", i-h, j+h);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, i-k, j+k, QUEEN);
  }
  // forward & right
  d1 = 72 - ((int) i);
  d = d1; if (d2 < d) d = d2;
  for (int k = 1; k <= d; k++) {
    printf("  %c%d = %d /\\ %c%d > 5", i, j, QUEEN, i+k, j+k);
    for (int h = 1; h < k; h++) printf(" /\\ %c%d = 6", i+h, j+h);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, i+k, j+k, QUEEN);
  }
  // backward & left
  d1 = ((int) i) - 65;
  d2 = j-1;
  d = d1; if (d2 < d) d = d2;
  for (int k = 1; k <= d; k++) {
    printf("  %c%d = %d /\\ %c%d > 5", i, j, QUEEN, i-k, j-k);
    for (int h = 1; h < k; h++) printf(" /\\ %c%d = 6", i-h, j-h);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, i-k, j-k, QUEEN);
  }
  // backward & right
  d1 = 72 - ((int) i);
  d = d1; if (d2 < d) d = d2;
  for (int k = 1; k <= d; k++) {
    printf("  %c%d = %d /\\ %c%d > 5", i, j, QUEEN, i+k, j-k);
    for (int h = 1; h < k; h++) printf(" /\\ %c%d = 6", i+h, j-h);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, i+k, j-k, QUEEN);
  }
}

void white_king(char i, int j) {
  printf("  /* --- white king --- */\n");
  if (i>'A' && j>1)
  printf("  %c%d = %d /\\ %c%d > 5 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, KING, i-1, j-1, i, j, i-1, j-1, KING);
  if (i>'A')
  printf("  %c%d = %d /\\ %c%d > 5 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, KING, i-1, j,   i, j, i-1, j,   KING);
  if (i>'A' && j<8)
  printf("  %c%d = %d /\\ %c%d > 5 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, KING, i-1, j+1, i, j, i-1, j+1, KING);
  if (j>1)
  printf("  %c%d = %d /\\ %c%d > 5 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, KING, i,   j-1, i, j, i,   j-1, KING);
  if (j<8)
  printf("  %c%d = %d /\\ %c%d > 5 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, KING, i,   j+1, i, j, i,   j+1, KING);
  if (i<'H' && j>1)
  printf("  %c%d = %d /\\ %c%d > 5 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, KING, i+1, j-1, i, j, i+1, j-1, KING);
  if (i<'H')
  printf("  %c%d = %d /\\ %c%d > 5 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, KING, i+1, j,   i, j, i+1, j,   KING);
  if (i<'H' && j<8)
  printf("  %c%d = %d /\\ %c%d > 5 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, KING, i+1, j+1, i, j, i+1, j+1, KING);
}

void black_pawn(char i, int j) {
  printf("  /* --- black pawn --- */\n");
  if (j==1 || j==8) return;
  printf("  %c%d = %d /\\ %c%d = 6 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, BLACK+PAWN, i, j-1, i, j, i, j-1, BLACK+PAWN);
  if (j==7)
  printf("  %c%d = %d /\\ %c%d = 6 /\\ %c%d = 6 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, BLACK+PAWN, i, j-1, i, j-2, i, j, i, j-2, BLACK+PAWN);
  if (i>'A')
  printf("  %c%d = %d /\\ %c%d < 6 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, BLACK+PAWN, i-1, j-1, i, j, i-1, j-1, BLACK+PAWN);
  if (i<'H')
  printf("  %c%d = %d /\\ %c%d < 6 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, BLACK+PAWN, i+1, j-1, i, j, i+1, j-1, BLACK+PAWN);
}

void black_rook(char i, int j) {
  printf("  /* --- black rook --- */\n");
  // forward
  for (int k = 1; k < j; k++) {
    printf("  %c%d = %d /\\ %c%d < 7", i, j, BLACK+ROOK, i, k);
    for (int h = k+1; h < j; h++) printf(" /\\ %c%d = 6", i, h);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, i, k, BLACK+ROOK);
  }
  // backward
  for (int k = j+1; k <= 8; k++) {
    printf("  %c%d = %d /\\ %c%d < 7", i, j, BLACK+ROOK, i, k);
    for (int h = j+1; h < k; h++) printf(" /\\ %c%d = 6", i, h);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, i, k, BLACK+ROOK);
  }
  // left
  for (char k = 'A'; k < i; k++) {
    printf("  %c%d = %d /\\ %c%d < 7", i, j, BLACK+ROOK, k, j);
    for (char h = k+1; h < i; h++) printf(" /\\ %c%d = 6", h, j);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, k, j, BLACK+ROOK);
  }
  // right
  for (char k = i+1; k <= 'H'; k++) {
    printf("  %c%d = %d /\\ %c%d < 7", i, j, BLACK+ROOK, k, j);
    for (char h = i+1; h < k; h++) printf(" /\\ %c%d = 6", h, j);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, k, j, BLACK+ROOK);
  }
}

void black_knight(char i, int j) {
  printf("  /* --- black knight --- */\n");
  if (i>'B' && j>1)
  printf("  %c%d = %d /\\ %c%d < 7 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, BLACK+KNIGHT, i-2, j-1, i, j, i-2, j-1, BLACK+KNIGHT);
  if (i>'A' && j>2)
  printf("  %c%d = %d /\\ %c%d < 7 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, BLACK+KNIGHT, i-1, j-2, i, j, i-1, j-2, BLACK+KNIGHT);
  if (i<'H' && j>2)
  printf("  %c%d = %d /\\ %c%d < 7 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, BLACK+KNIGHT, i+1, j-2, i, j, i+1, j-2, BLACK+KNIGHT);
  if (i<'G' && j>1)
  printf("  %c%d = %d /\\ %c%d < 7 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, BLACK+KNIGHT, i+2, j-1, i, j, i+2, j-1, BLACK+KNIGHT);
  if (i<'G' && j<8)
  printf("  %c%d = %d /\\ %c%d < 7 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, BLACK+KNIGHT, i+2, j+1, i, j, i+2, j+1, BLACK+KNIGHT);
  if (i<'H' && j<7)
  printf("  %c%d = %d /\\ %c%d < 7 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, BLACK+KNIGHT, i+1, j+2, i, j, i+1, j+2, BLACK+KNIGHT);
  if (i>'A' && j<7)
  printf("  %c%d = %d /\\ %c%d < 7 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, BLACK+KNIGHT, i-1, j+2, i, j, i-1, j+2, BLACK+KNIGHT);
  if (i>'B' && j<8)
  printf("  %c%d = %d /\\ %c%d < 7 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, BLACK+KNIGHT, i-2, j+1, i, j, i-2, j+1, BLACK+KNIGHT);
}

void black_bishop(char i, int j) {
  printf("  /* --- black bishop --- */\n");
  int d, d1, d2;
  // forward & left
  d1 = ((int) i) - 65;
  d2 = 8 - j;
  d = d1; if (d2 < d) d = d2;
  for (int k = 1; k <= d; k++) {
    printf("  %c%d = %d /\\ %c%d < 7", i, j, BLACK+BISHOP, i-k, j+k);
    for (int h = 1; h < k; h++) printf(" /\\ %c%d = 6", i-h, j+h);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, i-k, j+k, BLACK+BISHOP);
  }
  // forward & right
  d1 = 72 - ((int) i);
  d = d1; if (d2 < d) d = d2;
  for (int k = 1; k <= d; k++) {
    printf("  %c%d = %d /\\ %c%d < 7", i, j, BLACK+BISHOP, i+k, j+k);
    for (int h = 1; h < k; h++) printf(" /\\ %c%d = 6", i+h, j+h);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, i+k, j+k, BLACK+BISHOP);
  }
  // backward & left
  d1 = ((int) i) - 65;
  d2 = j-1;
  d = d1; if (d2 < d) d = d2;
  for (int k = 1; k <= d; k++) {
    printf("  %c%d = %d /\\ %c%d < 7", i, j, BLACK+BISHOP, i-k, j-k);
    for (int h = 1; h < k; h++) printf(" /\\ %c%d = 6", i-h, j-h);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, i-k, j-k, BLACK+BISHOP);
  }
  // backward & right
  d1 = 72 - ((int) i);
  d = d1; if (d2 < d) d = d2;
  for (int k = 1; k <= d; k++) {
    printf("  %c%d = %d /\\ %c%d < 7", i, j, BLACK+BISHOP, i+k, j-k);
    for (int h = 1; h < k; h++) printf(" /\\ %c%d = 6", i+h, j-h);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, i+k, j-k, BLACK+BISHOP);
  }
}

void black_queen(char i, int j) {
  printf("  /* --- black queen --- */\n");
  // forward
  for (int k = 1; k < j; k++) {
    printf("  %c%d = %d /\\ %c%d < 7", i, j, BLACK+QUEEN, i, k);
    for (int h = k+1; h < j; h++) printf(" /\\ %c%d = 6", i, h);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, i, k, BLACK+QUEEN);
  }
  // backward
  for (int k = j+1; k <= 8; k++) {
    printf("  %c%d = %d /\\ %c%d < 7", i, j, BLACK+QUEEN, i, k);
    for (int h = j+1; h < k; h++) printf(" /\\ %c%d = 6", i, h);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, i, k, BLACK+QUEEN);
  }
  // left
  for (char k = 'A'; k < i; k++) {
    printf("  %c%d = %d /\\ %c%d < 7", i, j, BLACK+QUEEN, k, j);
    for (char h = k+1; h < i; h++) printf(" /\\ %c%d = 6", h, j);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, k, j, BLACK+QUEEN);
  }
  // right
  for (char k = i+1; k <= 'H'; k++) {
    printf("  %c%d = %d /\\ %c%d < 7", i, j, BLACK+QUEEN, k, j);
    for (char h = i+1; h < k; h++) printf(" /\\ %c%d = 6", h, j);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, k, j, BLACK+QUEEN);
  }
  int d, d1, d2;
  // forward & left
  d1 = ((int) i) - 65;
  d2 = 8 - j;
  d = d1; if (d2 < d) d = d2;
  for (int k = 1; k <= d; k++) {
    printf("  %c%d = %d /\\ %c%d < 7", i, j, BLACK+QUEEN, i-k, j+k);
    for (int h = 1; h < k; h++) printf(" /\\ %c%d = 6", i-h, j+h);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, i-k, j+k, BLACK+QUEEN);
  }
  // forward & right
  d1 = 72 - ((int) i);
  d = d1; if (d2 < d) d = d2;
  for (int k = 1; k <= d; k++) {
    printf("  %c%d = %d /\\ %c%d < 7", i, j, BLACK+QUEEN, i+k, j+k);
    for (int h = 1; h < k; h++) printf(" /\\ %c%d = 6", i+h, j+h);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, i+k, j+k, BLACK+QUEEN);
  }
  // backward & left
  d1 = ((int) i) - 65;
  d2 = j-1;
  d = d1; if (d2 < d) d = d2;
  for (int k = 1; k <= d; k++) {
    printf("  %c%d = %d /\\ %c%d < 7", i, j, BLACK+QUEEN, i-k, j-k);
    for (int h = 1; h < k; h++) printf(" /\\ %c%d = 6", i-h, j-h);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, i-k, j-k, BLACK+QUEEN);
  }
  // backward & right
  d1 = 72 - ((int) i);
  d = d1; if (d2 < d) d = d2;
  for (int k = 1; k <= d; k++) {
    printf("  %c%d = %d /\\ %c%d < 7", i, j, BLACK+QUEEN, i+k, j-k);
    for (int h = 1; h < k; h++) printf(" /\\ %c%d = 6", i+h, j-h);
    printf(" -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, i+k, j-k, BLACK+QUEEN);
  }
}

void black_king(char i, int j) {
  printf("  /* --- black king --- */\n");
  if (i>'A' && j>1)
  printf("  %c%d = %d /\\ %c%d < 7 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, BLACK+KING, i-1, j-1, i, j, i-1, j-1, BLACK+KING);
  if (i>'A')
  printf("  %c%d = %d /\\ %c%d < 7 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, BLACK+KING, i-1, j,   i, j, i-1, j,   BLACK+KING);
  if (i>'A' && j<8)
  printf("  %c%d = %d /\\ %c%d < 7 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, BLACK+KING, i-1, j+1, i, j, i-1, j+1, BLACK+KING);
  if (j>1)
  printf("  %c%d = %d /\\ %c%d < 7 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, BLACK+KING, i,   j-1, i, j, i,   j-1, BLACK+KING);
  if (j<8)
  printf("  %c%d = %d /\\ %c%d < 7 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, BLACK+KING, i,   j+1, i, j, i,   j+1, BLACK+KING);
  if (i<'H' && j>1)
  printf("  %c%d = %d /\\ %c%d < 7 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, BLACK+KING, i+1, j-1, i, j, i+1, j-1, BLACK+KING);
  if (i<'H')
  printf("  %c%d = %d /\\ %c%d < 7 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, BLACK+KING, i+1, j,   i, j, i+1, j,   BLACK+KING);
  if (i<'H' && j<8)
  printf("  %c%d = %d /\\ %c%d < 7 -> %c%d\' = 6 /\\ %c%d\' = %d\n", i, j, BLACK+KING, i+1, j+1, i, j, i+1, j+1, BLACK+KING);
  printf("\n");
}

int initpos(char i, int j) {
  if (j>2 && j<7) return EMPTY;
  if (j==2) return PAWN;
  if (j==7) return BLACK+PAWN;
  if (j==1) { if (i<'F') return i-64; else return 73-i;}
  if (j==8) { if (i<'F') return i-64+BLACK; else return BLACK+73-i;}
}

int main() {
   printf("Variables\n"); 
   for (int j=1; j<=8; j++){
     for (char i='A'; i<='H'; i++){
        int j1 = (j-1)%8 + 1;
        printf("   %c%d [0, 12]\n", i, j1);
     }
   }
   printf("Initial states\n");
   for (int j=1; j<=8; j++){
     for (char i='A'; i<='H'; i++){
        int j1 = (j-1)%8 + 1;
        printf("   %c%d = %d\n",  i, j1, initpos(i,j1));
     }
   }

   printf("Transitions\n\n");
   for (char i='A'; i<='H'; i++) {
     int c = i-64;
     for (int j=1; j<=8; j++) {

       printf("  /* ========================= */\n");
       printf("  /* moves from the %c%d square  */\n", i, j);
       printf("  /* ========================= */\n\n");
       white_pawn(i, j);
       white_rook(i, j);
       white_knight(i, j);
       white_bishop(i, j);
       white_queen(i, j);
       white_king(i, j);

       black_pawn(i, j);
       black_rook(i, j);
       black_knight(i, j);
       black_bishop(i, j);
       black_queen(i, j);
       black_king(i, j);

     }
   }

  return 0;
}
