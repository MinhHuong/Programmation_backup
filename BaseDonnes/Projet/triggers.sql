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
	
--==============================================================
-- Calculer le montant total d'une réservation et 
-- automatiquement l'insérer dans la table RESERVATIONS
--==============================================================

create or replace trigger trg_montant_total
after insert on detail_reserv
for each row 
declare
	total			number(8,2);
	
	prix_adult		number(7,2);
	nb_adu			number(3);
	
	prix_enf		number(7,2);
	nb_e			number(3);
	
	prix_seule		number(7,2);
	nb_s			number(3);
	
	red_enf			number(2);
	red_sem			number(7,2);
	
	date_reelle_fin	date;
	sem_ayant_reduc char(6);
begin
	prix_adult 	:= :new.prix_ttc_adult;
	prix_enf 	:= :new.prix_ttc_enf;
	
	select	nb_adults 	into nb_adu 	from reservations 	where code_res = :new.code_res;
	select 	nb_enf 		into nb_e		from reservations	where code_res = :new.code_res;
	select	nb_seule	into nb_s		from reservations	where code_res = :new.code_res;
	select 	mont_reserv into total		from reservations 	where code_res = :new.code_res;
	
	select 	suppl_ch_seule into prix_seule	
	from 	tarif t, calendrier c
	where	t.no_sem = c.no_sem
	and		c.no_sem = :new.no_sem;
	
	select 	reduc_enf into red_enf
	from 	tarif t, calendrier c
	where	t.no_sem = c.no_sem
	and		c.no_sem = :new.no_sem;
	
	select	(date_debut + nb_jours) into date_reelle_fin
	from	calendrier c, sejours s
	where	c.no_sem = :new.no_sem
	and		s.code_sejour = :new.code_sejour;
	
	select	no_sem into sem_ayant_reduc
	from	calendrier
	where	date_debut <= date_reelle_fin
	and		date_reelle_fin <= date_fin;
	
	select	prix_sem_sup into red_sem
	from	tarif
	where	no_sem = sem_ayant_reduc;
	
	total := (    prix_adult * nb_adu 
				+ prix_enf * nb_e 
				+ prix_seule * nb_s 
				- red_sem ) * ( 1 - red_enf/100 );
	
	dbms_output.put_line('Total montant = '|| total);
	
	update reservations set mont_reserv = total where code_res = :new.code_res;
end trg_montant_total;
/

--==============================================================
-- Tester la validité d'une nouvelle réservation
-- ( date de réservation )
-- sinon non valide, empêche l'utilisateur à en insérer
--==============================================================

create or replace trigger trg_valide_reserv
before insert on detail_reserv
for each row
declare
	date_de_debut		date;
	date_reservation	date;
begin
	select 	date_debut 	into date_de_debut
	from	calendrier
	where	no_sem = :new.no_sem;
	
	select 	date_reserv into date_reservation
	from	reservations r, calendrier c
	where	r.code_res = :new.code_res
	and		c.no_sem = :new.no_sem;
	
	if ( date_reservation >= date_de_debut ) then 
		raise_application_error(-20102, 'Une reservation doit etre effectuee avant la date de debut du sejour !');
	end if;
	
end trg_valide_reserv;
/

--==============================================================
-- Tester la validité du payement à une réservation 
-- ( somme_versee, date_vers )
-- sinon non valide, empêche l'utilisateur à mettre à jour
--==============================================================

create or replace trigger trg_valide_versement
before update on reservations
for each row
declare
	date_versement		date;
	somme_vers	 		number(7,2);
	total 				number(8,2);
	date_de_debut		date;
	date_reservation	date;
begin
	date_versement := :new.date_vers;
	somme_vers := :new.somme_versee;
	total := :new.mont_reserv;
	date_reservation := :new.date_reserv;
	
	select	date_debut	into date_de_debut
	from 	calendrier c, detail_reserv dr
	where	dr.code_res = :new.code_res
	and		c.no_sem = dr.no_sem;
	
	if ( date_versement >= date_de_debut ) then
		raise_application_error(-20103, 'Il faut verser une partie du montant total avant la date de debut du sejour !');
	end if ;
	
	if( date_versement < date_reservation ) then
		raise_application_error(-20104, 'Invalide : la date de versement doit avoir lieu en meme temps ou apres la date de reservation !');
	end if;
	
	if ( somme_vers < total/2 ) then
		raise_application_error(-20105, 'Il faut verser une moitie du montant pour effectuer une reservation valide !');
	end if;
end trg_valide_versement;
/










