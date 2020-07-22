
/* 
 * Author: Kevin Vo
 * Assignment: Lab Simple Vector Modification
 * CSC-17C (42475)
 * File:   main.cpp
 * Created on March 7, 2018, 9:42 PM
 */

#include <cstdlib>
#include <iostream>
#include "SimpleVector.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    const int size = 5;
    
    SimpleVector<int> sv(size);
    
    //pushes values onto stack
    sv.push(1);
    sv.push(2);
    sv.push(3);
    sv.push(4);
    sv.push(5); 
    sv.push(6);
    sv.push(7);
    sv.push(8);
   
    sv.advPush(999); //push function that adds twice the space
    
    sv.push(9);
    sv.push(10);
    
   
    cout<<"pop: "<<sv.pop()<<endl;
    cout<<"pop: "<<sv.pop()<<endl;
    cout<<"pop: "<<sv.pop()<<endl;
    cout<<"pop: "<<sv.pop()<<endl;
    cout<<"pop: "<<sv.pop()<<endl;
    cout<<"pop: "<<sv.pop()<<endl;
    cout<<"pop: "<<sv.pop()<<endl;
    cout<<"pop: "<<sv.pop()<<endl;
    cout<<"pop: "<<sv.pop()<<endl;
    cout<<"pop: "<<sv.pop()<<endl;
    cout<<"pop: "<<sv.pop()<<endl;
    

    

    
     
      
      
      
      
      
      
    

    
    
    
    
    
    
    return 0;
}

