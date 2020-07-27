/************************************************************************************************************************

Victor Nguyen
CS 211
Homework Assignment 1
Date: 3/1/2019

This program helps customers make reservations at local restaurants.  The program has many features such as finding
a table based on the city location, the type of restaurant, size of the group, and ideally reservation time. Finding 
a table at a certain restaurant based on the customer's group size and preferred restaurant name.  Being able to make 
a reservation for a certain restaurant, the customer is able to input their name, phone number, group size, and reservation 
time.  The program also has a feature to print out all the avaiable rstaurants that are in the database (vector).  And 
finally the program is able to print out all reservations for a certain restaurant.

************************************************************************************************************************/
#include "RestaurantReservations.h"
#include "Restaurant.h"
#include "Reservation.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
  RestaurantReservations openTable; //create a RestaurantReservations class named openTable
  openTable.ProcessTransactionFile("TransactionFile.txt"); //pass string to ProcessTransactionFile memberfunction
  return 0;
}
