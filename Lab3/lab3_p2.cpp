/***********************************************************************************************

Victor Nguyen
CS211
2-8-19

**********************************************************************************************/

#include<iostream>
#include<string>

using namespace std;

bool isPalindrome(const string);

int main()
{
  bool isTrueValue; 
  string userIn;
  cout << "Please enter in a Palindrome: ";
  getline(cin, userIn);
  isTrueValue = isPalindrome(userIn);
  if(isTrueValue == true)
    {
      cout << "What you entered is a Palindrome :) ." << endl;
    }
      else if(isTrueValue == false)
    {
      cout << "Sorry, what you entered is not a Palindrome :( ." << endl;
    }
    return 0;
}

bool isPalindrome(const string hold)
{
  bool isTrue;
  string testIf = hold;
  int place = testIf.find(" ", 0);
  while(place != testIf.npos)
    {
      testIf.erase(place, 1);
      place = testIf.find(" ", place+1);
    }

  int size = testIf.size();
  char palin[size];
  char reverseTest[size];
  int j = size;
  char k;
  for(int i = 0; i < size; i++)
    {
      palin[i] = testIf[i];
      reverseTest[i] = testIf[i];
    }
  for(int i = 0; i < j; i++)
    {
      j--;
      k = reverseTest[i];
      reverseTest[i] = reverseTest[j];
      reverseTest[j] = k;
    }
  for(int i = 0; i < size; i++)
    {
      if(palin[i] == reverseTest[i])
	{
	  isTrue = true;
	}
      else
	{
	  isTrue = false;
	  break;
	}
    }
  return isTrue;
}
