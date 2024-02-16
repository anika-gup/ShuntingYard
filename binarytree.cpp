#include "binarytree.h"
#include <iostream>
#include <cstring>

using namespace std;


binarytree::binarytree(Node* n) {
  current = n;
  right = NULL;
  left = NULL;
}

binarytree::~binarytree() {
  delete current;
  delete right;
  delete left;
}


void binarytree::setLeft(binarytree* tleft) {
  left = tleft;
}

binarytree* binarytree::getLeft() {
  return left;
}


void binarytree::setRight(binarytree* tright) {
  right = tright;
}

binarytree* binarytree::getRight() {
  return right;
}

Node* binarytree::getNode() {
  return current;
}

binarytree* binarytree::getNext() {
  return next;
}
void binarytree::setNext(binarytree* tnext) {
  next = tnext;
}
