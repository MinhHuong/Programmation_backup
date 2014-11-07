alter user 	Paul
profile		profile_guichets;

alter user 	Pierre
profile		profile_guichets;

alter user 	Alain
profile		profile_guichets;

alter user 	Dounia
profile		profile_guichets;

alter user 	Meriem
profile		profile_all_users;

alter user 	Guillaume
profile		profile_all_users;

grant	role_guichet
to		Paul;

grant	role_guichet
to		Pierre;

grant	role_guichet
to		Alain;

grant	role_guichet
to		Dounia;

grant	role_directrice
to 		Meriem;

grant 	role_program
to 		Guillaume
with admin option;

