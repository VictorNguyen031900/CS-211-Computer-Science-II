/**********************************************************************************

Victor Nguyen
CS 211
1-25-19

**********************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

double getEndBalance (double, double , double);

int main()
{
  int accNum;
  string accType;
  double startBal;
  double totalDep;
  double totalWith;
  double endBal;
  double holder;
  const double PREMIUM = 0.05;
  const double CHOICE = 0.03;
  const double BASIC = 0.01;
  ifstream infile;
  ofstream outfile;
  infile.open("input.txt");
  outfile.open("accountsOut.txt");
  if(infile)
    {
      cout << "Opened Successfully!" << endl;
      outfile << "Account    Type   StartBalance  Deposit      Withdrawal       EndBalance" << endl;
      outfile << "------------------------------------------------------------------------" << endl;
      while(infile >> accNum >> accType >> startBal >> totalDep >> totalWith)
	{
	  if(accType == "Premium")
	    {
	      holder = getEndBalance(startBal, totalDep, totalWith);
	      endBal = (holder * PREMIUM) + holder;
	      outfile << setw(6) << showpoint << fixed << setprecision(2) << accNum << setw(9) << accType << setw(12) << startBal << setw(12) << totalDep << setw(16) << totalWith << setw(16) << endBal << endl;
	    }
	  else if(accType == "Choice")
	    {
	      holder = getEndBalance(startBal, totalDep, totalWith);
              endBal = (holder * CHOICE) + holder;
              outfile << setw(6) << showpoint << fixed << setprecision(2) << accNum << setw(9) << accType << setw(12) << startBal << setw(12) << totalDep << setw(16) << totalWith << setw(16) << endBal << endl;
	    }
	  else
	    {
	      holder = getEndBalance(startBal, totalDep, totalWith);
              endBal = (holder * BASIC) + holder;
              outfile << setw(6) << showpoint << fixed << setprecision(2) << accNum << setw(9) <<  accType << setw(12) << startBal << setw(12) << totalDep << setw(16) << totalWith << setw(16) << endBal << endl;
	    }
	}
    }
  else
    {
      cout << "Unsuccessfully Opened!" << endl;
    }
  cout << "Written to accountsOut.txt" << endl;
  infile.close();
  outfile.close();
  return 0;
}

double getEndBalance(double a, double b, double c)
{
  double balance;
  balance = (a + b) - c;
  return balance;
}
