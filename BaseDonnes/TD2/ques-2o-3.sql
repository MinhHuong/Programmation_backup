select	re.numero_realisateur, nom_realisateur
from	realisateur re
left outer join film f
on		re.numero_realisateur = f.numero_realisateur
where	f.numero_realisateur is null;