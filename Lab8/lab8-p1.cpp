//g++ -std=c++11 FILENAME.cpp (to complie properly)
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void selSort(vector<string> &);
void display(const vector<string> &);
int binSearch(const vector<string> &, string);

int main()
{
  int index;
  vector<string> names{"Joe Garcia", "Amelia Perez", "Bob Haynes", "Tim Ducrest", "Kevin Garcia", "Suzy Walter", "Fang Yi", "Robert James", "Mary Andres"};
  cout << "Created vector \"names\"." << endl;
  display(names);
  cout << endl << "Sorting vector..." << endl;
  selSort(names);
  cout << endl << "Sorted!" << endl;;
  display(names);
  cout << endl << endl << "Searching for \"Kevin Garcia\"" << endl;
  index = binSearch(names, "Kevin Garcia");
  if(index == -1)
    {
      cout << "Name not found..." << endl;
    }
  else
    {
      cout << "Found name at index " << index << endl;
    }
  cout << endl << "Searching for \"Joe James\"" << endl;
  index = binSearch(names, "Joe James");
  if(index == -1)
    {
      cout << "Name not found..." << endl;
    }
  else
    {
      cout << "Found name at index " << index << endl;
    }
  return 0;
}

void selSort(vector<string> &v)
{
  string smallest;
  string testCase;
  string temp;
  int rIndex;
  for(int i = 0; i < v.size(); i++)
    {
      smallest = v[i];
      for(int j = i; j < v.size(); j++)
	{
	  testCase = v[j];
	  if(smallest[0] >= testCase[0])
	    {
	      temp = testCase;
	      smallest = testCase; 
	      temp = v[i];
	      rIndex = j;
	    }
        }
      v[i] = smallest;
      v[rIndex] = temp;
    }
}

void display(const vector<string> &v)
{
  for(int i = 0; i < v.size(); i++)
    {
      if(i < (v.size() - 1))
	{
	  cout << v[i] << ", ";
	}
      else
	{
	  cout << v[i];
	}
    }
}

int binSearch(const vector<string> &v, string key)
{
  int mid = 0;
  int left = 0;
  int right;

  right = v.size();

  while(left < right)
    {
      mid = left + (right - left)/2;
      if(key > v[mid])
	{
	  left = mid + 1;
	}
      else if(key < v[mid])
	{
	  right = mid;
	}
      else
	{
	  return mid;
	}
    }
  return -1;
}
