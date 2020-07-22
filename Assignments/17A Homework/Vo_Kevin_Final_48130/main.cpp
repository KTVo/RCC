/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Assignment: Final 
 * Class: CSC-17A (48130)
 * Created on December 10, 2014, 10:42 AM
 *
 * For Problem 4 I do not know what Recursive Calculation, so it's incorrect
 *
 * For Problem 3 I can't seem to make the program read & calculate the text 
 * file since the rows&cols never added up correctly, so I made an array instead
 *
 * Extra Credit:
 * 2.5 pts->Exception handling for Problems 4 and 5
 * 1   pt->Discuss any code that you would make better & support your reasoning.   
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <ctime>
#include <fstream>
#include <cctype>
#include <cstring>

using namespace std;

#include "Prob1.h"
#include "Prob4.h"
#include "Prob5.h"

void prob2Main();
void prob3Main();

void Menu();
int getN();
void def(int);



int main(int argv,char *argc[]){
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        //I reversed the cases because Prob.1 only works in a case if I were to
        //only go through the other cases first
        case 1:{
            char n=5;
            unsigned char rndseq[]={16,34,57,79,144};
            int ntimes=100000;
            
            //get the system time
            unsigned seed = time (0);

            //seed the random number generator
            srand(seed);

            cout<<"Problem #1  (Random Sequence)\n";
            
            Prob1Random a(n,rndseq);

            for(int i=1;i<=ntimes;i++){
                a.randFromSet();
            }
    
            int *x=a.getFreq();
            unsigned char *y=a.getSet();
    
            for(int i=0;i<n;i++){
                cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
            }
            cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;                             
        };break;

        case 2:{
            cout<<"Problem #2  (All Kinds of Sorting)\n";
            prob2Main();
        };break;

        case 3:{
            cout<<"Problem #3  (Spreadsheet Stuff)\n";
            cout<<"\npt->Discuss any code that you would make better and "
                <<"support your reasoning.\n"
                <<"I'd like to make this prob. better since I was unable to\n"
                <<"have the program calculate the correct sum when reading it\n"
                <<"out of Problem3.txt. Instead I had to make the numbers an\n"
                <<"array and ran it from there.\n\n";
            prob3Main();
        };break;

        case 4:{
            cout<<"\n*Extra Credit: 2.5 pts->Exception handling for Problems 4" 
                <<" and 5\n\n";

            saveAccount mine(-300);

            for(int i=1;i<=10;i++)
            {
                mine.Transaction((float)(rand()%500)*(rand()%3-1));
            }
            mine.toString();
            cout<<"Balance after 7 years given 10% interest = "
                <<fixed<<setprecision(2)<<mine.Total((float)(0.10),7)<<endl;
            cout<<"Balance after 7 years given 10% interest = "
		<<mine.TotalRecursive((float)(0.10),7)
		<<" Recursive Calculation "<<endl;
        };break;

        case 5:{
            cout<<"Problem #5  (Employee Class)\n";
            cout<<"\n*Extra Credit: 2.5 pts->Exception handling for Problems 4" 
                <<" and 5\n\n";
            Employee Mark("Mark","Boss",215.50);
            Mark.setHoursWorked(-3);
            Mark.toString();
            Mark.CalculatePay(Mark.setHourlyRate(20.0),
		Mark.setHoursWorked(25));
            Mark.toString();
            Mark.CalculatePay(Mark.setHourlyRate(40.0),
		Mark.setHoursWorked(25));
            Mark.toString();
            Mark.CalculatePay(Mark.setHourlyRate(60.0),
		Mark.setHoursWorked(25));
            Mark.toString();

            Employee Mary("Mary","VP",50.0);
            Mary.toString();
            Mary.CalculatePay(Mary.setHourlyRate(50.0),
		Mary.setHoursWorked(40));
            Mary.toString();
            Mary.CalculatePay(Mary.setHourlyRate(50.0),
		Mary.setHoursWorked(50));
            Mary.toString();
            Mary.CalculatePay(Mary.setHourlyRate(50.0),
		Mary.setHoursWorked(60));
            Mary.toString();
        };break;
          case 6:{
                cout<<"\nProblem #6  (Conversions)\n";
                cout<<"\nGiven the following Hex IEEE 754 single point floating"
                    <<" representations\n"
                    <<"\n***NOTE: The work for the conversions are in pictures:"
                    <<" 'Conversion Work 1' & 'Conversion Work 2' "
                    <<"are located in the file of this program.\n";
                    
                    cout<<"\na) 4207999a -> Decimal = 33.9\n";
                    cout<<"b) 44861333 -> Decimal = 1072.6\n";
                    cout<<"c) 3d8f5c29 -> Decimal = 0.07\n";
            };break;

          default:   def(inN);}
        }while(inN<7);
        return 1;
    }
    void Menu()
    {
           cout<<endl;
           cout<<"Type 1 for problem 1 (Random Sequence)"<<endl;
           cout<<"Type 2 for problem 2 (All Kinds of Sorting)"<<endl;
           cout<<"Type 3 for problem 3 (Spreadsheet Stuff)"<<endl;
           cout<<"Type 4 for problem 4 (Savings Account Class)"<<endl;
           cout<<"Type 5 for problem 5 (Employee Class)"<<endl;
           cout<<"Type 6 for problem 6 (Conversions)"<<endl;
           cout<<"Type 7 to exit \n"<<endl;
    }
    int getN()
    {
           int inN;
           cin>>inN;
           return inN;
    }

    
    void def(int inN)
    {
           cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }



