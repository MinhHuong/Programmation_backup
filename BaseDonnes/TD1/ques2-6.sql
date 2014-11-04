select 	nom_realisateur, prenom_realisateur
from	realisateur re, role ro, film f
where	re.numero_realisateur = f.numero_realisateur
and		f.numero_film = ro.numero_film
and		ro.numero_acteur = 7;