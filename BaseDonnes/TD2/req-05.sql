select count(*) compte , R.*
from REALISATEUR R , REALISATEUR R_DEUX
where R.NATION_REALISATEUR = R_DEUX.NATION_REALISATEUR
group by R.NUMERO_REALISATEUR, R.NOM_REALISATEUR, R.PRENOM_REALISATEUR, R.NATION_REALISATEUR
order by compte , R.NUMERO_REALISATEUR ;

--chercher et grouper les réalisateurs de même nationalité, donner le nombre de réalisateurs dans chaque groupe