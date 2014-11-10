select	re.numero_realisateur, nom_realisateur
from	realisateur re
left outer join film f
on		re.numero_realisateur = f.numero_realisateur
where	f.numero_realisateur is null;

/*
select REAL.NUMERO_REALISATEUR , NOM_REALISATEUR
from REALISATEUR REAL, FILM F
where REAL.NUMERO_REALISATEUR = F.NUMERO_REALISATEUR(+)
and F.NUMERO_REALISATEUR is null;
*/