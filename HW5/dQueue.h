//dynamic queue
#ifndef DQUEUE_H
#define DEQUEUE_H
#include <iostream>
using namespace std;

typedef string el_t;

class Queue
{
 private:
  struct QueueNode //Node that hold information
  {
    el_t letter;
    QueueNode *next; //Points to next node in queue
  };

  QueueNode *front; //Front of the queue
  QueueNode *rear; //Rear of the queue

  int amount;

 public:
  Queue();
  ~Queue();
  void enqueue(el_t);
  void dequeue(el_t &);
  void displayAll() const;
  bool isEmpty() const;
  void destroy();
  void permutations();
};

#endif
