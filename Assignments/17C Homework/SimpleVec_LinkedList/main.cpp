/* 
 * Author: Kevin Vo
 * Assignment: Lab Simple Vec and Linked List
 * CSC-17C (42475)
 * File: main.cpp
 * Created on March 19, 2018, 9:42 PM
 */

#include <iostream>
#include "SimpleVector_Link.h"

using namespace std;

int main(int argc, char** argv) {
    //Class declaration
    SimpleVector<int> link;
    
    //Pushing values onto link list
    link.push(0);
    link.push(33);
    link.push(11);
    link.push(99);
    link.push(101);
    
    //displaying entire link list
    cout<<endl<<"Display Link List\n------------------\n";
    for(int i = 0; i < link.getSize(); i++)
        cout<<"[ "<<link[i]<<" ] -> ";
    cout<<"[ NULL ] "<<endl;
 
  
  

 
  
  return 0;
}

