select		a.numero_acteur, sum(duree)
from		acteur a, film f, role ro
where		a.numero_acteur = ro.numero_acteur
and			f.numero_film = ro.numero_film
and			nation_acteur = 'FRANCAISE'
group by	a.numero_acteur
having		sum(duree) < 600;