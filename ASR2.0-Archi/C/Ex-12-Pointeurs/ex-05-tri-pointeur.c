#include <stdio.h>
#include <stdlib.h>

const int MAX = 50;

void saisir(int t[], int taille) {
  printf("Entrez le tableau : \n");
  int i;
  for (i=0 ; i<taille ; i++)
    scanf("%d", &t[i]);
}

void afficher(int t[], int taille) {
  printf("Votre tableau : ");
  int i;
  for (i=0 ; i<taille ; i++)
    printf("%d ", t[i]);
  printf("\n");
}

void trier_indice(int t[], int taille, int pos[]) {
  int i, j;

  for (i=0 ; i<taille ; i++)
    pos[i]=0;

  for (i=0 ; i<taille ; i++) {
    for (j=0 ; j<taille ; j++) {
      if (t[i] > t[j])
	pos[i]++;
    }
  }

  printf("Votre tableau apres le tri : ");
  for (i=0 ; i<taille ; i++) {
    for (j=0 ; j<taille ; j++) {
      if (pos[j]==i)
	printf("%d ", t[j]);
    }
  }
  printf("\n");
}

void trier_pointeur(int t[], int taille, int *pos[]) {
  int i, j, rank=0, egal=0;
  
  for (i=0 ; i<taille ; i++) {
    for (j=0 ; j<taille ; j++) {
      if (t[i] > t[j])
	rank++;
      if (t[i] == t[j])
	egal++;
    }
    egal--;
  }
  
  /*
  for (i=0 ; i<taille; i++)
    printf("%d ", *pos[i]);
  printf("\n");
  */
}

int main() {
  int tab[MAX], *indice[MAX], size;
  printf("Size of array : ");
  scanf("%d", &size);
  
  saisir(tab, size);
  //afficher(tab, size);
  trier_pointeur(tab, size, indice);

  return EXIT_SUCCESS;
}
