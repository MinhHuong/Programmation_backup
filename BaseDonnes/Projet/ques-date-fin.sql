select	no_sem
from	calendrier
where	date_debut <= to_date( '7-JAN-2011', 'DD-MM-YYYY' )
and		to_date( '7-JAN-2011', 'DD-MM-YYYY' ) <= date_fin;
