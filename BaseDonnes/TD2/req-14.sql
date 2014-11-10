select 	NUMERO_ACTEUR , NOM_ACTEUR , DATE_DE_NAISSANCE ,
		( DATE_DE_NAISSANCE - interval '99' YEAR ) DATE_DE_NAISSANCE_XXeme
from 	ACTEUR
where 	DATE_DE_NAISSANCE is not null
and ( DATE_DE_NAISSANCE - interval '59' YEAR, DATE_DE_NAISSANCE - interval '49' YEAR ) overlaps
	( CURRENT_DATE - interval '50' YEAR , CURRENT_DATE - interval '30' YEAR );
	
/*
	- interval '99' YEAR : l'intervalle entre 99 années 0 mois
	- ( DATE_DE_NAISSANCE - interval '99' YEAR ) : prend l'année dans DATE_DE_NAISSANCE - 99 années
	- CURRENT_DATE : la date courante
	- overlaps : tester s'il y a un chevauchement de temps sur l'intervalle de temps prédéfinie
	Ex : 1900 - 2000 overlaps 1950 - 1994 --> résultat : oui
	
	Chercher des acteurs tels que :
		- sa date de naissance non nulle
		- il y a un chevauchement de temps pendant la durée (année_naissance - 59, année_naissance - 49) et (année_courant - 50, année_courante - 30)
*/