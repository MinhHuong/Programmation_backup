#!/bin/bash

g++ -c $1.cc
g++ -c $2.cc
rm *~ 2> /dev/null
g++ $1.o $2.o -o main
