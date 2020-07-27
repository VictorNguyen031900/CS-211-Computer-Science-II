#include "OvernightPackage.h"
#include "Package.h"
#include <iostream>
using namespace std;

OvernightPackage::OvernightPackage()
{

}

OvernightPackage::OvernightPackage(string sN, string sA, string sC, string sS, long sZ, string rN, string rA, string rC, string rS, long rZ, string l, string d, double w, double cPO, string iT, double oNF) : Package(sN, sA, sC, sS, sZ, rN, rA, rC, rS, rZ, l, d, w, cPO, iT)
{
  overnightFee = oNF;
}

double OvernightPackage::calculateCost()
{
  double temp;
  if(insuranceType == "upto1000")
    {
      temp = ((costPerOunce + overnightFee) * weight) + 5.25;
    }
  else if(insuranceType == "upto5000")
    {
      temp = ((costPerOunce + overnightFee) * weight) + 5.50;
    }
  else if(insuranceType == "none")
    {
      temp = (costPerOunce + overnightFee) * weight;
    }
  else
    {
      cout << "Invalid insurance type!" << endl;
    }
  return temp;
}
