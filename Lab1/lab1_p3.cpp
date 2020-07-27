/*****************************************************************************************

Victor Nguyen
CS 211
1/28/19

*****************************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

void minMaxAvg (int &, int &, double &);

int main()
{
  int a;
  int b;
  double c;
  cout << "Enter 3 integers: ";
  cin >> a >> b >> c;
  minMaxAvg(a, b, c);
  cout << showpoint << fixed << setprecision(2) << "The average is: " << c << endl;
  cout << "The min is: " << b << endl;
  cout << "The max is: " << a << endl;
  return 0;
}

void minMaxAvg(int &a1, int &b1, double &c1)
{
  int a = a1;
  int b = b1;
  int c = c1;
  int max = a1;
  int min = a1;
  double avg = 0;
  if (a > b && a > c)
    {
      max = a;
    }
  else if (b > a && b > c)
    {
      max = b;
    }
  else if (c > a && c > b)
    {
      max = c;
    }

  if (a < b && a < c)
    {
      min = a;
    }
  else if (b < a && b < c)
    {
      min = b;
    }
  else if (c < a && c < b)
    {
      min = c;
    }

  avg = (a + b + c) / 3.0;
  c1 = avg;
  b1 = min;
  a1 = max;
}
