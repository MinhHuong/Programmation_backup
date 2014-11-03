delete	from	role	where	numero_acteur in
(
	select	numero_acteur
	from	acteur
	where 	nation_acteur = 'AMERICAINE'
);

delete	from	acteur	where	nation_acteur = 'AMERICAINE';