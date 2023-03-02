#include <stdio.h>

//сумма
int sum(int a, int b){
    return (a + b);
}
//разность
int difference(int a, int b){
    return (a - b);
}

//произведение
int work(int a, int b){
    return (a * b);
}

//частное
int privat(int a, int b){
    return (a / b);
}

int main(void)
{
    int a, b;

    scanf("%d %d", &a, &b);

    int sum1 = sum(a, b);
    int difference1 = difference(a, b);
    int work1 = work(a, b);

    if(a == 0 || b == 0){
        printf("%d %d %d n/a", sum1, difference1, work1);
    }else{
        int privat1 = privat(a, b);
        printf("%d %d %d %d", sum1, difference1, work1, privat1);
    }

    return 0;
}
