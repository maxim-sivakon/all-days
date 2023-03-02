#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int *n);
double variance(int *a, int *n);
void output(int a);

int main() {
    int n, data[NMAX];

    output(input(data, &n));

    return 0;
}

void output(int a) {
    if (a == 0) {
        printf("%d", a);
    } else if (a == 999 || a == 888) {
        printf("n/a");
    } else {
        printf("%d", a);
    }
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
                if (*p >= mean(a, n) && *n <= NMAX && *p <= mean(a, n) + 3 * sqrt(variance(a, n)) &&
                    *p % 2 == 0) {
                    result = *p;
                } else {
                    result = 0;
                }
            } else {
                result = 888;
            }
        }
    } else {
        result = 999;
    }

    return result;
}

double mean(int *a, int *n) {
    int sum = 0;
    for (int *p = a; p - a < *n; p++) {
        sum += *p;
    }
    return (double)sum / *n;
}

double variance(int *a, int *n) {
    double meanD = mean(a, n), dici;
    for (int *p = a; p - a < *n; p++) {
        dici += ((*p - meanD) * (*p - meanD)) / *n;
    }
    return dici;
}
