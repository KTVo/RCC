/* 
 * File:   Problem_5.h
 * Author: Kevin Vo
 * Instructor: Dr. Lehr
 * Course: CSC-17C (42475)
 * Assignment: Final
 * Created on May 31, 2018, 8:31 AM
 */

#ifndef PROBLEM_5_H
#define PROBLEM_5_H
#include <iostream>
using namespace std;
class BinaryTree{
    private:
        struct Node{
            Node *left;
            Node *right;
            string data;
        };

        Node *root; //Points to the first node
        
        //prints the different traverses
        void prntIn(Node*);
        
        int size;
        int cmp;
        int eq;
        int incr;
     

    public:
        //Constructor
        BinaryTree();

        //Insert values onto tree
        void insert(string);

        //Display the printed orders
        void showIn();
        
        int getSize(){return size;}
        
        void getOpStat();
        bool searchIn(const string);
};

#endif /* PROBLEM_5_H */

