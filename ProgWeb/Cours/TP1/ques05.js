var products = [];

var object;

function Product(c, t, a, u) {
	this._code = c;
	this._titre = t;
	this._annee = a;
	this._url = u;
}

function loadProduct() {
	var articles = JSON.parse(document.getElementById("product").text);
	articles.forEach(function(p) {
		var _prod = new Product(p.Code, p.Titre, p.An, p.URL);
		products.push(_prod);
	});
}

function afficherProduct() {
	loadProduct();
	var zoneAlbums = document.getElementById("albums");
	var listeAlbums = document.createElement("ul");
	var item, pic, text, link, _id = 0;
	for(var i = 0 ; i < products.length ; i++) {
		item = document.createElement("li");
		pic = document.createElement("img");

		pic.setAttribute("id", _id + "");
		_id++;
		pic.setAttribute("src", products[i]._url);
		pic.setAttribute("width", "45px");
		pic.setAttribute("height", "45px");
		pic.setAttribute("draggable", "true");
		pic.addEventListener("drag", MouseDrag);
		pic.addEventListener("drop", MouseDrop);
		pic.addEventListener("dragstart", DragStart);

		item.appendChild(pic);
		text = document.createTextNode(
			products[i]._titre + ", " + products[i]._annee
			);
		link = document.createElement("a");
		link.setAttribute("href", products[i]._url);
		link.setAttribute("target", "_blank")
		link.appendChild(text);
		item.appendChild(link);
		listeAlbums.appendChild(item);
	}
	zoneAlbums.appendChild(listeAlbums);
}

function MouseDrop(ev) {
	ev.preventDefault();

	var _tab = document.getElementById("tab");
	if(hasOccurrence(_tab)) {
		alert("Item already added to cash");
		return;
	}

	var _img = document.createElement("img");
	_img.setAttribute("src", object.src);
	_img.setAttribute("id", "img" + object.id);
	_img.style.left = "" + (ev.clientX - 420) +"px";
	_img.style.top = "" + (ev.clientY - 220) + "px";
	_img.setAttribute("width", "45px");
	_img.setAttribute("height", "45px");
	_img.style.position = "absolute";
	_img.addEventListener("drop", MouseDrop);
	_img.addEventListener("dragstart", DragStart);
	_img.addEventListener("drag", MouseDrag);
	_img.style.zIndex = "1";
	document.getElementById("prod-caddie").appendChild(_img);

	updateTab();

	object = null;
}

function updateTab() {
	var _title = products[object.id]._titre;
	var _tab = document.getElementById("tab");

	var prize = 10;

	var row = document.createElement("tr");
	row.setAttribute("id", "row" + object.id);

	var colTitle = document.createElement("td");
	colTitle.appendChild(document.createTextNode(_title));

	var colQuan = document.createElement("td");
	var spinner = document.createElement("input");
	spinner.setAttribute("type", "number");
	spinner.setAttribute("value", "1");
	spinner.setAttribute("id", "quant" + object.id);
	spinner.addEventListener("change", changePrize);
	colQuan.appendChild(spinner);

	var colPrize = document.createElement("td");
	colPrize.appendChild(document.createTextNode(prize));
	colPrize.setAttribute("id", "prize" + object.id);

	row.appendChild(colTitle);
	row.appendChild(colQuan);
	row.appendChild(colPrize);

	_tab.appendChild(row);
}

function changePrize() {
	var realID = this.id.substring(5);
	var prizeField = document.getElementById("prize" + realID);

	if(this.value == 0) {
		var row = document.getElementById("row" + realID);
		row.parentNode.removeChild(row);
		var caddie = document.getElementById("prod-caddie");
		caddie.removeChild(document.getElementById("img" + realID));
	}
	else {
		var newPrize = this.value * 10;
		prizeField.removeChild(prizeField.firstChild);
		prizeField.appendChild(document.createTextNode(newPrize));	
	}
}

function hasOccurrence(tab) {
	var elem = tab.childNodes;

	for (var i = 2; i < elem.length; i++) {
		if(elem[i].id.substring(3) == object.id) {
			return true;
		}
	}

	return false;
}

function MouseDrag(ev) {
	ev.preventDefault();
}

function DragStart(ev) {
	object = this;
}

function allowDrop(ev) {
	ev.preventDefault();
}

function initialize() {
	afficherProduct();
	object = null;
}

