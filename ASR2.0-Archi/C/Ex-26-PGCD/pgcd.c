#include <stdio.h>
#include <stdlib.h>

int pgcd(int x, int y) {
  if (x%y == 0)
    return y;
  else
    return pgcd(y,x%y);
}

int main() {
  int a, b, result = 0;

  printf("Entrez 2 nombres : ");
  scanf("%d%d", &a, &b);

  if (a==0 || b==0) {
    printf("Les 2 nombres doivent etre differents de 0.\n");
    exit(-1);
  }

  if (a>b) 
    result = pgcd(a,b);
  else
    result = pgcd(b,a);

  printf("%d\n", result);

  return EXIT_SUCCESS;
}
