$(document).ready(function() {
	$("button").click(function() {
		checkForm();
		return false;
	});
});

function checkForm() {
	var err = "";

	if( !$("#name")[0].value ) {
		err += "Nom incorrect. ";
	}

	if( !$("#pass")[0].value ) {
		err += "Mot de passe incorrect.";
	}

	if( err ) {
		$("#error").html(err);
		$("#error").css({"visibility" : "visible"});
	}
	else {
		$("#error").html("No error");
		$("#error").css({"visibility" : "hidden"});
	}
}