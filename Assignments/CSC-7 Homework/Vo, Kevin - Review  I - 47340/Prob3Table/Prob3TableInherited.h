/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob3TableInherited.h
 * Author: Kevin
 *
 * Created on September 20, 2017, 9:46 AM
 */

#ifndef PROB3TABLEINHERITED_H
#define PROB3TABLEINHERITED_H

#include "Prob3Table.h"

class Prob3TableInherited:public Prob3Table
{
	protected:
		int *augTable;                                  //Augmented Table with sums
	public:
		Prob3TableInherited(char *,int,int);          //Constructor
		~Prob3TableInherited(){delete [] augTable;};  //Destructor
		const int *getAugTable(void){return augTable;}; 
};

#endif /* PROB3TABLEINHERITED_H */

