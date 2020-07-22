/* 
 * File:   Prob_11.cpp
 * Author: Kevin Vo
 * Course: CSC-17C
 * Assignment: Midterm
 * Problem: #11
 * Created on April 19, 2018, 11:43 PM
 */

#include <iostream>
#include <ctime>
#include <cmath>
#include <ctime>
#include <ratio>
#include <chrono>
#include <cstdlib>
float p3H(float);
float gxRecursion(float);
using namespace std;


float gxRecursion(float x){
    
    if(x >= -1 && x <= 1)
        if( abs(x) < 10e-6) {
       
            return (2*x-((2*x*2*x*2*x)/6.f)); //Multiply x by 2 gives 
          
        
        }
   
        x /= 2.f;
                                           //closer answer
  
    float g = ((2.f*gxRecursion(x))/(1+(gxRecursion(x)*gxRecursion(x))));
    return g;
        
    
}

void runProb11(){
    cout<<"\n**** Problem 11 - g(2x) Recursion ****\n";
    cout<<endl<<endl;
    
    for(float x = -1.0; x <= 1.1; x+= 0.10){
    

        cout<<"\t g(2x) = 2g(2x)/[1 + g(x)^2]";
        cout<<endl;

        cout<<"\n\t\tDomain: -1 <= x <= 1\n";

        cout<<"\nLet x = "<<x<<endl;


        if(x >= -1.0 && x <= 1.1){
            cout<<"\ng(2x) = "<<gxRecursion(x)<<endl;


        }else{
            cout<<"\nError: x is out of bound. x must be >= -1 AND <= 1.\n";
        }
        cout<<"\n-------------------------------------------------------\n";
    }
    
    cout<<"\n\n*** Note: Was not sure if you wanted x  = PI/4 for Problem 11"
        <<" or 12, so here is the value of g(2x) when x = PI/4 ~ 0.785398.\n";
    
    float fourth_pi = 0.785398;
    
    cout<<"\ng(2 * PI/4) = "<<gxRecursion(fourth_pi)<<endl;

}