#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

float max = 9.0;

int main(int argc, char* argv[])
{
  int total = atoi(argv[1]);

  int i;
  int n;
  int alea;
  int pid;
  int fd[total][2];

  for(i = 0 ; i < total ; i++)
    {
      if(pipe(fd[i]) == -1)
	{
	  fprintf(stdout, "Error : can't open pipe\n");
	  exit(EXIT_FAILURE);
	}
    }

  for(i = 0 ; i < total ; i++)
    {  
      n = fork();

      if(n == -1)
	{
	  fprintf(stdout, "Can't duplicate process\n");
	  exit(-1);
	}

      if(n == 0)
	{
	  close(fd[i][0]);
	  srand(time(NULL) + getpid());
	  pid = getpid();
	  alea = (int) (max * rand() / RAND_MAX);
	  write(fd[i][1], &alea, sizeof(int));
	  write(fd[i][1], &pid, sizeof(int));
	  close(fd[i][1]);
	  exit(i);
	}
    }

  int sum = 0;
  for(i = 0 ; i < total ; i++)
    {
      wait(NULL);

      close(fd[i][1]);
      read(fd[i][0], &alea, sizeof(int));
      read(fd[i][0], &pid, sizeof(int));
      fprintf(stdout, "Processus %d choisit %d\n", pid, alea);
      sum += alea;
      close(fd[i][0]);
    }

  fprintf(stdout, "(PROCESSUS) Somme totale = %d\n", sum);

  exit(EXIT_SUCCESS);
}
