drop role	role_guichet cascade;
drop role 	role_directrice cascade;
drop role 	role_program cascade;

create role	role_guichet;
create role role_directrice;
create role role_program;	

grant connect to role_guichet;
grant create session to role_guichet;

grant connect to role_directrice;
grant create session to role_guichet;

grant connect to role_program;
grant create session to role_guichet;

grant select on acteur 			 to role_guichet;
grant select on realisateur 	 to role_guichet;
grant select on film 			 to role_guichet;
grant select on role 			 to role_guichet;
grant select on seance 			 to role_guichet;
grant select on categorie_seance to role_guichet;
grant select on place 			 to role_guichet;
grant select on categorie_place  to role_guichet;
grant all	 on reservation 	 to role_guichet;
grant select on tarif 			 to role_guichet;

grant all 	 on film 	to role_directrice;
grant all 	 on tarif 	to role_directrice;

grant all	 on seance 	to role_program;
grant all 	 on place	to role_program;





