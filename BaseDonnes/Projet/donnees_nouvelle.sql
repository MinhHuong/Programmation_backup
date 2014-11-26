--==============================================================--
-- 				   SUPPRIMER TOUTES LES DONNÉES					--	
--==============================================================--

delete from DETAIL_RESERV;

--==============================
-- Reset la séquence (auto_increment le id_detail dans DETAIL_RESERV
--==============================

drop sequence seq_detail;

create sequence seq_detail
	start with 		1
	increment by 	1
	cache			5 ; 

create or replace trigger trg_auto_incre_detail
before insert on DETAIL_RESERV
for each row
begin
	select 	seq_detail.nextVal
	into 	:new.id_detail
	from 	dual;
end trg_auto_incre_detail;
/

delete from RESERVATIONS;

--==============================
-- Reset la séquence (auto_increment le code_res dans RESERVATIONS
--==============================

drop sequence seq_reservation;

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

delete from TARIF;

delete from CALENDRIER;

delete from ETAPES_SEJOUR;

delete from CIRCUITS;

delete from TRANSPORT;

delete from HOTEL_RESIDENCE;

delete from SEJOURS;

delete from HEBERGEMENT;

delete from VILLES_ETAPES;

delete from PAYS;

delete from VALEUR_TEMP;

commit;

--==============================================================--
-- 				   		INSÉRER DES DONNÉES						--	
--==============================================================--

--====================================
-- 1 	PAYS
--====================================

insert into PAYS values ('SEN', 'SENEGAL');
insert into PAYS values ('VNM', 'VIETNAM');

commit;

--====================================
-- 2	VILLES_ETAPES
--====================================

insert into VILLES_ETAPES values (1, 'SEN', 'DAKAR');
insert into VILLES_ETAPES values (2, 'VNM', 'NHA TRANG');
insert into VILLES_ETAPES values (3, 'VNM', 'DA LAT');

commit;

--====================================
-- 3	HEBERGEMENT
--====================================

insert into HEBERGEMENT values (1, 'PENSION COMPLETE'	);
insert into HEBERGEMENT values (2, 'DEMI-PENSION'		);
insert into HEBERGEMENT values (3, 'HEBERGEMENT SEUL'	);

commit;

--====================================
-- 4	SEJOURS
--====================================

insert into SEJOURS values ('SSND07', 
							'CLUB DAKAR SOMONE', 
							'La Somonne, sa baie, ses plages, sa vie locale, sa petite riviere, Parc Ornithologique', 
							12, 11, 
							1,
							3, 0 );
							
insert into SEJOURS values ('NTDL15',
							'MER ET MONTAGNE',
							'Nha Trang - une belle plage et Da Lat, le paysage montagnard romantique',
							8, 7,
							2, 
							5, 0 );

commit;

--====================================
-- 5 	HOTEL_RESIDENCE
--====================================

insert into HOTEL_RESIDENCE values ('SSND07', 1, 'FOUR SEASONS', 4, '151 CUSSET, VICHY', '00 63 81 92 56 78' );

commit;

--====================================
-- 6	TRANSPORT
--====================================

insert into TRANSPORT values (1, 'AUTOCAR'		);
insert into TRANSPORT values (2, 'BATEAU'		);
insert into TRANSPORT values (3, 'VEHICULE 4X4'	);

commit;

--====================================
-- 7	CIRCUITS
--====================================

insert into CIRCUITS values ('NTDL15', 3);

commit;

--====================================
-- 8	ETAPES_SEJOUR
--====================================

insert into ETAPES_SEJOUR values ('NTDL15', 1, 2, 4);
insert into ETAPES_SEJOUR values ('NTDL15', 2, 3, 4);

commit;

--====================================
-- 9	CALENDRIER	
--====================================

insert into CALENDRIER values ('482010', '5-DEC-2010' , '12-DEC-2010');
insert into CALENDRIER values ('492010', '12-DEC-2010', '19-DEC-2010'); 
insert into CALENDRIER values ('502010', '19-DEC-2010', '26-DEC-2010');
insert into CALENDRIER values ('512010', '26-DEC-2010', '2-JAN-2011' );
insert into CALENDRIER values ('522010', '2-JAN-2011' , '9-JAN-2011' );

insert into CALENDRIER values ('012011', '9-JAN-2011' , '16-JAN-2011');
insert into CALENDRIER values ('022011', '16-JAN-2011', '23-JAN-2011');
insert into CALENDRIER values ('032011', '23-JAN-2011', '30-JAN-2011');
insert into CALENDRIER values ('042011', '30-JAN-2011', '6-FEB-2011' );

commit;

--====================================
-- 10 	TARIF
--====================================

insert into TARIF values ('482010', 'SSND07', 699, 10, 25, 150 );
insert into TARIF values ('492010', 'SSND07',  749, 10, 15, 150 );
insert into TARIF values ('502010', 'SSND07', 1149, 15, 26, 179);
insert into TARIF values ('512010', 'SSND07', 1469, 23, 31, 250);
insert into TARIF values ('522010', 'SSND07', 899, 15, 17, 150 );
insert into TARIF values ('012011', 'SSND07', 749, 10, 15, 150 );
insert into TARIF values ('022011', 'SSND07', 729, 10, 12, 130 );
insert into TARIF values ('032011', 'SSND07', 799, 10, 12, 130 );
insert into TARIF values ('042011', 'SSND07', 799, 10, 12, 130 );

insert into TARIF values ('482010', 'NTDL15', 523, 10, 25, 150 );
insert into TARIF values ('492010', 'NTDL15', 125, 10, 15, 150 );
insert into TARIF values ('502010', 'NTDL15', 1250, 15, 26, 179);
insert into TARIF values ('512010', 'NTDL15', 789, 23, 31, 250);
insert into TARIF values ('522010', 'NTDL15', 177, 15, 17, 150 );
insert into TARIF values ('012011', 'NTDL15', 358, 10, 15, 150 );
insert into TARIF values ('022011', 'NTDL15', 594, 10, 12, 130 );
insert into TARIF values ('032011', 'NTDL15', 799, 10, 12, 130 );
insert into TARIF values ('042011', 'NTDL15', 999, 10, 12, 130 );

commit;

--====================================
-- 11	RESERVATIONS
--====================================

--====================================
-- 12	DETAIL_RESERV
--====================================

--==============================================================--
-- 				   	TESTER L'INSERTION DE DONNÉES				--	
--==============================================================--

select 	count(*), '= 2', 'PAYS' 			from PAYS
union
select 	count(*), '= 3', 'VILLES_ETAPES'	from VILLES_ETAPES
union
select 	count(*), '= 3', 'HEBERGEMENT'		from HEBERGEMENT
union
select 	count(*), '= 2', 'SEJOURS'			from SEJOURS	
union
select 	count(*), '= 1', 'HOTEL_RESIDENCE'	from HOTEL_RESIDENCE
union	
select 	count(*), '= 3', 'TRANSPORT'		from TRANSPORT
union
select 	count(*), '= 1', 'CIRCUITS'			from CIRCUITS
union
select 	count(*), '= 2', 'ETAPES_SEJOUR'	from ETAPES_SEJOUR
union
select 	count(*), '= 9', 'CALENDRIER'		from CALENDRIER
union
select 	count(*), '= 18', 'TARIF'			from TARIF
union
select 	count(*), '= 3', 'RESERVATIONS'		from RESERVATIONS
union
select 	count(*), '= 0', 'DETAIL_RESERV'	from DETAIL_RESERV ;





