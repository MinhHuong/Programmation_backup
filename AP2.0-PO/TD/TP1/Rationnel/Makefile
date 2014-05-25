CC=g++
OBJECTS=Rationnel.o TestRationnel.o util.o

TestRationnel:$(OBJECTS)
	$(CC) $(OBJECTS) -o TestRationnel

Rationnel.o:Rationnel.cc Rationnel.h util.h
	$(CC) -c Rationnel.cc

util.o:util.cc util.h Rationnel.h
	$(CC) -c util.cc

TestRationnel.o:TestRationnel.cc Rationnel.h
	$(CC) -c TestRationnel.cc

clean:
	rm -f *~ *.o TestRationnel
