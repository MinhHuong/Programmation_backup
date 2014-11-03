drop view ActeursFrancais;

create	view	ActeursFrancais	as
select	*
from	acteur
where	nation_acteur = 'FRANCAISE'
with check option; 
--pour éviter le cas òu l'utilisateur ajoute un acteur d'autres nationalités dans la vue