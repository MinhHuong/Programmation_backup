SELECT	DISTINCT Nom, Prenom
FROM	INDIVIDU I, ACTEUR A, FILM F
WHERE	I.NumInd = A.NumInd
AND		F.Realisateur = A.NumInd
AND		A.NumFilm = F.NumFilm;