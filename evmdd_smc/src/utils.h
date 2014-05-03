#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

int utils_power(int, int);

FILE *utils_fopen(char *base_name, char *ext);
FILE *utils_nfopen(char *base_name, int n, char *ext);

#endif /* UTILS_H */
