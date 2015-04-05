CC = g++

OBJECTS = Stack.o AStack.o LStack.o main.o

Exec: $(OBJECTS)
	$(CC) $(OBJECTS) -o Exec

main.o: main.cc
	$(CC) -c main.cc

Link.o: Link.cc
	$(CC) -c Link.cc

Stack.o : Stack.cc
	$(CC) -c Stack.cc

AStack.o : AStack.cc
	$(CC) -c AStack.cc

LStack.o : LStack.cc
	$(CC) -c LStack.cc

clean:
	rm -fr *~ *.o Exec; clear
