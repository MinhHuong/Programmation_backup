select		nom_realisateur, prenom_realisateur
from		realisateur re, role ro, acteur a, film f
where		re.numero_realisateur = f.numero_realisateur
and			ro.numero_film = f.numero_film
and			ro.numero_acteur = a.numero_acteur
and			nom_acteur = 'POIRET'
order by	nom_realisateur asc;