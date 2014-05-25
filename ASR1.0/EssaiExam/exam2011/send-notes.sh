#!/bin/bash

while read line; do
    adresse=`echo $line | awk -F":" '{ print $1 }'`
    let pos=`echo $adresse | wc -c`
    i=1
    total=0
    while [ $i -le 4 ]; do
	note[$i]=`echo ${line:$pos:1}`
	let total=total+note[$i]
	let pos=pos+2
	let i=i+1
    done
    sujet=`echo "Note devoir = $total"`
    echo "Vous avez au ${note[1]}, ${note[2]}, ${note[3]} et ${note[4]} aux questions du devoir de samedi, soit $total sur 19 au total." > content.txt
    mail -s "$sujet" "$adresse@etu.u-bordeaux1.fr" < content.txt
done < $1
