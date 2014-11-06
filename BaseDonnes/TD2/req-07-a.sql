select REALISATEUR.NUMERO_REALISATEUR, ACTEUR.NUMERO_ACTEUR, count(FILM.NUMERO_FILM)
from REALISATEUR
join FILM on REALISATEUR.NUMERO_REALISATEUR = FILM.NUMERO_REALISATEUR
join ROLE on FILM.NUMERO_FILM = ROLE.NUMERO_FILM
join ACTEUR on ROLE.NUMERO_ACTEUR = ACTEUR.NUMERO_ACTEUR
where REALISATEUR.NUMERO_REALISATEUR <= 3 and ACTEUR.NUMERO_ACTEUR <= 3
group by REALISATEUR.NUMERO_REALISATEUR , ACTEUR.NUMERO_ACTEUR
order by REALISATEUR.NUMERO_REALISATEUR , ACTEUR.NUMERO_ACTEUR ;

--pour chaque r�alisateur, le num�ro de l'acteur / des acteurs avec qui il travaille, ainsi que le nombre de films que le r�alisateur et l'acteur ont r�alis� ensemble