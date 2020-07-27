#include "RestaurantReservations.h"
#include "Restaurant.h"
#include "Reservation.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

RestaurantReservations::RestaurantReservations() //Default constructor
{

}

void RestaurantReservations::ProcessTransactionFile(string fileName) //ProcessTransactionFile member function ("Main")
{
  string command; //used to read command from input file
  string rName; //used to read restaurant name from input file
  string rAddress; //used to read restaurant address from input file
  string rCity; //used to read restaurant city from input fille
  string rType; //used to read restaurant type from input file
  string cName; //used to read customer name from input file to set reservations
  string cPhone; //used to read customer phone from input file to set reservations
  int rGroup; //used to read customer group size from input file to set reservations
  int rTime; //used to read customer time from input file to set reservations
  int rCapacity; //used to read restuarant capacity size to create a new restaurant
  int rNum; //used to read reservation number to cancel reservation
  ifstream infile; //in file stream named infile, used to read text from
  infile.open(fileName.c_str()); //open file fileName string that was passed from main to member function
  if(!infile) //used to check if file could be opened, if can't be open display error message 
    {
      cout << "File \"" << fileName << "\" couldn't open properly!  Try again!" << endl; //error message if can't be opened
    }
  else //if file can be open then proceed with else portion of code
    {
      while(infile >> command) //while infile can read the first word of each line then proceed with while portion of code
	{
	  if(command == "CreateNewRestaurant") //if command string is the same as string "CreateNewRestaurant" then proceed with if portion else go to else if
	    {
	      infile >> rName >> rAddress >> rCity >> rType >> rCapacity; //read the rest of the same line as command string
	      cout << "CreateNewRestaurant " << rName << " " << rAddress << " " << rCity << " " << rType << " " << rCapacity << endl; //print command format
	      CreateNewRestaurant(rName, rAddress, rCity, rType, rCapacity); //pass rName, rAddress, rCity, rType, rCapacity to member function CreatenewRestaurant
	    }
	  else if(command == "FindTable") //else if command string is the same as string "FindTable" then proceed with else if portion else go to next else if statement
	    {
	      infile >> rCity >> rType >> rGroup >> rTime; //read the rest of the same line as command string
	      cout << "FindTable " << rCity << " " << rType << " " << rGroup << " " << rTime << endl; //print command format
	      FindTable(rCity, rType, rGroup, rTime);
	    }
	  else if(command == "FindTableAtRestaurant") //else if command string is the same as string "FindTableAtRestaurant" then proceed with else if portion else go to next else if statement
	    {
	      infile >> rName >> rGroup; //read the rest of the same line as command string
	      cout << "FindTableAtRestaurant " << rName << " " << rGroup << endl; //print command format
	      FindTableAtRestaurant(rName, rGroup); //pass rName and rGroup to FindTableAtRestaurant member function
	    }
	  else if(command == "MakeReservation") //else if command string is the same as string "MakeReservation" then proceed with else if portion else go to next else if statement
	    {
	      infile >> rName >> cName >> cPhone >> rGroup >> rTime; //read the rest of the same line as command string
	      cout << "MakeReservation " << rName << " " << cName << " " << cPhone << " " << rGroup << " " << rTime << endl; //print command format
	      MakeReservation(rName, cName, cPhone, rGroup, rTime); //pass rName, cName, cPhone, rGroup, and rTime to MakeReservation member function
	    }
	  else if(command == "CancelReservation") //else if command string is the same as string "CancelReservation" then proceed with else if portion else go to next else if statement
	    {
	      infile >> rName >> rNum; //read the read of the same line as command string
	      cout << "CancelReservation " << rName << " " << rNum << "(Canceled Function)" << endl; //print command format however member function was canceled by professor in an email
	      CancelReservation(rName, rNum); //pass rName and rNum to CancelRservation member function
	    }
	  else if(command == "PrintAllRestaurants") //else if command string is the same as string "PrintAllRestaurants" then proceed with else if portion else go to next else if statement
	    {
	      cout << "PrintAllRestaurants" << endl; //print command format
	      cout << "Restaurant           Address, City                     Type            Capacity" << endl; //print table header
	      cout << "-------------------------------------------------------------------------------" << endl; //print table header
	      PrintAllRestaurants(); //call PrintAllRestaurant member function
	    }
	  else if(command == "PrintRestaurantReservations") //else if command string is the same as string "PrintRestaurantReservations" then proceed with else if portion else go to final else statement
	    {
	      infile >> rName; //read the rest of the same line as command string
	      cout << "PrintRestaurantReservations " << rName << endl; //print command format
	      PrintRestaurantReservations(rName); //pass variable rName to member function PrintRestaurantReservations
	    }
	  else //if command string doesn't match with any command then command string was invalid
	    {
	      cout << "Incorrect command!" << endl; //print error message for incorrect command
	    }
	}
    }
  infile.close(); //close file "TransactionFile.txt"
}

