#ifndef STUDENT_H
#define STUDENT_H
#include<string>
using namespace std;

class Student
{
 private:
  string name;
  const long studentID;
  string major;
  string classification;
  int units;
  float tuition;
 public:
  static int totalNumofStudents;
  static int nextStudentID;
  Student();
  Student(string, string, string, int);
  ~Student();
  void print() const;
  void getData();
};


#endif
