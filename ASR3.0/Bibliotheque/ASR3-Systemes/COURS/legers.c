#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <pthread.h>

int sum = 0;
float max = 9.0;
pthread_mutex_t mutex;

void* calculer(void* arg)
{
  int j = (int)arg;
  int alea = (int) (max * rand() / RAND_MAX);
  fprintf(stdout, "Thread %i choisit %d\n", j, alea);
  
  //section critique
  pthread_mutex_lock(&mutex);
  sum += alea;
  pthread_mutex_unlock(&mutex);

  pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
  int total = atoi(argv[1]);
  int i;
  int ret;
  pthread_t tid[total];

  pthread_mutex_init(&mutex, NULL);

  srand(time(NULL) + getpid());
  for(i = 0 ; i < total ; i++)
    {
      ret = pthread_create(&tid[i], NULL, calculer, (void*)i);
      if(ret != 0)
	{
	  fprintf(stdout, "Can't create thread !\n");
	  exit(EXIT_FAILURE);
	}
    }

  for(i = 0 ; i < total ; i++)
    {
      ret = pthread_join(tid[i], NULL);

      if(ret != 0)
	{
	  fprintf(stdout, "Thread is not joinable !\n");
	  exit(EXIT_FAILURE);
	}
    } 

  fprintf(stdout, "THREAD : Somme totale = %d\n", sum);

  pthread_mutex_destroy(&mutex);

  exit(EXIT_SUCCESS);
}
