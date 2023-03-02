#include <stdio.h>
#include <stdlib.h>
#include "decision.h"
#include "../data_libs/data_io.h"

int main(void) {
  int n;

  char zx;
  int scan_flag = scanf("%d%c", &n, &zx);

  if (scan_flag == 2 && zx == '\n') {
    double *data = (double *)malloc(n * sizeof(double));
    input(data, n);
    if (make_decision(data, n)) {
      printf("YES");
    } else {
      printf("NO");
    }
    free(data);
  } else {
    printf("n/a");
  }
}
