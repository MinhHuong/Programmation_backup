select		nom_acteur, min(duree) as min_duree, max(duree) as max_duree, max(duree) - min(duree) as ecart, avg(duree) as moyenne_duree
from		acteur a, film f, role ro
where		a.numero_acteur = ro.numero_acteur
and			f.numero_film = ro.numero_film
group by	nom_acteur;