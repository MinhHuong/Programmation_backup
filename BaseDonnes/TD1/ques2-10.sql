select	distinct nom_realisateur
from	realisateur re, film f
where	re.numero_realisateur = f.numero_realisateur;