#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
  int i;
  printf("Ceci est mon programme %s avec %d arguments.\n", argv[0], argc);
  
  for (i = 0 ; i < argc ; i++)
    printf("argv[%d]=%s\n", i, argv[i]);

  return EXIT_SUCCESS;
}
