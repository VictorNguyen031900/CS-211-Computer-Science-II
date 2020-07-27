#ifndef RESTAURANTRESERVATIONS_H
#define RESTAURANTRESERVATIONS_H
#include "Restaurant.h"
#include "Reservation.h"
#include <string>
#include <vector>

using namespace std;

class RestaurantReservations
{
 private:
  vector <Restaurant> restaurants;
 public:
  RestaurantReservations();
  void ProcessTransactionFile(string);
  void CreateNewRestaurant(string, string, string, string, int);
  void PrintAllRestaurants();
  void FindTable(string, string, int, int);
  void FindTableAtRestaurant(string, int);
  void MakeReservation(string, string, string, int, int);
  void CancelReservation(string, long);
  void PrintRestaurantReservations(string);
};

#endif
