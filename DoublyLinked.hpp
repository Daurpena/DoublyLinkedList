#ifndef DLinkedList_H
#define DLinkedList_H
#include <iostream> 
#include "Node_D.hpp"

template<typename T> 
class DoublyLinked
{
     private: 
          int node_count=0; 
     public:
          DoublyLinked(); 
          Node<T>* Head; 
          Node<T>* Tail; 

     //Insert ---------------------------
          void InsertHead(T val);
          void InsertTail(T val);
          void Insert(int index, T val); 
     
     //Remove ---------------------------
          void RemoveHead(); 
          void RemoveTail(); 
          void Remove(int index); 
     
          int Find_Index(T val); 
          int Count();
          void PrintList(); 
};   

// METHOD DEFINITIONS  ---------------------------------------------
template<typename T> 
DoublyLinked<T>::DoublyLinked() : node_count(0), Head(NULL), Tail(NULL) {}

// INSERT HEAD  ---------------------------------------------
template<typename T> 
void DoublyLinked<T>::InsertHead(T val)
{
     Node<T> * node = new Node<T>(val);      //Create a new node
     node->Next = Head;                 //Prepare new node to be Head. Set new head before current Head

     if(Head != NULL)                   //if the current Head exists, set previous node to new node
          { Head->Previous = node;}
     
     Head = node; 

     if(node_count == 0)                //if linked list has 1 element, Head is Tail 
          { Tail = Head; }
     node_count++;                      // Element is added, increment count    
}

// INSERT TAIL ---------------------------------------------
template<typename T> 
void DoublyLinked<T>::InsertTail(T val)
{
     if(Tail == NULL && Head == NULL)    //If list is empty, add Head node 
     { 
          InsertHead(val);                   
          return; 
     }
     else 
     {
          Node<T>* node = new Node<T>(val);   //If list not empty, create node & set Tail to new node
          Tail->Next = node;
          node->Previous = Tail; 
          Tail=node; 
     }

     node_count++;                      //Increment count to reflect added element 
     return; 
}

// INSERT  --------------------------------------------------
template<typename T> 
void DoublyLinked<T>::Insert(int index, T val)
{   
     if(index < 0 || index > node_count)     //If index out of range, return with error message.
          { 
               std::cout << "[INSERT ERROR]: Index out of bounds.  \n "; 
               return; 
          }
     if(index == 0 )                         //If list is empty, insert node as Head
          {
               InsertHead(val); 
               return; 
          }
     else if(index == node_count)            //If index matches node_count, insert node as Tail
          {
               InsertTail(val); 
               return;
          }
          
     Node<T> * prevNode = Head;              //Start from Head to find index position 
     for(int i =0 ; i < index-1; i++)        
          {
               prevNode = prevNode->Next;
          }
     
     Node<T> * nextNode = prevNode->Next;    //Once index position found, create next node
     Node<T> * node = new Node<T>(val);      //Create new node to store inserted Data
     node->Next = nextNode;
     node->Previous = prevNode;
     prevNode->Next = node; 
     nextNode->Previous =  node;   
     node_count++;                           //Increment count for added element 
}

// REMOVE HEAD  --------------------------------------------------
template<typename T>
void DoublyLinked<T>::RemoveHead()
{
     if(node_count == 0) return;             //if list is empty, do nothing
     Node<T>*node = Head;                   //Save current node to new node
     
     Head = Head->Next;                      //Point Head to next node
     delete node;                            

     if(Head != NULL)                        // If there's still an element in the list, 
          { Head->Previous = NULL;}          //the previous pointer of Head should be NULL
     node_count--; 

}

// REMOVE TAIL  --------------------------------------------------
template<typename T> 
void DoublyLinked<T>::RemoveTail()
{
     if(node_count == 0 )                    //If list is empty, inform the user 
     {
          std::cout << "[REMOVE TAIL ERROR]: List is empty.\n";
          return; 
     }
     if(node_count == 1 ) { RemoveHead(); return;  }   //if list has 1 element, remove
     
     Node<T>* prevNode = Head;               
     Node<T>* node = Head->Next;             //node will maintain ahead of prevNode

     while(node->Next != NULL)               //Iterate through linked list until NULL is found
     {
          prevNode = prevNode->Next;         //prevNode will become Tail-1
          node = node->Next;
     }
     prevNode->Next = NULL;                  
     Tail = prevNode;                        //prevNode is now the last node, so Tail = prevNode
     delete node;

     node_count--; 

}

// REMOVE  ------------------------------------------------------
template<typename T> 
void DoublyLinked<T>::Remove(int index)
{
     if(node_count == 0 )                    //If list is empty, inform the user 
     {
          std::cout << "[REMOVE ERROR]: List is empty.\n";
          return; 
     }

     if(index < 0 || index >= node_count )   //If index is out of bounds, inform the user 
     { 
          std::cout << "[REMOVE ERROR]: Index out of bounds.  \n";
          return; 
     }

     if(index == 0) { RemoveHead(); return ;}
     
     if(index == node_count-1) { RemoveTail(); return; }

     Node<T>* prevNode = Head;              // Start list traversal from Head 
     for(int i=0; i < index-1; i++)          
     {
          prevNode = prevNode->Next;         // Set prevNode before index
     }
     
     Node<T>* node = prevNode->Next;        // Set node to be deleted
     Node<T>* nextNode = node->Next;        // Point next node after node to be deleted
     prevNode->Next = nextNode;              // prevNode bypass node to be deleted
     nextNode->Previous = prevNode;          // nextNode bypass node to be deleted 

     delete node; 
     node_count--;                           //decrement count to reflect removed node
}

// SEARCH  ------------------------------------------------------
template<typename T> 
int DoublyLinked<T>::Find_Index(T val)           //Return index for data
{
     if(node_count == 0 ) 
          { 
               std::cout << "[FIND INDEX ERROR]: List is empty.\n";
               return -1; 
          }
     int index=0; 
     Node<T>* node = Head; 

     while(node->Data != val)
     {
          index++;
          node = node->Next; 

          if(node == NULL)
          {
               std::cout << "[FIND INDEX ERROR]: Data not found.\n";
               return -1; 
          }    
     }
     return index; 
}


// PRINT LINKED LIST  -------------------------------------------
template<typename T> 
void DoublyLinked<T>::PrintList()
{
     Node<T>* node = Head;
     while(node != NULL)
     {
          std::cout << node->Data << " -> "; 
          node = node->Next; 
     }
     std::cout << " NULL" <<"\n";
}

template<typename T> 
int DoublyLinked<T>::Count()
{
     if(node_count > 0) 
     {
          return node_count;
     }
     else 
     {
          return -1; 
     }
}

#endif
