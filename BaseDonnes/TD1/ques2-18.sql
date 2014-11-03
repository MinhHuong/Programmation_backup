select	distinct nom_acteur
from	acteur
union
(
select	nom_realisateur
from	realisateur
);