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

  void setLeft(binarytree* tleft);
  binarytree* getLeft();

  void setRight(binarytree* tright);
  binarytree* getRight();

  Node* getNode();

  binarytree* getNext();
  void setNext(binarytree* tnext);

 private:
  Node* current;
  binarytree* left;
  binarytree* right;
  binarytree* next;


} ;

#endif 
