select		a.numero_acteur
from		acteur a, film f, role ro
where		ro.numero_acteur = a.numero_acteur
and			ro.numero_film = f.numero_film
group by	a.numero_acteur
having		avg(duree) = 120;