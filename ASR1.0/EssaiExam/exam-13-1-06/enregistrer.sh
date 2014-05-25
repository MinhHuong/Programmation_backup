#!/bin/bash

ajouter_utilisateur() {
    read -p "The number of users you want to add : " nb
    nb_user=1
    while [ $nb_user -le $nb ]; do
	read -p "Your name : " name
	read -p "Your user_name : " user_name
	password=`tr -dc 'a-zAA-Z0-9' < /dev/urandom | head -c6`
	echo $user_name $password "$name" >> $1
	let nb_user=nb_user+1
    done
}

fabriquer-paires() {
    while read line; do
	user_name=`echo $line | awk '{ print $1 }'`
	password=`echo $line | awk '{ print $2 }'`
	echo $password
	sudo useradd $user_name
	echo $user_name:$password | chpasswd
    done < $1
}

fabriquer-paires $1
