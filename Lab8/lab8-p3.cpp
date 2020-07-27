#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int numChars(string, char, int);

int main()
{
  string text;
  char character;
  int sIndex = 0;
  int occur;
  cout << "Please enter a string: ";
  getline(cin, text);
  cout << "Please enter a character to search for occurrences: ";
  cin >> character;
  occur = numChars(text, character, sIndex);
  if(occur == 1)
    {
      cout << "The character '" << character << "' appears once in string \"" << text << "\""<<  endl;
    }
  else
    {
      cout << "The character '" << character << "' appears " << occur << " times in string \"" << text << "\""<<  endl;
    }
  return 0;
}

int numChars(string check, char letter, int index)
{
  int stringSize = check.size();
  if(index > stringSize)
    {
      return 0;
    }
  else if(check[index] == letter)
    {
      return 1 + numChars(check, letter, index + 1);
    }
  else
    {
      return 0 + numChars(check, letter, index + 1);
    }
}
