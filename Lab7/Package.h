#ifndef PACKAGE_H
#define PACKAGE_H
#include <iostream>
using namespace std;

class Package
{
 private:

 protected:
  string senderName;
  string senderAddress;
  string senderCity;
  string senderState;
  long senderZIPcode;

  string recipName;
  string recipAddress;
  string recipCity;
  string recipState;
  long recipZIPcode;

  string label;
  string date;
  double weight;
  double costPerOunce;
  string insuranceType;

 public:
  Package();
  Package(string, string, string, string, long, string, string, string, string, long, string, string, double, double, string);
  void print();
  //double calculateCost(double, double, string);
  double calculateCost();
  //string getSenderName();
  //string getSenderAddress();
  //string getSenderCity();
  //string getSenderState();
  //long getSenderZIPCode();
  //string getRecipName();
  //string getRecipAddress();
  //string getRecipCity();
  //string getRecipState();
  //long getRecipZIPCode();
  //string getLabel();
  //string getDate();
  //double getWeight();
  //double getCostPerOunce();
  //string getInsuranceType();
};

#endif
