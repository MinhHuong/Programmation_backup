REMARK * Affichez les noms des réalisateurs avec les titres de leurs films *
REMARK * 1 page cadrée, dans la fenêtre de session, avec en-têtes, rupture par réalisateur ...*

set	pause 'Tapez pour continuer'
set pause on
set pagesize 35
set linesize 100

clear breaks
clear computes

break on nom_realisateur skip 2
compute number label 'Nombre de films :' of titre_film on nom_realisateur

TTITLE SKIP -
 SKIP -
 CENTER 'Resultats' -
 RIGHT 'page:' FORMAT 99 SQL.PNO -
 SKIP -
 CENTER '----------------------' -
 SKIP -
 SKIP
BTITLE SKIP SKIP

column nom_realisateur heading 'Nom des|realisateur' justify center
column titre_film heading 'Titre du film' justify center

select		nom_realisateur, titre_film
from		realisateur re, film f
where		re.numero_realisateur = f.numero_realisateur
order by	nom_realisateur;