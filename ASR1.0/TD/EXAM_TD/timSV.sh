#!/bin/bash

countLine() {
    l=0
    while read line; do
	let l=l+1
    done < datasv.txt
}

find_1() {
    m=1
    while read line; do
	maSV=`echo $line | awk -F", " '{ print $1 }'`
	if [ $maSV = $1 ]; then
	    echo $line
	    exit 0
	fi
	let m=m+1
    done < datasv.txt
    if [ $m -gt $l ]; then
	echo "Danh sach chi co $l sinh vien"
	exit 1
    fi
}

find_Debut_Fin_Position() {
    i=1
    while read line; do
	maSV=`echo $line | awk -F", " '{ print $1 }'`
	if [ $maSV = $1 ]; then
	    debut=$i
	fi
	if [ $maSV = $2 ]; then
	    fin=$i
	fi	
	let i=i+1
    done < datasv.txt    
    if [ -z $debut ] || [ -z $fin ]; then
	echo "Danh sach chi co $l sinh vien"
	exit 1
    fi
}

find_Multi() {    
    find_Debut_Fin_Position $1 $2
    j=1
    while read line; do
	if [ $j -ge $debut ] && [ $j -le $fin ]; then
	    echo $line
	fi
	let j=j+1
    done < datasv.txt
}

countLine
if [ $# -eq 1 ]; then
    find_1 $1
elif [ $# -eq 2 ]; then
    find_Multi $1 $2
else
    echo "So luong tham so sai ! Chi duoc nhap tu 1 den 2 ma SV !" 
	exit 1
fi
