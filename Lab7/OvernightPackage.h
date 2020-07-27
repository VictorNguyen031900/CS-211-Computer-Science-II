#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H
#include "Package.h"
#include <iostream>
using namespace std;

class OvernightPackage : public Package
{
 private:

 protected:
  double overnightFee;

 public:
  OvernightPackage();
  OvernightPackage(string, string, string, string, long, string, string, string, string, long, string, string, double, double, string, double);
  double calculateCost();
};

#endif
