select	code_sejour, nom_sejour
from	sejours s, pays p
where	s.cod_pays = p.cod_pays
and		nom_pays = 'ESPAGNE';