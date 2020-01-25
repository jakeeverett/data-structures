#include<iostream>
#include<string>
#include "QueType.h"

//for this we will use a dynamicly allocated array

//constructor (overloaded)
template<class ItemType>
QueType<ItemType>::QueType(int i){
  SIZE = i;
  arr = new ItemType[SIZE];
  front = rear = -1;
  
//int arr[SIZE];
//int front = -1;
//int rear = -1;
}

//construcstor (default)
template <class ItemType>
QueType<ItemType>::QueType(){
  SIZE = 500;//default max size
  arr = new ItemType[SIZE];
  front = rear = -1;
}

//destuctor
template <class ItemType>
QueType<ItemType>::~QueType(){
  delete arr;
}

//makes queue empty
template <class ItemType>  
void QueType<ItemType>::MakeEmpty(){
  front = rear = -1;//think this it right
}

//checks if the queue isempty
template <class ItemType>
bool QueType<ItemType>::IsEmpty() const{
  if (front==-1 && rear==-1){
    return true;
  }
  else{
    return false;
  }
}

//checks if the queue is full
template <class ItemType>
bool QueType<ItemType>::IsFull() const{
  if(rear == SIZE-1){
    cout << "Queue is full\n";
    return true;
  }
  else{
    return false;
  }
}


//adds an item to the queue
template <class ItemType>
void QueType<ItemType>::Enqueue(ItemType value){
  if(IsFull()){
    cout << "cannot enqueue, Queue is Full\n";
  }
  else{
    if(front == -1){//case insert at front nothing in the list
      front = 0;//
    }
    rear++;
    arr[rear]=value;//insert at rear
  }
}

//made the return type itemtype so that the driver may get the item dequed
template <class ItemType>
ItemType QueType<ItemType>::Dequeue(){
int loc = front;
  if(IsEmpty()){
  cout << "Queue is empty\n";
    throw EmptyQueueReg();
    //might want to remove the next few lines
    
    //return -999999;
  }
  else{//need returns
    if(front ==rear){//removing last item
      front = rear = -1;
      return arr[loc];
    }
    else{      
      front++;//item at front is removed, so increment front
      return arr[loc];
    }
  }
}

//gets thwe length of the queue
template <class ItemType>
int QueType<ItemType>::Length(){
  int length = rear-front;
  if(rear==-1&&front==-1){
    return 0;
  }
  else{
    return length+1;
  }
}

//returns the front of the queue qithout dequeueing
template <class ItemType>
ItemType QueType<ItemType>::getFront(){
  if(IsEmpty()){
    cout << "quetype getfront\n";
    cout << front;
    throw EmptyQueueReg();
  }
  else{
    return arr[front];
  }
}

//prints the queueu
template <class ItemType>
void QueType<ItemType>::Print(){
  int loc = front;
  for(int i=0; i<Length();i++){
    cout << arr[loc].getName() <<" "  << arr[loc].getWait() <<  " Wait \n";
    loc++;
  }
}


  //int front, rear;
  //ItemType* items;
  //int maxQue;
  
  
  
  
  
//#define SIZE 5
//int arr[SIZE];
//int front = -1;
//int rear = -1;












