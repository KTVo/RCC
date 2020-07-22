/* 
 * File:   Problem_5.cpp
 * Author: Kevin Vo
 * Instructor: Dr. Lehr
 * Course: CSC-17C (42475)
 * Assignment: Final
 * Created on May 31, 2018, 8:31 AM
 */

#include <cstdlib>
#include <iostream>
#include <queue>
#include <chrono>
#include <cmath>
#include "Problem_1.h"
#include "Problem_5.h"

using namespace std;
//prototype
void displayCollisions(int, Hash);

void prob5(BinaryTree &tree, Hash &table){      
                
    cout<<endl;
    cout<<"*********************************************"<<endl;
    cout<<"*          Problem 5 - Binary Trees         *"<<endl;
    cout<<"*********************************************"<<endl;
    
    if(tree.getSize() <= 0)
        cout<<"\nPlease run Problem 1 first to fill up the Tree.\n";
    else{ 
        
        cout<<"\nHash Table Results\n";
        cout<<"-----------------------";
        table.displayCollisions();
        cout<<endl;
        //Prints out Tree In-Order
        cout<<"\nPrinting Tree In-Order:\n";
        cout<<"----------------------------\n";
        tree.showIn();
        //string fVal = table.getRndVal();
        string fVal;
        
        //Prompts for input of string to be searched on Tree and Hash Table
        do{
            cout<<"\n\nEnter STRING to be searched on by the Tree and Hash = ";
            cin>>fVal;
            if(fVal.length() != 3)
                cout<<"\nError: The inputted STRING must be 3 characters long.\n";
        }while(fVal.length() != 3);
        
        cout<<endl<<endl;
        
        //Displays if string found on table
        cout<<endl;
        
        std::chrono::high_resolution_clock::time_point t1T = std::chrono::high_resolution_clock::now();
        tree.searchIn(fVal);
        std::chrono::high_resolution_clock::time_point t2T = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> time_span_tree = t2T - t1T;
    
        cout<<"\n\tRuntime for Searching in Sorted Binary Tree = "<<time_span_tree.count()<<" seconds"<<endl;
        cout<<endl;
        
        tree.getOpStat();
        
        
        //Displays if string found in hash table
        cout<<endl;
        std::chrono::high_resolution_clock::time_point t1H = std::chrono::high_resolution_clock::now();
        table.hashFoundItem(fVal);
        std::chrono::high_resolution_clock::time_point t2H = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> time_span_hash = t2H - t1H;
        
        cout<<"\n\tRuntime for Searching in Hash = "<<time_span_hash.count()<<" seconds"<<endl;
        
        float timeDeviation = time_span_tree.count()-time_span_hash.count();
        
        
        cout<<"\nDifference between Tree's Runtime and Hash's Runtime = "
            <<abs(timeDeviation)<<" seconds.\n";
        cout<<endl;
        table.getOpStatHash();
        
        
        
    }

}


//Constructor
BinaryTree::BinaryTree(){
    root = NULL;
    size = 0;
    cmp = 0;
    eq = 0;
    incr = 0;


}

//Inserts inputted data onto tree
void BinaryTree::insert(string inVal) {
    //cmp+=4;
    Node *newNode = new Node;
    Node *temp;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = inVal;
    size++;
    //incr++;

    //cmp++;
    if(root == NULL) {
        //eq++;
        root = newNode;
    }else{
        //eq++;
        Node *tRoot;
        tRoot = root;

        //cmp++;
        while(tRoot != NULL){
            temp = tRoot;
            //eq++;
            if(inVal > tRoot->data){
                //eq++;
                tRoot = tRoot->right;
            }else{
                //eq++;
                tRoot = tRoot->left;
            }
            //cmp++;
        };
        
        //cmp++;
        if(inVal < temp->data){
            //eq++;
            temp->left = newNode;
        }else{
            //eq++;
            temp->right = newNode;
        }
    }
}


//Borrowed from Dr. Lehr's code during class
/* Given a binary tree, print its nodes in inorder*/
void BinaryTree::prntIn(Node *n){
     if (n == NULL)
          return;
     /* first recur on left child */
     prntIn(n->left);
     /* then print the data of node */
     cout<<n->data<<" ";  
     /* now recur on right child */
     prntIn(n->right);
}

bool BinaryTree::searchIn(const string sVal){
    eq++;
    Node *t = root;
    
    cmp++;
    while(t != NULL){
        cmp++;
        if(t->data == sVal)
            break;
        cmp++;
        if(sVal > t->data){
            eq++;
            t = t->right;
        }else{
            cmp++;
            if(sVal < t->data){
                eq++;
                t = t->left;
            }
        }
        cmp++;
    };
     
    cmp++;         
    if(t == NULL){
        cout<<"\nNOT FOUND on TREE\n";
        return false;
    }
    
    cmp++;
    if(t->data == sVal){
        cout<<"\nFOUND on TREE\n";
        return true;
    }
   
    cout<<"\nNOT FOUND on Tree\n";
    return false;
  
}

void BinaryTree::showIn(){
 
    this->prntIn(root);
}

void BinaryTree::getOpStat(){
    cout<<endl;
    cout<<"Operations for Tree";
    cout<<"\n-------------------\n";

    cout<<"Number of Compare Operations: "<<cmp<<endl;
    cout<<"Number of Arithmetic (+, -, /, *, =) Operations: "<<eq<<endl;
    cout<<"Number of Increment Operations: "<<incr<<endl;
    cout<<"Total Numbers of Operations: "<<cmp+eq+incr<<endl;
        

}



