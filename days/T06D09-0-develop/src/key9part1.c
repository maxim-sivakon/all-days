#include <stdio.h>
#define SIZE_ARR 10

int input(int *buffer, int *length);
int output(int *buffer, int *length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int *length, int *number, int *numbers);

int main() {
    int buffer[SIZE_ARR], length, numbers[SIZE_ARR];
    if (input(buffer, &length) == 1) {
        int t = sum_numbers(buffer, length);
        find_numbers(buffer, &length, &t, numbers);
        output(buffer, &length);
    } else {
        printf("n/a");
    }
}

int input(int *buffer, int *length) {
    char symbols;
    int result = 1;
    int scan_flag = scanf("%d%c", length, &symbols);

    if (scan_flag == 2 && (symbols == ' ' || symbols == '\n')) {
        for (int i = 0; i < *length; i++) {
            int scan_flagZ = scanf("%d%c", &buffer[i], &symbols);
            if (scan_flagZ == 2 && (symbols == ' ' || symbols == '\n')) {
            } else {
                result = 0;
            }
        }
    } else {
        result = 0;
    }
    return result;
}

int output(int *buffer, int *length) {
    printf("%d\n", *length);
    for (int i = 0; i < *length; i++) {
        printf("%d ", buffer[i]);
    }
    return 0;
}

int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int i = 0; i <= length; i++) {
        if (buffer[i] != 0) {
            if (buffer[i] % 2 == 0) {
                sum += buffer[i];
            }
        }
    }
    return sum;
}

int find_numbers(int *buffer, int *length, int *number, int *numbers) {
    int count = 0;
    for (int j = 0; j < *length; j++) {
        if (buffer[j] != 0) {
            if (*number % buffer[j] == 0) {
                numbers[count++] = buffer[j];
            }
        }
    }
    *length = count;
    return *numbers;
}
