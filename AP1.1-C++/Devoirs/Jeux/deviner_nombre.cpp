#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <termios.h>
using namespace std;


/* ===== METHODE 1 : UTILISER LES NOMBRES BINAIRES ===== */

/*int calculer_nombre(int nombre, int b, char repondre);

int main()
{
  int nombre = 0;

  char repondre;
  
  cout << "Liste 1 : 1   3   5   7   9" << endl
       << "Liste 2 : 2   3   6   7"     << endl
       << "Liste 3 : 4   5   6   7"     << endl
       << "Liste 4 : 8   9"             << endl;

  for (int i = 0 ; i <= 3 ; i++) {
    cout << "Votre nombre est-il dans la liste " << i + 1 << " ?  "; cin >> repondre; 
    nombre = calculer_nombre(nombre, i, repondre);
  }

  cout << "Votre nombre est " << nombre << endl;
}


int calculer_nombre(int nombre, int b, char repondre)
{
  switch(repondre) {
  case 'y' :
    nombre = nombre + 1 * pow(2,b);
    break;
  case 'n' :
    break;
  }
  return nombre;
}
*/

/*************************************************************************************************************/

/* ===== METHODE 2 : DIVISER LES POSSIBILITES EN MOITIE ===== */

int main()
{
  char c;

  cout << "Est-ce que votre nombre est >= 5 ? : " ;
  cin >> c;

  srand (time(NULL));

  if (c == 'y') 
    {
      cout << "Est-ce que votre nombre est >= 7 ? : " ;
      cin >> c;

      if (c == 'y') 
	{
	  cout << "Est-ce que votre nombre = 7 ? : ";
	  cin >> c;

	  if (c == 'y')
	    cout << "Votre nombre est 7" << endl;
	  else if (c == 'n')
	    cout << "Votre nombre est " << rand() % 2 + 8 << endl;
	}

      else if (c == 'n')
	{ 
	  cout << "Est-ce que votre nombre = 5 ? : ";
	  cin >> c;

	  if (c == 'y')
	    cout << "Votre nombre est 5" << endl;
	  else if (c == 'n')
	    cout << "Votre nombre est 6" << endl;
	}
    }

  else if (c == 'n')
    {
      cout << "Est-ce que votre nombre >= 2 ? : ";
      cin >> c;
      
      if (c == 'y')
	{
	  cout << "Est-ce votre nombre = 2 ? : ";
	  cin >> c;

	  if (c == 'y')
	    cout << "Votre nombre est 2" << endl;
	  else if (c == 'n')
	    cout << "Votre nombre est " << rand() % 2 + 3 << endl;
	}
    
      else if (c == 'n')
	{
	  cout << endl << "Est-ce que votre nombre = 0 ? : ";
	  cin >> c;

	  if (c == 'y')
	    cout << "Votre nombre est 0" << endl;
	  else if (c == 'n')
	    cout << "Votre nombre est 1" << endl;
	}
    }
}
    
    
  
  
