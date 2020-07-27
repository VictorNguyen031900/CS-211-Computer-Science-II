/**************************************************************************************
Victor Nguyen
CS 211
2--19
**************************************************************************************/

#include<iostream>
#include<string>

using namespace std;

void ReplaceSubString(const string, const string, const string);

int main()
{
  string string1;
  string string2;
  string string3;
  cout << "Enter a string: ";
  getline(cin, string1);
  cout << endl << "Now enter a target word: ";
  cin >> string2;
  cout << endl << "Now enter a replacement word for the target: ";
  cin >> string3;
  ReplaceSubString(string1, string2, string3);
  return 0;
}

void ReplaceSubString(const string one, const string two, const string three)
{
  string string4 = one;
  int sizeTwo = two.size();
  int sizeThree = three.size();
  int a = string4.find(two, 0);
  while(a != string4.npos)
    {
      string4.replace(a, sizeTwo, three);
      a = string4.find(two, a+1);
    }

  cout << endl << "The word " << "\"" << two << "\"" << " was replaced with " << "\"" << three << "\"" << " it is now: \"" << string4 << "\"" << endl;
}