void RestaurantReservations::CreateNewRestaurant(string rName, string rAddress, string rCity, string rType, int rCapacity) //member function used to create a new restaurant and add it to database(vector)
{
  Restaurant temp(rName, rAddress, rCity, rType, rCapacity); //create a new Restaurant class named temp and pass variables rName, rAddess, rCity, rType, and rCapacity
  restaurants.push_back(temp); //push back(add) temp to vector restaurants
}

void RestaurantReservations::PrintAllRestaurants() //member function used to print all restaurants in restaurants vector
{
  int vectorSize = restaurants.size(); //variable vectorSize set to the size of vector restaurants to use it for for-loop
  for(int i = 0; i < vectorSize; i++) //for-loop used to print a restaurant line by line
    {
      cout << left << setw(21) << restaurants[i].getName() << left << setw(34) << restaurants[i].getAddress() + ", " + restaurants[i].getCity() << left << setw(16) << restaurants[i].getType() << left << setw(8) << restaurants[i].getSeats(0) << endl; //print restaurant name, address, city, type, and capacity line by line
    }
}

void RestaurantReservations::FindTable(string rCity, string rType, int rGroup, int rTime) //member function used to find a table with available for all restaurants based on city, restaurant type, reservation group size, and reservation time
{
  int vectorSize = restaurants.size(); //variable vectorSize set to the size of vector restaurants
  string nameHold; //string nameHold used to hold name of vector restaurants index i's name
  vector<string> names; //vector used to hold all restaurant names with available criteria passed in
  int count = 0; //variable count used to help if there's an entry in vector names
  for(int i = 0; i < vectorSize; i++) //for-loop used to check through vector restaurants 
    {
      if(rCity == restaurants[i].getCity()) //if passed in variable rCity matches with vector restaurants index i's city then proceed with if portion
	{
	  if(rType == restaurants[i].getType()) //if passed in variable rType matches with vector restaurants index i's type then proceed with if portion
	    {
	      if(rTime == 5) //if passed in variable rTime matches with 5 then proceed with if portion else go to next else if statement
		{
		  if(rGroup <= restaurants[i].getSeats(0)) //if passed in variable rGroup is greater than or equal to vector restaurants index i's array availableSeats index 0
		    {
		      nameHold = restaurants[i].getName(); //set variable nameHold to vector restaurants index i's name
		      names.push_back(nameHold); //push back(add) namedHold to vector names
		      count++; //increment count variable by 1
		    }
		}
	      else if(rTime == 6) //else if passed in variable rTime matches with 6 then proceed with if portion else go to next else if statement
		{
		  if(rGroup <= restaurants[i].getSeats(1)) //if passed in variable rGroup is greater than or equal to vector restaurants index i's array availableSeats index 1
                    {
		      nameHold = restaurants[i].getName(); //set variable nameHold to vector restaurants index i's name
                      names.push_back(nameHold); //push back(add) nameHold to vector names
                      count++; //increment count variable by 1
                    }
		}
	      else if(rTime == 7) //else if passed in variable rTime matches with 7 then proceed with if portion else go to next else if statement
		{
		  if(rGroup <= restaurants[i].getSeats(2)) //if passed in variable rGroup is greater than or equal to vector restaurants index i's array availableSeats index 2
                    {
		      nameHold = restaurants[i].getName(); //set variable nameHold to vector restaurants index i's name
                      names.push_back(nameHold); //push back(add) nameHold to vector names
                      count++; //increment count variable by 1
                    }
		}
	      else if(rTime == 8) //else if passed in variable rTime matches with 7 then proceed with if portion else go to next else statement
		{
		  if(rGroup <= restaurants[i].getSeats(3)) //if passed in variable rGroup is greater than or equal to vector restaurants index i's array availableSeats index 3
                    {
		      nameHold = restaurants[i].getName(); //set variable nameHold to vector restaurants index i's name
                      names.push_back(nameHold); //push back(add) nameHold to vector names
                      count++; //increment count variable by 1
                    }
		}
	      else //if rTime doesn't match with 5, 6, 7 or 8 then rTime that was passed in was invalid for the program
		{
		  cout << "Incorrect time for reservation" << endl; //print error message
		}
	    }
	}
    }
  int printVector = names.size(); //create a variable named printVector and set it to the size of vector names to be used in the for-loop under
  if(count > 0) //if count variable is greater than 0 then that means there's a string in the vector names
    {
      cout << "You may reserve a table for " << rGroup << " at " << rTime << " pm at:" << endl; //print formatted response
      for(int i = 0; i < printVector; i++) //for-loop used to print every entry in the vector
      {
        cout << names[i] << endl; //print index i in vector names
      }
    }
  else //if count variable equal to or less than 0 then that means there's not entries in the vector print meaning there's no restaurants that fit the criteria
    {
      cout << "No restaurant can accommodate such a group at this time, check another time." << endl; //print message indicating there's not restaurant that doesn't fit the criteria
    }
}

