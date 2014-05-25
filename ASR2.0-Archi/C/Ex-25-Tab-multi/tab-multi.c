#include <stdio.h>
#include <stdlib.h>

int main() {
  int i;
  int j;

  printf("\t");
  for (i = 1 ; i <= 9 ; i++)
    printf("%d\t", i);
  
  printf("\n");
  printf("\t");
  for (i = 1 ; i <= 9 ; i++)
    printf("--\t");
  printf("\n");

  for (i = 1 ; i <= 9 ; i++) {
    printf("%d :", i);
    printf("\t");
    for (j = 1 ; j <= 9 ; j++) 
      printf("%d\t", i*j);
    printf("\n");
  }
  
  return EXIT_SUCCESS;
}
