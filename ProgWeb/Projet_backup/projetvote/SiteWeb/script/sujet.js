/* 
 * La classe SubTopic, representant des subtopics
 *		+ ID
 *		+ Titre du SubTopic
 *		+ Le lien de l'image
 */
 function SubTopic(id, t, urlimg) {
 	this.ID = id;
 	this.Titre = t;
 	this.URLImg = urlimg;
 }

/* 
 * La classe Topic, representant le grand topic, dedans se presentant 4 subtopics
 *		+ ID
 *		+ Titre du TOPIC
 *		+ Le tableau de 4 subtopics
 */
 function Topic(id, t, arrSubtopic) {
 	this.ID = id;
 	this.Titre = t;
 	this.Subtopics = arrSubtopic;
 }

/* 
 * Le tableau des Topics
 */
 var topics = [];

/* 
 * La variable qui store le topic choisi actuellement,
 * qui est utilise pendant la modification d'un Topic
 * pour contenant des donnees anciennes
 * --> restore le topic si l'utilisateur annuler des modifications
 */
 var oldTopic = null;

/* 
 * Identifiant courant, servant a attribuer l'identifiant quand un Topic est ajouter
 * La variable est mise a2 4, car il y a 3 topics qui sont predefinis
 */
 var _idTopic = 4;

/* 
 * Chercher le Topic dans le tableau topics[] par ID
 */
 function findTopicById(paramID) {
 	for(var i = 0 ; i < topics.length ; i++) {
 		if(topics[i].ID == parseInt(paramID)) {
 			return topics[i];
 		}
 	}
 	return null;
 }

/* 
 * Predefinir 3 Topics
 */
 function initializeTopic() {
 	var stp01, stp02, stp03, stp04;
 	var arrSTP01 = new Array();
 	var arrSTP02 = new Array();
 	var arrSTP03 = new Array();
 	var topic;

	// TOPIC 1 : MÉTÉO
	var stp01 = new SubTopic(1, "soleil", "../img/sun.jpg");
	var stp02 = new SubTopic(2, "pluie", "../img/rain.jpg");
	var stp03 = new SubTopic(3, "neige", "../img/snow.jpg");
	var stp04 = new SubTopic(4, "brouillard", "../img/mist.jpg");
	arrSTP01.push(stp01);
	arrSTP01.push(stp02);
	arrSTP01.push(stp03);
	arrSTP01.push(stp04);
	var topic = new Topic(1, "Meteo", arrSTP01);
	topics.push(topic);

	// TOPIC 2 : COULEUR
	var stp01 = new SubTopic(5, "rouge", "../img/red.jpeg");
	var stp02 = new SubTopic(6, "vert", "../img/green.png");
	var stp03 = new SubTopic(7, "bleu", "../img/blue.jpg");
	var stp04 = new SubTopic(8, "jaune", "../img/yellow.jpg");
	arrSTP02.push(stp01);
	arrSTP02.push(stp02);
	arrSTP02.push(stp03);
	arrSTP02.push(stp04);
	var topic = new Topic(2, "Couleur", arrSTP02);
	topics.push(topic);

	// TOPIC 3 : HOBBIT
	var stp01 = new SubTopic(9, "smaug", "../img/smaug.jpg");
	var stp02 = new SubTopic(10, "the ring", "../img/onering.jpg");
	var stp03 = new SubTopic(11, "gollum", "../img/gollum.jpeg");
	var stp04 = new SubTopic(12, "arkenstone", "../img/arkenstone.jpg");
	arrSTP03.push(stp01);
	arrSTP03.push(stp02);
	arrSTP03.push(stp03);
	arrSTP03.push(stp04);
	var topic = new Topic(3, "Hobbit", arrSTP03);
	topics.push(topic);
}

