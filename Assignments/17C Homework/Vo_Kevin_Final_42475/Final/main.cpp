/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Instructor: Dr. Lehr
 * Course: CSC-17C (42475)
 * Assignment: Final
 * Created on May 31, 2018, 8:31 AM
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Problem_1.h"
#include "Problem_5.h"

using namespace std;


void prob1(BinaryTree &, Hash &);
void prob2();
void prob3();
void prob4();
void prob5(BinaryTree &, Hash &);
void prob6();


int main(int argc, char** argv) {
    //Object for sorted Binary Tree
    BinaryTree tree;
    //Object for hash table (linked list array)
    Hash table;
    srand(time(NULL));
    
    char choice;
    
    do{
        cout<<"\nCSC-17C Final\n";
        cout<<"\nEnter 1 for Problem 1 - Hashing";
        cout<<"\nEnter 2 for Problem 2 - Stacks";
        cout<<"\nEnter 3 for Problem 3 - Queues";
        cout<<"\nEnter 4 for Problem 4 - Sorting";
        cout<<"\nEnter 5 for Problem 5 - Binary Trees";
        cout<<"\nEnter 6 for Problem 6 - Weighted Graph";
        cout<<"\nEnter anything else to EXIT";
        cout<<"\n\nUser Input: ";
        cin>>choice;
        
        switch(choice){
            case '1': prob1(tree, table); break;
            case '2': prob2(); break;
            case '3': prob3(); break;
            case '4': prob4(); break;
            case '5': prob5(tree, table); break;
            case '6': prob6(); break;
            
            default: cout<<"\nOption Exit selected... Terminating\n"; break;
        }
        
    }while(choice >= '1' && choice <= '6');
    return 0;
}

