/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 10, 2012, 8:02 PM
 * Sorting using Arrays
 */

#include <iostream>//cout
#include <cstdlib>//srand()
#include <ctime>//time()
#include <cstring>//strcmp,strcpy
using namespace std;

//Prototypes
void fillArray(int [], int);
void printArray(int [], int, int);
void posMin(int [], int, int);
void swap1(int &,int &);
void swap2(int &,int &);
void markSort(int [],int);

//Perform on a 2 dimensional character array
const int NAMELEN=10;
void fillArray(char [][NAMELEN], int);
void printArray(char [][NAMELEN], int);
void posMin(char [][NAMELEN], int, int);
void markSort(char [][NAMELEN],int);
void swap3(char [],char []);


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
    //Declare and fill the character array
    const int NC=100;
    char table[NC][NAMELEN];
    fillArray(table,NC);
    //Print the character array
    printArray(table,NC);
    //Test to find the minimum Name in the array
    markSort(table,NC);
    //Print the character array
    printArray(table,NC);
    //Exit
    return 0;
}

void markSort(char table[][NAMELEN],int size){
    for(int i=0;i<size-1;i++){
        posMin(table,size,i);
    }
}

void swap3(char a[],char b[]){
    char temp[NAMELEN];
    strcpy(temp,a);
    strcpy(a,b);
    strcpy(b,temp);
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

void posMin(char array[][NAMELEN], int size, int pos){
    for(int i=pos+1;i<size;i++){
        if(strcmp(array[pos],array[i])>0){
            swap3(array[pos],array[i]);
        }
    }
}

void posMin(int array[], int size, int pos){
    for(int i=pos+1;i<size;i++){
        if(array[pos]>array[i]){
            swap2(array[pos],array[i]);
        }
    }
}

void fillArray(char array[][NAMELEN], int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<NAMELEN-1;j++){
            array[i][j]=rand()%26+65;
        }
        array[i][NAMELEN-1]='\0';
    }
}
void printArray(char array[][NAMELEN], int size){
    cout<<endl;
    for(int i=0;i<size;i++){
            cout<<i<<" "<<array[i]<<endl;
    }
    cout<<endl;
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