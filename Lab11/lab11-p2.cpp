#include "dStack.h"
#include <iostream>

using namespace std;

int main()
{
  Stack s;
  el_t c;

  cout << "initial stack contents" << endl;
  s.displayAll();

  s.pop(c);

  s.push('a');
  cout << endl << "stack contents after pushing a: " << endl;
  s.displayAll();

  s.push('b');
  cout << endl << "stack contents after pushing b: " << endl;
  s.displayAll();

  s.push('c');
  s.push('d');
  s.push('e');
  s.push('f');
  s.push('g');
  cout << endl << "stack contents after pushing c-g" << endl;
  s.displayAll();

  s.getTop(c);
  cout << endl << "top element is " << c << endl;

  s.pop(c);
  cout << endl << c << endl;
  cout << endl << "stack contents after popping one element: " << endl;
  s.displayAll();

  s.pop(c);
  cout << endl << "popped element: " << c << endl;
  cout << endl << "stack conntenst after popping another element: " << endl;
  s.displayAll();

  s.pop(c);
  s.pop(c);

  if(!s.isEmpty())
    {
      s.getTop(c);
      cout << endl << "top element is " << c << endl;
    }

  s.pop(c);
  cout << endl << "stack contents after popping 3 more elements: " << endl;
  s.displayAll();

  s.pop(c);
  s.pop(c);

  s.push('a');
  s.push('b');

  cout << endl << "final stack contents" << endl;
  s.displayAll();

  return 0;
}
