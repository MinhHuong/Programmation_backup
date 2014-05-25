#!/bin/bash

read -p "Entrez le nombre : " nb
let longueur=`echo $nb | wc -c`-1
i=$longueur
while [ $i -ge 0 ]; do
    echo -n ${nb:$i:1}
    let i=i-1
done