$(document).ready(function() {
	/* 
	 * Initialiser les 3 predefinis Topics
	 */
	 initializeTopic();

	 $("#radio-3").attr("checked", true);

	/* 
	 * L'evenement CLICK des boutons radio
	 */
	 $("input[type=radio]").click(function() {
	 	radioOnClick( $(this).attr("id") );
	 });

	/* 
	 * Au debut, des elements appartenant a la classe ".modifying" n'affichent pas
	 * ( .modifying = des elements dans la partie MODIFIER )
	 */
	 $(".modifying").css("display", "none");

	/* 
	 * Click sur le bouton COMMENCER : Aller a une autre page (voting.html)
	 */
	 $("#btn-ready").click(function() {
	 	window.location.replace("../html/voting.html");
	 });

	/* 
	 * Click sur le bouton MODIFIER pour modifier des informations d'un Topic
	 */
	 $("#btn-edit").click(function() {
		changeDisplayStyle(0);

		// Des boutons radio sont disabled quand l'utilisateur veut modifier un Topic
		turnOnOffRadio(true);

		//Faire des operations sur ID pour pouvoir prendre l'ID de l'objet Topic
		var indexBegin = ($("input[type=radio]:checked").attr("id")).indexOf("-");

		// indexBegin != -1 ===> Bouton radio choisi a l'ID "radio-xx", representant un Topic existant
		if(indexBegin != -1) {
			var idTopic = ($("input[type=radio]:checked").attr("id")).substring(indexBegin+1);
			oldTopic = findTopicById(parseInt(idTopic));

			$("#topic").val(oldTopic.Titre);

			for(var i = 1 ; i <= 4 ; i++) {
				var idSubtopic = "subtopic" + i;
				$("#" + idSubtopic + " > div > input[type='text']").val(oldTopic.Subtopics[i-1].Titre);
			}
		}
		// indexBegin = -1 ==> Bouton radio choisi a l'ID "radionew", pour ajouter de nouveaux Topics
		else {
			$("#topic").val("TOPIC");

			for(var i = 1 ; i <= 4 ; i++) {
				var idSubtopic = "subtopic" + i;
				$("#" + idSubtopic + " > div > input[type='text']").val("Subtopic");
			}
		}
	});

	/* 
	 * Click sur le bouton CONFIRMER dans la partie de modification
	 */
	 $("#btn-edit-confirm").click(function() {
	 	// verifier si tous les champs sont valides, avant d'ajouter un nouveau Topic
	 	var accepted = true;

	 	var idSubtopic, selectorInput;

		// oldTopic != null ==> en train de modifier un Topic existant
		if(oldTopic != null) {
			for(var i = 1 ; i <= 4 ; i++) {
				idSubtopic = "subtopic" + i;
				selectorInput = "#" + idSubtopic + " > div > input[type='text']";

				// Le titre des Subtopics
				if ( isValid($(selectorInput).val(), selectorInput) )  {
					var titreSubtopic = $(selectorInput).val();
					oldTopic.Subtopics[i-1].Titre = titreSubtopic;	
				}
				else {
					accepted = false;
				}

				// L'image des Subtopics
				var _url = $("#" + idSubtopic + " > div > img").attr("src");
				if( urlImgValid(_url) ) {
					oldTopic.Subtopics[i-1].URLImg = _url;
				}
			}

			if( isValid($("#topic").val(), "#topic") ) {
				oldTopic.Titre = $("#topic").val();
			}
			else {
				accepted = false;
			}
			
			if(accepted && allUrlImgValid() ) { setTopic(oldTopic); }
		}
		// oldTopic = null ==> en train de creer un nouveau Topic
		else {
			var arrStp = new Array();
			var stp; 
			var selectorInput;
			var _url;

			// Le titre des Subtopics
			for(var i = 1 ; i <= 4 ; i++) {
				idSubtopic = "subtopic" + i;
				selectorInput = "#" + idSubtopic + " > div > input[type='text']";
				_url = $("#" + idSubtopic + " > div > img").attr("src");

				if(isValid($(selectorInput).val(), $(selectorInput)) && urlImgValid(_url) ) {
					var titreSubtopic = $(selectorInput).val();
					// L'image du Subtopic
					stp = new SubTopic( (_idTopic-1)*4 + i, titreSubtopic, _url );
					arrStp.push(stp);
				}
				else {
					accepted = false;
				}
			}

			if( isValid($("#topic").val(), "#topic") ) {
				var titreTopic = $("#topic").val();
			} 
			else {
				accepted = false;
			}

			if(accepted && allUrlImgValid() ) {
				var newTopic = new Topic(_idTopic, titreTopic, arrStp);
				topics.push(newTopic);

				// creer un nouveau bouton radio representant ce nouveau Topic
				var radioBtn = document.createElement("input");
				$(radioBtn).attr({
					"type" 		: "radio",
					"name" 		: "theme",
					"checked" 	: "checked",
					"id"		: "radio-" + _idTopic
				});

				$(radioBtn).click(function() {
					radioOnClick( $(radioBtn).attr("id") );
				});

				$("#radionew").before( $(radioBtn) );

				// creer un nouveau label pour ce bouton radio
				var _label = document.createElement("label")
				$(_label).attr({
					"for" : $(radioBtn).attr("id")
				});

				var labelBtn = document.createElement("p");
				$(labelBtn).text(titreTopic);
				$(_label).append( $(labelBtn) );
				$("#radionew").before( $(_label) );

				var breakLine = document.createElement("br");
				$("#radionew").before( $(breakLine) );

				setTopic(newTopic);

				_idTopic++;
			}
		}

		if(accepted && allUrlImgValid() ) {
			// Enable le bouton COMMENCER (commancer la vote)
			$("#btn-ready").removeClass("disabled");
			turnOnOffRadio(false);
			oldTopic = null;

			// Changer l'affichage : faire apparaitre des elements de la classe ".ready"
			changeDisplayStyle(1);
		}
		else {
			for(var i = 1 ; i <= 4 ; i++) {
				idSubtopic = "subtopic" + i;
				var _url = $("#" + idSubtopic + " > div > img").attr("src");
				if( !urlImgValid(_url) ) {
					$("#" + idSubtopic + " > div > img").css(
						"box-shadow", "5px 5px 5px #FE2E2E"
						);
				}
				else {
					$("#" + idSubtopic + " > div > img").css(
						"box-shadow", "5px 5px 5px #A4A4A4"
						);
				}
			}
		}
	});

	/* 
	 * Quand tous les changements dans la partie de modification sont annules
	 */
	 $("#btn-edit-cancel").click(function() {
	 	changeDisplayStyle(1);
	 	setTopic(oldTopic);
	 	oldTopic = null;
	 	turnOnOffRadio(false);
	 }); 

	/* 
	 * Le click sur le bouton IMG simule un click sur <input type=file>, permettant de choisir
	 * une image
	 */
	 $(".subtopic button").click(function() {
	 	var prefixID = ($(this).parent())[0].id;
	 	$("#"+prefixID+"-selectfile").click();
	 });

	/* 
	 * Charger l'image choisie
	 * Evenement CHANGE sur <input type=file>
	 */
	 $("input[type=file]").change(function() {
	 	var filesSelected = $(this)[0].files;
	 	if (filesSelected.length > 0) 
	 	{
	 		var fileToLoad = filesSelected[0];
	 		var indexEnd = $(this).attr("id").indexOf("-");
	 		var divParentId = $(this).attr("id").substring(0, indexEnd);

	 		if (fileToLoad.type.match("image.*"))
	 		{
	 			var fileReader = new FileReader();
	 			fileReader.onload = function(fileLoadedEvent) 
	 			{
	 				$("#" + divParentId + " img").attr({
	 					"src" : fileLoadedEvent.target.result
	 				});
	 			};
	 			fileReader.readAsDataURL(fileToLoad);
	 		}
	 		else {
	 			$("#" + divParentId + " img").attr({
	 				"src" : "../img/error-img.png"
	 			});
	 		}
	 	}
	 });

	 // Initialiser les Tooltips
	 $('[data-toggle="tooltip"]').tooltip(); 
	});

