#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <termios.h>
using namespace std;


/* =================================================================================================== */


/* 1) --- CIN PLUSIEURS VARIABLES A LA FOIS --- 
int main()
{
  int a,b;
  cout << "Entrez a, b = " ;
  cin >> a >> b;
  cout << "a = " << a << endl << "b = " << b << endl;
}
*/


/* =================================================================================================== */


/* 2) --- UTILISER LE CHAR AVEC ' ' OU PAS ---
int main ()
{
  int N;
  cout << "Entez N = " ; cin >> N;
  char a = N;
  cout << "a = " << a << endl; // il va afficher un mot code par ASCII

  char a = 'P';
  cout << "a = " << a << endl; // il va afficher directement ce mot (P)
}
*/


/* ==================================================================================================== */


/* 3) --- CONVERTIR LA TEMPERATURE DE FAHRENHEIT EN CELCIUS ---
int main()
{
  float F,C;
  cout << "Entrez la temperature en Fahrenheit = " ; cin >> F;
  C = 5.0/9.0 * (F - 32.0);
  cout << F << " degree en Fahrenheit = " << C << " degree en Celcius" << endl;
}
*/


/* ==================================================================================================== */


/* 4) --- VERIFIER SI N EST UN NOMBRE PAIR OU IMPAIR (SANS UTILISER IF...ELSE) --- 
int main()
{
  int n;
  cout << "Entrez n = " ; cin >> n;
  ( n % 2 == 0) ? cout << "n est pair \n" : cout << "n est impair \n";
}
*/


/* ==================================================================================================== */


/* 5) --- VERIFIER UN NOMBRE EST SOIT IMPAIR ET POSITIF, SOIT PAIR ET NEGATIF --- 

int main()
{
  int N;
  cout << "Entrez N = " ; cin >> N;
  
  if (N % 2 == 1 || N % 2 == -1) // N % 2 == -1, car il s'agit d'un nombre negatif
    { if (N > 0)
	cout << "N est impair et positif" << endl;
      else 
	cout << "Nope" << endl; }
  else 
    { if (N > 0)
	cout << "Nope" << endl;
      else
	cout << "N est pair et negatif" << endl; }
}
*/


/* ==================================================================================================== */


/* 6) --- VERIFIER SI LE CARACTERE SAISI EST UN NOMBRE OU UN CARACTERE --- 
int main()
{
  char a; // Principe utilise : le type "char" et le code de ASCII
  cout << "Entrez a = " ; cin >> a;

  if (int(a) >= 48 && int(a) <= 57) // int(a) pour obtenir la valeur decimale equivalente au caractere "char" dans le tableau ASCII  
    cout << "a est un nombre" << endl;

  else if ((int(a) >= 65 && int(a) <= 90) || (int(a) >= 97 && int(a) <= 122))
    cout << "a est un caractere" << endl;

  else 
    cout << "Nope" << endl;
}
*/


/* ==================================================================================================== */


/* 7) --- CALCULER LA VALEUR ABSOLUE D'UN NOMBRE ---

*** METHODE 1 : ***
int main()
{
  float N;
  cout << "Entrez N = " ; cin >> N;
  cout << "La valeur absolue de N = " << abs(N) << endl;
}


*** METHODE 2 ***
int main()
{
  int N;
  cout << "Entrez N = " ; cin >> N;
  if (N > 0)
    cout << "La valeur absolue de N = " << N << endl;
  else if (N < 0)
    cout << "La valuer absolue de N = " << N*-1 << endl;
  else 
    cout << "La valeur absolue de N = " << 0 << endl;
}
*/


/* ==================================================================================================== */


/* 8) --- CALCULER LA LONGUEUR D'UNE CHAINE DE CARACTERES --- 
int main()
{
  string a;
  cout << "Entrez a = " ; cin >> a;
  cout << a.length() << endl;
}
*/


/* ==================================================================================================== */


/* 9) --- CALCULER LA VALEUR DE 2^N ET N^2 (N EST ENTIERE ET POSITIVE) ---
int main()
{
  unsigned int N;
  cout << "Entrez N = " ; cin >> N;
  cout << "N^2 = " << pow(N,2) << " et 2^N = " << pow(2,N) << endl;
}
*/


/* ==================================================================================================== */


/* 10) --- VERIFIER SI LES NOMBRES SONT TRIES OU NON ---

*** METHODE 1 : ***
int main()
{
  int a,b,c;
  cout << "Entrez a, b, c = " ; cin >> a >> b >> c ;
  a < b ? (b < c ? cout << "Sorted \n" : cout << "Not sorted \n") : cout << "Not sorted \n" ;
}



*** METHODE 2 ***
int main ()
{
  int a,b,c;
  cout << "Entrez a,b,c = " ; cin >> a >> b >> c ;
  if ( a < b && b < c ) cout << "Sorted" << endl;
  else if ( a > b && b > c) cout << "Not sorted" << endl;
  else cout << "Nope" << endl;
}
*/


