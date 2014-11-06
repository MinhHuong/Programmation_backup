select *
from ( select GENRE , count(*) from FILM group by GENRE order by count(*) desc )
where rownum <= 4 ;

--rownum : le nombre de lignes