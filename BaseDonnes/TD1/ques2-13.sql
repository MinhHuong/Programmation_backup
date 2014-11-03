select		nom_acteur, min(duree), max(duree), max(duree) - min(duree), avg(duree)
from		acteur a, film f, role ro
where		a.numero_acteur = ro.numero_acteur
and			f.numero_film = ro.numero_film
group by	nom_acteur;