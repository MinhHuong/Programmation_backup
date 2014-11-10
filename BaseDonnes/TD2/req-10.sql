select 	GENRE, 
		rank() over(partition by GENRE order by DUREE) as rang_duree, 
		NUMERO_FILM, TITRE_FILM, DUREE,
		count(*) over(partition by GENRE) as nb_genres,
		count(*) over() as nombre,
		min(Duree) over(partition by GENRE) as min_duree,
		min(Duree) over() as min_result,
		max(Duree) over(partition by GENRE) as max_duree, 
		max(Duree) over()
from FILM
where trim(GENRE) not like '% %'
order by GENRE , DUREE , NUMERO_FILM ;

--The OVER clause specifies the partitioning, ordering & window "over which" the analytic function operates.
--rank() over(partition by GENRE order by DUREE) : donner le rang selon la durée de chaque genre (à chaque nouveau genre, le rang est renouvelé)
--count(*) over(partition by GENRE) : compter le nombre de films dans un genre
--count(*) over() : compter le nombre de total des résultats
--min(Duree) over(partition by GENRE) : la durée minimale dans l'ensemble des films de chaque genre