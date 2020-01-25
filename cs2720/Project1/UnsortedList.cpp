#include "UnsortedList.h"
using namespace std;
//default constructor
template <class ItemType>
UnsortedList<ItemType>::UnsortedList(){
  Max_Items= 50;//max items defaulted to fifty
  Length=0;
  info= new ItemType[Max_Items];
}
 
 
template <class ItemType>
UnsortedList<ItemType>::UnsortedList(int max)
// default argument constructor
// Post: Max_Itemms and Length have been initialized.
// The array to hold the queue elements has been allocated.
{
  Max_Items= max;//max
  Length=0;
  info= new ItemType[Max_Items];
}

template <class ItemType>
UnsortedList<ItemType>::~UnsortedList()         // Class destructor
{
  delete [] info;
}

template <class ItemType>
void UnsortedList<ItemType>::makeEmpty()
// Post: Length has been reset to the empty state.
{
  Length=0;
}

template <class ItemType>
bool UnsortedList<ItemType>::isEmpty() const
// Returns true if the List is empty; false otherwise.
{
	if (Length == 0)
		return true;
	else
		return false;
 
}

template <class ItemType>
bool UnsortedList<ItemType>::isFull() const
// Returns true if the List is full; false otherwise.
{
	if (Length == Max_Items)
		return true;
	else
		return false;
	//

}

template <class ItemType>
void UnsortedList<ItemType>::putItem(ItemType newItem)
// Post: If list is not full) newItem is at the end of the list;
//       otherwise a FullList exception is thrown.  
{
	if (isFull()){
 
		cout << "list is full, Insertion failed";//throw FullList();
  }
  else 
  if (findIndex(newItem) != -1)
     cout<<"DuplicateItem \n";
  else
  {
    info[Length]= newItem;
    Length++;
  }
}
template <class ItemType>
int UnsortedList<ItemType>::findIndex(ItemType item) const
// Returns true if the List is empty; false otherwise.
{
	for (int i = 0; i < Length; i++)
	{
		if (info[i] == item)
			return i;
	}
	return -1;
	//
}
template <class ItemType>
int UnsortedList<ItemType>::getLength() const
// Returns the number of items in the List
{
	return Length;
}
template <class ItemType>
ItemType UnsortedList<ItemType>::getAt(int index)
{
	if (index < Length)
		return info[index];
	else
    cout << "index out of bounds" << endl;
    //throw; //IndexOutOfBoundException; dont need anymore
		return info[0];// -1000 -> not always of type ItemType; // throw an exception
}
/// define the remaining function


template <class ItemType>
void UnsortedList<ItemType>::deleteItem(ItemType Item){
  int index=findIndex(Item);
  if(index==-1){
    cout << "Item is not in the list\n";
  }
  else{
    info[index] = info[Length-1];
    Length--;
  }
}
