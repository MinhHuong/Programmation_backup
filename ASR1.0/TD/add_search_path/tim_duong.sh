#!/bin/bash

echo -n "Nhap diem di & diem den : "
read source dest

grep $source.*$dest path.txt > temp_tim_duong.txt

while read line; do
    total=`echo $line | wc -c`
    i=0
    while [ $i -lt $(($total-1)) ]; do
	if [ $source = ${line:i:1} ]; then
	    pos_source=$i
	fi
	if [ $dest = ${line:i:1} ]; then
	    pos_dest=$i
	fi
	let i=i+1
    done
    let length=pos_dest-pos_source+1
    echo ${line:$pos_source:$length}
done < temp_tim_duong.txt


