clear 	screen

column	cod_pays			heading 'Code|pays' justify center
column	nom_pays			heading 'Pays' justify center

column	cod_ville 			heading 'Code|ville' justify center
column	nom_ville			heading 'Ville' justify center

column	type_heberg			heading 'Type|Heberg' justify center
column	nom_heberg			heading 'Hebergement' justify center

column	code_sejour			heading 'Code|sejours' justify center
column	nom_sejour			heading 'Nom|sejour' justify center
column	nb_jours			heading 'Jours' justify center
column 	nb_nuits			heading 'Nuits' justify center
column 	nb_sejours			heading 'Places' justify center
column	nb_reserv			heading 'Occupees' justify center
column	description_sejour	heading 'Description' justify center

column 	nom_hotel			heading 'Hotel' justify center
column	nb_etoiles			heading 'Etoile' justify center
column 	adres_hotel			heading 'Adresse|hotel' justify center
column 	tel_hotel			heading	'Telephone|hotel' justify center

column 	type_transport		heading 'Type|transport' justify center
column 	nom_transport		heading	'Transport' justify center

column	rang_pas			heading 'Rang|passage' justify center
column  nb_jours_etap		heading 'Jours|etape' justify center

column	no_sem				heading 'No. de|semaine' justify center
column	date_deb			heading 'Date de|debut' justify center
column	date_debut			heading 'Date de|debut' justify center
column	date_fin			heading 'Date de|fin' justify center

column 	reduc_enf			heading 'Reduction|enfant (%)' justify center
column 	prix_sem_sup 		heading 'Prix semaine|supplementaire' justify center
column 	suppl_ch_seule		heading	'Chambre|supplementaire' justify center
column	prix_ttc 			heading 'Prix TTC' justify center 

column 	code_res			heading	'Code|reservation' justify center
column 	nom_pers			heading 'Nom' justify center
column 	prenom_pers 		heading 'Prenom' justify center
column 	adresse_pers		heading 'Adresse' justify center
column 	codpost_pers		heading 'Code|postal'
column 	ville_pers			heading 'Ville|client' justify center
column 	tel_pers			heading	'Telephone|client' justify center
column 	date_reserv			heading 'Date|reservation' justify center
column 	nb_adults			heading 'Nb|Adults' justify center
column 	nb_enf				heading	'Nb|Enfants' justify center
column 	nb_seule			heading	'Nb|Ch.seule' justify center
column 	somme_versee		heading 'Somme|versee' justify center
column 	date_vers			heading	'Date|versement' justify center
column 	mont_reserv			heading	'Montant|total' justify center	

column 	prix_ttc_adult		heading 'Prix TTC|Adult' justify center
column 	prix_ttc_enf		heading 'Prix TTC|Enfant' justify center

set pagesize 50
set linesize 150 

ttitle -
	skip -
	left '=============== RESULTAT ===============' -
	skip 2 -
	left 'PAGE : ' format 99 sql.pno -
	skip -
	skip ;
	
	
	
	
	