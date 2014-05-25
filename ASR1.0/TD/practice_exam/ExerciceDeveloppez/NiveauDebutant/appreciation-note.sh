#!/bin/bash

entrerNote() {
    if [ $note -ge 16 ]; then
	echo "Tres Bien"
    elif [ $note -ge 14 ]; then
	echo "Bien"
    elif [ $note -ge 12 ]; then
	echo "Assez Bien"
    elif [ $note -ge 10 ]; then
	echo "Moyen"
    else
	echo "Insuffisant"
    fi
}

entrerNoteComplet() {
    check=0
    somme=0
    nb=0
    while [ $check -eq 0 ]; do
	read -p "Entrez la note : " note
	if [ "$note" = "q" ]; then
	    echo "Le programme s'arrete."
	    check=1
	elif [ "$note" = "m" ]; then
	    let moyen=somme/nb
	    echo "La note moyenne : $moyen"
	    check=1
	elif [ $note -gt 20 ] || [ $note -lt 0 ]; then
	    echo "Erreur saisie. Le programme s'arrete."
	    check=1	    
	else
	    entrerNote
	    let somme=somme+note
	    let nb=nb+1
	fi
    done
}

clear
echo -e "Le programme d'estimer la note des etudiants.\nAppuyez sur 'q' pour quitter, 'm' pour savoir le moyenne de toutes les notes entrees"
entrerNoteComplet
