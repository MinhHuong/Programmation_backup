#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const static int MAX = 100;

int main() {
  int number=0;
  int tab[MAX];
  int taille = 0;
  int choix;

  int i;
  printf("Entrez les chiffres :\n");
  for (i=0;i<MAX;i++)
    {
      scanf("%d", &tab[i]);

      if (tab[i]==0) {
	printf("Voulez-vous continuer ? (yes 1, no 2) : ");
	scanf("%d", &choix);
	if (choix == 1)
	  continue;
	else
	  break;
      }

      taille++;
    }

  for (i=taille;i>=0;i--)
    number += tab[i] * pow(10, i); 

  printf("Result = %d\n", number);
  
  return EXIT_SUCCESS;
}
