/***************************************************************************

Creator: Victor Nguyen
Course: CS211
Date: Match 28, 2019
Homework: Homework Assignement 3 Problem 2
Program Description: This is a program that will compute all permutations
  of a string given by the user and all permutations will be put in a vector
  and then all permutations will be printed from said vector.  The permute 
  function handles all the computations and combinations for the number of
  permutations for a string with n characters. (n being a positive intger)

***************************************************************************/
//g++ -std=c++11 FILENAME.cpp (to complie properly)

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void permute(string, int, int, vector<string> &); //Function used to compute permutations of a string

int main()
{
  string str1; //Input string
  vector<string> permutations; //Vector used to hold all permutations of a string
  int vSize; //Size of vector used later
  int e; //Last index of str1
  cout << endl << "Enter a word to find permutations: ";
  cin >> str1;
  e = (str1.size()) - 1; //Gets length of str1 and decrease by 1
  permute(str1, 0, e, permutations); //Call permute function and pass input string, starting position,
                                     //last index, vector permutations.
  vSize = permutations.size(); //Set vSize to size of vector permutations
  //For loop to print all elements inside vector permutations
  for(int i = 0; i < vSize; i++)
    {
      if(i == (vSize - 1))
	{
	  cout << permutations[i];
	}
      else
	{
	  cout << permutations[i] << ", ";
	}
    }
  //cout statement used to print the number of permutations for input string
  cout << endl << "There is " << vSize << " permutations for string \"" << str1 << "\"" << endl << endl;
  return 0;
}

//Function used to compute all permutations and add each computed permutation into vector permutations
void permute(string input, int position, int last, vector<string> &permutation)
{
  char hold; //variable used to hold a character in a string
  if(position == last)
    {
      permutation.push_back(input); //Each permutation computed is pushed into vector permutations
    }
  else
    {
      //For loop to compute each permutation, cycles the characters every position in string
      for(int i = position; i < input.length(); i++)
	{
	  hold = input[position]; //Hold character in input[position]
	  input[position] = input[i]; //Set input[position] to input[i]
	  input[i] = hold; //Set input[i] to hold
	  //3 Statements above are used to swap two characters in a string
	  permute(input, (position + 1), last, permutation); //Call permute function(recursive)
	  hold = input[position]; //Hold character in input[position]
	  input[position] = input[i]; //Set input[position] to input[i]
          input[i] = hold; //Set input[i] to hold
	  //3 Statements above before permute function call are used to swap two characters in a string
	}
    }
}
