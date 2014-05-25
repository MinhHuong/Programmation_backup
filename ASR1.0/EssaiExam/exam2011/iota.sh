#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Erreur : il faut un parametre"
    exit 1
fi

seq 1 $1
