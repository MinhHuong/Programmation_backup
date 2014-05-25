#!/bin/bash

# INITIALISER UN TABLEAU : ===============================

# METHODE 1 :

tab[11]=23
tab[19]=42
tab[51]=lucius
echo "Le nombre d'elements dans tab =" ${#tab[@]}

echo "tab[11] =" ${tab[11]} 
echo "tab[19] =" ${tab[19]}
echo "tab[51] =" ${tab[51]}
echo "tab[15] =" ${tab[15]} "(rien n'affiche car l'element tab[15] n'est pas initialise)"

let somme=${tab[11]}+${tab[19]}
echo "tab[11] + tab[19] =" $somme

#-----------------------------------

echo;echo;

# METHODE 2 :

tab2=( zero un deux trois quatre )
echo "Le nombre d'elements dans le tab2 =" ${#tab2[@]} 

echo "En utilisant la boucle for pour afficher le tableau :"
for i in $( seq 0 $((${#tab2[@]}-1)) ) #$((${#tab2[@]}-1)) = 5-1 = 4
do
    echo "tab2[$i] =" ${tab2[i]}
done

#------------------------------------

echo; echo;

# METHODE 3 :

tab3=( [10]=dix [15]=quinze [20]=vingt )
echo "Le nombre d'elements dans le tab3 =" ${#tab3[@]}

echo "tab3[10] =" ${tab3[10]}
echo "tab3[15] =" ${tab3[15]}
echo "tab3[20] =" ${tab3[20]}

#-------------------------------------
