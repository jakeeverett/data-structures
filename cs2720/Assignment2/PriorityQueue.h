#include<iostream>
#include<string>
using namespace std;

class EmptyQueue{};

template <class ItemType>
struct QueueNode{
  ItemType info;
  int priority;
  QueueNode<ItemType> * next;
};

/*
// https://www.geeksforgeeks.org/priority-queue-using-linked-list/
QueueNode<ItemType> QueueNode(ItemType data, int p){
  QueueNode<ItemType> holder = (QueueNode<ItemType>*)malloc(sizeof(QueueNode<ItemType>));
  holder->info = data;
  holder->priority = p;
  holder->next = NULL;
  
  return holder;
}
*/

template<class ItemType>
class PriorityQueue{
public:
  //PriorityQueue(int i);
  PriorityQueue();
  void MakeEmpty();
  bool IsEmpty() const;
  bool IsFull() const;
  void Enqueue(ItemType value, int p);//O(n) overhead??
  void Dequeue();//O(1)
  int GetLength();
  void PrintQueue(ofstream& streamy);
  ItemType Peek();//reterns the item with most priority
  int PeekPriority();//should return priority of item at front of queue
  
private:
//need a queue front and rear equall to null
  QueueNode<ItemType> * front  = new QueueNode<ItemType>;
  //QueueNode<ItemType> * head = new QueueNode<ItemType>;
  //QueueNode<ItemType> * rear = new QueueNode<ItemType>;
  QueueNode<ItemType> * curr;
  QueueNode<ItemType> * temp;
  
  int length;
};