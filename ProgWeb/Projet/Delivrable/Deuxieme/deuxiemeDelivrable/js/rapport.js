var imgWeb = [ 
	{
		lien: "img/web/login.png", 
		explain: "<b>[ LOGIN ]</b><br><br> Un formulaire s'affiche, permet de se connecter au site web"
	},
	{
		lien: "img/web/loginWrongUsername.png", 
		explain: "<b>[ LOGIN ]</b><br><br> Le cas òu l'utilisateur saisit le faux nom de compte."
	},
	{
		lien: "img/web/loginWrongPass.png", 
		explain: "<b>[ LOGIN ]</b><br><br> Le cas òu l'utilisateur saisit le faux mot de passe"
	},
	{
		lien: "img/web/loginWrongUsernamePass.png",
		explain: "<b>[ LOGIN ]</b><br><br> Le cas òu l'utilisateur laisse les deux champs vides"
	},
	{
		lien: "img/web/loginCorrectly.png",
		explain: "<b>[ LOGIN ]</b><br><br> Saisir le bon nom de compte + Mot de passe pour se connecter. Dans cette simple intégration de maquette, il suffit d'entrer n'importe quelle valeur dans ces deux champs"
	},
	{
		lien: "img/web/votantWelcome.png",
		explain: "<b>[ VOTANT ]</b><br><br> L'écran bienvenue du site web. L'item VOTANTS sur le navigation bar est coloré en gris, pour dire que l'utilisateur est maintenant dans la partie de gestion des Votants"
	}, 
	{
		lien: "img/web/votantAjouterInstruction.png",
		explain: "<b>[ VOTANT ]</b><br><br> Hover sur l'item “Ajouter un petit votant” pour lire l'instruction affichée au-dessous"
	},
	{
		lien: "img/web/votantAjouter.png",
		explain: "<b>[ VOTANT ]</b><br><br> Le modal “Ajouter un petit candidat” affiche un formulaire pour prendre l'information d'un nouveau Votant"
	},
	{
		lien: "img/web/votantEnAjout.png",
		explain: "<b>[ VOTANT ]</b><br><br> On complète le formulaire. Un message d'erreur s'affiche Dans ce 3 cas : <br>+ prénom/nom vide<br>+ prénom/nom contient des chiffres/caractères spéciaux<br>+ fichier choisi n'est pas une image (même des noms avec les accents, tels que é,è, â... sont refusés, nous ne sommes pas surs de cette restriction)"
	},
	{
		lien: "img/web/votantAjoute.png",
		explain: "<b>[ VOTANT ]</b><br><br> Un nouveau Votant est ajouté dans le tableau."
	},
	{
		lien: "img/web/votantAjouterBcp.png",
		explain: "<b>[ VOTANT ]</b><br><br> On peut alors ajouter plusieurs Votants. Chaque fois un Votant est ajouté, il est marqué en bleu"
	},
	{
		lien: "img/web/votantModifierInstruction.png",
		explain: "<b>[ VOTANT ]</b><br><br> Pour MODIFIER, cliquer sur un petit Votant (dans ce cas, Legolas), puis cliquer sur l'item “Modifier un petit votant” <br><br>(l'usage est indiqué dans l'instruction au-dessous)"
	},
	{
		lien: "img/web/votantEnModifier.png",
		explain: "<b>[ VOTANT ]</b><br><br> Un Modal s'affiche, permet de modifier des informations de Legolas (nom/prénom/photo)"
	},
	{
		lien: "img/web/votantModifie.png",
		explain: "<b>[ VOTANT ]</b><br><br> Legolas Greenleaf est modifié. Maintenent il est Legolas Gorgeous"
	},
	{
		lien: "img/web/votantEnlever.png",
		explain: "<b>[ VOTANT ]</b><br><br> Pour ENLEVER, cliquer sur le petit votant que vous voulez, puis cliquer sur l'item “Enlever ce petit votant” <br><br>(L'usage est indiqué dans l'instruction au-dessous)"
	},
	{
		lien: "img/web/votantEnEnlever.png",
		explain: "<b>[ VOTANT ]</b><br><br> Un Modal de confirmation s'affiche, présente les informations complètes de petit Votant, pour garantir que c'est bien l'intention de l'utilisateur"
	},
	{
		lien: "img/web/votantEnleve.png",
		explain: "<b>[ VOTANT ]</b><br><br> Galadriel est enlevé de la liste des Votants. Qui va sauver Middle-Earth ??"
	},
	{
		lien: "img/web/sujetDefault.png",
		explain: "<b>[ TOPIC ]</b><br><br> L'état initial de la page “VOTE DU JOUR”, avec l'item “VOTE DU JOUR” sur le navigation bar marqué en gris.<br> Cliquer sur le bouton “Commencer” pour commencer la vote du jour. <br>Cliquer sur le bouton “Modifier” pour modifier ce Topic. <br>Chaque Topic a 4 subtopics."
	},
	{
		lien: "img/web/sujetEnModifier.png",
		explain: "<b>[ TOPIC ]</b><br><br> On entre dans la modification d'un Topic"
	},
	{
		lien: "img/web/sujetModifie.png",
		explain: "<b>[ TOPIC ]</b><br><br> On remplace le Subtopic ONE RING par THRANDUIL. <br>Cliquer sur “Confirmer” pour appliquer le changement<br>“Annuler” pour annuler toutes les modifications"
	},
	{
		lien: "img/web/sujetNouveauTopic.png",
		explain: "<b>[ TOPIC ]</b><br><br> Cliquer sur le bouton radio “Nouveau thème +” pour préparer un nouveau Topic. <br>Le bouton “Commencer” est disabled dans ce cas"
	},
	{
		lien: "img/web/sujetNouveauTopicModifier.png",
		explain: "<b>[ TOPIC ]</b><br><br> On entre dans la partie de modification d'un Topic"
	},
	{
		lien: "img/web/sujetNouveauTopicEnModifier.png",
		explain: "<b>[ TOPIC ]</b><br><br> On fait quelques changements dans cette partie. <br>Un message d'erreur s'affiche dans 3 cas : <br>+ Titre de Topic/Subtopic contient des chiffres/caractères spéciaux<br>+ Titre de Topic/Subtopic est vide<br>+ Le fichier choisi n'est pas une image (même des noms avec les accents, tels que é,è, â... sont refusés)"
	},
	{
		lien: "img/web/sujetNouveauTopicAjoute.png",
		explain: "<b>[ TOPIC ]</b><br><br> Un nouveau Topic est ajouté. Un autre bouton radio est ajouté dans la liste à gauche, représentant le Topic qui vient d'être défini"
	},
	{
		lien: "img/web/votingDefault.png",
		explain: "<b>[ EN COURS DE VOTE ]</b><br><br> L'état initial qui aide à la supervision de la vote. <br>L'utilisateur ne peut pas se déconnecter pendant ce procès. <br>Le bouton “Actualiser” met à jour le status des Votants (déjà – en cours – pas encore voter). <br>Le bouton “Arrêter” cesse immédiatement la vote, sans savoir si tous les Votants ont déjà fait leur choix."
	},
	{
		lien: "img/web/votingActualise.png",
		explain: "<b>[ EN COURS DE VOTE ]</b><br><br> Le bouton “Actualiser” est cliqué. <br>+ Le tick vert : ce votant a déjà voté. <br>+ Le crayon jaune : ce votant est en train de voter (cad sur l'application Android, il appuie déjà sur son nom, mais il ne choisit pas encore son sujet préféré). <br>+ Les restes ne votent pas encore"
	},
	{
		lien: "img/web/resultDefault.png",
		explain: "<b>[ RÉSULTAT ]</b><br><br> La page de résultat. <br>À gauche, le résultat de la vote, le nombre de choix pour chaque Subtopic. <br>À droite, le tableau de tous les Votants, avec leur choix de Subtopic précisé. <br>Le bouton “Nouvelle vote” sert à commencer une nouvelle vote, mais toutes les données de l'ancienne vote seront perdues"
	},
	{
		lien: "img/web/resultNouvelleVote.png",
		explain: "<b>[ RÉSULTAT ]</b><br><br> Un Modal de confirmation avant d'éraser ces résultats. <br>“Confirmer” : la page fait retourner à la partie de gestion des Topics.<br>“Annuler” : la page ne change rien."
	},
	{
		lien: "img/web/resultDisconnect.png",
		explain: "<b>[ RÉSULTAT ]</b><br><br> L'utilisateur peut se déconnecter en cliquant sur le lien ici. Cela fait retourner à la page de LOGIN."
	}
];

