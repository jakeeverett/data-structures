#include <iostream>
#include <fstream>
#include <string>
#include "Customer.cpp"
#include "QueType.cpp"
#include "PriorityQueue.cpp"

using namespace std;

int timeDay = -1;//this will tick up as the day progesses
//it is mesured in seconds and a day is defined in this project as 7 hours

int numTellers =1;//this denotes the number of bank tellers IE the number of customers that can be served at once 


int main(){
  
  int numCustomers;
  string command;
  ifstream inFile;
  ofstream outFile;
  inFile.open("input.txt");
  string name;
  int arival;
  int service;
  inFile>> command; // read commands from a text file
  inFile >> numTellers;
  inFile >> command;
  inFile >> numCustomers;
  cout << "number of Tellers: " << numTellers << "\n";
  cout << "Number of Customers: " <<numCustomers << "\n";
  //numCustomers++;// just so we dont get the dequeue operation empty list exception
  
  //seting up the waiting Line
  QueType<Customer> daysCustomers(numCustomers);//one to store the days total customers
  QueType<Customer> waitLine(numCustomers);
  QueType<Customer> Served(numCustomers);//holds people who have left the bank, is cleared every hour
  int waitTracker[50];
  int index =0;
  PriorityQueue<Customer> serviceLine(numTellers); 
  
  
  double avgWait=0;
  //int numServed;
  int counter = 0;
  
  //filling the daysCustomers queue
  for(int i =1;i<numCustomers;i++){//assuming that the file is correct
    inFile >> name;
    inFile >> command;
    inFile >> arival;
    inFile >> command;
    inFile >> service;
    Customer * holder = new Customer(name, arival, service);
    daysCustomers.Enqueue(*holder);
    //cout <<  holder->getArival() << "\n";
    counter++;
    
  }
  //done crating the waiting Queue
  
  
  
  cout << counter<<  " list filled\n";
  int hour = 1;//setting for the umber of hours in the workday
  
  
  //day loop
  while(timeDay<25200){
    try{
    timeDay++;
    
      //move customers over to the waitLine once they get to the bank  
      if(!daysCustomers.IsEmpty()){
        if(daysCustomers.getFront().getArival()==timeDay){
          //cout << daysCustomers.getFront().getArival()<< " stuff\n";
          
          waitLine.Enqueue(daysCustomers.Dequeue());
        }//while
      } 
      
      
      //dequeueuing people from the service queue once they are done
      if(!serviceLine.IsEmpty()){
        if(serviceLine.PeekPriority() == timeDay){
          Served.Enqueue(serviceLine.Dequeue());
          //this next bit is for the special case where two people need to leave the bank at the same time
          //i would have made this a while loop but for some reason this breaks the program
          if(serviceLine.PeekPriority() == timeDay){
            cout << "SPECIAL CASE\n";
            Served.Enqueue(serviceLine.Dequeue());
          }  
        }
      }
      else{
        //cout << "serviceLine is empty\n";
      }
      
      
      //enqueueing someone in the service line when there is an empty spot
      if(!waitLine.IsEmpty()){
        if(!serviceLine.IsFull()){
                
          //for figuring out avg wait time at the end
          int wait = timeDay-waitLine.getFront().getArival();
          avgWait += wait;//geting the wait time of the individual person
          waitTracker[index] = wait;
          
          //adding their individual wait times
          waitLine.getFront().setWait(wait);
          
          //enqueing
          int depTime = waitLine.getFront().getService()+timeDay;//geting their time to departure to priorites by
          Customer holder = waitLine.Dequeue();
          serviceLine.Enqueue(holder,depTime);
          index++;
        }
      }
      
      
      //printing out the cusomers served each hour
      if(timeDay%3600==0){
        cout << "for hour " << hour << "\n";
        cout <<"\n";
        index = 0;
        while(!Served.IsEmpty()){
          Customer holder = Served.Dequeue();
          //cout << holder.getName() << " " << holder.getWait() << " wait  service " << holder.getService() << "\n";//for some reason my wait time dosnt stay attached to the customer object when transfering from a priority queue to a regular queue so it would just return 0
          cout << holder.getName() << " " << waitTracker[index] << " wait  service " << holder.getService() << "\n";
          index++;
        }
        
        cout << "\n";
        cout <<"\n";
        //Served.MakeEmpty();
        index = 0;
        hour++;
      }
      
    
    }catch(EmptyQueue){
          cout << "Empty Queue Exception thrown\n";
    }//catch    
  }
  
  cout << timeDay << "\n";
  avgWait = avgWait/numCustomers;
  
  //cout << "number people served before days end "  <<numCustomers<< "\n";
  cout << "AVG Wait Time: " <<avgWait << " Seconds\n";
  
  
  //this next part list the people still left unserved due to an odity such as having a arival time at the end of the day pluss a service time that pushes there departure day until after the day has ended
  cout << "people whos still left unserved, will be blank if all were served.\n";
  
  while(!serviceLine.IsEmpty()){
    cout << serviceLine.Peek().getName() << " Aival " << serviceLine.Peek().getArival() << " Service " << serviceLine.Peek().getService()  << " Wait "<< serviceLine.Peek().getWait() <<"\n";
    serviceLine.Dequeue();
  } 
  
  
  cout << "\n";
  cout << "****NOTE****\n";
  cout << "This is the end of the program\n";
  cout << "disregard *glibc detected* this will not go away and only occurs after my main method has finished executing\n";
  cout << "\n";
  cout << "\n";
  
  
}

