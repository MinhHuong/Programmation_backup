#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 256

#define NB_THREAD 3
#define READ 0
#define WRITE 1

char tube[MAX];
pthread_mutex_t m;

char c;
int i;
int rw;

void* producteur(void* arg) 
{
  while(i < MAX)
    {
      pthread_mutex_lock(&m);
      if(rw == WRITE)
	{
	  i++;
	  tube[i]=c;
	  printf("producteur lu : %c\n", tube[i]);
	  c++;
	  
	  if(c>'z')
	    c='a';

	  rw = READ; 
	}
      pthread_mutex_unlock(&m);
      sleep(1);
    }
 
  return NULL;
}

void* consommateur(void* arg)
{
  while(i < MAX)
    {
      pthread_mutex_lock(&m);
      if(rw == READ)
	{
	  if(tube[i] != 0)
	    {
	      printf("conso lu : %c numero %d\n", tube[i], i);
	      tube[i]=0;
	    }
	  rw = WRITE;
	}
      pthread_mutex_unlock(&m);
    }

  return NULL;
}

int main(int argc, char** argv) 
{
  i = -1;
  c = 'a';
  rw = WRITE;

  pthread_t prod[NB_THREAD];
  pthread_t cons[NB_THREAD];
  memset(tube, 0, MAX);

  pthread_mutex_init(&m, NULL);
  int j;
  int val;
  for(j = 0 ; j < NB_THREAD ; j++)
    {
      pthread_create(&prod[j], NULL, producteur, NULL);
      pthread_create(&cons[j], NULL, consommateur, NULL);
    }

  int ret;
  for(j = 0 ; j < NB_THREAD ; j++)
    {
      ret = pthread_join(prod[j], NULL);
      ret = pthread_join(cons[j], NULL);
    }

  pthread_mutex_destroy(&m);

  return 0;
}
