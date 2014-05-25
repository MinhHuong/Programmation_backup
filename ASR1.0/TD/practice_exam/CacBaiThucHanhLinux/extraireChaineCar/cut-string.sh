#!/bin/bash

trouverReadLine() {
    while read line; do
	for mot in $line; do
	    if [ "$mot" = $1 ]; then
		echo "$mot est trouve a la ligne : \"$line\""
	    fi
	done
    done < $2
}

trouverReadLine $1 $2
