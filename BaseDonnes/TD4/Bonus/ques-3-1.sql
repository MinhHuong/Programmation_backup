set serveroutput on;

create or replace trigger trg_annee 
after update on etudiants
for each row
begin
	if updating then
		if (:new.annee_etu - :old.annee_etu > 1) then
			raise_application_error(-20101, 'Erreur');
		end if;
	end if;	
end trg_annee;
/