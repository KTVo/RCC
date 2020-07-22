/* 
 * File: main.cpp
 * Name: Kevin Vo
 * Instructor: Dr. Lehr
 * Course: CSC-7 (42833)
 * Date: 3/24/2016
 * Assignment: Lab 1 - Luhn Algorithm (FIXED)
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Constants

//Function Prototypes
char rndDgit();
void prpLuhn(char[],int);
void Luhn(char[],int);

int main() {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    const int SIZE=12;
    char crdCard[SIZE];
    //Prepare for Luhn encoding
    cout<<"A random number created in Prep for Luhn Digit"<<endl;
    prpLuhn(crdCard,SIZE-2);

    //Output the preLuhn credit card
    cout<<crdCard<<endl;
    //Now create a function that fills the last digit
    //using the Luhn Algorithm

    cout<<"The random number with Luhn Encoding, Output Here!"<<endl;
    
    //Calculates Luhn's alg. and displays results w/ last digit
    Luhn(crdCard, SIZE-2);

    //Exit Stage Right
    return 0;
}

void Luhn(char cc[],int nSIZE){
    int even = 0, totEven = 0, odd = 0, totOdd = 0, total = 0;
   
    //Slips up every odd and even elements
    // 2 * every even elements
    //if cc["EVEN ELEMENT"] > 9 then -9 from it
    //Odd elements, leave it alone
    //Sum all up
    for(int elem = 9; elem >= 0; elem--){
        if(elem%2!=0){
                even = (cc[elem]-48)* 2;
                if(even > 9) even -= 9;
                totEven += even;
             
            }
            else{
                odd = (cc[elem]-48);
                totOdd += odd;
              
            }
    }
        
    //Calculates and displays Sum of Digits, Check Digit, in/valid
    total = totOdd + totEven;
    cout<<"\n---Results---\n";
    cout<<"Sum of Digits: "<<total<<endl;
    total *= 9;
    total %= 10;
  
    cout<<"Check Digit = "<<total<<endl;
    cout<<"Credit Card is ";
    if(total != cc[9])cout<<"INVALID."<<endl;
    else cout<<"VALID."<<endl;
    
}

void prpLuhn(char cc[],int n){
    //Create a random cc in prep for Luhn checksum
    for(int i=0;i<n;i++){
        cc[i]=rndDgit();
    }
    //Put null terminator at the end
    for(int i=n;i<=n+1;i++){
        cc[i]='\0';
    }
}

char rndDgit(){
    return rand()%10+48;
}
