/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Course: CSC-17C
 * Assignment: Midterm
 * Created on April 19, 2018, 11:43 PM
 */

#include <cstdlib>
#include <iostream>
//#include "Prototypes.h"


//Problem 1 prototypes
void runLinear();
void runBinary();

//Problem 2 Prototypes
void runBubbleSort();
void runSelectionSort();

//Problem 3 Prototypes
void simpleVectorPush();
void runVectorEfficent();
void vectorLinkedList();


//Problem 7 Prototype
void prob7Fib();

//Problem 8 Prototype
void prob8Dices();

//Problem 9 Prototype
void prob9_bitVector();


//Problem 10 Prototype
void prob10PowerFN();

//Problem 11 Prototype
void runProb11();

//Problem 12 Prototype
void runProb12();

//Problem 13 Prototype
void runMode();



using namespace std;


int main(int argc, char** argv) {
    cout<<"PC Specs Used to Test Code Below:\n";
    cout<<"-----------------------------\n";
    cout<<"CPU: Intel Core i5-4670K Haswell Quad-Core 3.4 GHz\n";
    cout<<"Ram: 8GB 1600MHz DDR3\n";
    int choice;
    
    srand(time(NULL));
    
    do{
        cout<<"\nEnter 1 for Linear Search         (Problem 1)";
        cout<<"\nEnter 2 for Binary Search         (Problem 1)";
        cout<<"\nEnter 3 for Bubble Sort           (Problem 2)";
        cout<<"\nEnter 4 for Selection Sort        (Problem 2)";
        cout<<"\nEnter 5 for Simple Vector         (Problem 3)";
        cout<<"\nEnter 6 for Efficient S. Vector   (Problem 3)";
        cout<<"\nEnter 7 for Linked List S. Vector (Problem 3)";
        cout<<"\nEnter 8 for Fibonacci             (Problem 7)";
        cout<<"\nEnter 9 for Dice                  (Problem 8)";
        cout<<"\nEnter 10 for Bit Vector           (Problem 9)";
        cout<<"\nEnter 11 for Power Function       (Problem 10)";
        cout<<"\nEnter 12 for Recursive Function   (Problem 11)";
        cout<<"\nEnter 13 for Mutual Recursion     (Problem 12)";
        cout<<"\nEnter 14 for Mode w/ Set + Map    (Problem 13)";

        cout<<"\n\nEnter anything else to EXIT.\n";
        cout<<endl<<"User Input: ";
        cin>>choice;
        
        switch(choice){
            case 1: runLinear();break;
            case 2: runBinary();break;
            case 3: runBubbleSort();break;
            case 4: runSelectionSort();break;
            case 5: simpleVectorPush();break;
            case 6: runVectorEfficent();break;
            case 7: vectorLinkedList();break;
            case 8: prob7Fib();break;
            case 9: prob8Dices() ;break;
            case 10: prob9_bitVector();break;
            case 11: prob10PowerFN();break;
            case 12: runProb11();break;
            case 13: runProb12();break;
            case 14: runMode();break;

            
            default: cout<<"\nOption EXIT chosen... terminating.\n";
        }
    }while(choice >= 1 && choice <= 14);
    return 0;
}

