select		nom_acteur as nom_act, titre_film as titre, date_de_sortie
from		acteur a, film f_res, role ro
where		ro.numero_acteur = a.numero_acteur
and			ro.numero_film = f_res.numero_film
and     	date_de_sortie =
(
	select	min(date_de_sortie)
	from	role ro_bis, film f_bis
	where	ro_bis.numero_film = f_bis.numero_film
	and		ro_bis.numero_acteur = a.numero_acteur
)
order by	nom_acteur;