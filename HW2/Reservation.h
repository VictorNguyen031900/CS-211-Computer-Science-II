//This is Reservation.h
#ifndef RESERVATION_H
#define RESERVATION_H
#include <iostream>
#include <string>

using namespace std;

class Reservation
{
 private:
  long reservationNum; //const
  string contactName;
  string contactPhone;
  int groupSize;
  int reservationTime;

 public:
  Reservation();
  Reservation(string, string, int, int);
  //void print() const;
  long getResNum() const;
  string getConName() const;
  string getConPhone() const;
  int getGroupSize() const;
  int getResTime() const;
  static long nextReservationNum;
};

#endif
