/* 
 * File:   Prob_13_Set_Map.cpp
 * Author: Kevin Vo
 * Course: CSC-17C
 * Assignment: Midterm
 * Problem: #13
 * Created on April 19, 2018, 11:43 PM
 */

//Libraries
#include <cstdlib>//Random number seed
#include <ctime>//Set the seed
#include <iostream>//I/O
#include <map>
#include <set>
using namespace std;

//No Global Constants

//Function Prototypes
int *fillAry(int,int);
void prntAry(int *,int,int);
void prntMod(int *);
void swap(int *,int *);
void minPos(int *,int,int);
void mrkSort(int *,int);
void *mode(const int *,int);
int *copy(const int *,int);

//Execution begins here
void runMode() {
    int arySize=35;
    /*
    for(int pp = 0; pp < 5; pp++){
        if(pp == 0)
            arySize=0;
        else if(pp == 1)
            arySize=1;
        else if(pp == 2)
            arySize=10;
        else if(pp == 3)
            arySize=11;
        else if(pp == 4)
            arySize = 35;
        */
        cout<<"\narrSize = "<<arySize<<endl<<endl;
            
        //Declare variables and fill
        int modNum=10;
        int *ary=fillAry(arySize,modNum);

        //Print the initial array
        prntAry(ary,arySize,10);

        //Calculate the mode array
        mode(ary,arySize);


        //Delete allocated memory
        delete []ary;
    //}
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void *mode(const int *array,int arySize){
    //Copy the array
    int *ary=copy(array,arySize);
    //Sort the ary
    mrkSort(ary,arySize);
    //Sort the copy
    //Find the max Freq
    int count = 0;
    
    map<int, int, greater<int>> m;
    set<int, greater<int>> s;
        
    for(int i = 0; i < arySize; i++)
        m[ary[i]]++;
    
    bool dupOfValue = false;    //checks for any duplications
    
    for(map<int, int>::iterator it = m.begin(); it != m.end(); ++it){
        s.insert(it->second);
        if(it->second > 1)
            dupOfValue = true;
    }

    for(map<int,int>::iterator it=m.begin();it!=m.end();++it){
        if(it->second == *s.begin() && dupOfValue == true)
            count++;
    }
    
    int numFreq;    
    if(arySize <= 0)
        numFreq = 1;
    else
        numFreq = *s.begin();
    
    
    cout<<"Max Freq: "<<numFreq<<endl;
    
    cout<<"Number of modes = "<<count<<endl<<endl;
    
    cout<<"The number of modes = "<<count<<endl;
    
    cout<<"The max Frequency = "<<numFreq<<endl;
    
    //Checks if the map is empty to display mode set as "null" or not
    if(m.empty() == false && dupOfValue == true){
        
        cout<<"The mode set = { ";
        for(map<int,int>::iterator it=m.begin();it!=m.end();++it)
            if(*s.begin() == it->second)
                cout<<it->first<<" ";
        cout<<"}"<<endl;
    }else{
        cout<<"The mode set = {null}"<<endl;
    }
    

    //Delete the allocated copy and return
    delete []ary;
    
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        minPos(array,n,i);
    }
}

void minPos(int *array,int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(*(array+pos)>*(array+i))
            swap(array+pos,array+i);
    }
}

void swap(int *a,int *b){
    //Swap in place
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}

void prntAry(int *array,int n,int perLine){
    //Output the array
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*(array+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n, int modNum){
    //Allocate memory
    int *array=new int[n];
    
    //Fill the array with 2 digit numbers
    for(int i=0;i<n;i++){
        *(array+i)=i%modNum;
        //*(array+i)=rand()%modNum;
    }
    
    //Exit function
    return array;
}