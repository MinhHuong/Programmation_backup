set serveroutput on;

accept nom char prompt 'Entrer le prenom du realisateur (en majuscule) : ';

declare
	nbFilms	number;
begin
	nbFilms:=realNbFilms('&nom');
	dbms_output.put_line('&nom a realise ' || nbFilms || ' film(s)');
end;
/