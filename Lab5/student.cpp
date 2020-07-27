#include "student.h"
#include <iostream>
#include <string>

using namespace std;

int Student::totalNumofStudents = 0;

int Student::nextStudentID = 10000;

Student::Student() : studentID(nextStudentID)
{
  name = "Unknown";
  //studentID = nextStudentID;
  major = "CS";
  classification = "undergraduate";
  units = 12;
  tuition = 0;
  totalNumofStudents++;
  nextStudentID++;
}

Student::Student(string theName, string theMajor, string theClassification, int theUnits) : studentID(nextStudentID)
{
  name = theName;
  //studentID = nextStudentID;
  major = theMajor;
  classification = theClassification;
  units = theUnits;
  tuition = 0;
  totalNumofStudents++;
  nextStudentID++;
}

Student::~Student()
{
  totalNumofStudents--;
}

void Student::getData()
{
  cout << endl << endl;
  cout << "Input name: ";
  getline(cin, name);
  cout << "Input major: ";
  cin >> major;
  cout << "Input Classification: ";
  cin >> classification;
  cout << "Input units: ";
  cin >> units;
  // studentID = nextStudentID;
}

void Student::print() const
{
  cout << endl << endl;
  cout << "Name: " << name << endl;
  cout << "Student ID: " << studentID << endl;
  cout << "Major: " << major << endl;
  cout << "Classification: " << classification << endl;
  cout << "Units: " << units << endl;
  cout << "Tutition: " << tuition << endl;
  cout << "Total Number of Students: " << totalNumofStudents << endl;
  cout << "Next Student ID: " << nextStudentID << endl;
}
