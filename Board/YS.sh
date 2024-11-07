#!/bin/bash
g++ main.cpp -O2 -o main -std=c++17
# vl = 1

for ((i=1;i<=10000000;i++))
do
    ./main
    echo $i
    sleep 2
done