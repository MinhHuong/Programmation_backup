select		distinct c.no_sem, prix_ttc
from		tarifs t, calendrier c
where 		t.no_sem = c.no_sem
and			prix_ttc >= 400
order by	prix_ttc asc;