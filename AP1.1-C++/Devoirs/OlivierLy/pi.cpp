#include <iostream>
#include <math.h>
using namespace std;


int main()
{
  float Ax = 1.0/2.0, Ay = sqrt(3.0)/2.0, Bx = 1, By = 0, Hx, Hy, h, bas,aire, pi;
  int N = 6;

  int n;
  cout << "Le nombre de tours = " ; cin >> n;

  for (int i = 1 ; i <= n ; i ++) //pas de "i" dans le corps de FOR, "i" ici indique le nombre de fois qu'on va repeter l'action re-calculer N, Ax, Ay 
    { Hx = 0.5 * (Ax + 1); Hy = 0.5 * Ay;
      h = sqrt(Hx*Hx + Hy*Hy);
      bas = sqrt(pow(Ax - 1,2) + pow(Ay,2));
      aire = 0.5 * h * bas;
      pi = N * aire;
      N *= 2;
      Ax = 1.0/h * Hx; //bien qu'ayant attribuee d'1 valeur 0.5 dans le float au debut, ce Ax n'est pas invariable, elle es en fait toujour une VARIABLE, et 0.5 n'est qu'une de ses valeurs 
      Ay = 1.0/h * Hy;
      cout << "pi(" << i << ") = " << pi << endl; }
}
