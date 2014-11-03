 SELECT		IA.Nom, IA.Prenom, IR.Nom, IR.Prenom
 FROM		ACTEUR A, FILM F, INDIVIDU IA, INDIVIDU IR
 WHERE		A.NumFilm = F.NumFilm
 AND		A.NumInd = IA.NumInd
 AND		F.Realisateur = IR.NumInd;