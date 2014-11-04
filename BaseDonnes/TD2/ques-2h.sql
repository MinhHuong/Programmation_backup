select		numero_acteur as num_act, nom_acteur as nom_act, prenom_acteur as prenom_act
from		acteur
where		nation_acteur = 'FRANCAISE'
and			prenom_acteur	in
(
	select		prenom_realisateur
	from		realisateur
	group by	prenom_realisateur
	having		count(*) = 1
)
order by	nom_acteur;