#include "Reservation.h"
#include <iostream>
#include <iomanip>

using namespace std;

long Reservation::nextReservationNum = 100; //static variable set to 100

Reservation::Reservation() : reservationNum(nextReservationNum) //Default constructor set constant variable reservationNum to nextReservationNum
{
  contactName = ""; //set contactName to blank
  contactPhone = ""; //set contachPhone to blank
  groupSize = 0; //set groupSize to 0
  reservationTime = 0; //set reservationTime to 0
  nextReservationNum += 10; //increase nextReservationNum by 10
}

Reservation::Reservation(string cName, string cPhone, int rGroup, int rTime) : reservationNum(nextReservationNum) //overloaded constructor set constant vriable reservationNum to nextRerservationNum, passed to member function cName, cPhone, rGroup, and rTime
{
  contactName = cName; //set contactName to passed in cName
  contactPhone = cPhone; //set contactPhone to passed in cPhone
  groupSize = rGroup; //set groupSize to passed in rGroup
  reservationTime = rTime; //set reservationTime to passed in rTime
  nextReservationNum += 10; //increase nextReservationNum by 10
}

long Reservation::getResNum() const //member function used to get reservation number
{
  return reservationNum; //return variable reservationNum from Reservation class
}

string Reservation::getConName() const //member function used to get contact name
{
  return contactName; //return variable contactName from Reservation class
}

string Reservation::getConPhone() const //member function used to get contact phone
{
  return contactPhone; //return variable contactphone from Reservation class
}

int Reservation::getGroupSize() const //member function used to get group size
{
  return groupSize; //return variable groupSize from Reservation class
}

int Reservation::getResTime() const //member function used to get reservation time
{
  return reservationTime; //return variable reservationTime from Reservation class
}
