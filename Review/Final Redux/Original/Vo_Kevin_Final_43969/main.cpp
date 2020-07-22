/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Assignment: Finals for CSC-5 (43969)
 * Problem Extra Credit: Outputs a string of numbers of the input number
 * Problem 1: Displays the input number in reversed form
 * Problem 2: Guess the Number Game
 * Problem 3: Determines if a pair of integers are multiples
 * Problem 4: Displays the frequency of 5 numbers that are obtained after looping 10000x
 * Problem 5: Print out and then sorts the array from least to greatest
 * Problem 6: Displays a set of numbers in columns then displays its summed value
 * Created on June 2, 2012, 11:10 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;
//Function for displays the menu
void menuDisplay();

//Main Body Functions for all of the Problems
int ProblemExtraMain();
int Problem1Main();
int Problem2Main();
int Problem3Main();
int Problem4Main();
int Problem5Main();
int Problem6Main();

//Extra Credit's Prototypes
void MarkNumber(char []);

//Problem 1's Prototype
int reverser(int);

//Problem 2's Prototype
void AdditonForRowCol(int numSet[][6], const int column);

//Problem 3's Prototype
bool multiple(int numb1, int numb2);

//Problem 5's Prototype
void NumStorter(int[]);

int main(int argc, char** argv) {
    bool loop = true;
    
    do{
    int choice;
    
    menuDisplay();
    
    cout<<"Your Input: ";
    cin>>choice;
    
    switch(choice){
    
        case 1:{
            ProblemExtraMain();
        };break;
    
        case 2:{
            Problem1Main();
        };break;
    
        case 3:{
            Problem2Main();
        };break;
                
        case 4:{
            Problem3Main();
        };break;
    
        case 5:{
            Problem4Main();
        };break;
    
        case 6:{
            Problem5Main();
        };break;
    
        case 7:{
            Problem6Main();
        };break;
    
        default:{
            cout<<"Program Terminated...\n";
            loop = false;
            break;
            exit (0);
        }
    
    }
    }while(loop);
    return 0;
}

void menuDisplay(){
    cout<<"\n*** Final for CSC-5 ***\n";
    cout<<"1) Input 1 for Extra Credit Problem\n";
    cout<<"2) Input 2 for Problem 1\n";
    cout<<"3) Input 3 for Problem 2\n";
    cout<<"4) Input 4 for Problem 3\n";
    cout<<"5) Input 5 for Problem 4\n";
    cout<<"6) Input 6 for Problem 5\n";
    cout<<"7) Input 7 for Problem 6\n";
}

//Functions for the Extra Credit Problem

int ProblemExtraMain(){
    const int FIVE = 5;
    char numInput[FIVE];
    
//Prompt for Extra Credit
    cout<<"This Program will display a string of numbers in a following manner\n"
        <<"based on the form of the Number that is inputted below.\n";
    cout<<"Note: This program will only accept values ranging between 0 and 127.\n";
    
    cout<<"Please Enter a Number: ";
    cin >>numInput;

    //Function for providing the string results
    MarkNumber(numInput);

return 0;}

void MarkNumber(char character[])
{
        int num = atoi(character), counter=0;

        cout<<"Input ->  Output\n";
        cout<<"----------------\n";
        cout<<num<<" -> ";
        for(int i = 0; i <= num; ++i){
                if(counter==10){
                        counter=0;
                }    
        cout<<counter<<" ";
        ++counter;}
}

//Problem 1's Problems
int Problem1Main(){
    int inputReversedNum;
    
    cout<<"This program take the number that's inputted then returns the value"
        <<"\nin reverse formation.\n";
    
    cout<<"Please enter a value that you would wish to be reversed: ";
    cin>>inputReversedNum;
//Display result of reversed #
cout<<"\nRevsered = "<<reverser(inputReversedNum)<<endl;
return 0;}

int reverser(int inputReversedNum){		
int num, reversedNumberResult = 0;
	
//if statement that displays 0 if input value was 0
if(inputReversedNum == 0){
	
    cout<<0<<endl;
}	
else {
    
//loops while the inputted number is more than 0 else it stops	
while(inputReversedNum > 0){
		
num = inputReversedNum % 10;
	
//Truncates the last unneeded number
inputReversedNum /= 10;

//Equation for reversing the number
reversedNumberResult = (reversedNumberResult * 10) + num;

}
	
return reversedNumberResult;	
 	
}	
 	
}

//Problem #2 function
int Problem2Main(){
        //Random Number Generator    
        unsigned seed = time(0);    
        srand(seed);

        int randNum = 1+(rand()%1000), inputAnswer = 0;
        char restart;
        do{
        //Output Prompt for program
        cout<<"This program is a \"Guess the Number\" game. You play by trying "
            <<"to guess\nthe right number and enter it in below.\n";   

        for (int tries = 0; tries <= 9; tries++){
            if (tries <= 9){
                cout<<"\nEnter in the number that you've guessed: ";
                cin>>inputAnswer;
            }
                        //Output if answer is too low
                        if (inputAnswer < randNum && tries < 10 && tries !=9){ 
                                cout<<"Too low.  Try again.\n";
                          
                        }
                        else if (inputAnswer > randNum && tries < 10 && tries !=9){ 
                                cout<<"Too High. Try again.\n";
                                
                        }
                        else if (inputAnswer != randNum && tries == 9){
                                tries = 100;
                                cout<<"Too many tries.\n";
                                cout<<"Would you like to play again? (y / n):";
                                cin>>restart;
                        }
                        else if (inputAnswer == randNum){
                                //Output if the number was guessed correctly
                                tries = 100;
                                cout<<"\nYou guessed the number!\n";
                                cout<<"Would you like to play again? (y / n):";
                                cin>>restart;
                        }
        }

        }while(restart == 'Y' || restart == 'y');
return 0;}

