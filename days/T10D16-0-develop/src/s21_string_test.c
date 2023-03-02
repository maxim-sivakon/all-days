#include <stdlib.h>
#include "s21_string.h"

void s21_strlen_test(){
    char oneString[] = "my little\0";
    char twoString[] = "4828\0";
    char *treeString = NULL;

    s21_checkString(oneString, 10);
    s21_checkString(twoString, 4);
    s21_checkString(treeString, 4);
}

int main(void)
{
    s21_strlen_test();
    return 0;
}