// main.cpp for shunting yad


/*

currently need to finish pop (remove top value from stack)

next finish queue (add to back of queueu linked list) and then dequeue (which is basically pop but for queueueueueu)

and then AFTERWARDS do binary tree stuff


 */
#include <iostream>
#include "Node.h"
#include <cstring>
#include <ctype.h>

using namespace std;


void ADD(char equation[50], Node* &qhead, Node* &shead);
void push(Node* &shead, Node* &current);
void pop(Node* shead);
void peek(Node* &shead);
void enqueue(Node* qhead, Node* &current);
void dequeue(Node* &qhead);
void printLinkedList(Node* head);


int main() {

  // testing:
  /*
  cout << "main" << endl;
  char g = 'g';
  Node* newNode = new Node(g);
  cout << "ur node has value: " << newNode->getValue() << endl;
  Node* nextNode = new Node('a');
  newNode->setNext(nextNode);
  cout << "current node has next value of: " << newNode->getNext()->getValue() << endl;
  */
  Node* qhead = NULL; // head of queue
  Node* shead = NULL; //head of stack 
  cout << "WHats your equation" << endl;
  char equation[50];
  cin >> equation;
  ADD(equation, qhead, shead);
  return 0;
}

void ADD(char equation[50], Node* &qhead, Node* &shead) {
  cout << "reached adding function" << endl;
  cout << "youw ant to add: " << equation << endl;
  for (int i=0; i<strlen(equation); i++) {
    if (isdigit(equation[i])) {
      cout << "it's a number: " << equation[i] << endl;
      Node* current = new Node(equation[i]);
      push(shead, current);
    }
  }
  
}

void push(Node* &shead, Node* &current) {
  // add to stack
  // adds to TOP (push head to next)
  cout << "pushing : " << current->getValue() << endl;
  Node* store = shead;
  shead = current;
  shead->setNext(store);

  //  printLinkedList(shead);
  // push is working !
}

void printLinkedList(Node* head) {
  Node* c = head;
  while(c!=NULL) {
    cout << c->getValue() << " " << endl;
    c = c->getNext();
  }
}
void pop(Node* &shead) {
  // removes from stack
  // removes from TOP (head->getNext() becomes new head)
}

void peek(Node* &shead) {
  // prints out value of head of stack
}

void enqueue(Node* &qhead, Node* &current) {
  // adds a node to BACK of que
}
void dequeue(Node* &qhead) {
  // removes from TOP of queue (same as pop function .....)
}
