select		distinct nom_acteur as Nom_Acteur, nation_acteur as nation, date_de_naissance as Naissance, nom_realisateur as Nom_Real
from		realisateur re, film f, ActeursFrancais af, role ro
where		re.numero_realisateur = f.numero_realisateur
and			af.numero_acteur = ro.numero_acteur
and			f.numero_film = ro.numero_film
order by	nom_acteur asc;