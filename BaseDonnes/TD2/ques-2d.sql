select	f.numero_film as num_film, f.titre_film as titre, a.numero_acteur as num_act, a.nom_acteur as nom_act
from	film f, acteur a, role ro
where	ro.numero_acteur = a.numero_acteur
and		ro.numero_film = f.numero_film;