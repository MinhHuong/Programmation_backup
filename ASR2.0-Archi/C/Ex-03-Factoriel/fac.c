#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int fac_for(int N) {
  int i;
  int result=1;

  if (N==0)
    result = 1;
  for (i = 1; i <= N ; i++)
    result *= i;

  return result;
}


int fac_while(int N) {
  int i = 0;
  int result=1;

  if (N==0)
    result = 1;
  while (i <= N) {
    result *= i;
    i++;
  } 

  return result;
}


int main() {
  int nb, fac;

  do {
  printf("Entrez N : ");
  scanf("%d", &nb);
  }
  while (nb < 0);

  fac = fac_while(nb);
  printf("Fac(%d) = %d\n", nb, fac);

  return 0;
}
