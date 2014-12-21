#include <stdio.h>
#include <stdlib.h>

int main() {
  int number;
  int check;
  int i;
  printf("Votre nombre : ");
  scanf("%d", &number);

  for (i = number ; i > 0 ; i--) {
    if (number % i == 0)
      check++;
  }

  if (check == 2)
    printf("%d est un nombre premier\n", number);
  else
    printf("%d n'est pas un nombre premier\n", number);

  return EXIT_SUCCESS;
}
