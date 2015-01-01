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
void  calculerPoint(int pidArray[], int pointArray[], int symbolArray[], int size, int fois);

/*==================================
** PROGRAMME PRINCIPAL
====================================*/

int main(int argc, char *argv[])
{
  int nb_joueurs = 0;

  int fois = 3;
  
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
  
  int nb_symbol[nb_joueurs*fois];
  int points[nb_joueurs*fois];
  int tab_pid[nb_joueurs*fois];
  
  for(i = 0 ; i < nb_joueurs*fois; i++)
    {
      points[i] = 0;	
    }

  for(i = 0 ; i < nb_joueurs*fois ; i++)
    {
      if( (n = fork()) == 0 )
		{	 
			srand(time(NULL) + getpid());
			alea = (int) (max * rand() / RAND_MAX);
			exit(alea);
		}
    }

  for(i = 0 ; i < nb_joueurs*fois ; i++)
    {
      pid = wait(&code);
      
		if(WIFEXITED(code) == 1)
		{
			nb_symbol[i] = WEXITSTATUS(code);
			tab_pid[i] = pid;
		}
    }

  for(i = 0 ; i < nb_joueurs*fois ; i++)
  {
	  printf("Joueur %d - Symbol : %s\n", i/fois + 1, getSymbol(nb_symbol[i]));
	  if(i % 3 == 2) printf("\n");
  }
  
  calculerPoint(tab_pid, points, nb_symbol, nb_joueurs, fois);

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

void calculerPoint(int pidArray[], int pointArray[], int symbolArray[], int size, int fois)
{
	int f;
	int j;
	int i;

  for(f = 0 ; f < fois ; f++)
  {
	  for(j = 0 ; j < size ; j++)
	  {
		  for(i = 0 ; i < size ; i++)
		  {
			  if((j*fois+f != i*fois+f) && (symbolArray[j*fois+f] != symbolArray[i*fois+f]))
			  {
				  printf("Position a comparer : %d\n", j*fois+f);
				  if(estGagne(symbolArray[j*fois+f], symbolArray[i*fois+f]) == 0) pointArray[j*fois+f]++;
			  }
		  }
	  }
  }

  int sum = 0;
  int count = 0;
  for(i = 0 ; i < size*fois ; i++)
    {
      sum += pointArray[i];
      printf("Point : %d\n", pointArray[i]);
      if(i%3 == 2)
	{
	  count++;
	  //printf("Joueur %d - Sum = %d\n", count, sum);
	  sum = 0;
	}
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
