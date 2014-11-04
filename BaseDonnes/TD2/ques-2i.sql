--i. Le nombre d'acteurs jouant dans le film 'GARCON'

select	nom_acteur as nom_act
from	acteur a, role ro, film f
where	ro.numero_acteur = a.numero_acteur
and		ro.numero_film = f.numero_film
and		titre_film = 'GARCON';