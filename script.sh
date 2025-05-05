#!/bin/bash

cd gen

g++ gen.cpp -o gen


./gen $1 > ../testdata/4.in

echo generated

cd .. && cd testdata

g++ brute.cpp -o brute

./brute < 4.in > ../build/brute.out

echo brute done

cd .. && cd build

cmake .. && make && time ./code < ../testdata/4.in > BPT.out

diff BPT.out brute.out

rm BPT

cd ..