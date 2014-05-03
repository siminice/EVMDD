#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv) {
  FILE *f, *h;
  char filename[128], plotfile[128], s[512];
  double runt, total_rt;
  int numr;

  for (int d = 1; d <= 5; d++) {
    sprintf(plotfile, "../plots/d%d.dat", d);
    h = fopen(plotfile, "wt");
  for (int n = 1; n <= 10; n++) {
  for (int x = 1; x <= 5; x++) {
    if (!h) continue;
      numr = 0;
      total_rt = 0.0;
      for (int r = 0; r <10; r++) {
        sprintf(filename, "../results/dio-n%d-m%d-d%d-%d.out", 100*n, 100*n*x, d, r);
        f = fopen(filename, "rt");
        runt = 1801.0;	// not run
        if (f!=NULL) {
          while (!feof(f)) {
            fgets(s, 512, f);
            if (strstr(s, "Timeout")!=NULL) {
              runt = 1800.0;
              total_rt = total_rt + runt;
              numr++;
            }
            else if (strstr(s, "building expression(s)")!=NULL) {
              char *c = strstr(s, "User:");
              strtok(c+2, " ");
              char *rts = strtok(NULL, " ");
              if (rts) {
                runt = atof(rts);
                total_rt = total_rt + runt;
                numr++;
              }
            }
          }
          fclose(f);
        }
      } //  end for r
      if (numr > 0) {
        fprintf(h, "%d\t%d\t%10.3f\n", 100*n, x, total_rt/numr);
      }
    } // end for x
    fprintf(h, "\n");
  } // end for n
    fclose(h);
  } // end for d
  return 0;
}
