select NUMERO_ACTEUR , NUMERO_FILM , count(*) as Total
from ROLE
group by cube( NUMERO_ACTEUR , NUMERO_FILM )
order by 1 asc nulls last , 2 asc nulls last ;

--même requête que la question précédente