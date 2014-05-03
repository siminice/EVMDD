#include <stdlib.h>
#include "cuthill_mckee.h"

void reverse_cuthill_mckee(int n, char **dep, int *vo) {
  int i, j, k, qu1, qu2, qu3, visited;
  int *deg, *queue, *used;
  int sorted, si, aux, last;

  deg   = (int*)malloc((n+1)*sizeof(int));
  used  = (int*)malloc((n+1)*sizeof(int));
  queue = (int*)malloc(2*(n+1)*sizeof(int));

  /* compute vertex degrees */
  for (i=1; i<=n; i++) {
    deg[i] = 0;
    used[i] = 0;
    for (j=1; j<=n; j++) {
      if (i!=j && dep[i][j]=='+') deg[i] = deg[i] + 1;
    }
  }

  /* set up empty queue */
  qu1 = 0;
  qu2 = -1;

  visited = 0;
  while (visited<n) {
    /* find unused vertex of minimum degree */
    k=1;
    while (k<=n && used[k]>0) k++;
    for (j=k+1; j<=n; j++)
      if (used[j]==0 && deg[j]<deg[k]) k=j;
    vo[++visited] = k;
    used[k] = 1;

    /* add adjacent nodes to the queue */
    qu3 = qu2+1;
    for (i=1; i<=n; i++) 
      if (i!=k && dep[k][i]=='+') {
        queue[++qu2] = i;
      }
    
    /* bubblesort new queue in increasing degree order */
    last = qu2;
    do {
      sorted = 1;
      for (si=qu3; si<=last-1; si++) {
         if (deg[queue[si+1]] < deg[queue[si]]) {
           sorted = 0;
           aux = queue[si];
           queue[si] = queue[si+1];
           queue[si+1] = aux;
         }
      }
      last--;
    } while (!sorted);

    while (qu2>=qu1) {
      /* pick element from queue */
      i = queue[qu1];
      qu1++;
      if (!used[i]) {
        vo[++visited] = i;
        used[i] = 1;
      }

      /* add unused adjacent nodes to the queue */
      qu3 = qu2+1;
      for (j=1; j<=n; j++) 
        if (j!=k && used[j]==0 && dep[i][j]=='+') {
          queue[++qu2] = j;
        }
      
      /* bubblesort new queue in increasing degree order */
      last = qu2;
      do {
        sorted = 1;
        for (si=qu3; si<=last-1; si++) {
           if (deg[queue[si+1]] < deg[queue[si]]) {
             sorted = 0;
             aux = queue[si];
             queue[si] = queue[si+1];
             queue[si+1] = aux;
           }
        }
        last--;
      } while (!sorted);
    } /* end while queue non-empty */
  } /* end while unvisited nodes */

  /* reverse the order */
/*
  for (i=1; i<=n/2; i++) {
    aux = vo[i];
    vo[i] = vo[n+1-i];
    vo[n+1-i] = aux;
  }
*/

  free(deg);
  free(used);
  free(queue);
}
