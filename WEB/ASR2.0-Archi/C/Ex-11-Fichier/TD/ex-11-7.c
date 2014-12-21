#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char mot[50];

  FILE *write = fopen("mot.txt", "w+");
  while (1) {
    printf("Mot : ");
    scanf("%s", mot);
    if ( strcmp(mot,"*")==0 )
      break;
    fprintf(write, "%s\n", mot);
  }
  fclose(write);

  return EXIT_SUCCESS;
}
