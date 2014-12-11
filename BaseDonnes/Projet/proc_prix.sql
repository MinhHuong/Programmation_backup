set serveroutput on;

create or replace procedure complete_prix (sem char, res number) as
	total		number(8,2);
	prix_adult 	number(7,2);
	prix_enf	number(7,2);
begin
	select	temp_mont_reserv 	into total 		from valeur_temp where rownum = 1;
	select	temp_prix_ttc_adult	into prix_adult	from valeur_temp where rownum = 1;
	select	temp_prix_ttc_enf	into prix_enf	from valeur_temp where rownum = 1;
		
	update	reservations
	set 	mont_reserv = mont_reserv + total
	where	code_res = res;
	
	update	detail_reserv
	set		prix_ttc_adult = prix_adult, prix_ttc_enf = prix_enf
	where	code_res = res
	and		no_sem = sem ;
	
	delete from valeur_temp;
	
	dbms_output.put_line('	');
	dbms_output.put_line('Puis, (si pas deja fait) il convient a mettre a jour ces 2 informations dans RESERVATION : somme versee, date de versement');
end complete_prix;
/

create or replace procedure change_prix (sem char, res number) as
	total		number(8,2);
	prix_adult 	number(7,2);
	prix_enf	number(7,2);
begin
	select	temp_mont_reserv 	into total 		from valeur_temp where rownum = 1;
	select	temp_prix_ttc_adult	into prix_adult	from valeur_temp where rownum = 1;
	select	temp_prix_ttc_enf	into prix_enf	from valeur_temp where rownum = 1;
	
	update	detail_reserv
	set		prix_ttc_adult = prix_adult, prix_ttc_enf = prix_enf
	where	code_res = res
	and		no_sem = sem ;	
	
	update	reservations
	set 	mont_reserv = total
	where	code_res = res;
	
	delete from valeur_temp;
end change_prix;
/