#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  int i;
  float result=0.0;

  printf("Entrez N : ");
  scanf("%d", &n);
  printf("%d\n", n);

  for (i=1;i<=n;i++)
    result += 1.0/i;
  
  printf("Serie harmonique = %.3f\n", result);

  return EXIT_SUCCESS;
}
