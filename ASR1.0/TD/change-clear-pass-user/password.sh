#!/bin/bash

# Tao user tu test1 -> test10 va password cho cac user do


for n in {1..10}
do
    password=$RANDOM
    echo $password
    sudo useradd test$n
    echo test$n:$password | chpasswd
done
