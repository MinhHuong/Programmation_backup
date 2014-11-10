insert into reservation values (15, 1, 'HILLARY');

select 	type_place
from	reservation rev, place p, categorie_place cp
where	rev.numero_place = p.numero_place
and		p.categorie_de_la_place = cp.categorie_de_la_place
and		rev.numero_place = 1
and		nom_spectateur = 'HILLARY';

update reservation set numero_place = 1 where numero_seance = 2 and nom_spectateur = 'LUC';

select 	type_place
from	reservation rev, place p, categorie_place cp
where	rev.numero_place = p.numero_place
and		p.categorie_de_la_place = cp.categorie_de_la_place
and		rev.numero_place = 1
and		numero_seance = 2
and		nom_spectateur = 'LUC';
