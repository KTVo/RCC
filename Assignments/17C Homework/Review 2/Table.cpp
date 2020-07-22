/* 
 * Author: Kevin Vo
 * Created on March 8, 2018, 8:54 AM
 * Purpose:  Abstraction, Operator Overloading, 
 *           Copy Construction and Polymorphism
 * Filename: Table.cpp
 */

#include <cstdlib>

#include "Table.h"

//Constructor
Table::Table(unsigned int numRow, unsigned int numCol){
    //Obtains and set rows and col size
    szRow = numRow;
    szCol = numCol;

    //Declaring size for array and setting it to a random integer through the aggregation with RowAray
    columns = new RowAray *[szRow];
    
    for (int i = 0; i < szRow; i++) 
        columns[i] = new RowAray(szCol);
    
}

//2nd Constructor
Table::Table(const Table &obj){
    szRow = obj.szRow;
    szCol = obj.szCol;
    
    columns = new RowAray *[szRow];
    
    for (int i = 0; i < szRow; i++) {
        columns[i] = new RowAray(szCol);
        for (int j = 0; j < szCol; j++){
            columns[i]->setData(j, (obj.columns[i]->getData(j)));
        }
    }
}

//Destructor for Table class
//Deallocates columns[]
Table::~Table() {
    for (int i = 0; i < szRow; i++){
        delete columns[i];
    }
    delete [] columns;
}

//Accessor method
int Table::getData(int numRow, int numCol) const{
    
    if (numRow < 0 && numRow > szRow && numCol < 0 && numCol > szCol){
        return 0;
    } else 
        return columns[numRow]->getData(numCol);
    
}

//Mutator method
//Injects new value for columns[]
void Table::setData(int numRow, int numCol, int inVal){
    columns[numRow]->setData(numCol, inVal);
}