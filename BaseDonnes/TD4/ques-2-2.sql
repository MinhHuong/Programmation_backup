set serveroutput on;

declare
	nb	number;
begin
	select 	count(*) into nb
	from	reservation;
	dbms_output.put_line('Nombre total de reservations : ' || nb);
end;
/