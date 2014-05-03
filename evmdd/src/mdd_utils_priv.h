#ifndef UTILS_PRIV_H
#define UTILS_PRIV_H

int mdd_utils_power(int, int);

int mdd_utils_next_prime(int);

FILE *mdd_utils_fopen(char *base_name, char *ext);
FILE *mdd_utils_nfopen(char *base_name, int n, char *ext);

#endif /* UTILS_PRIV_H */
