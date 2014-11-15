select	date_deb, date_fin, prix_ttc
from	sejours s, calendrier c, tarifs t
where	s.code_sejour = t.code_sejour
and		c.no_sem = t.no_sem
and 	nom_sejour = 'MER ET DESERT'
and		prix_ttc =
(
	select	min(prix_ttc)
	from	tarifs t, sejours s
	where	t.code_sejour = s.code_sejour
	and		nom_sejour = 'MER ET DESERT'
);