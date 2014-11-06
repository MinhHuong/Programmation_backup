select GENRE , count(*) from FILM group by GENRE order by count(*) desc;

--le nombre de films appartenant à un genre précisé