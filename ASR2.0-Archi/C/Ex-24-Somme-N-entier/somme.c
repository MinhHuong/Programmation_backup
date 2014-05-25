#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  int i;
  int somme = 0;

  printf("Entrez N : ");
  scanf("%d", &n);

  for (i = 0 ; i <= n ; i++) {
    somme += i;
  }

  printf("La somme : %d\n", somme);

  return EXIT_SUCCESS;
}
