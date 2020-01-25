#include<iostream>
#include<string>

using namespace std;

class Customer
{
public: 
    Customer();
    Customer(string name, int Atime, int Stime);
    
    void setName(string name);
    void setArival(int time);
    void setService(int time);
    void setWait(int time);
    
    string getName();
    int getArival();
    int getService();
    int getWait();
    
private:
    string Name;
    int Arival;
    int Service;
    int Wait;
};//Student
