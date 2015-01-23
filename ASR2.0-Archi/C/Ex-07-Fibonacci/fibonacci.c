#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int fibo(int N) {
  if (N==0 || N==1)
    return 1;
  else
    return (fibo(N-1) + fibo(N-2));
}

int main() {
  int result;
  int n;

  printf("Entrez N = ");
  scanf("%d", &n);

  result = fibo(n);
  printf("%d\n", result);

  return EXIT_SUCCESS;
}
