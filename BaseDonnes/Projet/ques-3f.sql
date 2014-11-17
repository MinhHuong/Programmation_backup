select 	avg(prix_ttc) as prix_moyen
from	tarifs t, sejours s, calendrier c, pays p
where	t.code_sejour = s.code_sejour
and		t.no_sem = c.no_sem
and		s.cod_pays = p.cod_pays
and		nom_pays = 'ESPAGNE'
and		(date_deb, date_fin) overlaps (TO_DATE('1-JUL-2011', 'DD-MM-YY'), TO_DATE('31-AUG-2011', 'DD-MM-YY'));