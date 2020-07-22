/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Problem: Gaddis Problem 6.7
 * Description: Displays a table with Fahrenheit & Celsius temperature(0F-20F) 
 * Created on May 10, 2012, 10:24 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

float celsius(float);

int main(int argc, char** argv) {
    float CelsiusDisplayed;
    int F;
    cout<<"Fahrenheit  |  Celsius\n";
    cout<<"-----------------------\n";
    
    for (F = 0; F<=20; F++){

        CelsiusDisplayed = celsius(F);
    cout<<"    "<<F<<"       |    "<<fixed<<setprecision(1)<<CelsiusDisplayed<<endl;

    }

        
    return 0;
}

float celsius(float F){
    float TOTALcelsius;
    
    TOTALcelsius = static_cast<float>(5)/9*(F-32);
    
return TOTALcelsius;}