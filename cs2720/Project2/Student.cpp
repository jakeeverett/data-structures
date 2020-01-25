#include "Student.h"
#include<iostream>
#include<string>
using namespace std;

int StudentID;
string studentName;

//default constructor
Student::Student(){
}

//overloaded Constructor
Student::Student(int ID, string Name){
  StudentID= ID;
  studentName = Name;
}

//Setters
void Student::setName(string Name){
  studentName = Name; 
}
//setters
void Student::setID(int ID){
  StudentID = ID;
}
//Gettter
string Student::getName(){
  return this->studentName;
}
//getter
int Student::getID(){
  return this->StudentID;
}

//operator overload
bool Student::operator==(Student & rhs){
  if(this->getID() == rhs.getID()){
    return true;
  }
  else{
    return false;
  }  
}

//operator overload
bool Student::operator>(Student & rhs){
  if(this->getID() > rhs.getID()){
    return true;
  }
  else{
    return false;
  }   
}
//operator overload
bool Student::operator<(Student & rhs){
  if(this->getID() < rhs.getID()){
    return true;
  }
  else{
    return false;
  } 
}
//operator overload
bool Student::operator!=(Student & rhs){
  if(this->getID() != rhs.getID()){
    return true;
  }
  else{
    return false;
  } 
}

