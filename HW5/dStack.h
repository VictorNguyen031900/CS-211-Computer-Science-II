#ifndef DSTACK_H
#define DSTACK_H
#include <iostream>

using namespace std;

typedef char el_t;

class Stack
{
 private:
  struct StackNode //Node that hold information
  {
    el_t element;
    StackNode *next; //Points to next node
  };

  StackNode *top; //Points to top of the stack, a node

 public:
 Stack();
 ~Stack();
 void push(el_t);
 void pop(el_t &);
 void displayAll() const;
 bool isEmpty() const;
 void destroy();
 bool ProperlyBalanced(string);
};

#endif
