CC = g++
OBJECTS = Entier.o main.o

main : main.o Entier.o
	$(CC) $(OBJECTS) -o main

Entier.o : Entier.h Entier.cc
	$(CC) -c Entier.cc

main.o : main.cc Entier.h
	$(CC) -c main.cc

clean : 
	rm -f -r *.o *~ main
