#!/bin/bash

if [ $USER != "root" ]; then
    echo "Vous n'etes pas l'utilisateur root"
    exit 255
fi

i=0
while read line; do
    let i=i+1
done < nhap.txt

let t=i-$1
tail -n$t nhap.txt > temp
cat temp > nhap.txt
