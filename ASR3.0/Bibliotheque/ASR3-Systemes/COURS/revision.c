#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>

char* total;

void compet()
{ 
  int i;
  int n;

  for(i = 0 ; i < 2 ; i++)
    {
      n = fork();

      if(i == 0 && n == 0)
	{
	  execl("legers", ".", total, NULL);
	}
      else if(i == 1 && n == 0)
	{
	  execl("lourds", ".", total, NULL);
	}
    }

  for(i = 0 ; i < 2 ; i++)
    {
      wait(NULL);
    }
}

int main(int argc, char* argv[])
{
  signal(SIGUSR1, compet);
  total = argv[1];

  if(argc < 2)
    {
      fprintf(stdout, "Veuillez lancer revision <nombre>\n");
      exit(EXIT_FAILURE);
    }

  fprintf(stdout, "total = %s\n", total);
  int i;
  for(i = 0 ; i < 3 ; i++)
    {
      fprintf(stdout, "%d...", (i+1));
      fflush(stdout);
      sleep(1);
    }
  fprintf(stdout, "Go !\n");

  kill(getpid(), SIGUSR1);

  exit(EXIT_SUCCESS);
}
