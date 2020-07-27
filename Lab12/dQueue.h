//dynamic queue
#ifndef DQUEUE_H
#define DEQUEUE_H
#include <iostream>
using namespace std;

typedef char el_t;

class Queue
{
 private:
  struct QueueNode
  {
    el_t letter;
    QueueNode *next;
  };

  QueueNode *front;
  QueueNode *rear;

  int amount;

 public:
  Queue();
  ~Queue();
  void enqueue(el_t);
  void dequeue(el_t &);
  void displayAll() const;
  bool isEmpty() const;
  void destroy();
};

#endif
