//This is Elel.cpp for Class LL
#include "LL.h"
#include "node.h"
#include <iostream>
#include <string>

using namespace std;

// Default constructor to initialize a linked list
LL::LL()
{
  head = nullptr;
}

// Overloaded constuctor to perform a deep of a initialized linked list
LL::LL(const LL &source)
{
  head = nullptr;
  node *nodePtr2;
  if(source.head == nullptr)
    {
      cout << "There's nothing to copy to new list." << endl << endl;
    }
  else
    {
      nodePtr2 = source.head;
      while(nodePtr2 != nullptr)
	{
	  insert(nodePtr2->name, nodePtr2->phoneNumber);
	  nodePtr2 = nodePtr2->next;
	}
    }
}

// Destroyer function to delete the initialized linked lists after the program is done
LL::~LL()
{
  cout << "Deleted Linked List(s)." << endl << endl;
  destroy();
}

// Insert a new node in to the linked list but place it in the list such that it is in
// alphabetical order
void LL::insert(string pName, string phone)
{
  node *newNode;
  node *nodePtr;
  node *prev;

  newNode = new node;
  newNode->name = pName;
  newNode->phoneNumber = phone;
  newNode->next = nullptr;
  if(!head)
    {
      head = newNode;
    }
  else
    {
      nodePtr = head;
      prev = nullptr;

      while(nodePtr != nullptr)
	{
	  if(nodePtr->name >= newNode->name)
	    {
	      break;
	    }
	  else
	    {
	      prev = nodePtr;
	      nodePtr = nodePtr->next;
	    }
	}

      if(nodePtr == head)
	{
	  newNode->next = head;
	  head = newNode;
	}
      else
	{
	  newNode->next = nodePtr;
	  prev->next = newNode;
	}
    }
}

// Function used to print the whole linked list
void LL::print()
{
  node *nodePtr;
  int *count;

  count = new int;
  *count = 1;
  nodePtr = head;

  while(nodePtr != nullptr)
  {
    cout << *count << ". " << nodePtr->name << ", " << nodePtr->phoneNumber << endl;
    nodePtr = nodePtr->next;
    *count+=1;
  }
  cout << endl;
  delete count;
}

// Function used to find a name in the list and if found 
// output the position of the name in the list
void LL::searchByName(string pName)
{
  node *nodePtr;
  bool *boolPtr = nullptr;
  string *stringPtr = nullptr;
  int *count;

  nodePtr = head;
  boolPtr = new bool;
  stringPtr = new string;
  count = new int;
  *count = 1;

  while(nodePtr != nullptr)
    {
      if(nodePtr->name == pName)
	{
	  *boolPtr = true;
	  *stringPtr = nodePtr->phoneNumber;
	  break;
	}
      else
	{
	  *boolPtr = false;
	  *count+=1;
	}
      nodePtr = nodePtr->next;
    }
  if(*boolPtr == true)
    {
      cout << "Found " << pName << "! Their phone number is " << *stringPtr << ". They're #" << *count << " in the list." << endl;
    }
  else
    {
      cout << "Could not find " << pName << " in our database!" << endl << endl;;
    }
  delete boolPtr;
  delete stringPtr;
  delete count;
}

// Function used to delete each node in the linked list one by one
void LL::destroy()
{
  node *current = head;
  node *next;
  while(current != nullptr)
    {
      next = current->next;
      delete current;
      current = next;
    }
  head = nullptr;
}

// Function uses two arrays to create a node and insert the new node
// in to the linked list
void LL::readFromArrays(string nArr[], string pArr[], int size)
{
  for(int i = 0; i < size; i++)
    {
      insert(nArr[i], pArr[i]);
    }
}

// Function is used to insert a new node in to the linked list at a certain given postion
void LL::insertAtPos(string pName, string phone, int pos)
{
  node *newNode;
  node *nodePtr;
  node *prev;
  int *count;

  count = new int;
  *count = 1;
  newNode = new node;
  newNode->name = pName;
  newNode->phoneNumber = phone;
  newNode->next = nullptr;

  if(!head)
    {
      head = newNode;
    }
  else
    {
      nodePtr = head;
      if(pos == 1)
	{
	  newNode->next = head;
	  head = newNode;
	}
      else
	{
	  while((nodePtr != nullptr) && (pos != *count))
	    {
	      prev = nodePtr;
	      nodePtr = nodePtr->next;
	      *count+=1;
	    }

	  if(nodePtr)
	    {
	      newNode->next = nodePtr;
	      prev->next = newNode;
	    }
	  else if(*count >= pos)
	    {
	      prev->next = newNode;
	    }
	}
    }

  delete count;
}

// Function prints each node in the linked list in reverse order
void LL::printReverse()
{
  reverse();
  print();
  reverse();
}

// Function tranverses the list to find a new in the record and if found
// replace the user's old phone number with their new one
void LL::updateNumber(string pName, string newPhone)
{
  node *nodePtr;
  bool *boolPtr = nullptr;

  nodePtr = head;
  boolPtr = new bool;

  while(nodePtr != nullptr)
    {
      if(nodePtr->name == pName)
        {
          *boolPtr = true;
	  nodePtr->phoneNumber = newPhone;
          break;
        }
      else
        {
          *boolPtr = false;
        }
      nodePtr = nodePtr->next;
    }
  if(*boolPtr == true)
    {
      cout << "Updated " << pName << "'s record to " << newPhone << "." << endl;
    }
  else
    {
      cout << "Could not find " << pName << " in our database in order to change their record!" << endl << endl;;
    }
  delete boolPtr;
}

// Function deletes a node in the linked list based on the name given to the function
void LL::removeRecord(string pName)
{
  node *nodePtr;
  node *prev;
  if(!head)
    {
      return;
    }

  if(head->name == pName)
    {
      nodePtr = head->next;
      delete head;
      head = nodePtr;
    }
  else
    {
      nodePtr = head;
      while((nodePtr != nullptr) && (nodePtr->name != pName))
	{
	  prev = nodePtr;
	  nodePtr = nodePtr->next;
	}

      if(nodePtr)
	{
	  prev->next = nodePtr->next;
	  delete nodePtr;
	}
      else
	{
	  cout << pName << " does not exist in the records!" << endl;
	}
    }
}

// Function is used to copy every node in a list and copy said node
// in to a new linked list
LL& LL::operator=(const LL& source)
{
  node *nodePtr;
  node *newNode;
  nodePtr = source.head;
  destroy();
  while(nodePtr->next)
    {
      insert(nodePtr->name, nodePtr->phoneNumber);
      nodePtr = nodePtr->next;
    }
}

// Function is used to reverse a whole linked list
void LL::reverse()
{
  node *current = head; 
  node *prev = nullptr;
  node *next = nullptr;
  
  while (current != nullptr) 
    { 
      next = current->next; 
      current->next = prev; 
      prev = current; 
      current = next; 
    } 
  head = prev; 
}
