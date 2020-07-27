/*******************************************************************************************

Creator: Victor Nguyen
Date: 4/29/2019
Course: CS211
Description: In this program the user will enter a string in to the program and the program
 will determine if the string is "properly balanced" meaning that there is and equal amount
 of braces, parentheses and brackets. If the string is not properly balanced and the program
 will inform the user why it is not balanced such as missing a brace, parenthese, 
 and bracket.

*******************************************************************************************/
#include "dStack.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
  Stack s; //Initialize stack to hold ( , ) , [ , ] , { , and }
  el_t i; //i is a char used as a sentinel value, 'y' to continue or 'n' to end loop
  string userInput; //string used to hold the user's input
  while((i != 'n') && (i != 'N')) //keep looping until user enters 'n' or 'N'
    {
      cout << "Enter a string: ";
      getline(cin, userInput); //get input and put it in to string userInput
      if(s.ProperlyBalanced(userInput)) //if ProperlyBalanced is true, continue if statement
	cout << "It is properly balanced!" << endl;
      else //if ProperlyBalanced is false, continue to else statement
	cout << "It is not properly balanced!" << endl;
      cout << "Do you want to continue! Y/N: ";
      cin >> i; //User enters a sentinel calue 'y' or 'n'
      cin.ignore();
    }
  return 0;
}
