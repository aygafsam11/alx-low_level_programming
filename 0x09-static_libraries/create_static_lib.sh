#!/bin/bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -c *.c
ar -rc liball.a *.o
ar -t liball.a
ranlib liball.a
