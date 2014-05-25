#!/bin/bash

# shell script in ra noi dung 1 so dong trong file
# ./print_file_content from_line total_line file_name

i=1
j=1

if [ $# -ne 3 ]; then
    echo "So luong tham so sai"
    echo "Cu phap : ./print_file_content from_line total_line file_name"
    exit 2
fi

while read line; do
    if [ $i -eq $1 ]; then
	if [ $j -le $2 ]; then
	    echo $line
	    let j=j+1
	else
	    exit 1
	fi
    else
	let i=i+1
    fi
done < $3

	    
# Tinh n = tong so dong, dung while read line
# let t=$n-$1
# Cach khac : tail -c$t | head $2
