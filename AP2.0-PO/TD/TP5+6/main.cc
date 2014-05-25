#include <iostream>
#include <cstdlib>
#include <typeinfo>

#include "Screen.h"
#include "Point.h"

#include "Shape.h"
#include "Line.h"
#include "LineBrok.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"
#include "Circle.h"

#include "util.h"
#include "DessinShapes.h"

void menu()
{
  cout << "****************************************************" << endl
       << "*   1. Ligne          3. Rectangle   5. Triangle   *" << endl
       << "*   2. Ligne cassee   4. Carre       6. Cercle     *" << endl
       << "*                                                  *" << endl
       << "*   c. Colorer tout       x. Colorer une           *" << endl
       << "*   d. Deplacer tout      y. Deplacer une          *" << endl
       << "*   e. Effacer tout       z. Effacer une           *" << endl
       << "*                                                  *" << endl
       << "*   r. Modifier Rayon                q. Quitter    *" << endl
       << "****************************************************" << endl
       << endl;
}

char saisieChoix()
{
  char choix;
  do {
    cin >> choix;
  } while(    !( choix>='1' && choix<='6') 
	      && !( choix>='c' && choix<='e')
	      && !( choix>='x' && choix<='z')
	      && choix !='r'
	      && choix !='q' );
  return choix;
}

int main()
{
  Screen ecran;

  // Pour stocker et gerer toutes les formes
  DessinShapes dessin;

  // POUR FACILITER LES TESTS
  //dessin.addShape( new Line(black, Point(4,5), Point(15,22)) );  
  //dessin.addShape( new LineBrok( red, Point(20,25), Point(30,30), Point(27,15) ) );
  //dessin.addShape( new Rectangle( green, Point(20,20), Point(10,10) ) );
  //dessin.addShape( new Circle( blue, Point(40,30), 5 ) );
  //dessin.refresh( ecran );

  int ind;
  int my_dx, my_dy;
  int rayon;
  char col;
  int l;
  Point p1,p2,p3;
  char choix;
  do {
    menu();
    choix = saisieChoix();
    switch( choix ) {      
    case '1': // Line
      cinLine(col,p1,p2);
      dessin.addShape( new Line(col, p1, p2) );
      dessin.refresh(ecran);
      break;

    case '2': // LineBrok
      cinPoint(p1);
      cinPoint(p2);
      cinPoint(p3);
      cinColour(col);
      dessin.addShape( new LineBrok(col, p1, p2, p3) );
      dessin.refresh(ecran);
      break;

    case '3': // Rectangle
      cinColour(col);
      cinPoint(p1);
      cinPoint(p2);
      dessin.addShape( new Rectangle(col, p1, p2) );
      dessin.refresh(ecran);
      break;

    case '4': // Carre
      cinColour(col);
      cinPoint(p1);
      cout << "Longueur d'un cote : ";
      cin >> l;
      dessin.addShape( new Square(col, p1, l) );
      dessin.refresh(ecran);
      break;

    case '5': // Triangle
      cinColour(col);
      cinPoint(p1);
      cinPoint(p2);
      cinPoint(p3);
      dessin.addShape( new Triangle(col, p1, p2, p3) );
      dessin.refresh(ecran);
      break;

    case '6': // Cercle
      cinColour(col);
      cinPoint(p1);
      cout << "Rayon : ";
      cin >> rayon;
      dessin.addShape( new Circle(col, p1, rayon));
      dessin.refresh(ecran);
      break;

    case 'c': // Colorer tout
      cinColour(col);
      dessin.setColourAll(col);
      dessin.refresh(ecran);
      break;

    case 'd': // Deplacer tout
      ecran.clear();
      cout << "Dx puis Dy : ";
      cin >> my_dx >> my_dy;
      dessin.moveAll(my_dx,my_dy);
      dessin.refresh(ecran);
      break;

    case 'e': // Effacer tout
      dessin.eraseAll();
      ecran.clear();
      dessin.refresh(ecran);
      break;

    case 'x': // Colorer une
      /* 
      // Utiliser des indices
      cinPosition(ind);
      cinColour(col);
      dessin.setColourOne_1(ind, col);
      dessin.refresh(ecran);
      */     

      // Utiliser des points appartenant a forme
      cinPoint(p1);
      cinColour(col);
      dessin.setColourOne(p1,col);
      dessin.refresh(ecran);
      break;

    case 'y': // Deplacer une
      /*
      // Utiliser des indices
      cinPosition(ind);
      cout << "Dx puis Dy : ";
      cin >> my_dx >> my_dy;
      dessin.moveOne_1(ind, my_dx, my_dy);
      ecran.clear();
      dessin.refresh(ecran);
      */

      // Utiliser des points appartenant a forme
      cinPoint(p1);
      cout << "Dx puis Dy : ";
      cin >> my_dx >> my_dy;
      dessin.moveOne(p1,my_dx,my_dy);
      ecran.clear();
      dessin.refresh(ecran);
      break;

    case 'z': // Effacer une
      /*
      // Utiliser des indices      
      cinPosition(ind);
      dessin.eraseOne(ind);
      ecran.clear();
      dessin.refresh(ecran);
      */

      // Utiliser des points appartenant a forme
      cinPoint(p1);
      dessin.eraseOne(p1);
      ecran.clear();
      dessin.refresh(ecran);
      break;

    case 'r': // Modifier le rayon      
      cinPosition(ind);
      cout << "Entrez le nouveau rayon : ";
      cin >> rayon;
      dessin.modifierRayon(ind,rayon);
      ecran.clear();
      dessin.refresh(ecran);
      break;

    case 'q': // Quitter
      cout << "Bye" << endl;
      break;

    }
  } while( choix !='q' );
  
  return EXIT_SUCCESS;
}

