--fonction qui calcule la moyenne d'1 étudiant ( exception : si l'eleve n'a aucune note )

create or replace function calculerMoyenne (n_etu number) return number as
	e		exception;
	nb 		number;
	res		number(4,2);
	somme	number;
	nb_coef	number;
	cursor cs_moyenne is
		select	note, coeff_mat
		from	etudiants e, matieres m, notes n
		where	e.num_etu = n.num_etu
		and		n.code_mat = m.code_mat
		and		e.num_etu = n_etu;
begin	
	select	count(*) into nb
	from	etudiants e, notes n
	where	e.num_etu = n.num_etu
	and		e.num_etu = n_etu;
	
	if nb = 0  then raise e;
	else
		somme:=0;
		nb_coef:=0;
		for l in cs_moyenne
		loop
			somme := somme + l.note*l.coeff_mat ;
			nb_coef := nb_coef + l.coeff_mat ;
		end loop;
		res:=somme/nb_coef;
		return res;
	end if;
exception
	when e then
		return 0;
end	calculerMoyenne;
/
	