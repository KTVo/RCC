/* 
 * name:  Kevin Vo
 * date:  Feb. 25th, 2012
 * Problem:  Gaddis Ch.2 Problem: 6
 * Description:  Calculating total annual pay
 * preferences in Annual Pay
 * 
 */

#include <cstdlib>
#include <iostream>
using namespace std;

//This program will help calculate an employee's total annual pay
int main(int argc, char** argv) {
    
    //Defining variables w/ double b/c the value does not change of what is
    //already inputed
    double payAmount = 1.700e3,//The amount paid each time
          payPeriods = 26,//How many times the employee gets paid 
          annualPay = payAmount * payPeriods;//Amount of an entire year's income
    
    //Output Display of the program
    cout<<"Gaddis Problem 2.6 Answer:\n";
    cout<<""<<endl;
    cout<<"Total Annual Pay: $"<<annualPay<<endl;//Answer to Gaddis Prob. 2.6

    return 0;
}

