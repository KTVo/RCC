/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 25th, 2018, 7:05 PM
 * Purpose:  Compare Fibonacci Implementations
 */

//System Libraries Here
#include <iostream>
#include <ctime>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int fibAray(int);
int fibVar3(int);
int fibRec(int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    
    //Input or initialize values Here
    
    //Process/Calculations Here
    int end,beg;
    beg=time(0);
    cout<<fibAray(47)<<endl;
    end=time(0);
    cout<<"Array Time = "<<end-beg<<endl;
    
    beg=time(0);
    cout<<fibVar3(47)<<endl;
    end=time(0);
    cout<<"Variable Time = "<<end-beg<<endl;
    
    beg=time(0);
    cout<<fibRec(47)<<endl;
    end=time(0);
    cout<<"Recursion Time = "<<end-beg<<endl;
    
    //Output Located Here

    //Exit
    return 0;
}

int fibAray(int n){
    int *array=new int[n+1];
    array[0]=0;
    array[1]=1;
    for(int i=2;i<=n;i++){
        array[i]=array[i-1]+array[i-2];
    }
    int x=array[n];
    delete []array;
    return x;
}
int fibVar3(int n){
    int fim2=0;
    int fim1=1;
    int count=2;
    int fi;
    do{
        fi=fim1+fim2;
        fim2=fim1;
        fim1=fi;
        count++;
    }while(count<=n);
    return fi;
}

int fibRec(int n){
    if(n==0)return 0;
    if(n==1)return 1;
    return fibRec(n-1)+fibRec(n-2);
}