select	nom_acteur
from	acteur
where	nom_acteur in
( 
select	nom_realisateur
from	realisateur
);