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
-- Calculer automatiquement le montant total d'une réservation
--==============================================================

create or replace trigger trg_montant_total
after insert on detail_reserv
for each row 
declare
	total			number(8,2);
	prix_ttc_sem	number(7,2);
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
	select	nb_adults 	into nb_adu 	from reservations 	where code_res = :new.code_res;
	select 	nb_enf 		into nb_e		from reservations	where code_res = :new.code_res;
	select	nb_seule	into nb_s		from reservations	where code_res = :new.code_res;
	
	select 	prix_ttc into prix_ttc_sem
	from	tarif t, calendrier c
	where	t.no_sem = c.no_sem
	and		c.no_sem = :new.no_sem
	and		t.code_sejour = :new.code_sejour;
	
	select 	suppl_ch_seule into prix_seule	
	from 	tarif t, calendrier c
	where	t.no_sem = c.no_sem
	and		c.no_sem = :new.no_sem
	and		t.code_sejour = :new.code_sejour;
	
	select 	reduc_enf into red_enf
	from 	tarif t, calendrier c
	where	t.no_sem = c.no_sem
	and		c.no_sem = :new.no_sem
	and		t.code_sejour = :new.code_sejour;
	
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
	where	no_sem = sem_ayant_reduc
	and		code_sejour = :new.code_sejour;

	prix_adult := prix_ttc_sem * nb_adu;
	prix_enf := prix_ttc_sem * nb_e * ( 1 - red_enf/100 );
	total := func_total_montant(prix_ttc_sem, nb_adu, red_enf, nb_e, prix_seule, nb_s, 0);
	
	dbms_output.put_line('Total montant = '|| total || ', dont le prix d''adultes = ' || prix_adult || ' et le prix d''enfants = ' || prix_enf);
	
	insert into valeur_temp values ( total, prix_adult, prix_enf );
	
	dbms_output.put_line('	');
	dbms_output.put_line('Ensuite, veuillez executer la procedure complete_prix(no_sem, code_res) pour completer ces 3 nouveau montants (total, adult, enfant) !');
	
end trg_montant_total;
/

--==============================================================
-- Recalculer automatiquement le montant total d'une réservation
-- apres une mise a jour ( prix TTC, nombre d'adultes... )
--==============================================================

create or replace trigger trg_maj_tarif_montant
after update on tarif
for each row
declare
	prix_adult	number(7,2);
	prix_enf	number(7,2);
	total 		number(8,2);
	cursor cs_nb is
		select 	nb_adults, nb_enf, nb_seule
		from	reservations r, detail_reserv dr
		where	r.code_res = dr.code_res
		and		dr.no_sem = :new.no_sem;
begin
	for l in cs_nb
	loop
		prix_adult := :new.prix_ttc * l.nb_adults;
		prix_enf   := :new.prix_ttc * l.nb_enf * ( 1 - :new.reduc_enf/100 );
	
		total := func_total_montant(:new.prix_ttc, l.nb_adults, :new.reduc_enf, l.nb_enf, :new.suppl_ch_seule, l.nb_seule, :new.prix_sem_sup);
	end loop;
	
	delete from valeur_temp;
	insert into valeur_temp values (total, prix_adult, prix_enf);
	
	dbms_output.put_line('	');
	dbms_output.put_line('Ensuite, il vous faut executer la fonction change_prix(no_sem, code_res) pour changer les prix dans des tables convenantes');
end trg_maj_tarif_montant;
/

--==============================================================
--Tester la validité d'une nouvelle réservation
--( date de réservation )
--sinon non valide, empêche l'utilisateur à en insérer
--==============================================================

create or replace trigger trg_valide_reserv
before insert on detail_reserv
for each row
declare
	date_de_debut		date;
	date_reservation	date;
begin
	dbms_output.put_line(:new.no_sem);
	dbms_output.put_line(:new.code_res);
	select 	date_debut 	into date_de_debut
	from	calendrier
	where	no_sem = :new.no_sem;
	
	select 	date_reserv into date_reservation
	from	reservations
	where	code_res = :new.code_res;
	
	if ( date_reservation >= date_de_debut ) then 
		dbms_output.put_line('Date de debut du sejour : ' || date_de_debut);
		dbms_output.put_line('Date de reservation : ' || date_reservation);
		raise_application_error(-20102, 'Une reservation doit etre effectuee avant la date de debut du sejour !');
	end if;
	
end trg_valide_reserv;
/

--==============================================================
-- Tester la validité du payement à une réservation 
-- ( date_vers )
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
	date_reservation := :new.date_reserv;
	
	select	date_debut	into date_de_debut
	from 	calendrier c, detail_reserv dr
	where	dr.code_res = 1
	and		c.no_sem = dr.no_sem
	and 	id_detail = 
	( select max(id_detail) from detail_reserv );
	
	if ( date_versement >= date_de_debut ) then
		raise_application_error(-20103, 'Il faut verser une partie du montant total avant la date de debut du sejour !');
	end if ;
	
	if( date_versement < date_reservation ) then
		raise_application_error(-20104, 'Invalide : la date de versement doit avoir lieu en meme temps ou apres la date de reservation !');
	end if;

	somme_vers := :new.somme_versee;
	total := :new.mont_reserv;
	
	if ( :old.mont_reserv != :new.mont_reserv ) then
		if ( somme_vers > :new.mont_reserv ) then
			dbms_output.put_line('Montant = ' || total || ', Somme versee = ' || somme_vers);
			dbms_output.put_line('Somme versee > Montant total');
		end if;
	end if;
	
	if ( total != 0 ) and ( :old.somme_versee != 0 ) then
		if ( somme_vers < total/2 ) then
			dbms_output.put_line('Montant = ' || total || '	, Somme versee = ' || somme_vers);
			raise_application_error(-20105, 'Il faut verser une moitie du montant pour effectuer une reservation valide !');
		end if;
	end if;
	
	if ( total = 0 ) then
		raise_application_error(-20109, 'Veuillez execute la procedure complete_prix(no_sem, code_res) pour avoit le montant total.');
	end if;
end trg_valide_versement;
/
