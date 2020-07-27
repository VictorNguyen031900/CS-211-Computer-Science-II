#include "header.h"
#include <iostream>

using namespace std;

RationalNumber::RationalNumber()
{
  numerator = 0;
  denominator = 1;
}

RationalNumber::RationalNumber(int a, int b)
{
  numerator = a;
  denominator = b;
}

RationalNumber RationalNumber::operator-(const RationalNumber& c)
{
  RationalNumber temp;
  temp.numerator = (numerator * c.denominator) - (c.numerator * denominator);
  temp.denominator = denominator * c.denominator;
  return temp;
}

RationalNumber operator++(RationalNumber &c, int dummy)
{
  RationalNumber temp;
  temp = c;
  c.numerator = c.numerator + c.denominator;
  return temp;
}

ostream& operator<<(ostream& os, const RationalNumber& c)
{
  os << c.numerator;
  os << "/";
  os << c.denominator;
  os << endl;
  return os;
}

istream& operator>>(istream& is, RationalNumber& c)
{
  is >> c.numerator;
  is >> c.denominator;
  return is;
}
