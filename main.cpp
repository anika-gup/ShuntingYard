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
void ADDTOBINARYTREE(Node* &qhead, binarytree* &bthead);
void PUSHBT(binarytree* &bthead, binarytree* &current);
binarytree* POPBT(binarytree* &bthead);
void printBinaryTree(binarytree* bthead);

void IN(binarytree* self, binarytree* side);
void PRE(binarytree* self, binarytree* side);
void POST(binarytree* self, binarytree* side);

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

  binarytree* bthead = NULL; //head of binary tree stack

  
  cout << "WHats your equation" << endl;
  char equation[50];
  //getline(cin, equation);
  cin.get(equation, 50);
  cin.get();
  //cin >> equation;
  int precedence(char c);
  // adding each thing from the equation into stuff
  ADD(equation, qhead, shead);
  // print output queue
  printLinkedList(qhead);


  ADDTOBINARYTREE(qhead, bthead);



  /*
  cout << "printing binary tree" << endl;
  printBinaryTree(bthead);

  */

  cout << "how to print binary tree: infix postfix prefix " << endl;

  char printtype[50];
  cin >> printtype;
  if (strcmp(printtype, "infix")==0) {
    IN(bthead, bthead);
  }
  else if (strcmp(printtype, "postfix")==0) {
    POST(bthead, bthead);
  }
  else if (strcmp(printtype, "prefix")==0) {
    PRE(bthead, bthead);
  }
  else {
    cout << "lo siento pero no entiendo" << endl;
  }
  return 0;
}

void ADD(char equation[50], Node* &qhead, Node* &shead) {
  //cout << "reached adding function" << endl;
  //cout << "youw ant to add: " << equation << endl;
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
      //cout << "number, add to queue" << endl;
      enqueue(qhead, current);
    }


    
    else if (equation[i]=='+' || equation[i]=='-' || equation[i]=='*' || equation[i]=='^' || equation[i]=='/') {
      // is operator
      //cout << "operator: " << equation[i] << endl;


      
      while (shead!=NULL && shead->getValue()!='(')  {
	//cout << "stack head: " << shead->getValue() << endl;
	if (precedence(shead->getValue())>=precedence(equation[i])) {
	  //cout << "precedence is greater ting" << endl;
	  Node* popped = pop(shead);
	  enqueue(qhead, popped);
	}
	else {
	 
	  break;
	}
       
      }

      

      /// adding operator to stack
      //cout << "adding operator to stack." << endl;
      Node* current = new Node(equation[i]);
      push(shead, current);

    }
    
    
    
    else if (equation[i]=='(') {
      // is left parenthesis

      // push to operator stack
      //cout << "push left parenthesis to operator stack" << endl;
      Node* current = new Node(equation[i]);
      push(shead, current);
    }

    
    else if (equation[i]==')') {

      
      // is right parenthesis
      //cout << "right parenthesis" << endl;
      while(shead->getValue()!='(') {
	if (shead==NULL) {
	  //cout << "invalid. not matching parenthesis)." << endl;
	  break;
	  return;
	}
	else {
	  Node* popped = pop(shead);
	  //cout << "enqueueing + popping the: " << popped->getValue() << endl;
	  enqueue(qhead, popped);
	}
      }
      if (shead==NULL) {
	cout << "invalid not matching parentehsis." << endl;
	return;
      }
      else if (shead->getValue()=='(') {
	//cout << "popping left parentehsis out of stack" << endl;
	//cout << "the thing to pop off is: " << shead->getValue();
	Node* pod=pop(shead);
	pod->~Node();
	delete pod;
	//pop(shead)->~Node();
	//cout << "current head of stack is: " << shead->getValue() << endl;
      }
    }
    
  }

    //*/

  
  Node* cur = shead;
  while(shead!=NULL) {
    //cout << "ther's more after.." << endl;
    cur = shead;
    if (cur->getValue()=='(' || cur->getValue()==')') {
      cout << "invalid, not matching parenthesis." << endl;
      break;
      return;
    }
    //cout << "head of stack: " << shead->getValue() << endl;
    
    Node* poppeda = pop(shead);
    
    //cout << "now enqueing" << endl;
    //cout << "enqueueing: " << poppeda->getValue() << endl;
    enqueue(qhead, poppeda);
    if (shead==NULL) {
      break;
      return;
    }
    cur = shead;
  }
  //cout << "current is not null" << endl;

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
  //cout << "printing LL" << endl;
  while(c->getNext()!=NULL) {
    cout << c->getValue() << " ";
    c = c->getNext();
  }
  cout << c->getValue() << endl;
}


