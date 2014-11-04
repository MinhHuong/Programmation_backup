--j. Pour chaque acteur (nom, prénom), le nombre de films dans lesquels il a joué

select		nom_acteur, prenom_acteur, count(*) as nb_films
from		acteur a, role ro 
where		ro.numero_acteur = a.numero_acteur
group by	nom_acteur, prenom_acteur
order by	nom_acteur asc;

--numero_acteur et numero_film est une cle de ROLE, alors il est impossible qu'un acteur joue plusieurs roles dans un meme film