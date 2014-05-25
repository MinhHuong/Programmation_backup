CC=g++
OBJECTS=Complexe.o TesteComplexe.o util.o

main : $(OBJECTS)
	$(CC) $(OBJECTS) -o main

Complexe.o : Complexe.cc Complexe.h util.h
	$(CC) -c Complexe.cc

util.o : util.cc util.h Complexe.h
	$(CC) -c util.cc

clean:
	rm -f *~ *.o main
