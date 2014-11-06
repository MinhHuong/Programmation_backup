select R.NUMERO_REALISATEUR, NOM_REALISATEUR, count(*) as nb_films, count(NUMERO_FILM) as nb_films, count(distinct F.NUMERO_REALISATEUR) as nb_real
from REALISATEUR R
left outer join FILM F on R. NUMERO_REALISATEUR = F. NUMERO_REALISATEUR
where NATION_REALISATEUR = 'FRANCAISE'
group by R.NUMERO_REALISATEUR , NOM_REALISATEUR , PRENOM_REALISATEUR;

--pour chaque réalisateur (numéro + nom), le nombre de films qu'il a réalisé