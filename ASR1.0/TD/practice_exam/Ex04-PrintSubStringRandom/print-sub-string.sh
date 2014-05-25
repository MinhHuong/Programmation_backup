#!/bin/bash

# Le programme demande a l'utilisateur de saisir une chaine de caracteres,
# puis il va afficher une sous-chaine de longueur aleatoire 
# de la chaine originaire

read -p "Entrez une chainde de caracteres : " string

let long_string=`echo $string | wc -c`-1
boolCheck=1
while [ $boolCheck -eq 1 ]; do
    let long_sub_string=$RANDOM%$long_string
    if [ $long_sub_string -eq 0 ]; then
	continue
    fi
    let pos_debut=$RANDOM%$long_string
    if [ $pos_debut -lt $long_string ]; then
	boolCheck=0
    fi
done

echo -n ${string:$pos_debut:$long_sub_string}
echo
