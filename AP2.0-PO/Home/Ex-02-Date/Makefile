CC=g++
OBJECTS=main.o Date.o

main:$(OBJECTS)
	$(CC) $(OBJECTS) -o main

main.o:main.cc
	$(CC) -c main.cc

Date.o:Date.cc Date.h
	$(CC) -c Date.cc

clean:
	rm -f *~ *.o main
