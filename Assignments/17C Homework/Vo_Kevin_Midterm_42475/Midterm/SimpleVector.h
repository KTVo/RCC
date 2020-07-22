/* 
 * File:   SimpleVectorPush.h
 * Author: Dr. Mark E. Lehr
 * Student Name: Kevin Vo
 * Created on April 25th, 2018, 4:32 PM
 * Purpose:  Simple Vector only works with Class Wrapper Objects
 *           Inefficient Push implemented
 */

#ifndef SIMPLEVECTORPUSH_H
#define	SIMPLEVECTORPUSH_H


// SimpleVector class template
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function


using namespace std;

template <class T>
class SimpleVector{
    private:
       T *aptr;          // To point to the allocated array
       int arraySize;    // Number of elements in the array
       void memError();  // Handles memory allocation errors
       void subError();  // Handles subscripts out of range
       int C_incr;
       int C_cmp;
       int C_equal;

    public:
       // Default constructor
       SimpleVector()
          { aptr = 0; arraySize = 0;}

       // Constructor declaration
       SimpleVector(int);
       
       // Constructor declaration
       SimpleVector(const T &);

       // Copy constructor declaration
       SimpleVector(const SimpleVector &);

       // Destructor declaration
       ~SimpleVector();

       // Access to return the array size
       int size() const
          { return arraySize; }

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
void SimpleVector<T>::push(T &val){
    //Declare new array pointer
    T *naptr;

    // Allocate memory for the new array.
    try{
        C_equal++;
        C_incr++;
      naptr = new T [arraySize+1];
    }catch (bad_alloc){
      memError();
    }
    
    C_equal++;
    //Fill the Array
    for (int count = 0; count < arraySize; count++){
        C_incr++;
        C_cmp++;
        C_equal++;
        naptr[count]=aptr[count];
    }
    
    C_incr++;
    C_equal++;
    //Add new value and increment the array size
    naptr[arraySize++]=val;
    
    //Delete the old array and point to new array
    delete []aptr;
    
    C_equal+=2;
    aptr=0;
    aptr=naptr;
    
}

//***********************************************************
// Constructor for SimpleVector class with 1 object
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(const T &d){
    C_incr = 0;
    C_cmp = 0;
    C_equal = 0;
    
   arraySize = 1;
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
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s){
   C_incr = 0;
   C_cmp = 0;
   C_equal = 0;
    
   arraySize = s;
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
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj){
   C_incr = 0;
   C_cmp = 0;
   C_equal = 0; 
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
SimpleVector<T>::~SimpleVector(){
   if (arraySize > 0)
      delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError(){
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError(){
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub){
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
T &SimpleVector<T>::operator[](const int &sub){
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

template <class T>
void SimpleVector<T>::printOperations(){
    cout<<"\n\nNumber of Compare Operations = "<<C_cmp;
    cout<<"\nNumber of Increment Operations = "<<C_incr;
    cout<<"\nNumber of Equal Operations = "<<C_equal;
    cout<<"\nTotal Operations = "<<C_cmp + C_incr + C_equal<<endl<<endl;
}

#endif	/* SIMPLEVECTORPUSH_H */