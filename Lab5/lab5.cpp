#include "student.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
  Student student1;
  student1.print();

  string name = "unknown";
  string major = "PHYS";
  string classification = "graduate";
  int units = 0;
  Student student2(name, major, classification, units);
  student2.print();

  student2.getData();
  student2.print();

  return 0;
}
