#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int n;
  int i;
  float x;
  float coef;
  float result=0.0;

  printf("Entrez n = "); scanf("%d", &n);
  printf("Entrez x = "); scanf("%f", &x);

  for (i=n;i>=0;i--) {
    printf("Entrez A[%d] = ", i);
    scanf("%f", &coef);
    result += coef*pow(x,i);
  }

  printf("Result = %.3f\n", result);
    
  return EXIT_SUCCESS;
}
