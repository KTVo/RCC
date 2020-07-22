/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Assignment: Assignment 2
 * Purpose: Singly linked list that is sorted as you add data
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
    LinkList<int> link;
    
    srand(time(NULL));
    
    //Assigns 10 random integers to linked list
    //then sorts it
    for(int i = 0; i < 10; i++)
        link.push(rand()%899 + 100);

    link.prntLst();
    
    return 0;
}

