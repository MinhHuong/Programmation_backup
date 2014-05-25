#include <math.h>
#include <iostream>
#include <cstdlib>
//#include <terminos.h>
#include <unistd.h>
#include <stdio.h>
//#include <ncurses.h>
using namespace std;

/*****************************************************************************************/

#define N 30 // so hang
#define M 79 // so cot
#define nbr_gallet 20 // thanh chan gallet o duoi dai 20 ky tu =
#define hang 5
#define cot 12
#define speedx 1
#define speedy 1
//#define level 2
//#define nb_balle 1

/*****************************************************************************************/

typedef struct {
  double x;
  double y;
  double dx;
  double dy;
} Sprite;

typedef struct {
  int x;
  int y[5];
  bool check;
} brique;

char screen [N][M];

/**************************** Declarer les fonctions ************************************/

void verifier_condition(int & ball,long int & score, int & level);
void avant_jouer(Sprite & goutte, Sprite q[]);
void aider ();
void annonce ();
bool touche_appuyee();
int code_touche();
void arranger_brique (brique d[][cot]);
void init_sprite(Sprite & s, double x, double y, double dx, double dy);
void clavier (Sprite & goutte, Sprite q[]);
void paysage ();
void affiche_screen();
void mise_a_jour_sprite(Sprite & s, 
            Sprite q[], 
            brique d[][cot], 
            long int & score, 
            int & ball, 
            bool & cheat, 
            int &level);// khai bao them sprite q[] la de cho gallet tuong tac voi trai banh
//void check_button (char c, Sprite q[]); //ham kiem tra nhan ban phim

/*********************************** MAIN ************************************************/

int main () {
  annonce ();
  Sprite goutte,gallet[nbr_gallet];
  brique gach[hang][cot];
  arranger_brique (gach);
  int ball =3;
  long int score = 0;
  bool cheat = false;
  int level =1;
  
  for ( int g=0; g<nbr_gallet; g++)
  {
    init_sprite(gallet[g],N-5,g+1,0,0);// moi khi dong for chay, cu moi gallet ke tiep nhau o dong thu N-5 se co y tang len 1 de thanh 1 day ====== sat nhau
  }
  
  start_here:
  avant_jouer (goutte, gallet);
  verifier_condition(ball, score, level);
  for (int t=0;; t++) 
  {
    system ("stty raw");
    usleep(10 * 10000);    
    clavier (goutte, gallet);
    
    system ("stty cooked");

    paysage();// in khung XXX
       for ( int g=0; g<nbr_gallet; g++)
    {
      screen[(int) gallet[g].x][(int) gallet[g].y] = '='; // in ra gallet
    }
       for (int row=0; row<hang; row++)
     for (int column=0; column<cot; column++)
       if (gach[row][column].check == 1) 
       for (int characters=0; characters<5; characters++)
          screen[gach[row][column].x][gach[row][column].y[characters]] = 'W';
        
          
        
       
       screen[(int) goutte.x][(int) goutte.y] = '0'; //in ra trai banh
 
    
    affiche_screen();
    mise_a_jour_sprite(goutte, gallet, gach, score, ball, cheat, level); //de trai banh chuyen dong, va gallet chuyen dong
    cout << "\nLevel: "<< level << "\t\tBall: "<< ball <<"\t\t\t\tScore:  " <<score;
    cout << "\n\tPress  'h' for help\t\tPress Enter to start\n";
    
    if (goutte.dy == 0) goto start_here;
  }
}

/********************************** Les fonctions ****************************************/
void verifier_condition(int & ball, long int & score, int & level)
{
  if (ball < 0)
  { system ("clear");
    cout << "\n\n\tMung qua!!! Da co nguoi choi te hon tui. Tui iu ban!!";
    cout << "\nNhan phim Enter de thoat\n";
    char c=getchar();
    exit (0);    
  }
  if (level >3)
    { system ("clear");
    cout << "\n\n\tChuc mung ban da chien thang voi so diem " << score <<endl;
    cout << "\nBan nhan duoc 1 phan thuong, xin vui long lien he voi";
    cout << "\nvan phong dieu hanh Puf de lanh qua.";
    cout << "\nNhan phim Enter de thoat\n";
    char c=getchar();
    exit (0);    
  }
    
}

void avant_jouer(Sprite & goutte, Sprite q[])
{
  double goutte_y;
  goutte_y= (q[0].y + q[nbr_gallet-1].y)/2;
  init_sprite(goutte, N-6, goutte_y, 0,0);
}

void annonce (){
  system ("clear");
  string line[6];
  line[0] = "\t\t\t\tFBI WARNING\n";
  line[1] = "\t\tThis game copyright by group LamHieuLoc,all rights reserved.\n";
  line[2] = "\t\tThe unauthorized reproduction or distribution of this\n";
  line[3] = "\t\tcopyrighted work is illegal. Criminal copyright infringement\n";
  line[4] = "\t\tis investigated by federal law enforcement agencies and is\n";
  line[5] = "\t\tpunishable by up to 100 years in prison and a fine of $1,000,000.\n";
  
  for (int i=0; i<25; i++)
  {
    system ("clear");
    for (int f=0; f<25-i; f++)
      cout << endl;
    for (int m=0; m<i && m<6; m++)
      cout << line[m];
    usleep (100000);
  }
  sleep (3);
  cout << endl << endl << endl <<"\t\t\tPress ENTER to continue";
  char c = getchar ();
  
}
void arranger_brique (brique d[][cot])
{
  for (int row=0; row<hang; row++)
    for (int column=0; column<cot; column++)
      {
    d[row][column].x = row+3;
    d[row][column].check = true;
    for (int h=0; h<5; h++)
    {
      d[row][column].y[h] = 3 + column*6 + (h+1);
    }
      
    
      }
}

