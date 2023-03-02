#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "data_process.h"

int main(void) {
  int n;

  char zx;
  int scan_flag = scanf("%d%c", &n, &zx);

  if (scan_flag == 2 && zx == '\n') {
    double *data = (double *)malloc(n * sizeof(double));
    input(data, n);
    if (normalization(data, n)) {
      output(data, n);
    } else {
      printf("ERROR");
    }
    free(data);
  } else {
    printf("n/a");
  }

  return 0;
}
