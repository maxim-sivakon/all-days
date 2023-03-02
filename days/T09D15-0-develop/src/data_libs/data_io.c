#include "data_io.h"
#include <stdio.h>
#include <stdlib.h>

void input(double *data, int n) {
    for (int i = 0; i < n; i++) {
        char zy;
        int scan_flagZ = scanf("%lf%c", &data[i], &zy);
        if (scan_flagZ != 2 && zy != '\n') {
            printf("n/a");
            break;
        }
    }
}

void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%lf ", data[i]);
    }
}