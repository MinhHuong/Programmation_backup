function valider(firstN, lastN, fullN) //transmettre des parametres
{
    if(firstN.value.length < 1)
    {
	alert("Veuillez saisir votre prenom.");
	firstN.focus();
    }

    if(lastN.value.length < 1)
    {
	alert("Veuillez saisir votre nom");
	lastN.focus();
    }

    if(lastN.value.length >= 1 && firstN.value.length >= 1)
    {
	var full = firstN.value + " " + lastN.value;
	fullN.value = full;
	alert("Votre nom complet : " + full);
	document.write(full);
    }
}

function other_valider() //utiliser directement la variable du fichier HTML
{
    if(document.saisirNom.prenom.value.length < 1)
    {
	alert("Veuillez saisir le prenom");
    }
}
