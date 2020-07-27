/*******************************************************************************************************************

Victor Nguyen
CS 211
Homework Assignment 1
Date: 2/11/2019

This program helps owners of a restaurant to advertise their business by adding their restaurant's name, the
location of the restaurant, contact information, and the category of food they serve to a database other 
restaurants. This program can also be used by users who don't own a restaurant but are hungry and is looking
for a restaurant to eat at. The user can search for a restaurant by the type of foods that are served, city 
where the restaurant is located, name of the restaurant, and by the top rated restaurant in the city. The 
user can even give a rating to the restaurant based on a five star system.  If the restaurant sadly closes,
the owner of the restaurant can remove their restaurant listing from the database.

*******************************************************************************************************************/

#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

struct Restaurant
{
  string name; // restaurant name
  string address; // restaurant street address
  string city; // restaurant city
  string state; // restaurant state
  int zipcode; // restaurant zip code
  string type; // type of food served
  string website; // restaurant website
  float rating; // restaurant rating, a number from 1 to 5
  int reviewers; // number of reviewers
};

void addListing(vector<Restaurant> &, const Restaurant); // prototype
void removeListing(vector<Restaurant> &, const string); // prototype
void displayAll(const vector<Restaurant> &); // prototype
void findByName(const vector<Restaurant> &, const string); // prototype
void findByCriteria(const vector<Restaurant> &, const string, const string); // prototype
void rate(vector<Restaurant> &, const string, const float); // prototype
void findTopRated(const vector<Restaurant> &, const string); // prototype

int main()
{
  vector<Restaurant> restaurants; // initialize vector "restaurants" with sturcture type Restaurant
  Restaurant temp; // intialize temporary structure to hold a restaurant then send it to vector "restaurants"
  string fCommand; // used to hold a "command" from reading file
  string rN; // used to hold the name of the restaurant
  string rA; // used to hold the address of the restaurant
  string rC; //used to hold the city of the restaurant
  string rS; // used to hold the state of the restaurant
  int rZC; // used to hold the zipcode of the restaurant
  string rT; // used to hold the type of the restautrant
  string rW; // used to hold the website of the restaurant
  float rating = 0.00; // used to set the rating of the restaurant to 0 when adding restaurant to vector first time
  int reviewers = 0; // used to set the amount of reviewers of the restaurant to 0 when adding restaurant to vector first time
  float fRating; // used to hold the rating of the restaurant after rating command has been executed
  string keyword; // used to for the FindByName command due to restaurant not being searched by full name
  ifstream infile; // initialize input stream to read from file
  infile.open("RestaurantsTrans.txt"); //open file "RestaurantsTrans.txt"
  if(!infile) //checks to file "RestaurantsTrans.txt" has opened properly
    {
      cout << "File \"RestaurantsTrans.txt\" couldn't open properly! Try again!" << endl; // output message if file doesn't open properly
    }
  else
    {
      while(infile >> fCommand) // checks to see if infile can read the first entry for each row of text, if so take first entry and put in to string fCommand
	{
	  if(fCommand == "AddListing") //if fCommand is equal to "AddListing" then proceed with if statement, if false go to next else if statement
	    {
	      infile >> rN >> rA >> rC >> rS >> rZC >> rT >> rW; // set every entry after first entry to variables rN, rA, rC, rS, rZC, rT, and rW
	      temp.name = rN; // set rN to name variable in temporary structure
	      temp.address = rA; // set rA to address variable in temporary structure
	      temp.city = rC; // set rC to city variable in temporary structure
	      temp.state = rS; // set rS to state variable in temporary structure
	      temp.zipcode = rZC; // set rZC  to zipcode variable in temporary structure
	      temp.type = rT; // set rT to type varible in temporary structure
	      temp.website = rW; // set rW to website variable in temporary structure
	      temp.rating = rating; // set rating which was set 0 to rating variable in temporary structure
	      temp.reviewers = reviewers; // set reviewerw which was set 0 to reviewers variable in temporary structure
	      addListing(restaurants, temp); // call function addListing passing vector restaurants and temporary structure
	    }
	  else if(fCommand == "RemoveListing") //if fCommand is equal to "RemoveListing" then proceed with else if statement, if false go to next else if statement
	    {
	      infile >> rN; // set next entry in row to variable rN
	      removeListing(restaurants, rN); // call function removeListing and pass vector restaurants and variable rN
	    }
	  else if(fCommand == "DisplayAll") //if fCommand is equal to "DisplayAll" then proceed with else if statement, if false go to next else if statement
	    {
	      displayAll(restaurants); //call displayAll function and passing vector restaurants
	    }
	  else if(fCommand == "FindByName") //if fCommand is equal to "FindByName" then proceed with else if statement, if false go to next else if statement
	    {
	      infile >> keyword; // set next entry in row to variable keyword
	      findByName(restaurants, keyword); // call function findByName passing vector restaurants and variable keyword
	    }
	  else if(fCommand == "FindByCriteria") //if fCommand is equal to "FindByCriteria" then prooceed with else if statement, if false go to next else if statement
	    {
	      infile >> rC >> rT; // set every entry after first entry to variables rC and rT
	      findByCriteria(restaurants, rT, rC); // call function findByCriteria passing vector restaurants, variable rT, and variable rC
	    }
	  else if (fCommand == "Rate") // if fCommand is equal to "Rate" then proceed with else if statement, if false go to next else if statement
	    {
	      infile >> rN >> fRating; // set every entry after first entry to variables rN and fRating
	      rate(restaurants, rN, fRating); // call function rate passing vector restaurants, variable rN, and variable fRating
	    }
	  else if(fCommand == "FindTopRated") // if fCommand is equal to "FindTopRated" then proceed with else if statement, if false go to next statement
	    {
	      infile >> rC; // set entry after first entry to variable rC
	      findTopRated(restaurants, rC); // call function findTopRated passing vector restaurants and variable rC
	    }
	  else // used as a default statement if fCommand is not equal to anything
	    {
	      cout << "wrong command" << endl; // output error message if fCommand is not equal to anything
	    }
	}
    }
  infile.close(); // close file "RestaurantsTrans.txt"
  return 0;
}

