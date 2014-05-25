#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <termios.h>
using namespace std;

/*****************************************************************************************************************/

/* ======================================== TINH THUE THU NHAP CA NHAN ========================================= */

/*****************************************************************************************************************/

int ThueCoNpt (double tncn, double tndt, double tg, double tax);
int ThueKhongNpt (double tncn, double tax);

/************************************************* --- MAIN --- **************************************************/

int main() {
  int npt;
  double tncn, tndt, tg, tax;
  char traLoi;

  cout << "Nhap tien thu nhap ca nhan = " ; cin >> tncn;
  tncn = tncn/(10E5);

  cout << "Nhap so nguoi phu thuoc = " ; cin >> npt;

  if (npt <= 0) 
    ThueKhongNpt (tncn,tax);

  else {
    cout << "Co chiu trach nhiem nguoi phu thuoc hay khong ? (y/n) : ";
    cin >> traLoi;
    
    if (traLoi == 'y') {
      tg = 4 + 1.6*npt;
      
      if (tg <= 10) 
	ThueCoNpt (tncn,tndt,tg,tax);
      else {
	tg = 10;
	ThueCoNpt (tncn,tndt,tg,tax);
      }
    }

    else if (traLoi == 'n') {
      tg = 4;
      ThueCoNpt (tncn,tndt,tg,tax);
    }
  }
}
  
/****************************************** --- LES FONCTIONS --- ************************************************/

int ThueKhongNpt (double tncn, double tax) {
  if (tncn <= 4)
    cout << "Khong can dong thue" << endl;

  if (tncn > 4 && tncn <= 6)
    tax = (tncn - 4)*0.05;
  
  else if (tncn > 6 && tncn <= 9)
    tax = 6*0.05 + (tncn - 6)*0.1;

  else if (tncn > 9 && tncn <= 14)
    tax = 6*0.05 + 3*0.1 + (tncn - 6 - 3)*0.15 ;

  else if (tncn > 14 && tncn <=24)
    tax = 6*0.05 + 3*0.1 + 5*0.15 + (tncn - 6 - 3 - 5)*0.2 ;

  else if (tncn > 24 && tncn <= 44)
    tax = 6*0.05 + 3*0.1 + 5*0.15 + 10*0.2 + (tncn - 6 - 3 - 5 - 10)*0.25;
      
  else if (tncn > 44 && tncn <= 84)
    tax = 6*0.05 + 3*0.1 + 5*0.15 + 10*0.2 + 20*0.25 + (tncn - 6 - 3 - 5 - 10 - 20)*0.3;
      
  else
    tax = 6*0.05 + 3*0.1 + 5*0.15 + 10*0.2 + 20*0.25 + 40*0.3 + (tncn - 6 - 3 - 5 - 10 - 20 - 40)*0.35;
  
  cout << "Thue can nop = " << tax*10E5 << endl;
}

/*****************************************************************************************************************/

int ThueCoNpt (double tncn, double tndt, double tg, double tax) {
  if (tncn < tg)
    cout << "Khong can dong thue thu nhap" << endl;
  
  else {
    tndt = tncn - tg;

    if (tndt + 4 > 4 && tndt + 4 <= 6)
      tax = tndt*0.05;

    else if (tndt + 4 > 6 && tndt + 4 <= 9)
      tax = 2*0.05 + (tndt - 2)*0.1;

    else if (tndt + 4 > 9 && tndt + 4 <= 14)
      tax = 2*0.05 + 3*0.1 + (tndt - 2 - 3)*0.15;

    else if (tndt + 4 > 14 && tndt + 4 <= 24)
      tax = 2*0.05 + 3*0.1 + 5*0.15 + (tndt - 2 - 3 - 5)*0.2;

    else if (tndt + 4 > 24 && tndt + 4 <= 44)
      tax = 2*0.05 + 3*0.1 + 5*0.15 + 10*0.2 + (tndt - 2 - 3 - 5 - 10)*0.25;

    else if (tndt + 4 > 44 && tndt + 4 <= 84)
      tax = 2*0.05 + 3*0.1 + 5*0.15 + 10*0.2 + 20*0.25 + (tndt - 2 - 3 - 5 - 10 - 20)*0.3;

    else
      tax = 2*0.05 + 3*0.1 + 5*0.15 + 10*0.2 + 20*0.25 + 40*0.3 + (tndt - 2 - 3 - 5 - 10 - 20 - 40)*0.35;

    cout << "Thue can nop = " << tax*10E5 << endl;
  }
}




