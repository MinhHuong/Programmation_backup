#include <iostream>
#include <math.h>
#include <cstdlib>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <unistd.h>
#include <string>
using namespace std;

const int SCREEN_WIDTH = 1100;
const int SCREEN_HEIGHT = 650;
const int SCREEN_BPP = 24;
const int LIM_UP = 55;
const int LIM_DOWN = 590;
const int LIM_LEFT = 75;
const int LIM_RIGHT = 1025;
const int GALLET_HEIGHT = 135;
const int GALLET_WIDTH = 35;
const int BALL_HEIGHT = 45;
const int BALL_WIDTH = 45;
const int BALL_SPEED = 8;
const int GALLET_SPEED = 14;
const int BALL_PLAY = 3;
const int SIZE_BUTTON_H = 150;
const int SIZE_BUTTON_W = 150;
const int SIZE_LEVEL_H = 115;
const int SIZE_LEVEL_W = 225;
const int NBR_BUTTON = 4;
const int NBR_LEVEL = 3;

SDL_Surface *screen=NULL;
SDL_Surface *background=NULL;
SDL_Surface *gallet1_img=NULL;
SDL_Surface *gallet2_img=NULL;
SDL_Surface *image2=NULL;
SDL_Surface *button_img=NULL;
SDL_Surface *level_img=NULL;
SDL_Surface *welcome=NULL; // hinh nen cua phan gioi thieu
SDL_Rect src, dest, button[NBR_BUTTON], level[NBR_LEVEL], button_press[NBR_BUTTON], level_press[NBR_LEVEL];
SDL_Event event, sukien;
TTF_Font *font = NULL;


typedef struct hinh_chuyen_dong
{
  int x, y;
  int dx, dy;
  
} banh, gallet;


static banh ball, ball_screen[BALL_PLAY], ball_score1[BALL_PLAY],ball_score2[BALL_PLAY];
static gallet gallet1, gallet2;

// Thiet lap gia tri cua ball, gallet ban dau
void value_begin()
{
  for (int i=0; i< BALL_PLAY; i++)
  {
    ball_screen[i].x = 800 + (i*50);
    ball_screen[i].y = 600;
    ball_screen[i].dx = 0;
    ball_screen[i].dy =0;
    
    ball_score2[i].x = 100 +(i*50);
    ball_score2[i].y = 10;
    ball_score2[i].dx = 0;
    ball_score2[i].dy = 0;
    
    ball_score1[i].x = 850 + (i*50);
    ball_score1[i].y = 10;
    ball_score1[i].dx = 0;
    ball_score1[i].dy = 0;
  }
  
  srand(time(NULL));
  ball.x = SCREEN_WIDTH/2;  // chinh giua man hinh
  ball.y = rand () % (LIM_DOWN - LIM_UP)+ LIM_UP; // ngau nhien theo y
  ball.dx = BALL_SPEED;
  ball.dy = BALL_SPEED;
  int random = rand()%100;  // ngau nhien 1 so tu 0 den 99
  switch (random%4)
    {
    case 1:  // UP + LEFT
      ball.dx *= -1;
      ball.dy *= -1;
      break;
    case 2:  // DOWN + LEFT
      ball.dx *= -1;
      break;
    case 3:  // UP + RIGHT
      ball.dy *= -1;
      break;
    case 0: // DOWN + RIGHT
      break;
    }
   
   gallet1.x = LIM_LEFT - GALLET_WIDTH;
   gallet1.y = SCREEN_HEIGHT/2 - GALLET_HEIGHT/2;
   gallet1.dx = 0;
   gallet1.dy = GALLET_SPEED;
   
   gallet2.x = LIM_RIGHT;
   gallet2.y = SCREEN_HEIGHT/2 - GALLET_HEIGHT/2;
   gallet2.dx = 0;
   gallet2.dy = GALLET_SPEED;
}


