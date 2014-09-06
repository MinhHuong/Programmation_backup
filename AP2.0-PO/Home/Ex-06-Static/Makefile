CC = g++
OBJECTS = Compter.o main.o

main : $(OBJECTS)
	$(CC) $(OBJECTS) -o main

main.o : main.cc Compter.h
	$(CC) -c main.cc

Compter.o : Compter.h Compter.cc
	$(CC) -c Compter.cc

clean :
	rm -f *.o *~ main
