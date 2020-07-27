#include "header.h"
#include <iostream>
using namespace std;

int main()
{
  RationalNumber r1(7, 3);
  RationalNumber r2(3, 9);
  RationalNumber r3;
  RationalNumber r4;
  r3 = r1 - r2;
  cout << "r3 = " << r3;
  cout << endl;
  r3 = r1++;
  cout << "r3 = " << r3;
  cout << endl;
  cout << "r1 = " << r1;
  cout << endl;
  cout << "Enter numbers for r4: ";
  cin >> r4;
  cout << "r4 = " << r4;
  cout << endl;
  return 0;
}
