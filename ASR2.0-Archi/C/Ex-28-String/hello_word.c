#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  char *pt;
  char message[]="Hello World !";
  
  for (pt=message ; *pt != '\0' ; pt++)
    printf("%c", *pt);
  printf("\n");
  
  for (pt=message ; *pt != '\0' ; pt++) {
    if ( isupper(*pt) != 0)
      printf( "%c", tolower(*pt) );
    else if ( islower(*pt) != 0)
      printf( "%c", toupper(*pt) );
    else
      printf( "%c", *pt);
  }
  
  return EXIT_SUCCESS;
}
