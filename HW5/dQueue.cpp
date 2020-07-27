//Dynamic Queue
#include "dQueue.h"
#include <iostream>
using namespace std;

Queue::Queue() //Default constructor
{
  front = nullptr; //Set front pointer to null
  rear = nullptr; //Set rear pointer to null
  amount = 0; //Set amount of elements in queue to 0
}

Queue::~Queue() //Destructor
{
  amount = 0; //Set amount of element in queue to 0
  destroy(); //Call destroy function to clear queue
}

void Queue::enqueue(el_t in) //Function used to add elements in to queue
{
  QueueNode *newNode; //Create a newNode to later add in to queue
  newNode = new QueueNode; //Allocate memory for said newNode
  newNode->letter = in; //Set newNode's element to in which is a string
  newNode->next = nullptr; //Set newNode's next node pointer to null
  if(isEmpty()) //If isEmpty function is true then continue with if statement
    {
      //Means there were no elements in queue before
      front = newNode; //Set the front of the queue to newNode
      rear = newNode; //set the read of the queue to newNode
    }
  else //If isEmpty function is false then contine with else statement
    {
      //Means there were at least one element in queue before
      rear->next = newNode; //Set rear of queue to newNode
      rear = newNode;
    }
  amount++; //Increase counter to indicate number of elements in queue
}

void Queue::dequeue(el_t &out) //Function used to remove elements from the queue
{
  QueueNode *temp; //Create a pointer named temp
  if(isEmpty()) //If isEmpty is true then continue with if statement
    {
      //Means there is nothing in the queue to take out
      cout << "Underflow! There is nothing in the queue to dequeue!" << endl;
    }
  else //If isEmpty is false then continue with else statement
    {
      //Means there is at least one element in the queue to remove from
      out  = front->letter; //Set out to front's element since out is sent by reference
      temp = front; //Set pointer temp to the front's address
      front = front->next; //Set Front to next element in queue
      delete temp; //Deallocate temp to free up memory
      amount--; //Decrease the counter to indicate number of elements in queue
    }
}

void Queue::displayAll() const //Function used to display all elements in the queue
{
  QueueNode *temp; //Create a pointer named temp
  temp = front; //Set temp to front
  if(isEmpty()) //If isEmpty is true then continue with if statement
    {
      //Means queue is empty, there is nothing to display
      cout << "Underflow! There is nothing in the queue to print!" << endl;
    }
  else //If isEmpty is false then continue with else statement
    {
      while(temp != nullptr) //While loop until temp points to null
	{
	  cout << temp->letter << endl; //Output temp's element
	  temp = temp->next; //Set temp to next element in queue
	}
    }
  cout << endl;
}

bool Queue::isEmpty() const //Function used to determine if queue is empty or not
{
  if(amount == 0) //Checks if amount if 0 since amount is used to indicate number of elements in queue
    {
      return true;
    }
  else //If amount is greater than 0 then that means there is an element in queue
    {
      return false;
    }
}

void Queue::destroy() //Function used to deallocate each node in the queue
{
  QueueNode *temp; //Create a pointer named temp
  el_t dummy; //Dummy string to trick dequeue function

  while(isEmpty() != true) //While loop until isEmpty returns true
    {
      dequeue(dummy); //Removes a node from the queue one at a time
    }
}

void Queue::permutations() //Function used to display all combinations of 1,2,3 character strings
{
  int count1 = 0; //Counter used for main while loop
  int count2 = 0; //Counter used for secondary while loop
  string mainHold; //String used to concatenate with
  string secHold; //String used to concatenate with
  Queue secondary; //Create a secondary queue for concatenated strings
  Queue third; //Create a third queue for concatenated strings
  secondary.enqueue("A"); //Add string "A"
  secondary.enqueue("B"); //Add string "B"
  secondary.enqueue("C"); //Add string "C"

  displayAll(); //Display all elements in main queue, represent combinations of 1 character strings

  //While loop used for combinations of 2 character strings
  while(count1 != 9) //There is only 9 combinations for a 2 character string
    {
      dequeue(mainHold); //Get front element from main queue
      count2 = 0; //Reset secondary counter to 0
      while(count2 != 3)
	{
	  secondary.dequeue(secHold); //Get front element from secondary queue
	  third.enqueue(mainHold + secHold); //Concatenate mainHold and secHold strings and put in to third queue
	  secondary.enqueue(secHold);//Put secHold string back in to secondary queue
	  count1++; //Increase main counter
	  count2++; //Decrease secondary counter
	}
      enqueue(mainHold); //Put string back in to main queue
    }

  third.displayAll(); //Display all elements in third queue

  while(secondary.isEmpty() != true) //While loop until secondary queue is empty
    {
      secondary.dequeue(secHold); //Removes each node from queue
    }

  secHold = ""; //Clear secHold string
  count1 = 0; //Set main counter to 0

  //While loop used for combinations of 3 character strings
  while(count1 != 27) //There is only 27 combinations for a 3 character string
    {
      third.dequeue(secHold); //Get front element in third queue, put in to secHold string
      count2 = 0; //Reset secondary counter to 0
      while(count2 != 3)
	{
	  dequeue(mainHold); //Get front element from main queue
	  secondary.enqueue(secHold + mainHold); //Concatenate mainHold and secHold strings and put in secondary queue
	  enqueue(mainHold); //Put mainHold string back in to main queue
	  count1++; //Increase main counter
	  count2++; //Increase secondary counter
	}
      third.enqueue(secHold); //Put secHold string back in to third queue
    }

  secondary.displayAll(); //Display all elements in secondary queue

}
