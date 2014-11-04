select	distinct	nom_acteur
from	acteur
union
(
	select distinct	nom_realisateur
	from	realisateur
);