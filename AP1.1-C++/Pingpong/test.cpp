#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


using namespace std;
#define NUM_balloon 10
#define MAX_SPEED 6
/* This structure stores the information for one
on-screen balloon. */
typedef struct balloon_s 
{
	int x, y; /* position on the screen */
	int dx, dy; /* movement vector */
} balloon_t, *balloon_p;
/* Array of balloons. */
static balloon_t balloons[NUM_balloon];
/* These are now global variables, for convenience. */
static SDL_Surface *screen;
static SDL_Surface *balloon;
/* This routine loops through the array of balloons and
sets each to a random starting position and direction. */
static void init_balloons()
{
	int i;
	for (i = 0; i < NUM_balloon; i++) 
	{
		//balloons[i].x = rand() % screen->w;
		balloons[i].x = 0;
		balloons[i].y = rand() % screen->h;
		balloons[i].dx = (rand() % (MAX_SPEED * 2)) - MAX_SPEED;
		balloons[i].dy = (rand() % (MAX_SPEED * 2)) - MAX_SPEED;
	}
}
/* This routine moves each balloon by its motion vector. */
static void bongbongbay()
{
	int i;
	for (i = 0; i < NUM_balloon; i++) 
	{
/* Move the balloon by its motion vector. */
		//balloons[i].dx = (rand() % (MAX_SPEED * 2)) - MAX_SPEED;
		//balloons[i].dy = (rand() % (MAX_SPEED * 2)) - MAX_SPEED;
		balloons[i].x += balloons[i].dx;
		balloons[i].y += balloons[i].dy;
/* Turn the balloon around if it hits the edge
of the screen. */
		if (balloons[i].x < 0 || balloons[i].x > screen->w - 1)
			balloons[i].dx = -balloons[i].dx;
		if (balloons[i].y < 0 || balloons[i].y > screen->h - 1)
			balloons[i].dy = -balloons[i].dy;
	}
}
/* This routine draws each balloon to the screen surface. */
static void ve_bongbong()
{
	int i;
	SDL_Rect src, dest;
	for (i = 0; i < NUM_balloon; i++) 
	{
		src.x = 0;
		src.y = 0;
		src.w = balloon->w;
		src.h = balloon->h;
/* The balloon's position specifies its
center. We subtract half of its width
and height to get its upper left corner. */
		dest.x = balloons[i].x - balloon->w / 2;
		dest.y = balloons[i].y - balloon->h / 2;
		dest.w = balloon->w;
		dest.h = balloon->h;
		SDL_BlitSurface(balloon, &src, screen, &dest);
	}	
}

int main()
{
	SDL_Surface *background;
	SDL_Rect src, dest;
	SDL_Event event;
	int frames;
/* Initialize SDL's video system and check for errors. */
	if (SDL_Init(SDL_INIT_VIDEO) != 0) 
	{
		printf("Unable to initialize SDL: %s\n", SDL_GetError());
		return 1;
	}
/* Make sure SDL_Quit gets called when the program exits! */
	atexit(SDL_Quit);
/* Attempt to set a 640x480 hicolor (16-bit) video mode. */
	screen = SDL_SetVideoMode(760, 600, 24, SDL_DOUBLEBUF);
	if (screen == NULL) 
	{
		printf("Unable to set video mode: %s\n", SDL_GetError());
		return 1;
	}
/* Load the bitmap files. */
	background = SDL_LoadBMP("image.bmp");
	if (background == NULL)
	{
		printf("Unable to load bitmap.\n");
		return 1;
	}	
	balloon = IMG_Load ("b1.png");
	if (balloon == NULL) 
	{
		printf("Unable to load bitmap.\n");
		return 1;
	}
/* Set the balloon's colorkey. */
	SDL_SetColorKey (balloon, SDL_SRCCOLORKEY,
					(Uint8) SDL_MapRGB(balloon->format, 255, 255, 255));
/* Initialize the balloon position data. */
	init_balloons();
/* Animate 300 frames (approximately 10 seconds). */
	for (frames = 0; frames < 3000; frames++)
	{
/* Draw the background image. */
		src.x = 0;
		src.y = 0;
		src.w = background->w;
		src.h = background->h;
		dest = src;
		SDL_BlitSurface(background, &src, screen, &dest);
/* Put the balloons on the screen. */
		ve_bongbong();
/* Ask SDL to update the entire screen. */
		SDL_UpdateRect(screen, 0, 0, 0, 0);
/* Move the balloons for the next frame. */
		bongbongbay();
		//while (SDL_PollEvent(&event) != 0)
		//{
		//  switch (event.type)
		//    case SDL_QUIT:
		//		printf("Quit event. Bye.\n");
		//		exit(0);
		//}
	}
/* Free the memory that was allocated to the bitmap. */
	SDL_FreeSurface(background);
	SDL_FreeSurface(balloon);
	return 0;
} 
