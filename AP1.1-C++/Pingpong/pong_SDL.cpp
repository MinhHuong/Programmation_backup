#include <iostream>
#include <math.h>
#include <cstdlib>
#include <stdio.h>
#include <SDL/SDL.h>
#include <unistd.h>
#include <string>
using namespace std;

const int SCREEN_WIDTH = 451;
const int SCREEN_HEIGHT = 301;
const int SCREEN_BPP = 32;

SDL_Surface *screen=NULL;
SDL_Surface *background=NULL;
SDL_Surface *image=NULL;
SDL_Surface *image2=NULL;
SDL_Rect src, dest;
SDL_Event event;

typedef struct kieu_banh
{
  int x, y;
  int dx, dy;
} banh;
static banh ball;

void banh_chay()
{
  
  ball.x += ball.dx;
  ball.y += ball.dy;
  if (ball.x < 0 || ball.x > screen->w - 1)
	ball.dx = -ball.dx;
  if (ball.y < 0 || ball.y > screen->h - 1)
	ball.dy = -ball.dy;
}

void ve_banh()
{
    src.x = 0;
    src.y = 0;
    src.w = image->w-560;
    src.h = image->h-385;
    dest.x = ball.x;
    dest.y = ball.y;
    dest.w = image->w;
    dest.h = image->h;
    SDL_BlitSurface(image2, &src, screen, &dest);
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
  }
  return ep_hinh;
}

bool nhan_hinh()
{
    background = xulyhinh( "aries.bmp" );
    image = xulyhinh("green.bmp");
    image2 = xulyhinh("red.bmp");
    if( background == NULL )
       return false;
    if( image == NULL )
       return false;
    if( image2 == NULL )
       return false;

    return true;
}

void hien_thi()
{
	 src.x = 0;
      src.y = 0;
      src.w = background->w;
      src.h = background->h;
      dest.x = 0;
      dest.y = 0;
      dest.w = background->w;
      dest.h = background->h;
      SDL_BlitSurface(background, &src, screen, &dest);
      
	  src.x = 0;
	  src.y = 0;
	  src.w = image->w-565;
	  src.h = image->h-350;
	  dest.x = 15;
	  dest.y = 100;
	  dest.w = image->w;
	  dest.h = image->h;
	  SDL_BlitSurface(image, &src, screen, &dest);
	  
	  src.x = 0;
	  src.y = 0;
	  src.w = image->w-565;
	  src.h = image->h-350;
	  dest.x = background->w-20;
	  dest.y = 100;
	  dest.w = image->w;
	  dest.h = image->h;
	  SDL_BlitSurface(image, &src, screen, &dest);
}

bool kiemtra()
{
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
   
    if( screen == NULL )
    {
        return false;
    }
    SDL_WM_SetCaption( "Bai Pong cua Long", NULL );

    return true;
}

void dondep()
{
    SDL_FreeSurface( image );
    SDL_FreeSurface( image2 );
    SDL_FreeSurface( background );
    SDL_Quit();
}
int main() {
  bool thoat =false;
  if (kiemtra() == false)
    return 1;
  if( nhan_hinh() == false )
    return 1;
  int i=0;
  ball.dx= 5; ball.dy =5;

   /* Ask SDL to update the entire screen. */
	  SDL_UpdateRect(screen, 0, 0, 0, 0);
	 	 
 while (thoat == false)
 {
   hien_thi();
   banh_chay();
   ve_banh();
   SDL_Delay(100);
      //SDL_UpdateRect(screen, 0, 0, 0, 0);
  while (SDL_PollEvent(&event) != 0) {
    SDL_keysym keysym;

    switch (event.type) {
    case SDL_KEYDOWN:
      //ve_banh();
     // SDL_UpdateRect(screen, 0, 0, 0, 0);
      //SDL_Delay(1000);
      break;
    case SDL_QUIT:
      thoat = true;
    }
  }
  if( SDL_Flip( screen ) == -1 )
    {
        return 1;
    }
 }    
 
  dondep();
    return 0;
  
}
  
