/* 
 * File:   Prob8_Dices.cpp
 * Author: Kevin Vo
 * Course: CSC-17C
 * Assignment: Midterm
 * Problem: #8 - 4 Dice Problem
 * Created on April 19, 2018, 11:43 PM
 */

#include <cstdlib>
#include <ctime>
#include <iostream>

#include <algorithm> //For using sort() in STL.
using namespace std;


void prob8Dices(){
    
    cout<<"\n**** Problem 8 Dices ****\n";
    
    int const numDie = 4;           //Holds the number of dice to be simulated
    int const numTrial = 100000;    //Number of loops to get an average
    int count4Kind = 0;             //Holds count for 4 of a kind
    int count3Kind = 0;             //Holds count for 4 of a kind
    int count1Pair = 0;             //Holds count for 1 Pair
    int count2Pairs = 0;            //Holds count for 2 pairs
    
    int Die[numDie];                //Holds a face for each dice
    
    //Loops by number of trails to get an average
    for(int k = 0; k < numTrial; k++){
        //Use to figure out each outcome per trial
        int checkCountFirst = 1; 
        int checkCount2nd = 1;
        
        //Assign random values of for each dice
        for(int i = 0; i < numDie; i++)
            Die[i] = rand()%6+1;

        //Uses STL's sort() to have the result of the dice be in order
        sort(Die, Die+numDie);
   
       //Finds the number of collisions
        for(int i = 0; i < numDie - 1; i++){
            if(Die[i] == Die[i+1]){
                checkCountFirst++;
            }else{
                if(checkCountFirst > 1){
                    checkCount2nd = checkCountFirst;
                }
                checkCountFirst = 1;
            }
        }

        //Stores the amount of event for each condition
        if(checkCountFirst == 2 && checkCount2nd != 2)
            count1Pair++;
        
        if(checkCountFirst != 2 && checkCount2nd == 2)
            count1Pair++;
        
        if(checkCountFirst == 2 && checkCount2nd == 2)
            count2Pairs++;
        
        if(checkCountFirst == 3 || checkCount2nd==3)
            count3Kind++;
        
        if(checkCountFirst == 4)
            count4Kind++;
        
    }

    //Displays accumulated results from all trials
    cout<<"\n\t\tNumber of Trials = "<<numTrial<<endl<<endl;
    
    cout << "Number of 1 Pair = " <<count1Pair;
    cout << "\nNumber of 2 Pairs = " <<count2Pairs;
    cout << "\nNumber of 3 of a Kind = "<<count3Kind;
    cout << "\nNumber of 4 of a Kind = "<< count4Kind;
    
    cout<<"\n\nAverage for 1 Pair = "
        <<(float)count1Pair/(float)numTrial*(float)100
        <<" %\n";
            
    cout<<"\nAverage for 2 Pairs = "
        <<(float)count2Pairs/(float)numTrial*(float)100
        <<" %\n";
    
    cout<<"\nAverage for 3 of a Kind = "
        <<(float)count3Kind/(float)numTrial*(float)100
        <<" %\n";
    
    cout<<"\nAverage for 4 of a Kind = "
        <<(float)count4Kind/(float)numTrial*(float)100
        <<" %\n";

    cout<<endl<<endl;
 
}

