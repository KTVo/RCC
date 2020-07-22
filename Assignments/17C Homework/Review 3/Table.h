/* 
 * Author: Kevin Vo
 * Created on March 15th, 2018, 8:54 AM
 * Course: CSC-17C-42475
 * Purpose:  Templated aggregates
 * Filename: Table.h
 */

#ifndef TABLE_H
#define	TABLE_H

#include "RowAray.h"
template <class T>
class Table{
    private:
        int szRow;
        int szCol;
        RowAray<T> **records;
    public:
        Table(int,int);
        Table(const Table &);
        ~Table();
        int getSzRow()const {return szRow;}
        int getSzCol()const {return szCol;}
        T getData(int,int) const;
        Table<T> operator+(const Table &);
};

//Constructor
//Obtains size and allocate memory for rowData
template <class T>
Table<T>::Table(int numRow, int numCol) {
    szRow = numRow;
    szCol = numCol;
    
    //Declaring size for array and setting it to a random integer through the aggregation with RowAray
    records = new RowAray<T> *[szRow];
    
    for (int i = 0; i < szRow; i++) {
        records[i] = new RowAray<T>(szCol);
    }
}

//2nd Constructor
template <class T>
Table<T>::Table(const Table &obj) {
    szRow = obj.szRow;
    szCol = obj.szCol;
    
    records = new RowAray<T> *[szRow];
    
    for (int i = 0; i < szRow; i++) {
        records[i] = new RowAray<T>(szCol);
        for (int j = 0; j < szCol; j++) {
            
            records[i]->setData(j, (obj.records[i]->getData(j)));
        }
    }
}

//Destructor
//Deallocates records[]
template <class T>
Table<T>::~Table() {
    for(int i=0; i < szRow; i++){
        delete records[i];
    }
    delete [] records;
}

//Accessor method
template <class T>
T Table<T>::getData(int numRow, int numCol) const{    
    if (numRow < 0 && numRow > szRow && numCol < 0 && numCol > szCol) {
        return 0;
    } else 
        return records[numRow]->getData(numCol);
}

//Overload
template <class T>
Table<T> Table<T>::operator +(const Table &obj){
    Table a(szRow, szCol);
    
    a.szRow = obj.szRow;
    a.szCol = obj.szCol;
    
    for(int i=0;i<szRow;i++){
        for(int j=0;j<szCol;j++){
            a.records[i]->setData(j, (records[i]->getData(j)+obj.records[i]->getData(j)));
        }
    }
    return a;
}



#endif	/* TABLE_H */