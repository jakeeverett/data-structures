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

//overloaded constructor
template <class ItemType>
PriorityQueue<ItemType>::PriorityQueue(int i){
  front = NULL;
  //rear= NULL;//dont think i need a rear
  length=0;
  maxLength = i;
}


//makes list empty
template <class ItemType>  
void PriorityQueue<ItemType>::MakeEmpty(){
    front = NULL;
    length =0;
  //front->next = rear;
  //rear->next = front;
}

//checks if empty
template <class ItemType>
bool PriorityQueue<ItemType>::IsEmpty() const{
  if (length==0){//this was not right used front->next==NULL
    return true;
  }
  else{
    return false;
  }
}

//checks if full
template <class ItemType>
bool PriorityQueue<ItemType>::IsFull() const{
  if(length==maxLength){//make sure lengthis sumed right
    return true;
  }  
  else{
    return false;  
  }
}

//adds item to queue
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
    //cout << front->priority << " " << p << "\n";
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
      int counter = 1;
      if(length>1){
        while(counter<length && temp->next->priority < p){
          //cout <<  " run\n";
          temp = temp->next;
          counter++;
        }      
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

//removes the front item
template <class ItemType>
ItemType PriorityQueue<ItemType>::Dequeue(){
  if(!IsEmpty()){
    temp = front;//geting first item
    front=front->next;//linking over old first item
    length--;
    return temp->info;  
    
  }
  else{
    throw EmptyQueue();
    //cout << "Tried to Dequeue from empty Queue\n";
  }
}

//gets the length of the queue
template <class ItemType>
int PriorityQueue<ItemType>::GetLength(){
  return length;
}

//prints queue
template <class ItemType>
void PriorityQueue<ItemType>::PrintQueue(){
  temp=front;
  int i =0;
  while(i<length){
    cout << temp->info.getName() << " " << temp->priority << " | ";
    temp=temp->next;
    i++;
  }
}

//gets item with higjes priority
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

//gets the highes priority
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




