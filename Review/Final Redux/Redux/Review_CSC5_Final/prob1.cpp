//Purpose: Display input in reverse

#include <iostream>
using namespace std;
void prob1(){
    cout<<"**************************************\n";
    cout<<"*    Problem 1 - Reversed String     *\n";
    cout<<"**************************************\n\n";
    
    string strInput;
            
    cout<<"Enter a string to be reversed: ";
    
    //ignores the most recent cout's "\n" so that getline() can work properly
    cin.ignore();
    //Stores line on stream since cin does not include spaces
    getline(cin, strInput);

    
    cout<<"\nInput Reversed: ";
    //Displays inputted string in reversed
    for(int i = strInput.length(); i >= 0; i--)
        cout<<strInput[i];
    
    cout<<endl;
    
}