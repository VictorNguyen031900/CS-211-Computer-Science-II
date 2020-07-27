#ifndef DSTACK_H
#define DSTACK_H
#include <iostream>

using namespace std;

typedef char el_t;

class Stack
{
 private:
  struct StackNode
  {
    el_t element;
    StackNode *next;
  };

 StackNode *top;

 public:
 Stack();
 ~Stack();
 void push(el_t);
 void pop(el_t &);
 void getTop(el_t &) const;
 void displayAll() const;
 bool isEmpty() const;
 void destroy();
};

#endif
