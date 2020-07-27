#include <iostream>
#include <iomanip>

using namespace std;

int multiply(int, int);

int main()
{
  int x;
  int y;
  int total;
  cout << "Enter integer x: ";
  cin >> x;
  cout << "Enter integer y: ";
  cin >> y;
  total = multiply(x, y);
  cout << x << " times " << y << " equals " << total << endl;
  return 0;
}

int multiply(int a, int b)
{
  if(b == 1)
    {
      return a;
    }
  else if(b == 0)
    {
      return 0;
    }
  else
    {
      return a + multiply(a, (b - 1));
    }
}
