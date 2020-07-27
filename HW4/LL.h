//This is Elel.h for Class LL
#ifndef LL_H
#define LL_H
#include "LL.h"
#include "node.h"
#include <iostream>
#include <string>

using namespace std;

class LL
{

 private:
  node *head;

 public:
  LL();
  LL(const LL &);
  ~LL();
  void insert(string, string);
  void searchByName(string);
  void destroy();
  void print();
  void reverse();
  void removeRecord(string);
  void updateNumber(string, string);
  void printReverse();
  void insertAtPos(string, string, int);
  void readFromArrays(string [], string [], int);
  LL& operator= (const LL &);
};

#endif

