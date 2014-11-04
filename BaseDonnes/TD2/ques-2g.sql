select		re.numero_realisateur as num_real, nom_realisateur as nom_real, prenom_realisateur as prenom_real, count(*)
from		realisateur re, film f
where		re.numero_realisateur = f.numero_realisateur
group by	re.numero_realisateur, nom_realisateur, prenom_realisateur
having		count(*) between 2 and 5
order by	re.numero_realisateur;