var imgApp = [
	{
		typeEcran: "normal",
		lien: "img/app/norm-waiting.png",
		explain: "<b>[ ATTENTE ]</b><br><br> L'écran d'attente, prétend que le serveur n'est pas encore prêt (l'enseignant ne finit pas à configurer la vote du jour).<br>Dans cette intégration, cliquer sur l'écran pour commencer l'application"
	},
	{
		typeEcran: "normal",
		lien: "img/app/norm-votants.png",
		explain: "<b>[ VOTANTS ]</b><br><br>La liste des votants (page 1), quand un votant clique sur sa photo, une voix parle : 'Bonjour, nom_du_votant'"
	},
	{
		typeEcran: "normal",
		lien: "img/app/norm-votants-2.png",
		explain: "<b>[ VOTANTS ]</b><br><br>La liste des votants (page 2)"
	},
	{
		typeEcran: "normal",
		lien: "img/app/norm-votants-3.png",
		explain: "<b>[ VOTANTS ]</b><br><br>La liste des votants (page 3)"
	},
	{
		typeEcran: "normal",
		lien: "img/app/norm-topic.png",
		explain: "<b>[ TOPIC ]</b><br><br>Des quatre Subtopics"
	},
	{
		typeEcran: "normal",
		lien: "img/app/norm-one-voted.png",
		explain: "<b>[ VOTANTS ]</b><br><br>Un des petits votants a déjà voté, sa photo est marquée en gris.'"
	},
	{
		typeEcran: "normal",
		lien: "img/app/norm-vote.png",
		explain: "<b>[ VOTANTS ]</b><br><br>Quand tous les votants ont déjà voté, l'application est prête à afficher le résultat"
	},
	{
		typeEcran: "normal",
		lien: "img/app/norm-result.png",
		explain: "<b>[ RÉSULTAT ]</b><br><br>Des résultats s'affichent sour forme des cercles multicolores"
	},
	{
		typeEcran: "landscape",
		lien: "img/app/land-waiting.png",
		explain: "<b>[ LANDSCAPE ATTENTE ]</b><br><br> L'écran d'attente, prétend que le serveur n'est pas encore prêt (l'enseignant ne finit pas à configurer la vote du jour).<br>Dans cette intégration, cliquer sur l'écran pour commencer l'application"
	},
	{
		typeEcran: "landscape",
		lien: "img/app/land-votants-1.png",
		explain: "<b>[ LANDSCAPE VOTANTS ]</b><br><br>La liste des votants (page 1), quand un votant clique sur sa photo, une voix parle : 'Bonjour, nom_du_votant'"
	},
	{
		typeEcran: "landscape",
		lien: "img/app/land-votants-2.png",
		explain: "<b>[ LANDSCAPE VOTANTS ]</b><br><br>La liste des votants (page 2)"
	},
	{
		typeEcran: "landscape",
		lien: "img/app/land-votants-3.png",
		explain: "<b>[ LANDSCAPE VOTANTS ]</b><br><br>La liste des votants (page 3)"
	},
	{
		typeEcran: "landscape",
		lien: "img/app/land-topic.png",
		explain: "<b>[ LANDSCAPE TOPIC ]</b><br><br>Des quatre Subtopics"
	},
	{
		typeEcran: "landscape",
		lien: "img/app/land-one-voted.png",
		explain: "<b>[ LANDSCAPE VOTANTS ]</b><br><br>Un des petits votants a déjà voté, sa photo est marquée en gris.'"
	},
	{
		typeEcran: "landscape",
		lien: "img/app/land-result.png",
		explain: "<b>[ LANDSCAPE RÉSULTAT ]</b><br><br>Des résultats s'affichent sour forme des cercles multicolores"
	},	
];

