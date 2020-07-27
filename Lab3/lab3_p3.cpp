/*******************************************************************************************

Victor Nguyen
CS211
2-8-19

*******************************************************************************************/

#include<iostream>
#include<string>
#include<sstream>

using namespace std;

void removeSpace(string);

int main()
{
  string userIn;
  cout << "Please enter a phrase: ";
  getline(cin, userIn);
  removeSpace(userIn);
  return 0;
}

void removeSpace(string hold)
{
  //string userOut = hold;
  //int place = userOut.find(" ", 0);
  //while(place != userOut.npos)
  //{
  //userOut.erase(place, 1);
  //place = userOut.find(" ", place+1);
  //}
  stringstream ss;
  string holder;
  ss << hold;
  hold = "";
  while(!ss.eof())
    {
      ss >> holder;
      hold  = hold + holder;
    }
  cout << "The resulting phrase is: \"" << hold  << "\"" << endl;
}
