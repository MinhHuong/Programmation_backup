CC=g++
OBJECTS=Piece.o Roi.o Dame.o Tour.o Cavalier.o Fou.o Pion.o Joueur.o JoueurBlanc.o JoueurNoir.o Echiquier.o main.o util.o
PIECES=Roi.h Dame.h Tour.h Cavalier.h Fou.h Pion.h

main: $(OBJECTS)
	$(CC) $(OBJECTS) -o main

Piece.o: Piece.cpp Piece.h Echiquier.h
	$(CC) -c Piece.cpp

Roi.o: Roi.cpp Roi.h Piece.h
	$(CC) -c Roi.cpp

Dame.o: Dame.cpp Dame.h Piece.h
	$(CC) -c Dame.cpp

Tour.o: Tour.cpp Tour.h Piece.h
	$(CC) -c Tour.cpp

Cavalier.o: Cavalier.cpp Cavalier.h Piece.h
	$(CC) -c Cavalier.cpp

Fou.o: Fou.cpp Fou.h Piece.h
	$(CC) -c Fou.cpp

Pion.o: Pion.cpp Pion.h Piece.h Echiquier.h Dame.h
	$(CC) -c Pion.cpp

Joueur.o : Joueur.cpp Joueur.h Piece.h Echiquier.h
	$(CC) -c Joueur.cpp

JoueurNoir.o: JoueurNoir.cpp JoueurNoir.h Joueur.h $(PIECES)
	$(CC) -c JoueurNoir.cpp

JoueurBlanc.o: JoueurBlanc.cpp JoueurBlanc.h Joueur.h $(PIECES)
	$(CC) -c JoueurBlanc.cpp

Echiquier.o: Echiquier.cpp Echiquier.h Piece.h
	$(CC) -c Echiquier.cpp

main.o: main.cpp $(PIECES) Piece.h Joueur.h JoueurBlanc.h JoueurNoir.h Echiquier.h
	$(CC) -c main.cpp

util.o : util.cpp util.h Piece.h Echiquier.h Roi.h
	$(CC) -c util.cpp

clean:
	rm -fr *~ *.o main
