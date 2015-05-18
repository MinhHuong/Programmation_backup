$(document).ready(function() {
	$("#menu-manag > li").hover(
		function() {
			var msg = getInstruction($(this));
			$(this).css({
				"background-color" : "#D8D8D8",
				"font-weight" : "bold"
			});
			$("#instruction > p").html(msg);
		}, 
		function() {
			$(this).css({
				"background-color" : "#FFFFFF",
				"font-weight" : "normal"
			});
			$("#instruction > p").html("");
		});

	$("#add-confirm").click(function() {
		// à faire suivant
	});

	$("#add-cancel").click(function() {
		alert("Cancel this");
	})
});

function getInstruction(caller) {
	switch(caller[0].id) {
		case "item-add": 
		{
			return "<b>AJOUTER UN PETIT VOTANT</b><br><br>Cliquer sur cet item, s'affiche alors un formulaire. Completer ce très simple formulaire pour ajouter un petit votant à la liste";
			break;
		}

		case "item-edit":
		{
			return "<b>MODIFIER UN PETIT VOTANT</b><br><br>Cliquer sur cet item, puis cliquer sur la photo du petit votant que vous voulez modifier (la photo choisie sera marquee en gris)";
			break;
		}
			
		case "item-remove":
		{
			return "<b>ENLEVER UN PETIT VOTANT</b><br><br>Cliquer sur cet item, puis cliquer sur la photo du petit votant que vous voulez enlever (la photo choisie sera marquee en gris)";
			break;
		}
			
		default:
		{
			return "";
			break;
		}
	}
}
