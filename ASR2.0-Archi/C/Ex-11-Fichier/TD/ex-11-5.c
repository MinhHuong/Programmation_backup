#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_file (FILE *f, FILE *g) {
  if ( !f || !g ) {
    printf("Erreur dans la creation / l'ouverture des fichiers !\n");
    exit(-1);
  }
}

void supprimer_matri_8(FILE *f1, FILE *f2, int nb, char n[], char prn[]) {
  check_file(f1, f2);
  
  while ( !feof(f1) ) {
    fscanf(f1, "%d %s %s", &nb, n, prn);
    if ( nb%10!=8 )
      fprintf(f2, "%d\t%s\t%s\n", nb, n, prn);
  }
}

void supprimer_prenom_paul(FILE *f1, FILE *f2, int nb, char n[], char prn[]) {
  check_file(f1, f2);
  
  while ( !feof(f1) ) {
    fscanf(f1, "%d %s %s", &nb, n, prn);
    if ( strcmp(prn,"Paul")!=0 )
      fprintf(f2, "%d\t%s\t%s\n", nb, n, prn);
  }
}

int check_palindrome(char word[]) {
  char *p1 = word, 
    *p2 = word + strlen(word) - 1;

  while (p2>p1) {
    if ( tolower(*p1) == tolower(*p2) ) {
      p1++;
      p2--;
    }
    else
      return 0;
  }

  return 1;
}

void supprimer_palin(FILE *f1, FILE *f2, int nb, char n[], char prn[]) {
  check_file(f1, f2);

  while ( !feof(f1) ) {
    fscanf(f1, "%d %s %s", &nb, n, prn);
    if ( check_palindrome(n)==0 ) {
      fprintf(f2, "%d\t%s\t%s\n", nb, n, prn);
    }
  }
}

int main() {
  int matri, choice;
  char nom[50], prenom[50];

  FILE *erase = fopen("inform.txt", "r+");
  FILE *modified = fopen("infbis.txt", "w+");

  printf("----------\n1) Matricule termine par 8\n2) Prenom = 'PAUL'\n3) Nom est 1 palindrome\n\n==> Votre choix : ");
  scanf("%d", &choice);

  switch( choice ) {
  case 1: 
    {
      supprimer_matri_8(erase, modified, matri, nom, prenom);
      break;
    }
  case 2:
    {
      supprimer_prenom_paul(erase, modified, matri, nom, prenom);
      break;
    }
  case 3:
    {
      supprimer_palin(erase, modified, matri, nom, prenom);
      break;
    }
  default:
    {
      printf("Erreur saisie. Veuillez ressayer.\n");
      break;
    }
  }

  fclose(modified);
  fclose(erase);

  return EXIT_SUCCESS;
}
