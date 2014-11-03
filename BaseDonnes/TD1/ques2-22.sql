select 	*
from	realisateur
where	numero_realisateur = 
(
	select	numero_realisateur
	from	realisateur
	minus
	(
		select	numero_realisateur
		from	film 
	)
);