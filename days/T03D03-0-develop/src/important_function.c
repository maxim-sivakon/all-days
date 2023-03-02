#include <stdio.h>
#include <math.h>

int main(void){

    float x, result;

    scanf("%f", &x);
    result = 7 * 0.001 * pow(x,4) + ((22.8 * pow(x,(1/3)) - 1 * 1000) * x + 3) / (x * x / 2) - x * pow((10 + x),(2/x)) - 1.01;
    printf("%.1f", result);

}

