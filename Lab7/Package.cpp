#include "Package.h"
#include <iostream>
using namespace std;

Package::Package()
{

}

Package::Package(string sN, string sA, string sC, string sS, long sZ, string rN, string rA, string rC, string rS, long rZ, string l, string d, double w, double cPO, string iT)
{
  senderName = sN;
  senderAddress = sA;
  senderCity = sC;
  senderState = sS;
  senderZIPcode = sZ;
  recipName = rN;
  recipAddress = rA;
  recipCity = rC;
  recipState = rS;
  recipZIPcode = rZ;
  label = l;
  date = d;
  weight = w;
  costPerOunce = cPO;
  insuranceType = iT;
}

void Package::print()
{
  cout << "Sender Information: " << endl;
  cout << "Name: " << senderName << endl << "Address: " << senderAddress << ", " << senderCity << " " << senderState << " " << senderZIPcode << endl;
  cout << "Recipient Information: " << endl;
  cout << "Name: " << recipName << endl << recipAddress << " " << recipCity << " " << recipState << " " << recipZIPcode << endl;
  cout << "Package Information: " << label << " " << weight << " " << costPerOunce << " " << insuranceType << endl;
}

double Package::calculateCost()
{
  double temp;
  if(insuranceType == "upto1000")
    {
      temp = costPerOunce * weight + 5.25;
    }
  else if(insuranceType == "upto5000")
    {
      temp = costPerOunce * weight + 5.50;
    }
  else if(insuranceType == "none")
    {
      temp = costPerOunce * weight;
    }
  else
    {
      cout << "Invalid insurance type!" << endl;
    }
  return temp;
}

/*****************SENDER***********************/

//string Package::getSenderName()
//{
  //return senderName;
  //}

//string Package::getSenderAddress()
//{
  //return senderAddress;
  //}

//string Package::getSenderCity()
//{
  //return senderCity;
  //}

//string Package::getSenderState()
//{
  //return senderState;
  //}

//long Package::getSenderZIPCode()
//{
  //return senderZIPcode;
  //}

/****************RECIPIENT*********************/

//string Package::getRecipName()
//{
  //return recipName;
  //}

//string Package::getRecipAddress()
//{
  //return recipAddress;
  //}

//string Package::getRecipCity()
//{
  //return recipCity;
  //}

//string Package::getRecipState()
//{
  //return recipState;
  //}

//long Package::getRecipZIPCode()
//{
  //return recipZIPcode;
  //}

/********************SHIPPING**********************/

//string Package::getLabel()
//{
  //return label;
  //}

//string Package::getDate()
//{
  //return date;
  //}

//double Package::getWeight()
//{
  //return weight;
  //}

//double Package::getCostPerOunce()
//{
  //return costPerOunce;
  //}

//string Package::getInsuranceType()
//{
  //return insuranceType;
  //}
