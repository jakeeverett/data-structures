//#include "UnsortedList.h"
#include<iostream>
#include<string>
using namespace std;
//not done not right check
//see what i need to make private

class Student
{
public: 
    Student();
    //do i need a defualt constroctor
    Student(int ID, string Name);
    
    //do i just need getters
    void setName(string Name);
    void setID(int ID);
    
    string getName();
    int getID();
    
    
    bool operator==(Student & rhs);
    bool operator>(Student & rhs);
    bool operator<(Student & rhs);
    bool operator!=(Student & rhs);
    
private:
    int StudentID;
    string studentName;
};//Student