void RestaurantReservations::FindTableAtRestaurant(string rName, int rGroup) //member function used to find a table at a certain restaurant based on the size of the reservation group, then output times with available seating
{
  int vectorSize = restaurants.size(); //variable vectorsize set to the size of vector restaurants to be used in the for loop
  int count = 0; //variable used to helped out the available times for seating
  vector<int> times; //vector times used for to have available times with correct seating for customer
  for(int i = 0; i < vectorSize; i++) //for-loop used to add available times with correct seating to vector to be used later
    {
      if(rName == restaurants[i].getName()) //check if passed in rName is the same as vector restaurants index i's name
	{
	  for(int j = 0; j < 4; j++) //goes through availableseats array to check capacity
	    {
	      if(rGroup <= restaurants[i].getSeats(j)) //if group size is less than or equal to the capacity in index j of availableseats array
		{
		  int h = j + 5; //variable h used for times 5:00, 6:00, 7:00, or 8:00
		  times.push_back(h); //push back(add) variable h to vector times
		  count++; //increase variable count to tell if statement if that there is an available time
		}
	    }
	}
    }
  int vecPrint = times.size(); //variable vecPrint set to the size of vector times
  if(count > 0) //if variable count is greater than 0, then that means there's an avaiable times
    {
      cout << "You can reserve a table for " << rGroup <<  " at " << rName << " at "; //print there's an avaiable time for rGroup amount of people at times
      for(int i = 0; i < vecPrint; i++) //for-loop used to print available times from vector times
	{
	  cout << times[i] << ":00 pm"; //print time as the format "0:00"
	  if(i < (vecPrint - 1)) //if statement used to print commas inbetween times if multiple times available
	    {
	      cout << ", "; //print comma
	    }
	}
      cout << endl; //skip line
    }
  else //if there's no available time then print message regarding time avilability
    {
      cout << rName << " does not have such availability." << endl; //print message
    }
}

void RestaurantReservations::MakeReservation(string rName, string cName, string cPhone, int rGroup, int rTime) //member function used to make a reservation with passed in variables rName, cname, cPhone, rGroup, rTime
{
  int vectorSize = restaurants.size(); //variable vectorsize set to the size of vector restaurants to be used in for-loop
  for(int i = 0; i < vectorSize; i++) //for-loop used to add reservation to vector
    {
      if(rName == restaurants[i].getName()) //if rName variable that was passed in is equal to vector restaurants index i's name then proceed with if portion
	{
	  restaurants[i].makeReservation(cName, cPhone, rGroup, rTime); //pass in cName, cPhone, rGroup, and rTime in to makeReservation member function from restaurant class
	}
    }
}

void RestaurantReservations::CancelReservation(string rName, long rNum) //member function use was to be used to cancel reservation, but now it s now been removed from the assignment
{
  cout << "Canceled function stated by professor!" << endl; //print message
}

void RestaurantReservations::PrintRestaurantReservations(string rName) //member function is used to print all the reservations in a certain restaurant indicated by string rname
{
  int vectorSize = restaurants.size(); //variable vectorSize set to size of vector restaurants
  cout << "Reservation   Contact   Phone         Group   Time" << endl; //print table header
  cout << "--------------------------------------------------" << endl; //print table header
  for(int i = 0; i < vectorSize; i++) //for-loop used to print all reservations for a certain restaurant
    {
      if(rName == restaurants[i].getName()) //if rName matches with vector restaurants index i's name then proceed with if portion
	{
	  restaurants[i].printReservation(); //call printReservation member function in restaurants class
	}
    }
}
