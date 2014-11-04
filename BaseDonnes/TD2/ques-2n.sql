select	prenom_realisateur
from	realisateur
minus
(
	select	prenom_acteur
	from	acteur
);