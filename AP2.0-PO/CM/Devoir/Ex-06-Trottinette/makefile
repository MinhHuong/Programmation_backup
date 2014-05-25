CC=g++
OBJECTS=main.o Trottinette.o

main:$(OBJECTS)
	$(CC) $(OBJECTS) -o main

Trottinette.o:Trottinette.cc Trottinette.h
	$(CC) -c Trottinette.cc

main.o:Trottinette.h main.cc
	$(CC) -c main.cc

clean:
	rm -f *~ *.o main
