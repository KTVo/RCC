//Purpose: Display Array of Random Ints then re-Display after Sorted

#include <iostream>
using namespace std;

//Prototpes for Problem 5
void printArrTable(const int[], const int);
void bubbleSort(int[], const int);

void prob5(){
    const int sz = 100; //The size of the table
     
    int rndNum [sz];    //Holds each value for the table
    
    cout<<"\n\tTotal Number of Elements = "<<sz<<endl;
    
    //Assigns Random Value to table
    for(int i = 0; i < sz; i++)
        rndNum[i] = rand()%90 + 10;
    
    cout<<"\n--- Unsorted ---\n";
    
    printArrTable(rndNum, sz);
    
    bubbleSort(rndNum, sz);
    
    cout<<"\n--- Sorted ---\n";
    
    printArrTable(rndNum, sz);
        
}

//Sorts the array with bubble sort (ascending order)
void bubbleSort(int rndNum[], const int sz){
    for(int i = 0; i < sz; i++)
        for(int j = i + 1; j < sz; j++)
            if(j != i && rndNum[i] > rndNum[j]){
                int temp = rndNum[i];
                rndNum[i] = rndNum[j];
                rndNum[j] = temp;
                
            }
}


//Prints an array into table format
void printArrTable(const int arr[], const int size){
    for(int i = 0; i < size; i++){
        //Ends the row after 10th element is displayed
        if(i != 0 && i%10 == 0)
            cout<<endl; 
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}