void control_gallet1()
{
  Uint8 *keystates = SDL_GetKeyState( NULL );
    
  if( keystates[ SDLK_q ] ) gallet1.y -= gallet1.dy;
  else if( keystates[ SDLK_a ] )  gallet1.y += gallet1.dy;
  
  if(gallet1.y< LIM_UP) gallet1.y = LIM_UP; 
  else if (gallet1.y > LIM_DOWN - GALLET_HEIGHT)
    gallet1.y = LIM_DOWN - GALLET_HEIGHT;
 
}
void control_gallet2()
{
  Uint8 *keystates = SDL_GetKeyState( NULL );
    
  
  if( keystates[ SDLK_UP ] ) gallet2.y -= gallet2.dy;
  else if( keystates[ SDLK_DOWN ] ) gallet2.y += gallet2.dy;
 
  
  if(gallet2.y< LIM_UP) gallet2.y = LIM_UP;
  else if (gallet2.y > LIM_DOWN - GALLET_HEIGHT)
    gallet2.y = LIM_DOWN - GALLET_HEIGHT;
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
void banh_chay(int & count, int & ball_left, int & pl1_score, int & pl2_score)
{
  
  count++;
  if (count == 30)
  {
     background = xulyhinh( "images/bg1_small.bmp" );
     gallet1_img = xulyhinh("images/gallet_small.bmp");
     gallet2_img = xulyhinh("images/gallet_small.bmp");
     count=0;
  }
  
  ball.x += ball.dx;
  ball.y += ball.dy;
  
  // Limit left
  if (ball.x < LIM_LEFT && 
      (ball.y < (gallet1.y+ GALLET_HEIGHT - (BALL_HEIGHT/2)) && 
      ball.y > gallet1.y - BALL_HEIGHT/2))
  {
    ball.dx = -ball.dx;
    gallet1_img = xulyhinh("images/gallet_red_small.bmp");
    count=0;
  }
  //Limit right
  if (ball.x > LIM_RIGHT - BALL_WIDTH && 
    (ball.y < (gallet2.y+ GALLET_HEIGHT ) && 
      ball.y > gallet2.y - BALL_HEIGHT/2))
  {
    ball.dx = -ball.dx;
    gallet2_img = xulyhinh( "images/gallet_red_small.bmp" );
    count=0;
  }
  // Limit up
  if (ball.y < LIM_UP  )
  {
    ball.dy = -ball.dy;
    background = xulyhinh( "images/bg2_small.bmp" );
    count=0;    
  }
  // Limit down
  if (ball.y > LIM_DOWN - BALL_HEIGHT )
  {
    ball.dy = -ball.dy;
    background = xulyhinh( "images/bg3_small.bmp" ); 
    count=0;
  }
  if (ball.x <= LIM_LEFT - GALLET_WIDTH) 
  {
    value_begin();
    ball_left--;
    pl1_score++;
  }
  if ( ball.x >= LIM_RIGHT)
    {
    value_begin();
    ball_left--;
    pl2_score++;
  }
}

bool nhan_hinh()
{
    background = xulyhinh( "images/bg1_small.bmp" );
    gallet1_img = xulyhinh("images/gallet_small.bmp");
    gallet2_img = xulyhinh("images/gallet_small.bmp");
    image2 = xulyhinh("images/ball2_2_3.bmp");
      if( background == NULL )
       return false;
    if( gallet1_img == NULL )
       return false;
    if( gallet2_img == NULL )
       return false;
    if( image2 == NULL )
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

void hien_thi(int ball_left, int pl1_score, int pl2_score )
{
  capnhathinh(0,0, background, screen);
  
  for (int i=0; i< ball_left; i++)
  {
    capnhathinh(ball_screen[i].x, ball_screen[i].y, imagep2, screen);
   
  }
  
  for (int i=0; i< pl1_score; i++)
  { capnhathinh(ball_score1[i].x, ball_score1[i].y, image2, screen);
    
  }
  
  for (int i=0; i< pl2_score; i++)
  {
    capnhathinh(ball_score2[i].x, ball_score2[i].y, image2, screen);
  }
  
  capnhathinh(ball.x, ball.y, image2, screen);
   
  capnhathinh(gallet1.x, gallet1.y, gallet1_img, screen);
 
  capnhathinh(gallet2.x, gallet2.y, gallet2_img, screen);
  
}

bool kiemtra()
{
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_DOUBLEBUF );
   
    if( screen == NULL )
    {
        return false;
    }
    if( TTF_Init() == -1 )
    {
        return false;
    }
    SDL_WM_SetCaption( "Pong Metal", NULL );

    return true;
}

void value_button()
{
  welcome = xulyhinh( "images/intro.bmp" );
   button_img = xulyhinh("images/button.bmp");
   level_img = xulyhinh("images/button_level.bmp");
   
  for (int i =0; i < NBR_BUTTON; i++)
  {
     button[i].x = 0;
     button[i].y = i*SIZE_BUTTON_H;
     button[i].w = SIZE_BUTTON_W;
     button[i].h = SIZE_BUTTON_H;
     
     button_press[i].x = SIZE_BUTTON_W;
     button_press[i].y = i*SIZE_BUTTON_H;
     button_press[i].w = SIZE_BUTTON_W;
     button_press[i].h = SIZE_LEVEL_H;  
  }
  for (int i=0; i<NBR_LEVEL; i++)
  {
    level[i].x = 75;
    level[i].y = i*150 +20;
    level[i].w = SIZE_LEVEL_W;
    level[i].h = SIZE_LEVEL_H;
    
    level_press[i].x = 375 +75;
    level_press[i].y = i*150 +20;
    level_press[i].w = SIZE_LEVEL_W;
    level_press[i].h = SIZE_LEVEL_H;
  }
   
}

void gioithieu( bool & intro)
{
  
  value_button();
  capnhathinh(0,0, welcome, screen);
  
  for (int i=0; i< NBR_BUTTON; i++)
    capnhathinh(200+ i*180, 480, button_img, screen, &button[i]);
   
  SDL_Flip (screen );
  while (intro)
  {
     SDL_Flip (screen );
      while (SDL_PollEvent(&event) != 0)
      {
	switch (event.type) {
    
    case SDL_QUIT:      
      intro = false;
    case SDL_MOUSEBUTTONDOWN:
    {
      int x = event.button.x;
      int y = event.button.y;
      //hard
      if (x> 200 && x < 350 &&
	y >480 && y <630)
      {
	if(event.button.button == SDL_BUTTON_LEFT)
		  {
		     capnhathinh(200+ 0*180, 480, button_img, screen, &button_press[0]);
		     for (int i=0; i<NBR_LEVEL; i++)
		       capnhathinh(50, 50+ i*150, level_img, screen, &level[i]);
		     SDL_Flip (screen);
		     SDL_Delay(50);
		     break;
		  }
      }
      //help
      if (x> 380 && x < 530 &&
	y >480 && y <630)
      {
	if(event.button.button == SDL_BUTTON_LEFT)
		  {
		     capnhathinh(200+ 1*180, 480, button_img, screen, &button_press[1]);
		     for (int i=0; i<NBR_LEVEL; i++)
		       capnhathinh(50, 50+ i*150, level_img, screen, &level[i]);
		     SDL_Flip (screen);
		     SDL_Delay(50);
		     break;
		  }
      }
      //play
      if (x> 560 && x < 710 &&
	y >480 && y <630)
      {
	if(event.button.button == SDL_BUTTON_LEFT)
		  {
		     capnhathinh(200+ 2*180, 480, button_img, screen, &button_press[2]);
		     for (int i=0; i<NBR_LEVEL; i++)
		       capnhathinh(50, 50+ i*150, level_img, screen, &level[i]);
		     SDL_Flip (screen);
		     SDL_Delay(50);
		     break;
		  }
      }
      if (x> 740 && x < 890 &&
	y >480 && y <630)
      {
	if(event.button.button == SDL_BUTTON_LEFT)
		  {
		     capnhathinh(200+ 3*180, 480, button_img, screen, &button_press[3]);
		     for (int i=0; i<NBR_LEVEL; i++)
		       capnhathinh(50, 50+ i*150, level_img, screen, &level[i]);

		     SDL_Flip (screen);
		     SDL_Delay(50);
		     break;
		  }
      }
    }
    }
      }
  }
  
  
  SDL_FreeSurface( button_img );
  SDL_FreeSurface( welcome );
  nhan_hinh();
}
void dondep()
{
    SDL_FreeSurface( gallet1_img );
    SDL_FreeSurface( gallet2_img );
    SDL_FreeSurface( image2 );
    SDL_FreeSurface( background );
    TTF_CloseFont( font );
    TTF_Quit();
    SDL_Quit();
}
int main() {
  bool thoat =false,
  play = true,
  intro = true;
  if (kiemtra() == false)
    return 1;
  //if( nhan_hinh() == false )
   // return 1;
  int i=0, count=0, ball_left=BALL_PLAY, pl1_score=0, pl2_score=0;
 value_begin();

 while (thoat == false)
 {
   gioithieu(intro);
   while (play)
   {
     
   hien_thi(ball_left, pl1_score, pl2_score);
   banh_chay(count,ball_left, pl1_score, pl2_score);
   control_gallet1();
  control_gallet2();
  while (SDL_PollEvent(&event) != 0) {
    SDL_keysym keysym;

    switch (event.type) {
    
    case SDL_QUIT:
      thoat = true;
      play = false;
    }
  }
  if( SDL_Flip( screen ) == -1 )
    {
        return 1;
    }
   }
 }    
 
  dondep();
    return 0;
  
}
  
