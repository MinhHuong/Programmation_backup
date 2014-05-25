#include <stdio.h>
#include <math.h>

int main(void) {
  int a, b, c, delta;
  float x1, x2;

  do {
    printf("Entrez a, b, c : ");
    scanf("%d%d%d", &a, &b, &c);
  }
  while (a == 0);

  delta = b*b - 4*a*c;

  if (delta == 0) {
    x1 = -b/2*a;
    printf("x = %.3f\n", x1);
  }
  else if (delta < 0)
    printf("L'equation n'a pas de solutions.\n");
  else {
    x1 = (-b + sqrt(delta) )/(2*a);
    x2 = (-b - sqrt(delta) )/(2*a);
    printf("x1 = %.3f\n", x1);
    printf("x2 = %.3f\n", x2);
  }

  return 0;
}
