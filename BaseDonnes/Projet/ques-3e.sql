select 	count(*) as total
from	tarifs t, sejours s
where	t.code_sejour = s.code_sejour
and		prix_ttc < 500;