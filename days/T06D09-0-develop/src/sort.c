#include <stdio.h>
#define SIZE_ARR 10

int sorArray(int *arr) {
    for (int i = 0; i < SIZE_ARR; i++) {
        for (int j = 0; j < SIZE_ARR; j++) {
            if (arr[i] < arr[j]) {
                int ii = 0;
                ii = arr[i];
                arr[i] = arr[j];
                arr[j] = ii;
            }
        }
    }
    return 0;
}

int input(int *arrD) {
    int result = 0;
    for (int i = 0; i < SIZE_ARR; i++) {
        char zy;
        int scan_flagZ = scanf("%d%c", &arrD[i], &zy);
        if (scan_flagZ == 2 && (zy == ' ' || zy == '\n')) {
        } else {
            result = 999;
        }
    }
    return result;
}

int main() {
    int array[SIZE_ARR], arrY = input(array);

    if (arrY != 999) {
        sorArray(array);
        for (int i = 0; i < SIZE_ARR; i++) {
            printf("%d ", array[i]);
        }
    } else {
        printf("n/a");
    }
    return 0;
}
