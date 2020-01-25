#include "Customer.h"
#include<string>
#include <stdio.h> 
#include <stdlib.h> 
using namespace std;

//default constructor
Customer::Customer(){
  Name = "bob";
  Arival = rand()%25200;//rand gen arival time
  Service = (rand()%360)+120;//from 120 to 480
  Wait = 0;
}



Customer::Customer(string name, int Atime, int Stime){
  Name = name;
  Arival = Atime;
  Service = Stime;
  
  //Arival = rand()%25200;//rand gen arival time
  //Service = (rand()%360)+120;//from 120 to 480
  Wait = 0;
}


    
void Customer::setName(string name){
  Name = name;
}
//does Arival need to be set by input or just call rand() in seter
void Customer::setArival(int time){
  Arival = time;
}
void Customer::setService(int time){
  Service = (rand()%360)+120;//from 120 to 480
}
void Customer::setWait(int time){
  Wait = time;
}

string Customer::getName(){
  return Name;
}
int Customer::getArival(){
  return Arival;
}
int Customer::getService(){
  return Service;
}
int Customer::getWait(){
  return Wait;
}

