#!/bin/bash

#echo "gia tri tham so thu nhat : $1"
#echo "gia tri tham so thu hai : $2"
#let x=$1+$2
#echo "Tong cua 2 tham so : $x"

#echo $*
#echo $#
#echo $?
#echo $0

#echo;

#ping6 -c2 ::1

#if [ $? -eq 0 ]
#then
#    echo "ping6 ton tai"
#fi

ping6 -c2 ::1 &> /dev/null

case $? in
    0) echo "ping6 ton tai";;
    1) echo "ping6 khong ton tai";;
esac 

