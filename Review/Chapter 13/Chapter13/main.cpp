/* 
 * File:   main.cpp
 * Author: dangerouspirate
 * Description: Gaddis Chapter 13: Classes - Challenge Problems
 * Created on June 14, 2018, 7:47 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

//Prototypes
void prob1();
void prob2();
void prob3();
void prob6();
void prob12();
void prob13();
void prob14();
void prob15();
void prob16();

int main(int argc, char** argv) {
    int choice;
    do{
        cout<<"\nChapter 13 - Classes\n-----------------\n";
        cout<<"Enter 1 Problem 1"<<endl;
        cout<<"Enter 2 Problem 2"<<endl;
        cout<<"Enter 3 Problem 3"<<endl;
        cout<<"Enter 4 Problem 6"<<endl;
        cout<<"Enter 5 Problem 12"<<endl;
        cout<<"Enter 6 Problem 13"<<endl;
        cout<<"Enter 7 Problem 14"<<endl;
        cout<<"Enter 8 Problem 15"<<endl;
        cout<<"Enter 9 Problem 16"<<endl;
        cout<<"Enter any other Integer to EXIT.\n";
        cout<<"User Input: ";
        cin>>choice;
        
        switch(choice){
            case 1: prob1()  ;break;
            case 2: prob2()  ;break;
            case 3: prob3()  ;break;
            case 4: prob6()  ;break;
            case 5: prob12() ;break;
            case 6: prob13() ;break;
            case 7: prob14() ;break;
            case 8: prob15() ;break;
            //case 9: prob16() ;break;
            
            default: cout<<"\nOption Exit chosen. Terminating...\n";
        }
    
    }while(choice >= 1 && choice <= 10);
    return 0;
}

