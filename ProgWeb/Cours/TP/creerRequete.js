var requete = null;

function creerRequete() {
  try {
   requete = new XMLHttpRequest();
 } catch (essaimicrosoft) {
   try {
     requete = new ActiveXObject("Msxml2.XMLHTTP");
   } catch (autremicrosoft) {
     try {
       requete = new ActiveXObject("Microsoft.XMLHTTP");
     } catch (echec) {
       requete = null;
     }
   }
 }

 if (requete == null)
   alert("Impossible de créer l'objet requête!");
}

function getPlanchesVendues()
{
  creerRequete();
  var url="getVentesActualisees.php";
  requete.open("GET", url, true);
  requete.onreadystatechange=actualiserPage;
  requete.send(null);
}

function actualiserPage()
{
  if(requete.readyState == 4)
  {
    var result = parseInt(requete.responseText);
    var nbPlanches = document.getElementById("planches-vendues");
    remplacerTexte(nbPlanches, result);

    var prixEl = document.getElementById("prix");
    var prix = getTexte(prixEl);

    var coutEl = document.getElementById("cout");
    var cout = getTexte(coutEl);

    var benefParPlanche = parseInt(prix) - parseInt(cout);
    var benefice = benefParPlanche * result;
    var benefEl = document.getElementById("benef");
    remplacerTexte(benefEl, benefice);

    benefice = Math.round(benef * 100) / 100;
  }
}