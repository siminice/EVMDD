#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"

int utils_power(int x, int y)
{
  int tmp;

  if (y == 0) return 1;

  tmp = utils_power(x, y >> 1);
  if (y & 1)
    return tmp*tmp*x;
  else
    return tmp*tmp;
}

FILE *utils_fopen(char *base_name, char *ext)
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

FILE *utils_nfopen(char *base_name, int n, char *ext)
{
  char *filename;
  FILE *f;  

  filename = malloc(strlen(base_name)+3+strlen(ext)+1);
  sprintf(filename, "%s%03d%s", base_name, n, ext);
  f = fopen(filename, "w");
  free(filename);

  return f;
}
