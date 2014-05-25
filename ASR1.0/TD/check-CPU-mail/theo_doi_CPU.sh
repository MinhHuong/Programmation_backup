#!/bin/bash

MAX=10

df -h | tail -n7 | awk -F" " '{ print $5 }' temp2 | awk -F"%" '{ print $1 }' | while read output; do
    let total=$total+$output
    if [ $total -gt $MAX ]; then
	echo "You hard disk is going out soon" | mail -s"Overload" root@asus-N20A
	exit 255
    fi
done
