select 	avg(prix_ttc) as prix_moyen
from	tarifs t, sejours s, calendrier c, pays p
where	t.code_sejour = s.code_sejour
and		t.no_sem = c.no_sem
and		s.cod_pays = p.cod_pays
and		nom_pays = 'ESPAGNE'
and		TO_DATE('1-JUL-2011', 'DD-MM-YY') <= date_deb
and		date_fin <= TO_DATE('31-AUG-2011', 'DD-MM-YY');