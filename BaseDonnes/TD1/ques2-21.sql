select	nom_acteur, numero_acteur
from	acteur
where	nation_acteur = 'FRANCAISE'
union
(
select	nom_acteur, numero_acteur
from	acteur
where	nation_acteur = 'AMERICAINE'
);