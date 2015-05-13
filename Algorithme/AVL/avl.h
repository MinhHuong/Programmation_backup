//
//  avl.h
//  AVL
//
//  Created by Nguyen Hua Phung on 4/25/15.
//  Copyright (c) 2015 Nguyen Hua Phung. All rights reserved.
//

#ifndef __AVL__avl__
#define __AVL__avl__

#include <iostream>
#include <stdio.h>

enum BVal {L,EQ,R};

class AVL {
 private:
  int key;
  AVL * left;
  AVL * right;
  BVal balanced;
  int height;

  bool setBalanceAndHeight();
  static AVL * removeNextGreater(AVL *&root);
  static AVL * removeLeft(AVL* &root);
  static void rebalanceLeft(AVL* &root);
  static void rebalanceRight(AVL * &root);
  static std::string printBalance(BVal balance);

 public:
  AVL(int newKey) {
    this->key = newKey;
    this->left = this->right = NULL;
    this->balanced = EQ;
    this->height = 1;
  }

  int getKey();
  static int getHeight(AVL *root);
  static void insert(AVL* &root,int newKey);
  static AVL * remove(AVL* &root);
  static void del(AVL *&root,int delKey);
  static void printLNR(AVL * root);
  static void printNLR(AVL * root);
};

#endif /* defined(__AVL__avl__) */
