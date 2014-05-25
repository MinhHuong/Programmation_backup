CC=g++
OBJECTS=Siege.o main.o Employe.o Compagnie.o

main:$(OBJECTS)
	$(CC) $(OBJECTS) -o main

Siege.o:Siege.cc Siege.h
	$(CC) -c Siege.cc

main.o:main.cc Siege.h
	$(CC) -c main.cc

Employe.o:Employe.cc Employe.h
	$(CC) -c Employe.cc

Compagnie.o:Compagnie.h Compagnie.cc
	$(CC) -c Compagnie.cc

clean:
	rm -f *~ *.o main
