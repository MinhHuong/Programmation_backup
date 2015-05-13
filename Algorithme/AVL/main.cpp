#include <iostream>
#include "avl.h"
using namespace std;

int main() {
  AVL* root = new AVL(8);
  AVL::insert(root, 6);
  AVL::insert(root, 12);
  AVL::insert(root, 3);
  AVL::insert(root, 7);
  AVL::insert(root, 10);
  AVL::insert(root, 15);
  AVL::insert(root, 2);
  AVL::insert(root, 4);
  AVL::insert(root, 8);
  AVL::insert(root, 11);
  AVL::insert(root, 14);
  AVL::insert(root, 16);
  AVL::insert(root, 9);
 
  /*
  int _key;
  for(int i = 0 ; i < 13 ; i++) {
    cout << "New key: "; cin >> _key;
    AVL::insert(root, _key);
    AVL::printNLR(root);
    cout << endl;
  }
  */
  AVL::printNLR(root);
  cout << endl;

  AVL::del(root, 10);

  AVL::printNLR(root);
  cout << endl;

  AVL::printLNR(root);
  cout << endl;
  
  return 0;
}
