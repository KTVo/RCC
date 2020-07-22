/* 
 * File:   SimpleVectorEfficient.h
 * Author: Kevin Vo
 * Course: CSC-17C
 * Assignment: Midterm
 * Problem: #3
 * Created on April 19, 2018, 11:43 PM
 */

#ifndef SIMPLEVECTOREFFICIENT_H
#define SIMPLEVECTOREFFICIENT_H


// SimpleVectorEfficient class template
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function

using namespace std;

template <class T>
class SimpleVectorEfficient{
    private:
       T *aptr;          // To point to the allocated array
       int arraySize;    // Number of elements in the array
       int maxSize;      // Maximum Array size before copy
       void memError();  // Handles memory allocation errors
       void subError();  // Handles subscripts out of range
       int incr;
       int equal;
       int cmp;
       int mult;

    public:
       // Default constructor
       SimpleVectorEfficient()
          { aptr = 0; arraySize = 0;}

       // Constructor declaration
       SimpleVectorEfficient(int);
       
       // Constructor declaration
       SimpleVectorEfficient(const T &);

       // Copy constructor declaration
       SimpleVectorEfficient(const SimpleVectorEfficient &);

       // Destructor declaration
       ~SimpleVectorEfficient();

       // Access to return the array size
       int size() const
          { return arraySize; }
       
       // Access to return the max array size before copy
       int mxSize() const
          { return maxSize; }

       // Access to return a specific element
       T getElementAt(int position);

       // Overloaded [] operator declaration
       T &operator[](const int &);
       
       void push(T&);
       
       void printOperations();
};

//***********************************************************
// Push the new value by allocating, copying, then adding
// new value
//***********************************************************

template <class T>
void SimpleVectorEfficient<T>::push(T &val){
    cmp++;
    if(arraySize==maxSize){
        mult++;
        equal++;
        maxSize*=2;
        
        //Declare new array pointer
        T *naptr;

        // Allocate memory for the new array.
        try{
            equal++;
          naptr = new T [maxSize];
        }catch (bad_alloc){
          memError();
        }

        equal++;
        //Fill the Array
        for (int count = 0; count < arraySize; count++){
            equal++;
            cmp++;
            incr++;
            
            naptr[count]=aptr[count];
        }

        incr++;
        equal+=2;
        //Add new value and increment the array size
        naptr[arraySize++]=val;

        //Delete the old array and point to new array
        delete []aptr;
        
        equal += 2;
        aptr=0;
        aptr=naptr;
    }else{
        incr++;
        equal++;
        aptr[arraySize++]=val;
    }
}

//***********************************************************
// Constructor for SimpleVectorEfficient class with 1 object
//***********************************************************

template <class T>
SimpleVectorEfficient<T>::SimpleVectorEfficient(const T &d){
   incr = 0;
   cmp = 0;
   equal = 0;
   mult = 0;
   
   arraySize = 1;
   maxSize=1;
   // Allocate memory for the array.
   try{
      aptr = new T [arraySize];
   }catch (bad_alloc){
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < arraySize; count++)
      aptr[count]=d;
}

//***********************************************************
// Constructor for SimpleVectorEfficient class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVectorEfficient<T>::SimpleVectorEfficient(int s){
   incr = 0;
   cmp = 0;
   equal = 0;
   mult = 0;
   
   arraySize = s;
   maxSize=s;
   // Allocate memory for the array.
   try{
      aptr = new T [s];
   }catch (bad_alloc){
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < arraySize; count++){
      int rdm=rand()%8+2;
       aptr[count]=T(rdm);
   }
}

//*******************************************
// Copy Constructor for SimpleVectorEfficient class. *
//*******************************************

template <class T>
SimpleVectorEfficient<T>::SimpleVectorEfficient(const SimpleVectorEfficient &obj){
   incr = 0;
   cmp = 0;
   equal = 0;
   mult = 0;
    
   // Copy the array size.
   arraySize = obj.arraySize;
   maxSize=obj.maxSize;
   
   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVectorEfficient class.  *
//**************************************

template <class T>
SimpleVectorEfficient<T>::~SimpleVectorEfficient(){
   if (arraySize > 0)
      delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVectorEfficient<T>::memError(){
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVectorEfficient<T>::subError(){
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVectorEfficient<T>::getElementAt(int sub){
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
T &SimpleVectorEfficient<T>::operator[](const int &sub){
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}


template <class T>
void SimpleVectorEfficient<T>::printOperations(){
    cout<<"\n\nNumber of Compare Operations = "<<cmp;
    cout<<"\nNumber of Increment Operations = "<<incr;
    cout<<"\nNumber of Equal Operations = "<<equal;
    cout<<"\nNumber of Arithmetic (+, /, *, -) Operations = "<<mult;
    cout<<"\nTotal Operations = "<<cmp + incr + equal + mult<<endl<<endl;
}

#endif /* SIMPLEVECTOREFFICIENT_H */

