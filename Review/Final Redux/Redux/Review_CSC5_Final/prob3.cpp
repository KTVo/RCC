//Determines if 2 integers are multiples of each other

#include <iostream>
using namespace std;

void prob3(){
    cout<<"***********************************************************\n";
    cout<<"*    Problem 3 - Determine if 2 Integers are Multiples    *\n";
    cout<<"***********************************************************\n\n";
    int num1, num2; //Holds the inputted values
    
    //Prompts for the input of 2 values
    cout<<"Enter Integer 1: ";
    cin>>num1;
    cout<<"\nEnter Integer 2: ";
    cin>>num2;
    
    cout<<endl;
    
    //Tests if the two inputted integers are multiples of each other or not
    if(num1%num2 == 0)
        cout<<num1<<" is a multiple of "<<num2;
    else if(num2%num1 == 0)
        cout<<num2<<" is a multiple of "<<num1;
    else
        cout<<num1<<" and "<<num2<<" are not multiples of each other.";
    
    cout<<endl;
}