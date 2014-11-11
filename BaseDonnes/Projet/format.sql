column	cod_pays			heading 'Code|pays' justify center
column	nom_pays			heading 'Pays' justify center

column	code_sejour			heading 'Code|sejours' justify center
column	nom_sejour			heading 'Nom|sejour' justify center
column	description_sejour	heading 'Description' justify center

column	no_sem				heading 'No. de|semaine' justify center
column	date_deb			heading 'Date de|debut' justify center
column	date_fin			heading 'Date de|fin' justify center

column	prix_ttc 			heading 'Prix TTC' justify center 

set pagesize 50
set linesize 200 

ttitle -
	skip -
	left '=============== RESULTAT ===============' -
	skip 2 -
	left 'PAGE : ' format 99 sql.pno -
	skip -
	skip ;
	
	
	
	
	