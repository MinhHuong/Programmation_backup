#!/bin/bash

add_path_1() {
    echo -n "Them duong di : "
    read path
    echo $path > filetemp
    tr " " ":" < filetemp >> path.txt
}

add_path_2() {
    echo -n "So buoc di : "
    read nb
    
    echo -n "Nhap duong di : "
    read path

    let total=2*nb-1
    i=0
    while [ $i -lt $total ]; do
	echo -n ${path:i:1}"->" >> path.txt
	let i=i+2
	if [ $i -eq $(($total-1)) ]; then
	    echo -n ${path:i:1} >> path.txt
	    echo "" >> path.txt
	    break
	fi
    done
}
