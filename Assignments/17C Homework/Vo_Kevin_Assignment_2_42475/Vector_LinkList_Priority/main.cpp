/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Assignment: Assignment 2
 * Purpose: Single linked list initially sorted but transforms to a priority on request
 * Course: CSC-17C (42475)
 * Created on March 27, 2018, 1:59 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Vector_LinkList.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
   
    LinkList<int> l;
    srand(time(NULL));
    int input;
    string inRequest;
    //Assigns 10 random integers to linked list
    for(int i = 0; i < 10; i++)
        l.push(rand()%989 + 10); //Within push(int) function it calls for a bubble sort on last line

    
    l.prntLst();
    do{
        cout<<"Options:\n----------\n";
        cout<<"Enter 1 for PRIORITY mode\n";
        cout<<"Enter 2 to push value with sorting ENABLED\n";
        cout<<"Enter 3 to push value with sorting DISABLED\n";
        cout<<"Enter 4 to exit\n";
        cout<<"User Input: ";
        cin>>inRequest;
    
        if(inRequest == "1"){
            cout<<endl<<"Select a value from the linked list to have PRIORITY: ";
            cin>>input;
            int index = l.findLst(input);
        
            if(index != 0){
                l.priority(input, index);
            }else{
                cout<<"\n--- Inputted integer was NOT FOUND on the linked list.\n";
            }
 
        }else if(inRequest == "2"){
            cout<<"Enter integer to be pushed (sort enabled): ";
            cin>>input;
            l.push(input);
        }else if(inRequest == "3"){
            cout<<"Enter integer to be pushed (sort disabled): ";
            cin>>input;
            l.pushNoSort(input);
        }else if(inRequest == "4"){
            cout<<"Terminating...\n";
        }
        
        if(inRequest != "4")
            l.prntLst();
    
    }while(inRequest != "4");
    
    return 0;
}

