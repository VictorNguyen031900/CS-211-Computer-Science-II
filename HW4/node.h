//This is node.h for Class Node
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
using namespace std;

class node
{
  friend class LL;

 private:
  string name;
  string phoneNumber;
  node *next;

 public:

};

#endif

