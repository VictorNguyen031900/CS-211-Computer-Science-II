//This is Restaurant.cpp
#include "Restaurant.h"
#include "Reservation.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

Restaurant::Restaurant() //Default constructor
{
  restaurantName = "Unknown"; //set variable restaurantName to Unknown if given no parameters
  restaurantAddress = "Unknown"; //set variable restaurantAddress to Unknown if given no parameters
  restaurantCity = "Unknown"; //set variable restaurantCity to Unknown if given no parameters
  restaurantType = "Unknown"; //set variable restaurantType to Unknown if given no parameters
  availableSeats[0] = 0; //set array availableSeats index 0 to 0 if give no parameters 5:00
  availableSeats[1] = 0; //set array availableSeats index 1 to 0 if give no parameters 6:00
  availableSeats[2] = 0; //set array availableSeats index 2 to 0 if give no parameters 7:00
  availableSeats[3] = 0; //set array availableSeats index 3 to 0 if give no parameters 8:00
}

Restaurant::Restaurant(string name, string address, string city, string type, int capacity) //Overloaded constructor with parameters
{
  restaurantName = name; //passed variable name is set to restaurantName in Restaurant class
  restaurantAddress = address; //passed variable address is set to restaurantAddress in Restaurant class
  restaurantCity = city; //passed variable city is set to restaurantCity in Restaurant class
  restaurantType = type; //passed variable type is set to restaurantType in Restaurant class
  availableSeats[0] = capacity; //set array availableSeats index 0 to variable capacity 5:00
  availableSeats[1] = capacity; //set array availableSeats index 1 to variable capacity 6:00
  availableSeats[2] = capacity; //set array availableSeats index 2 to variable capacity 7:00
  availableSeats[3] = capacity; //set array availableSeats index 3 to variable capacity 8:00
}

string Restaurant::getName() const //member function used to get restaurantName
{
  return restaurantName; //return variable restaurantName
}

string Restaurant::getAddress() const //member function used to get restaurantAddress
{
  return restaurantAddress; //return variable restaurantAddress
}

string Restaurant::getCity() const //member function used to get restaurantCity
{
  return restaurantCity; //return variable restaurantCity
}

string Restaurant::getType() const //member function used to get restaurantType
{
  return restaurantType; //return variable restaurantType
}

int Restaurant::getSeats(int a) const //member function used to get available seating from array availableSeats based on index
{
  return availableSeats[a]; //return availableSeats based on index a 
}

void Restaurant::makeReservation(string name, string phone, int group, int time) //member function used to make reservations
{
  int test; //variable used to test available seatings
  Reservation temp(name, phone, group, time); //create a Reservation class named temp with passed in variables name, phone, group, and time
  if(time == 5) //if variable time matches with 5 then proceed with if portion
    {
      test = availableSeats[0] - group; //set variable test to availableSeats index 0 minus variable group
      if(test < 0) //if variable test is is less than 0 that means there is not enough seats to set the reservation
	{
	  cout << "No available seats at your time." << endl; //print unavailable seating message
	}
      else //if if statement turns false that means there is available seating 
	{
	  availableSeats[0] = test; //set array availableSeats index 0 to variable test
	  reservations.push_back(temp); //push back(add) temp class to vector reservations
	  cout << "Reservation made!" << endl; //print sucess message
	}
    }
  else if(time == 6) //else if variable time matches with 6 then proceed with else if portion
    {
      test = availableSeats[1] - group; //set variable test to availableSeats index 1 minus variable group
      if(test < 0) //if variable test is is less than 0 that means there is not enough seats to set the reservation
	{
	  cout << "No available seats at your time." << endl; //print unavailable seating message
	}
      else //if if statement turns false that means there is available seating
	{
	  availableSeats[1] = test; //set array availableSeats index 1 to variable test
          reservations.push_back(temp); //push back(add) temp class to vector reservations
	  cout << "Reservation made!" << endl; //print sucess message
	}
    }
  else if(time == 7) //else if variable time matches with 7 then proceed with else if portion
    {
      test = availableSeats[2] - group; //set variable test to availableSeats index 2 minus variable group
      if(test < 0) //if variable test is is less than 0 that means there is not enough seats to set the reservation
	{
	  cout << "No available seats at your time." << endl; //print unavailable seating message
	}
      else //if if statement turns false that means there is available seating
	{
	  availableSeats[2] = test; //set array availableSeats index 2 to variable test
          reservations.push_back(temp); //push back(add) temp class to vector reservations
	  cout << "Reservation made!" << endl; //print sucess message
	}
    }

  else if(time == 8) //else if variable time matches with 8 then proceed with else if portion
    {
      test = availableSeats[3] - group; //set variable test to availableSeats index 3 minus variable group
      if(test < 0) //if variable test is is less than 0 that means there is not enough seats to set the reservation
	{
	  cout << "No available seats at your time." << endl; //print unavailable seating message
	}
      else //if if statement turns false that means there is available seating
	{
	  availableSeats[3] = test; //set array availableSeats index 3 to variable test
          reservations.push_back(temp); //push back(add) temp class to vector reservations
	  cout << "Reservation made!" << endl; //print sucess message
	}
    }
  else //if variable time does not match 5, 6, 7, or 8 then variable time is incorrect
    {
      cout << "Error" << endl; //print error message
    }
}

void Restaurant::printReservation() const //member function used to print reservations from a certain restaurant
{
  int reservationVectorSize = reservations.size(); //variable reservationVectorSize set to size of vector reservations
  for(int i = 0; i < reservationVectorSize; i++) //for-loop used to print each reservation in vector
    {
      cout << left << setw(14) << reservations[i].getResNum() << left << setw(10) << reservations[i].getConName() << left << setw(14) << reservations[i].getConPhone() << left << setw(8) << reservations[i].getGroupSize() << left << setw(6) << reservations[i].getResTime() << endl; //print reservation formatted reservation number, contact name, contach phone, group size, and reservation time
    }
}
