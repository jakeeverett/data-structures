#include<iostream>
//#include<ofstream>
#include<string>
using namespace std;
/**
class FullList{};  

class EmptyList
{};

class DuplicateItem
{};

*///unused stuff


//creating nodetype struct
template <class ItemType>
struct NodeType{
  ItemType data;
  NodeType<ItemType> *next;
};





template <class ItemType>
class SortedList
{
public: 

    SortedList();//default constructor
    
    //UnsortedList(int max);
    // Class constructor.
    
    
   ~SortedList(); // class destructor
      //Function: Deallocates all dynamically allocated data members.
      //Precondition: None.
   
    bool isEmpty() const;
    // Function: Determines if the list is empty.
    //Precondition: List is initialized.
    //Postcondition: The function returns true if the list is empty and false otherwise. 
   
   bool isFull() const;
    //Function: Determines if the list is full (memory is full).
    //Precondition: List is initialized.
    //Postcondition: The function returns true if the list is full and false otherwise. 
  
  
  int getLength() const;
  //Function: Returns number of elements in the list.
  //Precondition: List is initialized.
  //Postcondition: Function value equals number of list elements. 
  
  
  void makeEmpty();
    //Function: Deallocates all dynamically allocated data members. Reinitializes the list to empty state.
    //Precondition: None.
    //Postcondition: List is empty. 
    
  ItemType getAt(int index);
    //Function: Returns the element at the specified position (index) in this list.
    //Precondition: List is initialized.
    //Postcondition: The function returns the element at the specified position in this list.
         //or throws IndexOutOfBoundsException - if the index is out of range
          // (index < 1 || index > length of the list).
          
  void putItem (ItemType newItem);
    //Function: Adds a new element to list. This function should not allow duplicate keys, and must
    //check that there is space for the new item.
    //Precondition: List is initialized.
    //Postconditions: newItem is in the list, if newItem’s key was not in the list
       //An exception is thrown if newItem’s keys was found in the list.
       //List order property is conserved
  
  void deleteItem (ItemType item);
    //Function: Removes an element from the list.
    //Precondition: List is initialized.
    //Postconditions: item is in not in the list.
      // An exception is thrown if item was
  
  void printList (ofstream& streamy);
    //Function: Prints list elements.
    //Precondition: list is initialized.
    //Postcondition: List elements are displayed on the screen.
  
  void merge (SortedList otherList);
    //Function: Merges the current list and otherList while maintaining sortedness.
    //Preconditions: List is initialized. otherList is initialized
    //Postcondition: Function returns current list after inserting all elements of otherList.
       //Current list is sorted and with no duplicate keys.
       //List size= list.length+ otherList.length
  

private:
    NodeType<ItemType> * ListData  = new NodeType<ItemType>;
    NodeType<ItemType> * head;
    NodeType<ItemType> * curr;
    NodeType<ItemType> * temp;
    int Length;
    
    //not using findItem
    bool findItem(ItemType item, NodeType<ItemType>*&predecessor) const;
    
    
    
    /**
    
    typedef struct node{
      //int data;//
      ItemType data; 
      node * next;
    }* nodePtr;
    
    nodePtr head;//might be same as ListData not sure
    nodePtr curr;
    nodePtr temp;
    
    */
    
    /**
    struct node{
      int data;
      node * next;
    }
    
    typedef struct node* nodePtr;
    
    nodePtr head;
    */
    

};























































