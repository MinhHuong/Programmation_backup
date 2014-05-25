CC=g++
OBJECTS=main.o Employe.o Gerant.o Secretaire.o

main : $(OBJECTS)
	$(CC) $(OBJECTS) -o main

main.o : Employe.o Gerant.o Secretaire.o
	$(CC) -c main.cc

Employe.o : Employe.h Employe.cc
	$(CC) -c Employe.cc

Gerant.o : Gerant.h Gerant.cc
	$(CC) -c Gerant.cc

Secretaire.o : Secretaire.h Secretaire.cc
	$(CC) -c Secretaire.cc

clean :	
	rm -f *~ *.o main
