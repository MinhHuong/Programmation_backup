#!/bin/bash

part1=`tr -dc 'a-zA-Z0-9' < /dev/urandom | head -c8`
part2=`tr -dc 'a-zA-Z0-9' < /dev/urandom | head -c10`
part3=`tr -dc 'a-zA-Z0-9' < /dev/urandom | head -c8`
part4=`tr -dc 'a-zA-Z0-9' < /dev/urandom | head -c6`

echo Generate key : "$part1"_"$part2"_"$part3"_"$part4"
