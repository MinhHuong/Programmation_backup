#include "avl.h"
using namespace std;

bool AVL::setBalanceAndHeight() {
  int hleft = getHeight(left);
  int hright = getHeight(right);
  int delta = hleft - hright;

  if(delta == 0) {
    balanced = EQ;
    height = hleft + 1;
    return true;
  }

  if(delta == 1) {
    balanced = L;
    height = hleft + 1;
    return true;
  }

  if(delta == -1) {
    balanced = R;
    height = hright + 1;
    return true;
  }
  
  return false;
}

void AVL::rebalanceLeft(AVL* &root) {
  AVL *a = root, *b = root->left, *c;

  if(b->balanced == L || b->balanced == EQ) {
    a->left = b->right;
    b->right = a;
    root = b;
    a->setBalanceAndHeight();
    b->setBalanceAndHeight();
  }

  if(b->balanced == R) {
    c = b->right;
    
    b->right = c->left;
    c->left = b;
    a->left = c->right;
    c->right = a;
  
    root = c;
    a->setBalanceAndHeight();
    b->setBalanceAndHeight();
    c->setBalanceAndHeight();
  }
}

void AVL::rebalanceRight(AVL* &root) {
  AVL *a = root, *b = a->right, *c;

  if(b->balanced == R || b->balanced == EQ) {
    a->right = b->left;
    b->left = a;
    root = b;
    a->setBalanceAndHeight();
    b->setBalanceAndHeight();
  }

  if(b->balanced == L) {
    c = b->left;
    b->left = c->right;
    c->right = b;
    a->right = c->left;
    c->left = a;
    root = c;
    a->setBalanceAndHeight();
    b->setBalanceAndHeight();
    c->setBalanceAndHeight();
  }
}

int AVL::getKey() {
  return key;
}

int AVL::getHeight(AVL* root) {
  if(root == NULL) 
    { return 0; }
  else 
    { return root->height; }
}

void AVL::insert(AVL* &root, int newKey) {
  if(root == NULL) { 
    root = new AVL(newKey); 
  }
  else {
    if(newKey >= root->key) { // go right
      insert(root->right, newKey);
      if( !root->setBalanceAndHeight() ) {
	rebalanceRight(root);
      }
    }
    else { // go left
      insert(root->left, newKey);
      if( !root->setBalanceAndHeight() ) {
	rebalanceLeft(root);
      }
    }
  }
}

void AVL::printNLR(AVL * root) {
  if(root == NULL) return;
  cout << root->key << " ";
  printNLR(root->left);
  printNLR(root->right);
}

void AVL::printLNR(AVL* root) {
  if(root != NULL) {
    printLNR(root->left);
    cout << root->key << " ";
    printLNR(root->right);
  }
}

void AVL::del(AVL* &root, int delKey) {
  if(root != NULL) {
    if(delKey > root->key) {
      del(root->right, delKey);
      if( !root->setBalanceAndHeight() ) { 
	rebalanceLeft(root);
      }
    }
    else if(delKey < root->key) {
      del(root->left, delKey);
      if( !root->setBalanceAndHeight() ) {
	rebalanceRight(root);
      }
    }
    else {
      root = remove(root);
    }
  }
}

AVL* AVL::remove(AVL* &root) {
  /* ========== Case 1 : no child ========== */
  if(root->left == NULL && root->right == NULL) {
    delete root;
    return NULL;
  }

  /* ========== Case 2 : got one child ========== */
  if(root->left != NULL && root->right == NULL) {
    AVL* temp = root->left;
    delete root;
    return temp;
  }
  
  if(root->left == NULL && root->right != NULL) {
    AVL* temp = root->right;
    delete root;
    return temp;
  }

  /* ========== Case 3 : lot of children ========== */
  if(root->left != NULL && root->right != NULL) {
    AVL* _root = root;
    AVL *rem = root; // to-remove node
    AVL *dad = NULL; // dad of the leftmost node
    AVL *ng = NULL;  // next greater node
    AVL *ngR = NULL; // right node of Next Greater node
    AVL *remL = NULL; // left of to-remove node
    AVL *remR = NULL; // right of to-remove node

    _root = root->right;

    if(_root->left == NULL) {
      ng = _root;
      remL = rem->left;
    }
    else {
      dad = removeNextGreater(_root);
      ng = dad->left;
      ngR = dad->left->right;
      remL = rem->left;
      remR = rem->right;
    }

    ng->left = remL;
    ng->right = remR;

    if(ngR != NULL) {
      dad->left = ngR;
    }
    else {
      if(dad != NULL) dad->left = NULL;
    }

    rem->left = NULL;
    rem->right = NULL;
    delete rem;

    return ng;
  }
}

AVL* AVL::removeNextGreater(AVL* &root) {
  AVL *nextGreater, *_root = root;

  while(_root->left != NULL) {
    nextGreater = _root;
    _root = _root->left;
  }
  
  return nextGreater;
}

AVL* AVL::removeLeft(AVL* &root) {
  
}
