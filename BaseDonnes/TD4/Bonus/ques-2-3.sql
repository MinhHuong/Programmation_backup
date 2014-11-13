--fonction qui calcule la moyenne d'1 étudiant ( exception : si l'eleve n'a aucune note )

create or replace function calculerMoyenne (n_etu number) return number as
	e	exception;
	nb 	number;
	res	number;
begin
	select 	count(*) into nb
	from	notes n, etudiants e
	where	n.num_etu = e.num_etu
	and		n.num_etu = n_etu;
	
	if nb = 0 	then raise e;
	else	
		select	avg(note) into res
		from	notes n, etudiants e
		where	n.num_etu = e.num_etu
		and		n.num_etu = n_etu;
	end if;
	return res;
exception
	when e then
		return 0;
end	calculerMoyenne;
/
	