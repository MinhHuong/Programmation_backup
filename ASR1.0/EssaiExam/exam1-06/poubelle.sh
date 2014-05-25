#!/bin/bash

TRASH="/home/minhhuong/Desktop/poubelle"

if [ -z $TRASH ]; then
    echo "variable TRASH non definie"
    exit 1
fi

if ! [ -d $TRASH ]; then
    echo "valeur de TRASH incorrecte"
    exit 1
fi

for file in $*; do
    if [ -f $file ]; then
	mv $file $TRASH
	echo "fichier $file deplace"
    else
	echo "fichier $file inexistant"
    fi
done
