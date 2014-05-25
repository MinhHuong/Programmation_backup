#!/bin/bash

combien_Caracteres() {
    sommeCar=0
    while read line; do
	for mot in $line; do
	    nb=`echo $mot | wc -c`
	    let realNb=nb-1
	    let sommeCar=sommeCar+realNb
	done
    done < $1
    echo $sommeCar
}

combien_Mot() {
    sommeMot=0
    while read line; do
	for mot in $line; do
	    let sommeMot=sommeMot+1
	done
    done < $1
    echo $sommeMot
}

echo -e "Choisissez un entre ces 2 taches a executer :\n1) Compter les caracteres\n2) Compter les mots"
read -p "Votre choix : " choix
read -p "Fichier a executer : " fichier
if ! [ -f $fichier ]; then
    echo "Ce fichier est inexistant"
    exit 1
else
    case $choix in
	1)
	    combien_Caracteres $fichier
	    ;;
	2)
	    combien_Mot $fichier
	    ;;
	*)
	    echo "Erreur saisie !"
	    exit 1
	;;
    esac  
fi
