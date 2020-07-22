//Purpose: Get 5 tries to get the right number
#include <iostream>

using namespace std;

void prob2(){
    cout<<"**************************************\n";
    cout<<"*    Problem 2 - Guess the Number    *\n";
    cout<<"**************************************\n\n";
    
    const int maxTurn = 5;  //Provides the number of max turns 
    int rndNum = rand()%100;    //Holds the randomly generated int for guessing
    int i;  //Counts the # of turns & checks for win status
    int numInput;   //Stores the user's input
    
    for(i = 0; i < maxTurn; i++){
        cout<<"\n\t\tTurn(s) Left: "<<(maxTurn - i)<<endl;
        cout<<"\n--- (FOR TESTING PURPOSES) --- NUMBER = "<<rndNum<<endl;
        cout<<"Enter your guessed Number: ";
        cin>>numInput;

        cout<<"\nGuess is ";
        
        //Displays status of each input
        if(numInput > rndNum)
            cout<<"too high.";
        else if(numInput < rndNum)
            cout<<"too low.";
        else{
            cout<<"RIGHT!";
            i = maxTurn;
        }
        cout<<endl;
    } 

    //Checks winning condition
    if(i != maxTurn + 1)
        cout<<"\nYou Lose.\n";
    else
        cout<<"\nYou Win.\n";
}