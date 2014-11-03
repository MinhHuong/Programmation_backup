SELECT 		G.Libelle, COUNT(*)
FROM		FILM_GENRE FG, GENRE G, FILM F
WHERE		FG.Codegenre = G.CodeGenre
AND			FG.NumFilm = F.NumFilm
GROUP BY	G.Libelle;                                       