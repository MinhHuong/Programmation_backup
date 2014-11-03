select		re.nom_realisateur
from		realisateur re, film f
where		f.numero_realisateur = re.numero_realisateur
group by	nom_realisateur
having		count(f.numero_film) = 2;