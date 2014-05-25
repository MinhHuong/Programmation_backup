CC=g++
OBJECTS=Point.o Polygone.o main.o

main:$(OBJECTS)
	$(CC) $(OBJECTS) -o main

Point.o:Point.cc Point.h
	$(CC) -c Point.cc

Polygone.o:Polygone.cc Polygone.h
	$(CC) -c -std=c++11 Polygone.cc

main.o:main.cc Polygone.h
	$(CC) -c main.cc

clean:
	rm -f *~ *.o main
