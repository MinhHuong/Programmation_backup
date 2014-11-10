select 	NUMERO_ACTEUR , NOM_ACTEUR , DATE_DE_NAISSANCE ,
		extract(year from DATE_DE_NAISSANCE) ANNEE_DE_NAISSANCE,
		width_bucket(1900+mod(extract(year from DATE_DE_NAISSANCE),100),1950,1970,4) WB
from 	ACTEUR
where 	DATE_DE_NAISSANCE is not null ;

/*
	- width_bucket : WIDTH_BUCKET lets you construct equiwidth histograms, in which the histogram range is divided into intervals that have identical size.
	- mod(extract(year from DATE_DE_NAISSANCE),100) : extraire l'année à partir de la date de naissance, calculer le reste par le quotient extract(...) par 100
	- width_bucket(1900+mod(extract(year from DATE_DE_NAISSANCE),100),1950,1970,4) : créer un histogram dont l'expression donne l'année de naissance, min 1950, max 1970, histogram dividisé en 4 parties de largeur identique, la fonction retourne un nombre entier qui indique dans quelle partie se trouve la valeur calculée par l'expression
*/