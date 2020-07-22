/* 
 * Author: Kevin Vo
 * Created on March 8, 2018, 8:54 AM
 * Purpose:  Abstraction, Operator Overloading, 
 *           Copy Construction and Polymorphism
 * Filename: PlusTab.cpp
 */

#include "PlusTab.h"
#include "AbsTabl.h"

//Overload
PlusTab PlusTab::operator +(const PlusTab &a){
    PlusTab obj(szRow, szCol);
    
    obj.szRow = a.szRow;
    obj.szCol = a.szCol;
    
    for(int i=0; i < szRow; i++){
        for(int j = 0; j < szCol; j++){
            obj.columns[i]->setData(j, (columns[i]->getData(j) + a.columns[i]->getData(j)));
        }
    }
    return obj;
}