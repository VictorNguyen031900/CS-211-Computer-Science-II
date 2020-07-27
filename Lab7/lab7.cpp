#include "Package.h"
#include "OvernightPackage.h"
#include <iostream>
using namespace std;

int main()
{
  double hold;
  Package A("AmyJohnson", "3465RegentsRd", "SanDiego", "CA", 92130 , "EdwardJohnes", "439NWGreens", "Fayetteville", "NY", 13066, "HG9983", "06/03/2016", 10, 0.7, "upto1000");
  //hold = A.calculateCost(10, 0.7, "upto1000");
  hold = A.calculateCost();
  A.print();
  cout << "Shipping cost: $" << hold << endl << endl;
  OvernightPackage B("MaryPalmer", "6534SpringburtDR", "PalmSprings", "CA", 92240 , "DennisGarcia", "8FifthSt", "Denver", "CO", 66665, "UI0900", "10/11/2016", 20.1, 0.8, "upto5000", 7);
  //hold = B.calculateCost(20.1, 0.8, "upto5000", 7);
  hold = B.calculateCost();
  B.print();
  cout << "Shipping cost(Overnight): $" << hold << endl << endl;
  return 0;
}
