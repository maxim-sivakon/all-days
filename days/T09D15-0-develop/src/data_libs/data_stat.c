#include "data_stat.h"
#include <stdio.h>

double min(double *data, int n) {
    double min = *data;
    for (double *p = data; p - data < n; p++) {
        if (min > *p) {
            min = *p;
        }
    }
    return min;
}

double max(double *data, int n) {
    double max = *data;
    for (double *p = data; p - data < n; p++) {
        if (max < *p) {
            max = *p;
        }
    }
    return max;
}

double mean(double *data, int n) {
    double sum = 0;
    for (double *p = data; p - data < n; p++) {
        sum += *p;
    }
    return sum / n;
}

double variance(double *data, int n) {
    double sum = 0;
    double mean1 = mean(data, n);
    for (double *p = data; p - data < n; p++) {
        sum += (*p - mean1) * (*p - mean1);
    }
    return sum / n;
}
