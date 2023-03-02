#!/bin/bash

#gcc -c -Wall -Werror -Wextra data_libs/*.c data_module/*.c
#gcc -c -Wall -Werror -Wextra yet_another_decision_module/*.c data_libs/*.c
gcc -Wall -Werror -Wextra *.o
rm *.o
./a.out
