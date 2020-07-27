
#include "course.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

course::course()
{
  courseNumber = 0;
  courseName = "";
  numberOfCredits = 0;
}

course::course(long cNum, string cName, int numCredits)
{
  courseNumber = cNum;
  courseName = cName;
  numberOfCredits = numCredits;
}

void course::setCourseNumber(long cNum)
{
  courseNumber = cNum;
}

void course::setCourseName(string cName)
{
  courseName = cName;
}

void course::setNumberOfCredits(int numCredits)
{
  numberOfCredits = numCredits;
}

long course::getCourseNumber() const
{
  return courseNumber;
}

string course::getCourseName() const
{
  return courseName;
}

int course::getNumberOfCredits() const
{
  return numberOfCredits;
}

void course::print() const
{
  if(courseNumber == 0)
    {
      cout << endl << "Course Number:" << setw(12) << right << courseNumber << endl;
      cout << "Course Name:" << setw(19) << right << courseName << endl;
      cout << "Number of Credits:" << setw(8) << right << numberOfCredits << endl << endl;
    }
  else
    {
      cout << endl << "Course Number:" << setw(16) << right << courseNumber << endl;
      cout << "Course Name:" << setw(19) << right << courseName << endl;
      cout << "Number of Credits:" << setw(8) << right << numberOfCredits << endl << endl;
    }
}
