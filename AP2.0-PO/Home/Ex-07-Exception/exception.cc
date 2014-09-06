#include <iostream>
#include <stdexcept>
#include <cstdlib>

using namespace std;

int something( int x, int y )
{
  if( y == 0 )
    {
      logic_error description("Division par zero.\n");
      throw description;
    }
  
  return ( x/y );
}

int main()
{
  int x = 3, y = 0;
  something( x, y );

  return EXIT_SUCCESS;
}
