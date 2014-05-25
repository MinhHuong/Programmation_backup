#!/bin/bash

dicto_easy() {
    while read line; do
	english=`echo $line | awk -F":" '{ print $1 }'`
	vn=`echo $line | awk -F":" '{ print $2 }'`
	if [ "$word" = $english ]; then
	    echo "Meaning :" $vn
	    exit 0
	elif [ "$word" = "$vn" ]; then
	    echo "Meaning :" $english
	    exit 0
	fi
    done < tu_dien.txt 
    
    echo "$word khong co trong tu dien"
}

dicto_headtail() {
    n=0
    while read line; do
	let n=n+1
	let test=n%2
	if [ "$word" = "$line" ]; then
	    if [ $test -eq 0 ]; then
		echo `head -n$n tu_dien.txt | tail -n2 | head -n1`
		exit 0
	    else
		echo `head -n$(($n+1)) tu_dien.txt | tail -n1`
		exit 0
	    fi
	fi
    done < tu_dien.txt

    echo "$word doesn't exist in this dictionary"
}

dicto_find_position() {
    n=1
    while read line; do
	if [ "$word" = "$line" ]; then
	    let pos=n
	    break
	else
	    let n=n+1
	fi
    done < tu_dien.txt

    let pos_word=pos%2
    if [ $pos_word -eq 0 ]; then
	let found=pos-1
    else
	let found=pos+1
    fi
    
    j=1
    while read line; do
	if [ $j -eq $found ]; then
	    echo $line
	fi
	let j=j+1
    done < tu_dien.txt
}

echo -n "Enter the word : "
read word
dicto_find_position
