CC=g++
OBJECTS=Gerant.o Employe.o main.o

main:$(OBJECTS)
	$(CC) $(OBJECTS) -o main

main.o:main.cc Gerant.h
	$(CC) -c main.cc

Gerant.o:Gerant.cc Gerant.h
	$(CC) -c Gerant.cc

Employe.o:Employe.h Employe.cc
	$(CC) -c Employe.cc

clean:
	rm -f *~ *.o main
