#include<iostream>
#include<string>
#include "PriorityQueue.h"


//construcstor (default)
template <class ItemType>
PriorityQueue<ItemType>::PriorityQueue(){
  front = NULL;
  //rear= NULL;//dont think i need a rear
  length=0;
}



template <class ItemType>  
void PriorityQueue<ItemType>::MakeEmpty(){
    front = NULL;
    length =0;
  //front->next = rear;
  //rear->next = front;
}

template <class ItemType>
bool PriorityQueue<ItemType>::IsEmpty() const{
  if (length==0){//this was not right used front->next==NULL
    return true;
  }
  else{
    return false;
  }
}

template <class ItemType>
bool PriorityQueue<ItemType>::IsFull() const{
  return false;
}

template <class ItemType>
void PriorityQueue<ItemType>::Enqueue(ItemType value, int p){
  QueueNode<ItemType> * newItem  = new QueueNode<ItemType>;
  newItem->info = value;
  newItem->priority = p;//creating new node
  temp = front;
  //cout << "madeItem\n";
  //case queue is empty
  if(IsEmpty()){//check if empty
    //cout << "empty stuff\n";
    front = newItem;
    //cout << "added\n";
    length++;
  }
  else{
    //case insert at front
    if(front->priority > p){
      //cout << "2\n";
      curr=front;//old head
      front = newItem;//assigning newItem to the head position
      front->next=curr;//moving old head back
      length++;
    }
    else{
      //index through list to find pos
      //cout << " About ot run loop\n"; 
      
      temp = front;
      /* for debugging
      if(temp->next!=NULL){
          cout <<temp->next->info << "\n";
          cout << temp->next->priority << "\n";
          cout << value << "\n";
          cout << p << "\n";
          cout << (temp->next->priority < p) << "\n";
      }
      */
      //finding where to insert
      while(temp->next !=NULL && temp->next->priority < p){
        temp = temp->next;
      }
      //at end of list or requiered posiotion
      //cout << "3\n";
      if(temp->next==NULL){
        temp->next = newItem;
      }
      else{
        curr = temp->next;
        temp->next=newItem;
        newItem->next=curr;
      }
      length++;
    }  
  }
}


template <class ItemType>
void PriorityQueue<ItemType>::Dequeue(){
  if(!IsEmpty()){
    temp = front;//geting first item
    front=front->next;//linking over old first item
    length--;
    //return temp->info;  
  }
  else{
    throw EmptyQueue();
    //cout << "Tried to Dequeue from empty Queue\n";
  }
}

template <class ItemType>
int PriorityQueue<ItemType>::GetLength(){
  int size = 1;
  temp = front;
  if(front!=NULL){
    while(temp->next!=NULL){
      size++;
      temp = temp->next;  
    }  
  }
  else{
    //cout << "found front null\n";
    size =0;
  }
  return size;
}

template <class ItemType>
void PriorityQueue<ItemType>::PrintQueue(ofstream& streamy){
  temp=front;
  int i =0;
  while(i<length){
    streamy << temp->info << " " << temp->priority << " | ";
    temp=temp->next;
    i++;
  }
}

template <class ItemType>
ItemType PriorityQueue<ItemType>::Peek(){
  if(IsEmpty()){
    throw EmptyQueue();
    //cout << "Called Peek on empty List\n";  
  }
  else{
    return front->info;
  }
}

template <class ItemType>
int PriorityQueue<ItemType>::PeekPriority(){
  if(IsEmpty()){
    throw EmptyQueue();
    //cout << "Called Peek on empty List\n";  
  }
  else{
    return front->priority;
  }
}



















