/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Problem: Gaddis Problem 6.9
 * Description: Calculates the present value to deposit in savings account
 * Created on May 10, 2012, 11:57 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

float presentValue(float, float, int);

int main(int argc, char** argv) {
    int years;
    float TOTAL, futureVALUE, interest;
    cout<<"This program will provide an estimation on the required amount of "
        <<"money to be deposited\nin your savings account in order to meet your"
        <<" future value goal.\nPlease answer the following question to proceed."
        <<endl<<endl;    

    cout<<"How do much money do you expect to gain in interest by the end? $";
    cin>>futureVALUE;
    cout<<"What is your annual interest rate? $";
    cin>>interest;
    cout<<"How many years are you dedicating to reach your future value goal? $";
    cin>>years;
            
    TOTAL = presentValue(futureVALUE, interest, years);
    
    cout<<"Present Value: $"<<TOTAL<<endl;
    
    return 0;
}

float presentValue(float futureV, float inter, int yr){
    float presentVALUE;
    
    presentVALUE = futureV / pow((1 + inter), yr);

return presentVALUE;}