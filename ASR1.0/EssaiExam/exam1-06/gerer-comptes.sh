#!/bin/bash

calculer_lignes() {
    total=1
    while read line; do
	let total=total+1
    done < comptes
}

afficher_lignes() {
    calculer_lignes
    read -p "De ligne combien a ligne combien ? " debut fin
    if [ $fin -gt $total ] || [ $fin -lt 1 ] || [ $debut -lt 1 ] || [ $debut -gt $total ] || [ $debut -gt $fin ]
    then
	echo "Erreur saisie. Le programme s'arrete"
	exit 1
    fi
    l=1
    while read line; do
	if [ $l -ge $debut ] && [ $l -le $fin ]; then
	    echo $line
	fi
	let l=l+1
    done < comptes
}

pas_groupe() {
    read -p "Choisissez 1 groupe dont le programme n'afficher pas les etudiants : " groupe_choisi
    while read line; do
	group=`echo $line | awk '{ print $4 }'`
	if [ "$group" != "$groupe_choisi" ]; then
	    echo $line
	fi
    done < comptes
}

save_name() {
    n=1
    while read line; do
	nom_prenom=`echo $line | awk '{ print $3" "$2 }'`
	echo "$n" "$nom_prenom" >> monGroupe
	let n=n+1
    done < comptes
    cat monGroupe
}

afficher_inverse() {
    while read line; do
	awk '{ print $1" "$3" "$2" "$4" "$5" "$6 }' >> compte
    done < comptes
    cat compte
}

executer() {
    echo -e "Les taches a executer : \n1) Afficher les lignes choisies \n2) Afficher l'ensemble des etudiants qui n'appartenant pas au groupe choisi \n3) Creer le fichier mon groupe contenant le nom & prenom des etudiants, precedes de leur numero d'apparition \n4) Afficher le contenu du fichier compte en inversant sur chaque ligne le prenom & le nom"
    read -p "Votre choix : " choix
    case $choix in
	1) 
	    afficher_lignes
	    ;;
	2) 
	    pas_groupe
	    ;;
	3)
	    save_name
	    ;;
	4) 
	    afficher_inverse
	    ;;
	*)
	    echo "Erreur saisie. Le programme s'arrete ici"
	    exit 1
	    ;;
    esac
}

executer
