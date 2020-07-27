/*****************************************************************************************************************************

Victor Nguyen
CS 211
2-10-19

*****************************************************************************************************************************/

#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>

using namespace std;

struct Person
{
  string firstName;
  string lastName;
  string phoneNumber;
};

void readFile(vector<Person> &);
void printFile(const vector<Person> &);

int main()
{
  vector<Person> v;
  readFile(v);
  printFile(v);
  return 0;
}

void readFile(vector<Person> &v)
{
  Person p;
  string fN;
  string lN;
  string pN;
  ifstream infile;
  infile.open("telephoneData.txt");
  if(!infile)
    {
      cout << "Error opening \"telephoneData.txt\"" << endl;
    }
  else
    {
      while(infile >> fN >> lN >> pN)
	{
	  p.firstName = fN;
	  p.lastName = lN;
	  p.phoneNumber = pN;
	  v.push_back(p);
	}
    }
  infile.close();
}

void printFile(const vector<Person> &v)
{
  cout << "Name" << setw(20) << "Telephone" << endl;
  cout << "---------------------------" << endl;
  int size = v.size();
  for(int i = 0; i < size; i++)
    {
      cout << setw(7) << left << v[i].firstName << setw(8) << v[i].lastName << setw(10) << right << v[i].phoneNumber << endl;
    }

}
