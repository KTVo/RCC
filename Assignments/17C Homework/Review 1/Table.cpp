#include "Table.h"

Table::Table(int numRow,int numCol){
    //Set row and column size
    szRow = numRow;
    szCol = numCol;
    
    //setting up array records with aggregation
    records = new RowAray *[szRow];
    
    for(int i = 0; i < szRow; i++){
        records[i] = new RowAray(szCol);
    }
}

//deallocates memory after running class
Table::~Table(){
    for(int i = 0; i < szRow; i++){
        delete records[i];
    }
    
    delete[] records;
}


//return random integer
int Table::getData(int numRow, int numCol){
    return records[numRow]->getData(numCol);
}