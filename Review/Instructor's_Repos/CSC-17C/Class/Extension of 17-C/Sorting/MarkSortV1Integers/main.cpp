/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 10, 2012, 8:02 PM
 * Sorting using Arrays
 */

#include <iostream>//cout
#include <cstdlib>//srand()
#include <ctime>//time()
using namespace std;

//Prototypes
void fillArray(int [], int);
void printArray(int [], int, int);
void posMin(int [], int, int);
void swap1(int &a,int &b);
void swap2(int &a,int &b);
void markSort(int [],int);


int main(int argc, char** argv) {
    //Set the random number seed according to time
    srand(static_cast<unsigned int>(time(0)));
    //Declare the array
    const int N=100;
    int column[N];
    //Fill the Array
    fillArray(column,N);
    //Output the 2 digit random array
    printArray(column,N,10);
    //Test out the posMin function;
    markSort(column,N);
    //Output the 2 digit random array
    printArray(column,N,10);
    //Exit
    return 0;
}

void markSort(int array[],int size){
    for(int i=0;i<size-1;i++){
        posMin(array,size,i);
    }
}

void swap2(int &a,int &b){
    a=a^b;
    b=a^b;
    a=a^b;
}

void swap1(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void posMin(int array[], int size, int pos){
    for(int i=pos+1;i<size;i++){
        if(array[pos]>array[i]){
            swap2(array[pos],array[i]);
        }
    }
}

//Fill the array with random 2 digit numbers
void fillArray(int array[], int size){
    for(int i=0;i<size;i++){
        array[i]=rand()%90+10;
    }
}
void printArray(int array[], int size , int perLine){
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

