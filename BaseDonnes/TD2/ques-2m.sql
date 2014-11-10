select	prenom_acteur
from	acteur
intersect
(
	select	prenom_realisateur
	from	realisateur
);