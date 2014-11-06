select *
from ACTEUR
where NUMERO_ACTEUR <> all ( select NUMERO_ACTEUR from ROLE ) ;

--chercher l'acteur qui n'a joué dans aucun film