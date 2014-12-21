#include <stdio.h>
#include <stdlib.h>

/*
  - faire entrer des valeurs a,b
  - faire la somme a+b
  - afficher la phrase la somme de a et b est c
*/

void saisir(int *x, int *y) {
  printf("Entrez 2 nombres : ");
  scanf("%d%d", x, y);
}

void somme(const int x, const int y, int *result) {
  *result = x+y;
}

void afficher(const int x, const int y, const int result) {
  printf("La somme de %d et %d vaut %d\n", x, y, result);
}


int main() {
  int a,b,c;
  
  saisir(&a,&b);
  somme(a,b,&c);
  afficher(a,b,c);

  return EXIT_SUCCESS;
}
