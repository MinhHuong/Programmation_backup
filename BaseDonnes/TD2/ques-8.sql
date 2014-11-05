ACCEPT nr NUMBER PROMPT 'Entrez le numero du realisateur choisi : '

column	numero_realisateur heading 'Numero|realisateur' justify center
column	prenom_realisateur heading 'Prenom du|realisateur' justify center
column	nation_realisateur heading 'Nationalite' justify center

SELECT * FROM REALISATEUR WHERE NUMERO_REALISATEUR = &nr;

--a partir d'un nombre saisi par l'utilisateur, le programme choisit un realisateur dont le numero y convient