#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <semaphore.h>


/*==================================
** VARIABLES GLOBALES & PROTOTYPES
====================================*/

#define SYMBOL_SIZE 10
#define BUFFER 2

float max = 3;

char* getSymbol(int i);
void  calculerPoint(int pointArray[], int symbolArray[], int size);
int   getAleatoire();
void* jouer(void* i);

int*  nb_symbol;

sem_t estNonPlein; //tester si le buffer est deja plein ou non, si plein, bloque les threads
sem_t estNonVide;  //tester si le buffer est vide ou non, si vide, bloque le proc pere qui tente de lire
sem_t mutex; //eviter que 2 threads ecrivent a une meme donnee dans un moment donne
int   cpt = 0;
int   pos = 0;
pthread_t* tab_tid;
pthread_t* update_tab_tid;

struct symbole_tid 
{
  pthread_t tid;
  int symbole;
};

struct symbole_tid m_tab[BUFFER];

/*==================================
** PROGRAMME PRINCIPAL
====================================*/

int main(int argc, char *argv[])
{
  int nb_joueurs = 0;

  sem_init(&estNonPlein, 0, BUFFER);
  sem_init(&estNonVide, 0, 0);
  sem_init(&mutex, 0, 1);
  
  if(argc == 2)
    {
      nb_joueurs = atoi(argv[1]);
      printf("\nNombre de joueurs = %d\n\n", nb_joueurs); fflush(stdout);
    }
  else
    {
      printf("S'il vous plait, entrez le nombre de joueurs (./shifumi <nb>)\n"); fflush(stdout);
      exit(-1);
    }

  int i;
  int points[nb_joueurs];
  nb_symbol = (int*)malloc(nb_joueurs * sizeof(int));
  
  for(i = 0 ; i < nb_joueurs ; i++)
    {
      points[i] = 0;	
    }

  srand(time(NULL) + getpid());

  tab_tid = (pthread_t*)malloc(nb_joueurs * sizeof(int));
  int ret;
  for(i = 0 ; i < nb_joueurs ; i++)
    {
      ret = pthread_create(&tab_tid[i], NULL, jouer, (void*)i);
      if(ret != 0)
	{
 	   fprintf(stdout, "Erreur de creer un thread\n");
	}
    }

  update_tab_tid = (pthread_t*)malloc(nb_joueurs * sizeof(int));
  for(i = 0 ; i < nb_joueurs ; i++)
    {
      sem_wait(&estNonVide);
      nb_symbol[i] = m_tab[pos].symbole;
      update_tab_tid[i] = m_tab[pos].tid;
      sem_post(&estNonPlein);
    }

  for(i = 0 ; i < nb_joueurs ; i++)
    {
      ret = pthread_join(tab_tid[i], NULL);
      if(ret != 0)
	{
     	   fprintf(stdout, "Erreur de pthread_join\n");
	}
    }

  calculerPoint(points, nb_symbol, nb_joueurs);

  printf("\n=====================\n"); fflush(stdout);

  free(nb_symbol);
  exit(EXIT_SUCCESS);
}

/*==================================
** TOUTES LES FONCTIONS
====================================*/

int getAleatoire()
{
  int alea = (int) (max * rand() / RAND_MAX);
  return alea;
}

void* jouer(void* i)
{
  int j = (int) i;

  sem_wait(&estNonPlein);

  sem_wait(&mutex);

  int alea = getAleatoire();
  fprintf(stdout, "Thread %lu is running, playing %s symbol at postion %d\n", tab_tid[j], getSymbol(alea), pos);
  pos = cpt % BUFFER;
  m_tab[pos].tid = tab_tid[j];
  m_tab[pos].symbole = alea;
  cpt++;

  sem_post(&mutex);

  sem_post(&estNonVide);

  pthread_exit((void*) NULL);
}

char* getSymbol(int i)
{
  char* resultat;

  switch(i)
    {
    case 0:
      {
	resultat = "Pierre";
	break;
      }

    case 1:
      {
	resultat = "Papier";
	break;
      }

    case 2:
      {
	resultat = "Ciseaux";
	break;
      }

    default:
      {
	resultat = "Erreur";
	break;
      }
    }

  return resultat;
}

void calculerPoint(int pointArray[], int symbolArray[], int size)
{
  int i;
  int j;

  for(i = 0 ; i < size ; i++)
    {
      for(j = 0 ; j < size ; j++)
	{
	  if(symbolArray[i] != symbolArray[j])
	    {
	      if(estGagne(symbolArray[i], symbolArray[j]) == 0) pointArray[i]++;
	    }
	}
    }


  for(i = 0 ; i < size ; i++)
    {
      printf("Thread %lu joue %s, point %d\n", update_tab_tid[i], getSymbol(symbolArray[i]), pointArray[i]);
      fflush(stdout);
    }
}

/*
** 0 si true, -1 si false
*/
int estGagne(int s1, int s2)
{
  // Pierre gagne Ciseaux
  if(s1 == 0)
    { 
      if (s2 == 2) return 0;
      else return -1;
    }
  
  // Papier gagne Pierre
  if(s1 == 1)
    { 
      if(s2 == 0) return 0;
      else return -1;
    }

  // Ciseaux gagne Papier
  if(s1 == 2) 
    {
      if(s2 == 1) return 0;
      else return -1;
    }
}
