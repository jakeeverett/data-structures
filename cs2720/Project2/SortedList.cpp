#include "SortedList.h"

using namespace std;



template <class ItemType>
SortedList<ItemType>::SortedList(){
  //ListData = NULL;
  head = NULL;
  Length = 0;
}
 
template <class ItemType>
bool SortedList<ItemType>::isEmpty() const
// Returns true if the List is empty; false otherwise.
{
  
  if (Length == 0){//could also check if head==NULL
    cout << "is empty" <<endl;;
    return true;
  }
  else
    {
      cout << "not empty" << endl;
      return false;
    }
}

template <class ItemType>
bool SortedList<ItemType>::isFull() const
// Returns true if the List is full; false otherwise.
{
  return false;
}

template <class ItemType>
int SortedList<ItemType>::getLength() const
// Returns the number of items in the List
{
  //cout << Length;
  return Length;
}


template <class ItemType>
void SortedList<ItemType>::makeEmpty()//need more
// Post: Length has been reset to the empty state.
{
  if(!isEmpty()){
    Length=0;//need more
    NodeType<ItemType> * deletionPtr;
    while(head != NULL)
      {
	temp = head;//index 0
	curr = head;//index 0
	deletionPtr = temp->next;//index 1
	temp = deletionPtr->next;//index 2
	curr->next = temp;//index 0->2
	delete deletionPtr;//delet unused space
      }  
  }
  else{
    cout << "List is already empty" << endl;
  }
}


//why is this based off index
template <class ItemType>
ItemType SortedList<ItemType>::getAt(int index)//need t o redo
//Function: Returns the element at the specified position (index) in this list.
//Precondition: List is initialized.
//Postcondition: The function returns the element at the specified position in this list.
//or throws IndexOutOfBoundsException - if the index is out of range
// (index < 1 || index > length of the list).
{
  if(index<Length){
    curr = ListData;
    for(int i = 0;i<index;i++){
      curr = curr->next;
    }
    return curr->data;
  }
  else{//need to figure out a return
    cout << "Index outside of list "<< endl;
  }
 
}
 

template <class ItemType>
void SortedList<ItemType>::putItem(ItemType newItem)
{
  NodeType<ItemType> * n = new NodeType<ItemType>;
  n->data = newItem;
  NodeType<ItemType> * predecessor;
  if(findItem(newItem, predecessor)==false){
    curr = predecessor->next;
    /*
      while(curr!= NULL){//loop through list
      if(curr->data<newItem){
      temp = curr;
      curr = curr->next;
      }
      else if(curr->data > newItem){
      break;
      }
      }
    */
    if(predecessor==NULL){//list has not been fild
      n->next =head;
      head = n;
    }
    else{
      n->next= curr;
      predecessor->next = n;
    }
    Length++;  
  }
  else{
    cout << " duplicate" << endl;
    //throw DuplicateItem;
  }
  

  
}

template <class ItemType>
void SortedList<ItemType>::deleteItem(ItemType Item){
  cout << "starting delete" << endl;
  NodeType<ItemType> * deletionPtr = NULL;
  temp = ListData;
  curr = ListData;
  
  while(curr != NULL && curr->data != Item){//go through all list
    temp = curr;
    curr = curr->next;
  }
  if(temp==NULL){//deleted Item is at the head of the list
    deletionPtr = ListData;
    ListData = ListData->next;
    delete deletionPtr;
  }
  if(curr == NULL){
    cout << "Item not in List" << endl;
    //throw DeletingMissingItem;
    delete deletionPtr;
  }
  else{//found item
    deletionPtr = curr;
    curr = curr->next;
    temp->next = curr;//patching out of list
    Length--;
    delete deletionPtr;
    cout << "Deleted: " << Item << endl;
  }
}
 
//prints the pointer when empty
template <class ItemType>
void SortedList<ItemType>::printList(ofstream& streamy){
  if(!isEmpty()){//list not empty
    cout << " printing" << endl;
    curr = ListData->next;
    while(curr!=NULL){
      
      streamy << curr->data << " ";
      cout << curr->data << " ";
      curr = curr->next;
        
    }    
    cout << endl;
  }
  else{//list is empty
    //streamy << "";
  }
  
  //streamy << endl;
  //somthin
}


//this donst work but 
template <class ItemType>
void SortedList<ItemType>::merge(SortedList otherList){
  NodeType<ItemType> * n;
  
  
  cout << "mergeing" << endl;
  temp = this->head;
  NodeType<ItemType> * curr2 = otherList.head;
  curr = this->head;
  while(curr != NULL || curr2 != NULL){
    cout << "in merge loop\n";
    if (curr->data < curr2->data){//list
      temp = curr; 
      curr = curr->next;
    }
    else{
      cout << " currdata: " << curr->data;
      n->data= curr2->data;
      cout << "\n ndata: " << n->data<< "\n";
      n->next = curr;
      temp->next = n;
    }
    
    /*  old code
	putItem(otherList.getAt(i));
	cout << "deleting: " << otherList.getAt(i) << endl;
	otherList.deleteItem(otherList.getAt(i));
	i++;
    */  
  }
  
  //somthin
}

template <class ItemType>
SortedList<ItemType>::~SortedList(){
  makeEmpty();
  delete head;//do i need this
  //delete ListData;
}



template <class ItemType>
bool SortedList<ItemType>::findItem(ItemType item, NodeType<ItemType>*&predecessor) const{
  NodeType<ItemType> * h;
  h = ListData;
  predecessor = NULL;
  bool found = false;
  while(h!=NULL && !found){
    if(h->data < item){
      predecessor = h;
      h = h->next;
    }
    else{
      if(item == h->data){
        found = true;
      }
      else{
        return false;
      }
    }
  }
  return found;
}

