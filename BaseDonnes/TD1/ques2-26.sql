select	nom_acteur
from	acteur
where 	numero_acteur	not in
(
	select	a.numero_acteur
	from	acteur a, role ro, film f, realisateur re
	where	a.numero_acteur = ro.numero_acteur
	and		f.numero_film = ro.numero_film
	and		f.numero_realisateur = re.numero_realisateur
	and		re.numero_realisateur = 7
);