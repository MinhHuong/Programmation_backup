select		re.numero_realisateur, nom_realisateur, count(f.numero_film)
from		realisateur re, film f
where		re.numero_realisateur = f.numero_realisateur
group by	re.numero_realisateur, nom_realisateur
having		count(f.numero_film) >= 3
order by	count(f.numero_film) desc, nom_realisateur asc;