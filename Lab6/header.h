#ifndef HEADER_H
#define HEADER_H
#include <iostream>

using namespace std;

class RationalNumber
{
  friend RationalNumber operator++ (RationalNumber&, int);
  friend ostream& operator<< (ostream&, const RationalNumber&);
  friend istream& operator>> (istream&, RationalNumber&);
 private:
  int numerator;
  int denominator;
 public:
  RationalNumber();
  RationalNumber(int, int);
  RationalNumber operator- (const RationalNumber&);
};

#endif
