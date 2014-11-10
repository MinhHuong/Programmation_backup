select 	NUMERO_ACTEUR , NOM_ACTEUR , 
		nullif(NATION_ACTEUR,'FRANCAISE') as Nationalite,
		coalesce(cast(DATE_DE_NAISSANCE as char(15)),'inconnue') as Naissance
from 	ACTEUR
where 	substr(NOM_ACTEUR,3,1) in ('A','E','I','O','U','Y') ;
/*
Chercher des acteurs tels que :
	- nation = null si nation = 'francaise', sinon afficher la nationalité 
	- coalesce(cast(DATE_DE_NAISSANCE as char(15)),'inconnue') : si DATE_DE_NAISSANCE est null, alors affichez 'inconnue'
	- le 3e caractère se trouve dans un de ces caractères : ('A','E','I','O','U','Y')
*/
