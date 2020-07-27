#include "dStack.h"
#include <iostream>

using namespace std;

Stack::Stack()
{
  top = nullptr;
}

Stack::~Stack()
{
  cout << "Destroying stack." << endl;
  destroy();
}

void Stack::push(el_t in)
{
  StackNode *newNode; 
  newNode = new StackNode;
  newNode->element = in;
  newNode->next = top;

  if(isEmpty())
    {
      top = newNode;
      newNode->next = nullptr;
    }
  else
    {
      newNode->next = top;
      top = newNode;
    }
}

void Stack::pop(el_t &out)
{
  StackNode *temp;

  if(isEmpty())
    {
      cout << "The stack is empty." << endl;
    }
  else
    {
      out = top->element;
      temp = top->next;
      delete top;
      top = temp;
    }
}

void Stack::getTop(el_t &element) const
{
  element = top->element;
}

void Stack::displayAll() const
{
  StackNode *temp = new StackNode;
  temp = top;
  while(temp != nullptr)
    {
      cout << temp->element << endl;
      temp = temp->next;
    }
}

bool Stack::isEmpty()const
{
  if(top == nullptr)
    {
      return true;
    }
  else
    {
      return false;
    }
}

void Stack::destroy()
{
  StackNode *temp;

  while(top != nullptr)
    {
      temp = top->next;
      delete top;
      top = temp;
    }
}
