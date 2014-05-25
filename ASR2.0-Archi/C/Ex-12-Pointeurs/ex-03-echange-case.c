#include <stdio.h>
#include <stdlib.h>

/*
  SWAP :
    a = a+b;
    b = a-b;
    a = a-b;
*/

void echange1(int a, int b) {
  a = a+b;
  b = a-b;
  a = a-b;
}

void echange2(int *a, int *b) {
  *a = *a + (*b);
  *b = *a - (*b);
  *a = *a - (*b);
}

int main() {
  int x,y;
  printf("Entrez 2 nombres : ");
  scanf("%d%d", &x, &y);

  echange1(x,y);
  printf("%d %d\n", x, y);

  echange2(&x, &y);
  printf("%d %d\n", x, y);
  
  return EXIT_SUCCESS;
}
