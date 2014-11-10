select	distinct	prenom_acteur
from	acteur
union
(
	select distinct	prenom_realisateur
	from	realisateur
);