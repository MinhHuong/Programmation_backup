#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int my_matri, matri;
  char my_nom[50], my_prenom[50], nom[50], prenom[50];

  FILE *copy = fopen("inform.txt", "r+");
  FILE *insert = fopen("infbis.txt", "w+");
  int found=0;

  printf("Matricule : "); scanf("%d", &my_matri);
  printf("Nom : "); scanf("%s", my_nom);
  printf("Prenom : "); scanf("%s", my_prenom);

  while ( !feof(copy) ) {
    fscanf(copy,"%d %s %s", &matri, nom, prenom);
    if ( strcmp(my_nom, nom)<=0 )
      found++;
    if (found==1)
      fprintf(insert, "%d\t%s\t%s\n", my_matri, my_nom, my_prenom);
    fprintf(insert, "%d\t%s\t%s\n", matri, nom, prenom);
  }

  if (found==0)
    fprintf(insert, "%d\t%s\t%s\n", my_matri, my_nom, my_prenom);

  fclose(insert);
  fclose(copy);

  return EXIT_SUCCESS;
}
