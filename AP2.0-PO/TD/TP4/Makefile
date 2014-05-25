CC=g++ -Wall
OBJECTS=util.o Date.o Oeuvre.o Plastique.o Peinture.o Sculpture.o Ecrite.o Livre.o Gestion.o main.o 

art : $(OBJECTS)
	$(CC) $(OBJECTS) -o art

util.o : util.cc util.h
	$(CC) -c util.cc

Date.o : Date.cc Date.h util.h
	$(CC) -c Date.cc

Oeuvre.o : Oeuvre.cc Oeuvre.h util.h
	$(CC) -c Oeuvre.cc

Plastique.o : Plastique.cc Plastique.h Oeuvre.h util.h
	$(CC) -c Plastique.cc

Peinture.o : Peinture.h Peinture.cc Plastique.h util.h
	$(CC) -c Peinture.cc

Sculpture.o : Sculpture.h Sculpture.cc Plastique.h util.h
	$(CC) -c Sculpture.cc

Ecrite.o : Ecrite.h Ecrite.cc Oeuvre.h util.h
	$(CC) -c Ecrite.cc

Livre.o : Livre.h Livre.cc Ecrite.h util.h
	$(CC) -c Livre.cc

Gestion.o : Gestion.h Gestion.cc Oeuvre.h util.h
	$(CC) -c Gestion.cc

main.o : main.cc Plastique.h Oeuvre.h util.h
	$(CC) -c main.cc

clean :
	rm -f *.o *~ art

