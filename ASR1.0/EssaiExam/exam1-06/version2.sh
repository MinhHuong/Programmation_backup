#!/bin/bash

myster() {
    for MOT in $*; do
	nb=`echo $MOT | wc -c`
	let nc=$nb-1
	echo -n $nc " "
    done
}

#content=`cat $1`
#myster "$content"

while read line; do
    myster $line
    echo
done < $1
