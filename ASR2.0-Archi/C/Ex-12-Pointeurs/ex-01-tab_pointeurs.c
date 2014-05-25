#include <stdio.h>
#include <stdlib.h>

void saisir(int *p, int n) {
  int i;
  for (i=0 ; i<n ; i++)
    scanf("%d", p+i);
}

void afficher(int *p, int n) {
  int i;
  for (i=0 ; i<n ; i++)
    printf("%d  ", *(p+i) );
}

int somme(int *p, int n) {
  int i, result=0;
  for (i=0 ; i<n ; i++)
    result += *(p+i);

  return result;
}

int main() {
  int size, *pt;
  printf("Size of array : ");
  scanf("%d", &size);

  saisir(pt, size);

  afficher(pt, size);
  printf("\n");

  printf( "%d\n", somme(pt,size) );

  return EXIT_SUCCESS;
}
