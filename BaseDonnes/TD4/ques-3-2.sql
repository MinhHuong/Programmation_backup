create or replace function realNbFilms (nomReal char) return number as
	nb	number;
begin
	select 	count(*) into nb
	from	realisateur re, film f
	where	re.numero_realisateur = f.numero_realisateur
	and		nom_realisateur = nomReal;
	return	nb;
end realNbFilms;
/