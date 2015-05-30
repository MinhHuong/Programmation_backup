/* 
 * Identifiant courant, utilise pour l'ajout de nouveaux votants
 */
var _id = 1;

/* 
 * Le tableau contenant des votants
 */
var votants = [];

/* 
 * Le Votant choisi (pour le click de la souris, utilise pour modifier et enlever le Votant choisi)
 */
var chosenVotant = null; //object

/* 
 * La classe Votant :
 *		+ identifiant
 *		+ prenom
 * 		+ nom
 *		+ le lien de la photo
 */
function Votant(id, p, n, urlImg) {
	this.ID = id;
	this.Prenom = p;
	this.Nom = n;
	this.URLImg = urlImg;
}

/* 
 * Trouver le votant par l'identifiant
 */
function findVotantById(iden) {
	for(var i = 0 ; i < votants.length ; i++) {
		if(votants[i].ID == iden) {
			return votants[i];
		}
	}
}

$(document).ready(function() {
	$(this).click(function() {
		$("#waiting").hide("slow");
	});
	/* 
	 * Des items dans le left-menu (#menu-manag : l'element ul)
	 * Evenement : hover sur chaque item
	 */
	$("#menu-manag > li").hover(
		function() {
			var msg = getInstruction($(this));
			$(this).css({
				"background-color" : getBackgroundColorLeftMenu($(this)),
				"font-weight" : "bold"
			});
			$("#instruction > p").html(msg);
			$("#instruction > p").css("color", "#000000");
		}, 
		function() {
			$(this).css({
				"background-color" : "#FFFFFF",
				"font-weight" : "normal"
			});
			$("#instruction > p").html("");
		});

	/* 
	 * Des menus sur le Navigation Bar (VOTANT / VOTE DU JOUR)
	 * Evenement : hover sur chaque item du Navigation Bar
	 */
	$(".menu-page-item").hover(
		function() {
			if( $(this).text() == "VOTANTS" ) {
				$("#instruction > p").html(
					"<b>VOTANTS</b><br><br>Aller à la partie de gestion des petits votants"
					);
			} 

			if( $(this).text() == "VOTE DU JOUR") {
				$("#instruction > p").html(
					"<b>VOTE DU JOUR</b><br><br>Aller à la partie de gestion de la vote du jour"
					);
			}
		},
		function() {
			$("#instruction > p").html("");
		});

	/* 
	 * Changer le curseur de la souris en hover sur chaque item du Left Menu
	 */
	$("#item-add").css("cursor", "pointer");
	$("#item-edit").css("cursor", "pointer");
	$("#item-remove").css("cursor", "pointer");

	/* 
	 * L'item "Ajouter un petit votant"
	 */
	$("#item-add").click(function() {
		$("#add-prenom").css("border-color", "#CCCCCC");
		$("#add-nom").css("border-color", "#CCCCCC");
		$("#modal-add").modal({backdrop: "static"});
	});

	/* 
	 * L'item "Modifier un petit votant"
	 */
	$("#item-edit").click(function() {
		if(chosenVotant != null) {
			$("#modal-edit form")[0].reset();
			$("#edit-prenom").attr("value", chosenVotant.Prenom);
			$("#edit-nom").attr("value", chosenVotant.Nom);
			$("#img-field-edit").attr({
				"src" : chosenVotant.URLImg
			});
			$("#modal-edit").modal( { backdrop: "static" } );
		}
		else {
			$("#instruction > p").html(
				"<b>AUCUN VOTANT CHOISI</b><br><br>Veuillez choisir un petit votant pour faire des modifications"
			);
			$("#instruction > p").css("color", "red");
		}
	});

	/* 
	 * L'item "Enlever un petit votant"
	 */
	$("#item-remove").click(function() {
		if(chosenVotant != null) {
			$("#remove-nom-prenom").text(chosenVotant.Prenom + " " + chosenVotant.Nom);
			$("#img-field-remove").attr({
				"src" : chosenVotant.URLImg
			});
			$("#modal-remove").modal( { backdrop: "static" } );
		}
		else {
			$("#instruction > p").html(
				"<b>AUCUN VOTANT CHOISI</b><br><br>Veuillez choisir un petit votant pour l'enlever de la liste"
			);
			$("#instruction > p").css("color", "red");
		}
	});

	/* 
	 * Le modal servant a l'ajout d'un nouveau votant
	 */
	$("#modal-add").on("show.bs.modal", function() {
		$("#modal-add form")[0].reset();
		$("#add-prenom").attr("placeholder", "Son prénom");
		$("#add-nom").attr("placeholder", "Son nom");
		$("#img-field-add").attr({
			"src" : "../img/defaultIMG.png"
		});
	});

	/* 
	 * Eviter le cas ou l'utilisateur appuye sur ENTER mais les deux boutons CONFIRMER et ANNULER
	 * n'ont pas de Focus, ce qui cause le modal a disparaitre de facon imprevu
	 */
	$("#modal-add").keydown(function(event) {
		// 13 : Enter 
		if(event.which == 13 && !$("#add-confirm").is(":focus") && !$("#add-cancel").is(":focus")) {
			event.preventDefault();
		}
	})

	/* 
	 * Le modal servant a la modification d'un votant existant
	 */
	$("#modal-edit").on("show.bs.modal", function() {
		$("#modal-edit form")[0].reset();
	});

	/* 
	 * Le bouton CONFIRMER dans le modal "Ajouter un petit votant"
	 */
	$("#add-confirm").click(function() {
		if(checkForm(0)) {
			var _prenom = $("#add-prenom")[0].value;
			var _nom = $("#add-nom")[0].value;
			var _url = $("#img-field-add").attr("src");

			var _votant = new Votant(_id, _prenom, _nom, _url);
			votants.push(_votant);

			var divVotant = buildDivVotant(_votant);
			$("#tab-image").append(divVotant);
			$(divVotant).trigger("click");

			$("#modal-add").modal("hide");

			_id++;
		}

		/* Il faut retourner false, sinon le <form> dans ce modal va rafraichir toutes les donnees,
		qui cause la perte de tous les changements */
		return false;
	});

	/* 
	 * Le bouton ANNULER dans le modal "Ajouter un petit votant"
	 */
	$("#add-cancel").click(function() {
		$("#modal-add").modal("hide");
		return false;
	});

	/* 
	 * Le bouton CONFIRMER dans le modal "Modifier un petit votant"
	 */
	$("#edit-confirm").click(function() {
		if(checkForm(1)) {
			chosenVotant.Nom = $("#edit-nom").val();
			chosenVotant.Prenom = $("#edit-prenom").val();
			chosenVotant.URLImg = $("#img-field-edit").attr("src");
			$("#"+chosenVotant.ID).find("p").html(chosenVotant.Prenom + "<br>" + chosenVotant.Nom);
			$("#"+chosenVotant.ID).find("img").attr("src", chosenVotant.URLImg);
			$("#modal-edit").modal("hide");
		}

		return false;
	});

	/* 
	 * Le bouton ANNULER dans le modal "Modifier un petit votant"
	 */
	$("#edit-cancel").click(function() {
		$("#modal-edit").modal("hide");
		return false;
	});

	/* 
	 * Le bouton CONFIRMER dans le modal "Enlever un petit votant"
	 */
	$("#remove-confirm").click(function() {
		votants.splice(votants.indexOf(chosenVotant), 1);
		$("#" + chosenVotant.ID).remove();
		chosenVotant = null;
		$("#modal-remove").modal("hide");
		return false;
	});

	/* 
	 * Le bouton ANNULER dans le modal "Enlever un petit votant"
	 */
	$("#remove-cancel").click(function() {
		$("#modal-remove").modal("hide");
		return false;
	});

	/* 
	 * Le bouton CHOISIR servant au choix de la photo pour le petit votant
	 * (dans le modal "Ajouter un petit votant")
	 */
	$("#btn-add-img").click(function() {
		/* Un click sur ce bouton provoque un clic sur <input type="file"> */
		$("#select-file-add").click();
		return false;
	});

	/* 
	 * Le bouton CHOISIR servant au choix de la photo pour le petit votant
	 * (dans le modal "Modifier un petit votant")
	 */
	$("#btn-edit-img").click(function() {
		/* Un click sur ce bouton provoque un clic sur <input type="file"> */
		$("#select-file-edit").click();
		return false;
	});

	/* 
	 * L'element <input> de type=file, qui est cache, place dans le modal "Ajouter un petit votant"
	 * Evenement "change" sur ce <input> cause le chargement de la photo sur le modal
	 */
	$("#select-file-add").change(function() {
		var filesSelected = $(this)[0].files;
		if (filesSelected.length > 0) 
		{
			var fileToLoad = filesSelected[0];

			// Si le fichier charge est une image
			if (fileToLoad.type.match("image.*"))
			{
				var fileReader = new FileReader();
				fileReader.onload = function(fileLoadedEvent) 
				{
					$("#img-field-add").attr({
						"src" : fileLoadedEvent.target.result
					});
				};
				fileReader.readAsDataURL(fileToLoad);
			}
			else {
				$("#img-field-add").attr({
					"src"	: "../img/error-img.png"
				});
			}
		}

		return false;
	});

	/* 
	 * L'element <input> de type=file, qui est cache, place dans le modal "Modifier un petit votant"
	 * Evenement "change" sur ce <input> cause le chargement de la photo sur le modal
	 */
	$("#select-file-edit").change(function() {
		var filesSelected = $(this)[0].files;
		if (filesSelected.length > 0)
		{
			var fileToLoad = filesSelected[0];

			if (fileToLoad.type.match("image.*"))
			{
				var fileReader = new FileReader();
				fileReader.onload = function(fileLoadedEvent) 
				{
					$("#img-field-edit").attr({
						"src" : fileLoadedEvent.target.result
					});
				};
				fileReader.readAsDataURL(fileToLoad);
			}
			else {
				$("#img-field-edit").attr({
					"src"	: "../img/error-img.png"
				});
			}
		}

		return false;
	});
});

