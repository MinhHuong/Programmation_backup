set serveroutput on;

declare
    cursor c is
           select nom,count(*) as nombre
           from individu i,film f
           where i.numind = f.realisateur
           group by(nom);
begin
    for l in c
    loop
        dbms_output.put_line(l.nom||' : '||l.nombre);
    end loop;
end;
/