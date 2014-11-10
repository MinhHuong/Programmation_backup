--i. Le nombre d'acteurs jouant dans le film 'GARCON'

select	count(*) as nb_acteurs
from	acteur a, role ro, film f
where	ro.numero_acteur = a.numero_acteur
and		ro.numero_film = f.numero_film
and		titre_film = 'GARCON';