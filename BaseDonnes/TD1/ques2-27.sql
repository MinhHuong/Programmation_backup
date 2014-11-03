select	*
from	realisateur
where	numero_realisateur not in
(
	select	numero_realisateur
	from	film
);
	