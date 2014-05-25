#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <termios.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
using namespace std;

/********************************************* -----CONSTANTS----- ************************************************/
#define BALLE_TAILLE 36
#define BALLE_DX 10
#define BALLE_DY 10

#define GALLET_LONG 32
#define GALLET_LAR 120
#define V_GALLET 3

#define ECRAN_LONG 1024
#define ECRAN_LAR 640


SDL_Surface *screen = NULL;
SDL_Surface *galletG = NULL;
SDL_Surface *galletD = NULL;
SDL_Surface *balle = NULL;
SDL_Surface *background = NULL;


typedef struct Sprite {
  int x, y;
  int dx, dy;
} banh, thanh;

static banh balleMoi;
static thanh galG, galD;

/********************************************* -----FONCTIONS----- ************************************************/

void init_elem() {
  balleMoi.x = ECRAN_LONG/2;
  balleMoi.y = ECRAN_LAR/2;
  balleMoi.dx = BALLE_DX;
  balleMoi.dy = BALLE_DY;

  galG.x = 70;
  galG.y = 120;
  galG.dx = 0;
  galG.dy = 5;

  galD.x = ECRAN_LONG - 70 - GALLET_LONG;
  galD.y = 120;
  galD.dx = 0;
  galD.dy = 5;
}

//le mouvement de la balle : la balle se deplace, touche les murs
void mouvementBalle(SDL_Rect & balle, int & balle_dx, int & balle_dy) {
  balle.x += balle_dx;
  balle.y += balle_dy;

  if (balle.x > ECRAN_LONG - BALLE_TAILLE || balle.x < 1) {
    //balle_dx *= -1;
    usleep(50*10000);
    balle.x = ECRAN_LONG/2;
    balle.y = ECRAN_LAR/2;
  }
  
  if (balle.y > ECRAN_LAR - BALLE_TAILLE || balle.y < 1)
    balle_dy *= -1;
}


//la balle touche les gallets et rebondit
void balleGallet(SDL_Rect balle, SDL_Rect gauche, SDL_Rect droite, int & v_balle) {
  if ((balle.x <= gauche.x + GALLET_LONG &&
       balle.y >= gauche.y &&
       balle.y <= gauche.y + GALLET_LAR) ||
      (balle.x >= droite.x - GALLET_LONG &&
       balle.y >= droite.y &&
       balle.y <= droite.y + GALLET_LAR))
    v_balle *= -1;
}


//limiter l'espace de deplacement des gallets
void limiteGallet(SDL_Rect & gauche, SDL_Rect & droite) {
  if (galG.y < 0)
    galG.y = 0;

  if (galG.y > ECRAN_LAR - GALLET_LAR)
    galG.y = ECRAN_LAR - GALLET_LAR;

  if (galD.y < 0)
    galD.y = 0;

  if (galD.y > ECRAN_LAR - GALLET_LAR)
    galD.y = ECRAN_LAR - GALLET_LAR;    
}


void controlGalletG() {
  Uint8 *keystates = SDL_GetKeyState(NULL);
    
  if (keystates[SDLK_UP]) 
    galG.y -= galG.dy;

  else if (keystates[SDLK_DOWN])  
    galG.y += galG.dy; 
}


void controlGalletD() {
  Uint8 *keystates = SDL_GetKeyState(NULL);
    
  if (keystates[SDLK_a]) 
    galD.y -= galD.dy;

  else if (keystates[SDLK_z])  
    galD.y += galD.dy; 
}


SDL_Surface *xulyhinh (string filename)
{
  SDL_Surface* hinh = NULL;
  SDL_Surface* ep_hinh = NULL;
  hinh = SDL_LoadBMP( filename.c_str() );
  if( hinh != NULL )
  {
    ep_hinh = SDL_DisplayFormat( hinh );
    SDL_FreeSurface( hinh);
    if( ep_hinh != NULL )
      SDL_SetColorKey( ep_hinh, SDL_SRCCOLORKEY, SDL_MapRGB( ep_hinh->format, 0, 0xFF, 0xFF ) );
  }
  return ep_hinh;
}


