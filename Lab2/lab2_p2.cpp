/***************************************************************************************************

Victor Nguyen
CS 211
2-4-19

***************************************************************************************************/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void commandInsert (vector<string>& V, string, int);
void commandDelete (vector<string>& V, int);
void commandPrint (const vector<string>& V);

int main()
{
  vector<string> V;
  string command;
  string input;
  int var;
  ifstream infile;
  infile.open("vectorData.txt");
  if(!infile)
    {
      cout << "No file detected." << endl;
    }
  else
    {
      while(infile >> command)
	{
	  if(command == "Insert")
	    {
	      infile >> input >> var;
	      commandInsert(V, input, var);
	    }
	  else if(command == "Delete")
	    {
	      infile >> var;
	      commandDelete(V, var);
	    }
	  else if(command == "Print")
	    {
	      commandPrint(V);
	    }
	}
    }
  infile.close();
  return 0;
}

void commandInsert (vector<string>& V, string text, int var)
{
  if(var <= V.size())
    {
      V.insert(V.begin() + var, text);
    }
}

void commandDelete (vector<string>& V, int var)
{
  if(var < V.size())
    {
      V.erase(V.begin() + var);
    }
}

void commandPrint (const vector<string>& V)
{
  for(int i = 0; i < V.size(); i++)
    {
      cout << V[i] << " ";
    }
  cout << endl;
}
