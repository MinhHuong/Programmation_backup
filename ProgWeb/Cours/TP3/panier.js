function Product(c, t, a, u) {
	this._code = c;
	this._titre = t;
	this._annee = a;
	this._url = u;
}

var products = [];

var productsCaddie = [];

var chosen = null;

var central, preced;

var prize = 10;

var firstX = 400, lastX = 800, firstY = 100, lastY = 500;

$(document).ready(function() {
	$.ajax({
		url		: "data.json",
		success	: function(result) {
			var arr = JSON.parse(result);
			$.each(arr, function(index, value) {
				var prod = new Product(value.Code, value.Titre, value.An, value.URL);
				products.push(prod);
			});
			displayProduct();
		}
	});
});


//Receives ID (Code) and returns the index of desired element
function findProductById(_id) {
 	for(var i = 0 ; i < products.length ; i++) {
 		if(_id == products[i]._code) {
 			return products[i];
 		}
 	}
}

function hasOccurence(elem, arr) {
 	for(var i = 0 ; i < arr.length ; i++) {
 		if(elem._code == arr[i]._code) {
 			return true;
 		}
 	}
 	return false;
}

function displayProduct() {
 	var listeAlbums = document.createElement("ul");

 	var item, pic, text, link;

 	for(var i = 0 ; i < products.length ; i++) {
 		item = document.createElement("li");
 		pic = document.createElement("img");

 		$(pic).attr({
 			"id"		: products[i]._code + "",
 			"src"		: products[i]._url,
 			"width"		: "45px",
 			"height"	: "45px",
 			"draggable"	: "true"
 		});

 		$(pic).click(function() {
 			chosen = $(this).clone();
 			$(chosen).attr("id", "caddie-" + $(this).attr("id"));
 			$(chosen).css({
 				"position" 	: "absolute",
 				"width"		: "45px",
 				"height"	: "45px"
 			});

 			$("body").mousemove(function(event) {
 				if(chosen != null) {
 					$(chosen).remove();
 					$(chosen).css({
 						"left"	: event.pageX - 22 + "px",
 						"top"	: event.pageY - 22 + "px"
 					});
 					$(chosen).click(function() {
 						if(event.pageX > firstX && event.pageX < lastX && event.pageY > firstY && event.pageY < lastY) {
 							$("body").off("mousemove");
 							var _id = $(this).attr("id");
 							var codeProd = _id.substring(_id.indexOf("-")+1);
 							if( !hasOccurence( findProductById(codeProd) , productsCaddie ) ) {
 								productsCaddie.push( findProductById(codeProd) );
 								updateTable();
 							}
 							else {
 								$(this).remove();
 								var _id = $(this).attr("id").substring($(this).attr("id").indexOf("-") + 1);
 								$("#quant-" + _id).val( parseInt($("#quant-" + _id).val())+1 ).change();
 							}
 							chosen = null;
 						}
 						else {
 							alert("Item must be placed inside of the basket !");
 						}
 					});

 					$(this).append($(chosen));
 				}
 			});
 		});

		link = document.createElement("a");
		$(link).attr({
			"href"	: products[i]._url,
			"target": "_blank"
		}).text(products[i]._titre + ", " + products[i]._annee);

		$(item).append($(pic)).append($(link));
		$(listeAlbums).append($(item));		
	}

	$("#albums").append($(listeAlbums));

	/* 
	 * Control the gallery
	 */
	central = parseInt(products.length/2)-1;
	$( ($("#albums ul").children())[central] ).find("img").animate({ height:"100px", width:"100px"}, 1000);
	$( ($("#albums ul").children())[central] ).find("a").css("color", "red");

	$("#prev").click(function() {
	 	preced = central + 1;
	 	var _last = $("#albums li:last-child");
	 	$(_last).remove();
	 	$("#albums ul").prepend( $(_last) );
	 	$( ($("#albums ul").children())[preced] ).find("img").animate({ height:"45px", width:"45px"}, 1000);
	 	$( ($("#albums ul").children())[central] ).find("img").animate({ height:"100px", width:"100px"}, 1000);
	 	$( ($("#albums ul").children())[central] ).find("a").css("color", "red");
	 	$( ($("#albums ul").children())[preced] ).find("a").css("color", "blue");
	});

	$("#next").click(function() {
	 	preced = central - 1;
	 	var _first = $("#albums li:first-child");
	 	$(_first).remove();
	 	$("#albums ul").append( $(_first) );
	 	$( ($("#albums ul").children())[preced] ).find("img").animate({ height:"45px", width:"45px"}, 1000);
	 	$( ($("#albums ul").children())[central] ).find("img").animate({ height:"100px", width:"100px"}, 1000);  
	 	$( ($("#albums ul").children())[central] ).find("a").css("color", "red");
	 	$( ($("#albums ul").children())[preced] ).find("a").css("color", "blue");
	});
}

function updateTable() {
	var _idChosen = $(chosen).attr("id").substring($(chosen).attr("id").indexOf("-") + 1);

	/* 
	 * The title of album
	 */
	var colTitle = document.createElement("td");
	$(colTitle).text( findProductById(_idChosen)._titre );

	/* 
	 * The quantity 
	 */
	var spinner = document.createElement("input");
	$(spinner).attr({
	 	"type"	: "number",
	 	"min"	: "0",
	 	"value"	: "1",
	 	"id"	: "quant-" + _idChosen
	});
	$(spinner).change(function() {
	 	var _id = $(this).attr("id").substring($(this).attr("id").indexOf("-") + 1);

	 	if( $(this).val() != 0 ) {
	 		$("#prize-" + _id).text( $(this).val() * prize );
	 	}
	 	else {
	 		$("#row-" + _id).remove();
	 		$("#caddie-" + _id).remove();
	 	}
	 });
	var colQuan = document.createElement("td");
	$(colQuan).append( $(spinner) );

	/* 
	 * The prize of that album (will be automatically updated when quantity changes)
	 */
	var colPrize = document.createElement("td");
	$(colPrize).attr("id", "prize-" + _idChosen).text(prize);

	/* 
	 * Create a row
	 */
	var row = document.createElement("tr");
	$(row).attr("id", "row-" + _idChosen);
	$(row).append( $(colTitle) ).append( $(colQuan) ).append( $(colPrize) );

	$("#tab").append( $(row) );
}
