
// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include "QueType.cpp"
using namespace std;
void testIntegersList();
//void testCharactersList();
//void testStudentsList();

int main()
{	
  int datatype;
  // Prompt user to enter type of elements 
  cout<< "Enter Elements Type\n1 for integer\n2 for character\n3 for Student\n";
  cin>> datatype;
  switch (datatype)
    { case 1: testIntegersList();
	break;
    //case 2: testCharactersList();
      //break;
    //case 3: testStudentsList();
     // break;
    }
  //….append any needed code here
  return 0;
}


void testIntegersList()
{
  QueType<int> Queuey(5);
  string command;
  ifstream inFile;
  ofstream outFile;
  inFile.open("QueType.in");
  outFile.open("outFile.txt");
  int number;
  inFile>> command; // read commands from a text file

  while (command != "Quit")
    {
      //try
	
    if (command == "IsEmpty"){
      if(Queuey.IsEmpty()){
        outFile << "The queue is empty\n";
      }
      else{
        outFile << " The list is not empty\n";
      }
    }
    else if(command =="Length"){
      outFile << "Number of items in the Queue is: " << Queuey.Length() << "\n";
    }
    else if(command=="Enqueue"){
      inFile >> number;
      Queuey.Enqueue(number);
      outFile << number << " is enqueued.\n";//why is this part not printed
    }
    else if(command == "Dequeue"){
      number = Queuey.Dequeue();
      if(number ==-999999){
        outFile<< "ERROR: Tried to dequeue when no items in list\n";
      }
      else{
        outFile << number <<" is dequeued.\n";
      }
         
    }
     
	  

      inFile>> command;

    } // while
} // testIntegersList



/*
//creats a student list and allows user to run list methods on in
void testStudentsList()
{
 
  // add code like in testIntegerslist
}


//creats a list of charaterrs and allows the user to use list methods on it
void testCharactersList()
{

  // add code to test the characters list, similar to testIntegerslist
} // testCharactersList 
*/
