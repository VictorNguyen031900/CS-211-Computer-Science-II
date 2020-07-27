//This is lab 11 problem 1
#include "sStack.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
  Stack s;
  char c;

  cout << "inital stack contents" << endl;
  s.displayAll();

  s.pop(c);

  s.push('a');
  cout << endl << "stack contents after pushing a: " << endl;
  s.displayAll();

  s.push('b');
  cout <<  endl << "stack contents after pushing b: " << endl;
  s.displayAll();

  s.push('c');
  s.push('d');
  s.push('e');
  s.push('f');
  s.push('g');
  cout << endl << "stacks contents after pushing c-g: " << endl;
  s.displayAll();

  s.pop(c);
  cout << endl << c << endl;
  cout << endl << "stack contents after popping one element: " << endl;
  s.displayAll();

  s.pop(c);
  cout << endl << "popped element: " << c << endl;
  cout << endl << "stack contents after popping another element: " << endl;
  s.displayAll();

  s.pop(c);
  s.pop(c);
  s.pop(c);
  cout << endl << "stack contents after popping 3 more elements: " << endl;
  s.displayAll();

  s.pop(c);
  s.push('a');
  s.push('b');

  cout << endl << "final stack contents" << endl;
  s.displayAll();

  return 0;
}
