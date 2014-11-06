select NUMERO_ACTEUR , NUMERO_FILM , 1
from ROLE
order by 1 asc nulls last , 2 asc nulls last ;

--pour chaque acteur, le numéro de films qu'il a joué, la colonne 1 se sert d'un compteur