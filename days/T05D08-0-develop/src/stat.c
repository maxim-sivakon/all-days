#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int *n);
int max(int *a, int *n);
int min(int *a, int *n);
double mean(int *a, int *n);
double variance(int *a, int *n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 0) {
        output(data, &n);
        output_result(max(data, &n), min(data, &n), mean(data, &n), variance(data, &n));
    } else {
        printf("n/a");
    }

    return 0;
}

int input(int *a, int *n) {
    char zx;
    int result = 0;
    int scan_flag = scanf("%d%c", n, &zx);

    if (scan_flag == 2 && (zx == ' ' || zx == '\n')) {
        for (int *p = a; p - a < *n; p++) {
            char zy;
            int scan_flagZ = scanf("%d%c", p, &zy);

            if (scan_flagZ == 2 && (zy == ' ' || zy == '\n')) {
            } else {
                result = 1;
            }
        }
    } else {
        result = 1;
    }

    return result;
}

void output(int *a, int *n) {
    for (int *p = a; p - a < *n; p++) {
        printf("%d ", *p);
    }
    printf("\n");
}

int max(int *a, int *n) {
    int maxD = 0;
    for (int *p = a; p - a < *n; p++) {
        if (*p > maxD) {
            maxD = *p;
        }
    }

    return maxD;
}

int min(int *a, int *n) {
    int minD = *n;
    for (int *p = a; p - a < *n; p++) {
        if (*p < minD) {
            minD = *p;
        }
    }

    return minD;
}

double mean(int *a, int *n) {
    double meanD;
    int sum = 0;

    for (int *p = a; p - a < *n; p++) {
        sum += *p;
    }
    meanD = (double)sum / *n;

    return meanD;
}

double variance(int *a, int *n) {
    double meanD, dici;

    meanD = mean(a, n);

    for (int *p = a; p - a < *n; p++) {
        dici += ((*p - meanD) * (*p - meanD)) / *n;
    }
    return dici;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %lf %lf", max_v, min_v, mean_v, variance_v);
}