/* 
 * Construire un DIV représentant un votant (photo + prénom + nom)
 * v : l'objet Votant
 */
function buildDivVotant(v) {
	var votant = document.createElement("div");

	var _img = document.createElement("img");
	$(_img).attr({
		"src" : v.URLImg,
		"width" : "120px",
		"height" : "120px",
		"alt" : v.Prenom + " " + v.Nom
	});

	var _label = document.createElement("p");
	if(!v.Prenom && !v.Nom) {
		$(_label).html(v.ID);
	}
	else {
		$(_label).html(v.Prenom + "<br>" + v.Nom);	
	}
	
	$(_label).css({
		textAlign : "center",
		margin : "5px"
	});

	$(votant).append(_img);
	$(votant).append(_label);

	$(votant).css({
		"margin": "15px",
		"border": "1px solid #000000",
		"display": "inline-block",
		"width": "122px",
		"box-shadow" : "5px 5px 5px #A4A4A4"
	});

	/* L'evenement HOVER sur chaque DIV du votant */
	$(votant).hover(
		function() {
			$(this).css({
				"box-shadow" : "8px 8px 8px #A9BCF5",
				"cursor" : "pointer"
			});
		}, 
		function() {
			$(this).css("box-shadow", "5px 5px 5px #A4A4A4");
		}
	);

	/* Chaque DIV est marque du meme ID que celui de votant que ce DIV represente */
	$(votant).attr("id", _id);

	/* L'evenement CLICK sur chaque DIV du votant */
	$(votant).click(function() {
		$(this).css("box-shadow", "8px 8px 8px #A9BCF5");
		$(this).find("p").css("font-weight", "bold");
		$(this).css("background-color", "#81BEF7");
		// Eviter le cas ou plusieurs votants sont choisis au meme temps
		if(chosenVotant != null && chosenVotant.ID != $(votant).attr("id")) {
			// Reset le votant precedemment choisi, quand l'utilisateur clique sur un autre
			$("#"+chosenVotant.ID).css("background-color", "#FFFFFF");
			$("#"+chosenVotant.ID).find("p").css("font-weight", "normal");
		}
		chosenVotant = findVotantById($(this).attr("id"));
	});

	return votant;
}

