/*******************************************************************************

Victor Nguyen
CS 211
2/1/19

*******************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

void readArray (int [], int [], int [], const int);
void printArray (const int [], const int);
void reverseArray (int [], const int);
int longestSequence(const int [], const int);

int main()
{
  int longest;
  const int SIZE = 10;
  int A[SIZE];
  int B[SIZE];
  int C[SIZE];
  readArray(A, B, C, SIZE);
  printArray(A, SIZE);
  printArray(B, SIZE);
  printArray(C, SIZE);
  reverseArray(A, SIZE);
  longest = longestSequence(A, SIZE);
  cout << "The longest sequence of array A is " << longest <<endl;
  longest = longestSequence(B, SIZE);
  cout << "The longest sequence of array B is " << longest <<endl;
  longest = longestSequence(C, SIZE);
  cout << "The longest sequence of array C is " << longest <<endl;
  return 0;
}

void readArray(int A[], int B[], int C[], const int SIZE)
{
  ifstream infile;
    infile.open("arrays.txt");
    if(!infile)
      {
	cout << "No file detected." << endl;
      }
    else
      {
	for(int i=0;i<SIZE;i++)
	  {
	    infile >> A[i];
	  }
	for(int j=0;j<SIZE;j++)
	  {
	    infile >> B[j];
	  }
	for(int k=0;k<SIZE;k++)
	  {
	    infile >> C[k];
	  }
      }
    infile.close();
}

void printArray(const int letter[], const int SIZE)
{
  cout << "Array: ";
  for (int i = 0; i < SIZE; i++)
    {
      cout << letter[i] << " ";
    }
  cout << endl << endl;
}

void reverseArray(int Ah[], const int SIZE)
{
  int i;
  int j = SIZE;
  int k;
  
  for (i=0;i<j;i++)
    {
      j--;
      k = Ah[i];
      Ah[i] = Ah[j];
      Ah[j] = k;
    }
  cout << "Reversed: ";
  for (int i = 0; i < SIZE; i++)
    {
      cout << Ah[i] << " ";
    }
  cout << endl << endl;
}

int longestSequence(const int test[], const int SIZE)
{
  int i;
  int length = 1;
  int long1 = 1;

  for(i=0;i<SIZE;i++)
    {
      if(test[i+1] == test[i]+1)
	{
	  length += 1;
	}
      else if(test[i] == test[i+1])
	{
	  
	}
      else if(length > long1)
	{
	  long1 = length;
	  length = 1;
	}
      else
	{
	  length = 1;
	}
    }
  return long1;
}
