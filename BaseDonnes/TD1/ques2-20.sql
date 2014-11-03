select	distinct nom_acteur
from	acteur
minus
( 
select	nom_realisateur
from 	realisateur 
);