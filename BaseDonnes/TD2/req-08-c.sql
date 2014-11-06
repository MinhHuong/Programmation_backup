select GENRE , NbFilmsDuGenre, RangNbFilmsDuGenre
from ( select GENRE , NbFilmsDuGenre ,
 rank() over(order by NbFilmsDuGenre desc) RangNbFilmsDuGenre
 from ( select GENRE , count(*) NbFilmsDuGenre
 from FILM
 group by GENRE
 order by NbFilmsDuGenre desc ) )
where RangNbFilmsDuGenre <= 4 ; 

--RANK : le rang n'est pas forcément une chaine de nombres consécutifs
--chercher les genres selon leur rang
--pas le même que ROWNUM = le nombre de lignes