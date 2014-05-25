#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  float somme = 0.0;
   int nombre = 0;
  float note;

  //r+ pour a la fois lire & ecrire
  FILE *fnotes = fopen("notes.txt", "r+");
  while (fscanf(fnotes, "%f", &note) == 1) {
    somme += note;
    nombre++;
  }
  fprintf(fnotes,
	  "%d notes lues, total = %.2f, moyenne = %05.2g\n",
	  nombre, somme, somme/nombre);
  fclose(fnotes);

  /*
  FILE *fwrite = fopen("result.txt", "w");
  fprintf(fwrite,
	  "%d notes lues, total = %.2f, moyenne = %05.2g\n",
	  nombre, somme, somme/nombre);
  fclose(fwrite);
  */
  
  return EXIT_SUCCESS;
}
