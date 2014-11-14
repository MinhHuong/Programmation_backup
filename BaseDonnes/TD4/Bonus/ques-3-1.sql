set serveroutput on;

create or replace trigger trg_annee 
before update on etudiants
for each row
begin
	if updating then
		if (:new.annee_etu - :old.annee_etu > 1) or (:new.annee_etu - :old.annee_etu < 0) then
			raise_application_error(-20101, '1 etudiant ne peut pas sauter de classe ni passer  a une classe inferieure.');
		end if;
	end if;	
end trg_annee;
/