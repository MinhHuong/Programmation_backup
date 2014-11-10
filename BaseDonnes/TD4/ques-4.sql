set serveroutput on;

create or replace trigger trg_placeSpec
before insert or update on reservation
for each row
begin
	if :new.numero_place = 1 then
		update place set categorie_de_la_place = 'S' where numero_place = 1;
		dbms_output.put_line('Trigger called');
	end if;	
end trg_placeSpec;
/