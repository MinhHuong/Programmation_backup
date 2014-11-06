select Genre , count(NUMERO_FILM) , avg(Duree)*count(Duree)-sum(Duree)
from FILM
group by Genre ;

--avg(Duree)*count(Duree)-sum(Duree) : résultat toujours égale (ou quasiment égale) à 0