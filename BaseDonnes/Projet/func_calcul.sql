set serveroutput on;

create or replace function func_total_montant(prix_per_sem number, nb_adult number, reduc_enfant number, nb_enfant number, prix_per_seule number, nb_seule number, reduc_semaine number) 
return number is
	total	number(8,2);
begin
	total :=  (	  prix_per_sem * nb_adult 
				+ prix_per_sem * nb_enfant * ( 1 - reduc_enfant/100 )
				+ prix_per_seule * nb_seule 
				- reduc_semaine );
	return total;
end func_total_montant;
/