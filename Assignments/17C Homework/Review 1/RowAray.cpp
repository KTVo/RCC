#include <cstdlib> //to use rand()

#include "RowAray.h"

//Sets the size for dynamically allocated array + provide random integer values to array
RowAray::RowAray(int numCol){
    size = numCol;
    rowData = new int [size];
    
    for(int i = 0; i < size; i++){
        *(rowData + i ) = rand()%90 + 10;
    }
}

//deallocates memory
RowAray::~RowAray(){
    delete[] rowData;
}