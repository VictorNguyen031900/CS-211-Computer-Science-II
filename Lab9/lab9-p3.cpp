#include "course2.h"

#include <iostream>

using namespace std;

int main()
{
  long ID;
  string cName;
  int cCredit;
  const int SIZE = 3;
  course *courseptr = nullptr;
  courseptr = new course[SIZE];
  course *hold = nullptr;
  for(int i = 0; i < SIZE; i++)
    {
      hold = new course;
      cout << "Enter Course ID, Course Name, and Number of Credits: " << endl;
      cin >> ID >> cName >> cCredit;
      hold->setCourseNumber(ID);
      hold->setCourseName(cName);
      hold->setNumberOfCredits(cCredit);
      *(courseptr + i) = *hold;
      delete hold;
      hold = nullptr;
    }
  cout << "Number      Name        Credits" << endl << "---------------------------------" << endl;
  for(int i = 0; i < SIZE; i++)
    {
      courseptr[i].print();
    }

  delete [] courseptr;
  delete hold;
  return 0;
}
