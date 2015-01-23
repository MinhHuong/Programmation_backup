#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NB_P 5
#define NB_C 5
#define IT   10
#define MAX  2

/****************** GLOBAL VARIABLES ******************/
int nb;
int in;
int out;

sem_t mutexin;
sem_t mutexout;
sem_t mutexteste;

sem_t nonplein;
sem_t nonvide;

int buffer[MAX];
int pos_test;
int done;

/********************** PROTOTYPES ********************/
void* prod(void* arg);
void* cons(void* arg);
void* filt();

int   test(int nb);
int  produire_1_element();

/********************* MAIN PROGRAM *******************/
int main()
{
  nb = 0;
  in = 0;
  out = 0;
  done = 0;

  int i;
  pthread_t p_tid[NB_P], c_tid[NB_C], f_tid;

  for(i = 0 ; i < MAX ; i++)
    {
      buffer[i] = 0;
    }

  sem_init(&mutexin    ,  0 , 1);
  sem_init(&mutexout   ,  0 , 1);
  sem_init(&mutexteste ,  0 , 1);
 
  sem_init(&nonplein   ,  0 , MAX);
  sem_init(&nonvide    ,  0 , 0);

  srand(time(NULL) + getpid());

  
  if(pthread_create(&f_tid, NULL, filt, NULL) != 0)
    {
      printf("Cannot create filter\n");
      exit(-1);
    }

  for(i = 0 ; i < NB_P ; i++)
    {
      if(pthread_create(&p_tid[i], NULL, prod, (void*)i) != 0)
	{
	  printf("Cannot create thread\n");
	  exit(-1);
	}
    }

  for(i = 0 ; i < NB_C ; i++)
    {
      if(pthread_create(&c_tid[i], NULL, cons, (void*)i) != 0)
	{
	  printf("Cannot create thread\n");
	  exit(-1);
	}
    }

  for(i = 0 ; i < NB_P ; i++)
    {
      if(pthread_join(p_tid[i], NULL) != 0)
	{
	  printf("Cannot join thread\n");
	  exit(-1);
	}
    }

  for(i = 0 ; i < NB_C ; i++)
    {
      if(pthread_join(c_tid[i], NULL) != 0)
	{
	  printf("Cannot join thread\n");
	  exit(-1);
	}
    }
  
  done = 1;

  if(pthread_join(f_tid, NULL) != 0)
    {
      printf("Cannot join filter\n");
      exit(-1);
    }


  sem_destroy(&mutexin);
  sem_destroy(&mutexout);
  sem_destroy(&mutexteste);

  sem_destroy(&nonplein);
  sem_destroy(&nonvide);

  exit(0);
}

/********************** FUNCTIONS *********************/
void* prod(void* arg)
{
  int i;
  int ind = (int) arg;

  for(i = 0 ; i < IT ; i++)
    {
      sem_wait(&nonplein);
      sem_wait(&mutexin);

      nb++;
      buffer[in] = nb;
      printf("P %d : je produis %d\n", ind, buffer[in]);
      pos_test = in;
      in = (in+1)%MAX;
      printf("P %d : Fois %d\n", ind, i);

      sem_post(&mutexin);
      sem_post(&mutexteste);
    }
  
  return NULL;
}

void* filt()
{
  int i, j;

  int pos_test = 0;

  while(done != 1)
    {
      sem_wait(&mutexteste);

      printf("F: je teste %d\n", buffer[pos_test]);
      
      while(test(buffer[pos_test]) != 0)
	{
	  printf("F : je filtre le nombre %d\n", buffer[pos_test]);
	  buffer[pos_test] -= 5;
	  printf("F : apres filtre %d\n", buffer[pos_test]);
	}

      pos_test = (pos_test+1)%MAX;
      sem_post(&nonvide);
    }

  return NULL;
}

void* cons(void* arg)
{
  int i;
  int ind = (int) arg;

  for(i = 0 ; i < IT ; i++)
    {
      sem_wait(&nonvide);
      sem_wait(&mutexout);

      printf("C %d : je lis %d\n", ind, buffer[out]);
      out = (out+1)%MAX;
  
      sem_post(&mutexout);
      sem_post(&nonplein);
    }

  return NULL;
}

int test(int m_nb)
{
  if(m_nb >= 1 && m_nb <= 6) 
    return 0;
  else 
    return -1;
}

int produire_1_element()
{
  int temp = buffer[in]-10;
  return temp;
}
