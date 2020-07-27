// This is static stack
#ifndef SSTACK_H
#define SSTACK_H
#include <iostream>
#include <string>

using namespace std;

const int MAX = 5;
typedef char el_t;

class Stack
{
 private:
  el_t Arr[MAX];
  int topEl;

 public:
  Stack();
  void push(el_t);
  void pop(el_t &);
  bool isEmpty();
  bool isFull();
  void displayAll();
};

#endif
