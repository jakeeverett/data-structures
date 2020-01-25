#include<iostream>
#include<string>
using namespace std;
template<class ItemType>
class QueType{
public:
  QueType(int i);
  QueType();
  ~QueType();
  void MakeEmpty();
  bool IsEmpty() const;
  bool IsFull() const;
  void Enqueue(ItemType value);
  ItemType Dequeue();
  int Length();
  
private:
  int front;//;eaving these public
  int rear;
  int SIZE;
  ItemType * arr;
  //int front
  //int rear;
  ItemType* items;
  int maxQue;
};
//#define SIZE 5
//int arr[SIZE];
//int front = -1;
//int rear = -1;
