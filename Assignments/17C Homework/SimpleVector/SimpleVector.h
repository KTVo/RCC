/* 
 * Author: Kevin Vo
 * Assignment: Lab Simple Vector Modification
 * CSC-17C (42475)
 * File:   SimpleVector.h
 * Created on March 7, 2018, 9:42 PM
 */

// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector
{
private:
   T *aptr;          // To point to the allocated array
   int arraySize;    // Number of elements in the array
   int countElem;    // Counts number of pushes
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range
   

public:
    int getCount() const{return countElem;}
    
   // Default constructor
   SimpleVector()
      { aptr = 0; arraySize = 0; }
      
   // Constructor declaration
   SimpleVector(int);
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector();
   
   // Accessor to return the array size
   int size() const
      { return arraySize; }

   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);
   
   //Adds new values onto vector
   void push(T);
   
   //returns and remove most recent element in vector
   T pop();
   
   //Adds new values onto vector
   //If array size exceeded it will double its size
   void advPush(T);
};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
   arraySize = s;
   
   countElem = 0; //Counts # of pushes
   
   // Allocate memory for the array.
   try
   {
      aptr = new T [s];
   }
   catch (bad_alloc)
   {
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < arraySize; count++)
      *(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   // Copy the array size.
   arraySize = obj.arraySize;
   
   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
    countElem = 0;
   if (arraySize > 0)
      delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//Pass parameter into an array
template <class T>
void SimpleVector<T>::push(T value){

    //After when is size exceeded it will allocated memory temporarily to create
    //an array with one size larger
    if(countElem == arraySize){
        cout<<"Array size exceeded -- Increasing size of array by +1..."<<endl;
        T *tempArr = new T[arraySize++];
       
        
         //holds value of older exceeded array   
        for(int i = 0; i < arraySize; i++){
            *(tempArr + i) = aptr[i];
        }
       
        //assigns the latest pushed value into newly opened slot
        tempArr[countElem] = value;
       
        //returns new value to new pointer
        for(int i = 0; i < arraySize; i++){
            aptr[i] = *(tempArr + i);
        }      
    
        //deallocates memory of tempArr
        delete[] tempArr;
     
    }else{
        //if array has not been exceeded it just assign pushed value
        aptr[countElem] = value;
    }

    cout<<"Value: "<<aptr[countElem]<<" has been pushed."<<endl;

    //keeps track index for the latest value
    countElem++;
}

//returns the latest pushed value then removes it from the stack
template <class T>
T SimpleVector<T>::pop(){
    //assigns a latest value to temp so that it doesn't get lost after deletion
    T temp = getElementAt(countElem-1);
  
    //allocates memory for tempArr with one size less
    T *tempArr = new T[arraySize--];
    
    //assigns value to tempArr with one space left
    for(int i = 0; i < arraySize; i++)
        *(tempArr + i) = aptr[i];
    
    //returns
    for(int i = 0; i < arraySize; i++){
            aptr[i] = *(tempArr + i);
    }
    
    //memory deallocation
    delete[] tempArr;  
    
    //resets index back one after removing a value
    countElem--;
    
    return temp;
}

//Works similarly to push() but it adds double the space
template <class T>
void SimpleVector<T>::advPush(T value){
    
    if(countElem == arraySize){
        cout<<"Array size exceeded -- Increasing size of array by 2x..."<<endl;
        T *tempArr = new T[arraySize*=2];
      
        for(int i = 0; i < arraySize; i++){
            *(tempArr + i) = aptr[i];
        }
        
        tempArr[countElem] = value;
        
        for(int i = 0; i < arraySize; i++){
            aptr[i] = *(tempArr + i);
        }
         
        delete tempArr;
        
    }else{
        aptr[countElem] = value;
    }
    
    cout<<"Value: "<<aptr[countElem]<<" has been pushed."<<endl;
    countElem++;
}
#endif