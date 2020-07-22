/* 
 * File:   Prob_3_All_3_SimpleVectors.cpp
 * Author: Kevin Vo
 * Course: CSC-17C
 * Assignment: Midterm
 * Problem: #3
 * Created on April 19, 2018, 11:43 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <ratio>
#include <chrono>
using namespace std;

#include "Object.h"
#include "SimpleVector.h" //Simple Vector only works with Classes
#include "SimpleVectorEfficient.h" //Simple Vector only works with Classes
#include "SimpleVectorLinkedList.h"

//Global Constants

//Execution Begins Here!

/***************************************
 *                                     *
 *      Inefficient Simple Vector      *
 *                                     *
 ***************************************/
void simpleVectorPush() {
    cout<<"\n**** Problem 3 - Simple Vector (Inefficient)\n";
    //for(int k = 1; k <= 8; k *= 2){
    
    //int N = 1000 * k;
    
    int N = 1000;
    
    cout<<"\nLet N = "<<N<<endl<<endl;
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Test an object
    Object a(3),b(4);
    //cout<<"One of the Objects"<<a;
    //Test an object by populating the simple vector and print
    SimpleVector<Object> svp(a);
    //cout<<"Simple Vector Object Initialization"<<svp[svp.size()-1];
    //Push an Object and printout the last object
   // svp.push(b);
    //cout<<"Simple Vector Push next object"<<svp[svp.size()-1];
    //Fill the simple vector with 100 randomly size 2D Array Objects and
    //print the last one
    int start = time(0);
    for(int i=0;i < N;i++){
        int rSize=rand()%10;
        Object c(rSize);
        svp.push(c);
        
    }
    int end = time(0);
    cout<<"\nRuntime = "<<end - start<<endl;
   // cout<<"Size of the Simple Vector = "<<svp.size()<<endl;
    //cout<<"The last object in the Vector is "<<endl;
    //cout<<svp[svp.size()-1];
    
    //Create another simple by copy constructor
    //SimpleVector<Object> csvp(svp);
    //cout<<"Size of the Copy Constructed Simple Vector = "<<csvp.size()<<endl;
    //cout<<"The last object in the Vector is "<<endl;
    //cout<<csvp[csvp.size()-1];
    //Utilize a simple integer Simple Vector
    //int size=15;
    //SimpleVector<Object> svi(size);
    //cout<<"Size of this vector = "<<svi.size()<<endl;
    //cout<<"Last 2 Objects of the Simple Vector"<<endl;
    //cout<<"The size = "<<svi.size()<<endl<<svi[svi.size()-2]
    //                                     <<svi[svi.size()-1];
    
    svp.printOperations();
    cout<<"\n\n---------------------------------------------------------\n";
    //}
    
}



/***************************************
 *                                     *
 *      Efficient Simple Vector        *
 *                                     *
 ***************************************/
void runVectorEfficent() {
    cout<<"\n**** Problem 3 - Simple Vector (Efficient)\n";
    //for(int k = 1; k <= 8; k *= 2){
    //int N = 1000 * k
    int N = 1000;
    
    cout<<"\nLet N = "<<N<<endl<<endl;
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Test an object
    Object a(3),b(4);
    
    //Test an object by populating the simple vector and print
    SimpleVectorEfficient<Object> svp(a);
    //cout<<"Simple Vector Object Size = "<<svp.mxSize()<<svp[svp.size()-1];
    //Push an Object and printout the last object
    //svp.push(b);
    //cout<<"Simple Vector Push Size = "<<svp.mxSize()<<svp[svp.size()-1];
    
    //Fill the simple vector with 100 randomly size 2D Array Objects and
    //print the last one
    
    //int start = time(0);
    cout<<"\nTimer has Started ---\n";
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    for(int i=0; i < N;i++){
        int rSize=rand()%10;
        Object c(rSize);
        svp.push(c);
    }
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    cout<<"\nTimer has Ended ---\n";
    cout<<"\nRuntime for Simple Vector Efficient = "<<time_span.count()<<" seconds\n";
    //int end = time(0);
    
    //cout<<"\nRuntime for Simple Vector Efficient = "<<end - start<<endl<<endl;
    /*
    cout<<"Max Size and Size of the Simple Vector = "
            <<svp.mxSize()<<" "<<svp.size()<<endl;
    cout<<"The last object in the Vector is "<<endl;
    cout<<svp[svp.size()-1];
    
    //Create another simple vector by copy constructor
    SimpleVectorEfficient<Object> csvp(svp);
    cout<<"Max Size and Size of the Copy Constructed Simple Vector = "
            <<csvp.mxSize()<<" "<<csvp.size()<<endl;
    cout<<"The last object in the Vector is "<<endl;
    cout<<csvp[csvp.size()-1];
 
    //Utilize a simple integer Simple Vector
    int size=50;
    SimpleVectorEfficient<Object> svi(size);
    cout<<"Last 2 values of the Simple Vector"<<endl;
    cout<<"The Max Size and Size = "
            <<svi.mxSize()<<" "<<svi.size()<<endl
            <<svi[svi.size()-2]<<svi[svi.size()-1];
    */
    
    svp.printOperations();
    //}

}



/***************************************
 *                                     *
 *      Linked List Simple Vector      *
 *                                     *
 ***************************************/

void vectorLinkedList() {
    cout<<"\n**** Problem 3 - Simple Vector (Linked List)\n";
    //for(int k = 1; k <= 8; k*=2){
    //int N = 1000 * k;
    int N = 1000;
    cout<<"\nLet N = "<<N<<endl<<endl;
    
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Test an object
    Object a(3),b(4);
    
    /*
    //Output the objects
    cout<<"Test Object to put in front = ";
    cout<<a;
    cout<<"Test Object to put at   end = ";
    cout<<b;
     */
    
    //Create a Simple Vector using Linked Lists
    SimpleVectorLL<Object> svp(a);
    
    //Fill the simple vector with 10 randomly size 2D Array Objects and
    //print the last one
    cout<<"\nTimer has Started ---\n";
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    for(int i=0; i < N;i++){
        int rSize=rand()%10;
        Object c(rSize);
        svp.push(c);
    }
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    cout<<"\nTimer has Ended ---\n";
    cout<<"\nRuntime for Simple Vector Linked List = "<<time_span.count()<<" seconds\n";
    
    /*
    //End the Simple Vector using lists with object b
    svp.push(b);    
    cout<<"Simple Vector Object size  = "<<svp.size()<<endl;
    cout<<"Simple Vector Front Object =  "<<svp[0];
    cout<<"Simple Vector End Object   =  "<<svp[svp.size()-1];
    */
    
    svp.printOp();
    cout<<endl<<"--------------------------------------------------------"<<endl;
    //}

}