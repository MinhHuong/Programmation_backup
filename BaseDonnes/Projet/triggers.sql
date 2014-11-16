set serveroutput on;

--==============================================================
-- Force l'insertion de la nouvelle reservation 
-- dans DETAIL_RESERV
--==============================================================

create or replace trigger trg_force_detail_reserv
after insert on reservations
for each row
begin
	dbms_output.put_line('Il faut immediatement inserer cette nouvelle reservation dans la table DETAIL_RESERV !');
end trg_force_detail_reserv;
/

--==============================================================
-- Tester s'il reste encore de places pour un sejour
-- Si oui, inserer la nouvelle reservation
-- Si non, afficher un message d'erreur et empeche l'insertion
--==============================================================

create or replace trigger trg_places
before insert on detail_reserv
for each row
declare
	nb_places	number(4);
	nb_occupes	number(4);
begin
	select 	nb_sejours into nb_places
	from	sejours
	where	code_sejour = :new.code_sejour;
	
	select	nb_reserv into nb_occupes
	from	sejours
	where	code_sejour = :new.code_sejour;
	
	if( nb_occupes = nb_places ) then
		raise_application_error(-20101, 'Il n''y a plus de places pour ce sejours');
	end if;
end trg_places;
/

--==============================================================
-- Incrementer le nombre de reservations dans SEJOURS 
-- chaque fois une reservation pour ce sejour est effectue
--==============================================================

create or replace trigger trg_incr_reserv
after insert on detail_reserv
for each row
begin
	update SEJOURS set nb_reserv = nb_reserv + 1 where code_sejour = :new.code_sejour;  
end trg_incr_reserv;
/

--==============================================================
-- Decrementer le nombre de reservations dans SEJOURS 
-- chaque fois une reservation pour ce sejour est supprimee
--==============================================================

create or replace trigger trg_dec_reserv
before delete on detail_reserv
for each row 
begin
		update SEJOURS set nb_reserv = nb_reserv - 1 where code_sejour = :old.code_sejour;
end trg_dec_reserv;
/
	
	
	
	