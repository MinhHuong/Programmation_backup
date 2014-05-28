CC=g++

main:Date.o main.o
	$(CC) Date.o main.o -o main

Date.o:Date.h Date.cc
	$(CC) -c Date.cc

main.o:Date.h main.cc
	$(CC) -c main.cc

clean:
	rm -fr *~ *.o main
