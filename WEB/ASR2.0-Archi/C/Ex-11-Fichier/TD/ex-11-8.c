#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_palin(char word[]) {
  char *p1 = word, 
    *p2 = word+strlen(word)-1;
  
  while (p2>p1) {
    if ( tolower(*p1)==tolower(*p2) ) {
      p1++;
      p2--;
    }
    else
      return 0;
  }

  return 1;
}


int main() {
  char mot[50];
  int nb_mots=0, nb_palin=0, longueur=0, temp=0;
  float moyen=0;

  FILE *calcul = fopen("mot.txt", "r");
  
  while ( !feof(calcul) ) {
    fscanf(calcul, "%s", mot);
    if ( strcmp(mot,"\n") )
      nb_mots++;
    if ( check_palin(mot)==1 )
      nb_palin++;
    longueur+=strlen(mot);
    temp=strlen(mot);
  }

  nb_mots--;
  longueur-=temp;
  
  printf("Nombre de mots : %d\n", nb_mots);
  printf("Nombre de palindromes : %d\n", nb_palin);
  printf("Longueur moyenne des mots : %.2f\n", (float) longueur/nb_mots);

  fclose(calcul);
  
  return EXIT_SUCCESS;
}
