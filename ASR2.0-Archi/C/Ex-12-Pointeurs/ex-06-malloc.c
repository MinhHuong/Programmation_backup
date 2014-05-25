#include <stdio.h>
#include <stdlib.h>

void saisir(int *t, int n) {
  int i;
  
  printf("Entrez votre tableau : ");
  for (i=0 ; i<n ; i++)
    scanf("%d", t+i );
}

void afficher(int *t, int n) {
  int i;

  printf("Votre tableau : ");
  for (i=0 ; i<n ; i++)
    printf("%d ", *(t+i) );
  printf("\n");
}

int main() {
  int *tab = (int*) malloc(sizeof(int)*2);
  
  int taille;
  printf("Votre taille : ");
  scanf("%d", &taille);
  
  saisir(tab, taille);
  afficher(tab, taille);

  //free(tab);

  return EXIT_SUCCESS;
}
