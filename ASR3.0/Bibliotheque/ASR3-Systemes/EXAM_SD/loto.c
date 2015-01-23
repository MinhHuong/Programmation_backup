#include <stdio.h>
#include <stdlib.h>

#define MAX 7

/********************* Prototypes ************************/
int getAlea();


/********************* Programme principal ***************/
int main()
{
  int f, n;
  int fd[MAX][2];

  for(n = 0 ; n < MAX ; n++)
    {
      if(pipe(fd[n]) != 0)
	{
	  printf("Erreur : Impossible de creer le tube\n");
	  exit(-1);
	}
    }

  int num;
  for(n = 0 ; n < MAX ; n++)
    {
      f = fork();
      
      if(f == 0)
	{
	  close(fd[n][0]);
	  srand(time(NULL) + getpid());
	  num = getAlea();
	  printf("Fils indice %d a tire %d\n", n, num);
	  write(fd[n][1], &num, sizeof(int));
	  write(fd[n][1], &n, sizeof(int));
	  close(fd[n][1]);
	  exit(0);
	}
    }

  int tab_ind[MAX], tab_num[MAX];
  for(n = 0 ; n < MAX ; n++)
    {
      wait(NULL);
      open(fd[n][0]);
      read(fd[n][0], &tab_num[n], sizeof(int));
      read(fd[n][0], &tab_ind[n], sizeof(int));
      printf("P: Processus pere a recu fils %d numero %d\n", tab_ind[n], tab_num[n]);
    }

  int j;

  printf("Grille : ");

  for(n = 0 ; n < MAX-1 ; n++)
    {
      for(j = 0 ; j < MAX ; j++)
	{
	  if(tab_ind[j] == n)
	    {
	      printf("%d ", tab_num[j]);
	    }
	}
    }

  for(n = 0 ; n < MAX ; n++)
    {
      if(tab_ind[n] == MAX-1)
	{
	  printf("\nComplementaire : %d\n", tab_num[n]);
	}
    }

  exit(0);
}

/************************** Des fonctions ********************/

int getAlea()
{
  float max = 49;
  int nb = (int) ( (max * rand() / RAND_MAX) + 1);
  return nb;
}