/* ==================================================================================================== */


/* 11) --- UTILISATION DE LA BOUCLE "WHILE" ---
int main()
{
  int N;
  cout << "Entrez N = "; cin >> N;

  int somme = 0;
  int i = 1; 
  while (i <= N)
    { somme += i;
      i++; }

  cout << "Somme(" << N << ") = " << somme << endl;
}
*/


/* ==================================================================================================== */


/* 12) --- INDIQUER LA POSITION D'UN NOMBRE DANS LE TABLEAU ---
int main()
{
  int tab[5] = {1,2,3,4,5};
  int position,nombre;
  bool trouver = false;

  cout << "Entrez le nombre = " ; cin >> nombre;

  int i = 0 ;
  while (trouver == false && i < 5)
    { if (tab[i] == nombre)
	{ position = i ;
	  trouver = true; }
      i++; }
  
  if (trouver == true)
    cout << "La position de " << nombre << " dans le tableau est tab[" << position << "]" << endl;
  else
    cout << nombre << " n'est pas presente dans ce tableau" << endl;
}
*/


/* ==================================================================================================== */


/* 13) --- INDIQUER LA POSITION D'UN NOMBRE DANS UN TABLEAU DE 2 DIMENSIONS ---
int main()
{
  int tab[2][5] = {1,2,3,4,5,
		   6,7,8,9,10};
  int positionL,positionC,nombre;
  bool trouver = false;

  cout << "Entrez le nombre = " ; cin >> nombre;
  
  int i = 0 ;
  int j = 0 ;
  while (trouver == false && i < 2)
    { while (trouver == false && j < 5)
	{ if (tab[i][j] == nombre) 
	    { trouver = true;
	      positionC = j;
	      positionL = i; }
	  j++; }
      i++;
      j = 0; } // j = 0 pour commencer une nouvelle examination des nombres a la 1ere colonne de la ligne suivante 
  
  if (trouver = true)
    cout << "La position de " << nombre << " dans ce tableau est tab[" << positionL << "]" << "[" << positionC << "]" << endl;
  else
    cout << nombre << " n'est pas presente dans ce tableau" << endl;
}
*/


/* ==================================================================================================== */


/* 14) --- LE PROBLEME DE TROUVER LE NOMBRE DE POULES ET DE CHIENS ---
int main()
{
  int poule,chien;
  
  for (poule = 0 ; poule < 36 ; poule++)
    { for (chien = 0 ; chien < 25 ; chien++)
	{ if (poule * 2 + chien * 4 == 100 && poule + chien == 36)
	    cout << "Le nombre de poules = " << ga << ", et de chien = " << cho << endl; }
    }
    } */


/* ==================================================================================================== */


