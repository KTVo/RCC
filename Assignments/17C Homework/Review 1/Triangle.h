/* 
 * File:   Triangle.h
 * Name: Kevin Vo
 * Course: CSC-17C (42475)
 * Author: Dr. Mark E. Lehr
 * Created on February 22nd, 2018, 8:36 PM
 * Purpose:  Specification of a Triangular array from a Row Array
 */

#ifndef TRIANGLE_H
#define	TRIANGLE_H

#include "RowAray.h"

class Triangle{
    private:
        int szRow;
        RowAray **records;
    public:
        Triangle(int);
        ~Triangle();
        int getSzRow(){return szRow;}
        int getData(int,int);
};


#endif	/* TRIANGLE_H */
