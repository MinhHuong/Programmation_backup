create	view	ActeursFrancais	as
select	nom_acteur
from	acteur
where	nation_acteur = 'FRANCAISE';