CC=g++

gameBintz : Bintz.o main.o
	$(CC) Bintz.o main.o -o gameBintz

Bintz.o : Bintz.h Bintz.cc
	$(CC) -c Bintz.cc

main.o : main.cc Bintz.h
	$(CC) -c main.cc

clean :
	rm -fr *~ *.o gameBintz
