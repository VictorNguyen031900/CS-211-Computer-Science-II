// This is static stack
#include "sStack.h"
#include <iostream>
#include <string>

using namespace std;

Stack::Stack()
{
  for(int i = 0; i < MAX; i++)
    {
      Arr[i] = -1;
    }
  topEl = -1;
}

void Stack::push(el_t in)
{
  if(isFull())
    {
      cout << "Overflow (can't push " << in << ")" << endl;
    }
  else
    {
      topEl++;
      Arr[topEl] = in;
    }
}

void Stack::pop(el_t &out)
{
  if(isEmpty())
    {
      cout << "Underflow (can't pop)" << endl;;
    }
  else
    {
      out = Arr[topEl];
      Arr[topEl] = -1;
      topEl--;
    }
}


bool Stack::isEmpty()
{
  if(Arr[0] == -1)
    {
      return true;
    }
  else
    {
      return false;
    }
}

bool Stack::isFull()
{
  if(Arr[MAX - 1] != -1)
    {
      return true;
    }
  else
    {
      return false;
    }
}

void Stack::displayAll()
{
  if(isEmpty())
    {
      cout << "There is nothing to print out." << endl;
    }
  else
    {
      //      cout << "entering print loop. - top is " << topEl << endl;
        for(int i = topEl; i >= 0; i--)
      	{
      	  cout << Arr[i] << endl;       
      	}
    }
}
