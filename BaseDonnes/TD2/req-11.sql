select 	NUMERO_ACTEUR , 
		trim(NOM_ACTEUR) || ' ' || ltrim(PRENOM_ACTEUR) as nom_acteur,
		DATE_DE_NAISSANCE ,
		NATION_ACTEUR , 
		case when NATION_ACTEUR = 'FRANCAISE' then 'francaise'
		else 'etrangere'
		end FR_OU_ETR
from 	ACTEUR
where 	extract(year from DATE_DE_NAISSANCE) between 1955 and 1960
or 		regexp_like(PRENOM_ACTEUR,'^[D-F]')
order by NOM_ACTEUR ;

--chercher des acteurs qui sont nés entre 1955 et 1960
--regexp_like(PRENOM_ACTEUR,'^[D-F]') : quand prénom_acteur commence de 'd' à 'f'