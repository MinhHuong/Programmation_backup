-- faire passer les étudiants ayant plus de 11 de moyenne, supprimer tous les étudiants 
-- ayant moins de 8 de moyenne / n'ayant aucune note

create or replace procedure passerEtudiant as
	moyenne	number;
	cursor cs_etu is
		select	num_etu, annee_etu
		from	etudiants;
begin
	for l in cs_etu
	loop
		moyenne := calculerMoyenne(l.num_etu);
		
		if moyenne > 11 then
			update etudiants set annee_etu = annee_etu + 1 where num_etu = l.num_etu;
		elsif moyenne < 8 or moyenne = 0 then
			delete from etudiants where num_etu = l.num_etu;
		end if;
		
	end loop;
end;
/