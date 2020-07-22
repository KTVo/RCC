/* 
 * name:  Kevin Vo
 * date:  Feb. 26th, 2012
 * Problem:  Gaddis Ch.2 Problem: 7
 * Description:  Display ocean levels
 * preferences in Ocean Levels
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

//This program will show ocean levels within 5, 7 & 10 years beginning with
//an uprise of 1.5 millimeters per year
int main(int argc, char** argv) {

    //Use of "float" for for the statements
    float Rise = 1.5,//Measurement of rise per year
           Yr5 = 5 * Rise,//Rise of ocean lvl in 5 years
           Yr7 = 7 * Rise,//"  " 7 years
           Yr10 = 10 * Rise;//"  " 10 years
           

    //Output of the of ocean's levels
    cout<<"Gaddis Problem 2.7 Answers:\n"<<endl;
   
    
    //Prompt for calculating ocean's level in the near future
    cout<<"This program will include the predicted measurements of rising ocean's\n";
    cout<<"levels in the up upcoming years, and NOT the actual the sea level itself.";
    cout<<""<<endl<<endl;
    
    //User's notice of how to use the info.
    cout<<"Note: The values that are displayed is to be added on top of\n";
    cout<<"the current ocean's level, rather than on top of each other.\n"<<endl;
    
    //The predicted measurements of rising ocean's lvls in 5, 7 & 10 years
    cout<<"Rise of Ocean's Level in 5yrs: "<<Yr5<<" millimeters higher\n"<<endl;
    cout<<"Rise of Ocean's Level in 7yrs: "<<Yr7<<" millimeters higher\n"<<endl;
    cout<<"Rise of Ocean's Level in 10yrs: "<<Yr10<<" millimeters higher"<<endl;
    
    
    
    return 0;
}

