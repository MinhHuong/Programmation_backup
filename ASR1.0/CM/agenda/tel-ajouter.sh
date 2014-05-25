#Role : chercher un numero de telephone

f=telephone.dat

#read -p "nom ?" nom
#read -p "telephone ?" tel
#echo $tel $nom >> $f

dialog --title "Mon carnet de telephone" \
       --inputbox "Nom ?" 15 60 2> reponse
nom=$(cat reponse)


dialog --title "Mon carnet de telephone" \
       --inputbox "Telephone ?" 15 60 2> reponse
tel=$(cat reponse)

#temporaire
#echo "le nom demande est :" $nom
#echo "le numero est :" $tel
#exit

echo $tel $nom >> $f
dialog --title "Mon carnet de telephone" \
       --infobox "$nom a ete ajoute (numero $tel)" 15 60


#grep "$nom" $f > resultat
#dialog --title "Mon carnet de telephone" \
#       --textbox resultat 15 60

