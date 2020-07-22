/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Instructor: Dr. Lehr
 * Assignment: Lab 7 Merkle Tree
 * Course: CSC-7 (42833)
 * File: main.cpp
 * Created on June 5, 2016, 7:12 PM
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <sstream>
#include "PJWHash.h"


using namespace std;


int main(int argc, char** argv) {

    string L1 = "Then out spake brave Horatius, The Captain of the Gate:";
    string L2 = "To every man upon this earth Death cometh soon or late.";
    string L3 = "And how can man die better Than facing fearful odds,";
    string L4 = "For the ashes of his fathers, And the temples of his Gods.";
    
    unsigned int hash0_0, hash0_1, hash1_0,hash1_1, hash0, hash1, TOPhash;

    hash0_1 = PJWHash(L1);
    hash0_0 = PJWHash(L2);
    hash1_1 = PJWHash(L3);
    hash1_0 = PJWHash(L4);

    cout<<"    Merkle Tree Lab\n-------------------------\n";

    cout<<"\nL1 = \""<<L1<<"\""<<setw(9)<<"  IS   "<<"Hash 0-1 = "<<hash0_1;
    cout<<"\nL2 = \""<<L2<<"\""<<setw(9)<<"  IS   "<<"Hash 0-0 = "<<hash0_1;
    cout<<"\nL3 = \""<<L3<<"\""<<setw(12)<<"  IS   "<<"Hash 1-1 = "<<hash1_1;
    cout<<"\nL4 = \""<<L4<<"\""<<setw(6)<<" IS   "<<"Hash 1-0 = "<<hash1_0;
    cout<<endl;

    unsigned int temp;
    string tempStr;

    temp = hash0_0 + hash0_1;

    ostringstream convert;
    convert<<temp;
    tempStr = convert.str();

    hash0 = PJWHash(tempStr);

    cout<<"\nHash 0 = PJWHash(Hash 0-0 + Hash 0-1) = "<<hash0<<endl;

    temp = hash1_0 + hash1_1;

    convert<<temp;
    tempStr = convert.str();

    hash1 = PJWHash(tempStr);
    cout<<"\nHash 1 = PJWHash(Hash 1-0 + Hash 1-1) = "<<hash1<<endl;

    temp = hash0 + hash1;

    convert<<temp;
    tempStr = convert.str();

    TOPhash = PJWHash(tempStr);
    cout<<"\nTOP HASH = PJWHash(Hash 0 + Hash 1) = "<<TOPhash<<endl;
    
    return 0;
}

