/* 
 * Le tableau des votants
 */
var votants = new Array();

/* 
 * Tester si l'actualisation a ete faite ou non
 * Dans cette version, nous autorisons une seule fois de click sur le bouton "ACTUALISER", ca va changer quand on fait des connexions au serveur
 */
var updated = false;

/* 
 * L'objet Votant, avec un autre attribut : STATUS
 */
function Votant(id, fn, urlimg, stat) {
	this.ID = id;
	this.FullName = fn;
	this.URLImg = urlimg;
	this.Status = stat; 
	/*
	 * statut : 0 - pas encore voter ; 1 - en train de voter ; 2 - déjà voter
	 */
}

/* 
 * Chercher un votant dans le tableau par ID
 */
function findVotantById(iden) {
	for(var i = 0 ; i < votants.length ; i++) {
		if(votants[i].ID == iden) {
			return votants[i];
		}
	}

	return null;
}

/* 
 * Ajouter des votants deja donnes dans .html dans le tableau
 * (ca va changer dans les versions suivantes)
 */
function addVotantsToArray() {
	var divVotants = $(".votant");
	var _votant, _fullname, _url;

	for(var i = 0 ; i < divVotants.length ; i++) {
		_fullname = $(divVotants[i]).find("p").text();
		_url = $(divVotants[i]).find("img").attr("src");
		_votant = new Votant(i+1, _fullname, _url, 0);
		votants.push(_votant);
	}
}

/* 
 * Simuler le fonctionnement du bouton ACTUALISER
 * Rien de particulier, on fait des affectations fixes, pour voir comment le site web se comporte 
 */
function changeStateVotant() {
	updated = true;

	var idAlready = [ 1, 2, 5, 8 ];
	var idInProcess = [ 6, 9 ];

	var divVotants = $(".votant");

	var _divVotant, _votant;

	for(var i = 0 ; i < idAlready.length ; i++) {
		votants[idAlready[i]-1].Status = 2;

		_divVotant = divVotants[idAlready[i]-1];
		$(_divVotant).find("img").css("opacity", "0.3");

		var _checkIcon = document.createElement("span");
		$(_checkIcon).addClass("glyphicon glyphicon-ok");
		$(_checkIcon).css({
			"position" 	: "relative",
			"top"		: "-130px",
			"color" 	: "green",
			"font-size"	: "300%"
		})
		$(_divVotant).append(_checkIcon);
	}

	for(var i = 0 ; i < idInProcess.length ; i++) {
		votants[idInProcess[i]-1].Status = 1;

		_divVotant = divVotants[idInProcess[i]-1];
		$(_divVotant).find("img").css("opacity", "0.6");

		var _checkIcon = document.createElement("span");
		$(_checkIcon).addClass("glyphicon glyphicon-pencil");
		$(_checkIcon).css({
			"position" 	: "relative",
			"top"		: "-130px",
			"color" 	: "yellow",
			"font-size"	: "300%"
		})
		$(_divVotant).append(_checkIcon);
	}
}

$(document).ready(function(){
    $('[data-toggle="tooltip"]').tooltip(); 

    addVotantsToArray();

    /* 
     * CLICK sur le bouton "Actualiser"
     */
    $("#btn-actu").click(function() {
    	if(!updated) {
    		changeStateVotant();	
    	}
    });

    /* 
     * CLICK sur le bouton "Arreter"
     */
    $("#btn-stop").click(function() {
    	window.location.replace("../html/result.html");
    });
});