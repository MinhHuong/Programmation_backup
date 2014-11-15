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

--====================================
-- 2	VILLES_ETAPES
--====================================

--====================================
-- 3	HEBERGEMENT
--====================================

--====================================
-- 4	SEJOURS
--====================================

--====================================
-- 5 	HOTEL_RESIDENCE
--====================================

--====================================
-- 6	TRANSPORT
--====================================

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








