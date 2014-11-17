select	prix_ttc, s.code_sejour, nom_sejour, date_deb, date_fin
from	tarifs t, calendrier c, sejours s, pays p
where	t.code_sejour = s.code_sejour
and		t.no_sem = c.no_sem
and 	s.cod_pays = p.cod_pays
and		(date_deb, date_fin) overlaps (to_date('20-DEC-2010', 'DD-MON-YYYY'), to_date('27-DEC-2010', 'DD-MON-YYYY') ) 	
and		nom_pays = 'FRANCE';