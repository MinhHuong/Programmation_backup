CC=g++
OBJECTS=main.o Triangle.o

main: $(OBJECTS)
	$(CC) $(OBJECTS) -o main

main.o:main.cc
	$(CC) -c main.cc

Triangle.o:Triangle.cc
	$(CC) -c Triangle.cc

clean:
	rm -f *~ *.o main
