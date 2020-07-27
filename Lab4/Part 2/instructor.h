#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include "course2.h"
#include<string>
using namespace std;

class instructor
{
 private:
  string firstName;
  string lastName;
  char gender;
  long employeeID;
  string officeNum;
  course courses[3];

 public:
  instructor();
  instructor(string, string, char, long, string, long, string, int, long, string, int, long, string, int);
  void setInstructor(string, string, char, long, string, long, string, int, long, string, int, long, string, int);
  void print() const;
};


#endif
