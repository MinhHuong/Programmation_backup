f=telephone.dat

ligne="+----------------------+----------------------+"

#l'affichage est prepare dans un fichier temporaire pour etre affiche ensuite par dialog
(
echo $ligne
cat $f | while read numero nom
do
    #echo $numero "=>" $nom
    #      === format ==  ==variable==
    printf "| %20s | %-20s |\n" $numero "$nom"
    #%20s  : au moins 20 caracteres
    #%-20s : au moins 20 caracteres, cadre a gauche
    #\n "  : sauter a la ligne
done
echo $ligne
) > temporaire


dialog --title "Mon carnet de telephone" \
       --textbox temporaire 20 60
