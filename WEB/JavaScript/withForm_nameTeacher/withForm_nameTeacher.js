function estVide(donnees, section)
{
    alert("Veuillez entrer votre " + section);
    donnees.focus();
}

function valider(lastN, firstN, birthday, place)
{
    var erreur = "";
    if( lastN.value.length < 1 || 
       firstN.value.length < 1 || 
       birthday.value.length < 1 || 
       place.value.length < 1 )
    {
	if( lastN.value.length < 1 )
	    erreur += " [nom]";
	if(firstN.value.length < 1)
	    erreur += " [prenom]"
	if(birthday.value.length < 1)
	    erreur += " [date de naissance]"
	if(place.value.length < 1)
	    erreur += " [lieu de naissance]";
	
	alert("Veuillez entrer votre " + erreur);
    }
    else
    {
	document.write("Nom et Prenom : " + lastN.value + " " + firstN.value + "<br>");
	document.write("Date de naissance : " + birthday.value + "<br>");
	document.write("Lieu de naissance : " + place.value + "<br>");
    }
}
