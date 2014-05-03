#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mdd_utils_priv.h"

/* TODO: improve */
static int mdd_utils_prime(int n)
{
  int i;
  for (i = 3; i*i <= n; i+=2)
    if (n % i == 0) return 0;
  return 1;
}

int mdd_utils_next_prime(int n)
{
  int i;
  for (i = n|1; i == 257 || !mdd_utils_prime(i); i+=2);
  return i;
}

FILE *mdd_utils_fopen(char *base_name, char *ext)
{
  char *filename;
  FILE *f;  

  filename = malloc(strlen(base_name)+strlen(ext)+1);
  strcpy(filename, base_name);
  strcat(filename, ext);
  f = fopen(filename, "w");
  free(filename);

  return f;
}

FILE *mdd_utils_nfopen(char *base_name, int n, char *ext)
{
  char *filename;
  FILE *f;  

  filename = malloc(strlen(base_name)+3+strlen(ext)+1);
  sprintf(filename, "%s%03d%s", base_name, n, ext);
  f = fopen(filename, "w");
  free(filename);

  return f;
}
