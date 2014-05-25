CC=g++
OBJECTS=main.o Employe.o Vendeur.o Bureau.o

main:$(OBJECTS)
	$(CC) $(OBJECTS) -o main

Employe.o:Employe.h Employe.cc
	$(CC) -c Employe.cc

Vendeur.o:Vendeur.h Vendeur.cc
	$(CC) -c Vendeur.cc

Bureau.o:Bureau.h Bureau.cc
	$(CC) -c Bureau.cc

clean:
	rm -f *~ *.o main
