/* 
 * File:   Prob9_BitVector.cpp
 * Author: Kevin Vo
 * Course: CSC-17C
 * Assignment: Midterm
 * Problem: 9
 * Created on April 19, 2018, 11:43 PM
 */

#include <iostream>
#include <ctime>
using namespace std;

void prob9_bitVector(){

    int collision = 0;
    float p = 0;
    int randNum[5];
    int numTrial = 1000000;
    
    cout<<"\n**** Problem 9: Probability with Bit Vector ****\n";
    
    for(int i = 0; i < numTrial; i++){
        
        for(int j = 0; j < 5; j++)
            randNum[j] = rand()%100+1;
   

        if(randNum[0] <= 30 && randNum[1] <= 30 && randNum[2] <= 30 && 
                randNum[3] <= 30 && randNum[4] <= 30){
            collision++;
        }
    }
    
    p = (float)collision/numTrial;
    
    cout<<"\nOdds that the 5 bits randomly chosen are all filled is: "<<p<<endl;
}