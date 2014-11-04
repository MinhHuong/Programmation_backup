select		nom_acteur
from		acteur
where		nom_acteur	in
(
	select		nom_acteur
	from		acteur
	group by	nom_acteur
	having		count(*) = 1
);