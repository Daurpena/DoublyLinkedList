#ifndef Node_H
#define Node_H

#include <iostream> 


template<typename T> 
class Node
{
     public:
          T Data; 
          Node<T>* Previous; 
          Node<T>* Next; 
          Node(T val); 
};

template<typename T> 
Node<T>::Node(T val) : Data(val), Next(NULL) {}

#endif 