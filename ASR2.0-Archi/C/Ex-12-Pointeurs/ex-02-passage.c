#include <stdio.h>
#include <stdlib.h>

void sqr(int a, int b) {
  printf("\nFonction sqr(int a, int b) : \n");
  printf("%p\n", &a);
  printf("%p\n", &b);
  
  b=a*a;
}

void sqr2(int a, int *b) {
  printf("\nFonction sqr2(int a, int *b) :\n");
  printf("%p\n", &a);
  printf("%p\n", b);

  *b=a*a;
  printf("\nResultat = %d", *b);
}

int main() {
  int a=4, b;

  printf("Main initiale :\n");
  printf("%p\n", &a);
  printf("%p\n", &b);

  sqr(a,b);
  printf("\nMain apres sqr :\n");
  printf("%p\n", &a);
  printf("%p\n", &b);

  sqr2(a,&b);
  printf("\nMain apres sqr2 :\n");
  printf("%p\n", &a);
  printf("%p\n", &b);
 
  return EXIT_SUCCESS;
}
