create or replace trigger trg_conserver
after delete on etudiants
for each row
begin
	if deleting then
		insert into etud_old values (:old.num_etu, :old.nom_etu, :old.prenom_etu, TO_DATE(SYSDATE, 'DD-MM-YY'));
	end if;
end trg_conserver;
/