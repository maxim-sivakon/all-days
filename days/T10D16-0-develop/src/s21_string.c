#include <stdio.h>

int s21_string(char str_length[]){
    int result = 0;
    if(str_length != NULL){
        int length;
        for(length = 0; str_length[length] != '\0'; ++length);
        result = ++length;
    }else{
        result = 0;
    }
    return result;
}

void s21_checkString(char str_length[], int length){
    int checkLength = s21_string(str_length);
    if(checkLength == length){
        printf("SUCCESS\n");
    }else{
        printf("FAIL\n");
    }
}
