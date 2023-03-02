#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int *n);
void squaring(int *a, int *n);

int main(void) {
    int n, data[NMAX];
    input(data, &n);
    squaring(data, &n);
    output(data, &n);

    return 0;
}

int input(int *a, int *n) {
    scanf("%d", n);
    for (int *p = a; p - a < *n; p++) {
        scanf("%d", p);
    }
    return 0;
}

void output(int *a, int *n) {
    for (int *p = a; p - a < *n; p++) {
        printf("%d ", *p);
    }
}

void squaring(int *a, int *n) {
    for (int *p = a; p - a < *n; p++) {
        *p = *p * *p;
    }
}
