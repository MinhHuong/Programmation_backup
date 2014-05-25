#!/bin/bash

enterTab () {
    n=0
    while [ $n -lt 5 ]
    do
	echo -n "Nhap phan tu a[$n] : "
	read a[$n]
	let n=n+1
    done
}

printTab () {
    echo "Tab : "
    n=0
    while [ $n -lt 5 ]
    do
	echo ${a[$n]}
	let n=n+1
    done
}

echangerCase () {
    x=${a[$2]}
    a[$2]=${a[$1]}
    a[$1]=$x
}


sortTab () {
    for((i=0;i<4;i++))
    do
	for((j=i+1;j<5;j++))
	do
	    if [ ${a[$i]} -gt ${a[$j]} ]; then
		echangerCase i j
	    fi
	done
    done
}

enterTab
sortTab
printTab
