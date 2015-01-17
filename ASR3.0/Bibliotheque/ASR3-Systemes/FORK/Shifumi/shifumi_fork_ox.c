#include <stdlib.h>
#include <stdio.h>
//#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

/*==================================
** VARIABLES GLOBALES & PROTOTYPES
====================================*/

#define PIERRE 0
#define PAPIER 1
#define CISEAUX 2

char* codeType(int i);

/*==================================
** PROGRAMME PRINCIPAL
====================================*/

int main(int argc, char *argv[])
{
  int nbjoueurs = 0;

  if(argc == 2)
    {
      nbjoueurs = atoi(argv[1]);
      fprintf (stdout, "\nNombre de joueurs = %d\n\n", nbjoueurs);;
    }
  else
    {
      fprintf(stderr, "Usage: %s <nombre de joueurs> \n", argv[0]);
      exit(EXIT_FAILURE);
    }
    
  int i, code; 
  int type[nbjoueurs];
  int points[nbjoueurs];
  pid_t tab_pid[nbjoueurs];

  for(i = 0 ; i < nbjoueurs ; i++)
    {
      if( fork() == 0 )
	{ 
	  int choix = 0;
	  srand(time(NULL) + getpid());
	  choix = aleatoire();
	  exit(choix);
	}
    }

  for(i = 0 ; i < nbjoueurs ; i++)
    {
      tab_pid[i] = wait(&code);
      type[i] = WEXITSTATUS(code);
      fprintf(stdout, "Process%d : %d \t chon %s \n", i, tab_pid[i], codeType(type[i]));
    }
  fprintf(stdout, "\nResultat\n");
	int nb;
	
	for (nb=0; nb<nbjoueurs; nb++)
	{
		points[nb] = 0;
		for (i=0; i<nbjoueurs; i++)
		{
			if(type[nb] ==PAPIER && type[i] == PIERRE)
				points[nb]++;
			if(type[nb] == CISEAUX && type[i] == PAPIER)
				points[nb]++;
			if(type[nb] == PIERRE && type[i] == CISEAUX)
				points[nb]++;
		}
	}
	
  for (i=0; i<nbjoueurs; i++)
  {
    fprintf(stdout, "Process%d : %d \t", i, tab_pid[i]);
    fprintf(stdout, "\t\tDiem: %d\n", points[i]);
  }

  fprintf(stdout, "\n");
  exit(EXIT_SUCCESS);
}

/*==================================
** TOUTES LES FONCTIONS
====================================*/

char* codeType(int i)
{
  char *choix[] = { "PIERRE", "PAPIER", "CISEAUX" };
  return choix[i];
}

int aleatoire()
{
  float max =3;
  int nombre = (int) (max *rand() /RAND_MAX);
  return(nombre);
}