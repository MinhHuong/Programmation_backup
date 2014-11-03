select	distinct nom_acteur
from	acteur
intersect
(
select	nom_realisateur 
from	realisateur
);