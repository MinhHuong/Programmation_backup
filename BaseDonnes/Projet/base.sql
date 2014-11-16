--=====================================
-- DROP ALL TABLES
--=====================================

drop table	TARIFS;

drop table	CALENDRIER;

drop table	SEJOURS;

drop table	PAYS;

--=====================================
-- PAYS 
--=====================================

create table PAYS (
	cod_pays					char(3)							,
	nom_pays					char(20)						,
	constraint	pk_pays			primary key (cod_pays)
);

--=====================================
-- SEJOURS
--=====================================

create table SEJOURS (
	code_sejour					char(10)						,
	cod_pays					char(3)			not null		,
	nom_sejour					varchar(25)		not null		,
	description_sejour			varchar(100)					,
	constraint	pk_sejours		primary key (code_sejour)
);
	
--=====================================
-- CALENDRIER
--=====================================

create table CALENDRIER (
	no_sem						char(6)							,
	date_deb					date			not null		,
	date_fin					date			not null		,
	constraint	pk_calendrier	primary key (no_sem)
);

--=====================================
-- TARIF
--=====================================

create table TARIFS (
	code_sejour					char(10)							,
	no_sem						char(6)								,
	prix_ttc					number(7,2)			not null		,
	constraint	pk_tarif		primary key (code_sejour, no_sem)
);

--=====================================
-- DES CLES EXTERNES 
--=====================================

alter table SEJOURS
	add constraint	fk_sejours				foreign key (cod_pays)
		references	PAYS (cod_pays)
			on delete cascade ;
		
alter table TARIFS
	add constraint	fk_tarifs_sejour 		foreign key (code_sejour)
		references	SEJOURS (code_sejour)
			on delete cascade ;

alter table TARIFS	
	add constraint	fk_tarifs_calendrier	foreign key (no_sem)
		references	CALENDRIER (no_sem)
			on delete cascade ;
			
alter session set nls_date_format = 'DD-MON-YYYY';