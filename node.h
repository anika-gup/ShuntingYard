#ifndef NODE_H
#define NODE_H


#include <iostream>
using namespace std;
class Node {
public:
    Node(char data);
    ~Node();

    void setNext(char n);
    void setNext(Node* n);

    char getValue();
    Node* getNext();

private:
    char value;
    Node* next;
};

#endif // NODE_H