void addListing(vector<Restaurant> &restaurants, const Restaurant temp) // function gets passed with vector restaurants and structure temp, function is used to add structure temp to the end of vector restaurants, to "build" database of restaurants
{
  restaurants.push_back(temp);
}

void removeListing(vector<Restaurant> &restaurants, const string removeName) // function gets passed vector  restaurants and string removemName, function is used to remove a restaurant from the database
{
  int falseSearch = 0; // variable used to test if loop found a restaurant
  const int SIZE = restaurants.size(); // size of vector restaurants set to variable SIZE
  cout << "RemoveListing " << removeName << endl; // prints out the command
  for(int i = 0; i < SIZE; i++) // loops until variable i is equal to variable SIZE, loop is used to find a restaurant based on string removeName and remove said restaurant from the database
    {
      string rRN = restaurants[i].name; // initialize string rRN and set it to the name variable of index i
      if(rRN == removeName) // if rRN is equal to string removeName, continue if statement
        {
	  restaurants.erase(restaurants.begin() + i); // erase the index which is the addition of the beginning of the vector and variable i
          falseSearch += 1; // increment falseSearch by 1
        }
    }
  if(falseSearch == 0) // if falseSearch is equal to 0, which means the loop couldn't find the restaurant and couldn't increment falseSearch
    {
      cout << "No such restaurant exists" << endl << endl; // print out and error message
    }
}

void displayAll(const vector<Restaurant> &restaurants) // function gets passed with vector restaurants, the function is used to display all restaurants in the vector
{
  const int size = restaurants.size(); // the size of the vector restaurants is put in the variable size
  cout << "Restaurant          City         Type       Rating  Reviewers" << endl;  // prints out a table format
  cout << "---------------------------------------------------------------------" << endl; // prints out the divider between the table and the data
  for(int i = 0; i < size; i++)  // this loops until variable i is equal to variable size, loop is used to print out each structure in the vector index by index and correctly formatted
    {
      cout << setw(20) << left << restaurants[i].name << setw(13) << left << restaurants[i].city << setw(11) << left << restaurants[i].type << setw(8) << left << fixed << setprecision(2) << restaurants[i].rating << setw(17) << left << restaurants[i].reviewers << endl; // prints out the data of a restaurant in index i in the vector array
    }
  cout << endl; // skips line
}

