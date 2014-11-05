--Affichez toutes les informations concernant les acteurs dont le prénom est choisi lors de l'exécution de votre requête

accept nom char prompt 'Entrer le prenom de l''acteur (en majuscule) : '

column numero_acteur heading 'Numero|acteur' justify center
column nom_acteur heading 'Nom|acteur' justify center
column prenom_acteur heading 'Prenom|acteur' justify center
column nation_acteur heading 'Nationalite' justify center
column date_de_naissance heading 'Naissance' justify center

select * from acteur where prenom_acteur in '&nom';