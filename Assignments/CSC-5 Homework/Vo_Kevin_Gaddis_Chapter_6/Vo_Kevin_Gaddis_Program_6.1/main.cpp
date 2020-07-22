/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Problem: Gaddis Problem 6.1
 * Description: Finds an item's retail price w/ markup % & wholesale cost
 * Created on May 8, 2012, 9:34 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
float calculateRetail(float, float);//Function prototype

int main(int argc, char** argv) {
    float wholesaleCOST;
    int Markup;
    
    //Output prompt and user input for program
    cout<<"Please enter the wholesale cost and markup percentage of an item to "
        <<"determine its retail price.\nWholesale Cost: ";
    cin>>wholesaleCOST;
    cout<<"Markup Percentage: ";
    cin>>Markup;
    
    //If statement for input validation (no negative digits) 
    if (wholesaleCOST < 0 || Markup < 0){
        cout<<"Input Validation: Do not accept negative value for either the "
            <<"wholesale cost of the\nitem or the markup percentage.\n";    
    }
    
    else{      
calculateRetail(wholesaleCOST, Markup);//function call    
    }

    return 0;
}

//Function
float calculateRetail(float NUMwhole, float NUMmark){
    float totalRetailPrice;
    
    totalRetailPrice = ((NUMwhole * (NUMmark / 100)) + NUMwhole);//equation
    
    //output display of the result
    cout<<"If an item's wholesale cost is "<<fixed<<setprecision(2)<<showpoint
            <<NUMwhole<<" and its mark up percentage is "<<NUMmark
            <<"%, then the\nitem's retail price is "<<totalRetailPrice<<".\n"; 
return totalRetailPrice;}
