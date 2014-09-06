#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <SDL/SDL.h>
using namespace std;


int main()
{
  SDL_Surface *manhinh;
     
     /* srand(time(NULL));
      for (int i = 0; i<100; i++)
      {
	int a;
	a = rand() % 10;
	cout << a << " ";
	if ( i % 5 ==0)
	  cout << endl;
      }*/
      SDL_Event sukien;

  if (SDL_Init(SDL_INIT_VIDEO) != 0) 
  {
    printf("Khong the thiet lap SDL: %s\n", SDL_GetError());
    return 1;
  }

  atexit(SDL_Quit);

  manhinh = SDL_SetVideoMode(256, 256, 16, 0);
  if (manhinh == NULL)
  {
    printf("Khong the thiet lap che do man hinh: %s\n", SDL_GetError());
    return 1;
  }
  printf("Bam phim ESC de thoat, bam phim bat ky tren ban phim de kiem tra\n");
  printf("(Chu y chi dung cho ban phim he tieng Anh)\n");

  while (SDL_WaitEvent(& sukien) != 0) 
  {
    SDL_keysym nut;

    switch (sukien.type) 
    {
      case SDL_KEYDOWN:
	printf("Ban phim duoc nhan. ");
	nut = sukien.key.keysym;
	printf("\tPhim \" %s \" \tMa phim %i. ", SDL_GetKeyName(nut.sym), nut.sym);
	if (sukien.key.keysym.mod & KMOD_LSHIFT)
	  printf(" (Co Shift trai)\n");
	else
	  printf(" (Khong co Shift trai)\n");

	if (nut.sym == SDLK_ESCAPE) 
	{
	  printf("ESC da duoc nhan. Ban thoat khoi chuong trinh.\n");
	  goto end;
	}
	break;
      case SDL_KEYUP:
	printf("Phim duoc tha ra. \n");
	break;
      case SDL_QUIT:
	printf("Thoat khoi chuong trinh. Bye.\n");
	exit(0);
    }
  }
  end:
  sleep(3);
  printf("Bye Bye\n");
  
}
