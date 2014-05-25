#!/bin/bash

afficher_Max() {
    max=0
    l=1
    while read line; do
	let longueur=`echo $line | wc -c`-1
	if [ $longueur -gt $max ]; then
	    ligne="$line"
	    max=$longueur
	    nb=$l
	fi
	let l=l+1
    done < $1
    echo La ligne la plus longue : "$ligne"
    echo Elle est a la ligne $nb
    echo Sa longueur : $max
}

afficher_Min() {
    min=99999
    l=1
    while read line; do
	let longueur=`echo $line | wc -c`-1
	if [ $longueur -lt $min ]; then
	    ligne="$line"
	    min=$longueur
	    nb=$l
	fi
	let l=l+1
    done < $1
    echo La ligne la plus courte : "$ligne"
    echo Elle est a la ligne $nb
    echo Sa longueur : $min
}

read -p "Entrez le fichier a executer : " fichier
if ! [ -f $fichier ]; then
    echo "Le fichier $fichier est inexistant"
    exit 1
fi
echo "Entrez le numero de la tache que vous voulez executer : "
echo "1) Trouver la plus longue ligne"
echo "2) Trouver la plus courte ligne"
read -p "Votre option : " choix
case $choix in
    1)
	afficher_Max $fichier
	;;
    2)
	afficher_Min $fichier
	;;
    3) 
	echo "Erreur saisie !"
	;;
esac
