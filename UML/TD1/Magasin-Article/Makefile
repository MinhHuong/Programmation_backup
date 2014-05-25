CC=g++
OBJECTS=Article.o PrixArticle.o Magasin.o Employe.o main.o

main : $(OBJECTS)
	$(CC) $(OBJECTS) -o main

Article.o : Article.h Article.cc
	$(CC) -c Article.cc

Magasin.o : Magasin.h Magasin.cc Employe.h
	$(CC) -c Magasin.cc

PrixArticle.o : PrixArticle.h PrixArticle.cc Magasin.h Article.h
	$(CC) -c PrixArticle.cc

Employe.o : Employe.cc Employe.h
	$(CC) -c Employe.cc

main.o : main.cc PrixArticle.h Magasin.h Article.h Employe.h
	$(CC) -c main.cc

clean :
	rm -f *~ *.o main
