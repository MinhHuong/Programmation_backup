select row_number() over(order by NATION_ACTEUR) row_number_NATION_ACTEUR ,
 rank() over(order by NATION_ACTEUR) ,
 NUMERO_ACTEUR , NOM_ACTEUR , PRENOM_ACTEUR , NATION_ACTEUR
from ACTEUR
where substr(PRENOM_ACTEUR,0,1) in ( 'B' , 'K' , 'M' , 'P' )
order by row_number_NATION_ACTEUR ;

--row_number = rownum = le nombre de lignes
--afficher les informations de l'acteur, le rang selon la nation, le numéro selon la ligne de la nation