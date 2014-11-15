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
							3, 0 );
							
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

--====================================
-- 10 	TARIF
--====================================

--====================================
-- 11	RESERVATIONS
--====================================

--====================================
-- 12	DETAIL_RESERV
--====================================








