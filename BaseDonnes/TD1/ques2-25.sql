select		numero_acteur, nom_acteur, nation_acteur
from		acteur
where		nation_acteur	in
(	
	select		nation_acteur	
	from		acteur
	group by 	nation_acteur
	having		count(nation_acteur)	=
	(
		select		max(count(*))
		from		acteur
		group by	nation_acteur
	)
);

