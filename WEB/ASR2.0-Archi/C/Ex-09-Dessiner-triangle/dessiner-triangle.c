#include <stdio.h>
#include <stdlib.h>

int main() {
  int N;
  printf("Entrez N (lignes) : ");
  scanf("%d", &N);

  int i, j, espace, nb_stars;
  for ( i=1 ; i<=N ; i++ ) {
    nb_stars = 2*i-1;
    espace = N-i;
    for( j=0 ; j<espace ; j++)
      printf(" ");
    for( j=0 ; j<nb_stars ; j++)
      printf("*");
    for( j=0 ; j<espace ; j++)
      printf(" ");
    printf("\n");
  }
    

  return EXIT_SUCCESS;
}
