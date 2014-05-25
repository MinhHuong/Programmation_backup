CC=g++
OBJECTS=main.o Point.o Cercle.o Forme.o Segment.o

main:$(OBJECTS)
	$(CC) $(OBJECTS) -o main

main.o:main.cc Point.h
	$(CC) -c main.cc

Point.o:Point.cc Point.h
	$(CC) -c Point.cc

Cercle.o:Cercle.cc Cercle.h
	$(CC) -c Cercle.cc

Forme.o:Forme.cc Forme.h
	$(CC) -c Forme.cc

Segment.o:Segment.cc Segment.h
	$(CC) -c Segment.cc

clean:
	rm -f *~ *.o main
