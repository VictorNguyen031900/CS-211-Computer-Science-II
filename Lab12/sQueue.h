//Static Queue
#ifndef SQUEUE_H
#define SQUEUE_H
#include <iostream>

using namespace std;

const int MAX = 5;
typedef char el_t;

class Queue
{
 private:
  el_t Arr[MAX];
  int front;
  int rear;
  int amount;

 public:
  Queue();
  void enqueue(el_t);
  void dequeue(el_t &);
  bool isFull() const;
  bool isEmpty() const;
  void displayAll() const;

};

#endif
