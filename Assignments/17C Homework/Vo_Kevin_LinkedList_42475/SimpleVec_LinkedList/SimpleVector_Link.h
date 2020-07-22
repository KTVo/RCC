/* 
 * Author: Kevin Vo
 * Assignment: LinkList
 * CSC-17C (42475)
 * File: SimpleVector_Link.h
 * Created on March 22, 2018, 9:42 PM
 */

#ifndef SIMPLEVECTOR_LINK_H
#define	SIMPLEVECTOR_LINK_H

#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function

using namespace std;

template <class T>
class SimpleVector{
    private:
        int size;          
        int countElem; 
        void subError();
        void memError();
        
    public:
        // Default constructor
        SimpleVector(){
            size = 0;
            countElem = 0;
        }
        // Constructor declaration
        SimpleVector(int);
        // Destructor
        ~SimpleVector();
        // Overloaded [] operator declaration
        T &operator[](const int &);
        //Adds new values onto vector
        void push(T);
        // Get size of the link list
        int getSize(){return countElem;}
  
    private:
        struct Link{
            T data;          //Any integer data, to be changed any class with templates later
            Link *linkPtr;   //Self Reference which when utilized forms a linked list
        };
  
        Link *head;        //points to the head of the link list
        Link *tail;        //points to the last of the link list
        Link *current;      //traverses link list
};

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

template <class T>
SimpleVector<T>::SimpleVector(int s){
    size = s;
    countElem = s;
    try{
        //create first Link
        head = new Link;
        head->linkPtr = NULL; //set linkPtr address to null
        tail = head;
        //create the rest
        for(int i = 1; i < s; i++){
            tail->linkPtr = new Link;
            tail = tail->linkPtr;
        }
    }catch(bad_alloc){
        memError();
    }
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector(){
if(size>0){
    delete head;    
  }
  else{
    for(int i=0;i<size;i++){
      current=head->linkPtr;    
      delete head;         
      head=current;         
    }
  }
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the link list indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator [](const int& sub){
    if(sub<0 || sub>=countElem){
        subError();
    }else{
        current = head;
        
        for(int i=0;i < sub; i++){
            current = current->linkPtr;
        }
        return current->data;
    }
}

//Pass parameter into link list
template <class T>
void SimpleVector<T>::push(T value){
    
    if(countElem < size){
        tail = tail->linkPtr;
        tail->data = value;
    }else{
        if(size == 0){
            size = 1;
            countElem = 0; 
            
            //creates new link
            head = new Link;
            head->data = value;
            
            tail = head;
        }else{
            //add the first one and input the value
            tail->linkPtr = new Link;
            
            //reposition the tail and assigns a value
            tail = tail->linkPtr; 
            tail->data = value;
        }
        //position pointer to create the next node
        current = tail;
        
        for(int i = 1; i < size; i++){
            current->linkPtr = new Link();
            current = current->linkPtr;
        }
        if(countElem > 1)
            size++;
    }
  
    cout<<"Value: "<<value<<" has been pushed."<<endl;
    //increment the countElem to keep track
    countElem++;
}

#endif	 /* SIMPLEVECTOR_LINK_H */

