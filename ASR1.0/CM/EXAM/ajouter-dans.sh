#!/bin/bash

boolCheck=0
while [ $boolCheck -eq 0 ]; do
    read -p "Adresse a ajouter (vide pour arreter) ? " adr
    if [ -z $adr ]; then
	exit 1
    fi
    read -p "Nom et prenom ? " nom prenom
    echo "$adr" "$nom" "$prenom" >> profs.liste 
done
