CC = g++
OBJECTS = main.o Point.o Vecteur.o Ligne.o Rectangle.o Carre.o

main : $(OBJECTS)
	$(CC) $(OBJECTS) -o main

main.o : main.cc Point.h
	$(CC) -c main.cc

Point.o : Point.cc Point.h
	$(CC) -c Point.cc

Vecteur.o : Vecteur.cc Vecteur.h Point.h
	$(CC) -c Vecteur.cc

Ligne.o : Ligne.cc Ligne.h Point.h
	$(CC) -c Ligne.cc

Rectangle.o : Rectangle.cc Rectangle.h
	$(CC) -c Rectangle.cc

Carre.o : Carre.cc Carre.h Rectangle.h
	$(CC) -c Carre.cc

clean:
	rm -fr *~ *.o main
