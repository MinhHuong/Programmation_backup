select		numero_realisateur as num_real, nom_realisateur as nom_real
from		realisateur
where		numero_realisateur not in
(
	select		re.numero_realisateur
	from		realisateur re, film f
	where		re.numero_realisateur = f.numero_realisateur
);