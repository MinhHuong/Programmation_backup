#!/bin/bash

read -p "Entrez le nom du fichier : " f

if ! [ -f $f ]; then
    echo "Entree invalidee ! Le fichier $f n'existe pas"
    exit 1
fi

echo "Changer le nom du fichier $f en : "
echo "  1) Majuscule"
echo "  2) Minuscule"
read -p "Votre choix : " choix

case $choix in 
    1)  nouv_nom=`echo $f | tr 'a-z' 'A-Z'`
	mv $f $nouv_nom | ls -l | grep "$nouv_nom"
	;;
    2)  nouv_nom=`echo $f | tr 'A-Z' 'a-z'`
	mv $f $nouv_nom | ls -l | grep "$nouv_nom"
	;;
    *)  echo "Faux choix. Le programme termine."
	exit 1;;
esac
