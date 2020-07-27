//Static Queue
#include "sQueue.h"
#include <iostream>

using namespace std;

Queue::Queue()
{
  for(int i = 0; i < MAX; i++)
    {
      Arr[i] = -1;
    }
  front = -1;
  rear = -1;
  amount = 0;
}

void Queue::enqueue(el_t in)
{
  if(isEmpty())
    {
      front = 0;
      amount++;
      Arr[front] = in;
      rear = 0;
    }
  else if(isFull())
    {
      cout << "Queue is Full. Can't queue in " << in << "." << endl;
    }
  else
    {
      rear++;
      if((rear == MAX) && (amount != MAX))
	{
	  rear = 0;
	  Arr[rear] = in;
	  amount++;
	}
      else
	{
	  Arr[rear] = in;
	  amount++;
	}
    }
}

void Queue::dequeue(el_t &out)
{
  if(isEmpty())
    {
      cout << "The queue is empty! Can't dequeue anything!" << endl;
    }
  else
    {
      out = Arr[front];
      Arr[front] = -1;
      front++;
      if(front == MAX)
	{
	  front = 0;
	  amount--;
	}
      else
	{
	  amount--;
	}
    }
}

bool Queue::isFull() const
{
  if(amount == MAX)
    {
      return true;
    }
  else
    {
      return false;
    }
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

void Queue::displayAll() const
{
  if(isEmpty())
    {
      cout << "Queue is empty! Can't print anything!" << endl;
    }
  else if(rear < front)
    {
      for(int i = front; i < MAX; i++)
	{
	  cout << Arr[i] << endl;
	}

      for(int i  = 0; i <= rear; i++)
	{
	  cout << Arr[i] << endl;
	}
    }
  else
    {
      for(int i = front; i <= rear; i++)
	{
	  cout << Arr[i] << endl;
	}
    }

  //cout << "Test print array" << endl;
  //for(int i = 0; i < MAX; i++)
    //{
      //cout << Arr[i] << " ";
      //}
  //cout << endl;
}
