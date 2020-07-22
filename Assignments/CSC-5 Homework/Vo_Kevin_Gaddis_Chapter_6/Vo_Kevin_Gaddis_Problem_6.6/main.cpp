/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Problem: Gaddis Problem 6.6
 * Description: Calculates the kinetic energy of an object
 * Created on May 10, 2012, 9:56 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

void kineticEnergy(float &, float &);

int main(int argc, char** argv) {
    float kineticEnergyDIS;
    float inputMass, inputVelocity;
    const float half = .50;
    
    kineticEnergy(inputMass, inputVelocity);
    
    kineticEnergyDIS =  half * (inputMass*(inputVelocity*inputVelocity));
    
    cout<<"The Kinetic Energy of the object is "<<kineticEnergyDIS<<endl;
    
    return 0;
}

void kineticEnergy(float &inputMass, float &inputVelocity){
  
    cout<<"Please enter the mass of the object in kilograms: ";
    cin>>inputMass;
    
    cout<<"Please enter the velocity of the object in meter per second: ";
    cin>>inputVelocity;
    
}