void findByName(const vector<Restaurant> &restaurants, const string restaurantName) // function gets passed with vector restaurants and string restaurantName, the function is used to find a restaurant regardless of full name or not
{
  int falseSearch = 0; // variable used to test if loop found a restaurant
  const int SIZE = restaurants.size(); // size of vector restaurant is set in to variable SIZE
  cout << "FindByName " << restaurantName << endl; // print out command
  for(int i = 0; i < SIZE; i++) // loops until variable i is equal to variable SIZE, loop is used to find a restaurant based on the string restaurantName given by the command and print out said restaurant
    {
      string rN = restaurants[i].name; // initialze string rN and set it to index i's variable name in the restaurants vector
      if(rN.find(restaurantName) != rN.npos) // if the find member function can find restaurantName in string rN before the end of string rN continue with if statement
	{
	  cout << restaurants[i].name << ", " << restaurants[i].type << endl; // print out the name and type of index i in vector restaurants 
	  cout << restaurants[i].address << ", " << restaurants[i].city << " " << restaurants[i].state << " " << restaurants[i].zipcode << endl; // print the address, city, state, and zipcode of index i in vector restaurants
	  cout << restaurants[i].website << endl; // print out the websitr of index i in vector restaurants
	  cout << "rating: " << restaurants[i].rating << " (" << restaurants[i].reviewers << " reviews)" << endl << endl; // print out the rating and amount of reviewers of index i in vector restaurants
	  falseSearch += 1; // increment falseSearch by 1
	}
    }
  if(falseSearch == 0) // if falseSearch is equal to 0 that means the loop couldn't find the restaurantName and couldn't increment falseSearch
    {
      cout << "No such restaurant exists" << endl << endl; // print out error message
    }
}

void findByCriteria(const vector<Restaurant> &restaurants, const string city, const string type) // function get passed with vector restaurants, string city, and string type, the function is used to find a restaurant based on city and type
{
  int falseSearch = 0; // variable used to test if loop found a restaurant
  const int SIZE = restaurants.size(); // size of vector restaurant is set in to variable SIZE
  cout << "FindByCriteria " << type << " " << city << endl; // print out command
  for(int i = 0; i < SIZE; i++) // loops until variable i is equal to variable SIZE, loop is used to find a restaurant based on the string city and string type given and print out said restaurant(s) with correct city and type 
    {
      string rC = restaurants[i].city; // initialize rC and set to index i's variable city in the vector restaurants
      string rT = restaurants[i].type; // initialize rT and set to index i's variable type in the vector restaurants
      if((rT == type) && (rC == city)) // if rT compared to string type is true and rC compared to string city is also true, continue with if statement
        {
          cout << restaurants[i].name << endl; // print out the name of index i in vector restaurants
          cout << restaurants[i].address << ", " << restaurants[i].city << " " << restaurants[i].state << " " << restaurants[i].zipcode << endl; // print out the address, city, state, and zipcodde of index i in vector restaurants
          cout << restaurants[i].website << endl; // print out the website of index i in vector restaurants
          cout << "rating: " << restaurants[i].rating << " (" << restaurants[i].reviewers << " reviews)" << endl << endl; // print out the rating and amount of reviewers of index i in vector restaurants
          falseSearch += 1; // increment falseSearch by 1
        }
    }
  if(falseSearch == 0) // if falseSearch is equal to 0 that means the loops couldn't find the restaurant based on string city and string type
    {
      cout << "No such restaurant exists" << endl << endl; //print out error message
    }
}

