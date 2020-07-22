/* 
 * File:   prob7_Fib.cpp
 * Author: Kevin Vo
 * Course: CSC-17C
 * Assignment: Midterm
 * Problem: #7
 * Created on April 19, 2018, 11:43 PM
 */

#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>   //Used to obtain std::chrono::highresolution_clock to obtain time
using namespace std;


//Function that returns Fibonacci series with Recursion
int recursiveFib(int n){

   if (n <= 1)
      return n;

   return recursiveFib(n-1) + recursiveFib(n-2);

}

//Code borrowed from class
int nonRecursiveFib(int n){
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

void prob7Fib(){
    int n = 40;
    int start,
        end,
        fibVal;
    
    cout<<"\nFibonacci without Recursion:\n\n";
    
    //start = time(0);
    cout<<"\n--- Timer Started ---\n";
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    
    fibVal = nonRecursiveFib(n);
    
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    
    cout<<"\n--- Timer Ended ---\n\n";
    
    //end = time(0);
    
    cout<<"Fibonacci Value at n = "<<n<<" (NON-RECURSIVE): "<<fibVal<<endl;
    
    cout<<"\nRuntime for NON-Recursion Fibonacci = "<<time_span.count()<<" seconds\n";
    //cout<<"Runtime for NON-Recursion: "<<end - start<<endl;
    
    cout<<"\n---------------------------------------------------\n\n";
    
    cout<<"\nFibonacci with Recursion:\n\n";
    
    cout<<"\n--- Timer Started ---\n";
    //start = time(0);
    
    t1 = std::chrono::high_resolution_clock::now();
    
    fibVal = recursiveFib(n);
    
    t2 = std::chrono::high_resolution_clock::now();
    time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    
    cout<<"\n--- Timer Ended ---\n\n";
    //end = time(0);
    
    cout<<"Fibonacci Value at n = "<<n<<" (RECURSIVE): "<<fibVal<<endl;
    
    cout<<"\nRuntime for Recursion Fibonacci = "<<time_span.count()<<" seconds\n";
    
    //cout<<"Runtime for Recursion: "<<end - start<<endl;

}