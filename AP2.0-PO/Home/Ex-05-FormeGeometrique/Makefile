CC = g++
OBJECTS = main.o Rectangle.o Carre.o

main : $(OBJECTS)
	$(CC) $(OBJECTS) -o main

Rectangle.o : Rectangle.h Rectangle.cc
	$(CC) -c Rectangle.cc

Carre.o : Carre.h Carre.cc Rectangle.h
	$(CC) -c Carre.cc

main.o : main.cc Rectangle.h Carre.h
	$(CC) -c main.cc

clean :
	rm -f *.o *~ main
