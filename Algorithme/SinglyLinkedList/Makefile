CC = g++

OBJECTS = Link.o List.o LList.o main.o

Exec: $(OBJECTS)
	$(CC) $(OBJECTS) -o Exec

main.o : main.cc LList.cc
	$(CC) -c main.cc LList.cc

Link.o: Link.cc
	$(CC) -c Link.cc

List.o: List.cc
	$(CC) -c List.cc

LList.o: LList.cc
	$(CC) -c LList.cc

clean:
	rm -fr *~ *.o Exec; clear


