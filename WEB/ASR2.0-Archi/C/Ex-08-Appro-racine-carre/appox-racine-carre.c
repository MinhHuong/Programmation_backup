#include <stdio.h>
#include <stdlib.h>

float racine_carre(float a, int j) {
  if (j==1)
    return a;
  else
    return (racine_carre(a,j-1) + a/racine_carre(a,j-1))/2;
}

int main() {
  float number;
  do {
    printf("Votre nombre : ");
    scanf("%f", &number);
  } while (number<=0);

  int niveau;
  do {
    printf("Approximation a niveau : ");
    scanf("%d", &niveau);
  } while (niveau<=0 && niveau>=50);

  float result;
  int i=1;
  while (i<=niveau) {
    result=racine_carre(number,i);
    printf("La %dere approximation de la racine carre de %f est %f\n", i, number, result);
    i++;
  }

  return EXIT_SUCCESS;
}
