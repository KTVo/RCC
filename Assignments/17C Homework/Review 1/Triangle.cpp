#include "Triangle.h"

//Set the row size for array then uses aggregation to fill records array with random integer
Triangle::Triangle(int numRow){
    szRow = numRow;
    
    records = new RowAray* [szRow]; 
    
    for(int i = 0; i < szRow; i++){
        records[i] = new RowAray(szRow);
    }
}

//Deallocates memory when usage of class is finished
Triangle::~Triangle(){
    for(int i = 0; i <szRow; i ++){
        delete records[i];
    }
    
    delete[] records;
}

//returns the a random int value
int Triangle::getData(int numRow,int numCol){
    return records[numRow]->getData(numCol);
}