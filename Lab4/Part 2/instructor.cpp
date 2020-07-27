#include "instructor.h"
#include "course2.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

instructor::instructor()
{

}

instructor::instructor(string fN, string lN, char g, long eID, string oNum, long cNum1, string cN1, int nC1, long cNum2, string cN2, int nC2, long cNum3, string cN3, int nC3)
{
  firstName = fN;
  lastName = lN;
  gender = g;
  employeeID = eID;
  officeNum = oNum;
  courses[0].setCourseNumber(cNum1);
  courses[0].setCourseName(cN1);
  courses[0].setNumberOfCredits(nC1);
  courses[1].setCourseNumber(cNum2);
  courses[1].setCourseName(cN2);
  courses[1].setNumberOfCredits(nC2);
  courses[2].setCourseNumber(cNum2);
  courses[2].setCourseName(cN2);
  courses[2].setNumberOfCredits(nC2);
}

void instructor::setInstructor(string fN, string lN, char g, long eID, string oNum, long cNum1, string cN1, int nC1, long cNum2, string cN2, int nC2, long cNum3, string cN3, int nC3)
{
  firstName = fN;
  lastName = lN;
  gender = g;
  employeeID = eID;
  officeNum = oNum;
  courses[0].setCourseNumber(cNum1);
  courses[0].setCourseName(cN1);
  courses[0].setNumberOfCredits(nC1);
  courses[1].setCourseNumber(cNum2);
  courses[1].setCourseName(cN2);
  courses[1].setNumberOfCredits(nC2);
  courses[2].setCourseNumber(cNum2);
  courses[2].setCourseName(cN2);
  courses[2].setNumberOfCredits(nC2);
}

void instructor::print() const
{
  if(employeeID  == 0)
    {
      cout << "First name:" << setw(25) << right << firstName << endl;
      cout << "Last name:" << setw(23) << right << lastName << endl;
      cout << "Gender:" << setw(22) << right << gender << endl;
      cout << "Employee ID:" << setw(17) << right << employeeID << endl;
      cout << "Office Number:" << setw(21) << right << officeNum << endl << endl;
      cout << "#1 Course Number:" << setw(12) << right << courses[0].getCourseNumber() << endl;
      cout << "#1 Course Name:" << setw(18) << right << courses[0].getCourseName() << endl;
      cout << "#1 Number of Credits:" << setw(8) << right << courses[0].getNumberOfCredits() << endl << endl;
      cout << "#2 Course Number:" << setw(12) << right << courses[1].getCourseNumber() << endl;
      cout << "#2 Course Name:" << setw(12) << right << courses[1].getCourseName() << endl;
      cout << "#2 Number of Credits:" << setw(8) << right << courses[1].getNumberOfCredits() << endl << endl;
      cout << "#3 Course Number:" << setw(12) << right << courses[2].getCourseNumber() << endl;
      cout << "#3 Course Name:" << setw(18) << right << courses[2].getCourseName() << endl;
      cout << "#3 Number of Credits:" << setw(8) << right << courses[2].getNumberOfCredits() << endl << endl;
    }
  else
    {
      cout << "First name:" << setw(25) << right << firstName << endl;
      cout << "Last name:" << setw(23) << right << lastName << endl;
      cout << "Gender:" << setw(22) << right << gender << endl;
      cout << "Employee ID:" << setw(23) << right << employeeID << endl;
      cout << "Office Number:" << setw(21) << right << officeNum << endl << endl;
      cout << "#1 Course Number:" << setw(16) << right << courses[0].getCourseNumber() << endl;
      cout << "#1 Course Name:" << setw(18) << right << courses[0].getCourseName() << endl;
      cout << "#1 Number of Credits:" << setw(8) << right << courses[0].getNumberOfCredits() << endl << endl;
      cout << "#2 Course Number:" << setw(16) << right << courses[1].getCourseNumber() << endl;
      cout << "#2 Course Name:" << setw(18) << right << courses[1].getCourseName() << endl;
      cout << "#2 Number of Credits:" << setw(8) << right << courses[1].getNumberOfCredits() << endl << endl;
      cout << "#3 Course Number:" << setw(16) << right << courses[2].getCourseNumber() << endl;
      cout << "#3 Course Name:" << setw(18) << right << courses[2].getCourseName() << endl;
      cout << "#3 Number of Credits:" << setw(8) << right << courses[2].getNumberOfCredits() << endl << endl;
    }
}
