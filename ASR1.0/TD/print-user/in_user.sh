#!/bin/bash

i=1
while read line; do
    let i=i+1
    let test=$i%2
    uid=`echo $line | awk -F":" '{print $3}'`
    gid=`echo $line | awk -F":" '{print $4}'`
    if [ $test -eq 0 ] && [ $uid -eq $gid ]; then
	echo $line
    fi
done < passwd
