#include "course2.h"
#include "instructor.h"
#include <iostream>
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
