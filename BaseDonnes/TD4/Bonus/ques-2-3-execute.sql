set serveroutput on;

accept numero_etu number prompt 'Entrez le numero de l''etudiant : ';

declare
	moyen	number;
begin
	moyen:=calculerMoyenne(&numero_etu);
	dbms_output.put_line('La moyenne de cet etudiant : ' || moyen);
end;
/