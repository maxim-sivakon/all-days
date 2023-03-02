#include <stdio.h>

int main(void){
    float a, b;
    scanf("%f %f", &a, &b);

    if((a * a) + (b * b) < 25){
        printf("GOTCHA");
    }else{
        printf("MISS");
    }
}
