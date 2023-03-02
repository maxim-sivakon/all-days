#include <stdio.h>

int maxim(int a, int b){
    if (a > b){
        return a;
    }else{
        return b;
    }
}

int main(void){
    int a, b, z;
    z = scanf("%d %d", &a, &b);

    if(z == 2){
        printf("%d", maxim(a, b));
    }else{
        printf("%3s", "n/a");
    }

}
