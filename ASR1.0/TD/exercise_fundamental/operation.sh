#!/bin/bash

if [ $# -ne 3 ]
then
    echo "Khong du tham so"
    exit 1
fi

case $2 in
    +) echo $(( $1 + $3 ));;
    -) echo $(( $1 - $3 ));;
    x) echo $(( $1 * $3 ));;
    /) 
	if [ $3 -ne 0 ]
	    then
	    echo $(( $1 / $3 ))
	    exit 1
	fi
	echo "error : b = 0";;
    *) echo "Loi phep tinh";;
esac
