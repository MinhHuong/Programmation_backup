select		f.numero_film as num_film, titre_film as titre, count(*) as nb_acteurs
from		film f, role ro
where		ro.numero_film = f.numero_film
group by	f.numero_film, titre_film
having		count(*) >= 2
order by	f.numero_film asc;