/*
 * Fonction pour valider le formulaire
 * Vérifier si des input sont non vides, ou ne contiennent pas des symbols spéciaux
 * Cette fonction est partagée pour la validate du modal ADD et EDIT
 * type : 0 pour indiquer le modal ADD, 1 pour le modal EDIT
 */
function checkForm(type) {
	var isValid = true;
	var prefix = (type == 0) ? "add" : "edit";
	var idInputPrenom = "#" + prefix + "-prenom";
	var idInputNom = "#" + prefix + "-nom";

	/* Verifier <input> : Prenom */
	if( $(idInputPrenom).val() == "") {
		// Vide ?
		$(idInputPrenom).css("border-color", "red");
		$(idInputPrenom).attr("placeholder", "*** Veuillez entrer le Prénom !");
		isValid = false;
	}
	else if( !/^[a-zA-Z- ]*$/.test($(idInputPrenom).val()) ) {
		$(idInputPrenom).css("border-color", "red");
		$(idInputPrenom).val("");
		$(idInputPrenom).attr("placeholder", "*** Symboles/Chiffres non acceptes !");
		isValid = false;
	}
	else {
		$(idInputPrenom).css("border-color", "#CCCCCC");
		$(idInputPrenom).attr("placeholder", "Son prénom");
	}

	/* Verifier <input> : Nom */
	if( $(idInputNom).val() == "" ) {
		// Vide ?
		$(idInputNom).css("border-color", "red");
		$(idInputNom).attr("placeholder", "*** Veuillez entrer le Nom !");
		isValid = false;
	}
	else if( !/^[a-zA-Z- ]*$/.test($(idInputNom).val()) ) {
		$(idInputNom).css("border-color", "red");
		$(idInputNom).val("");
		$(idInputNom).attr("placeholder", "*** Symboles/Chiffres non acceptes !");
		isValid = false;
	}
	else {
		$(idInputNom).css("border-color", "#CCCCCC");
		$(idInputNom).attr("placeholder", "Son nom");
	}

	return isValid;
}

