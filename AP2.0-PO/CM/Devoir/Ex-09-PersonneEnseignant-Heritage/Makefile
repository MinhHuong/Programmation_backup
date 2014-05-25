CC=g++
OBJECTS=Personne.o Enseignant.o main.o

main:$(OBJECTS)
	$(CC) $(OBJECTS) -o main

Personne.o:Personne.cc Personne.h
	$(CC) -c Personne.cc

Enseignant.o:Enseignant.cc Enseignant.h
	$(CC) -c Enseignant.cc

main.o:main.cc Enseignant.h
	$(CC) -c main.cc

clean:
	rm -f *~ *.o main
