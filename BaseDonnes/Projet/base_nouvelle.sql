--====================================
-- DROP ALL TABLES
--====================================

--====================================
-- 1 	PAYS
--====================================

create table PAYS (
	cod_pays					char(3)							,
	nom_pays					varchar(20)						,
	constraint	pk_pays			primary key (cod_pays)
);

--====================================
-- 2	VILLES_ETAPES
--====================================

create table VILLES_ETAPES (
	cod_ville					number(3)		auto_increment	,
	cod_pays					char(3)							,
	nom_ville					varchar(20)		not null		,
	constraint	pk_villes		primary key (cod_ville)
);
	
--====================================
-- 3	HEBERGEMENT
--====================================

create table HEBERGEMENT (
	type_heberg					number(1)						,
	nom_type					varchar(20)		not null		,
	constraint	pk_heberg		primary key (type_heberg)
);

--====================================
-- 4	SEJOURS
--====================================

create table SEJOURS (
	code_sejour					char(10)						,
	nom_sejour					varchar(25)		not null		,
	description_sejour			varchar(100)					,
	nb_jours					number(3)		not null		,
	nb_nuits					number(3)		not null		,
	type_heberg					number(1)						,
	nb_sejours					number(4)		not null		,
	constraint	pk_sejours		primary key (code_sejour) 
);

--====================================
-- 5 	HOTEL_RESIDENCE
--====================================

create table HOTEL_RESIDENCE (
	code_sejour					char(10)						,
	cod_ville					number(3)						,
	nom_hotel					varchar(20)		not null		,
	nb_etoiles					number(1)		not null		,
	adres_hotel					varchar(50)		not null		,
	tel_hotel					varchar(15)		not null		,
	constraint	pk_hotel_resi	primary key (code_sejour)		
);
	
--====================================
-- 6	TRANSPORT
--====================================
	
create table TRANSPORT (
	type_transport				number(2) 		auto_increment	,
	nom_type					varchar(30)		not null		,
	constraint	pk_transport	primary key (type_transport)
);

--====================================
-- 7	CIRCUIT
--====================================
	
create table CIRCUIT (
	code_sejour				char(10)							,
	type_transport			number(2)							,
	constraint	pk_circuit	primary key (code_sejour)	
);

--====================================
-- 8	ETAPES_SEJOUR
--====================================
	
create table ETAPES_SEJOUR (
	code_sejour				char(10)							,
	rang_pas				number(2)			not null		,
	cod_ville				number(3)							,
	nb_jours_etap			number(2)			not null		,
	constraint	pk_etp_sej	primary key (code_sejour, rang_pas) 
);

--====================================
-- 9	CALENDRIER	
--====================================

create table CALENDRIER (
	no_sem					char(6)								,
	date_debut				date				not null 		,
	date_fin				date				not null		,
	constraint	pk_calen	primary key (no_sem)
);

--====================================
-- 10 	TARIF
--====================================
	
create table TARIF (
	no_sem					char(6)								,
	code_sejour				char(10)							,
	prix_ttec				number(7,2)			not null		,
	reduc_enf				number(7,2)							,
	prix_sem_sup			number(7,2)							,
	suppl_ch_seule			number(7,2)							,
	constraint	pk_tarif	primary key (no_sem, code_sejour)
);

--====================================
-- 11	RESERVATIONS
--====================================
	
create table RESERVATIONS (
	code_res				number(5)							,
	nom_pers				varchar(20)			not null		,
	prenom_pers				varchar(20)			not null		,
	adresse_pers			varchar(50)			not null		,
	codpost_pers			char(9)				not null		,
	ville_pers				varchar(20)			not null		,
	tel_pers				varchar(15) 		not null		,
	date_reserv				date				not null		,
	nb_adults				number(2)			not null		,
	nb_enf					number(2)			not null		,
	somme_versee			number(7,2)			not null		,
	date_vers				date				not null		,
	constraint	pk_reserv	primary key (code_res)
);

--====================================
-- 12	DETAIL_RESERV
--====================================

create table DETAIL_RESERV (

);





	
	