/* 
 * Relever l'instruction correspondante à chaque élément dans la page 
 * (distinguer par ID)
 * caller : l'élément HTML
 */
function getInstruction(caller) {
	switch(caller[0].id) {
		case "item-add": 
		{
			return "<b>AJOUTER UN PETIT VOTANT</b><br><br>Cliquer sur cet item, s'affiche alors un formulaire. Completer ce très simple formulaire pour ajouter un petit votant à la liste";
			break;
		}

		case "item-edit":
		{
			return "<b>MODIFIER UN PETIT VOTANT</b><br><br>Cliquer sur la photo du petit votant que vous voulez, puis cliquer sur cet item pour le modifier (la photo choisie sera marquee en différente couleur)";
			break;
		}

		case "item-remove":
		{
			return "<b>ENLEVER UN PETIT VOTANT</b><br><br>Cliquer sur la photo du petit votant que vous voulez, puis cliquer sur cet item pour l'enlever de la liste (la photo choisie sera marquee en différente couleur)";
			break;
		}

		default:
		{
			return "";
			break;
		}
	}
}

/* 
 * Relever la couleur de fond correspondante à chaque item dans le left-menu 
 * (Ajouter, Modifier, Enlever)
 */
function getBackgroundColorLeftMenu(caller) {
	switch(caller[0].id) {
		case "item-add" :
		{
			return "#F3F781";
			break;
		}

		case "item-edit" :
		{
			return "#A9D0F5";
			break;
		}

		case "item-remove" : 
		{
			return "#F78181";
			break;
		}

		default : 
		{
			return "CCCCCC";
			break;
		}
	}
}