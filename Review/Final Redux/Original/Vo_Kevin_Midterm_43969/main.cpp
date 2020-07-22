/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Purpose: Using menu for challenge selection
 * Problem 1 -> Provides 3 diff. subscriptions of a random ISP
 * Problem 2 -> Converts 6 numbers into asterisks 
 * Problem 3 -> Determines the min. & max. # from custom set & range of #s 
 * Problem 4 -> Determines if "(x&&y)^y==(x||y)^x is true
 * Problem 5 -> Update checking balance and debits $20 if overdrawn
 * Problem 6 -> Determines employee's gross pay (straight, double, triple time)
 * Created on April 04, 2012, 11:18 AM
 */
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    bool loop=true;
    char Banking_Restart;
    int Sel;
    //Do-while loop to restart program of usage
     do{
        cout<<"Type 1 to solve problem 1\n";
        cout<<"Type 2 to solve problem 2\n";
        cout<<"Type 3 to solve problem 3\n";
        cout<<"Type 4 to solve problem 4\n";
        cout<<"Type 5 to solve problem 5\n";
        cout<<"Type 6 to solve problem 6\n";
        cout<<"Type 7 to solve problem 7\n";
        cout<<"Type anything else to quit with no solutions.\n";
        cin>>Sel;
   //Switch statement for selection menu
        switch (Sel){
            case 1:{
                char Package_Selection;
                int Hours;
                float Price;
                //Prompt on how to use the program
                    cout<<"*** Problem #1 ***\n";
                    cout<<"Please enter in \"A\", \"B\" or \"C\" to select the";
                    cout<<" package you want.\nThen enter in the number ";
                    cout<<"of hours you like to have access online per month.";
                    cout<<endl<<endl;
                    //Package Info Display
                    cout<<"A)  $29.95 per month, 11 hours access.  Additional ";
                    cout<<"hours access. Additional hours\n are charged  at ";
                    cout<<"$3.00/hour\n";
                    
                    cout<<"B)  $34.95 per month, 11 hours access.  Additional ";
                    cout<<"hours access. Additional hours\n are charged  at ";
                    cout<<"$2.00/hour\n";
                    
                    cout<<"C)  $39.95 per month, unlimited access\n";
                    //cins for user's input
                    cout<<"Choose your package: ";
                    cin>>Package_Selection;
                    cout<<"Number of hours: ";
                    cin>>Hours;
                   
        //if statement to decide which package was selected
                    if (Package_Selection == 'A' || Package_Selection == 
                            'a' && Hours <= 11)
                    {
                      cout<<"Congratulations you have chosen package A!\n";
                      cout<<"Your package's month fee will be $29.95 with 11 ";
                      cout<<"hours access included.\n";
                      cout<<endl;
                     }
                     else if (Package_Selection == 'A' || Package_Selection == 
                             'a' && Hours > 11)
                     {
                         Price = ((Hours - 11) * 3) + 29.95;
                         cout<<"Congratulations you have chosen package A!\n";
                         cout<<"Your package's monthly fee will be $";
                         cout<<setprecision(2)<<fixed<<Price;
                         cout<<" which will include the "<<Hours<<" hours of\n";
                         cout<<"access that you have requested.\n";
                         cout<<endl;
                     }
                       if (Package_Selection == 'B' || Package_Selection == 
                            'b' && Hours <= 11)
                    {
                      cout<<"Congratulations you have chosen package B!\n";
                      cout<<"Your package's month fee will be $34.95 with 11 ";
                      cout<<"hours access included.\n";
                      cout<<endl;
                     }
                     else if (Package_Selection == 'B' || Package_Selection == 
                             'b' && Hours > 11)
                     {
                         Price = ((Hours - 11) * 2) + 29.95;
                         cout<<"Congratulations you have chosen package B!\n";
                         cout<<"Your package's monthly fee will be $";
                         cout<<setprecision(2)<<fixed<<Price;
                         cout<<" which will include the "<<Hours<<" hours of\n";
                         cout<<"access that you have requested.\n";
                         cout<<endl;
                     }
                      if (Package_Selection == 'C' || Package_Selection == 
                            'c')
                    {
                         cout<<"Congratulations you have chosen package C!\n";
                         cout<<"Your package's month fee will be $39.95 with ";
                         cout<<"unlimited access included.\n";
                         cout<<endl;
                     }
                    
                             
                     else 
                     {
                         cout<<"You have not selected one of our internet";
                         cout<<" packages. Please enter in\na letter that ";
                         cout<<"corresponds to the package you desire.";
                         cout<<endl<<endl;
                     }
            };break; 
            case 2:{ 
                
                int d1, d2, d3, d4, d5, d6, i;
                //Prompt output
                cout<<"*** Problem #2 ***\n";
                cout<<"Please enter 6 digits between 1 & 30 to form a ";
                cout<<"histogram of asterisks. If you want fewer lines to ";
                cout<<"be displayed just enter in \"0\".\n";
                //User's input
                cout<<"Digit #1: ";
                cin>>d1;
                cout<<setw(14);
                
                if(d1>=1 && d1<=30)
                {
                        for (i=0; i < d1; i++)
                        {
                             cout<<"*";
                        }
                }
                else
                    cout<<"Sorry you must enter in a number between 1 - 30.\n";
                
                cout<<endl;
                
                cout<<"Digit #2: ";
                cin>>d2;
                cout<<setw(14);
                
                if(d2>=1 && d2<=30)
                {
                        for (i=0; i < d2; i++)
                        {
                             cout<<"*";
                        }
                }
                else
                    cout<<"Sorry you must enter in a number between 1 - 30.\n";
                
                cout<<endl;
                
                cout<<"Digit #3: ";
                cin>>d3;
                cout<<setw(14);
                
                if(d3>=1 && d3<=30)
                {
                        for (i=0; i < d3; i++)
                        {
                               cout<<"*";
                        }
                }
                else
                    cout<<"Sorry you must enter in a number between 1 - 30.\n";
                
                cout<<endl;
                
                cout<<"Digit #4: ";
                cin>>d4;
                cout<<setw(14);
                
                if(d4>=1 && d4<=30)
                {
                        for (i=0; i < d4; i++)
                        {
                            cout<<"*";
                        }
                }
                else
                    cout<<"Sorry you must enter in a number between 1 - 30.\n";
                
                cout<<endl;
                
                cout<<"Digit #5: ";
                cin>>d5;
                cout<<setw(14);
                
                 if(d5>=1 && d5<=30)
                {
                        for (i=0; i < d5; i++)
                        {
                                cout<<"*";
                        }
                }
                else
                    cout<<"Sorry you must enter in a number between 1 - 30.\n";
                
                cout<<endl;
                
                cout<<"Digit #6: ";
                cin>>d6;
                cout<<setw(14);
                
                 if(d6>=1 && d6<=30)
                {
                        for (i=0; i < d6; i++)
                        {
                                cout<<"*";
                        }
                }
                 else//else statement for any other possibilities
                    cout<<"Sorry you must enter in a number between 1 - 30.\n";
                
                cout<<endl;
            }break;  
                    
            case 3:{ 
            int Num_Input, Stored_Num;
            float max = 0.0, min;
            //prompt output
            cout<<"*** Problem #3 ***\n";
            cout<<"This problem will provide you with the minimum and maximum\n"
                <<"value from a set of numbers with the range of your choosing."    
                <<endl;   
            //User's input of amount of digits they want to input
            cout<<"How many numbers are you going to input: ";
            cin>>Num_Input;
            //For loop repeats until the amount above has been reached
            for (int count = 1; count<=Num_Input; count++)
            {
                cout<<"Enter digit "<<count<<" here: ";
                cin>>Stored_Num;
                if (count == 0) 
                    min = max = Stored_Num;
   else 
   {
      if (Stored_Num<min) min = Stored_Num;
      if (Stored_Num>max) max = Stored_Num;
   }            
}
        cout<<"Minimum: "<<min<<endl;
        cout<<"Maximum: "<<max<<endl; 
        }break; 
            
            case 4:{
                int Test, Tester;
         cout<<"*** Problem #4 ***\n";
         cout<<"This program will determine if \"(x&&y)^y==(x||y)^x\" is true.\n";
         cout<<"Press enter to determine truth or false...";
        //Has the user enters a key before determining the truth
        cin.ignore();
        cin.get();
    
    unsigned x=rand(), y=rand(), z, seed = time(0);
    srand(seed);
    

    z==(x&&y)^y;
    //Determines which couts to display depends on result
    if ((x||y)^x==z)
     {
    cout<<"After testing it, it has been proven that (x&&y)^y is in fact equal";
    cout<<" to (x||y)^x TRUE.\n\n";
     }
     else
     {
    cout<<"After testing it, it has been proven that (x&&y)^y is in fact equal";
    cout<<" to (x||y)^x FALSE.\n\n";
     }
    
            }break;   
          
            case 5:{
                
                //do-loop to provide user to restart just this case 
                do{
                int account_Num, balance, nBalance, checksWritten, deposits, Total, 
                        Depo, Writ, Debit, counter = 4; 
                const int penalty = -20, overDrawn = -1;
                cout<<"*** Problem #5 ***\n";
                cout<<"Please enter in the following information to determine\n"
                    <<"your current balance of your checking account.\n\n";
                
                cout<<"Account Number (4 digits only): ";
                cin>>account_Num;
                //if statement to make sure user entered in exactly 4 digits
                if(account_Num>1000 && account_Num<=9999)
                {
                    //Outline for program after the 4 digits have been entered
                    cout<<"Balance at the beginning of the month: ";
                    cin>>balance;
                    cout<<"Total of all check(s) written (this month): ";
                    cin>>checksWritten;
                    cout<<"Total of all deposits credited to this customer's "
                        <<"account (this month): ";
                    cin>>deposits;
                    cout<<endl;
                    Depo = deposits-checksWritten;
                    Writ = checksWritten-deposits;
                    
                   //conditional operators to improper subtractions
             Total=checksWritten>deposits?nBalance=balance-Writ:nBalance=Depo+balance;
             //balance for overdrawn account
             if(nBalance<=overDrawn)
             {
                 //cout for overdrawn
                 Debit=penalty+Total;
                 cout<<"\nAccount #: "<<account_Num<<endl<<endl;
                 cout<<"Updated Balance: $"<<Debit<<endl;
                 cout<<"Warning: Since you have overdrawn your balance, an "
                     <<"additional $20 fee\nhas been deducted and included in "
                     <<"your \"Updated Balance\"."<<endl<<endl;     
             }
             else
             {
                 //cout for good/okay balance
                 Debit=nBalance;
                 cout<<"\nAccount #: "<<account_Num<<endl<<endl;
                 cout<<"Updated Balance: $"<<Debit<<endl<<endl;
             }
                    
                }
                else
                {
                    //cout if digits are under/over 4
                    cout<<"\nSorry but you enter in a four digit number for this"
                        <<"to work.\n";
                    
                    cout<<"Would you like to restart (y/n).\n";
                    cout<<"User Input: ";
                    cin>>Banking_Restart;
                    cout<<endl;
                            
                } 
                //do while to restart the banking program
                }while(Banking_Restart == 'Y' || Banking_Restart == 'y');
            }break;    
            case 6: {
            float gross, rateOfpay, leftoverH, avgPay;
            int hours;
            const int straight = 20, Tdoub = 40;
            
            cout<<"*** Problem #6 ***\n";
           //output prompt 
            cout<<"Please enter in the following information below to determine"
                <<" your gross pay.\n\n";
            //cin for hours and pay rate
            cout<<"Hours Worked: ";
            cin>>hours;
            cout<<"Rate of Pay: ";
            cin>>rateOfpay;
            
            
            //cout for straight, double, triple time
            if(hours<=straight)
            {
                //calculations for straight
                 gross=hours*rateOfpay;
                 cout<<"Your Gross Pay: $"<<fixed<<showpoint<<setprecision(2)
                         <<gross;
                 cout<<endl<<endl;
            }
            else if(hours>=straight && hours<=Tdoub)
            {
                //calculations for double
                leftoverH=hours-straight;
                avgPay=hours-leftoverH;
                gross=((leftoverH*rateOfpay)*2)+(avgPay*rateOfpay);
                cout<<"Your Gross Pay: $"<<fixed<<showpoint<<setprecision(2)
                        <<gross;
                cout<<endl<<endl;
            }
            else
            {
                //calculations for triple
                leftoverH=hours-straight;
                avgPay=hours-leftoverH;
                gross=((leftoverH*rateOfpay)*3)+(avgPay*rateOfpay);
                cout<<"Your Gross Pay: $"<<fixed<<showpoint<<setprecision(2)
                        <<gross;
                cout<<endl<<endl;
            }

            }break;    
           
        default:{//exit for last option
                        cout<<"Exit?"<<endl;
                        loop=false;
                        break;
                }
            
        };
    }while(loop);//do while loop to restart the entire program
    return 0;
}
    