void rate(vector<Restaurant> &restaurants, const string name, const float ratingN) // function get passed with vector restaurants, string name, and float ratingN
{
  int falseSearch = 0; // variable used to test if loop could find a restaurant and rate
  const int SIZE = restaurants.size(); // size of vector restaurant is set in to variable SIZE
  cout << "Rate " << name << " " << ratingN << endl; // print out comamnd
  if((ratingN < 1) || (ratingN > 5)) // test if ratingN is not in the range of 1 to 5, if true then continue if statement, if false then go to else statement
    {
      cout << "Rating should be a number 1 to 5" << endl; // print out rating out of range message
    }
  else
    {
      for(int i = 0; i < SIZE; i++) // loops until variable i is equal to SIZE, loop is used to calculate the rating of each restaurant with the given string name and float ratingN by the command. 
	{
	  string rN = restaurants[i].name; // initialize rN and set to index i's variable name in the vector restaurants
	  if(rN == name) // test rN is equal to string name
	    {
	      restaurants[i].reviewers = restaurants[i].reviewers + 1; // index i's variable reviewers is equal to index i's variable reviewers + 1, increments by 1 each time it loops
	      restaurants[i].rating = ((restaurants[i].rating * (restaurants[i].reviewers - 1)) + ratingN)/restaurants[i].reviewers; // calculates the actual rating by multiplying rating with reviews minus 1, then add ratingN, then divde by reviewers
	    }
	  falseSearch += 1; // increment falseSearch by 1
	}
      if(falseSearch == 0) // if falseSearch is equal to 0 that means the loop couldn't find the restaurant with the given string name and couldn't increment falseSearch
	{
	  cout << "No rating can be given due to no such restaurant existing" << endl << endl; // print out error message
	}
    }
}
void findTopRated(const vector<Restaurant> &restaurants, const string city) // function get passed with vector restaurants and string city, function is used to find the top rated restaurant in the city regardless of type
{
  int falseSearch = 0; // variable used to test if loop could find a restaurant in the city given
  Restaurant temp; // initialize a Restaurant structure named temp to hold the largest rating restaurant
  const int SIZE = restaurants.size(); // size of vector restaurant is set in to variable SIZE
  cout << "FindTopRated " << city << endl; // print out command
  for(int i = 0; i < SIZE; i++) // loops until variable i is equal to SIZE, this loops keeps looping until it finds the first restaurant that is in the city provided, breaks out of this loop when found
    {
      if(restaurants[i].city == city) // if index i's variable city is equal to string city, if true then continue if statement
        {
	  temp = restaurants[i]; // set index i in to temp structure
	  falseSearch = 1; // set falseSearch to 1
        }
      if(falseSearch == 1) // break out the for loop when falseSearch is equal to 1
	{
	  break;
	}
    }
  for(int i = 0; i < SIZE; i++) // loops until variable i is equal to SIZE, this loop compares index i and temp structure, and if index is greater than temp structure, index is set to temp structure
    {
      if(temp.city == restaurants[i].city) // if variable city in temp structure is equal to variable city in index i of vector restaurants then continue if statement
	{
	  if(temp.rating <= restaurants[i].rating) // if variable rating in temp structure is less than variable rating in index i of vector restaurants then continue if statement
	    {
	      temp = restaurants[i]; // set index i of vector restaurants to temp structure to be compared with other index i when looped again
	    }
	}
    }
  if(falseSearch == 0) // if falseSearch is equal to 0 then continue with if statement, if false go to else statement,  means that the loops couldn't find a top rated restaurant in the city provided
    {
      cout << "Cannot find the top rated restaurant in " << city << endl; // print out error message
    }
  else
    {
      cout << temp.name << ", " << temp.type << endl; // print out temp structure's variable name and type
      cout << temp.address << ", " << temp.city << " " << temp.state << " " << temp.zipcode << endl; // print out temp structure's variable address, city, state, and zipcode
      cout << temp.website << endl; // print out temp structure's variable website
      cout << "rating: " << temp.rating << " (" << temp.reviewers << " reviews)" << endl << endl; // print out temp structure's variable rating and amount of reviewers 
    }
}
