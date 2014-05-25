#Jeu : il faut deviner le nombre choisi par l'ordinateur
#===========================================================

#1. L'ordinateur choisit un nombre
mystere=$RANDOM
#echo $mystere


#2. Boucle :
while true
do
#   - il demande de deviner le nombre
    read -p "Devinez : " nombre
#   - si c'est egal c'est fini
    [ $nombre = $mystere ] && break
#   - si c'est trop grand ou trop petit il le dit
    if [ $mystere -gt $nombre ]
    then
	echo "Le nombre mystere est plus GRAND que $nombre"
    else
	echo "Le nombre mystere est plus PETIT que $nombre"
    fi
done
echo "C'est fini"