/* 15) --- AFFICHER LE CADRE ET LES GOUTTES QUI BOUGENT ---

/*#define N 20
#define NOMBRE_GOUTTE 2


char screen[N][N];


typedef struct 
{ double x;
  double y;
  double dx;
  double dy; } Sprite;


bool touche_appuyee ();


void init_goutte (Sprite & s, double x, double y, double dx, double dy);
void mouvement_goutte (Sprite & s);
void paysage ();
void affichage_screen ();



int main() 
{
  Sprite goutte[NOMBRE_GOUTTE];
  init_goutte (goutte[0], 4, 5, 0.0, 0.3);
  init_goutte (goutte[1], 6, 8, 0.5, 0);

  for (int t = 0 ; t < 2000 ; t++)  
    { system("stty raw");          
      usleep (40 * 1000);
      
      if (touche_appuyee())
	{ char c = getchar();
	  system("stty cooked"); 

	  switch (c)
	    { case 'q':
		goutte[0].dx =  0.3; // la boule descend
		break;
	      case 'a' :
		goutte[0].dx = -0.3; // la boule monte
		break;
	      case 'z':
		goutte[0].dx = 0.0; // la boule retourne a son mouvement original
		break;
	      case 'w':
		goutte[1].dy =  0.5;
		break;
	      case 's':
		goutte[1].dy = -0.5;
		break;
	      case 'x':
		goutte[1].dy =  0.0;
		break;
	      case 13 :
		//system("stty cooked"); // pourquoi a-t-on besoin system("stty cooked") ici ? 
		exit(0); }
	}

      system ("stty cooked"); // A quoi sert cett ligne exactement ? Sans elle, le programme marche avec des erreurs

      paysage ();

      for (int g = 0 ; g < NOMBRE_GOUTTE ; g++)
	screen[(int) goutte[g].x][(int) goutte[g].y] = '0';
      
      affichage_screen ();

      for (int g = 0 ; g < NOMBRE_GOUTTE ; g++)
	mouvement_goutte (goutte[g]);
      
    }
}



void paysage ()
{
  for (int i = 0 ; i < N ; i++)
    { for (int j = 0 ; j < N ; j++)
	if (i == 0 || j == 0 || i == N - 1 || j == N - 1)
	  screen[i][j] = '#';
	else
	  screen[i][j] = ' '; }
}



void affichage_screen ()
{
  system("clear");
  for (int i = 0 ; i < N ; i++)
    { for (int j = 0 ; j < N ; j++)
	cout << screen[i][j]; // meme pour le cadre et les boules
      cout << endl; }
}



void init_goutte (Sprite & s, double x, double y, double dx, double dy)
{ s.x = x;
  s.y = y;
  s.dx = dx;
  s.dy = dy; }



void mouvement_goutte (Sprite & s)
{ s.x += s.dx;
  s.y += s.dy;

  if (s.x > N - 1) 
    s.x = 0;

  if (s.x < 0) 
    s.x = N - 1;

  if (s.y > N - 1)
    s.y = 0;

  if (s.y < 0)
    s.y = N - 1; }


bool touche_appuyee () 
{
  struct timeval tv;
  fd_set fds;
  tv.tv_sec = 0;
  tv.tv_usec = 0;
  FD_ZERO(&fds);
  FD_SET(STDIN_FILENO, &fds);
  select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
  return (FD_ISSET(0, &fds));
} 
*/

/* ==================================================================================================== */

/* --- 16) ESTIMER L'ETAT PHYSIQUE D'UNE PERSONNE EN BASANT SUR LEUR POIDS & LEUR HAUTEUR ---

int main()
{
  double weight,height;
  cout << "Enter your height = "; cin >> height;
  cout << "Enter your weight = "; cin >> weight;

  if (weight < height/2.5)
    cout << "You're underweight" << endl;
  else if (height/2.5 <= weight && weight <= height/2.3)
    cout << "You're normal" << endl;
  else
    cout << "You're overweight" << endl;
}
*/

/* ==================================================================================================== */

/* --- 17) AFFICHER LA DATE --- */ 

/*int main()
{
  string jour, annee;
  string mois;
  
  string mois_nombre[12] = {"1","2","3","4","5","6","7","8","9","10","11","12"};
  string mois_mot[12] = {"Janvier","Fevrier","Mars","Avril","Mai","June",
			 "Juillet","Aout","Septembre","Octobre","Novembre","Decembre"};
  
  cout << "Entrez le jour, le mois, l'annee = " ; cin >> jour >> mois >> annee;

  for (int i = 0 ; i < 12 ; i++)
    if (mois == mois_nombre[i]) //mois_nombre[i] garde encore ses valeurs 1, 2, 3...
      { for(int j = 0 ; j < 12 ; j++)
	  if (i == j)
	    mois_nombre[i] = mois_mot[j]; //on attribue les mois en caracteres equivalents avec ceux en nombre
	                                  //desormais le mois_nombre[i] garde les valeurs Janvier, Fevrier...
	cout << mois_nombre[i] << " " << jour << ", " << "19" << annee << endl; } 
	}*/

/* ==================================================================================================== */

/* --- 18) LA FACTORIELLE - UTILISER LA FONCTION RECURSIVE --- 

int fact(int n)
{
  if (n <= 1) return 1;
  else 
    return n * fact(n - 1); // n * (n - 1)!
  return fact(n); 
}


int main()
{
  int N;
  cout << "Entrez 1 nombre entier = " ; cin >> N;

  if (N >= 0)    
    cout << "Fact(" << N << ") = " << fact(N) << endl;
  else 
    cout << "N doit etre positif ou au moins egal a 0 " << endl;
}
*/


/* ==================================================================================================== */

/* --- 19) TROUVER LE MAXIMUM, LE MINIMUM PARMI LES NOMBRES SAISIS --- */

/* a/ Exemple precis : La temperature */

/*int main()
{
  double temp, temp_moyenne;
  double temp_max   = -99;
  double temp_min   =  99;
  double temp_somme =   0;

  int N;
  cout << "Entrez N = " ; cin >> N;
  
  for (int i = 1 ; i <= N ; i++)
    { cout << "Entrez la temperature = " ; 
      cin >> temp; 
      
      if (temp > temp_max)
	temp_max = temp;

      if (temp < temp_min)
	temp_min = temp; 

      temp_somme += temp; }

  cout << "La temperature maximales = " << temp_max << endl;
  cout << "La temperature minimale = " << temp_min << endl;
  cout << "La temperature moyenne = " << temp_somme/N << endl;  
}
*/

