/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 13, 2017, 11:43 AM
 * Purpose:  Used as C++ functions for testing
 *           the GET/POST of PHP/Javascript
 */

//System Libraries
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//User Libraries
#include "SavingsFunctions.h"

//Universal Global Constants here

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    
    
    float pv=100;   //Present Value $'s
    float intr=6/100.0f;   //Interest Rate %
    int nYears=12;  //Number of compounding periods years

    //Declare object for class
    SavingsFunctions inst1(pv, intr, nYears);
    
    //Perform Calculation / Call the function
    float fv1=inst1.getSave1();
    float fv2=inst1.getSave2();
    float fv3=inst1.getSave3();
    float fv4=inst1.getSave4();
    float fv5=inst1.getSave5();
    float fv6;
    inst1.save6(fv6);
    float *fv7=inst1.save7();

    //Display the results
    cout<<"Present Value   = $"<<inst1.getPV()<<endl;
    cout<<"Interest Rate   =    "<<inst1.getIntr()*100<<"%"<<endl;
    cout<<"Number of Years =   "<<inst1.getN()<<endl;
    cout<<"Future Value    = $"<<fv1<<endl;
    cout<<"Future Value    = $"<<fv2<<endl;
    cout<<"Future Value    = $"<<fv3<<endl;
    cout<<"Future Value    = $"<<fv4<<endl;
    cout<<"Future Value    = $"<<fv5<<endl;
    cout<<"Future Value    = $"<<fv6<<endl;
    inst1.display(fv7,nYears+1);
    
    //Deallocate memory
    delete []fv7;
    return 0;
}