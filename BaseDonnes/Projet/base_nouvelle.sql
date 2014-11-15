--==============================================================--
-- 				   SUPPRIMER TOUTES LES TABLES					--	
--==============================================================--

drop table DETAIL_RESERV;

drop table RESERVATIONS;

drop sequence seq_reservation;

drop table TARIF;

drop table CALENDRIER;

drop table ETAPES_SEJOUR;

drop table CIRCUITS;

drop table TRANSPORT;

drop table HOTEL_RESIDENCE;

drop table SEJOURS;

drop table HEBERGEMENT;

drop table VILLES_ETAPES;

drop table PAYS;

--==============================================================--
-- 						CREER DES TABLES						--	
--==============================================================--

--====================================
-- 1 	PAYS
--====================================

create table PAYS (
	cod_pays					char(3)							,
	nom_pays					varchar(20)		not null		,
	constraint	pk_pays			primary key (cod_pays)
);

--====================================
-- 2	VILLES_ETAPES
--====================================

create table VILLES_ETAPES (
	cod_ville					number(3)						,
	cod_pays					char(3)							,
	nom_ville					varchar(20)		not null		,
	constraint	pk_villes		primary key (cod_ville)
);
	
--====================================
-- 3	HEBERGEMENT
--====================================

create table HEBERGEMENT (
	type_heberg					number(2)						,
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
	type_heberg					number(2)						,
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
	type_transport				number(2) 						,
	nom_type					varchar(30)		not null		,
	constraint	pk_transport	primary key (type_transport)
);

--====================================
-- 7	CIRCUITS
--====================================
	
create table CIRCUITS (
	code_sejour				char(10)							,
	type_transport			number(2)							,
	constraint	pk_circuits	primary key (code_sejour)	
);

--====================================
-- 8	ETAPES_SEJOUR
--====================================
	
create table ETAPES_SEJOUR (
	code_sejour				char(10)							,
	rang_pas				number(2)							,
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
	reduc_enf				number(7,2)			not null		,
	prix_sem_sup			number(7,2)			not null		,
	suppl_ch_seule			number(7,2)			not null		,
	constraint	pk_tarif	primary key (no_sem, code_sejour)
);

--====================================
-- 11	RESERVATIONS, SEQUENCE & TRIGGER pour auto-incrémenter le code_res
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

create sequence seq_reservation 
	start with 		1
	increment by 	1
	cache			5 ; 
	
create or replace trigger trg_auto_incre_reserv
before insert on RESERVATIONS
for each row
begin
	select 	seq_reservation.nextVal
	into 	:new.code_res
	from 	dual;
end trg_auto_incre_reserv;
/

--====================================
-- 12	DETAIL_RESERV
--====================================

create table DETAIL_RESERV (
	no_sem					char(6)								,
	code_res				number(5)							,
	code_sejour				char(10)							,
	prix_ttc_adult			number(7,2)			not null		,
	prix_ttc_enf			number(7,2)			not null		,
	constraint	pk_det_resv	primary key (no_sem, code_res)
);

--==============================================================--
-- 						CLES EXTERNES							--	
--==============================================================--

--====================================
-- VILLES_ETAPES ref PAYS
--====================================

alter table VILLES_ETAPES
	add constraint	fk_villes_etapes_pays		foreign key (cod_pays)
		references 	PAYS(cod_pays)
			on delete cascade;

--====================================
-- SEJOURS ref HEBERGEMENT
--====================================

alter table SEJOURS
	add constraint	fk_sejours_heberg			foreign key (type_heberg)
		references 	HEBERGEMENT(type_heberg)
			on delete cascade;

--====================================
-- HOTEL_RESIDENCE ref SEJOURS, ref VILLES_ETAPES
--====================================

alter table HOTEL_RESIDENCE
	add constraint	fk_hotel_resi_sejour		foreign key (code_sejour)
		references 	SEJOURS(code_sejour)
			on delete cascade;
			
alter table HOTEL_RESIDENCE
	add constraint	fk_hotel_resi_ville			foreign key (cod_ville)
		references 	VILLES_ETAPES(cod_ville)
			on delete cascade;

--====================================
-- CIRCUITS ref SEJOURS, ref TRANSPORT
--====================================

alter table CIRCUITS
	add constraint	fk_circuits_sejour			foreign key (code_sejour)
		references	SEJOURS(code_sejour)
			on delete cascade;
			
alter table CIRCUITS
	add constraint	fk_circuits_transport		foreign key (type_transport)
		references	TRANSPORT(type_transport)
			on delete cascade;

--====================================
-- ETAPES_SEJOUR ref CIRCUITS, ref VILLES_ETAPES
--====================================

alter table ETAPES_SEJOUR
	add constraint	fk_etapes_sej_sejours		foreign key (code_sejour)
		references	CIRCUITS(code_sejour)
			on delete cascade;

alter table ETAPES_SEJOUR
	add constraint	fk_etapes_sej_ville			foreign key (cod_ville)
		references	VILLES_ETAPES(cod_ville)
			on delete cascade;

--====================================
-- TARIF ref CALENDRIER
--====================================

alter table	TARIF
	add constraint 	fk_tarif_semaine			foreign key (no_sem)
		references	CALENDRIER(no_sem)
			on delete cascade;
			
--====================================
-- DETAIL_RESERV ref RESERVATIONS, ref CALENDRIER
--====================================

alter table DETAIL_RESERV
	add constraint	fk_detail_reserv_semaine	foreign key (no_sem)
		references	CALENDRIER(no_sem)
			on delete cascade;
			
alter table DETAIL_RESERV
	add constraint	fk_detail_reserv_reser		foreign key (code_res)
		references	RESERVATIONS(code_res)
			on delete cascade;

--==============================================================--
-- 					  AUTRES MODIFICATIONS						--	
--==============================================================--

alter session set nls_date_format = 'DD-MM-YYYY';