CC = g++

OBJECTS = Link.o Queue.o AQueue.o LQueue.o main.o

Exec: $(OBJECTS)
	$(CC) $(OBJECTS) -o Exec

main.o: main.cc
	$(CC) -c main.cc

Link.o: Link.cc
	$(CC) -c Link.cc

Queue.o: Queue.h Queue.cc
	$(CC) -c Queue.cc

AQueue.o: AQueue.h AQueue.cc
	$(CC) -c AQueue.cc

LQueue.o: LQueue.h LQueue.cc
	$(CC) -c LQueue.cc

clean:
	rm -fr *~ *.o Exec; clear
