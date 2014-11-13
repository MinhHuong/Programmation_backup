--=====================================
-- DELETE FROM ALL TABLES
--=====================================

delete from TARIFS		;

delete from SEJOURS		;

delete from CALENDRIER	;

delete from PAYS		;

commit;

--=====================================
-- PAYS
--=====================================

insert into PAYS values ('SEN', 'SENEGAL'	);
insert into PAYS values ('ESP', 'ESPAGNE'	);
insert into PAYS values ('FRA', 'FRANCE' 	);
insert into PAYS values ('CPV', 'CAP-VERT'	);

commit;

--=====================================
-- SEJOURS
--=====================================

insert into SEJOURS values ('SSND07', 'SEN', 'CLUB DAKAR SOMONE'		, 'La Somonne, sa baie, ses plages, sa vie locale, sa petite riviere, Parc Ornithologique');
insert into SEJOURS values ('SSPM08', 'ESP', 'SOLEIL DE L''ANDALOUSIE'	, 'L''hotel se trouve dans un quartier residentiel, en bord de mer');
insert into SEJOURS values ('SLMH09', 'FRA', 'VAL LOURON'				, 'Au coeurs des hautes-Pyrenees, 22km de pistes tous niveaux, club enfants');
insert into SEJOURS values ('SMTH06', 'CPV', 'MER ET DESERT'			, 'Sejour de luxe, infrastructure ideale, construit en front de mer, vacances de repos');

commit;

--=====================================
-- CALENDRIER
--=====================================

insert into CALENDRIER values ('482010', '5-DEC-2010' , '12-DEC-2010');
insert into CALENDRIER values ('492010', '12-DEC-2010', '19-DEC-2010'); 
insert into CALENDRIER values ('502010', '19-DEC-2010', '26-DEC-2010');
insert into CALENDRIER values ('512010', '26-DEC-2010', '2-JAN-2011' );
insert into CALENDRIER values ('522010', '2-JAN-2011' , '9-JAN-2011' );

insert into CALENDRIER values ('012011', '9-JAN-2011' , '16-JAN-2011');
insert into CALENDRIER values ('022011', '16-JAN-2011', '23-JAN-2011');
insert into CALENDRIER values ('032011', '23-JAN-2011', '30-JAN-2011');
insert into CALENDRIER values ('042011', '30-JAN-2011', '6-FEB-2011' );

insert into CALENDRIER values ('132011', '3-APR-2011' , '10-APR-2011');
insert into CALENDRIER values ('142011', '10-APR-2011', '17-APR-2011');
insert into CALENDRIER values ('152011', '17-APR-2011', '24-APR-2011');
insert into CALENDRIER values ('162011', '24-APR-2011', '1-MAY-2011' );

insert into CALENDRIER values ('272011', '10-JUL-2011', '17-JUL-2011');
insert into CALENDRIER values ('282011', '17-JUL-2011', '24-JUL-2011');
insert into CALENDRIER values ('292011', '24-JUL-2011', '31-JUL-2011');

insert into CALENDRIER values ('302011', '31-JUL-2011', '7-AUG-2011' );
insert into CALENDRIER values ('312011', '7-AUG-2011' , '14-AUG-2011');
insert into CALENDRIER values ('322011', '14-AUG-2011', '21-AUG-2011');

commit;

--=====================================
-- TARIF
--=====================================

insert into TARIFS values ('SSND07', '482010', 699 );
insert into TARIFS values ('SSND07', '492010', 749 );
insert into TARIFS values ('SSND07', '502010', 1149);
insert into TARIFS values ('SSND07', '512010', 1469);
insert into TARIFS values ('SSND07', '522010', 899 );
insert into TARIFS values ('SSND07', '012011', 749 );
insert into TARIFS values ('SSND07', '022011', 729 );
insert into TARIFS values ('SSND07', '032011', 799 );
insert into TARIFS values ('SSND07', '042011', 799 );

insert into TARIFS values ('SSPM08', '482010', 299 );
insert into TARIFS values ('SSPM08', '492010', 299 );
insert into TARIFS values ('SSPM08', '502010', 578 );
insert into TARIFS values ('SSPM08', '512010', 626 );
insert into TARIFS values ('SSPM08', '522010', 299 );
insert into TARIFS values ('SSPM08', '012011', 299 );
insert into TARIFS values ('SSPM08', '022011', 299 );
insert into TARIFS values ('SSPM08', '032011', 299 );
insert into TARIFS values ('SSPM08', '042011', 299 );
insert into TARIFS values ('SSPM08', '132011', 585 );
insert into TARIFS values ('SSPM08', '142011', 655 );
insert into TARIFS values ('SSPM08', '152011', 478 );
insert into TARIFS values ('SSPM08', '162011', 399 );
insert into TARIFS values ('SSPM08', '272011', 895 );
insert into TARIFS values ('SSPM08', '282011', 741 );
insert into TARIFS values ('SSPM08', '292011', 355 );
insert into TARIFS values ('SSPM08', '302011', 499 );
insert into TARIFS values ('SSPM08', '312011', 1598 );
insert into TARIFS values ('SSPM08', '322011', 1500 );

insert into TARIFS values ('SLMH09', '492010', 540 );
insert into TARIFS values ('SLMH09', '502010', 490 );
insert into TARIFS values ('SLMH09', '512010', 465 );
insert into TARIFS values ('SLMH09', '522010', 505 );
insert into TARIFS values ('SLMH09', '012011', 560 );
insert into TARIFS values ('SLMH09', '022011', 610 );

insert into TARIFS values ('SMTH06', '032011', 2369);
insert into TARIFS values ('SMTH06', '042011', 2589);
insert into TARIFS values ('SMTH06', '132011', 1399);
insert into TARIFS values ('SMTH06', '142011', 1159);
insert into TARIFS values ('SMTH06', '152011', 1519);
insert into TARIFS values ('SMTH06', '162011', 1199);

commit;

--=====================================
-- VERIFICATION DES DONNEES
--=====================================

select	count(*), '= 4 ?', 'PAYS' 			from PAYS
union
select	count(*), '= 4 ?', 'SEJOURS' 		from SEJOURS
union
select	count(*), '= 19 ?', 'CALENDRIER' 	from CALENDRIER
union
select	count(*), '= 40 ?', 'TARIF'			from TARIFS ;
