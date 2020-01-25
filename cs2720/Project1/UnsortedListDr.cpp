
// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include "UnsortedList.cpp"
#include "Student.h"
using namespace std;
void testIntegersList();
void testCharactersList();
void testStudentsList();

int main()
{	
  int datatype;
  // Prompt user to enter type of elements 
  cout<< "Enter Elements Type\n1 for integer\n2 for character\n3 for Student\n";
  cin>> datatype;
  switch (datatype)
    { case 1: testIntegersList();
	break;
    case 2: testCharactersList();
      break;
    case 3: testStudentsList();
      break;
    }
  //….append any needed code here
  return 0;
}


void testIntegersList()
{
  UnsortedList<int> list(5);
  string command;
  ifstream inFile;
  ofstream outFile;
  inFile.open("intcommands.txt");
  outFile.open("outFile.txt");
  int number;
  inFile>> command; // read commands from a text file

  while (command != "Quit")
    {
      try
	{
	  if (command == "IsEmpty")
	    if (list.isEmpty())
	      outFile << "list is empty\n";
	    else
	      outFile << "list is not empty\n";
	  else if (command == "PutItem")
	    {
	      inFile >> number;
	      if(list.isFull()){//also checking here because if it is cought by putItem it error msg only goes to std out not the outFile
		outFile << "list is full, Insertion failed" << endl;
	      }
	      else{
	        list.putItem(number);
	      }
	    }
	  else if (command == "IsFull")
	    {
	      if (list.isFull())
		outFile << "List is full\n";
	      else
		outFile << "List is not full\n";
	    }
	  else if (command == "GetLength")
	    outFile <<"Length = " << list.getLength()<<"\n";
	  else if (command == "PrintList")
	    {
	      outFile <<" for printlist Length = " << list.getLength()<<"\n";
	      outFile << "List Items: ";
	      int value;
	      for (int index = 0; index < list.getLength(); index++)
		{
		  value = list.getAt(index);
		  outFile << value << " ";
		}
	      outFile << "\n";
	    }
	  else if(command == "MakeEmpty"){//had to add myself
	    list.makeEmpty();
	  }
	  else if (command == "DeleteItem")
	    {
	      inFile >> number;//list item
	      list.deleteItem(number);
	    }
	  else if(command =="GetAt"){
	    inFile >> number;//list location
	    if(number< list.getLength()){
	      outFile << list.getAt(number) << endl;
	    }
	    else{
	      outFile << "index out of range" << endl;
	    }
	  }
	  // add other cases here to cover all possible commands and any invalid //command….
	  inFile>> command;

	} // try

  //catches are some what irrelevant now that we are no longer throwing exceptions
      catch (FullList)
	{
	  outFile << "List is full, FullList exception thrown." << endl;
	}
    
      catch (EmptyList)
	{
	  outFile << "List is empty, EmtpyList exception thrown." << endl;
	}

      catch (DuplicateItem)
	{
	  outFile << "DuplicateItem exception thrown." << endl;
	}

    } // while
} // testIntegersList


