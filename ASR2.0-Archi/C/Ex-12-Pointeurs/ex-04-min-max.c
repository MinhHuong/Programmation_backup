#include <stdio.h>
#include <stdlib.h>

void pointeurMinMax(int tab[], int n, int *min, int *max) {
  int i;

  *min=9999;  
  for (i=1 ; i<n ; i++) {
    if ( *min > tab[i] ) 
      *min = tab[i];
  }

  *max=-9999;
  for (i=1 ; i<n ; i++) {
    if ( *max < tab[i] )
      *max = tab[i];
  }
}

int main() {
  int t[5] = {3, 7, 1, 4, 6};
  int taille = 5;

  int *ptrmin, *ptrmax;
  pointeurMinMax(t, taille, ptrmin, ptrmax);
  printf("Min = %d\nAdresse Min = %p\n", *ptrmin, ptrmin);
  printf("Max = %d\nAdresse Max = %p\n", *ptrmax, ptrmax);

  return EXIT_SUCCESS;
}
