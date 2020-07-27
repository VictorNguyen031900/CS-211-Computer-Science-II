/************************************************************************

Creator: Victor Nguyen
Course: CS211
Date: Match 28, 2019
Homework: Homework Assignement 3 Problem 1
Program Description: This is a program that searches an array of integers
  to find an index in the array that with the index also has a matching
  element.  For example given an array {1, 2, 2, 4, 5, 6, 7}, the algorithm
  will find index 2 with its matching element of 2.

************************************************************************/
//g++ -std=c++11 FILENAME.cpp (to complie properly)

#include <iostream>

using namespace std;

int matchIndex(int [], int, int, int); //Function defintion for algorithm

int main()
{
  int arrayA[]= {-20, -15, -10, -8, -7, -6, -5, -3, 1, 2, 3, 4, 5, 6, 7, 8, 9, 15, 16}; //array size of 19
  int arrayB[] = {-40, -20, -1, 1, 2, 3, 5, 7, 9, 12}; //array size of 10
  int arrayC[] = {-5, -3, 2, 5, 6, 7, 8, 9, 15, 16, 20}; //array size of 11
  int arrayD[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //array size of 10
  int direct = 1; // Direction for linear search (0 = left, 1 = neutral, 2 = right)
  int sizea = sizeof(arrayA) / 4; //size of arrayA
  int sizeb = sizeof(arrayB) / 4; //size of arrayB
  int sizec = sizeof(arrayC) / 4; //size of arrayC
  int sized = sizeof(arrayD) / 4; //size of arrayD

  //All 4 cout statements are for outputting matching index and element
  cout << "Array A with its matching index " << matchIndex(arrayA, sizea, (sizea / 2), direct) << endl;
  cout << "Array B with its matching index " << matchIndex(arrayB, sizeb, (sizeb / 2), direct) << endl;
  cout << "Array C with its matching index " << matchIndex(arrayC, sizec, (sizec / 2), direct) << endl;
  cout << "Array D with its matching index " << matchIndex(arrayD, sized, (sized / 2), direct) << endl;
  return 0;
}

//function to find matching index and element
int matchIndex(int array[], int size, int position, int direction)
{
  int middleIndex = size / 2;
  //Checks if linear search reached the end of array
  if((position == size) || (position == 0))
    {
      return -1; //Algorithm couldn't find a matching index and element
    }
  //Determines direction for linear search if middleIndex isn't equal to its element
  else if(direction == 1) //Netural position(Doesn't begin search)
    {
      if(middleIndex == array[middleIndex]) //If matching index and element is found
	{
	  return middleIndex; //Return middleIndex variable
	}
      else if(middleIndex < array[middleIndex]) //If middleIndex is less than its element, 
	{                                       //then linear search left of middleIndex
	  return matchIndex(array, size, position, 0); //Changes direction to 0 to indicate left search
	}
      else if(middleIndex > array[middleIndex]) //If middleIndex is greater than its element,
	{                                       //then lienar search right of middleIndex
	  return matchIndex(array, size, position, 2); //Changes direction variable to 2 to indicate right search
	}
    }
  //Linear search left side(middle index to index 0)
  else if(direction == 0) //Left
    {
      if(array[position] != position) //If index is not equal to its element, call matchIndex function(recurisve)
	{
	  return matchIndex(array, size, position - 1, 0);
	}
      else if(array[position] == position) //If index is equal to its element, return the index to main
	{
	  return position;
	}
    }
  //Linear search right side(middle index to last index of array)
  else if(direction == 2) //Right
    {
      if(array[position] != position) //If index is not equal to its element, call matchIndex function(recursive)
	{
	  return matchIndex(array, size, position + 1, 2);
	}
      else if(array[position] == position) //If index is equal to its element, return the index to main
	{
	  return position;
	}
    }
}

