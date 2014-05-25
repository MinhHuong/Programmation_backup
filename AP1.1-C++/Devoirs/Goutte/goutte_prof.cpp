#include <iostream>
#include <math.h>
#include <cstdlib> 
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
using namespace std;

#define N 20
#define NBRE_GOUTTE 2

bool touche_appuyee(); // fonction de type "bool"

char screen[N][N]; // le tableau 2 dimensions de type "char"

void paysage(); 
void affiche_screen();

typedef struct {
  double x; // la position de la goutte dans les colonnes (elle est sur une ligne)
  double y; // la position _________________ les lignes   (elle est sur une colonne)

  double dx; // la vitesse avec laquelle  la goutte se deplace verticalement
  double dy; // la vitesse ___________________________________ horizontalement

} Sprite; // nouveau type appele "Sprite" qui se compse de 4 variables : x, y, dx, dy

void init_sprite(Sprite & s, double x, double y, double dx, double dy);
void mise_a_jour_sprite(Sprite & s); 

//Sprite s : variable dont le nom est "s" et le type "Sprite", chaque petite variable contenue dedans s'appelle s.x, s.y, s.dx, s.dy

int main () {
  Sprite goutte[NBRE_GOUTTE]; // le tableau nomme "goutte", de type "Sprite" et de dimension [NBRE_GOUTTE] = 2
                              // car on a besoin d'afficher 2 gouttes dans ce programme
  
  init_sprite(goutte[0], 4, 5, 0.0, 0.3); // la goutte qui se deplace, sa position originale est Ligne 4, Colonne 5
  // Coordonnes de la 1e goutte           // au debut, elle se deplace seuleM dans les Colonnes de la meme Ligne
                                          // (Horizontalement)

  init_sprite(goutte[1], 6, 8, 0, 0);     // la goutte qui est immobile (dx = 0 && dy = 0)
  // Coordonnees de la 2e goutte          // sa position originale est Ligne 6, Colonne 8

  for (int t=0; t<1000; t++) // "t" ? Le nombre de fois qu'on utilise le clavier pour controler 1 des 2 gouttes ? 
  {
    system ("stty raw"); 
    usleep(40 * 1000);

    if (touche_appuyee()) {
      char c = getchar(); 
      system ("stty cooked");
      
      switch (c) { // ces codes controlent le mouvement (descendre/monter) de la goutte
      case 'a':
        goutte[0].dx = 0.3;  // dy = 0.3, dx =  0.3  --> la goutte descend
        break;
      case 'b':
        goutte[0].dx = -0.3; // dy = 0.3, dx = -0.3 --> la goutte monte
        break;
      case 13:
        system ("stty cooked");
        exit(0); // on saisit une touche de clavier, ces commandes l'examinent, la font entrer dans l'ordinateur, la
      }          // traitent et puis affichent des informations selon la structure "switch() case: ..."
    }

    system ("stty cooked"); // faute de cette ligne le programme marche avec des erreurs. Pourquoi ? 

    paysage();

    for (int g=0; g<NBRE_GOUTTE; g++) // "g" pour les gouttes, ici on en a 2 (NBRE_GOUTTE = 2) 
      screen[(int) goutte[g].x][(int) goutte[g].y] = 'O'; //afficher la goutte dans le cadre
             //ds la colonne    //ds la ligne             // on fait une affectation du type : de "double" a "int"
 
    affiche_screen(); // Il est OBLIGE de placer la procedure "affiche_screen" ici, pour que les boules puissent etre
                      // affichee avec le cadre

    for (int g=0; g<NBRE_GOUTTE; g++)// la 1ere goutte g[0] ; la 2e goutte g[1]
      mise_a_jour_sprite(goutte[g]); // c'est cette commande qui decide le mouvement des 2 gouttes
                                     
  }
}


void init_sprite(Sprite & s,double x,double y,double dx,double dy) 
{ s.x = x; // "s.x" est le nom de la variable qui a la valeur equivalente de celle de "x"
  s.y = y;
  s.dx = dx;
  s.dy = dy; } // attribuer a s.dy (Sprite s) la valeur de dy equivalente 


void mise_a_jour_sprite(Sprite & s) 
{ s.x += s.dx; // pour modifier la position verticale de la goutte
  s.y += s.dy; // _________________________ horizontale 
  
  /* (1) Le cas de la goutte immobile: dx = dy = 0 alors si on effectue s.x += s.dx (meme pour y), ca n'influence pas
     a la position de cette goutte, ses valeurs s.x && s.y sont toujours = 0. Elle reste immobile. 

     (2) Le cas de la goutte qui bouge : la valeur s.dx et s.dy decident la vitesse de la goutte. Plus dx est grande,
     plus la vitesse est rapide. Explication :
 
     - Si dx = 0.3, il a besoin plus de "+ 0.3" pour que la goutte saute a une autre position a chaque mise a jour. 
     Par ex : la distance est 1.0, or x += dx et dx = 0.3 --> pour que la goutte traverse cette distance, il faut 
     environ "0.3 + 0.3 + 0.3" ~ 1

     - Tandis que dx = 1.0 - plus grand que 0.3, il prend moins de temps pour traverser cette distance  */ 	
	

  if (s.x < 0) s.x = N-1; // ces conditions servent a retourner la goutte ds le cadre pour qu'elle ne disparaisse pas
  
  if (s.x > N-1) s.x = 0; // la goutte est au bord, il faut la faire re-apparaitre au bord oppose du cadre en  
                          // attribuant 1 nouvelle valeur de s.x (s.x = 0)
  if (s.y < 0) s.y = N-1;
  if (s.y > N-1) s.y = 0; }


void paysage() {
  for (int i=0; i<N; i++)
    for (int j=0; j<N; j++)
      if (i==0 || i==N-1 || j==0 || j==N-1)
        screen[i][j] = '#'; // attribuer les valeurs (les caracteres) aux elements du tableau screen[i][j]
      else
        screen[i][j] = ' ';
}


void affiche_screen() {
  system("clear");
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++)
      cout << screen[i][j]; // utiliser les valeurs(caracteres) attribuees ci-dessus pour dessiner la cadre
    cout << endl;
  } 
}


bool touche_appuyee()  // je n'ai aucune idee sur cela 
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
