#!/bin/sh

rm -f fast small *.o *.gcda							&&
gcc -O3 -m64 -maltivec -mcpu=970 fast.c main.c -fprofile-generate -o fast	&&
./fast 10									&&
gcc -O3 -m64 -maltivec -mcpu=970 fast.c main.c -fprofile-use -o fast		&&
./fast 60									&&
gcc -Os -m32 -mcpu=970 small.c main.c -o small					&&
./small 1									&&
gcc -Os -m32 -mcpu=970 small.c -c						&&
size --common small.o
