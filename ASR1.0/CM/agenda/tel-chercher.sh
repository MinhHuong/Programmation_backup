#Role : chercher un numero de telephone

f=telephone.dat

#read -p "nom ?" nom

dialog --title "Mon carnet de telephone" \
       --inputbox "Nom ?" 15 60 2> reponse

nom=$(cat reponse)


#temporaire
#echo "le nom demande est" $nom
#exit

grep "$nom" $f > resultat
dialog --title "Mon carnet de telephone" \
       --textbox resultat 15 60

