set serveroutput on;

declare
	cursor	cs_nbFilms	is
		select		nom_acteur, prenom_acteur, count(*) as nb
		from		acteur a, role r
		where		a.numero_acteur = r.numero_acteur
		group by	nom_acteur, prenom_acteur;
begin
	for l in cs_nbFilms
	loop
		dbms_output.put_line(l.prenom_acteur || l.nom_acteur || ' a joue dans ' || l.nb || ' film(s)');
	end loop;
end;
/