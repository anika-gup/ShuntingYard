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


void binarytree::setLeft(Node* tleft) {
  left = tleft;
}

Node* binarytree::getLeft() {
  return left;
}


void binarytree::setRight(Node* tright) {
  right = tright;
}

Node* binarytree::getRight() {
  return right;
}

Node* binarytree::getNode() {
  return current;
}
