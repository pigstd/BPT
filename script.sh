#!/bin/bash

cd gen

g++ gen.cpp -o gen


./gen $1 > ../test/4.in

echo generated

cd .. && cd test

g++ brute.cpp -o brute

./brute < 4.in > ../build/brute.out

echo brute done

cd .. && cd build

cmake .. && make && time ./code < ../test/4.in > BPT.out

# diff BPT.out brute.out

rm BPT

cd ..