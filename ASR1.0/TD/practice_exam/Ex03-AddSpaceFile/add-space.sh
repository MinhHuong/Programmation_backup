#!/bin/bash

# add space between words in file

while read line; do    
    let total=`echo $line | wc -c`-1
    i=0
    while [ $i -lt $total ]; do
	echo -n ${line:$i:1}' '
	let i=i+1
    done
    echo
done < data.txt
