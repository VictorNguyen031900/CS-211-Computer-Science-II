#include "dQueue.h"
#include <iostream>

using namespace std;

int main()
{
  Queue q;
  el_t c;

  cout << "Initial Queue contents" << endl;
  q.displayAll();

  q.dequeue(c);

  q.enqueue('a');
  cout << endl << "Queue contents after adding a: " << endl;
  q.displayAll();

  q.enqueue('b');
  q.enqueue('c');
  q.enqueue('d');
  q.enqueue('e');
  q.enqueue('f');
  cout << endl << "Queue contents after adding b-f: " << endl;
  q.displayAll();

  q.dequeue(c);
  cout << endl << c << endl;
  cout << endl << "Queue contents after removing one element: " << endl;
  q.displayAll();

  q.dequeue(c);
  cout << endl << "Remvoed element: " << c << endl;
  cout << endl << "Queue contents after removing another element: " << endl;
  q.displayAll();

  q.enqueue('g');
  q.enqueue('h');
  q.enqueue('i');
  cout << endl << "Queue contents after adding g, h, i: " << endl;
  q.displayAll();

  q.dequeue(c);
  q.dequeue(c);
  q.dequeue(c);
  q.dequeue(c);
  cout << endl << "Queue contents after removing 4 elements: " << endl;
  q.displayAll();

  q.dequeue(c);
  q.dequeue(c);
  cout << endl << "Final Queue contents: " << endl;
  q.displayAll();

  return 0;
}
