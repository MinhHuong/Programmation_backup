var _id = 1;

var votants = [];

var votantsOnPage = [];

var maxOnPage;

var onPage = 1;

function Votant(id, p, n) {
	this.ID = id;
	this.Prenom = p;
	this.Nom = n;
}

$(document).ready(function() {
	$("#menu-manag > li").hover(
		function() {
			var msg = getInstruction($(this));
			$(this).css({
				"background-color" : getBackgroundColorLeftMenu($(this)),
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
		/*
		var votant = document.createElement("div");

		var _img = document.createElement("img");
		$(_img).attr({
			src : "../img/defaultIMG.png",
			width : "120px",
			height : "120px",
			alt : $("#add-prenom")[0].value + " " + $("#add-nom")[0].value
		});

		var _label = document.createElement("p");
		var _nom = $("#add-nom")[0].value;
		var _prenom = $("#add-prenom")[0].value;
		$(_label).html(_prenom + "<br>" + _nom);
		$(_label).css({
			textAlign : "center",
			margin : "5px"
		});

		var _votant = new Votant(_prenom, _nom);
		votants.push(_votant);

		$(votant).append(_img);
		$(votant).append(_label);

		$(votant).css({
			"margin": "15px",
			"border": "1px solid #000000",
			"display": "inline-block",
			"width": "122px"
		});
		
		$(votant).attr("id", _id);
		*/

		var _votant = new Votant(_id, $("#add-prenom")[0].value, $("#add-nom")[0].value);
		votants.push(_votant);
		var divVotant = buildDivVotant(_votant);

		// is ready to switch pages 
		// change data in votantsOnPage
		if( !maxOnPage ) {
			maxOnPage = getMaxByPage($("#tab-image"), divVotant);
		}

		if( (_id%maxOnPage == 1) && (_id != 1) ) {
			for(var i = 0 ; i < votantsOnPage.length ; i++) {
				votantsOnPage.pop();
			}
			$("#tab-image").empty();
			$("#tab-goleft").css("visibility", "visible");
			onPage++;
		}

		votantsOnPage.push(_votant);
		$("#tab-image").append(divVotant);

		_id++;

		/******** TASK ********/
		/*
		** 1. Switch between pages of photos
		** 2. Make web responsive !!! REALLY IMPORTANT !!!
		**/

		$("#modal-add").modal("hide");
		return false;
	});

	$("#add-cancel").click(function() {
		$("#modal-add").modal("hide");
		return false;
	});

	$("#modal-add").on("show.bs.modal", function() {
		$("#modal-add form")[0].reset();
	});

	$("#tab-goleft").click(function() {
		var end = (onPage-1)*maxOnPage;
		var begin = end - maxOnPage + 1;

		for(var i = 0 ; i < votantsOnPage.length ; i++) {
			votantsOnPage.pop();
		}
		$("#tab-image").empty();

		for(var i = 0 ; i < maxOnPage ; i++) {
			votantsOnPage.push(votants[begin+i-1]);
			$("#tab-image").append(buildDivVotant(votants[begin+i-1]));
		}

		$("#tab-goright").css("visibility", "visible");
		if(begin == 1) {
			$("#tab-goleft").css("visibility", "hidden");
		}
		onPage--;
	});

	$("#tab-goright").click(function() {
		onPage++;
		var end = onPage*maxOnPage;
		end = (end > (_id-1)) ? (_id-1) : end; 
		/*var begin = end - maxOnPage + 1;*/
		var begin = (onPage-1)*maxOnPage+1;

		for(var i = 0 ; i < votantsOnPage.length ; i++) {
			votantsOnPage.pop();
		}
		$("#tab-image").empty();

		for(var i = begin ; i <= end ; i++) {
			votantsOnPage.push(votants[i-1]);
			$("#tab-image").append(buildDivVotant(votants[i-1]));
		}

		$("#tab-goleft").css("visibility", "visible");
		if(end == (_id-1)) {
			$("#tab-goright").css("visibility", "hidden");
		}
	});
});

function buildDivVotant(v) {
	var votant = document.createElement("div");

	var _img = document.createElement("img");
	$(_img).attr({
		src : "../img/defaultIMG.png",
		width : "120px",
		height : "120px",
		alt : v.Prenom + " " + v.Nom
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
		"width": "122px"
	});

	$(votant).attr("id", _id);

	return votant;
}

function getMaxByPage(divWrapping, divWrapped) {
	var w_wrapping = divWrapping[0].clientWidth;
	var styleWrapped = $(divWrapped).css("width");
	var styleMargin = $(divWrapped).css("margin");
	var w_wrapped = parseInt(styleWrapped.substring(0, styleWrapped.indexOf("p")));
	var w_margin = parseInt(styleMargin.substring(0, styleMargin.indexOf("p")));
	var val = Math.floor(w_wrapping/(w_margin+w_wrapped))
	return val*2;
}

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
			return "grey";
			break;
		}
	}
}