/* 
 * Changer l'affichage de la page (switch entre les deux classes : .ready et .modifying)
 * status = 0 : .ready 		--> .modifying
 * statuc = 1 : .modifying 	--> .ready
 */
function changeDisplayStyle(status) {
 	if(status == 1) {
 		$(".modifying").css("display", "none");

	 	$("h2.ready").css({
	 		"display" : "block"	
	 	});

	 	$(".subtopic-content").css({
	 		"display" : "inline-block"
	 	});

	 	$(".subtopic").css("display", "inline-block");

	 	$("p.ready").css({
	 		"display" : "block"
	 	});

	 	$("#btn-ready, #btn-edit").css({
	 		"display" : "inline"
	 	});

	 	$(".subtopic-content img").css({
	 		"box-shadow" : "5px 5px 5px #A4A4A4"
	 	});
 	}
 	else if(status == 0) {
 		$(".ready").css("display", "none");
	 	$(".modifying").css("display", "inline-block");

	 	$(".subtopic-content").css({
	 		"width" : "122px"
	 	});

	 	$("input[type='text'].modifying").css({
	 		"display" 	: "inline-block",
	 		"border" 	: "1px solid #CCCCCC"
	 	});
 	}
}

/* 
 * Mettre des textes, des images sur la page
 */
