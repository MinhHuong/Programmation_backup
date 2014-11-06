select 	distinct PRENOM_REALISATEUR
from 	REALISATEUR
where 	exists 
( 
	select 	*
	from 	ACTEUR
	where 	PRENOM_ACTEUR = PRENOM_REALISATEUR 
);

--chercher tous les acteurs dont le prenom est le même que celui des réalisateurs
-- exists : retourner 'true' si la sous-requête trouve au moins une ligne