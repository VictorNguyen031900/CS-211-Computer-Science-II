#include <iostream>
using namespace std;

typedef double* doubleptr;

int main()
{
  int arraySIZE;
  do{
  cout << "Please enter the amount of desired elements: ";
  cin >> arraySIZE;
  if(arraySIZE > 12)
    {
      cout << "Input is over 12!  There is 12 months in a year." << endl;
    }
  else if(arraySIZE < 1)
    {
      cout << "Input is under 1!  There isn't 0 months in a year." << endl;
    }
  } while((arraySIZE > 12) || (arraySIZE < 1));

  double *arrayptr = nullptr;
  arrayptr = new double[arraySIZE];

  double hold = 0;
  for(int i = 0; i < arraySIZE; i++)
    {
      cout << "Enter the monthly sales for month " << i + 1 << ": ";
      cin >> hold;
      *(arrayptr + i) = hold;
    }  
  hold = 0;
  for(int i = 0; i < arraySIZE; i++)
    {
      hold += *(arrayptr + i);
    }

  cout << "The total sales for the year is: $" << hold << endl;

  delete [] arrayptr;
  arrayptr = nullptr;

  return 0;
}
