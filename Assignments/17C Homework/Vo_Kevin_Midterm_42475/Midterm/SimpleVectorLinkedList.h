/* 
 * File:   SimpleVectorLinkedList.h
 * Author: Kevin Vo
 * Course: CSC-17C
 * Assignment: Midterm
 * Problem: #3
 * Created on April 19, 2018, 11:43 PM
 */

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimpleVectorLinkedList.h
 * Author: Kevin
 *
 * Created on April 30, 2018, 10:34 PM
 */

#ifndef SIMPLEVECTORLINKEDLIST_H
#define SIMPLEVECTORLINKEDLIST_H

// SimpleVector class template
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

#include "LinkedList.h"

template <class T>
class SimpleVectorLL{
    private:
       LinkedList<T> *aptr;  //Pointer to Linked List
       void memError();      // Handles memory allocation errors
       void subError();      // Handles subscripts out of range
      

    public:
       // Constructor declaration
       SimpleVectorLL(const T &);

       // Copy constructor declaration
       SimpleVectorLL(const SimpleVectorLL &);

       // Destructor declaration
       ~SimpleVectorLL();

       // Access to return the array size
       int size() const
          { return aptr->cntLst(); }

       // Access to return a specific element
       T getElementAt(int position);

       // Overloaded [] operator declaration
       T &operator[](const int &);
       
       void push(const T &);
       
       void printOp();
};

//***********************************************************
// Push the new value by allocating, copying, then adding
// new value
//***********************************************************

template <class T>
void SimpleVectorLL<T>::push(const T &val){
    //Add a value into the Linked List
    aptr->addLst(val);
}

//***********************************************************
// Constructor for SimpleVectorLL class with 1 object
//***********************************************************

template <class T>
SimpleVectorLL<T>::SimpleVectorLL(const T &d){
    
    aptr=new LinkedList<T>(d); 
}

//*******************************************
// Copy Constructor for SimpleVectorLL class. *
//*******************************************

template <class T>
SimpleVectorLL<T>::SimpleVectorLL(const SimpleVectorLL &obj){
    
   // Allocate memory for the array.
   aptr = new LinkedList<T>(obj.aptr->getObj(0));
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 1; count < obj.size(); count++){
       aptr->addLst(obj.aptr->getObj(count));
   }
}

//**************************************
// Destructor for SimpleVectorLL class.  *
//**************************************

template <class T>
SimpleVectorLL<T>::~SimpleVectorLL(){
      delete aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVectorLL<T>::memError(){
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVectorLL<T>::subError(){
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// script in the array.                                  *
//*******************************************************

template <class T>
T SimpleVectorLL<T>::getElementAt(int sub){
   if (sub < 0 || sub >= aptr->cntLst())
      subError();
   return aptr->getObj(sub);
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVectorLL<T>::operator[](const int &sub){
   if (sub < 0 || sub >= aptr->cntLst())
      subError();
   return aptr->getPtr(sub);
}

template <class T>
void SimpleVectorLL<T>::printOp(){
    aptr->printOperations();
}

#endif /* SIMPLEVECTORLINKEDLIST_H */

