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

template <class ItemType>
QueType<ItemType>::~QueType(){
  delete arr;
}


template <class ItemType>  
void QueType<ItemType>::MakeEmpty(){
  front = rear = -1;//think this it right
}

template <class ItemType>
bool QueType<ItemType>::IsEmpty() const{
  if (front==-1 && rear==-1){
    return true;
  }
  else{
    return false;
  }
}

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
    return -999999;//needed a place holder empty out put since needed a return type matching ItemType
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

  //int front, rear;
  //ItemType* items;
  //int maxQue;
  
  
  
  
  
//#define SIZE 5
//int arr[SIZE];
//int front = -1;
//int rear = -1;














































