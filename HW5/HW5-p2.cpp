/*************************************************************************

Creator: Victor Nguyen
Date: 4/30/19
Course: CS 211
Description: This program uses queues to determine how many combinations
 a 1 character string has, how many combinations a 2 character string has, and
 how many combinations a 3 character string has. All combinations for 
 1 character, 2 character, and 3 character strings.

*************************************************************************/

#include "dQueue.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
  Queue main; //Create a queue named main
  main.enqueue("A"); //In queue named main, add in to queue "A"
  main.enqueue("B"); //In queue named main, add in to queue "B"
  main.enqueue("C"); //In queue named main, add in to queue "C"
  main.permutations(); //Call permutations function to find combinations
  return 0;
}
