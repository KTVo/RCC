/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob3Table.h
 * Author: Kevin
 *
 * Created on September 19, 2017, 11:11 PM
 */

#ifndef PROB3TABLE_H
#define PROB3TABLE_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;
class Prob3Table
{
	protected:
		int rows;                                 //Number of rows in the table
		int cols;                                 //Number of cols in the table
		int *rowSum;                              //RowSum array
		int *colSum;                              //ColSum array
		int *table;                               //Table array
		int grandTotal;                           //Grand total
		void calcTable(void);                     //Calculate all the sums
	public:
		Prob3Table(char *,int,int);               //Constructor then Destructor
		~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
		const int *getTable(void){return table;};
		const int *getRowSum(void){return rowSum;};
		const int *getColSum(void){return colSum;};
		int getGrandTotal(void){return grandTotal;};
};

#endif /* PROB3TABLE_H */

