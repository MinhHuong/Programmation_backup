select		p.cod_pays, nom_pays, count(*) as TOTAL
from		pays p, sejours s
where 		p.cod_pays = s.cod_pays
group by	p.cod_pays, nom_pays;