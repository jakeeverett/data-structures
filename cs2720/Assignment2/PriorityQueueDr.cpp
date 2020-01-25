
// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include "PriorityQueue.cpp"
using namespace std;
void testIntegersList();
void testCharactersList();
//void testStudentsList();

int main()
{	
  int datatype;
  // Prompt user to enter type of elements 
  cout<< "Enter Elements Type\n1 for integer\n2 for character\n";
  cin>> datatype;
  switch (datatype)
    { case 1: testIntegersList();
	break;
    case 2: testCharactersList();
      break;
    //case 3: testStudentsList();
     // break;
    }
  //….append any needed code here
  return 0;
}


void testIntegersList()
{
  PriorityQueue<int> Queuey;
  string command;
  ifstream inFile;
  ofstream outFile;
  inFile.open("inFile.txt");
  outFile.open("outFile.txt");
  int number;
  int priority;
  inFile>> command; // read commands from a text file
 // cout << command << endl;
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
      outFile << "Number of items in the Queue is: " << Queuey.GetLength() << "\n";
    }
    else if(command=="Enqueue"){
      inFile >> number;
      inFile >> priority;
      Queuey.Enqueue(number, priority);
      outFile << number << " is enqueued.\n";//why is this part not printed
    }
    else if(command == "Dequeue"){
      number = Queuey.Peek();
      Queuey.Dequeue();
      outFile << number <<" was dequeued.\n";
         
    }
    else if(command=="Peek"){
      outFile << "Front Item is " << Queuey.Peek() << "\n";
    
    }
    else if(command == "PeekPriority"){
      outFile << "Priority of the front item is " << Queuey.PeekPriority() << "\n";
    
    }
    else if(command == "IsFull"){
      if(Queuey.IsFull()){
        outFile << "The Queue is Full\n";
      }
      else{
        outFile << "Queue is not full\n";
      }
    }
    else if(command == "MakeEmpty"){
      Queuey.MakeEmpty();
    }
    else if(command =="PrintQueue"){
      outFile << "Queue: ";
      Queuey.PrintQueue(outFile);
      outFile << "\n";
    }
    
     
	  

      inFile>> command;

    } // while
} // testIntegersList


void testCharactersList()
{
  PriorityQueue<char> Queuey;
  string command;
  ifstream inFile;
  ofstream outFile;
  inFile.open("inFile.txt");
  outFile.open("outFile.txt");
  char chary;
  string holder;
  int priority;
  inFile >> command; // read commands from a text file
  //cout << command << endl;
  while (command != "Quit")
    {
    try{

	
      if (command == "IsEmpty"){
        if(Queuey.IsEmpty()){
          outFile << "The queue is empty\n";
        }
        else{
          outFile << " Queue is not empty\n";
        }
      }
      else if(command =="Length"){
        outFile << "Number of items in the Queue is: " << Queuey.GetLength() << "\n";
      }
      else if(command=="Enqueue"){
        //cout << "in enqueueu \n";
        inFile >> holder;
        chary = holder.at(0);//for some reason this segfaults when i got inFile >> chary
        inFile >> priority;
        //cout << "about to add " << chary << " " << priority << "\n";
        Queuey.Enqueue(chary, priority);
        outFile << chary << " is enqueued.\n";//why is this part not printed
      }
      else if(command == "Dequeue"){
        chary = Queuey.Peek();
        Queuey.Dequeue();
        
        outFile << chary <<" was dequeued.\n";
        
           
      }
      else if(command=="Peek"){
        outFile << "Front Item is " << Queuey.Peek() << "\n";    
      }
      else if(command == "PeekPriority"){
        outFile << "Priority of the front item is " << Queuey.PeekPriority() << "\n";    
      
      }
      else if(command == "IsFull"){
        if(Queuey.IsFull()){
          outFile << "The Queue is Full\n";
        }
        else{
          outFile << "Queue is not full\n";
        }    
      }
      else if(command == "MakeEmpty"){
        Queuey.MakeEmpty();
      }
      else if(command =="List"){
        outFile << "Queue: ";
        Queuey.PrintQueue(outFile);
        outFile << "\n";
      }
      
       
  	  
  
        
      }catch (EmptyQueue){
        outFile << "Empty Queue Exception thrown\n";
      }
      inFile>> command;
    } // while
} // testIntegersList



