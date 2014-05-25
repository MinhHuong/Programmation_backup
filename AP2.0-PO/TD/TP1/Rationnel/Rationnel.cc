#include "Rationnel.h"

Rationnel::Rationnel() {
  my_num = my_deno = 0;
}

Rationnel::Rationnel(int num, int deno) {
  my_num = num;
  if (deno != 0)
    my_deno = deno;
  else
    cout << "Erreur. Deno doit etre != 0" << endl;
}

void Rationnel::affiche() {
  cout << "Le nombre (reduit si possible) : " << toString_reduit() << endl;
}

void Rationnel::setNum(int num) {
  my_num = num;
}

void Rationnel::setDeno(int deno) {
  if (deno != 0) 
    my_deno = deno;
  else
    cout << "Erreur. Deno doit etre != 0" << endl;
}

void Rationnel::inverse() {
  int temp = my_num;
  my_num = my_deno;
  my_deno = temp;
}

bool Rationnel::egal(Rationnel r) const {
  int res;

  if (my_num > r.my_num)
    res = pgcd(my_num, my_deno);
  else if (my_num == r.my_num)
    return (my_deno == r.my_deno);
  else
    res = pgcd(r.my_num, r.my_deno);
  
  return ( ( (my_num == (r.my_num)*res) &&
	     (my_deno == (r.my_deno)*res) ) ||
	   ( (my_num*res == r.my_num) &&
	     (my_deno*res == r.my_deno) ) );
}

// 1)
void Rationnel::plus(const Rationnel & r, Rationnel & s) const {
  if (my_deno == r.my_deno)
    s.my_num = my_num + r.my_num;
  else {
    s.my_num = my_num*r.my_deno + r.my_num*my_deno;
    s.my_deno = my_deno*r.my_deno;
  }
}

/* 2) Rationnel Rationnel::plus(const Rationnel & r) const 
   Difference : 1) tao 1 vung nho cho Rationnel &s tai 1 vi tri nhat dinh, de quan li
                2) tao 1 vung nho bat ki tren thanh ghi, noi nao cho cho trong se ghi len 
*/

void Rationnel::moins(const Rationnel & r, Rationnel & d) const {
  if (my_deno == r.my_deno)
    d.my_num = my_num - r.my_num;
  else {
    d.my_num = my_num*r.my_deno - r.my_num*my_deno;
    d.my_deno = my_deno*r.my_deno;
  }
}

void Rationnel::fois(const Rationnel & r, Rationnel & p) const {
  p.my_num = my_num * r.my_num;
  p.my_deno = my_deno * r.my_deno;
}

void Rationnel::diviser(const Rationnel & r, Rationnel & q) const {
  q.my_num = my_num * r.my_deno;
  q.my_deno = r.my_num * my_deno;
}

int Rationnel::getNum() const {
  return my_num;
}

int Rationnel::getDeno() const {
  return my_deno;
}

void Rationnel::reduit() {
  int res = pgcd(my_num, my_deno);
  
  my_num /= res;
  my_deno /= res;
}


string Rationnel::toString_normal() const {
  string nb;
  
  if (my_deno == 1)
    nb = intToString(my_num);
  else
    nb = intToString(my_num) + "/" + intToString(my_deno);
  
  return nb;
}


string Rationnel::toString_reduit() {
  reduit();
  
  string nb;
  if (my_deno == 1)
    nb = intToString(my_num);
  else
    nb = intToString(my_num) + "/" + intToString(my_deno);
  
  return nb;
}