bool nhan_hinh()
{
    background = xulyhinh( "background.bmp" );
    galletG = IMG_Load("candyGauche.png");
    galletD = IMG_Load("candyDroite.png");
    balle = IMG_Load("balle.png");
    if( background == NULL )
      return false;
    if( galletG == NULL )
      return false;
    if( galletD == NULL )
      return false;
    if( balle == NULL )
      return false;

    return true;
}

void capnhathinh(int x, int y, SDL_Surface* source, 
		  SDL_Surface* destination, SDL_Rect* clip = NULL)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface( source, clip, destination, &offset );
}

void hien_thi( )
{
  capnhathinh(0,0, background, screen);
  
  capnhathinh(balleMoi.x, balleMoi.y, balle, screen);
   
  capnhathinh(galG.x, galG.y, galletG, screen);
 
  capnhathinh(galD.x, galD.y, galletD, screen);
}


/******************************************************************************************************************/

int main() {

  /*----------------------------------------------DECLARER LES VARIABLES------------------------------------------*/

  //int balle_dx = BALLE_DX;
  //int balle_dy = BALLE_DY;

  SDL_Event event;
  bool bRun = 1;

  init_elem();
  nhan_hinh();
  


  /*
  SDL_Rect backgroundRect;
  backgroundRect.x = 0;
  backgroundRect.y = 0;

  SDL_Rect balleRect;
  balleRect.x = ECRAN_LONG/2;
  balleRect.y = ECRAN_LAR/2;
  
  SDL_Rect galletRectG;
  galletRectG.x = 70;
  galletRectG.y = 120;
    
  SDL_Rect galletRectD;
  galletRectD.x = ECRAN_LONG - GALLET_LONG - 70;
  galletRectD.y = 120;
  */

  /*-----------------------------------------INITIALISER LA FENETRE DU JEU----------------------------------------*/

  atexit(SDL_Quit);
  
  if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    exit(1);

  SDL_WM_SetCaption("A Very Ping Pong Christmas", NULL);

  screen = SDL_SetVideoMode(ECRAN_LONG, ECRAN_LAR, 24, 0);

  /*---------------------------------AFFICHER DES IMAGES : ECRAN, BALLE, GALLETS----------------------------------*/
  /*--------------------------------------------------------------------------------------------------------------*/

  while (bRun) {
  
    hien_thi();
      
    SDL_Flip(screen);
    //SDL_Delay(10);

    controlGalletG();
    controlGalletD();
      
    /*-----------------------------------------CONTROLER LES GALLETS---------------------------------------------*/
    
    while (SDL_PollEvent(&event)) {
      switch(event.type) {
      //case SDL_KEYDOWN:
      //controlGalletG(galletRectG);
      //controlGalletD(galletRectD);
	//break;

	/*
	switch(event.key.keysym.sym) {
	case SDLK_UP:
	  galletRectD.y -= V_GALLET;
	  break;
	case SDLK_DOWN:
	  galletRectD.y += V_GALLET;
	  break;
	case SDLK_a:
	  galletRectG.y -= V_GALLET;
	  break;
	case SDLK_z:
	  galletRectG.y += V_GALLET;
	  break;
	*/

      case SDLK_ESCAPE:
	bRun = 0;
	break;
      //default:
      //break;
      }
      //break;
      
      //case SDL_QUIT:
      //bRun = 0;
      //break;
      
      //default:
      //break;
    }      

    mouvementBalle(balleRect, balle_dx, balle_dy);
    
    limiteGallet(galletRectG, galletRectD);
    
    balleGallet(balleRect, galletRectG, galletRectD, balle_dx);

  }

  return 0;
}
      
/******************************************************************************************************************/
