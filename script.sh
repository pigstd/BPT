#!/bin/bash

cd gen

g++ gen.cpp -o gen

./gen $1 > ../testdata/4.in

echo generated

cd .. && cd build

cmake .. && make && ./code < ../testdata/4.in

cd ..