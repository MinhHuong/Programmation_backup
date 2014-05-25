#include <iostream>
#include <cstdlib>
using namespace std;

//BAI TAP 1 :

/*
const int taille = 5;

void TinkyWinky(int *n, int * &ptr) { //int * &ptr nghia la bien con tro ptr ma sau do gia tri chua trong ptr duoc luu tru lai trong main 
  ptr = new int[taille]; //thiet lap 1 array moi, chua ra 1 khoang trong bo nho cho array nay
  int cpt = 0;
  
  do {
    *(ptr + cpt) = n[cpt]; //ptr[cpt] = n[cpt], sau do cpt++ cho den khi cpt == taille; luc nay n[cpt] (hay n[0] = 0, n[1] = 1,...) da co san cac gia tri 0, 1, 2...luc nay gan no vao bien con tro *(ptr + cpt)
    cpt++;
  } while (cpt < taille);
}


void Dipsy (int *n) { //int *n = int n[]
  for (int i = 0 ; i < taille ; i++)
    n[i] = i; //gan n[i] = i, cu the la n[0] = 0, n[1] = 1, n[2] = 2...
}


void LaaLaa(int *n) { //in du lieu ra
  for (int i = 0 ; i < taille ; i++)
    cout << *(n + i) << " "; //*(n + i) = n[i], nghia la tu n[0] tro toi vi tri n[i]
  cout << endl;
}


void Po(int *n, int *b) { 
  int *c = n; //n cung la 1 bien con tro
  for (int i = 0 ; i < taille - 1; i++) 
    n++; //dia chi cua n nhay len 5 don vi (i++ 5 lan)
   
  int i = 0;
  while (c <= n) { //sua lai tu (c != n) thanh (c <= n)
    b[i] = *n; //gan vao array b[i] gia tri cua cac dia chi chua trong n
    n--;
    i++;
  }
}


int main() {
  int *p;
  int *tabA = new int [taille];
  int *tabB;
  
  Dipsy(tabA);
  LaaLaa(tabA);

  TinkyWinky(tabA, tabB);
  LaaLaa(tabB);

  Po(tabA, tabB);
  LaaLaa(tabB);

  return EXIT_SUCCESS;
}
*/

/*
Chuong trinh se cho ket qua :
01234
01234
43214

Sau khi sua lai thanh (c <= n) thi chuong trinh se cho hien thi :
01234
01234
43210
*/


//BAI TAP 2 :

/*
int Pow1(int a, int b) {
  if (b == 0)
    return 1;
  else
    return Pow1(a, b - 1)*a;
}


int Pow2 (int a, int b) {
  if (b == 0)
    return 1;
  else if (b > 0 && b % 2 == 0)
    return Pow2(a*a, b/2);
  else
    return Pow2(a*a, (b - 1)/2)*a;
}


int main() {
  int x, y;
  cout << "Entrez x = "; cin >> x;
  cout << "Entrez le coefficient y = "; cin >> y;

  cout << "Puissance en utilisant la recurrence A = " << Pow1(x, y) << endl;
  cout << "Puissance en utilisant la recurrence B = " << Pow2(x, y) << endl;
}
*/


//BAI TAP 3 :

#define MAX_ETUDIANTS 30
#define MAX_NOTES 6
#define NOTE_MAXIMALE 20

void saisir_notes(double notes[][MAX_NOTES], int &nb_etu, int &nb_notes) {
  cout << "Entrez le nombre des etudiants : "; cin >> nb_etu ;
  cout << "Entrez le nombre de notes : " ; cin >> nb_notes;

  for (int i = 0 ; i < nb_etu ; i++) {
    cout << "- Pour l'etudiant " << i + 1 << " : " << endl;
    cout << "Entrez la note : ";
    for (int j = 0 ; j < nb_notes ; j++) {
      cin >> notes[i][j];
    }
  }
}


double moyenne_note(double notes[][MAX_NOTES], int numero_note, int nb_etu) {
  double somme = 0.0, moyenne = 0.0;

  for (int i = 0 ; i < nb_etu ; i++)
    somme += notes[i][numero_note];
  moyenne = somme/nb_etu;

  return moyenne;
}


double moyenne_etudiant(double notes[][MAX_NOTES], int numero_etudiant, int nb_notes) {
  double somme = 0.0, moyenne = 0.0;
  
  for (int i = 0 ; i < nb_notes ; i++)
    somme += notes[numero_etudiant][i];
  moyenne = somme/nb_notes;

  return moyenne;
}



int main() {
  double notes_etu[MAX_ETUDIANTS][MAX_NOTES];
  int nb_etu, nb_notes;

  saisir_notes(notes_etu, nb_etu, nb_notes);

  int numero_etu = 1;
  cout << "Moyenne de l'etudiant " << numero_etu + 1 << " : " << moyenne_etudiant(notes_etu, numero_etu, nb_notes) << endl;
  
  int numero_note = 2;
  cout << "Moyenne des etudiants sur la note " << numero_note + 1 << " : " << moyenne_note(notes_etu, numero_note, nb_etu) << endl;
} 


