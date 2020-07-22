/* 
 * File:   Prob12_MutualRecursion.cpp
 * Author: Kevin Vo
 * Course: CSC-17C
 * Assignment: Midterm
 * Problem: #12
 * Created on April 19, 2018, 11:43 PM
 */

#include <iostream>
#include <cmath>    //For using abs() FN

int C(int);
int S(int);
void runProb12();

using namespace std;

float C(float x);
float S(float x);

void runProb12(){
    float x = 3.14159265359/4;
    
    cout<<"\n**** Problem 12 Mutual Recursion w/ C(2x) and S(2x) ****\n";
    
    cout<<"\nLet x = PI/4 ~ "<<x<<endl<<endl;
    
    cout <<"C(2x) = "<< C(x);
    cout <<"\nS(2x) = "<< S(x);
    
    cout<<endl<<endl;
    
}

float C(float x){
    //Stop at base condition: |x| < 10^-6
    if(abs(x)< 10e-6) 
        return (1/(2*x) + x/6); 
    
    x/=2;                                     
    
    return (0.5 * C(x)*S(x));
}

float S(float x){
    float c;    //Holds value of C(x)
    float s;    //Holds value of S(x)
    
    //Stop at base condition: |x| < 10^-6
    if(abs(x)< 10e-6) 
        return (1 + (2*x*x)); 
    
    x/=2;                                      
    
   
    c = C(x);
    s = S(x);
    
    return (c*c*s*s) / (c*c - s*s);
}

