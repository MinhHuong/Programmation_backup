set serveroutput on;

declare
	cursor cs_realAme is
		select	nom_acteur, prenom_acteur, date_de_naissance
		from	acteur
		where	nation_acteur = 'AMERICAINE';
begin
	for l in cs_realAme
	loop
		dbms_output.put_line('Acteur : ' || l.prenom_acteur || ' ' || l.nom_acteur || ', ne(e) le ' || l.date_de_naissance);
	end loop;
end;
/
		