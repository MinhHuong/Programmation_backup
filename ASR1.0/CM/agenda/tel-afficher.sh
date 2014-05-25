#Role : afficher les donnees

f=telephone.dat  #le nom du fichier de donnees

dialog --title "Mon carnet de telephone" \
       --textbox $f 15 60

