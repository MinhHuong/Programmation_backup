#!/bin/bash

remplace-par-sed() {
    N="dupont"
    P="marcel"
    T="9988776655"
    
    sed -e 's/^marcel:dupont:.*$/marcel:dupont:9988776655/g' agenda.txt > temporaire
    #sed -e 's/^$P:$N:.*$/$P:$N:$T/g' agenda.txt > temporaire
    cp temporaire agenda.txt
    cat agenda.txt
}

extractTelParis() {
    while read line; do
	tel=`echo $line | awk -F":" '{ print $3 }'`
	prefixe=`echo ${tel:0:2}`
	if [ "$prefixe" = "01" ]; then
	    echo $line
	fi
    done < agenda.txt
}

extractTelParis
