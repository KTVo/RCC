/* 
 * Author: Kevin Vo
 * Created on March 15th, 2018, 8:54 AM
 * Course: CSC-17C-42475
 * Purpose:  Templated aggregates
 * Filename: RowAray.cpp
 */


#ifndef ROWARAY_H
#define	ROWARAY_H
#include <cstdlib>

template <class T>
class RowAray{
    private:
        unsigned int size;
        T *rowData;
    public:
        RowAray(int);
        ~RowAray();
        int getSize(){return size;}
        T getData(int i){return rowData[i];}
        void setData(int,T);
};


//Constructor
//Obtains size and allocate memory for rowData
template <class T>
RowAray<T>::RowAray( int size) {
    this->size = size;
    
    rowData = new T[this->size];
    
    //Assigns a random integer to each element of rowData[]
    for (int i = 0; i < this->size; i++) {
        rowData[i] = rand() % 90 + 10;
    }
}

//Destructor
//Deallocates rowData
template <class T>
RowAray<T>::~RowAray() {
    delete [] rowData;
}

//Mutator
//Directly injects new data for specified index
template <class T>
void RowAray<T>::setData(int index, T inVal) {
    if (index < size && index >= 0) {
        rowData[index] = inVal;
    }
}
#endif	/* ROWARAY_H */