select	prix_ttc
from	tarifs t, calendrier c, sejours s
where	t.no_sem = c.no_sem
and		t.code_sejour = s.code_sejour
and		TO_DATE('10-APR-2011', 'DD-MM-YY') <= date_deb
and		date_fin <= TO_DATE('10-MAY-2011', 'DD-MM-YY')
and		nom_sejour = 'SOLEIL DE L''ANDALOUSIE';