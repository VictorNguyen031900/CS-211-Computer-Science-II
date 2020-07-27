#include <iostream>
using namespace std;

int main()
{
  int length;
  int width;
  int area;

  int *lengthPtr = nullptr;
  int *widthPtr = nullptr;

  cout << "Please Enter the Length: ";
  cin >> length;
  cout << "Please Enter the Width: ";
  cin >> width;
  lengthPtr = &length;
  widthPtr = &width;
  cout << "The Area is: " << *lengthPtr * *widthPtr << endl;
  if(*lengthPtr > *widthPtr)
    {
      cout << "Length is greater than Width." << endl;
      cout << "Length: " << *lengthPtr << endl;
      cout << "Width: " << *widthPtr << endl;
    }
  else
    {
      cout << "Width is greater than Length." << endl;
      cout << "Width: " << *widthPtr << endl;
      cout << "Length: " << *lengthPtr << endl;
    }

  return 0;
}
