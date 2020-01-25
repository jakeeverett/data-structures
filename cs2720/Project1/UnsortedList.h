#include<iostream>
#include<string>
class FullList{};  

class EmptyList
{};

class DuplicateItem
{};
  
template <class ItemType>
class UnsortedList
{
public: 

    UnsortedList();//default constructor
    
    UnsortedList(int max);
    // Class constructor.
    
    
   ~UnsortedList();
    // Class destructor.
    void makeEmpty();
    // Function: Initializes the list to an empty state.
    // Post: list is empty.
   
    bool isEmpty() const;
    // Function: Determines whether the list is empty.
    // Post: Function value = (list is empty)
   
   bool isFull() const;
    // Function: Determines whether the list is full.
    // Post: Function value = (list is full)
  
  void putItem(ItemType newItem);
    // Function: Adds newItem to the end of the list.
    // Post: If (List is full) FullList exception is thrown
    //       If item is already in the list DuplicateItem exception is thrown
    //       else newItem is at end of the list.
  void deleteItem(ItemType Item);
  // Function: deletes Item from the list.
  // Post: If List is empty EmptyList exception is thrown
  //       If item is not in the list an exception is thrown
  //       else newItem is not in the list.

int getLength()const;
	// Function: returns the number of items in the list
ItemType getAt(int index);
//// add remaining functions
private:
    ItemType* info;
    int Max_Items;
    int Length;
    int findIndex (ItemType item) const;
         // pre: list is initialized
         // post: If item is in the list then function value =  
         //       index of item.
         //       If item is not in the list -1 is returned

};

