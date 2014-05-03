#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bigint_priv.h"

struct bigint {
  int size;  /**< size of the mantissa */
  int *m;  /**< mantissa */
};

bigint_t *bigint_new(int init_value)
{
  bigint_t *r = malloc(sizeof(bigint_t));

  r->size = 1;
  r->m = malloc(sizeof(int));
  r->m[0] = init_value;

  return r;
}

void bigint_free(bigint_t *n)
{
  free(n->m);
  free(n);
}

void bigint_add(bigint_t *a, bigint_t *b, bigint_t *c)
{
  int i, carry=0, leastsize;
  bigint_t *tmp;

  if (a->size < b->size) {
    tmp = a; a = b; b = tmp;
  }
  /* when calling the function, a and c can be aliased
   * so now b and c can be aliased and we gonna
   * change c->size further */
  leastsize = b->size;

  c->size = a->size;
  c->m = realloc(c->m, c->size*sizeof(int));

  for (i = 0; i < leastsize; ++i) {
    c->m[i] = carry+a->m[i]+b->m[i];
    carry   = c->m[i]/1000000000;
    c->m[i] = c->m[i]%1000000000;
  }
  for (; i < c->size; ++i) {
    c->m[i] = carry+a->m[i];
    carry   = c->m[i]/1000000000;
    c->m[i] = c->m[i]%1000000000;
  }
  if (carry) {
    ++(c->size);
    c->m = realloc(c->m, c->size*sizeof(int));
    c->m[c->size-1] = carry;
  }
}

void bigint_print(bigint_t *n, FILE *f)
{
  int i = n->size-1;

  if (n->m[i] >= 1000000) {
    fprintf(f, "%d", n->m[i]/1000000);
    fprintf(f, ",%03d", n->m[i]%1000000/1000);
    fprintf(f, ",%03d", n->m[i]%1000);
  } else if (n->m[i] >= 1000) {
    fprintf(f, "%d", n->m[i]/1000);
    fprintf(f, ",%03d", n->m[i]%1000);
  } else
    fprintf(f, "%d", n->m[i]);
  --i;
  while (i >= 0) {
    fprintf(f, ",%03d", n->m[i]/1000000);
    fprintf(f, ",%03d", n->m[i]%1000000/1000);
    fprintf(f, ",%03d", n->m[i]%1000);
    --i;
  }

  fprintf(f, " (");
  if      (n->m[n->size-1] >= 100000000)
    fprintf(f, "%dx10^%d", n->m[n->size-1]/100000000, 8+9*(n->size-1));
  else if (n->m[n->size-1] >= 10000000)
    fprintf(f, "%dx10^%d", n->m[n->size-1]/10000000,  7+9*(n->size-1));
  else if (n->m[n->size-1] >= 1000000)
    fprintf(f, "%dx10^%d", n->m[n->size-1]/1000000,   6+9*(n->size-1));
  else if (n->m[n->size-1] >= 100000)
    fprintf(f, "%dx10^%d", n->m[n->size-1]/100000,    5+9*(n->size-1));
  else if (n->m[n->size-1] >= 10000)
    fprintf(f, "%dx10^%d", n->m[n->size-1]/10000,     4+9*(n->size-1));
  else if (n->m[n->size-1] >= 1000)
    fprintf(f, "%dx10^%d", n->m[n->size-1]/1000,      3+9*(n->size-1));
  else if (n->m[n->size-1] >= 100)
    fprintf(f, "%dx10^%d", n->m[n->size-1]/100,       2+9*(n->size-1));
  else if (n->m[n->size-1] >= 10)
    fprintf(f, "%dx10^%d", n->m[n->size-1]/10,        1+9*(n->size-1));
  else
    fprintf(f, "%dx10^%d", n->m[n->size-1],             9*(n->size-1));
  fprintf(f, ")");
}
