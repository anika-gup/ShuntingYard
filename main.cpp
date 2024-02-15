// main.cpp for shunting yad


/*

currently need to finish pop (remove top value from stack)

next finish queue (add to back of queueu linked list) and then dequeue (which is basically pop but for queueueueueu)

and then AFTERWARDS do binary tree stuff


 */
#include <iostream>
#include "Node.h"
#include "binarytree.h"
#include <cstring>
#include <ctype.h>

using namespace std;


void ADD(char equation[50], Node* &qhead, Node* &shead);
void push(Node* &shead, Node* &current);
Node* pop(Node* &shead);
void peek(Node* &shead);
void enqueue(Node* &qhead, Node* &current);
void dequeue(Node* &qhead);
void printLinkedList(Node* head);
int precedence(char c);

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
  int precedence(char c);
  // adding each thing from the equation into stuff
  ADD(equation, qhead, shead);
  // print output queue
  //printLinkedList(qhead);
  
  return 0;
}

void ADD(char equation[50], Node* &qhead, Node* &shead) {
  cout << "reached adding function" << endl;
  cout << "youw ant to add: " << equation << endl;
  for (int i=0; i<strlen(equation); i++) {


    /*
    cout << "---------------------------" << endl;
    cout << "printing queue: " << endl;
    printLinkedList(qhead);
    cout << endl;
    cout << "printing stack: " << endl;
    printLinkedList(shead);

    */
    // if it's a number, add to output queue
    if (isdigit(equation[i])) {
      Node* current = new Node(equation[i]);
      cout << "number, add to queue" << endl;
      enqueue(qhead, current);
    }


    
    else if (equation[i]=='+' || equation[i]=='-' || equation[i]=='*' || equation[i]=='^' || equation[i]=='/') {
      // is operator
      cout << "operator: " << equation[i] << endl;


      /*
      while (shead!=NULL && shead->getValue()!='(')  {
	cout << "stack head: " << shead->getValue() << endl;
	if (precedence(shead->getValue())>=precedence(equation[i])) {
	  cout << "precedence is greater ting" << endl;
	  Node* popped = pop(shead);
	  enqueue(qhead, popped);
	}
	else {
	 
	  break;
	}
       
      }

      */

      /// adding operator to stack
      cout << "adding operator to stack." << endl;
      Node* current = new Node(equation[i]);
      push(shead, current);

    }
    
    
    /*
    else if (equation[i]=='(') {
      // is left parenthesis

      // push to operator stack
      cout << "push left parenthesis to operator stack" << endl;
      Node* current = new Node(equation[i]);
      push(shead, current);
    }

    
    else if (equation[i]==')') {

      
      // is right parenthesis
      cout << "right parenthesis" << endl;
      while(shead->getValue()!='(') {
	if (shead==NULL) {
	  cout << "invalid. not matching parenthesis)." << endl;
	  break;
	  return;
	}
	else {
	  Node* popped = pop(shead);
	  cout << "enqueueing + popping the: " << popped->getValue() << endl;
	  enqueue(qhead, popped);
	}
      }
      if (shead==NULL) {
	cout << "invalid not matching parentehsis." << endl;
      }
      else if (shead->getValue()=='(') {
	cout << "popping left parentehsis out of stack" << endl;
	cout << "the thing to pop off is: " << shead->getValue();
	Node* pod=pop(shead);
	pod->~Node();
	delete pod;
	//pop(shead)->~Node();
	//cout << "current head of stack is: " << shead->getValue() << endl;
      }
    }
    */
  }

    //*/

  
  Node* cur = shead;
  while(shead!=NULL) {
    cout << "ther's more after.." << endl;
    cur = shead;
    if (cur->getValue()=='(' || cur->getValue()==')') {
      cout << "invalid, not matching parenthesis." << endl;
      break;
      return;
    }
    cout << "head of stack: " << shead->getValue() << endl;
    
    Node* poppeda = pop(shead);
    
    cout << "now enqueing" << endl;
    cout << "enqueueing: " << poppeda->getValue() << endl;
    enqueue(qhead, poppeda);
    if (shead==NULL) {
      break;
      return;
    }
    cur = shead;
  }
  cout << "current is not null" << endl;

}



void push(Node* &shead, Node* &current) {
  // add to stack
  // adds to TOP (push head to next)
  //cout << "pushing : " << current->getValue() << endl;
  Node* store = shead;
  shead = current;
  shead->setNext(store);

  //printLinkedList(shead);
  // push is working !

  
}

void printLinkedList(Node* head) {
  Node* c = head;
  cout << "printing LL" << endl;
  while(c->getNext()!=NULL) {
    cout << c->getValue() << " " << endl;
    c = c->getNext();
  }
}


Node* pop(Node* &shead) {
  // removes from stack
  // removes from TOP (head->getNext() becomes new head)
  cout << "trying to pop off: " << shead->getValue() << endl;
  if (shead==NULL) {
    return NULL;
  }
  Node* copyHead = shead;
  if (shead->getNext()==NULL) {
    Node* chead = shead;
    shead = NULL;
    return chead;
  }
  Node* newh = shead->getNext();
  //shead->~Node();
  shead = newh;
  cout << "post pop print: " << endl;
  printLinkedList(shead);
  
  return copyHead;
}


void peek(Node* &shead) {
  // prints out value of head of stack

  //cout << shead->getValue() << endl;
  
}

void enqueue(Node* &qhead, Node* &current) {
  // adds a node to BACK of que
  //cout << "reahced enqueueueue" << endl;
  
  if (qhead==NULL) {
    qhead = current;
  }
  else {

    Node* c = qhead;
    while (c->getNext()!=NULL) {
      
      //cout << c->getValue() << endl;
      c = c->getNext();
    }
    c->setNext(current);
  }

  // enqueueuueue works
  
}
void dequeue(Node* &qhead) {
  // removes from TOP of queue (same as pop function .....)
  if (qhead==NULL) {
    return;
  }
  Node* newh = qhead->getNext();
  qhead->~Node();
  qhead = newh;
 
}

int precedence(char c) {
   if (c=='^') {
     return 3;
   }
   else if (c=='/' || c=='*') {
     return 2;
   }
   else if (c=='+' || c=='-') {
     return 1;
   }

   return 0;
 }