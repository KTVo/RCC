/* 
 * File:   Problem_1.h
 * Author: Kevin Vo
 * Instructor: Dr. Lehr
 * Course: CSC-17C (42475)
 * Assignment: Final
 * Created on May 31, 2018, 8:31 AM
 */

#ifndef PROBLEM_1_H
#define PROBLEM_1_H




#include <cstdlib>
#include <iostream>
#include <string>       //For string manipulation

using namespace std;

class Hash{
    private:
        int numItem;
        
        static const int tableSize = 512; //Allows us to define the size of the table inside the class
        
        struct Item{
            string initial;   //that person's initials;
            Item *next;     //Has the ability to point to another "Item"
        };
        
        //Creating hash table
        Item *HashTable[tableSize]; //We're using an array as our table
                                    //It also has the ability to point to an Item
        
        string rndVal;
        
        int cmpH;
        int eqH;
        int incrH;
    public:
        //Constructor
        Hash();
        int phoneHash(string, bool);         //Generates an integer index from a string that's the key 
        void printValue(int);    //Prints out the values within an index
        void insert(string);   //Assigns values name then initial
        int countChain(int);    //Returns the number of Items within a chain
                                //Accepts the index
        void printTable();   //Prints the entire hash table
        void printItem(int);    //prints one item with index
        
        int getNumItem(){return numItem;}
        
        static const int getTableSize(){ return tableSize; }
        
        string getInitial(int indx){
            return HashTable[indx]->initial; 
        }
        
        void hashFoundItem(const string);
        
        void getOpStatHash();
        
        string getRndVal(){
            return rndVal;
        }
        
        void setRndVal(string s){
            rndVal = s;
        }
        //Displays collision results of this hash table
        void displayCollisions();

};






#endif /* PROBLEM_1_H */

