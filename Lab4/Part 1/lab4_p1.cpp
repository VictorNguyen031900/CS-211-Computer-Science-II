/*******************************************************************************************

Victor Nguyen
CS 211
2/15/2019

*******************************************************************************************/
#include "course.h"
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int main()
{
  long cNumber;
  string cName;
  int numCredits;
  cout << endl << "Enter Course Number: ";
  cin >> cNumber;
  cout << "Enter Course Name: ";
  cin.ignore();
  getline(cin, cName);
  cout << "Enter Number of Credits: ";
  cin >> numCredits;
  course test1(cNumber, cName, numCredits);
  test1.print();
  course test2;
  test2.print();
  cout << endl << "Enter Course Number: ";
  cin >> cNumber;
  cout << "Enter Course Name: ";
  cin.ignore();
  getline(cin, cName);
  cout << "Enter Number of Credits: ";
  cin >> numCredits;
  test2.setCourseNumber(cNumber);
  test2.setCourseName(cName);
  test2.setNumberOfCredits(numCredits);
  test2.print();
  return 0;
}
