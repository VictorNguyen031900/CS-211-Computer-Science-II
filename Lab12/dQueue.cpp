//Dynamic Queue
#include "dQueue.h"
#include <iostream>
using namespace std;

Queue::Queue()
{
  front = nullptr;
  rear = nullptr;
  amount = 0;
}

Queue::~Queue()
{
  cout << "Destroying queue list!" << endl;
  amount = 0;
  destroy();
}

void Queue::enqueue(el_t in)
{
  QueueNode *newNode;
  newNode = new QueueNode;
  newNode->letter = in;
  newNode->next = nullptr;
  if(isEmpty())
    {
      front = newNode;
      rear = newNode;
    }
  else
    {
      rear->next = newNode;
      rear = newNode;
    }
  amount++;
}

void Queue::dequeue(el_t &out)
{
  QueueNode *temp;
  if(isEmpty())
    {
      cout << "Underflow! There is nothing in the queue to dequeue!" << endl;
    }
  else
    {
      out  = front->letter;
      temp = front;
      front = front->next;
      delete temp;
      amount--;
    }
}

void Queue::displayAll() const
{
  QueueNode *temp;
  temp = front;
  if(isEmpty())
    {
      cout << "Underflow! There is nothing in the queue to print!" << endl;
    }
  else
    {
      while(temp != nullptr)
	{
	  cout << temp->letter << " ";
	  temp = temp->next;
	}
    }
  cout << endl;
}

bool Queue::isEmpty() const
{
  if(amount == 0)
    {
      return true;
    }
  else
    {
      return false;
    }
}

void Queue::destroy()
{
  QueueNode *temp;
  char dummy;

  while(isEmpty() != true)
    {
      dequeue(dummy);
    }
}
