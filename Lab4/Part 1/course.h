#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace std;

class course
{
 private:
  long courseNumber;
  string courseName;
  int numberOfCredits;

 public:
  course();
  course(long, string, int);
  void setCourseNumber(long);
  void setCourseName(string);
  void setNumberOfCredits(int);
  long getCourseNumber() const;
  //{
  //return courseNumber;
  //}
  string getCourseName() const;
  //{
  //return courseName;
  //}
  int getNumberOfCredits() const;
  //{
  //return numberOfCredits;
  //}
  void print() const;
};

#endif