function setTopic(_topic) {
 	if(_topic != null) {
 		var _subtopics = _topic.Subtopics;

 		$("#area-topic h2").text(_topic.Titre.toUpperCase());

 		for(var i = 1 ; i <= _subtopics.length ; i++) {
 			var divID = "subtopic" + i;
 			$("#" + divID + " p").html(_subtopics[i-1].Titre.toUpperCase());
 			$("#" + divID + " img").attr("src", _subtopics[i-1].URLImg);
 		}

 		$("#radio-" + _topic.ID + " + label > p").text(_topic.Titre);
 	}
 	else {
 		// Le cas ou l'utilisateur veut ajoute un nouveau sujet
 		// mais enfin il annule toutes les modifications
 		for(var i = 1 ; i <= 4 ; i++) {
 			var idSubtopic = "subtopic" + i;
 			$("#" + idSubtopic + " > div > img").attr("src", "../img/default0" + i + ".png");
 			$("#" + idSubtopic + " > div > p").text("Subtopic");
 		}
 		$("h2.ready").text("TOPIC");
 		$("#btn-ready").addClass("disabled");
 	}
}

/* 
 * Change de textes et d'images correspondantes en dependant du bouton radio choisi
 */
function radioOnClick(iden) {
 	var indexBegin = iden.indexOf("-");

 	if(indexBegin != -1) {
 		// Un Topic existant, ID = "radio-xx"
 		var idtopic = iden.substring(indexBegin+1);
 		var _topic = findTopicById(idtopic);
 		setTopic(_topic);
 		$("#btn-ready").removeClass("disabled");
 	}
 	else {
 		// Un Topic non existant, ID = "radionew"
 		for(var i = 1 ; i <= 4 ; i++) {
 			var idSubtopic = "subtopic" + i;
 			$("#" + idSubtopic + " > div > img").attr("src", "../img/default0" + i + ".png");
 			$("#" + idSubtopic + " > div > p").text("Subtopic");
 		}
 		$("h2.ready").text("TOPIC");
 		$("#btn-ready").addClass("disabled");
 	}
}

/* 
 * Quand l'utilisateur est en train de modifier un topic,
 * des boutons radio deviennent disabled
 * type = true  : Disabled
 * type = false : Enabled
 */
function turnOnOffRadio(type) {
 	var allRadioBtn = $("input[type=radio]");
 	$(allRadioBtn).each(function() {
 		$(this).attr("disabled", type);
 	});
}

/* 
 * Verifier si la chaine de caracteres passee en parametre n'est pas vide
 */
function isValid(_value, valueFieldSelector) {
 	var result = true;

 	if( _value == "" ) {
 		$(valueFieldSelector).css("border", "1px solid red");
 		$(valueFieldSelector).attr("placeholder", "*** NON VIDE !");
 		result = false;
 	}
 	else if( !/^[a-zA-Z- ]*$/.test(_value) ) {
 		$(valueFieldSelector).css("border", "1px solid red");
 		$(valueFieldSelector).val("");
 		$(valueFieldSelector).attr("placeholder", "A-Z seulement !");
 		result = false;
 	}
 	else {
 		$(valueFieldSelector).css("border", "1px solid #A4A4A4");
 		$(valueFieldSelector).attr("placeholder", "");
 	}

 	return result;
}

/* 
 * Verifier si l'image precisee dans _url est valide (une vrai image)
 */
function urlImgValid(_url) {
 	if(_url == "../img/error-img.png") {
 		return false;
 	}

 	return true;
}

/* 
 * Verifier si toutes les images des 4 subtopics sont valides
 */
function allUrlImgValid() {
	var idSubtopic;

	for(var i = 1 ; i <= 4 ; i++) {
		idSubtopic = "subtopic" + i;
		if( $("#" + idSubtopic + " > div > img").attr("src") == "../img/error-img.png" ) {
			return false;
		}
	}

	return true;
}