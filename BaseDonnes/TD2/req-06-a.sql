-- 1 : retourne une colonne avec toute valeur = 1
select NUMERO_ACTEUR , NUMERO_FILM , 1
from ROLE
union
select NUMERO_ACTEUR , null , count(*)
from ROLE
group by NUMERO_ACTEUR
union
select null , NUMERO_FILM , count(*)
from ROLE
group by NUMERO_FILM
union
select null , null , count(*)
from ROLE
order by 1 asc nulls last , 2 asc nulls last ;
--nulls last : specifies that the NULL values should be returned after the NON-NULL values
--toutes les valeurs nulles sont placées après les valeurs non-nulles
--order by <entier> : la colonne <entier> dans la requête SELECT

-- OBJECTTIF : pour chaque acteur, afficher le nombre de films qu'il a eu un rôle, puis une ligne dernière (de chaque acteur) retourne le nombre total de leurs films

/*
En ordre :
	- 1e sous-enquête : le numéro des acteurs et le numéro des films avec une colonne dont toute valeur = 1 --> pour chaque valeur de (num_act, num_film), on affecte un compteur = 1
	- 2e sous-enquête : pour chaque acteur, le nombre total de films òu il a eu un rôle
	(la ligne dernière de chaque acteur avant d'en passer à un autre)
	- 3e sous-enquête : pour chaque film, le nombre d'acteurs qui ont un rôle (le numéro des acteurs se met à NULL)
	- 4e sous-requête : la ligne servant à compter le nombre total de lignes

*/