select	numero_realisateur as num_real, nom_realisateur as nom_real, prenom_realisateur as prenom_real
from	realisateur
where	prenom_realisateur	in
(
	select	prenom_acteur
	from	acteur
);