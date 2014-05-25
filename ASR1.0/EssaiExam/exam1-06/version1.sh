#!/bin/bash

myster() {
    for MOT in $*; do
	nb=`echo $MOT | wc -c`
	let nc=nb-1
	echo -n $nc" "
    done
}

liste="In girum imus nocte et consumimur igni"
myster $liste
