CC=g++ -g
OBJECTS=Employe.o main.o Siege.o Date.o Compagnie.o

main:$(OBJECTS)
	$(CC) $(OBJECTS) -o main

main.o:main.cc Employe.h
	$(CC) -c main.cc

Employe.o:Employe.cc Employe.h
	$(CC) -c Employe.cc

Siege.o:Siege.cc Siege.h
	$(CC) -c Siege.cc

Date.o:Date.cc Date.h
	$(CC) -c Date.cc

Compagnie.o:Compagnie.cc Compagnie.h
	$(CC) -c Compagnie.cc

clean:
	rm -f *~ *.o main