//creats a student list and allows user to run list methods on in
void testStudentsList()
{
  //cout << "Running student"<< endl; debugging only
  UnsortedList<Student> list(5);
  string command;
  ifstream inFile;
  ofstream outFile;
  inFile.open("studcommands.txt");
  outFile.open("outFile.txt");
  int number;
  string name;
  inFile>> command; // read commands from a text file

  while (command != "Quit")
    {
      try

	{

	  if (command == "IsEmpty")
	    if (list.isEmpty())
	      outFile << "list is empty\n";
	    else
	      outFile << "list is not empty\n";
	  else if (command == "PutItem")
	    {
	      inFile >> number;		
	      inFile >> name;
	      Student * holder = new Student(number,name);
	      if(list.isFull()){
		outFile << "list is full, Insertion failed" << endl;
	      }
	      else{
		list.putItem(*holder);
	      }
	      
	    }
	  else if (command == "IsFull")
	    {
	      if (list.isFull())
		outFile << "List is full\n";
	      else
		outFile << "List is not full\n";
	    }
	  else if (command == "GetLength")
	    outFile <<"Length = " << list.getLength()<<"\n";
	  else if (command == "PrintList")
	    {
	      outFile <<" for printlist Length = " << list.getLength()<<"\n";
	      outFile << "List Items: ";
	      //Student value = new Student(111,"steve");
	      for (int index = 0; index < list.getLength(); index++)
		{
		  outFile << list.getAt(index).getName() << " " << list.getAt(index).getID() << " ";
		}
	      outFile << "\n";
	    }
	  else if(command == "MakeEmpty"){//had to add myself
	    list.makeEmpty();
	  }
	  else if (command == "DeleteItem")//doing this wrong
	    {
	      inFile >> number;
	      //cout << number << endl; debuging line
	      //inFile >> name; DONT NEED
	      int targetLoc;//target location
	      bool found = false;
	      for(int i = 0;i<list.getLength();i++){
		//cout << (list.getAt(i)).getID() << endl; debuging line outprints student obj ID
		if(((list.getAt(i)).getID())==number){
		  targetLoc = i;
		  found = true;
		}
	      }
	      //need to get the student number goes to
	      if(found){//delets item
		Student holder = list.getAt(targetLoc);
		list.deleteItem(holder);   
	      }
	      else{//outprints error
		cout << "Item not in list" << endl;
		outFile << "Item not in list" << endl;
	      } 
	    }
	  else if(command =="GetAt"){
	    inFile >> number;
	    if(number< list.getLength()){
	      outFile << list.getAt(number).getName() << " " << list.getAt(number).getID() << endl;
	    }
	    else{
	      outFile << "index out of range" << endl;
	    }
	  }
	
	  // add other cases here to cover all possible commands and any invalid //command….
	  inFile>> command;

	} // try

      catch (FullList)
	{
	  outFile << "List is full, FullList exception thrown." << endl;
	}
    
      catch (EmptyList)
	{
	  outFile << "List is empty, EmtpyList exception thrown." << endl;
	}

      catch (DuplicateItem)
	{
	  outFile << "DuplicateItem exception thrown." << endl;
	}
 
    } // while


  // add code like in testIntegerslist
}


//creats a list of charaterrs and allows the user to use list methods on it
void testCharactersList()
{
  //cout << "Running char"<< endl; debugging only
  UnsortedList<char> list(5);
  string command;
  ifstream inFile;
  ofstream outFile;
  inFile.open("chcommands.txt");
  outFile.open("outFile.txt");
  int number;
  char character;
  inFile>> command; // read commands from a text file

  while (command != "Quit")
    {
      try

	{

	  if (command == "IsEmpty")
	    if (list.isEmpty())
	      outFile << "list is empty\n";
	    else
	      outFile << "list is not empty\n";
	  else if (command == "PutItem")
	    {
	      inFile >> character;
	      if(list.isFull()){
		outFile << "list is full, Insertion failed" << endl;
	      }
	      else{
		list.putItem(character);
	      }
	    }
	  else if (command == "IsFull")
	    {
	      if (list.isFull())
		outFile << "List is full\n";
	      else
		outFile << "List is not full\n";
	    }
	  else if (command == "GetLength")
	    outFile <<"Length = " << list.getLength()<<"\n";
	  else if (command == "PrintList")
	    {
	      outFile <<" for printlist Length = " << list.getLength()<<"\n";
	      outFile << "List Items: ";
	      char value;
	      for (int index = 0; index < list.getLength(); index++)
		{
		  value = list.getAt(index);
		  outFile << value << " ";
		}
	      outFile << "\n";
	    }
	  else if(command == "MakeEmpty"){//had to add myself
	    list.makeEmpty();
	  }
	  else if (command == "DeleteItem")
	    {
	      inFile >> character;
	      list.deleteItem(character);
	    }
	  else if(command =="GetAt"){
	    inFile >> number;
	    if(number< list.getLength()){
	      outFile << list.getAt(number) << endl;
	    }
	    else{
	      outFile << "index out of range" << endl;
	    }
	  }
 
	

	
	  // add other cases here to cover all possible commands and any invalid //command….
	  inFile>> command;

	} // try

      catch (FullList)
	{
	  outFile << "List is full, FullList exception thrown." << endl;
	}
    
      catch (EmptyList)
	{
	  outFile << "List is empty, EmtpyList exception thrown." << endl;
	}

      catch (DuplicateItem)
	{
	  outFile << "DuplicateItem exception thrown." << endl;
	}
 

    } // while
  // add code to test the characters list, similar to testIntegerslist
} // testCharactersList 
