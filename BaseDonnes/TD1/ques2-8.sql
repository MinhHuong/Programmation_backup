select	a.numero_acteur, a.nom_acteur, a.prenom_acteur, nation_acteur, date_de_naissance
from	acteur a, film f, role ro, realisateur re
where	re.numero_realisateur = f.numero_realisateur
and		ro.numero_film = f.numero_film
and		ro.numero_acteur = a.numero_acteur
and		re.numero_realisateur = 7;