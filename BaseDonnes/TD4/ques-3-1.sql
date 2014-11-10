set serveroutput on;

create or replace procedure realListeFilms (nomReal char) as
	cursor cs_listeF is
		select	titre_film, date_de_sortie, duree, genre
		from	film f, realisateur re
		where	f.numero_realisateur = re.numero_realisateur
		and		nom_realisateur = nomReal;
begin
	dbms_output.put_line('La liste de films que ' || nomReal || ' a realises : ');
	dbms_output.put_line('--------------------------------');
	for l in cs_listeF
	loop	
		dbms_output.put_line('Titre:   ' || l.titre_film);
		dbms_output.put_line('Sortie:  ' || l.date_de_sortie);
		dbms_output.put_line('Duree:   ' || l.duree);
		dbms_output.put_line('Genre:   ' || l.genre);
		dbms_output.put_line('--------------------------------');
	end loop;
end realListeFilms;
/