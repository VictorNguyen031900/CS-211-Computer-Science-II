#include "dStack.h"
#include <iostream>

using namespace std;

Stack::Stack() //Default constructor 
{
  top = nullptr; //Sets top pointer to null
}

Stack::~Stack() //Destructor
{
  cout << "Destroying stack." << endl;
  destroy(); //calls destroy function to clear stack
}

void Stack::push(el_t in) //Function used to add char to stack
{
  StackNode *newNode; //Create a pointer to later hold user input named newNode
  newNode = new StackNode; //Allocate space for new StackNode
  newNode->element = in; //Put char in to newNode
  newNode->next = top; //Make newNode the top node in the stack

  if(isEmpty()) //If isEmpty function is true, continue with if statement
    {
      top = newNode; //newNode is the only element in the stack
      newNode->next = nullptr; //set newNode's next node pointer to null
    }
  else //If isEmpty function is false, contine with else statement
    {
      newNode->next = top; //Make newNode the top node in the stack, more than one node in stack
      top = newNode; //Make top pointer point to newNode
    }
}

void Stack::pop(el_t &out) //Function used to remove node from stack
{
  StackNode *temp; //Create a pointer to hold node temporary

  if(isEmpty()) //If isEmpty function is true then continue with if statement
    {
      cout << "The stack is empty." << endl; //Means there's no nodes to remove
    }
  else //If isEmpty function is false then continue with else statement
    {
      out = top->element; //Set char out since set by reference to top node's element
      temp = top->next; //Set temp pointer to next top node
      delete top; //Deallocate top, removes node from stack
      top = temp; //Set top to temp, node
    }
}

void Stack::displayAll() const //Function used to display all nodes in stack
{
  StackNode *temp = new StackNode; //Allocate a new Stacknode named temp
  temp = top; //Set temp pointer to top node
  if(isEmpty()) //If isEmpty function is true then continue with if statement
    {
      cout << "There were no delimiters in the string!" << endl; //Stack is empty
    }
  else //If isEmpty function is false then continue with else statement
    {
      while(temp != nullptr) //While temp pointer is not null, continue with loop
	{
	  cout << temp->element << " "; //Output temp node's element
	  temp = temp->next; //Set temp node to pointer of next node
	}
      cout << endl;
    }
}

bool Stack::isEmpty()const //Function used to determine if stack is empty or not
{
  if(top == nullptr) //Checks top if it points to null
    {
      return true;
    }
  else //If top points to a node, continue with else statement
    {
      return false;
    }
}

void Stack::destroy() //Function used to delete each node in the stack
{
  StackNode *temp;

  while(top != nullptr) //While loop to check if top points to null
    {
      temp = top->next; //Set temp pointer to next top node's address
      delete top; //Deallocate top node
      top = temp; //Set top to temp
    }
}

bool Stack::ProperlyBalanced(string input) //Function used to check string is "balanced
{
  bool output; //Used to return to main function
  el_t popChar; //Char used to hold top element in stack
  int SIZE = input.size(); //Used as a const for the length of input string
  int openBrace = 0; //Counter used to count how many { in string
  int closedBrace = 0; //Counter used to count how many } in string
  int openParenthese = 0; //Counter used to count how many ( in string
  int closedParenthese = 0; //Counter used to count how many ) in string
  int openBracket = 0; //Counter used to count how many [ in string
  int closedBracket = 0; //Counter used to count how many ] in string
  for(int i = 0; i < SIZE; i++) //For loop used to put delimiters in stack
    {
      //If and else-if statements used for each case of a delimiter
      if(input[i] == '{')
        push(input[i]);
      else if(input[i] == '}')
        push(input[i]);
      else if(input[i] == '(')
        push(input[i]);
      else if(input[i] == ')')
        push(input[i]);
      else if(input[i] == '[')
        push(input[i]);
      else if(input[i] == ']')
        push(input[i]);
    }
  while(isEmpty() != true) //While loop until stack is empty
    {
      pop(popChar); //Remove top node from stack and put in to popChar char
      //If and else-if statements used for each case of a delimiter, 
      //then increase counter accordingly
      if(popChar == '{')
        openBrace++;
      else if(popChar == '}')
        closedBrace++;
      else if(popChar == '(')
        openParenthese++;
      else if(popChar == ')')
        closedParenthese++;
      else if(popChar == '[')
        openBracket++;
      else if(popChar == ']')
        closedBracket++;
    }
  //If statements used to determine if a certain delimiter is missing
  if(openBrace > closedBrace)
    {
      cout << "Missing/Extra } !" << endl;
      output = false;
    }
  if(openBrace < closedBrace)
    {
      cout << "Missing/Extra { !" << endl;
      output = false;
    }
  if(openParenthese > closedParenthese)
    {
      cout << "Missing/Extra ) !" << endl;
      output = false;
    }
  if(openParenthese < closedParenthese)
    {
      cout << "Missing/Extra ( !" << endl;
      output = false;
    }
  if(openBracket > closedBracket)
    {
      cout << "Missing/Extra ] !" << endl;
      output = false;
    }
  if(openBracket < closedBracket)
    {
      cout << "Missing/Extra [ !" << endl;
      output = false;
    }
  //If statement used if string is "balanced"
  if((openBrace == closedBrace) && (openParenthese == closedParenthese) && (openBracket == closedBracket))
    {
      return true;
    }
  return output;
}
