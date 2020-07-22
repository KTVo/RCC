/* 
 * File:   Prob1.h
 * Author: Kevin Vo
 *
 * Created on December 10, 2014, 10:43 AM
 */

#ifndef PROB1_H
#define	PROB1_H

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


class Prob1Random
{
	private:
                int arrCount;
		unsigned char *set;      //The set of numbers to draw random numbers from
		char  nset;     //The number of variables in the sequence
		int  *freq;     //Frequency of all the random numbers returned
		int   numRand;  //The total number of times the random number function is called
	public:
		Prob1Random(const char, unsigned char *);     //Constructor
		~Prob1Random(void);                       //Destructor
		char randFromSet(void);                   //Returns a random number from the set
		int *getFreq(void) const{ return freq; };                 //Returns the frequency histogram
		unsigned char *getSet(void) const{ return set; };                 //Returns the set used
		int getNumRand(void) const{ return numRand; };               //Gets the number of times randFromSet has
		                                          //been called
};

#endif	/* PROB1_H */

