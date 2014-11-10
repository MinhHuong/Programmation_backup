select 	stddev(NUMERO_FILM), variance(NUMERO_FILM),
		stddev(NUMERO_REALISATEUR), variance(NUMERO_REALISATEUR),
		corr(NUMERO_FILM,NUMERO_REALISATEUR)
from FILM ;

/*
	stddev : độ lệch (deviation)
	variance : phương sai
	corr : độ lệch tương quan (correlation coefficient)
*/