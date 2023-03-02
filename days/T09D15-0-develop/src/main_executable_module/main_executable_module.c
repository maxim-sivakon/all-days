#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "../data_module/data_process.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;

  char zx;
  int scan_flag = scanf("%d%c", &n, &zx);

  if (scan_flag == 2 && zx == '\n') {
    double *data = (double *)malloc(n * sizeof(double));
    input(data, n);
    printf("LOAD DATA...\n");
    input(data, n);

    printf("RAW DATA:\n\t");
    output(data, n);

    printf("\nNORMALIZED DATA:\n\t");
    normalization(data, n);
    output(data, n);

    printf("\nSORTED NORMALIZED DATA:\n\t");
    sort(data, n);
    output(data, n);

    free(data);
  } else {
    printf("n/a");
  }
}
