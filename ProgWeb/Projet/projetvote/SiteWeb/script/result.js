/* 
 * Un simple script
 */

$(document).ready(function() {
	/* 
	 * CLICK sur le bouton "Nouvelle vote"
	 * Demande la confirmation de l'utilisateur, avant de commencer une nouvelle vote
	 * Toutes les informations de l'ancienne vote seront perdues
	 */
	$("#btn-newvote").click(function() {
		$("#modal-confirm").modal({backdrop:"static"});
	});

	/* 
	 * CLICK sur le bouton "Confirmer" (dans le modal)
	 * Commencer une nouvelle vote
	 * Suppose que toutes les donnes des Votants sont gardes
	 */
	$("#btn-confirm").click(function() {
		window.location.replace("../html/sujet.html");
		$("#modal-confirm").modal("hide");
	});

	/* 
	 * CLICK sur le bouton "Annuler" (dans le modal)
	 * Rester sur la page de resultat
	 */
	$("#btn-cancel").click(function() {
		$("#modal-confirm").modal("hide");
	});

	/* 
	 * Initialiser les Tooltips
	 */
	 $('[data-toggle="tooltip"]').tooltip(); 
});
