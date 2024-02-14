#include "node.h"
#include <iostream>
#include <cstring>
using namespace std;
Node::Node(char data) {
  //creating node, char as data
  value = data;
  next=NULL;
  //cout << "creating node with value: " << value << endl;
}
Node::~Node() {
  // should do nothing because it's storing a char (not pointer) ?  
  //delete value;
}


void Node::setNext(Node* n) {
    next = n;
}

char Node::getValue() {
    return value;
}

Node* Node::getNext() {
    return next;
}

