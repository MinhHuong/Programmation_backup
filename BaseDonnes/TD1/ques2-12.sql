select		nom_acteur, count(a.numero_acteur)
from		acteur a, role ro
where		a.numero_acteur = ro.numero_acteur
group by	nom_acteur;