REMARK *****************************************************************
REMARK * Script SQL*Plus dOracle : liste des films, avec mise en page *
REMARK *****************************************************************
SET PAUSE 'Taper [RETURN] pour continuer'
SET PAUSE ON
SET PAGESIZE 35
SET LINESIZE 100
CLEAR BREAKS
CLEAR COMPUTES
CLEAR SCREEN
BREAK ON GENRE ON REPORT
COMPUTE NUM OF DUREE ON GENRE
COMPUTE NUM OF DUREE ON REPORT
TTITLE SKIP -
 SKIP -
 CENTER 'Les films par genre...' -
 RIGHT 'page:' FORMAT 99 SQL.PNO -
 SKIP -
 CENTER '----------------------' -
 SKIP -
 SKIP
BTITLE SKIP SKIP
COLUMN TITRE_FILM HEADING 'Titre du|film' JUSTIFY CENTER
COLUMN GENRE HEADING 'Genre' JUSTIFY CENTER
COLUMN DUREE HEADING 'Duree' JUSTIFY CENTER FORMAT 999
COLUMN DATE_DE_SORTIE HEADING 'Date de|sortie'JUSTIFY CENTER
SELECT TITRE_FILM,GENRE, DUREE, DATE_DE_SORTIE
FROM FILM
WHERE NUMERO_FILM <= 20
ORDER BY GENRE, DATE_DE_SORTIE