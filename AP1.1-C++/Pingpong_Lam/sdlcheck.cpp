#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <SDL/SDL.h>
using namespace std;

Uint16 CreateHicolorPixel (SDL_PixelFormat *fmt, Uint8 red, Uint8 green, Uint8 blue)
{
  Uint16 value;
  value = ((red >> fmt->Rloss) << fmt->Rshift) + 
	  ((green >> fmt->Gloss) << fmt->Gshift) +
	  ((blue >> fmt->Bloss) << fmt->Bshift);
  return value;
}
    int main(int argc, char *argv[])
    {
      SDL_Surface *screen;
      Uint16 *raw_pixels;
      int x, y;
     /* srand(time(NULL));
      for (int i = 0; i<100; i++)
      {
	int a;
	a = rand() % 10;
	cout << a << " ";
	if ( i % 5 ==0)
	  cout << endl;
      }*/
      if (SDL_Init (SDL_INIT_VIDEO) != 0)
      {
	printf (" Unable to initialize SDL: %s\n", SDL_GetError());
	return 1;
      }
      atexit (SDL_Quit);
      screen = SDL_SetVideoMode (255, 255, 16, 0);
      if (screen == NULL)
      {
	printf ("Unable to set video mode: %s\n", SDL_GetError());
	return 1;
      }
      SDL_LockSurface(screen);
      raw_pixels = (Uint16 *) screen->pixels;
      for (x=0; x<255; x++)
      {
	for (y=0; y<255; y++)
	{
	  Uint16 pixels_color;
	  int offset;
	  pixels_color = CreateHicolorPixel (screen->format, x, 0, y);
	  offset = (screen->pitch / 2 * y + x);
	  raw_pixels[offset] = pixels_color;
	}
      }
      SDL_UnlockSurface (screen);
      SDL_UpdateRect (screen, 0, 0, 0, 0);
      SDL_Delay (5000);
      printf ("Success!\n");
      sleep(3);
    printf("hello world\n");
    return 0;
    }
