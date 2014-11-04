select	numero_realisateur as num_real, nom_realisateur as nom_real
from	realisateur
where	numero_realisateur in
(
	select	numero_realisateur
	from	realisateur
	minus
	(
		select	numero_realisateur
		from	film
	)
);