$(document).ready(function() {
	loadImage();

	$("#div-web").hide();
	$("#div-description").hide();
	$("#div-android").hide();

	$("#slideshow-web").cycle({
		fx		: "scrollLeft",
		speed	: 350,
		timeout : 0,
		next	: "#slideshow-web",
		after	: showExplanationWeb
	});

	$("#slideshow-app").cycle({
		fx		: "scrollLeft",
		speed	: 350,
		timeout : 0,
		next	: "#slideshow-app",
		after	: showExplanationApp
	});

	$("#item-description").click(function() {
		$("#div-description").show(600);
		$("#div-web").hide();
		$("#div-android").hide();
	});

	$("#item-web").click(function() {
		$("#div-description").hide();
		$("#div-web").show("slow");
		$("#div-android").hide();
	});

	$("#item-android").click(function() {
		$("#div-description").hide();
		$("#div-web").hide();
		$("#div-android").show(600);
	});
});

function showExplanationWeb() {
	$("#explanation-web > p").html(this.alt);
}

function showExplanationApp() {
	$("#explanation-app > p").html(this.alt);
	$("#slideshow-app").css({
		"width"	: this.width,
		"height": this.height
	});
}

function loadImage() {
	/* 
	 * Charger des captures d'écran pour le site web
	 */
	for(var i = 0 ; i < imgWeb.length ; i++) {
		var _img = document.createElement("img");
		$(_img).attr({
			"src"	: imgWeb[i].lien,
			"alt"	: imgWeb[i].explain,
			"width"	: "670px",
			"height": "410px"
		});
		$("#slideshow-web").append($(_img));
	}

	/* 
	 * Charger des captures d'écran pour l'application Android
	 */
	for(var i = 0 ; i < imgApp.length ; i++) {
		var _img = document.createElement("img");
		var w, h;

		if(imgApp[i].typeEcran == "normal") {
			w = "324px";
			h = "519px";
		}
		else {
			w = "519px";
			h = "324px";
		}

		$(_img).attr({
			"src"	: imgApp[i].lien,
			"alt"	: imgApp[i].explain,
			"width"	: w,
			"height": h
		});
		$("#slideshow-app").append($(_img));
	}
}