#include <stdio.h>
#include <stdlib.h>

int main() {
  float x, y, x2, y2, temp;
  float my_x[100], my_y[100];
  int line=0, i;

  FILE *coor = fopen("Result.txt", "r");
  //creer 2 tableaux x, y

  for (i=0 ; i<100 ; i++) {
    while (fscanf(coor, "%f %f", &my_x[i], &my_y[i])==1) {}
  }
  fclose(coor);

  /*
  //afficher les 2 tableaux
  for (i=0 ; i<100 ; i++) {
  printf("x[%d] = %.1f\t", i, my_x[i]);
  printf("y[%d] = %7.3f\n", i,  my_y[i]);
  }
  */

  //Chercher le y0 a travers le x0
  printf("Entrez x (x >= 0 & x <= 19.8 ) = ");
  scanf("%f", &x);

  //si x0 existe deja
  for (i=0 ; i<100 ; i++) {
    if (x==my_x[i]) {
      printf("y0 = %7.3f\n", my_y[i]);
      goto write_file;
    }
  }
    
  //si x0 quelconque se situe entre 0 et 19.8
  for (i=0 ; i<100 ; i++) {
    if (my_x[i]>x) {
      x2=my_x[i];
      y2=my_y[i];
      break;
    }
  }

  temp=( (x2-x)*y2 )/x2;
  y=y2-temp;
  printf("y0 = %f\n", y);

  /*

  (x0 - x[i-1]) / (x[i] - x[i-1]) 
                 =
  (y0 - y[i-1]) / (y[i] - y[i-1])

  ==> y0 = [( x0 - x[i-1] ) * ( y[i]-y[i-1] ) /
            ( x[i] - x[i-1] )] + y[i-1]

  */
 write_file: ;
  //must be an empty statement to use label

  FILE *fwrite = fopen("Coordonnees.txt", "w");
  fprintf(fwrite, "( %.1f , %7.3f )\n", x, y);
  fclose(fwrite);
  
  return EXIT_SUCCESS;
}
