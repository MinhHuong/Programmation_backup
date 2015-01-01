#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


/*==================================
** VARIABLES GLOBALES & PROTOTYPES
====================================*/

#define SYMBOL_SIZE 10

char* getSymbol(int i);
void  calculerPoint(int pidArray[], int pointArray[], int symbolArray[], int size);

/*==================================
** PROGRAMME PRINCIPAL
====================================*/

int main(int argc, char *argv[])
{
  int nb_joueurs = 0;
  
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

  int alea = 0;
  float max = 3;
  int i;
  int n;
  int pid, code;
  
  int nb_symbol[nb_joueurs];
  int points[nb_joueurs];
  int tab_pid[nb_joueurs];
  
  for(i = 0 ; i < nb_joueurs ; i++)
    {
      points[i] = 0;	
    }

  for(i = 0 ; i < nb_joueurs ; i++)
    {
      if( (n = fork()) == 0 )
	{	 
	  srand(time(NULL) + getpid());
	  alea = (int) (max * rand() / RAND_MAX);
	  exit(alea);
	}
    }

  for(i = 0 ; i < nb_joueurs ; i++)
    {
      pid = wait(&code);
      
      if(WIFEXITED(code) == 1)
	{
	  nb_symbol[i] = WEXITSTATUS(code);
	  tab_pid[i] = pid;
	}
    }

  calculerPoint(tab_pid, points, nb_symbol, nb_joueurs);

  printf("\n=====================\n"); fflush(stdout);

  exit(EXIT_SUCCESS);
}

/*==================================
** TOUTES LES FONCTIONS
====================================*/

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

void calculerPoint(int pidArray[], int pointArray[], int symbolArray[], int size)
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
      printf("Processus %d joue %s, point %d\n", pidArray[i], getSymbol(symbolArray[i]), pointArray[i]);
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
