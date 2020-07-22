#include <iostream>

using namespace std;

void prob4(){
    const int sz = 10000;   //The number of elements that will be use for freq test
    int freq[5] = {0};  //Stores the number of freq for each number
    int tempNum;    //Stores the randomly generated number to count frequency
    
    for(int i = 0; i < sz; i++){
        tempNum = rand()%5;
        
        //calculates the frequence for the 5 numbers
        if(tempNum == 0)
            freq[0]++;
        else if(tempNum == 1)
            freq[1]++;
        else if(tempNum == 2)
            freq[2]++;
        else if(tempNum == 3)
            freq[3]++;
        else
            freq[4]++;
        
    }
    
    //Display the frequency for each of the 5 numbers
    cout<<"\n--- Frequency of 5 Numbers Result ---\n";
    cout<<"\tFrequency for 0 = "<<freq[0]<<endl;
    cout<<"\tFrequency for 1 = "<<freq[1]<<endl;
    cout<<"\tFrequency for 2 = "<<freq[2]<<endl;
    cout<<"\tFrequency for 3 = "<<freq[3]<<endl;
    cout<<"\tFrequency for 4 = "<<freq[4]<<endl;
}