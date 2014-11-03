select 	nom_realisateur, prenom_realisateur
from	realisateur, role, film
where	realisateur.numero_realisateur = film.numero_realisateur
and		film.numero_film = role.numero_film
and		role.numero_acteur = 7;