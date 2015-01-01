#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

float max = 3.0;

int main(int argc, char* argv[])
{
  srand(time(NULL) + getpid());
  int alea = (int) (max * rand() / RAND_MAX);
  exit(alea);
}
