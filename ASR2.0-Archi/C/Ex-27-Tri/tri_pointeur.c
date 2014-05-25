#include <stdio.h>
#include <stdlib.h>

void trier(int *pt) {
  int i, j, temp;

  for (i=0 ; i<2 ; i++) {
    for (j=i+1 ; j<3 ; j++) {
      if ( *(pt+i) > *(pt+j) ) {
	temp = *(pt+i);
	*(pt+i) = *(pt+j);
	*(pt+j) = temp;
      } 
    }
  }
 
  for (i=0 ; i<3 ; i++)
    printf("%d ", *(pt+i) );
  
  printf("\n");
}

int main() {
  int *p, i;

  printf("Entrez 3 nombres : ");
  for (i=0 ; i<3 ; i++)
    scanf("%d", p+i );

  trier(p);
  
}
