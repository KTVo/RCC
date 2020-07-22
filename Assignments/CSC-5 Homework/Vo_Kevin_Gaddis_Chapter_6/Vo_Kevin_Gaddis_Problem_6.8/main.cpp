/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Problem: Gaddis Problem 6.8
 * Description: Heads or Tails generator
 * Created on May 10, 2012, 11:24 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

unsigned coinToss(int);

int main(int argc, char** argv) {
    int FLIP, RESULT;
    cout<<"*** Coin Toss ***\n\n";
    
    cout<<"Please enter in the amount of time you wish the coin be flipped: ";
    cin>>FLIP;

    RESULT = coinToss(FLIP);
    
    if (RESULT == 1){
        
        cout<<"Coin Result: Heads\n";
    }
    else{
        cout<<"Coin Result: Tails\n";
    }

    return 0;
}

unsigned coinToss(int FLIP){
    unsigned randValue , seed = time(0);
    int x;
    
    for (x = 0; x <= FLIP; x++){
    srand(seed);
    
     randValue = 1 + rand()%2;
    }
return randValue;}
