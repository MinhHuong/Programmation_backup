select	re.numero_realisateur
from	realisateur re, film f
where	re.numero_realisateur = f.numero_realisateur
and		duree = 
( 
select 	max(duree)
from	film 
);