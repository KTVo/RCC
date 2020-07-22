/* 
 * File:   Prob10_ProwFunct.cpp
 * Author: Kevin Vo
 * Course: CSC-17C
 * Assignment: Midterm
 * Problem: #10
 * Created on April 19, 2018, 11:43 PM
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float recursionPower(float x, int n){
    
   if(n==0)   
       return 1;  

   //if N is odd
    if(n%2 == 1){

       n = n/2;
       return x* recursionPower(x*x, n);

   }else{   //if N is even

       n = n/2;
       return recursionPower(x*x, n);
   }

}


void prob10PowerFN(){
    cout<<"\n**** Problem 10: Recursive Power Function ****\n";

    //L
    for(int N = 0; N <= 10; N++){
        float X = 10;    //Holds the base value
    
        cout<<"\n\tZ = X ^ N\n";        //Displays the equation of the FN
        cout<<"\nLet X = "<<X<<endl;    //Displays the base
        cout<<"\nLet N = "<<N<<endl;    //Displays the exponent


        cout<<"\nZ = "<<recursionPower(X, N)<<endl;
        
        cout<<"\n--------------------------------------------------------\n\n";

    } 
}