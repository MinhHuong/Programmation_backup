SELECT	Titre, Nom, Prenom
FROM	FILM F, INDIVIDU I
WHERE	F.Realisateur = I.NumInd;