Node* pop(Node* &shead) {
  // removes from stack
  // removes from TOP (head->getNext() becomes new head)
  //cout << "trying to pop off: " << shead->getValue() << endl;
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
  //cout << "post pop print: " << endl;
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
  Node* ccurrent = current;
  if (qhead==NULL) {
    qhead = ccurrent;
  }
  else {

    Node* c = qhead;
    int count = 1;
    while (c->getNext()!=NULL) {
      
      //cout << c->getValue() << endl;
      c = c->getNext();
      count ++;
    }
    c->setNext(ccurrent);
    Node* nullnode = NULL;
    c->getNext()->setNext(nullnode);
    cout << "count: " << count << endl;
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


void ADDTOBINARYTREE(Node* &qhead, binarytree* &bthead) {
  
  while(qhead!=NULL) {
    // while the postfix form output queue still has stuff in it...
    cout << "in adding to binary tree while loop." << endl;
    // create new tree and put head of queue in it
    binarytree* newtree = new binarytree(qhead);

    if (isdigit(qhead->getValue())) {
      // if it's a number, push the tree into stack with head sheadnew.
      PUSHBT(bthead, newtree);
      dequeue(qhead);
    }
    else {
      // else it's an operator.
      binarytree* right = POPBT(bthead);
      binarytree* left = POPBT(bthead);
      newtree->setRight(right);
      newtree->setLeft(left);
      PUSHBT(bthead, newtree);
      dequeue(qhead);
      //pop the first thing off of bthead and save it as left
      // pop sheadnew again and save the node as right
      // set newtree left and right as the values
      // push tree in stack
    }
    
  }
}


void PUSHBT(binarytree* &bthead, binarytree* &current) {
  // adds to top of stack
  // this is only for binary trees NOT NODES!
  binarytree* store = bthead;
  bthead = current;
  bthead->setNext(store);
}
binarytree* POPBT(binarytree* &bthead) {
  if (bthead==NULL) {
    return NULL;
  }

  binarytree* copyHead = bthead;
  if (bthead->getNext()==NULL) {
    bthead = NULL;
    return copyHead;
  }
  binarytree* newHead = bthead->getNext();
  bthead = newHead;
  return copyHead;
}



void printBinaryTree(binarytree* bthead) {
  binarytree* c = bthead;
  while (c->getNext()!=NULL) {
    cout << c->getNode()->getValue() << " " ;
    c = c->getNext();
  }

  cout << c->getNode()->getValue() << endl;
}


void IN(binarytree* self, binarytree* side) {
  if (side->getLeft()!=NULL) {
    IN(self->getLeft(), side->getLeft());
  }
  //cout << side->getNode()->getValue() << endl;
  cout << self->getNode()->getValue() ;
  if (side->getRight()!=NULL) {
    IN(self->getRight(), side->getRight());
  }
  //cout << side->getNode()->getValue() << endl;
  
}
void PRE(binarytree* self, binarytree* side) {
  cout << self->getNode()->getValue() ;
  if (side->getLeft()!=NULL) {
    PRE(self->getLeft(), side->getLeft());
  }
  if (side->getRight()!=NULL) {
    PRE(self->getRight(), side->getRight());
  }
}
void POST(binarytree* self, binarytree* side) {
  if (side->getLeft()!=NULL) {
    POST(self->getLeft(), side->getLeft());
  }
  if (side->getRight()!=NULL) {
    POST(self->getRight(), side->getRight());
  }
  cout << self->getNode()->getValue() ;
}
