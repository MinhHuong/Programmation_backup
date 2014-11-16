--==============================================================--
-- 				   SUPPRIMER TOUTES LES DONNÉES					--	
--==============================================================--

delete from DETAIL_RESERV;

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

--==============================================================--
-- 				   		INSÉRER DES DONNÉES						--	
--==============================================================--

--====================================
-- 1 	PAYS
--====================================

insert into PAYS values ('SEN', 'SENEGAL');

--====================================
-- 2	VILLES_ETAPES
--====================================

insert into VILLES_ETAPES values (1, 'SEN', 'DAKAR');

--====================================
-- 3	HEBERGEMENT
--====================================

insert into HEBERGEMENT values (1, 'PENSION COMPLETE'	);
insert into HEBERGEMENT values (2, 'DEMI-PENSION'		);
insert into HEBERGEMENT values (3, 'HEBERGEMENT SEUL'	);

--====================================
-- 4	SEJOURS
--====================================

insert into SEJOURS values ('SSND07', 
							'CLUB DAKAR SOMONE', 
							'La Somonne, sa baie, ses plages, sa vie locale, sa petite riviere, Parc Ornithologique', 
							8, 7, 
							1,
							1, 0 );

--====================================
-- 5 	HOTEL_RESIDENCE
--====================================

insert into HOTEL_RESIDENCE values ('SSND07', 1, 'FOUR SEASONS', 4, '151 CUSSET, VICHY', '00 63 81 92 56 78' );

--====================================
-- 6	TRANSPORT
--====================================

insert into TRANSPORT values (1, 'AUTOCAR'		);
insert into TRANSPORT values (2, 'BATEAU'		);
insert into TRANSPORT values (3, 'VEHICULE 4X4'	);

--====================================
-- 7	CIRCUITS
--====================================

--====================================
-- 8	ETAPES_SEJOUR
--====================================

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

--====================================
-- 11	RESERVATIONS
--====================================

insert into RESERVATIONS values ( 	null, 'LE', 'ELISE', 
									'RUE MINH PHUNG, QUARTIER 10, DISTRICT 11', '00084',
									'HO CHI MINH', '090 8989 361', '24-DEC-2010',
									3, 2, 1, 250, '24-DEC-2010', 0 );
									
insert into RESERVATIONS values (	null, 'HIEU', 'MICHEL',
									'RUE NGUYEN DINH CHIEU, DISTRICT 3', '00084',
									'HO CHI MINH', '098 336 5270', '10-JAN-2011',
									5, 3 , 0, 600, '13-JAN-2011', 0 );

--====================================
-- 12	DETAIL_RESERV
--====================================

--==============================================================--
-- 				   	TESTER L'INSERTION DE DONNÉES				--	
--==============================================================--

select 	count(*), '= 1', 'PAYS' 			from PAYS
union
select 	count(*), '= 1', 'VILLES_ETAPES'	from VILLES_ETAPES
union
select 	count(*), '= 3', 'HEBERGEMENT'		from HEBERGEMENT
union
select 	count(*), '= 1', 'SEJOURS'			from SEJOURS	
union
select 	count(*), '= 1', 'HOTEL_RESIDENCE'	from HOTEL_RESIDENCE
union	
select 	count(*), '= 3', 'TRANSPORT'		from TRANSPORT
union
select 	count(*), '= 0', 'CIRCUITS'			from CIRCUITS
union
select 	count(*), '= 0', 'ETAPES_SEJOUR'	from ETAPES_SEJOUR
union
select 	count(*), '= 9', 'CALENDRIER'		from CALENDRIER
union
select 	count(*), '= 9', 'TARIF'			from TARIF
union
select 	count(*), '= 2', 'RESERVATIONS'		from RESERVATIONS
union
select 	count(*), '= 0', 'DETAIL_RESERV'	from DETAIL_RESERV ;





