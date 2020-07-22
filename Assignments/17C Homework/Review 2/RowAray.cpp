/* 
 * Author: Kevin Vo
 * Created on March 8, 2018, 8:54 AM
 * Purpose:  Abstraction, Operator Overloading, 
 *           Copy Construction and Polymorphism
 * Filename: RowAray.cpp
 */

#include <cstdlib>
#include <iostream>

using namespace std;

#include "RowAray.h"

//Constructor
//Obtains size and allocate memory for rowData
RowAray::RowAray(unsigned int size){
    this->size = size;
    
    rowData = new int[size];
    
    //Assigns a random integer to each element of rowData[]
    for (int i = 0; i < size; i++){
        rowData[i] = rand() % 90 + 10;
    }
}

//Destructor
//Deallocates rowData
RowAray::~RowAray(){
    delete [] rowData;
}

//Mutator
//Directly injects new data for specified index
void RowAray::setData(int index, int inVal){
    if (index < size && index >= 0) {
        rowData[index] = inVal;
    }
}