document.write("<b> <Font Face = \"VNI-Times\" size = \"7pt\">");
document.write("Un peu d'informations : </b> </Font> <br>");
document.write("Derniere modification " + document.lastModified + "<br>");
document.write("L'adresse du fichier : " + document.location + "<br>");

changerCouleur();

function changerCouleur()
{
    changeCouleur = window.confirm("Souhaitez-vous changer la couleur du fond ?");

    if(changeCouleur)
    {
	var color = prompt("Quelle couleur ? ");
	document.bgColor = color;
    }
    else
	alert("Vous gardez la couleur courante");
}