/* b/ Cas general */

/* METHODE 1 int main()
{
  int N;
  cout << "Entrez N = " ; cin >> N;

  int nombre[N];
  int max, min, moyen;
  int somme = 0 ; 

  for (int i = 1 ; i <= N ; i++)
    {
      cout << "nombre[" << i << "] = " ; cin >> nombre[i];
      max = min = nombre[1]; //on suppose que le max & min = nombre[1]

      for (int j = 2 ; j <= N ; j++) //on commence a comparer les nombres depuis nombre[2] -> nombre[N]
	{ if (nombre[j] > max)
	    max = nombre[j];
	  
	  if (nombre[j] < min)
	    min = nombre[j]; }
	  
      somme += nombre[i];
    }

  cout << "Le nombre maximal = " << max << endl;
  cout << "Le nombre minimal = " << min << endl;
  cout << "Le moyen = " << somme/N << endl;
}
*/

/* METHODE 2 */

/*
int main()
{
  int a,b,c;
  cout << "Entrez a = " ; cin >> a;
  cout << "Entrez b = " ; cin >> b;
  cout << "Entrez c = " ; cin >> c;
  
  int max,min;

  max = a > b ? a : b;
  max = max > c ? max : c;
  cout << "Le nombre maximal = " << max << endl;

  min = a < b ? a : b;
  min = min < c ? min : c;
  cout << "Le nombre minimal = " << min << endl;
}
*/

/* ==================================================================================================== */

/* --- 20) CHUYEN TU CO SO 2/8/16 SANG HE THAP PHAN --- */
 
/* CO SO 8 

int main()
{
  char nb_8[3]; //utiliser CHAR pour que les chiffres soient affichees succesivement 
                //si on utilise INT, entre les chiffres il faut 1 espace

  cout << "So co so 8 = " ; cin >> nb_8[0] >> nb_8 [1] >> nb_8[2];

  cout << "So co so 10 = " << ((int) nb_8[0] - 48) * 8 * 8 + ((int) nb_8[1] - 48) * 8 + ((int) nb_8[2] - 48) << endl;
  //convertir de valeur INT de CHAR a valeur INT de DECIMALE   
}

*/


/* CO SO 16

int main()
{
  char nb_16[2];
  cout << "So co so 16 = " ; cin >> nb_16[0] >> nb_16[1];
  
  
  int caractere;
  switch (nb_16[0]) {
  case 'a' :
  case 'A' :
    caractere = 10;
    break;
  case 'b' :
  case 'B' :
    caractere = 11;
    break;
  case 'c' :
  case 'C' :
    caractere = 12;
    break;
  case 'd' :
  case 'D' :
    caractere = 13;
    break;
  case 'e' :
  case 'E' :
    caractere = 14;
    break;
  case 'f' :
  case 'F' :
    caractere = 15;
    break; }


  int nombre;
  switch (nb_16[1]) {
  case '1' :
    nombre = 1;
    break;
  case '2' :
    nombre = 2;
    break;
  case '3' :
    nombre = 3;
    break;
  case '4' :
    nombre = 4;
    break;
  case '5' :
    nombre = 5;
    break;
  case '6' :
    nombre = 6;
    break;
  case '7' :
    nombre = 7;
    break;
  case '8' :
    nombre = 8;
    break;
  case '9' :
    nombre = 9;
    break; }
  
  cout << "So thap phan = " << caractere * 16 + nombre << endl;
}
*/


/* HE THAP PHAN --> HE NHI PHAN 

int main()
{
  int nb_10;
  cout << "So he thap phan = " ; cin >> nb_10;

  int nb_2[10];

  do
    { for (int i = 0 ; i < 10 ; i++)
       { switch (nb_10 % 2) {
 	 case 1 :
	   nb_2[i] = 1;
	   break;
	 case 0 :
	   nb_2[i] = 0;
	   break;
	 }
	 cout << "So nhi phan = " << nb_2[i] << endl;
       }
    }
  while (nb_10 == 1 || nb_10 == 0);
}
*/

/* ==================================================================================================== */

/* --- 21) AFFICHER LE TABLEAU DE MULTIPLICATION --- */

/* int main()
{
  int N ;

  for (int i = 1 ; i <= 9 ; i++)
    { for (int j = 1 ; j <= 9 ; j++)
	cout << i << " * " << j << " = " << i*j << endl; 
      cout << endl; }
}
*/


/* ==================================================================================================== */