void clavier (Sprite & goutte, Sprite q[])
{
    if (code_touche() == 'm') 
    {
      system ("stty cooked");
      if (q[nbr_gallet-1].y<M-3)
    for ( int g=0; g<nbr_gallet; g++)
      q[g].y += 3;
      return;
    }
    if (code_touche() == 'z')
    {
      system ("stty cooked");
      if (q[0].y > 2)
      for ( int g=0; g<nbr_gallet; g++)
    q[g].y -= 3;
      return;
    }
    if (code_touche() == 'h')
    {
      aider();
    }
    if (code_touche() == 13) {goutte.dx = -1; goutte.dy = 1;}
    if (code_touche() == 27)
    {
      system ("stty cooked");
      exit(0);
    }
  
  
}

void aider () {
  system ("clear");
  cout << "\n\n\n\n";
  cout << "\t\t*****************************************************************\n";
  cout << "\t\t*                                                               *\n";
  cout << "\t\t*      Ban co duoc 3 trai banh cho 3 lan choi, va 3 level       *\n";
  cout << "\t\t*    Khi ban qua duoc level moi, ban se duoc thuong them 1      *\n";
  cout << "\t\t*    trai banh dong thoi do dai thanh chan se ngan hon          *\n";
  cout << "\t\t*          'z': trai        'm' : phai                          *\n";
  cout << "\t\t*           ESC: thoat      Enter: bat dau                      *\n";
  cout << "\t\t*    1 phim bi mat choi an gian, ban hay tu tim lay hehehehe    *\n";
  cout << "\t\t*                                                               *\n";
  cout << "\t\t*****************************************************************\n";
  cout << "\t\t\tBam Enter de quay tro ve game";
  char c = getchar ();
}

/*
void check_button (char c, Sprite q[])
{
switch (c) {
      case 'm':
    system ("stty cooked");
    if (q[nbr_gallet-1].y<M-4) // neu gallet khong dung canh phai, thi duoc di chuyen sang phai
      for ( int g=0; g<nbr_gallet; g++)
        q[g].y += 4;
    break;
      case 'z':
    system ("stty cooked");
    if (q[0].y > 4)// neu gallet chua dung canh trai, thi duoc di chuyen sang trai
    for ( int g=0; g<nbr_gallet; g++)
      q[g].y -= 4;
    break;
      case 27:
        system ("stty cooked");
        exit(0);
      }
  
}
*/
void mise_a_jour_sprite(Sprite & s,
            Sprite  q[], 
            brique d[][cot], 
            long int & score, 
            int & ball, 
            bool & cheat, 
            int & level) {
  s.x += s.dx;
  s.y += s.dy;
  for (int row=0; row<hang; row++)
    for (int column=0; column<cot; column++)
      {
    if ( s.x == d[row][column].x 
        && s.y >= d[row][column].y[0] 
        && s.y <= d[row][column].y[4] 
        && d[row][column].check != 0 )
    {
      s.dx *= -speedx;
      d[row][column].check = false;
      score += 100;
      if (score%6000 ==0)
      {
        level += 1;
        ball +=1;
        s.dx = s.dy =1;
      }
    }
      }
  if ( s.x < 2 || (s.x == N-5 
          && s.y >= q[0].y 
          && s.y <= q[nbr_gallet-1].y )) s.dx *= -speedx; //ham xet dieu kien cho trai banh dung vao gallet
  if ( s.y < 2 || s.y > M-3) s.dy *= -speedy;
  if ( s.x == N) 
  { if (cheat == 1)
    s.dx *= -speedx;
    else
    {
      ball -=1;
      s.dx = s.dy =0;
    }
  }
    //exit(0); // neu trai banh dung vao canh duoi thi chuong trinh tu thoat
}

void paysage() {
  for (int i=0; i<N; i++)
    for (int j=0; j<M; j++)
      if (i==0 || i==N-1 || j==0 || j==M-1)
        screen[i][j] = 'X';
      else
        screen[i][j] = ' ';
}

void affiche_screen() {
  system("clear");
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++)
      cout << screen[i][j];
    cout << endl;
  }
}


void init_sprite(Sprite & s,
                 double x, 
                 double y, 
                 double dx, 
                 double dy) {
  s.x = x;
  s.y = y;
  s.dx = dx;
  s.dy = dy;
}

int code_touche() {
  int result = -1;
  system ("stty raw");
  if (touche_appuyee())
    result = (int) getchar();
  system ("stty cooked");
  return result;
}

bool touche_appuyee()  
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