//Problem# 3 Functions
int Problem3Main(){
        int number1, number2, truth;
        //Prompt for problem 3
        cout<<"This program will determine if the first integer is a multiple of the\n"
            <<"second integer from the two numbers that will be entered below.\n";

        cout<<"Number 1: ";
        cin >>number1;
        cout<<"Number 2: ";
        cin>>number2;

        truth = multiple(number1,number2);
        
        if (truth == 0){
                cout<<"TRUE it is a multiple.\n";
        }
        else{
                cout<<"FALSE not a multiple.\n";
        }
return 0;}

//find out whether if the pairs are multiples or not
bool multiple(int a, int b){ 
    int truthDetector;
    int x = b/a;
    
    if (a*x == b){
        truthDetector = 0;
    }
    else{
        truthDetector = 1;
    }
return truthDetector;}

//Functions for Problem 4
int Problem4Main(){
    const int n = 5, ntimes = 10000, seed = 1;
    int freq[n]={0};
    short int rndSeq[] = {19,50,78,161,252};
    int randNum, i;
    
          srand(seed);
    cout<<"This program will return a random number from \"19, 50, 78, 161, 252\"."
        <<"By looping this process\n10,000 times then prints the occurred numbers.\n";    
    cout<<"Press enter to continue...";
    cin.ignore();
    cin.get();
    //Loops the process 10000                    
    for(i = 0; i < ntimes; i++){
        randNum = rand()%5;
        freq[randNum]++;
                }
    //Output Results            
    for(i=0; i < n; i++){
        cout<<rndSeq[i]<<" occurred "
                <<freq[i]<<" times\n";
    }
return 0;}


//Constant global variable for Problem 5
const int Set = 10;
//Functions for Problem 5
int Problem5Main(){
    
    int num[Set] = {1,7,4,0,9,4,8,8,2,4};
     cout<<"This Program will stort through the numbers: (1,7,4,0,9,4,8,8,2,4)"
         <<"\nthen displays them in order from least to greatest.\n";  
     cout<<"Please press enter to continue...";
     cin.ignore();
     cin.get();
     
     cout<<"Unorganized Stored Values: ";
     // Output the original array values
     for(int count = 0; count < Set; count++)
     {
          cout <<"  "<< num[count];
     }
     
     //Organizes the stored value
     NumStorter(num);
     
     //Displays all of the value in organized fashion
     cout<<"\nOrganized Stored Output: " ;
     
     //Displays the output of the array with spaces between them (one value per loop)
     for( int count = 0; count < Set; count++ ){
          cout<<"  "<<num[count];
     }
     cout<<endl;
    
return 0;}

//Sorts the value stored in the area to organize it from least to greatest
void NumStorter(int num[])
{
     bool sortNum = false;
     while(sortNum == false)
     {
          sortNum = true;
          //Cycles through and tries to search and return the value
          for (int cycleNum = 0; cycleNum < Set - 1; ++cycleNum)
          {
               if(num[cycleNum]>num[cycleNum+1])
               {
                    int temp = num[cycleNum];
                    num[cycleNum] = num[cycleNum + 1];
                    num[cycleNum + 1] = temp;
                    sortNum = false;
               }
          }
 
     }
}

//Functions for Problem 6
int Problem6Main(){
    const int row = 5, col = 6;
    //double array for storing number set
    int numSet[row][col] = { 
                            { 141,   567,   434,   100,   269,   324, },
                            { 578,   458,   562,   564,   305,   245, },
                            { 381,   427,   561,   591,   595,   542, },
                            { 427,   536,   491,   204,   502,   253, },
                            { 392,   482,   521,   316,   318,   495, } 
    };
    
    //Displays the prompt of the program
    cout<<"This program will display a set of numbers long with the total sum"
        <<"\nof both the row and column.\n";    
    //Function for calculating the sum and then displaying them
    AdditonForRowCol(numSet,5);
return 0;}

void AdditonForRowCol(int numSet[][6], const int column){    
  int Adder1[6] = {0}, Adder2[5] = {0};
 
  //Adds rows and col
  for(int row = 0; row < 5; row++){
     for( int col = 0; col < 6; col++){
        Adder1[col] += numSet[row][col];
         Adder2[row] += numSet[row][col];
      }
  }
 
  //Displays the number set
for(int column = 0; column != 5; ++column){
	  for(int col = 0; col != 6; ++col){
              cout.width(6);
		  cout << numSet[column][col]<<"  ";
	  }
	  cout.width(6);
          cout<<Adder2[column]<<"  \n";
  }
 
  //Displays the results
  for(int cyc1 = 0; cyc1 != 6; ++cyc1){
          cout.width(6);
	  cout << Adder1[cyc1]<<"  ";
  }
  for (int cyc2 = 0; cyc2 != 0; ++cyc2){
      cout.width(7);
      cout<<Adder2[cyc2]<<"  ";
  }
  cout<<endl;
}
