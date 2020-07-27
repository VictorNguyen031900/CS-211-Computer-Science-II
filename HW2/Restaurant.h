#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "Reservation.h"
#include <string>
#include <vector>
using namespace std;

class Restaurant
{
 private:
  string restaurantName;
  string restaurantAddress;
  string restaurantCity;
  string restaurantType;
  int availableSeats[4];
  vector <Reservation> reservations;

 public:
  Restaurant();
  Restaurant(string, string, string, string, int);
  string getName() const;
  string getAddress() const;
  string getCity() const;
  string getType() const;
  int getSeats(int) const;
  //void printInfo() const;
  void makeReservation(string, string, int, int);
  void printReservation() const;
};

#endif
