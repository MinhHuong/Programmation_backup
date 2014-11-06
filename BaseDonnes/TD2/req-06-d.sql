select NUMERO_ACTEUR , NUMERO_FILM , count(*)
from ROLE
group by grouping sets ( NUMERO_ACTEUR , NUMERO_FILM , () )
order by 1 asc nulls last , 2 asc nulls last ;

--pour chaque acteur, le nombre total de films qu'il a joué
--pour chaque film, le nombre total d'acteurs
-- grouping sets != cube : il n'y a pas de valeurs "crossées"