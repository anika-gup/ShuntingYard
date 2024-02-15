// binary tree.h
#ifndef BINARY_H
#define BINARY_H

#include "Node.h"
#include <iostream>

using namespace std;

class binarytree {

 public:
  binarytree(Node* n);
  ~binarytree();

  void setLeft(Node* tleft);
  Node* getLeft();

  void setRight(Node* tright);
  Node* getRight();

  Node* getNode();

 private:
  Node* current;
  Node* left;
  Node* right;



} ;

#endif 
