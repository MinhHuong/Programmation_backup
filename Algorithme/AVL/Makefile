CC = g++
OBJECTS = avl.o main.o

main: $(OBJECTS)
	$(CC) $(OBJECTS) -o main

avl.o: avl.h avl.cpp
	$(CC) -c avl.cpp

main.o: main.cpp avl.h
	$(CC) -c main.cpp

clean:
	rm -fr *~ *.o main; clear;
